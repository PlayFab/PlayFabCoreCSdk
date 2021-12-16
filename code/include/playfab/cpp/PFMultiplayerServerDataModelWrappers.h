// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFMultiplayerServerDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerBuildSelectionCriterionWrapper : public ModelWrapper<PFMultiplayerServerBuildSelectionCriterion, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerBuildSelectionCriterion;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerBuildSelectionCriterionWrapper() = default;

    PFMultiplayerServerBuildSelectionCriterionWrapper(const PFMultiplayerServerBuildSelectionCriterion& model) :
        ModelWrapper<PFMultiplayerServerBuildSelectionCriterion, Alloc>{ model },
        m_buildWeightDistribution{ model.buildWeightDistribution, model.buildWeightDistribution + model.buildWeightDistributionCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerBuildSelectionCriterionWrapper(const PFMultiplayerServerBuildSelectionCriterionWrapper& src) :
        PFMultiplayerServerBuildSelectionCriterionWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerBuildSelectionCriterionWrapper(PFMultiplayerServerBuildSelectionCriterionWrapper&& src) :
        PFMultiplayerServerBuildSelectionCriterionWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerBuildSelectionCriterionWrapper& operator=(PFMultiplayerServerBuildSelectionCriterionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerBuildSelectionCriterionWrapper() = default;

    friend void swap(PFMultiplayerServerBuildSelectionCriterionWrapper& lhs, PFMultiplayerServerBuildSelectionCriterionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildWeightDistribution, rhs.m_buildWeightDistribution);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildWeightDistribution(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_buildWeightDistribution = std::move(value);
        this->m_model.buildWeightDistribution =  m_buildWeightDistribution.empty() ? nullptr : m_buildWeightDistribution.data();
        this->m_model.buildWeightDistributionCount =  static_cast<uint32_t>(m_buildWeightDistribution.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildWeightDistribution = m_buildWeightDistribution.empty() ? nullptr : m_buildWeightDistribution.data();
    }

    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_buildWeightDistribution;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildAliasRequestWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildAliasRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildAliasRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildAliasRequestWrapper() = default;

    PFMultiplayerServerCreateBuildAliasRequestWrapper(const PFMultiplayerServerCreateBuildAliasRequest& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildAliasRequest, Alloc>{ model },
        m_aliasName{ SafeString(model.aliasName) },
        m_buildSelectionCriteria{ model.buildSelectionCriteria, model.buildSelectionCriteria + model.buildSelectionCriteriaCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildAliasRequestWrapper(const PFMultiplayerServerCreateBuildAliasRequestWrapper& src) :
        PFMultiplayerServerCreateBuildAliasRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildAliasRequestWrapper(PFMultiplayerServerCreateBuildAliasRequestWrapper&& src) :
        PFMultiplayerServerCreateBuildAliasRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildAliasRequestWrapper& operator=(PFMultiplayerServerCreateBuildAliasRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildAliasRequestWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildAliasRequestWrapper& lhs, PFMultiplayerServerCreateBuildAliasRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aliasName, rhs.m_aliasName);
        swap(lhs.m_buildSelectionCriteria, rhs.m_buildSelectionCriteria);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAliasName(String value)
    {
        m_aliasName = std::move(value);
        this->m_model.aliasName =  m_aliasName.empty() ? nullptr : m_aliasName.data();
    }

    void SetBuildSelectionCriteria(ModelVector<PFMultiplayerServerBuildSelectionCriterionWrapper<Alloc>, Alloc> value)
    {
        m_buildSelectionCriteria = std::move(value);
        this->m_model.buildSelectionCriteria =  m_buildSelectionCriteria.empty() ? nullptr : m_buildSelectionCriteria.data();
        this->m_model.buildSelectionCriteriaCount =  static_cast<uint32_t>(m_buildSelectionCriteria.size());
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
        this->m_model.aliasName = m_aliasName.empty() ? nullptr : m_aliasName.data();
        this->m_model.buildSelectionCriteria = m_buildSelectionCriteria.empty() ? nullptr : m_buildSelectionCriteria.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_aliasName;
    ModelVector<PFMultiplayerServerBuildSelectionCriterionWrapper<Alloc>, Alloc> m_buildSelectionCriteria;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerBuildAliasDetailsResponseWrapper : public ModelWrapper<PFMultiplayerServerBuildAliasDetailsResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerBuildAliasDetailsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerBuildAliasDetailsResponseWrapper() = default;

    PFMultiplayerServerBuildAliasDetailsResponseWrapper(const PFMultiplayerServerBuildAliasDetailsResponse& model) :
        ModelWrapper<PFMultiplayerServerBuildAliasDetailsResponse, Alloc>{ model },
        m_aliasId{ SafeString(model.aliasId) },
        m_aliasName{ SafeString(model.aliasName) },
        m_buildSelectionCriteria{ model.buildSelectionCriteria, model.buildSelectionCriteria + model.buildSelectionCriteriaCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerBuildAliasDetailsResponseWrapper(const PFMultiplayerServerBuildAliasDetailsResponseWrapper& src) :
        PFMultiplayerServerBuildAliasDetailsResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerBuildAliasDetailsResponseWrapper(PFMultiplayerServerBuildAliasDetailsResponseWrapper&& src) :
        PFMultiplayerServerBuildAliasDetailsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerBuildAliasDetailsResponseWrapper& operator=(PFMultiplayerServerBuildAliasDetailsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerBuildAliasDetailsResponseWrapper() = default;

    friend void swap(PFMultiplayerServerBuildAliasDetailsResponseWrapper& lhs, PFMultiplayerServerBuildAliasDetailsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aliasId, rhs.m_aliasId);
        swap(lhs.m_aliasName, rhs.m_aliasName);
        swap(lhs.m_buildSelectionCriteria, rhs.m_buildSelectionCriteria);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAliasId(String value)
    {
        m_aliasId = std::move(value);
        this->m_model.aliasId =  m_aliasId.empty() ? nullptr : m_aliasId.data();
    }

    void SetAliasName(String value)
    {
        m_aliasName = std::move(value);
        this->m_model.aliasName =  m_aliasName.empty() ? nullptr : m_aliasName.data();
    }

    void SetBuildSelectionCriteria(ModelVector<PFMultiplayerServerBuildSelectionCriterionWrapper<Alloc>, Alloc> value)
    {
        m_buildSelectionCriteria = std::move(value);
        this->m_model.buildSelectionCriteria =  m_buildSelectionCriteria.empty() ? nullptr : m_buildSelectionCriteria.data();
        this->m_model.buildSelectionCriteriaCount =  static_cast<uint32_t>(m_buildSelectionCriteria.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.aliasId = m_aliasId.empty() ? nullptr : m_aliasId.data();
        this->m_model.aliasName = m_aliasName.empty() ? nullptr : m_aliasName.data();
        this->m_model.buildSelectionCriteria = m_buildSelectionCriteria.empty() ? nullptr : m_buildSelectionCriteria.data();
    }

    String m_aliasId;
    String m_aliasName;
    ModelVector<PFMultiplayerServerBuildSelectionCriterionWrapper<Alloc>, Alloc> m_buildSelectionCriteria;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerContainerImageReferenceWrapper : public ModelWrapper<PFMultiplayerServerContainerImageReference, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerContainerImageReference;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerContainerImageReferenceWrapper() = default;

    PFMultiplayerServerContainerImageReferenceWrapper(const PFMultiplayerServerContainerImageReference& model) :
        ModelWrapper<PFMultiplayerServerContainerImageReference, Alloc>{ model },
        m_imageName{ SafeString(model.imageName) },
        m_tag{ SafeString(model.tag) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerContainerImageReferenceWrapper(const PFMultiplayerServerContainerImageReferenceWrapper& src) :
        PFMultiplayerServerContainerImageReferenceWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerContainerImageReferenceWrapper(PFMultiplayerServerContainerImageReferenceWrapper&& src) :
        PFMultiplayerServerContainerImageReferenceWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerContainerImageReferenceWrapper& operator=(PFMultiplayerServerContainerImageReferenceWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerContainerImageReferenceWrapper() = default;

    friend void swap(PFMultiplayerServerContainerImageReferenceWrapper& lhs, PFMultiplayerServerContainerImageReferenceWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_imageName, rhs.m_imageName);
        swap(lhs.m_tag, rhs.m_tag);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetImageName(String value)
    {
        m_imageName = std::move(value);
        this->m_model.imageName =  m_imageName.empty() ? nullptr : m_imageName.data();
    }

    void SetTag(String value)
    {
        m_tag = std::move(value);
        this->m_model.tag =  m_tag.empty() ? nullptr : m_tag.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.imageName = m_imageName.empty() ? nullptr : m_imageName.data();
        this->m_model.tag = m_tag.empty() ? nullptr : m_tag.data();
    }

    String m_imageName;
    String m_tag;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerAssetReferenceParamsWrapper : public ModelWrapper<PFMultiplayerServerAssetReferenceParams, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerAssetReferenceParams;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerAssetReferenceParamsWrapper() = default;

    PFMultiplayerServerAssetReferenceParamsWrapper(const PFMultiplayerServerAssetReferenceParams& model) :
        ModelWrapper<PFMultiplayerServerAssetReferenceParams, Alloc>{ model },
        m_fileName{ SafeString(model.fileName) },
        m_mountPath{ SafeString(model.mountPath) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerAssetReferenceParamsWrapper(const PFMultiplayerServerAssetReferenceParamsWrapper& src) :
        PFMultiplayerServerAssetReferenceParamsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerAssetReferenceParamsWrapper(PFMultiplayerServerAssetReferenceParamsWrapper&& src) :
        PFMultiplayerServerAssetReferenceParamsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerAssetReferenceParamsWrapper& operator=(PFMultiplayerServerAssetReferenceParamsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerAssetReferenceParamsWrapper() = default;

    friend void swap(PFMultiplayerServerAssetReferenceParamsWrapper& lhs, PFMultiplayerServerAssetReferenceParamsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fileName, rhs.m_fileName);
        swap(lhs.m_mountPath, rhs.m_mountPath);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

    void SetMountPath(String value)
    {
        m_mountPath = std::move(value);
        this->m_model.mountPath =  m_mountPath.empty() ? nullptr : m_mountPath.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
        this->m_model.mountPath = m_mountPath.empty() ? nullptr : m_mountPath.data();
    }

    String m_fileName;
    String m_mountPath;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGameCertificateReferenceParamsWrapper : public ModelWrapper<PFMultiplayerServerGameCertificateReferenceParams, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGameCertificateReferenceParams;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGameCertificateReferenceParamsWrapper() = default;

    PFMultiplayerServerGameCertificateReferenceParamsWrapper(const PFMultiplayerServerGameCertificateReferenceParams& model) :
        ModelWrapper<PFMultiplayerServerGameCertificateReferenceParams, Alloc>{ model },
        m_gsdkAlias{ SafeString(model.gsdkAlias) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGameCertificateReferenceParamsWrapper(const PFMultiplayerServerGameCertificateReferenceParamsWrapper& src) :
        PFMultiplayerServerGameCertificateReferenceParamsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGameCertificateReferenceParamsWrapper(PFMultiplayerServerGameCertificateReferenceParamsWrapper&& src) :
        PFMultiplayerServerGameCertificateReferenceParamsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGameCertificateReferenceParamsWrapper& operator=(PFMultiplayerServerGameCertificateReferenceParamsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGameCertificateReferenceParamsWrapper() = default;

    friend void swap(PFMultiplayerServerGameCertificateReferenceParamsWrapper& lhs, PFMultiplayerServerGameCertificateReferenceParamsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gsdkAlias, rhs.m_gsdkAlias);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGsdkAlias(String value)
    {
        m_gsdkAlias = std::move(value);
        this->m_model.gsdkAlias =  m_gsdkAlias.empty() ? nullptr : m_gsdkAlias.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.gsdkAlias = m_gsdkAlias.empty() ? nullptr : m_gsdkAlias.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_gsdkAlias;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerLinuxInstrumentationConfigurationWrapper : public ModelWrapper<PFMultiplayerServerLinuxInstrumentationConfiguration, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerLinuxInstrumentationConfiguration;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFMultiplayerServerLinuxInstrumentationConfiguration, Alloc>::ModelWrapper;

    void SetIsEnabled(bool value)
    {
        this->m_model.isEnabled = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper : public ModelWrapper<PFMultiplayerServerMonitoringApplicationConfigurationParams, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerMonitoringApplicationConfigurationParams;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper() = default;

    PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper(const PFMultiplayerServerMonitoringApplicationConfigurationParams& model) :
        ModelWrapper<PFMultiplayerServerMonitoringApplicationConfigurationParams, Alloc>{ model },
        m_assetReference{ model.assetReference ? *model.assetReference : decltype(*model.assetReference){} },
        m_executionScriptName{ SafeString(model.executionScriptName) },
        m_installationScriptName{ SafeString(model.installationScriptName) },
        m_onStartRuntimeInMinutes{ model.onStartRuntimeInMinutes ? StdExtra::optional<double>{ *model.onStartRuntimeInMinutes } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper(const PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper& src) :
        PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper(PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper&& src) :
        PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper& operator=(PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper() = default;

    friend void swap(PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper& lhs, PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assetReference, rhs.m_assetReference);
        swap(lhs.m_executionScriptName, rhs.m_executionScriptName);
        swap(lhs.m_installationScriptName, rhs.m_installationScriptName);
        swap(lhs.m_onStartRuntimeInMinutes, rhs.m_onStartRuntimeInMinutes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssetReference(PFMultiplayerServerAssetReferenceParamsWrapper<Alloc> value)
    {
        m_assetReference = std::move(value);
        this->m_model.assetReference = &m_assetReference.Model();
    }

    void SetExecutionScriptName(String value)
    {
        m_executionScriptName = std::move(value);
        this->m_model.executionScriptName =  m_executionScriptName.empty() ? nullptr : m_executionScriptName.data();
    }

    void SetInstallationScriptName(String value)
    {
        m_installationScriptName = std::move(value);
        this->m_model.installationScriptName =  m_installationScriptName.empty() ? nullptr : m_installationScriptName.data();
    }

    void SetOnStartRuntimeInMinutes(StdExtra::optional<double> value)
    {
        m_onStartRuntimeInMinutes = std::move(value);
        this->m_model.onStartRuntimeInMinutes = m_onStartRuntimeInMinutes ? m_onStartRuntimeInMinutes.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.assetReference = &m_assetReference.Model();
        this->m_model.executionScriptName = m_executionScriptName.empty() ? nullptr : m_executionScriptName.data();
        this->m_model.installationScriptName = m_installationScriptName.empty() ? nullptr : m_installationScriptName.data();
        this->m_model.onStartRuntimeInMinutes = m_onStartRuntimeInMinutes ? m_onStartRuntimeInMinutes.operator->() : nullptr;
    }

    PFMultiplayerServerAssetReferenceParamsWrapper<Alloc> m_assetReference;
    String m_executionScriptName;
    String m_installationScriptName;
    StdExtra::optional<double> m_onStartRuntimeInMinutes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDynamicStandbyThresholdWrapper : public ModelWrapper<PFMultiplayerServerDynamicStandbyThreshold, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDynamicStandbyThreshold;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFMultiplayerServerDynamicStandbyThreshold, Alloc>::ModelWrapper;

    void SetMultiplier(double value)
    {
        this->m_model.multiplier = value;
    }

    void SetTriggerThresholdPercentage(double value)
    {
        this->m_model.triggerThresholdPercentage = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDynamicStandbySettingsWrapper : public ModelWrapper<PFMultiplayerServerDynamicStandbySettings, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDynamicStandbySettings;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDynamicStandbySettingsWrapper() = default;

    PFMultiplayerServerDynamicStandbySettingsWrapper(const PFMultiplayerServerDynamicStandbySettings& model) :
        ModelWrapper<PFMultiplayerServerDynamicStandbySettings, Alloc>{ model },
        m_dynamicFloorMultiplierThresholds{ model.dynamicFloorMultiplierThresholds, model.dynamicFloorMultiplierThresholds + model.dynamicFloorMultiplierThresholdsCount },
        m_rampDownSeconds{ model.rampDownSeconds ? StdExtra::optional<int32_t>{ *model.rampDownSeconds } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDynamicStandbySettingsWrapper(const PFMultiplayerServerDynamicStandbySettingsWrapper& src) :
        PFMultiplayerServerDynamicStandbySettingsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDynamicStandbySettingsWrapper(PFMultiplayerServerDynamicStandbySettingsWrapper&& src) :
        PFMultiplayerServerDynamicStandbySettingsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDynamicStandbySettingsWrapper& operator=(PFMultiplayerServerDynamicStandbySettingsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDynamicStandbySettingsWrapper() = default;

    friend void swap(PFMultiplayerServerDynamicStandbySettingsWrapper& lhs, PFMultiplayerServerDynamicStandbySettingsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dynamicFloorMultiplierThresholds, rhs.m_dynamicFloorMultiplierThresholds);
        swap(lhs.m_rampDownSeconds, rhs.m_rampDownSeconds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDynamicFloorMultiplierThresholds(ModelVector<PFMultiplayerServerDynamicStandbyThresholdWrapper<Alloc>, Alloc> value)
    {
        m_dynamicFloorMultiplierThresholds = std::move(value);
        this->m_model.dynamicFloorMultiplierThresholds =  m_dynamicFloorMultiplierThresholds.empty() ? nullptr : m_dynamicFloorMultiplierThresholds.data();
        this->m_model.dynamicFloorMultiplierThresholdsCount =  static_cast<uint32_t>(m_dynamicFloorMultiplierThresholds.size());
    }

    void SetIsEnabled(bool value)
    {
        this->m_model.isEnabled = value;
    }

    void SetRampDownSeconds(StdExtra::optional<int32_t> value)
    {
        m_rampDownSeconds = std::move(value);
        this->m_model.rampDownSeconds = m_rampDownSeconds ? m_rampDownSeconds.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.dynamicFloorMultiplierThresholds = m_dynamicFloorMultiplierThresholds.empty() ? nullptr : m_dynamicFloorMultiplierThresholds.data();
        this->m_model.rampDownSeconds = m_rampDownSeconds ? m_rampDownSeconds.operator->() : nullptr;
    }

    ModelVector<PFMultiplayerServerDynamicStandbyThresholdWrapper<Alloc>, Alloc> m_dynamicFloorMultiplierThresholds;
    StdExtra::optional<int32_t> m_rampDownSeconds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerScheduleWrapper : public ModelWrapper<PFMultiplayerServerSchedule, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerSchedule;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerScheduleWrapper() = default;

    PFMultiplayerServerScheduleWrapper(const PFMultiplayerServerSchedule& model) :
        ModelWrapper<PFMultiplayerServerSchedule, Alloc>{ model },
        m_description{ SafeString(model.description) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerScheduleWrapper(const PFMultiplayerServerScheduleWrapper& src) :
        PFMultiplayerServerScheduleWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerScheduleWrapper(PFMultiplayerServerScheduleWrapper&& src) :
        PFMultiplayerServerScheduleWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerScheduleWrapper& operator=(PFMultiplayerServerScheduleWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerScheduleWrapper() = default;

    friend void swap(PFMultiplayerServerScheduleWrapper& lhs, PFMultiplayerServerScheduleWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetEndTime(time_t value)
    {
        this->m_model.endTime = value;
    }

    void SetIsDisabled(bool value)
    {
        this->m_model.isDisabled = value;
    }

    void SetIsRecurringWeekly(bool value)
    {
        this->m_model.isRecurringWeekly = value;
    }

    void SetStartTime(time_t value)
    {
        this->m_model.startTime = value;
    }

    void SetTargetStandby(int32_t value)
    {
        this->m_model.targetStandby = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
    }

    String m_description;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerScheduledStandbySettingsWrapper : public ModelWrapper<PFMultiplayerServerScheduledStandbySettings, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerScheduledStandbySettings;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerScheduledStandbySettingsWrapper() = default;

    PFMultiplayerServerScheduledStandbySettingsWrapper(const PFMultiplayerServerScheduledStandbySettings& model) :
        ModelWrapper<PFMultiplayerServerScheduledStandbySettings, Alloc>{ model },
        m_scheduleList{ model.scheduleList, model.scheduleList + model.scheduleListCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerScheduledStandbySettingsWrapper(const PFMultiplayerServerScheduledStandbySettingsWrapper& src) :
        PFMultiplayerServerScheduledStandbySettingsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerScheduledStandbySettingsWrapper(PFMultiplayerServerScheduledStandbySettingsWrapper&& src) :
        PFMultiplayerServerScheduledStandbySettingsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerScheduledStandbySettingsWrapper& operator=(PFMultiplayerServerScheduledStandbySettingsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerScheduledStandbySettingsWrapper() = default;

    friend void swap(PFMultiplayerServerScheduledStandbySettingsWrapper& lhs, PFMultiplayerServerScheduledStandbySettingsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_scheduleList, rhs.m_scheduleList);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIsEnabled(bool value)
    {
        this->m_model.isEnabled = value;
    }

    void SetScheduleList(ModelVector<PFMultiplayerServerScheduleWrapper<Alloc>, Alloc> value)
    {
        m_scheduleList = std::move(value);
        this->m_model.scheduleList =  m_scheduleList.empty() ? nullptr : m_scheduleList.data();
        this->m_model.scheduleListCount =  static_cast<uint32_t>(m_scheduleList.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.scheduleList = m_scheduleList.empty() ? nullptr : m_scheduleList.data();
    }

    ModelVector<PFMultiplayerServerScheduleWrapper<Alloc>, Alloc> m_scheduleList;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerBuildRegionParamsWrapper : public ModelWrapper<PFMultiplayerServerBuildRegionParams, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerBuildRegionParams;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerBuildRegionParamsWrapper() = default;

    PFMultiplayerServerBuildRegionParamsWrapper(const PFMultiplayerServerBuildRegionParams& model) :
        ModelWrapper<PFMultiplayerServerBuildRegionParams, Alloc>{ model },
        m_dynamicStandbySettings{ model.dynamicStandbySettings ? StdExtra::optional<PFMultiplayerServerDynamicStandbySettingsWrapper<Alloc>>{ *model.dynamicStandbySettings } : StdExtra::nullopt },
        m_multiplayerServerCountPerVm{ model.multiplayerServerCountPerVm ? StdExtra::optional<int32_t>{ *model.multiplayerServerCountPerVm } : StdExtra::nullopt },
        m_region{ SafeString(model.region) },
        m_scheduledStandbySettings{ model.scheduledStandbySettings ? StdExtra::optional<PFMultiplayerServerScheduledStandbySettingsWrapper<Alloc>>{ *model.scheduledStandbySettings } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerBuildRegionParamsWrapper(const PFMultiplayerServerBuildRegionParamsWrapper& src) :
        PFMultiplayerServerBuildRegionParamsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerBuildRegionParamsWrapper(PFMultiplayerServerBuildRegionParamsWrapper&& src) :
        PFMultiplayerServerBuildRegionParamsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerBuildRegionParamsWrapper& operator=(PFMultiplayerServerBuildRegionParamsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerBuildRegionParamsWrapper() = default;

    friend void swap(PFMultiplayerServerBuildRegionParamsWrapper& lhs, PFMultiplayerServerBuildRegionParamsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dynamicStandbySettings, rhs.m_dynamicStandbySettings);
        swap(lhs.m_multiplayerServerCountPerVm, rhs.m_multiplayerServerCountPerVm);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_scheduledStandbySettings, rhs.m_scheduledStandbySettings);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDynamicStandbySettings(StdExtra::optional<PFMultiplayerServerDynamicStandbySettingsWrapper<Alloc>> value)
    {
        m_dynamicStandbySettings = std::move(value);
        this->m_model.dynamicStandbySettings = m_dynamicStandbySettings ? &m_dynamicStandbySettings->Model() : nullptr;
    }

    void SetMaxServers(int32_t value)
    {
        this->m_model.maxServers = value;
    }

    void SetMultiplayerServerCountPerVm(StdExtra::optional<int32_t> value)
    {
        m_multiplayerServerCountPerVm = std::move(value);
        this->m_model.multiplayerServerCountPerVm = m_multiplayerServerCountPerVm ? m_multiplayerServerCountPerVm.operator->() : nullptr;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetScheduledStandbySettings(StdExtra::optional<PFMultiplayerServerScheduledStandbySettingsWrapper<Alloc>> value)
    {
        m_scheduledStandbySettings = std::move(value);
        this->m_model.scheduledStandbySettings = m_scheduledStandbySettings ? &m_scheduledStandbySettings->Model() : nullptr;
    }

    void SetStandbyServers(int32_t value)
    {
        this->m_model.standbyServers = value;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.dynamicStandbySettings = m_dynamicStandbySettings ?  &m_dynamicStandbySettings->Model() : nullptr;
        this->m_model.multiplayerServerCountPerVm = m_multiplayerServerCountPerVm ? m_multiplayerServerCountPerVm.operator->() : nullptr;
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.scheduledStandbySettings = m_scheduledStandbySettings ?  &m_scheduledStandbySettings->Model() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<PFMultiplayerServerDynamicStandbySettingsWrapper<Alloc>> m_dynamicStandbySettings;
    StdExtra::optional<int32_t> m_multiplayerServerCountPerVm;
    String m_region;
    StdExtra::optional<PFMultiplayerServerScheduledStandbySettingsWrapper<Alloc>> m_scheduledStandbySettings;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildWithCustomContainerRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildWithCustomContainerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper() = default;

    PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper(const PFMultiplayerServerCreateBuildWithCustomContainerRequest& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildWithCustomContainerRequest, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildName{ SafeString(model.buildName) },
        m_containerFlavor{ model.containerFlavor ? StdExtra::optional<PFMultiplayerServerContainerFlavor>{ *model.containerFlavor } : StdExtra::nullopt },
        m_containerImageReference{ model.containerImageReference ? StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>>{ *model.containerImageReference } : StdExtra::nullopt },
        m_containerRunCommand{ SafeString(model.containerRunCommand) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_linuxInstrumentationConfiguration{ model.linuxInstrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Alloc>>{ *model.linuxInstrumentationConfiguration } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_monitoringApplicationConfiguration{ model.monitoringApplicationConfiguration ? StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>>{ *model.monitoringApplicationConfiguration } : StdExtra::nullopt },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper(const PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper& src) :
        PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper(PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper&& src) :
        PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper& operator=(PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper& lhs, PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_containerFlavor, rhs.m_containerFlavor);
        swap(lhs.m_containerImageReference, rhs.m_containerImageReference);
        swap(lhs.m_containerRunCommand, rhs.m_containerRunCommand);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_linuxInstrumentationConfiguration, rhs.m_linuxInstrumentationConfiguration);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_monitoringApplicationConfiguration, rhs.m_monitoringApplicationConfiguration);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetContainerFlavor(StdExtra::optional<PFMultiplayerServerContainerFlavor> value)
    {
        m_containerFlavor = std::move(value);
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
    }

    void SetContainerImageReference(StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>> value)
    {
        m_containerImageReference = std::move(value);
        this->m_model.containerImageReference = m_containerImageReference ? &m_containerImageReference->Model() : nullptr;
    }

    void SetContainerRunCommand(String value)
    {
        m_containerRunCommand = std::move(value);
        this->m_model.containerRunCommand =  m_containerRunCommand.empty() ? nullptr : m_containerRunCommand.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceParamsWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceParamsWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetLinuxInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_linuxInstrumentationConfiguration = std::move(value);
        this->m_model.linuxInstrumentationConfiguration = m_linuxInstrumentationConfiguration ? &m_linuxInstrumentationConfiguration->Model() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMonitoringApplicationConfiguration(StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>> value)
    {
        m_monitoringApplicationConfiguration = std::move(value);
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ? &m_monitoringApplicationConfiguration->Model() : nullptr;
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
        this->m_model.containerImageReference = m_containerImageReference ?  &m_containerImageReference->Model() : nullptr;
        this->m_model.containerRunCommand = m_containerRunCommand.empty() ? nullptr : m_containerRunCommand.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.linuxInstrumentationConfiguration = m_linuxInstrumentationConfiguration ?  &m_linuxInstrumentationConfiguration->Model() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ?  &m_monitoringApplicationConfiguration->Model() : nullptr;
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildName;
    StdExtra::optional<PFMultiplayerServerContainerFlavor> m_containerFlavor;
    StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>> m_containerImageReference;
    String m_containerRunCommand;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFMultiplayerServerAssetReferenceParamsWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceParamsWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    StdExtra::optional<PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Alloc>> m_linuxInstrumentationConfiguration;
    StringDictionaryEntryVector<Alloc> m_metadata;
    StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>> m_monitoringApplicationConfiguration;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> m_regionConfigurations;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerAssetReferenceWrapper : public ModelWrapper<PFMultiplayerServerAssetReference, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerAssetReference;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerAssetReferenceWrapper() = default;

    PFMultiplayerServerAssetReferenceWrapper(const PFMultiplayerServerAssetReference& model) :
        ModelWrapper<PFMultiplayerServerAssetReference, Alloc>{ model },
        m_fileName{ SafeString(model.fileName) },
        m_mountPath{ SafeString(model.mountPath) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerAssetReferenceWrapper(const PFMultiplayerServerAssetReferenceWrapper& src) :
        PFMultiplayerServerAssetReferenceWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerAssetReferenceWrapper(PFMultiplayerServerAssetReferenceWrapper&& src) :
        PFMultiplayerServerAssetReferenceWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerAssetReferenceWrapper& operator=(PFMultiplayerServerAssetReferenceWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerAssetReferenceWrapper() = default;

    friend void swap(PFMultiplayerServerAssetReferenceWrapper& lhs, PFMultiplayerServerAssetReferenceWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fileName, rhs.m_fileName);
        swap(lhs.m_mountPath, rhs.m_mountPath);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

    void SetMountPath(String value)
    {
        m_mountPath = std::move(value);
        this->m_model.mountPath =  m_mountPath.empty() ? nullptr : m_mountPath.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
        this->m_model.mountPath = m_mountPath.empty() ? nullptr : m_mountPath.data();
    }

    String m_fileName;
    String m_mountPath;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGameCertificateReferenceWrapper : public ModelWrapper<PFMultiplayerServerGameCertificateReference, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGameCertificateReference;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGameCertificateReferenceWrapper() = default;

    PFMultiplayerServerGameCertificateReferenceWrapper(const PFMultiplayerServerGameCertificateReference& model) :
        ModelWrapper<PFMultiplayerServerGameCertificateReference, Alloc>{ model },
        m_gsdkAlias{ SafeString(model.gsdkAlias) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGameCertificateReferenceWrapper(const PFMultiplayerServerGameCertificateReferenceWrapper& src) :
        PFMultiplayerServerGameCertificateReferenceWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGameCertificateReferenceWrapper(PFMultiplayerServerGameCertificateReferenceWrapper&& src) :
        PFMultiplayerServerGameCertificateReferenceWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGameCertificateReferenceWrapper& operator=(PFMultiplayerServerGameCertificateReferenceWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGameCertificateReferenceWrapper() = default;

    friend void swap(PFMultiplayerServerGameCertificateReferenceWrapper& lhs, PFMultiplayerServerGameCertificateReferenceWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gsdkAlias, rhs.m_gsdkAlias);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGsdkAlias(String value)
    {
        m_gsdkAlias = std::move(value);
        this->m_model.gsdkAlias =  m_gsdkAlias.empty() ? nullptr : m_gsdkAlias.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.gsdkAlias = m_gsdkAlias.empty() ? nullptr : m_gsdkAlias.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_gsdkAlias;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerMonitoringApplicationConfigurationWrapper : public ModelWrapper<PFMultiplayerServerMonitoringApplicationConfiguration, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerMonitoringApplicationConfiguration;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerMonitoringApplicationConfigurationWrapper() = default;

    PFMultiplayerServerMonitoringApplicationConfigurationWrapper(const PFMultiplayerServerMonitoringApplicationConfiguration& model) :
        ModelWrapper<PFMultiplayerServerMonitoringApplicationConfiguration, Alloc>{ model },
        m_assetReference{ model.assetReference ? *model.assetReference : decltype(*model.assetReference){} },
        m_executionScriptName{ SafeString(model.executionScriptName) },
        m_installationScriptName{ SafeString(model.installationScriptName) },
        m_onStartRuntimeInMinutes{ model.onStartRuntimeInMinutes ? StdExtra::optional<double>{ *model.onStartRuntimeInMinutes } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerMonitoringApplicationConfigurationWrapper(const PFMultiplayerServerMonitoringApplicationConfigurationWrapper& src) :
        PFMultiplayerServerMonitoringApplicationConfigurationWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerMonitoringApplicationConfigurationWrapper(PFMultiplayerServerMonitoringApplicationConfigurationWrapper&& src) :
        PFMultiplayerServerMonitoringApplicationConfigurationWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerMonitoringApplicationConfigurationWrapper& operator=(PFMultiplayerServerMonitoringApplicationConfigurationWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerMonitoringApplicationConfigurationWrapper() = default;

    friend void swap(PFMultiplayerServerMonitoringApplicationConfigurationWrapper& lhs, PFMultiplayerServerMonitoringApplicationConfigurationWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assetReference, rhs.m_assetReference);
        swap(lhs.m_executionScriptName, rhs.m_executionScriptName);
        swap(lhs.m_installationScriptName, rhs.m_installationScriptName);
        swap(lhs.m_onStartRuntimeInMinutes, rhs.m_onStartRuntimeInMinutes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssetReference(PFMultiplayerServerAssetReferenceWrapper<Alloc> value)
    {
        m_assetReference = std::move(value);
        this->m_model.assetReference = &m_assetReference.Model();
    }

    void SetExecutionScriptName(String value)
    {
        m_executionScriptName = std::move(value);
        this->m_model.executionScriptName =  m_executionScriptName.empty() ? nullptr : m_executionScriptName.data();
    }

    void SetInstallationScriptName(String value)
    {
        m_installationScriptName = std::move(value);
        this->m_model.installationScriptName =  m_installationScriptName.empty() ? nullptr : m_installationScriptName.data();
    }

    void SetOnStartRuntimeInMinutes(StdExtra::optional<double> value)
    {
        m_onStartRuntimeInMinutes = std::move(value);
        this->m_model.onStartRuntimeInMinutes = m_onStartRuntimeInMinutes ? m_onStartRuntimeInMinutes.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.assetReference = &m_assetReference.Model();
        this->m_model.executionScriptName = m_executionScriptName.empty() ? nullptr : m_executionScriptName.data();
        this->m_model.installationScriptName = m_installationScriptName.empty() ? nullptr : m_installationScriptName.data();
        this->m_model.onStartRuntimeInMinutes = m_onStartRuntimeInMinutes ? m_onStartRuntimeInMinutes.operator->() : nullptr;
    }

    PFMultiplayerServerAssetReferenceWrapper<Alloc> m_assetReference;
    String m_executionScriptName;
    String m_installationScriptName;
    StdExtra::optional<double> m_onStartRuntimeInMinutes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCurrentServerStatsWrapper : public ModelWrapper<PFMultiplayerServerCurrentServerStats, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCurrentServerStats;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFMultiplayerServerCurrentServerStats, Alloc>::ModelWrapper;

    void SetActive(int32_t value)
    {
        this->m_model.active = value;
    }

    void SetPropping(int32_t value)
    {
        this->m_model.propping = value;
    }

    void SetStandingBy(int32_t value)
    {
        this->m_model.standingBy = value;
    }

    void SetTotal(int32_t value)
    {
        this->m_model.total = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerBuildRegionWrapper : public ModelWrapper<PFMultiplayerServerBuildRegion, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerBuildRegion;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerBuildRegionWrapper() = default;

    PFMultiplayerServerBuildRegionWrapper(const PFMultiplayerServerBuildRegion& model) :
        ModelWrapper<PFMultiplayerServerBuildRegion, Alloc>{ model },
        m_currentServerStats{ model.currentServerStats ? StdExtra::optional<PFMultiplayerServerCurrentServerStatsWrapper<Alloc>>{ *model.currentServerStats } : StdExtra::nullopt },
        m_dynamicStandbySettings{ model.dynamicStandbySettings ? StdExtra::optional<PFMultiplayerServerDynamicStandbySettingsWrapper<Alloc>>{ *model.dynamicStandbySettings } : StdExtra::nullopt },
        m_multiplayerServerCountPerVm{ model.multiplayerServerCountPerVm ? StdExtra::optional<int32_t>{ *model.multiplayerServerCountPerVm } : StdExtra::nullopt },
        m_region{ SafeString(model.region) },
        m_scheduledStandbySettings{ model.scheduledStandbySettings ? StdExtra::optional<PFMultiplayerServerScheduledStandbySettingsWrapper<Alloc>>{ *model.scheduledStandbySettings } : StdExtra::nullopt },
        m_status{ SafeString(model.status) },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerBuildRegionWrapper(const PFMultiplayerServerBuildRegionWrapper& src) :
        PFMultiplayerServerBuildRegionWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerBuildRegionWrapper(PFMultiplayerServerBuildRegionWrapper&& src) :
        PFMultiplayerServerBuildRegionWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerBuildRegionWrapper& operator=(PFMultiplayerServerBuildRegionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerBuildRegionWrapper() = default;

    friend void swap(PFMultiplayerServerBuildRegionWrapper& lhs, PFMultiplayerServerBuildRegionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_currentServerStats, rhs.m_currentServerStats);
        swap(lhs.m_dynamicStandbySettings, rhs.m_dynamicStandbySettings);
        swap(lhs.m_multiplayerServerCountPerVm, rhs.m_multiplayerServerCountPerVm);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_scheduledStandbySettings, rhs.m_scheduledStandbySettings);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCurrentServerStats(StdExtra::optional<PFMultiplayerServerCurrentServerStatsWrapper<Alloc>> value)
    {
        m_currentServerStats = std::move(value);
        this->m_model.currentServerStats = m_currentServerStats ? &m_currentServerStats->Model() : nullptr;
    }

    void SetDynamicStandbySettings(StdExtra::optional<PFMultiplayerServerDynamicStandbySettingsWrapper<Alloc>> value)
    {
        m_dynamicStandbySettings = std::move(value);
        this->m_model.dynamicStandbySettings = m_dynamicStandbySettings ? &m_dynamicStandbySettings->Model() : nullptr;
    }

    void SetMaxServers(int32_t value)
    {
        this->m_model.maxServers = value;
    }

    void SetMultiplayerServerCountPerVm(StdExtra::optional<int32_t> value)
    {
        m_multiplayerServerCountPerVm = std::move(value);
        this->m_model.multiplayerServerCountPerVm = m_multiplayerServerCountPerVm ? m_multiplayerServerCountPerVm.operator->() : nullptr;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetScheduledStandbySettings(StdExtra::optional<PFMultiplayerServerScheduledStandbySettingsWrapper<Alloc>> value)
    {
        m_scheduledStandbySettings = std::move(value);
        this->m_model.scheduledStandbySettings = m_scheduledStandbySettings ? &m_scheduledStandbySettings->Model() : nullptr;
    }

    void SetStandbyServers(int32_t value)
    {
        this->m_model.standbyServers = value;
    }

    void SetStatus(String value)
    {
        m_status = std::move(value);
        this->m_model.status =  m_status.empty() ? nullptr : m_status.data();
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.currentServerStats = m_currentServerStats ?  &m_currentServerStats->Model() : nullptr;
        this->m_model.dynamicStandbySettings = m_dynamicStandbySettings ?  &m_dynamicStandbySettings->Model() : nullptr;
        this->m_model.multiplayerServerCountPerVm = m_multiplayerServerCountPerVm ? m_multiplayerServerCountPerVm.operator->() : nullptr;
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.scheduledStandbySettings = m_scheduledStandbySettings ?  &m_scheduledStandbySettings->Model() : nullptr;
        this->m_model.status = m_status.empty() ? nullptr : m_status.data();
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<PFMultiplayerServerCurrentServerStatsWrapper<Alloc>> m_currentServerStats;
    StdExtra::optional<PFMultiplayerServerDynamicStandbySettingsWrapper<Alloc>> m_dynamicStandbySettings;
    StdExtra::optional<int32_t> m_multiplayerServerCountPerVm;
    String m_region;
    StdExtra::optional<PFMultiplayerServerScheduledStandbySettingsWrapper<Alloc>> m_scheduledStandbySettings;
    String m_status;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildWithCustomContainerResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildWithCustomContainerResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper() = default;

    PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper(const PFMultiplayerServerCreateBuildWithCustomContainerResponse& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildWithCustomContainerResponse, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildId{ SafeString(model.buildId) },
        m_buildName{ SafeString(model.buildName) },
        m_containerFlavor{ model.containerFlavor ? StdExtra::optional<PFMultiplayerServerContainerFlavor>{ *model.containerFlavor } : StdExtra::nullopt },
        m_containerRunCommand{ SafeString(model.containerRunCommand) },
        m_creationTime{ model.creationTime ? StdExtra::optional<time_t>{ *model.creationTime } : StdExtra::nullopt },
        m_customGameContainerImage{ model.customGameContainerImage ? StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>>{ *model.customGameContainerImage } : StdExtra::nullopt },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_linuxInstrumentationConfiguration{ model.linuxInstrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Alloc>>{ *model.linuxInstrumentationConfiguration } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_monitoringApplicationConfiguration{ model.monitoringApplicationConfiguration ? StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>>{ *model.monitoringApplicationConfiguration } : StdExtra::nullopt },
        m_osPlatform{ SafeString(model.osPlatform) },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_serverType{ SafeString(model.serverType) },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper(const PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper& src) :
        PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper(PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper&& src) :
        PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper& operator=(PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper& lhs, PFMultiplayerServerCreateBuildWithCustomContainerResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_containerFlavor, rhs.m_containerFlavor);
        swap(lhs.m_containerRunCommand, rhs.m_containerRunCommand);
        swap(lhs.m_creationTime, rhs.m_creationTime);
        swap(lhs.m_customGameContainerImage, rhs.m_customGameContainerImage);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_linuxInstrumentationConfiguration, rhs.m_linuxInstrumentationConfiguration);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_monitoringApplicationConfiguration, rhs.m_monitoringApplicationConfiguration);
        swap(lhs.m_osPlatform, rhs.m_osPlatform);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_serverType, rhs.m_serverType);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetContainerFlavor(StdExtra::optional<PFMultiplayerServerContainerFlavor> value)
    {
        m_containerFlavor = std::move(value);
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
    }

    void SetContainerRunCommand(String value)
    {
        m_containerRunCommand = std::move(value);
        this->m_model.containerRunCommand =  m_containerRunCommand.empty() ? nullptr : m_containerRunCommand.data();
    }

    void SetCreationTime(StdExtra::optional<time_t> value)
    {
        m_creationTime = std::move(value);
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
    }

    void SetCustomGameContainerImage(StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>> value)
    {
        m_customGameContainerImage = std::move(value);
        this->m_model.customGameContainerImage = m_customGameContainerImage ? &m_customGameContainerImage->Model() : nullptr;
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetLinuxInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_linuxInstrumentationConfiguration = std::move(value);
        this->m_model.linuxInstrumentationConfiguration = m_linuxInstrumentationConfiguration ? &m_linuxInstrumentationConfiguration->Model() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMonitoringApplicationConfiguration(StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>> value)
    {
        m_monitoringApplicationConfiguration = std::move(value);
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ? &m_monitoringApplicationConfiguration->Model() : nullptr;
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetOsPlatform(String value)
    {
        m_osPlatform = std::move(value);
        this->m_model.osPlatform =  m_osPlatform.empty() ? nullptr : m_osPlatform.data();
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetServerType(String value)
    {
        m_serverType = std::move(value);
        this->m_model.serverType =  m_serverType.empty() ? nullptr : m_serverType.data();
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
        this->m_model.containerRunCommand = m_containerRunCommand.empty() ? nullptr : m_containerRunCommand.data();
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
        this->m_model.customGameContainerImage = m_customGameContainerImage ?  &m_customGameContainerImage->Model() : nullptr;
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.linuxInstrumentationConfiguration = m_linuxInstrumentationConfiguration ?  &m_linuxInstrumentationConfiguration->Model() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ?  &m_monitoringApplicationConfiguration->Model() : nullptr;
        this->m_model.osPlatform = m_osPlatform.empty() ? nullptr : m_osPlatform.data();
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.serverType = m_serverType.empty() ? nullptr : m_serverType.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildId;
    String m_buildName;
    StdExtra::optional<PFMultiplayerServerContainerFlavor> m_containerFlavor;
    String m_containerRunCommand;
    StdExtra::optional<time_t> m_creationTime;
    StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>> m_customGameContainerImage;
    ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    StdExtra::optional<PFMultiplayerServerLinuxInstrumentationConfigurationWrapper<Alloc>> m_linuxInstrumentationConfiguration;
    StringDictionaryEntryVector<Alloc> m_metadata;
    StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>> m_monitoringApplicationConfiguration;
    String m_osPlatform;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> m_regionConfigurations;
    String m_serverType;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerInstrumentationConfigurationWrapper : public ModelWrapper<PFMultiplayerServerInstrumentationConfiguration, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerInstrumentationConfiguration;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerInstrumentationConfigurationWrapper() = default;

    PFMultiplayerServerInstrumentationConfigurationWrapper(const PFMultiplayerServerInstrumentationConfiguration& model) :
        ModelWrapper<PFMultiplayerServerInstrumentationConfiguration, Alloc>{ model },
        m_isEnabled{ model.isEnabled ? StdExtra::optional<bool>{ *model.isEnabled } : StdExtra::nullopt },
        m_processesToMonitor{ model.processesToMonitor, model.processesToMonitor + model.processesToMonitorCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerInstrumentationConfigurationWrapper(const PFMultiplayerServerInstrumentationConfigurationWrapper& src) :
        PFMultiplayerServerInstrumentationConfigurationWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerInstrumentationConfigurationWrapper(PFMultiplayerServerInstrumentationConfigurationWrapper&& src) :
        PFMultiplayerServerInstrumentationConfigurationWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerInstrumentationConfigurationWrapper& operator=(PFMultiplayerServerInstrumentationConfigurationWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerInstrumentationConfigurationWrapper() = default;

    friend void swap(PFMultiplayerServerInstrumentationConfigurationWrapper& lhs, PFMultiplayerServerInstrumentationConfigurationWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_isEnabled, rhs.m_isEnabled);
        swap(lhs.m_processesToMonitor, rhs.m_processesToMonitor);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIsEnabled(StdExtra::optional<bool> value)
    {
        m_isEnabled = std::move(value);
        this->m_model.isEnabled = m_isEnabled ? m_isEnabled.operator->() : nullptr;
    }

    void SetProcessesToMonitor(CStringVector<Alloc> value)
    {
        m_processesToMonitor = std::move(value);
        this->m_model.processesToMonitor =  m_processesToMonitor.empty() ? nullptr : m_processesToMonitor.data();
        this->m_model.processesToMonitorCount =  static_cast<uint32_t>(m_processesToMonitor.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.isEnabled = m_isEnabled ? m_isEnabled.operator->() : nullptr;
        this->m_model.processesToMonitor = m_processesToMonitor.empty() ? nullptr : m_processesToMonitor.data();
    }

    StdExtra::optional<bool> m_isEnabled;
    CStringVector<Alloc> m_processesToMonitor;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildWithManagedContainerRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildWithManagedContainerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper() = default;

    PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper(const PFMultiplayerServerCreateBuildWithManagedContainerRequest& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildWithManagedContainerRequest, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildName{ SafeString(model.buildName) },
        m_containerFlavor{ model.containerFlavor ? StdExtra::optional<PFMultiplayerServerContainerFlavor>{ *model.containerFlavor } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_gameWorkingDirectory{ SafeString(model.gameWorkingDirectory) },
        m_instrumentationConfiguration{ model.instrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>>{ *model.instrumentationConfiguration } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_monitoringApplicationConfiguration{ model.monitoringApplicationConfiguration ? StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>>{ *model.monitoringApplicationConfiguration } : StdExtra::nullopt },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_startMultiplayerServerCommand{ SafeString(model.startMultiplayerServerCommand) },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper(const PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper& src) :
        PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper(PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper&& src) :
        PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper& operator=(PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper& lhs, PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_containerFlavor, rhs.m_containerFlavor);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_gameWorkingDirectory, rhs.m_gameWorkingDirectory);
        swap(lhs.m_instrumentationConfiguration, rhs.m_instrumentationConfiguration);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_monitoringApplicationConfiguration, rhs.m_monitoringApplicationConfiguration);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_startMultiplayerServerCommand, rhs.m_startMultiplayerServerCommand);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetContainerFlavor(StdExtra::optional<PFMultiplayerServerContainerFlavor> value)
    {
        m_containerFlavor = std::move(value);
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceParamsWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceParamsWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetGameWorkingDirectory(String value)
    {
        m_gameWorkingDirectory = std::move(value);
        this->m_model.gameWorkingDirectory =  m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
    }

    void SetInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_instrumentationConfiguration = std::move(value);
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ? &m_instrumentationConfiguration->Model() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMonitoringApplicationConfiguration(StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>> value)
    {
        m_monitoringApplicationConfiguration = std::move(value);
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ? &m_monitoringApplicationConfiguration->Model() : nullptr;
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetStartMultiplayerServerCommand(String value)
    {
        m_startMultiplayerServerCommand = std::move(value);
        this->m_model.startMultiplayerServerCommand =  m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameWorkingDirectory = m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ?  &m_instrumentationConfiguration->Model() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ?  &m_monitoringApplicationConfiguration->Model() : nullptr;
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.startMultiplayerServerCommand = m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildName;
    StdExtra::optional<PFMultiplayerServerContainerFlavor> m_containerFlavor;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFMultiplayerServerAssetReferenceParamsWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceParamsWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    String m_gameWorkingDirectory;
    StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> m_instrumentationConfiguration;
    StringDictionaryEntryVector<Alloc> m_metadata;
    StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>> m_monitoringApplicationConfiguration;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> m_regionConfigurations;
    String m_startMultiplayerServerCommand;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildWithManagedContainerResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildWithManagedContainerResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper() = default;

    PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper(const PFMultiplayerServerCreateBuildWithManagedContainerResponse& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildWithManagedContainerResponse, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildId{ SafeString(model.buildId) },
        m_buildName{ SafeString(model.buildName) },
        m_containerFlavor{ model.containerFlavor ? StdExtra::optional<PFMultiplayerServerContainerFlavor>{ *model.containerFlavor } : StdExtra::nullopt },
        m_creationTime{ model.creationTime ? StdExtra::optional<time_t>{ *model.creationTime } : StdExtra::nullopt },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_gameWorkingDirectory{ SafeString(model.gameWorkingDirectory) },
        m_instrumentationConfiguration{ model.instrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>>{ *model.instrumentationConfiguration } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_monitoringApplicationConfiguration{ model.monitoringApplicationConfiguration ? StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>>{ *model.monitoringApplicationConfiguration } : StdExtra::nullopt },
        m_osPlatform{ SafeString(model.osPlatform) },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_serverType{ SafeString(model.serverType) },
        m_startMultiplayerServerCommand{ SafeString(model.startMultiplayerServerCommand) },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper(const PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper& src) :
        PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper(PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper&& src) :
        PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper& operator=(PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper& lhs, PFMultiplayerServerCreateBuildWithManagedContainerResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_containerFlavor, rhs.m_containerFlavor);
        swap(lhs.m_creationTime, rhs.m_creationTime);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_gameWorkingDirectory, rhs.m_gameWorkingDirectory);
        swap(lhs.m_instrumentationConfiguration, rhs.m_instrumentationConfiguration);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_monitoringApplicationConfiguration, rhs.m_monitoringApplicationConfiguration);
        swap(lhs.m_osPlatform, rhs.m_osPlatform);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_serverType, rhs.m_serverType);
        swap(lhs.m_startMultiplayerServerCommand, rhs.m_startMultiplayerServerCommand);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetContainerFlavor(StdExtra::optional<PFMultiplayerServerContainerFlavor> value)
    {
        m_containerFlavor = std::move(value);
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
    }

    void SetCreationTime(StdExtra::optional<time_t> value)
    {
        m_creationTime = std::move(value);
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetGameWorkingDirectory(String value)
    {
        m_gameWorkingDirectory = std::move(value);
        this->m_model.gameWorkingDirectory =  m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
    }

    void SetInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_instrumentationConfiguration = std::move(value);
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ? &m_instrumentationConfiguration->Model() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMonitoringApplicationConfiguration(StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>> value)
    {
        m_monitoringApplicationConfiguration = std::move(value);
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ? &m_monitoringApplicationConfiguration->Model() : nullptr;
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetOsPlatform(String value)
    {
        m_osPlatform = std::move(value);
        this->m_model.osPlatform =  m_osPlatform.empty() ? nullptr : m_osPlatform.data();
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetServerType(String value)
    {
        m_serverType = std::move(value);
        this->m_model.serverType =  m_serverType.empty() ? nullptr : m_serverType.data();
    }

    void SetStartMultiplayerServerCommand(String value)
    {
        m_startMultiplayerServerCommand = std::move(value);
        this->m_model.startMultiplayerServerCommand =  m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameWorkingDirectory = m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ?  &m_instrumentationConfiguration->Model() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ?  &m_monitoringApplicationConfiguration->Model() : nullptr;
        this->m_model.osPlatform = m_osPlatform.empty() ? nullptr : m_osPlatform.data();
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.serverType = m_serverType.empty() ? nullptr : m_serverType.data();
        this->m_model.startMultiplayerServerCommand = m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildId;
    String m_buildName;
    StdExtra::optional<PFMultiplayerServerContainerFlavor> m_containerFlavor;
    StdExtra::optional<time_t> m_creationTime;
    ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    String m_gameWorkingDirectory;
    StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> m_instrumentationConfiguration;
    StringDictionaryEntryVector<Alloc> m_metadata;
    StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>> m_monitoringApplicationConfiguration;
    String m_osPlatform;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> m_regionConfigurations;
    String m_serverType;
    String m_startMultiplayerServerCommand;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildWithProcessBasedServerRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildWithProcessBasedServerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper() = default;

    PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper(const PFMultiplayerServerCreateBuildWithProcessBasedServerRequest& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildWithProcessBasedServerRequest, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildName{ SafeString(model.buildName) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_gameWorkingDirectory{ SafeString(model.gameWorkingDirectory) },
        m_instrumentationConfiguration{ model.instrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>>{ *model.instrumentationConfiguration } : StdExtra::nullopt },
        m_isOSPreview{ model.isOSPreview ? StdExtra::optional<bool>{ *model.isOSPreview } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_monitoringApplicationConfiguration{ model.monitoringApplicationConfiguration ? StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>>{ *model.monitoringApplicationConfiguration } : StdExtra::nullopt },
        m_osPlatform{ SafeString(model.osPlatform) },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_startMultiplayerServerCommand{ SafeString(model.startMultiplayerServerCommand) },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper(const PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper& src) :
        PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper(PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper&& src) :
        PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper& operator=(PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper& lhs, PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_gameWorkingDirectory, rhs.m_gameWorkingDirectory);
        swap(lhs.m_instrumentationConfiguration, rhs.m_instrumentationConfiguration);
        swap(lhs.m_isOSPreview, rhs.m_isOSPreview);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_monitoringApplicationConfiguration, rhs.m_monitoringApplicationConfiguration);
        swap(lhs.m_osPlatform, rhs.m_osPlatform);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_startMultiplayerServerCommand, rhs.m_startMultiplayerServerCommand);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceParamsWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceParamsWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetGameWorkingDirectory(String value)
    {
        m_gameWorkingDirectory = std::move(value);
        this->m_model.gameWorkingDirectory =  m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
    }

    void SetInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_instrumentationConfiguration = std::move(value);
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ? &m_instrumentationConfiguration->Model() : nullptr;
    }

    void SetIsOSPreview(StdExtra::optional<bool> value)
    {
        m_isOSPreview = std::move(value);
        this->m_model.isOSPreview = m_isOSPreview ? m_isOSPreview.operator->() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMonitoringApplicationConfiguration(StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>> value)
    {
        m_monitoringApplicationConfiguration = std::move(value);
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ? &m_monitoringApplicationConfiguration->Model() : nullptr;
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetOsPlatform(String value)
    {
        m_osPlatform = std::move(value);
        this->m_model.osPlatform =  m_osPlatform.empty() ? nullptr : m_osPlatform.data();
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetStartMultiplayerServerCommand(String value)
    {
        m_startMultiplayerServerCommand = std::move(value);
        this->m_model.startMultiplayerServerCommand =  m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameWorkingDirectory = m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ?  &m_instrumentationConfiguration->Model() : nullptr;
        this->m_model.isOSPreview = m_isOSPreview ? m_isOSPreview.operator->() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ?  &m_monitoringApplicationConfiguration->Model() : nullptr;
        this->m_model.osPlatform = m_osPlatform.empty() ? nullptr : m_osPlatform.data();
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.startMultiplayerServerCommand = m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildName;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFMultiplayerServerAssetReferenceParamsWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceParamsWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    String m_gameWorkingDirectory;
    StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> m_instrumentationConfiguration;
    StdExtra::optional<bool> m_isOSPreview;
    StringDictionaryEntryVector<Alloc> m_metadata;
    StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationParamsWrapper<Alloc>> m_monitoringApplicationConfiguration;
    String m_osPlatform;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> m_regionConfigurations;
    String m_startMultiplayerServerCommand;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper : public ModelWrapper<PFMultiplayerServerCreateBuildWithProcessBasedServerResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateBuildWithProcessBasedServerResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper() = default;

    PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper(const PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& model) :
        ModelWrapper<PFMultiplayerServerCreateBuildWithProcessBasedServerResponse, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildId{ SafeString(model.buildId) },
        m_buildName{ SafeString(model.buildName) },
        m_containerFlavor{ model.containerFlavor ? StdExtra::optional<PFMultiplayerServerContainerFlavor>{ *model.containerFlavor } : StdExtra::nullopt },
        m_creationTime{ model.creationTime ? StdExtra::optional<time_t>{ *model.creationTime } : StdExtra::nullopt },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_gameWorkingDirectory{ SafeString(model.gameWorkingDirectory) },
        m_instrumentationConfiguration{ model.instrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>>{ *model.instrumentationConfiguration } : StdExtra::nullopt },
        m_isOSPreview{ model.isOSPreview ? StdExtra::optional<bool>{ *model.isOSPreview } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_monitoringApplicationConfiguration{ model.monitoringApplicationConfiguration ? StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>>{ *model.monitoringApplicationConfiguration } : StdExtra::nullopt },
        m_osPlatform{ SafeString(model.osPlatform) },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_serverType{ SafeString(model.serverType) },
        m_startMultiplayerServerCommand{ SafeString(model.startMultiplayerServerCommand) },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper(const PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper& src) :
        PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper(PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper&& src) :
        PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper& operator=(PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper() = default;

    friend void swap(PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper& lhs, PFMultiplayerServerCreateBuildWithProcessBasedServerResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_containerFlavor, rhs.m_containerFlavor);
        swap(lhs.m_creationTime, rhs.m_creationTime);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_gameWorkingDirectory, rhs.m_gameWorkingDirectory);
        swap(lhs.m_instrumentationConfiguration, rhs.m_instrumentationConfiguration);
        swap(lhs.m_isOSPreview, rhs.m_isOSPreview);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_monitoringApplicationConfiguration, rhs.m_monitoringApplicationConfiguration);
        swap(lhs.m_osPlatform, rhs.m_osPlatform);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_serverType, rhs.m_serverType);
        swap(lhs.m_startMultiplayerServerCommand, rhs.m_startMultiplayerServerCommand);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetContainerFlavor(StdExtra::optional<PFMultiplayerServerContainerFlavor> value)
    {
        m_containerFlavor = std::move(value);
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
    }

    void SetCreationTime(StdExtra::optional<time_t> value)
    {
        m_creationTime = std::move(value);
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetGameWorkingDirectory(String value)
    {
        m_gameWorkingDirectory = std::move(value);
        this->m_model.gameWorkingDirectory =  m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
    }

    void SetInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_instrumentationConfiguration = std::move(value);
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ? &m_instrumentationConfiguration->Model() : nullptr;
    }

    void SetIsOSPreview(StdExtra::optional<bool> value)
    {
        m_isOSPreview = std::move(value);
        this->m_model.isOSPreview = m_isOSPreview ? m_isOSPreview.operator->() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMonitoringApplicationConfiguration(StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>> value)
    {
        m_monitoringApplicationConfiguration = std::move(value);
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ? &m_monitoringApplicationConfiguration->Model() : nullptr;
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetOsPlatform(String value)
    {
        m_osPlatform = std::move(value);
        this->m_model.osPlatform =  m_osPlatform.empty() ? nullptr : m_osPlatform.data();
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetServerType(String value)
    {
        m_serverType = std::move(value);
        this->m_model.serverType =  m_serverType.empty() ? nullptr : m_serverType.data();
    }

    void SetStartMultiplayerServerCommand(String value)
    {
        m_startMultiplayerServerCommand = std::move(value);
        this->m_model.startMultiplayerServerCommand =  m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameWorkingDirectory = m_gameWorkingDirectory.empty() ? nullptr : m_gameWorkingDirectory.data();
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ?  &m_instrumentationConfiguration->Model() : nullptr;
        this->m_model.isOSPreview = m_isOSPreview ? m_isOSPreview.operator->() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.monitoringApplicationConfiguration = m_monitoringApplicationConfiguration ?  &m_monitoringApplicationConfiguration->Model() : nullptr;
        this->m_model.osPlatform = m_osPlatform.empty() ? nullptr : m_osPlatform.data();
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.serverType = m_serverType.empty() ? nullptr : m_serverType.data();
        this->m_model.startMultiplayerServerCommand = m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildId;
    String m_buildName;
    StdExtra::optional<PFMultiplayerServerContainerFlavor> m_containerFlavor;
    StdExtra::optional<time_t> m_creationTime;
    ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    String m_gameWorkingDirectory;
    StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> m_instrumentationConfiguration;
    StdExtra::optional<bool> m_isOSPreview;
    StringDictionaryEntryVector<Alloc> m_metadata;
    StdExtra::optional<PFMultiplayerServerMonitoringApplicationConfigurationWrapper<Alloc>> m_monitoringApplicationConfiguration;
    String m_osPlatform;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> m_regionConfigurations;
    String m_serverType;
    String m_startMultiplayerServerCommand;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateRemoteUserRequestWrapper : public ModelWrapper<PFMultiplayerServerCreateRemoteUserRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateRemoteUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateRemoteUserRequestWrapper() = default;

    PFMultiplayerServerCreateRemoteUserRequestWrapper(const PFMultiplayerServerCreateRemoteUserRequest& model) :
        ModelWrapper<PFMultiplayerServerCreateRemoteUserRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_expirationTime{ model.expirationTime ? StdExtra::optional<time_t>{ *model.expirationTime } : StdExtra::nullopt },
        m_region{ SafeString(model.region) },
        m_username{ SafeString(model.username) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateRemoteUserRequestWrapper(const PFMultiplayerServerCreateRemoteUserRequestWrapper& src) :
        PFMultiplayerServerCreateRemoteUserRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateRemoteUserRequestWrapper(PFMultiplayerServerCreateRemoteUserRequestWrapper&& src) :
        PFMultiplayerServerCreateRemoteUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateRemoteUserRequestWrapper& operator=(PFMultiplayerServerCreateRemoteUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateRemoteUserRequestWrapper() = default;

    friend void swap(PFMultiplayerServerCreateRemoteUserRequestWrapper& lhs, PFMultiplayerServerCreateRemoteUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_expirationTime, rhs.m_expirationTime);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_username, rhs.m_username);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExpirationTime(StdExtra::optional<time_t> value)
    {
        m_expirationTime = std::move(value);
        this->m_model.expirationTime = m_expirationTime ? m_expirationTime.operator->() : nullptr;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.expirationTime = m_expirationTime ? m_expirationTime.operator->() : nullptr;
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<time_t> m_expirationTime;
    String m_region;
    String m_username;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateRemoteUserResponseWrapper : public ModelWrapper<PFMultiplayerServerCreateRemoteUserResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateRemoteUserResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateRemoteUserResponseWrapper() = default;

    PFMultiplayerServerCreateRemoteUserResponseWrapper(const PFMultiplayerServerCreateRemoteUserResponse& model) :
        ModelWrapper<PFMultiplayerServerCreateRemoteUserResponse, Alloc>{ model },
        m_expirationTime{ model.expirationTime ? StdExtra::optional<time_t>{ *model.expirationTime } : StdExtra::nullopt },
        m_password{ SafeString(model.password) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateRemoteUserResponseWrapper(const PFMultiplayerServerCreateRemoteUserResponseWrapper& src) :
        PFMultiplayerServerCreateRemoteUserResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateRemoteUserResponseWrapper(PFMultiplayerServerCreateRemoteUserResponseWrapper&& src) :
        PFMultiplayerServerCreateRemoteUserResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateRemoteUserResponseWrapper& operator=(PFMultiplayerServerCreateRemoteUserResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateRemoteUserResponseWrapper() = default;

    friend void swap(PFMultiplayerServerCreateRemoteUserResponseWrapper& lhs, PFMultiplayerServerCreateRemoteUserResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_expirationTime, rhs.m_expirationTime);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExpirationTime(StdExtra::optional<time_t> value)
    {
        m_expirationTime = std::move(value);
        this->m_model.expirationTime = m_expirationTime ? m_expirationTime.operator->() : nullptr;
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
        this->m_model.expirationTime = m_expirationTime ? m_expirationTime.operator->() : nullptr;
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    StdExtra::optional<time_t> m_expirationTime;
    String m_password;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCoreCapacityChangeWrapper : public ModelWrapper<PFMultiplayerServerCoreCapacityChange, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCoreCapacityChange;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCoreCapacityChangeWrapper() = default;

    PFMultiplayerServerCoreCapacityChangeWrapper(const PFMultiplayerServerCoreCapacityChange& model) :
        ModelWrapper<PFMultiplayerServerCoreCapacityChange, Alloc>{ model },
        m_region{ SafeString(model.region) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCoreCapacityChangeWrapper(const PFMultiplayerServerCoreCapacityChangeWrapper& src) :
        PFMultiplayerServerCoreCapacityChangeWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCoreCapacityChangeWrapper(PFMultiplayerServerCoreCapacityChangeWrapper&& src) :
        PFMultiplayerServerCoreCapacityChangeWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCoreCapacityChangeWrapper& operator=(PFMultiplayerServerCoreCapacityChangeWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCoreCapacityChangeWrapper() = default;

    friend void swap(PFMultiplayerServerCoreCapacityChangeWrapper& lhs, PFMultiplayerServerCoreCapacityChangeWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_region, rhs.m_region);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNewCoreLimit(int32_t value)
    {
        this->m_model.newCoreLimit = value;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetVmFamily(PFMultiplayerServerAzureVmFamily value)
    {
        this->m_model.vmFamily = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
    }

    String m_region;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper : public ModelWrapper<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper() = default;

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest& model) :
        ModelWrapper<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest, Alloc>{ model },
        m_changeDescription{ SafeString(model.changeDescription) },
        m_changes{ model.changes, model.changes + model.changesCount },
        m_contactEmail{ SafeString(model.contactEmail) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_notes{ SafeString(model.notes) },
        m_startDate{ model.startDate ? StdExtra::optional<time_t>{ *model.startDate } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper& src) :
        PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper&& src) :
        PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper& operator=(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper() = default;

    friend void swap(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper& lhs, PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_changeDescription, rhs.m_changeDescription);
        swap(lhs.m_changes, rhs.m_changes);
        swap(lhs.m_contactEmail, rhs.m_contactEmail);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_notes, rhs.m_notes);
        swap(lhs.m_startDate, rhs.m_startDate);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChangeDescription(String value)
    {
        m_changeDescription = std::move(value);
        this->m_model.changeDescription =  m_changeDescription.empty() ? nullptr : m_changeDescription.data();
    }

    void SetChanges(ModelVector<PFMultiplayerServerCoreCapacityChangeWrapper<Alloc>, Alloc> value)
    {
        m_changes = std::move(value);
        this->m_model.changes =  m_changes.empty() ? nullptr : m_changes.data();
        this->m_model.changesCount =  static_cast<uint32_t>(m_changes.size());
    }

    void SetContactEmail(String value)
    {
        m_contactEmail = std::move(value);
        this->m_model.contactEmail =  m_contactEmail.empty() ? nullptr : m_contactEmail.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetNotes(String value)
    {
        m_notes = std::move(value);
        this->m_model.notes =  m_notes.empty() ? nullptr : m_notes.data();
    }

    void SetStartDate(StdExtra::optional<time_t> value)
    {
        m_startDate = std::move(value);
        this->m_model.startDate = m_startDate ? m_startDate.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.changeDescription = m_changeDescription.empty() ? nullptr : m_changeDescription.data();
        this->m_model.changes = m_changes.empty() ? nullptr : m_changes.data();
        this->m_model.contactEmail = m_contactEmail.empty() ? nullptr : m_contactEmail.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.notes = m_notes.empty() ? nullptr : m_notes.data();
        this->m_model.startDate = m_startDate ? m_startDate.operator->() : nullptr;
    }

    String m_changeDescription;
    ModelVector<PFMultiplayerServerCoreCapacityChangeWrapper<Alloc>, Alloc> m_changes;
    String m_contactEmail;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_notes;
    StdExtra::optional<time_t> m_startDate;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper : public ModelWrapper<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper() = default;

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& model) :
        ModelWrapper<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse, Alloc>{ model },
        m_requestId{ SafeString(model.requestId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper& src) :
        PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper&& src) :
        PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper& operator=(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper() = default;

    friend void swap(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper& lhs, PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_requestId, rhs.m_requestId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetRequestId(String value)
    {
        m_requestId = std::move(value);
        this->m_model.requestId =  m_requestId.empty() ? nullptr : m_requestId.data();
    }

    void SetWasApproved(bool value)
    {
        this->m_model.wasApproved = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.requestId = m_requestId.empty() ? nullptr : m_requestId.data();
    }

    String m_requestId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteAssetRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteAssetRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteAssetRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteAssetRequestWrapper() = default;

    PFMultiplayerServerDeleteAssetRequestWrapper(const PFMultiplayerServerDeleteAssetRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteAssetRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteAssetRequestWrapper(const PFMultiplayerServerDeleteAssetRequestWrapper& src) :
        PFMultiplayerServerDeleteAssetRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteAssetRequestWrapper(PFMultiplayerServerDeleteAssetRequestWrapper&& src) :
        PFMultiplayerServerDeleteAssetRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteAssetRequestWrapper& operator=(PFMultiplayerServerDeleteAssetRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteAssetRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteAssetRequestWrapper& lhs, PFMultiplayerServerDeleteAssetRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteBuildRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteBuildRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteBuildRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteBuildRequestWrapper() = default;

    PFMultiplayerServerDeleteBuildRequestWrapper(const PFMultiplayerServerDeleteBuildRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteBuildRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteBuildRequestWrapper(const PFMultiplayerServerDeleteBuildRequestWrapper& src) :
        PFMultiplayerServerDeleteBuildRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteBuildRequestWrapper(PFMultiplayerServerDeleteBuildRequestWrapper&& src) :
        PFMultiplayerServerDeleteBuildRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteBuildRequestWrapper& operator=(PFMultiplayerServerDeleteBuildRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteBuildRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteBuildRequestWrapper& lhs, PFMultiplayerServerDeleteBuildRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
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
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteBuildAliasRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteBuildAliasRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteBuildAliasRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteBuildAliasRequestWrapper() = default;

    PFMultiplayerServerDeleteBuildAliasRequestWrapper(const PFMultiplayerServerDeleteBuildAliasRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteBuildAliasRequest, Alloc>{ model },
        m_aliasId{ SafeString(model.aliasId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteBuildAliasRequestWrapper(const PFMultiplayerServerDeleteBuildAliasRequestWrapper& src) :
        PFMultiplayerServerDeleteBuildAliasRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteBuildAliasRequestWrapper(PFMultiplayerServerDeleteBuildAliasRequestWrapper&& src) :
        PFMultiplayerServerDeleteBuildAliasRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteBuildAliasRequestWrapper& operator=(PFMultiplayerServerDeleteBuildAliasRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteBuildAliasRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteBuildAliasRequestWrapper& lhs, PFMultiplayerServerDeleteBuildAliasRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aliasId, rhs.m_aliasId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAliasId(String value)
    {
        m_aliasId = std::move(value);
        this->m_model.aliasId =  m_aliasId.empty() ? nullptr : m_aliasId.data();
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
        this->m_model.aliasId = m_aliasId.empty() ? nullptr : m_aliasId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_aliasId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteBuildRegionRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteBuildRegionRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteBuildRegionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteBuildRegionRequestWrapper() = default;

    PFMultiplayerServerDeleteBuildRegionRequestWrapper(const PFMultiplayerServerDeleteBuildRegionRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteBuildRegionRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_region{ SafeString(model.region) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteBuildRegionRequestWrapper(const PFMultiplayerServerDeleteBuildRegionRequestWrapper& src) :
        PFMultiplayerServerDeleteBuildRegionRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteBuildRegionRequestWrapper(PFMultiplayerServerDeleteBuildRegionRequestWrapper&& src) :
        PFMultiplayerServerDeleteBuildRegionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteBuildRegionRequestWrapper& operator=(PFMultiplayerServerDeleteBuildRegionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteBuildRegionRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteBuildRegionRequestWrapper& lhs, PFMultiplayerServerDeleteBuildRegionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_region, rhs.m_region);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_region;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteCertificateRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteCertificateRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteCertificateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteCertificateRequestWrapper() = default;

    PFMultiplayerServerDeleteCertificateRequestWrapper(const PFMultiplayerServerDeleteCertificateRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteCertificateRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteCertificateRequestWrapper(const PFMultiplayerServerDeleteCertificateRequestWrapper& src) :
        PFMultiplayerServerDeleteCertificateRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteCertificateRequestWrapper(PFMultiplayerServerDeleteCertificateRequestWrapper&& src) :
        PFMultiplayerServerDeleteCertificateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteCertificateRequestWrapper& operator=(PFMultiplayerServerDeleteCertificateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteCertificateRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteCertificateRequestWrapper& lhs, PFMultiplayerServerDeleteCertificateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteContainerImageRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteContainerImageRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteContainerImageRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteContainerImageRequestWrapper() = default;

    PFMultiplayerServerDeleteContainerImageRequestWrapper(const PFMultiplayerServerDeleteContainerImageRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteContainerImageRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_imageName{ SafeString(model.imageName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteContainerImageRequestWrapper(const PFMultiplayerServerDeleteContainerImageRequestWrapper& src) :
        PFMultiplayerServerDeleteContainerImageRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteContainerImageRequestWrapper(PFMultiplayerServerDeleteContainerImageRequestWrapper&& src) :
        PFMultiplayerServerDeleteContainerImageRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteContainerImageRequestWrapper& operator=(PFMultiplayerServerDeleteContainerImageRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteContainerImageRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteContainerImageRequestWrapper& lhs, PFMultiplayerServerDeleteContainerImageRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_imageName, rhs.m_imageName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetImageName(String value)
    {
        m_imageName = std::move(value);
        this->m_model.imageName =  m_imageName.empty() ? nullptr : m_imageName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.imageName = m_imageName.empty() ? nullptr : m_imageName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_imageName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerDeleteRemoteUserRequestWrapper : public ModelWrapper<PFMultiplayerServerDeleteRemoteUserRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerDeleteRemoteUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerDeleteRemoteUserRequestWrapper() = default;

    PFMultiplayerServerDeleteRemoteUserRequestWrapper(const PFMultiplayerServerDeleteRemoteUserRequest& model) :
        ModelWrapper<PFMultiplayerServerDeleteRemoteUserRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_region{ SafeString(model.region) },
        m_username{ SafeString(model.username) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerDeleteRemoteUserRequestWrapper(const PFMultiplayerServerDeleteRemoteUserRequestWrapper& src) :
        PFMultiplayerServerDeleteRemoteUserRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerDeleteRemoteUserRequestWrapper(PFMultiplayerServerDeleteRemoteUserRequestWrapper&& src) :
        PFMultiplayerServerDeleteRemoteUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerDeleteRemoteUserRequestWrapper& operator=(PFMultiplayerServerDeleteRemoteUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerDeleteRemoteUserRequestWrapper() = default;

    friend void swap(PFMultiplayerServerDeleteRemoteUserRequestWrapper& lhs, PFMultiplayerServerDeleteRemoteUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_username, rhs.m_username);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_region;
    String m_username;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper : public ModelWrapper<PFMultiplayerServerEnableMultiplayerServersForTitleRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerEnableMultiplayerServersForTitleRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper() = default;

    PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper(const PFMultiplayerServerEnableMultiplayerServersForTitleRequest& model) :
        ModelWrapper<PFMultiplayerServerEnableMultiplayerServersForTitleRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper(const PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper& src) :
        PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper(PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper&& src) :
        PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper& operator=(PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper() = default;

    friend void swap(PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper& lhs, PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper& rhs)
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
class PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper : public ModelWrapper<PFMultiplayerServerEnableMultiplayerServersForTitleResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerEnableMultiplayerServersForTitleResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper() = default;

    PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper(const PFMultiplayerServerEnableMultiplayerServersForTitleResponse& model) :
        ModelWrapper<PFMultiplayerServerEnableMultiplayerServersForTitleResponse, Alloc>{ model },
        m_status{ model.status ? StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus>{ *model.status } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper(const PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper& src) :
        PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper(PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper&& src) :
        PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper& operator=(PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper() = default;

    friend void swap(PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper& lhs, PFMultiplayerServerEnableMultiplayerServersForTitleResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_status, rhs.m_status);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatus(StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus> m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetAssetDownloadUrlRequestWrapper : public ModelWrapper<PFMultiplayerServerGetAssetDownloadUrlRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetAssetDownloadUrlRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetAssetDownloadUrlRequestWrapper() = default;

    PFMultiplayerServerGetAssetDownloadUrlRequestWrapper(const PFMultiplayerServerGetAssetDownloadUrlRequest& model) :
        ModelWrapper<PFMultiplayerServerGetAssetDownloadUrlRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetAssetDownloadUrlRequestWrapper(const PFMultiplayerServerGetAssetDownloadUrlRequestWrapper& src) :
        PFMultiplayerServerGetAssetDownloadUrlRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetAssetDownloadUrlRequestWrapper(PFMultiplayerServerGetAssetDownloadUrlRequestWrapper&& src) :
        PFMultiplayerServerGetAssetDownloadUrlRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetAssetDownloadUrlRequestWrapper& operator=(PFMultiplayerServerGetAssetDownloadUrlRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetAssetDownloadUrlRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetAssetDownloadUrlRequestWrapper& lhs, PFMultiplayerServerGetAssetDownloadUrlRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetAssetDownloadUrlResponseWrapper : public ModelWrapper<PFMultiplayerServerGetAssetDownloadUrlResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetAssetDownloadUrlResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetAssetDownloadUrlResponseWrapper() = default;

    PFMultiplayerServerGetAssetDownloadUrlResponseWrapper(const PFMultiplayerServerGetAssetDownloadUrlResponse& model) :
        ModelWrapper<PFMultiplayerServerGetAssetDownloadUrlResponse, Alloc>{ model },
        m_assetDownloadUrl{ SafeString(model.assetDownloadUrl) },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetAssetDownloadUrlResponseWrapper(const PFMultiplayerServerGetAssetDownloadUrlResponseWrapper& src) :
        PFMultiplayerServerGetAssetDownloadUrlResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetAssetDownloadUrlResponseWrapper(PFMultiplayerServerGetAssetDownloadUrlResponseWrapper&& src) :
        PFMultiplayerServerGetAssetDownloadUrlResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetAssetDownloadUrlResponseWrapper& operator=(PFMultiplayerServerGetAssetDownloadUrlResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetAssetDownloadUrlResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetAssetDownloadUrlResponseWrapper& lhs, PFMultiplayerServerGetAssetDownloadUrlResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assetDownloadUrl, rhs.m_assetDownloadUrl);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssetDownloadUrl(String value)
    {
        m_assetDownloadUrl = std::move(value);
        this->m_model.assetDownloadUrl =  m_assetDownloadUrl.empty() ? nullptr : m_assetDownloadUrl.data();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.assetDownloadUrl = m_assetDownloadUrl.empty() ? nullptr : m_assetDownloadUrl.data();
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    String m_assetDownloadUrl;
    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetAssetUploadUrlRequestWrapper : public ModelWrapper<PFMultiplayerServerGetAssetUploadUrlRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetAssetUploadUrlRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetAssetUploadUrlRequestWrapper() = default;

    PFMultiplayerServerGetAssetUploadUrlRequestWrapper(const PFMultiplayerServerGetAssetUploadUrlRequest& model) :
        ModelWrapper<PFMultiplayerServerGetAssetUploadUrlRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetAssetUploadUrlRequestWrapper(const PFMultiplayerServerGetAssetUploadUrlRequestWrapper& src) :
        PFMultiplayerServerGetAssetUploadUrlRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetAssetUploadUrlRequestWrapper(PFMultiplayerServerGetAssetUploadUrlRequestWrapper&& src) :
        PFMultiplayerServerGetAssetUploadUrlRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetAssetUploadUrlRequestWrapper& operator=(PFMultiplayerServerGetAssetUploadUrlRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetAssetUploadUrlRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetAssetUploadUrlRequestWrapper& lhs, PFMultiplayerServerGetAssetUploadUrlRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetAssetUploadUrlResponseWrapper : public ModelWrapper<PFMultiplayerServerGetAssetUploadUrlResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetAssetUploadUrlResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetAssetUploadUrlResponseWrapper() = default;

    PFMultiplayerServerGetAssetUploadUrlResponseWrapper(const PFMultiplayerServerGetAssetUploadUrlResponse& model) :
        ModelWrapper<PFMultiplayerServerGetAssetUploadUrlResponse, Alloc>{ model },
        m_assetUploadUrl{ SafeString(model.assetUploadUrl) },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetAssetUploadUrlResponseWrapper(const PFMultiplayerServerGetAssetUploadUrlResponseWrapper& src) :
        PFMultiplayerServerGetAssetUploadUrlResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetAssetUploadUrlResponseWrapper(PFMultiplayerServerGetAssetUploadUrlResponseWrapper&& src) :
        PFMultiplayerServerGetAssetUploadUrlResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetAssetUploadUrlResponseWrapper& operator=(PFMultiplayerServerGetAssetUploadUrlResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetAssetUploadUrlResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetAssetUploadUrlResponseWrapper& lhs, PFMultiplayerServerGetAssetUploadUrlResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assetUploadUrl, rhs.m_assetUploadUrl);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssetUploadUrl(String value)
    {
        m_assetUploadUrl = std::move(value);
        this->m_model.assetUploadUrl =  m_assetUploadUrl.empty() ? nullptr : m_assetUploadUrl.data();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.assetUploadUrl = m_assetUploadUrl.empty() ? nullptr : m_assetUploadUrl.data();
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    String m_assetUploadUrl;
    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetBuildRequestWrapper : public ModelWrapper<PFMultiplayerServerGetBuildRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetBuildRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetBuildRequestWrapper() = default;

    PFMultiplayerServerGetBuildRequestWrapper(const PFMultiplayerServerGetBuildRequest& model) :
        ModelWrapper<PFMultiplayerServerGetBuildRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetBuildRequestWrapper(const PFMultiplayerServerGetBuildRequestWrapper& src) :
        PFMultiplayerServerGetBuildRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetBuildRequestWrapper(PFMultiplayerServerGetBuildRequestWrapper&& src) :
        PFMultiplayerServerGetBuildRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetBuildRequestWrapper& operator=(PFMultiplayerServerGetBuildRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetBuildRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetBuildRequestWrapper& lhs, PFMultiplayerServerGetBuildRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
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
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetBuildResponseWrapper : public ModelWrapper<PFMultiplayerServerGetBuildResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetBuildResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetBuildResponseWrapper() = default;

    PFMultiplayerServerGetBuildResponseWrapper(const PFMultiplayerServerGetBuildResponse& model) :
        ModelWrapper<PFMultiplayerServerGetBuildResponse, Alloc>{ model },
        m_areAssetsReadonly{ model.areAssetsReadonly ? StdExtra::optional<bool>{ *model.areAssetsReadonly } : StdExtra::nullopt },
        m_buildId{ SafeString(model.buildId) },
        m_buildName{ SafeString(model.buildName) },
        m_buildStatus{ SafeString(model.buildStatus) },
        m_containerFlavor{ model.containerFlavor ? StdExtra::optional<PFMultiplayerServerContainerFlavor>{ *model.containerFlavor } : StdExtra::nullopt },
        m_containerRunCommand{ SafeString(model.containerRunCommand) },
        m_creationTime{ model.creationTime ? StdExtra::optional<time_t>{ *model.creationTime } : StdExtra::nullopt },
        m_customGameContainerImage{ model.customGameContainerImage ? StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>>{ *model.customGameContainerImage } : StdExtra::nullopt },
        m_gameAssetReferences{ model.gameAssetReferences, model.gameAssetReferences + model.gameAssetReferencesCount },
        m_gameCertificateReferences{ model.gameCertificateReferences, model.gameCertificateReferences + model.gameCertificateReferencesCount },
        m_instrumentationConfiguration{ model.instrumentationConfiguration ? StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>>{ *model.instrumentationConfiguration } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_osPlatform{ SafeString(model.osPlatform) },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount },
        m_serverType{ SafeString(model.serverType) },
        m_startMultiplayerServerCommand{ SafeString(model.startMultiplayerServerCommand) },
        m_useStreamingForAssetDownloads{ model.useStreamingForAssetDownloads ? StdExtra::optional<bool>{ *model.useStreamingForAssetDownloads } : StdExtra::nullopt },
        m_vmSize{ model.vmSize ? StdExtra::optional<PFMultiplayerServerAzureVmSize>{ *model.vmSize } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetBuildResponseWrapper(const PFMultiplayerServerGetBuildResponseWrapper& src) :
        PFMultiplayerServerGetBuildResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetBuildResponseWrapper(PFMultiplayerServerGetBuildResponseWrapper&& src) :
        PFMultiplayerServerGetBuildResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetBuildResponseWrapper& operator=(PFMultiplayerServerGetBuildResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetBuildResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetBuildResponseWrapper& lhs, PFMultiplayerServerGetBuildResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_areAssetsReadonly, rhs.m_areAssetsReadonly);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_buildStatus, rhs.m_buildStatus);
        swap(lhs.m_containerFlavor, rhs.m_containerFlavor);
        swap(lhs.m_containerRunCommand, rhs.m_containerRunCommand);
        swap(lhs.m_creationTime, rhs.m_creationTime);
        swap(lhs.m_customGameContainerImage, rhs.m_customGameContainerImage);
        swap(lhs.m_gameAssetReferences, rhs.m_gameAssetReferences);
        swap(lhs.m_gameCertificateReferences, rhs.m_gameCertificateReferences);
        swap(lhs.m_instrumentationConfiguration, rhs.m_instrumentationConfiguration);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_osPlatform, rhs.m_osPlatform);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        swap(lhs.m_serverType, rhs.m_serverType);
        swap(lhs.m_startMultiplayerServerCommand, rhs.m_startMultiplayerServerCommand);
        swap(lhs.m_useStreamingForAssetDownloads, rhs.m_useStreamingForAssetDownloads);
        swap(lhs.m_vmSize, rhs.m_vmSize);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAreAssetsReadonly(StdExtra::optional<bool> value)
    {
        m_areAssetsReadonly = std::move(value);
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetBuildStatus(String value)
    {
        m_buildStatus = std::move(value);
        this->m_model.buildStatus =  m_buildStatus.empty() ? nullptr : m_buildStatus.data();
    }

    void SetContainerFlavor(StdExtra::optional<PFMultiplayerServerContainerFlavor> value)
    {
        m_containerFlavor = std::move(value);
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
    }

    void SetContainerRunCommand(String value)
    {
        m_containerRunCommand = std::move(value);
        this->m_model.containerRunCommand =  m_containerRunCommand.empty() ? nullptr : m_containerRunCommand.data();
    }

    void SetCreationTime(StdExtra::optional<time_t> value)
    {
        m_creationTime = std::move(value);
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
    }

    void SetCustomGameContainerImage(StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>> value)
    {
        m_customGameContainerImage = std::move(value);
        this->m_model.customGameContainerImage = m_customGameContainerImage ? &m_customGameContainerImage->Model() : nullptr;
    }

    void SetGameAssetReferences(ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameAssetReferences = std::move(value);
        this->m_model.gameAssetReferences =  m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameAssetReferencesCount =  static_cast<uint32_t>(m_gameAssetReferences.size());
    }

    void SetGameCertificateReferences(ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> value)
    {
        m_gameCertificateReferences = std::move(value);
        this->m_model.gameCertificateReferences =  m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.gameCertificateReferencesCount =  static_cast<uint32_t>(m_gameCertificateReferences.size());
    }

    void SetInstrumentationConfiguration(StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> value)
    {
        m_instrumentationConfiguration = std::move(value);
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ? &m_instrumentationConfiguration->Model() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetMultiplayerServerCountPerVm(int32_t value)
    {
        this->m_model.multiplayerServerCountPerVm = value;
    }

    void SetOsPlatform(String value)
    {
        m_osPlatform = std::move(value);
        this->m_model.osPlatform =  m_osPlatform.empty() ? nullptr : m_osPlatform.data();
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

    void SetServerType(String value)
    {
        m_serverType = std::move(value);
        this->m_model.serverType =  m_serverType.empty() ? nullptr : m_serverType.data();
    }

    void SetStartMultiplayerServerCommand(String value)
    {
        m_startMultiplayerServerCommand = std::move(value);
        this->m_model.startMultiplayerServerCommand =  m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
    }

    void SetUseStreamingForAssetDownloads(StdExtra::optional<bool> value)
    {
        m_useStreamingForAssetDownloads = std::move(value);
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
    }

    void SetVmSize(StdExtra::optional<PFMultiplayerServerAzureVmSize> value)
    {
        m_vmSize = std::move(value);
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.areAssetsReadonly = m_areAssetsReadonly ? m_areAssetsReadonly.operator->() : nullptr;
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.buildStatus = m_buildStatus.empty() ? nullptr : m_buildStatus.data();
        this->m_model.containerFlavor = m_containerFlavor ? m_containerFlavor.operator->() : nullptr;
        this->m_model.containerRunCommand = m_containerRunCommand.empty() ? nullptr : m_containerRunCommand.data();
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
        this->m_model.customGameContainerImage = m_customGameContainerImage ?  &m_customGameContainerImage->Model() : nullptr;
        this->m_model.gameAssetReferences = m_gameAssetReferences.empty() ? nullptr : m_gameAssetReferences.data();
        this->m_model.gameCertificateReferences = m_gameCertificateReferences.empty() ? nullptr : m_gameCertificateReferences.data();
        this->m_model.instrumentationConfiguration = m_instrumentationConfiguration ?  &m_instrumentationConfiguration->Model() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.osPlatform = m_osPlatform.empty() ? nullptr : m_osPlatform.data();
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.serverType = m_serverType.empty() ? nullptr : m_serverType.data();
        this->m_model.startMultiplayerServerCommand = m_startMultiplayerServerCommand.empty() ? nullptr : m_startMultiplayerServerCommand.data();
        this->m_model.useStreamingForAssetDownloads = m_useStreamingForAssetDownloads ? m_useStreamingForAssetDownloads.operator->() : nullptr;
        this->m_model.vmSize = m_vmSize ? m_vmSize.operator->() : nullptr;
    }

    StdExtra::optional<bool> m_areAssetsReadonly;
    String m_buildId;
    String m_buildName;
    String m_buildStatus;
    StdExtra::optional<PFMultiplayerServerContainerFlavor> m_containerFlavor;
    String m_containerRunCommand;
    StdExtra::optional<time_t> m_creationTime;
    StdExtra::optional<PFMultiplayerServerContainerImageReferenceWrapper<Alloc>> m_customGameContainerImage;
    ModelVector<PFMultiplayerServerAssetReferenceWrapper<Alloc>, Alloc> m_gameAssetReferences;
    ModelVector<PFMultiplayerServerGameCertificateReferenceWrapper<Alloc>, Alloc> m_gameCertificateReferences;
    StdExtra::optional<PFMultiplayerServerInstrumentationConfigurationWrapper<Alloc>> m_instrumentationConfiguration;
    StringDictionaryEntryVector<Alloc> m_metadata;
    String m_osPlatform;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> m_regionConfigurations;
    String m_serverType;
    String m_startMultiplayerServerCommand;
    StdExtra::optional<bool> m_useStreamingForAssetDownloads;
    StdExtra::optional<PFMultiplayerServerAzureVmSize> m_vmSize;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetBuildAliasRequestWrapper : public ModelWrapper<PFMultiplayerServerGetBuildAliasRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetBuildAliasRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetBuildAliasRequestWrapper() = default;

    PFMultiplayerServerGetBuildAliasRequestWrapper(const PFMultiplayerServerGetBuildAliasRequest& model) :
        ModelWrapper<PFMultiplayerServerGetBuildAliasRequest, Alloc>{ model },
        m_aliasId{ SafeString(model.aliasId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetBuildAliasRequestWrapper(const PFMultiplayerServerGetBuildAliasRequestWrapper& src) :
        PFMultiplayerServerGetBuildAliasRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetBuildAliasRequestWrapper(PFMultiplayerServerGetBuildAliasRequestWrapper&& src) :
        PFMultiplayerServerGetBuildAliasRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetBuildAliasRequestWrapper& operator=(PFMultiplayerServerGetBuildAliasRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetBuildAliasRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetBuildAliasRequestWrapper& lhs, PFMultiplayerServerGetBuildAliasRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aliasId, rhs.m_aliasId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAliasId(String value)
    {
        m_aliasId = std::move(value);
        this->m_model.aliasId =  m_aliasId.empty() ? nullptr : m_aliasId.data();
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
        this->m_model.aliasId = m_aliasId.empty() ? nullptr : m_aliasId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_aliasId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper : public ModelWrapper<PFMultiplayerServerGetContainerRegistryCredentialsRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetContainerRegistryCredentialsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper() = default;

    PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper(const PFMultiplayerServerGetContainerRegistryCredentialsRequest& model) :
        ModelWrapper<PFMultiplayerServerGetContainerRegistryCredentialsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper(const PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper& src) :
        PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper(PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper&& src) :
        PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper& operator=(PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper& lhs, PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper& rhs)
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
class PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper : public ModelWrapper<PFMultiplayerServerGetContainerRegistryCredentialsResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetContainerRegistryCredentialsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper() = default;

    PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper(const PFMultiplayerServerGetContainerRegistryCredentialsResponse& model) :
        ModelWrapper<PFMultiplayerServerGetContainerRegistryCredentialsResponse, Alloc>{ model },
        m_dnsName{ SafeString(model.dnsName) },
        m_password{ SafeString(model.password) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper(const PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper& src) :
        PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper(PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper&& src) :
        PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper& operator=(PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper& lhs, PFMultiplayerServerGetContainerRegistryCredentialsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dnsName, rhs.m_dnsName);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDnsName(String value)
    {
        m_dnsName = std::move(value);
        this->m_model.dnsName =  m_dnsName.empty() ? nullptr : m_dnsName.data();
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
        this->m_model.dnsName = m_dnsName.empty() ? nullptr : m_dnsName.data();
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    String m_dnsName;
    String m_password;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper : public ModelWrapper<PFMultiplayerServerGetMultiplayerServerDetailsRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetMultiplayerServerDetailsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper() = default;

    PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper(const PFMultiplayerServerGetMultiplayerServerDetailsRequest& model) :
        ModelWrapper<PFMultiplayerServerGetMultiplayerServerDetailsRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_region{ SafeString(model.region) },
        m_sessionId{ SafeString(model.sessionId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper(const PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper& src) :
        PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper(PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper&& src) :
        PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper& operator=(PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper& lhs, PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_region;
    String m_sessionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerConnectedPlayerWrapper : public ModelWrapper<PFMultiplayerServerConnectedPlayer, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerConnectedPlayer;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerConnectedPlayerWrapper() = default;

    PFMultiplayerServerConnectedPlayerWrapper(const PFMultiplayerServerConnectedPlayer& model) :
        ModelWrapper<PFMultiplayerServerConnectedPlayer, Alloc>{ model },
        m_playerId{ SafeString(model.playerId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerConnectedPlayerWrapper(const PFMultiplayerServerConnectedPlayerWrapper& src) :
        PFMultiplayerServerConnectedPlayerWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerConnectedPlayerWrapper(PFMultiplayerServerConnectedPlayerWrapper&& src) :
        PFMultiplayerServerConnectedPlayerWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerConnectedPlayerWrapper& operator=(PFMultiplayerServerConnectedPlayerWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerConnectedPlayerWrapper() = default;

    friend void swap(PFMultiplayerServerConnectedPlayerWrapper& lhs, PFMultiplayerServerConnectedPlayerWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playerId, rhs.m_playerId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayerId(String value)
    {
        m_playerId = std::move(value);
        this->m_model.playerId =  m_playerId.empty() ? nullptr : m_playerId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playerId = m_playerId.empty() ? nullptr : m_playerId.data();
    }

    String m_playerId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper : public ModelWrapper<PFMultiplayerServerGetMultiplayerServerDetailsResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetMultiplayerServerDetailsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper() = default;

    PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper(const PFMultiplayerServerGetMultiplayerServerDetailsResponse& model) :
        ModelWrapper<PFMultiplayerServerGetMultiplayerServerDetailsResponse, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_connectedPlayers{ model.connectedPlayers, model.connectedPlayers + model.connectedPlayersCount },
        m_fQDN{ SafeString(model.fQDN) },
        m_iPV4Address{ SafeString(model.iPV4Address) },
        m_lastStateTransitionTime{ model.lastStateTransitionTime ? StdExtra::optional<time_t>{ *model.lastStateTransitionTime } : StdExtra::nullopt },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_region{ SafeString(model.region) },
        m_serverId{ SafeString(model.serverId) },
        m_sessionId{ SafeString(model.sessionId) },
        m_state{ SafeString(model.state) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper(const PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper& src) :
        PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper(PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper&& src) :
        PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper& operator=(PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper& lhs, PFMultiplayerServerGetMultiplayerServerDetailsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_connectedPlayers, rhs.m_connectedPlayers);
        swap(lhs.m_fQDN, rhs.m_fQDN);
        swap(lhs.m_iPV4Address, rhs.m_iPV4Address);
        swap(lhs.m_lastStateTransitionTime, rhs.m_lastStateTransitionTime);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_serverId, rhs.m_serverId);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        swap(lhs.m_state, rhs.m_state);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetConnectedPlayers(ModelVector<PFMultiplayerServerConnectedPlayerWrapper<Alloc>, Alloc> value)
    {
        m_connectedPlayers = std::move(value);
        this->m_model.connectedPlayers =  m_connectedPlayers.empty() ? nullptr : m_connectedPlayers.data();
        this->m_model.connectedPlayersCount =  static_cast<uint32_t>(m_connectedPlayers.size());
    }

    void SetFQDN(String value)
    {
        m_fQDN = std::move(value);
        this->m_model.fQDN =  m_fQDN.empty() ? nullptr : m_fQDN.data();
    }

    void SetIPV4Address(String value)
    {
        m_iPV4Address = std::move(value);
        this->m_model.iPV4Address =  m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
    }

    void SetLastStateTransitionTime(StdExtra::optional<time_t> value)
    {
        m_lastStateTransitionTime = std::move(value);
        this->m_model.lastStateTransitionTime = m_lastStateTransitionTime ? m_lastStateTransitionTime.operator->() : nullptr;
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetServerId(String value)
    {
        m_serverId = std::move(value);
        this->m_model.serverId =  m_serverId.empty() ? nullptr : m_serverId.data();
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    void SetState(String value)
    {
        m_state = std::move(value);
        this->m_model.state =  m_state.empty() ? nullptr : m_state.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.connectedPlayers = m_connectedPlayers.empty() ? nullptr : m_connectedPlayers.data();
        this->m_model.fQDN = m_fQDN.empty() ? nullptr : m_fQDN.data();
        this->m_model.iPV4Address = m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
        this->m_model.lastStateTransitionTime = m_lastStateTransitionTime ? m_lastStateTransitionTime.operator->() : nullptr;
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.serverId = m_serverId.empty() ? nullptr : m_serverId.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
        this->m_model.state = m_state.empty() ? nullptr : m_state.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    String m_buildId;
    ModelVector<PFMultiplayerServerConnectedPlayerWrapper<Alloc>, Alloc> m_connectedPlayers;
    String m_fQDN;
    String m_iPV4Address;
    StdExtra::optional<time_t> m_lastStateTransitionTime;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    String m_region;
    String m_serverId;
    String m_sessionId;
    String m_state;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper : public ModelWrapper<PFMultiplayerServerGetMultiplayerServerLogsRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetMultiplayerServerLogsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper() = default;

    PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper(const PFMultiplayerServerGetMultiplayerServerLogsRequest& model) :
        ModelWrapper<PFMultiplayerServerGetMultiplayerServerLogsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_serverId{ SafeString(model.serverId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper(const PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper& src) :
        PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper(PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper&& src) :
        PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper& operator=(PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper& lhs, PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_serverId, rhs.m_serverId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetServerId(String value)
    {
        m_serverId = std::move(value);
        this->m_model.serverId =  m_serverId.empty() ? nullptr : m_serverId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.serverId = m_serverId.empty() ? nullptr : m_serverId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_serverId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper : public ModelWrapper<PFMultiplayerServerGetMultiplayerServerLogsResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetMultiplayerServerLogsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper() = default;

    PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper(const PFMultiplayerServerGetMultiplayerServerLogsResponse& model) :
        ModelWrapper<PFMultiplayerServerGetMultiplayerServerLogsResponse, Alloc>{ model },
        m_logDownloadUrl{ SafeString(model.logDownloadUrl) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper(const PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper& src) :
        PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper(PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper&& src) :
        PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper& operator=(PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper& lhs, PFMultiplayerServerGetMultiplayerServerLogsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_logDownloadUrl, rhs.m_logDownloadUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLogDownloadUrl(String value)
    {
        m_logDownloadUrl = std::move(value);
        this->m_model.logDownloadUrl =  m_logDownloadUrl.empty() ? nullptr : m_logDownloadUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.logDownloadUrl = m_logDownloadUrl.empty() ? nullptr : m_logDownloadUrl.data();
    }

    String m_logDownloadUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper : public ModelWrapper<PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper() = default;

    PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper(const PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest& model) :
        ModelWrapper<PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_sessionId{ SafeString(model.sessionId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper(const PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper& src) :
        PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper&& src) :
        PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper& operator=(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper& lhs, PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_sessionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper : public ModelWrapper<PFMultiplayerServerGetRemoteLoginEndpointRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetRemoteLoginEndpointRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper() = default;

    PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper(const PFMultiplayerServerGetRemoteLoginEndpointRequest& model) :
        ModelWrapper<PFMultiplayerServerGetRemoteLoginEndpointRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_region{ SafeString(model.region) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper(const PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper& src) :
        PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper(PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper&& src) :
        PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper& operator=(PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper& lhs, PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_region;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper : public ModelWrapper<PFMultiplayerServerGetRemoteLoginEndpointResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetRemoteLoginEndpointResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper() = default;

    PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper(const PFMultiplayerServerGetRemoteLoginEndpointResponse& model) :
        ModelWrapper<PFMultiplayerServerGetRemoteLoginEndpointResponse, Alloc>{ model },
        m_iPV4Address{ SafeString(model.iPV4Address) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper(const PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper& src) :
        PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper(PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper&& src) :
        PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper& operator=(PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper& lhs, PFMultiplayerServerGetRemoteLoginEndpointResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_iPV4Address, rhs.m_iPV4Address);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIPV4Address(String value)
    {
        m_iPV4Address = std::move(value);
        this->m_model.iPV4Address =  m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
    }

    void SetPort(int32_t value)
    {
        this->m_model.port = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.iPV4Address = m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
    }

    String m_iPV4Address;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper : public ModelWrapper<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper() = default;

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest& model) :
        ModelWrapper<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper& src) :
        PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper&& src) :
        PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper& operator=(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper& lhs, PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper& rhs)
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
class PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper : public ModelWrapper<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper() = default;

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& model) :
        ModelWrapper<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse, Alloc>{ model },
        m_status{ model.status ? StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus>{ *model.status } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper& src) :
        PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper&& src) :
        PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper& operator=(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper& lhs, PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_status, rhs.m_status);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatus(StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus> m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper : public ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper() = default;

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest& model) :
        ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_requestId{ SafeString(model.requestId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper&& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper& operator=(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper& lhs, PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_requestId, rhs.m_requestId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetRequestId(String value)
    {
        m_requestId = std::move(value);
        this->m_model.requestId =  m_requestId.empty() ? nullptr : m_requestId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.requestId = m_requestId.empty() ? nullptr : m_requestId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_requestId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerQuotaChangeWrapper : public ModelWrapper<PFMultiplayerServerQuotaChange, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerQuotaChange;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerQuotaChangeWrapper() = default;

    PFMultiplayerServerQuotaChangeWrapper(const PFMultiplayerServerQuotaChange& model) :
        ModelWrapper<PFMultiplayerServerQuotaChange, Alloc>{ model },
        m_changeDescription{ SafeString(model.changeDescription) },
        m_changes{ model.changes, model.changes + model.changesCount },
        m_notes{ SafeString(model.notes) },
        m_requestId{ SafeString(model.requestId) },
        m_reviewComments{ SafeString(model.reviewComments) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerQuotaChangeWrapper(const PFMultiplayerServerQuotaChangeWrapper& src) :
        PFMultiplayerServerQuotaChangeWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerQuotaChangeWrapper(PFMultiplayerServerQuotaChangeWrapper&& src) :
        PFMultiplayerServerQuotaChangeWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerQuotaChangeWrapper& operator=(PFMultiplayerServerQuotaChangeWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerQuotaChangeWrapper() = default;

    friend void swap(PFMultiplayerServerQuotaChangeWrapper& lhs, PFMultiplayerServerQuotaChangeWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_changeDescription, rhs.m_changeDescription);
        swap(lhs.m_changes, rhs.m_changes);
        swap(lhs.m_notes, rhs.m_notes);
        swap(lhs.m_requestId, rhs.m_requestId);
        swap(lhs.m_reviewComments, rhs.m_reviewComments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChangeDescription(String value)
    {
        m_changeDescription = std::move(value);
        this->m_model.changeDescription =  m_changeDescription.empty() ? nullptr : m_changeDescription.data();
    }

    void SetChanges(ModelVector<PFMultiplayerServerCoreCapacityChangeWrapper<Alloc>, Alloc> value)
    {
        m_changes = std::move(value);
        this->m_model.changes =  m_changes.empty() ? nullptr : m_changes.data();
        this->m_model.changesCount =  static_cast<uint32_t>(m_changes.size());
    }

    void SetIsPendingReview(bool value)
    {
        this->m_model.isPendingReview = value;
    }

    void SetNotes(String value)
    {
        m_notes = std::move(value);
        this->m_model.notes =  m_notes.empty() ? nullptr : m_notes.data();
    }

    void SetRequestId(String value)
    {
        m_requestId = std::move(value);
        this->m_model.requestId =  m_requestId.empty() ? nullptr : m_requestId.data();
    }

    void SetReviewComments(String value)
    {
        m_reviewComments = std::move(value);
        this->m_model.reviewComments =  m_reviewComments.empty() ? nullptr : m_reviewComments.data();
    }

    void SetWasApproved(bool value)
    {
        this->m_model.wasApproved = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.changeDescription = m_changeDescription.empty() ? nullptr : m_changeDescription.data();
        this->m_model.changes = m_changes.empty() ? nullptr : m_changes.data();
        this->m_model.notes = m_notes.empty() ? nullptr : m_notes.data();
        this->m_model.requestId = m_requestId.empty() ? nullptr : m_requestId.data();
        this->m_model.reviewComments = m_reviewComments.empty() ? nullptr : m_reviewComments.data();
    }

    String m_changeDescription;
    ModelVector<PFMultiplayerServerCoreCapacityChangeWrapper<Alloc>, Alloc> m_changes;
    String m_notes;
    String m_requestId;
    String m_reviewComments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper : public ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper() = default;

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& model) :
        ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse, Alloc>{ model },
        m_change{ model.change ? StdExtra::optional<PFMultiplayerServerQuotaChangeWrapper<Alloc>>{ *model.change } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper&& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper& operator=(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper& lhs, PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_change, rhs.m_change);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChange(StdExtra::optional<PFMultiplayerServerQuotaChangeWrapper<Alloc>> value)
    {
        m_change = std::move(value);
        this->m_model.change = m_change ? &m_change->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.change = m_change ?  &m_change->Model() : nullptr;
    }

    StdExtra::optional<PFMultiplayerServerQuotaChangeWrapper<Alloc>> m_change;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper : public ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper() = default;

    PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest& model) :
        ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper(PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper&& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper& operator=(PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper() = default;

    friend void swap(PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper& lhs, PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper& rhs)
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
class PFMultiplayerServerCoreCapacityWrapper : public ModelWrapper<PFMultiplayerServerCoreCapacity, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCoreCapacity;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCoreCapacityWrapper() = default;

    PFMultiplayerServerCoreCapacityWrapper(const PFMultiplayerServerCoreCapacity& model) :
        ModelWrapper<PFMultiplayerServerCoreCapacity, Alloc>{ model },
        m_region{ SafeString(model.region) },
        m_vmFamily{ model.vmFamily ? StdExtra::optional<PFMultiplayerServerAzureVmFamily>{ *model.vmFamily } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCoreCapacityWrapper(const PFMultiplayerServerCoreCapacityWrapper& src) :
        PFMultiplayerServerCoreCapacityWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCoreCapacityWrapper(PFMultiplayerServerCoreCapacityWrapper&& src) :
        PFMultiplayerServerCoreCapacityWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCoreCapacityWrapper& operator=(PFMultiplayerServerCoreCapacityWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCoreCapacityWrapper() = default;

    friend void swap(PFMultiplayerServerCoreCapacityWrapper& lhs, PFMultiplayerServerCoreCapacityWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_vmFamily, rhs.m_vmFamily);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAvailable(int32_t value)
    {
        this->m_model.available = value;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetTotal(int32_t value)
    {
        this->m_model.total = value;
    }

    void SetVmFamily(StdExtra::optional<PFMultiplayerServerAzureVmFamily> value)
    {
        m_vmFamily = std::move(value);
        this->m_model.vmFamily = m_vmFamily ? m_vmFamily.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.vmFamily = m_vmFamily ? m_vmFamily.operator->() : nullptr;
    }

    String m_region;
    StdExtra::optional<PFMultiplayerServerAzureVmFamily> m_vmFamily;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerTitleMultiplayerServersQuotasWrapper : public ModelWrapper<PFMultiplayerServerTitleMultiplayerServersQuotas, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerTitleMultiplayerServersQuotas;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerTitleMultiplayerServersQuotasWrapper() = default;

    PFMultiplayerServerTitleMultiplayerServersQuotasWrapper(const PFMultiplayerServerTitleMultiplayerServersQuotas& model) :
        ModelWrapper<PFMultiplayerServerTitleMultiplayerServersQuotas, Alloc>{ model },
        m_coreCapacities{ model.coreCapacities, model.coreCapacities + model.coreCapacitiesCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerTitleMultiplayerServersQuotasWrapper(const PFMultiplayerServerTitleMultiplayerServersQuotasWrapper& src) :
        PFMultiplayerServerTitleMultiplayerServersQuotasWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerTitleMultiplayerServersQuotasWrapper(PFMultiplayerServerTitleMultiplayerServersQuotasWrapper&& src) :
        PFMultiplayerServerTitleMultiplayerServersQuotasWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerTitleMultiplayerServersQuotasWrapper& operator=(PFMultiplayerServerTitleMultiplayerServersQuotasWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerTitleMultiplayerServersQuotasWrapper() = default;

    friend void swap(PFMultiplayerServerTitleMultiplayerServersQuotasWrapper& lhs, PFMultiplayerServerTitleMultiplayerServersQuotasWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_coreCapacities, rhs.m_coreCapacities);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCoreCapacities(ModelVector<PFMultiplayerServerCoreCapacityWrapper<Alloc>, Alloc> value)
    {
        m_coreCapacities = std::move(value);
        this->m_model.coreCapacities =  m_coreCapacities.empty() ? nullptr : m_coreCapacities.data();
        this->m_model.coreCapacitiesCount =  static_cast<uint32_t>(m_coreCapacities.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.coreCapacities = m_coreCapacities.empty() ? nullptr : m_coreCapacities.data();
    }

    ModelVector<PFMultiplayerServerCoreCapacityWrapper<Alloc>, Alloc> m_coreCapacities;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper : public ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper() = default;

    PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& model) :
        ModelWrapper<PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse, Alloc>{ model },
        m_quotas{ model.quotas ? StdExtra::optional<PFMultiplayerServerTitleMultiplayerServersQuotasWrapper<Alloc>>{ *model.quotas } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper(const PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper&& src) :
        PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper& operator=(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper() = default;

    friend void swap(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper& lhs, PFMultiplayerServerGetTitleMultiplayerServersQuotasResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_quotas, rhs.m_quotas);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetQuotas(StdExtra::optional<PFMultiplayerServerTitleMultiplayerServersQuotasWrapper<Alloc>> value)
    {
        m_quotas = std::move(value);
        this->m_model.quotas = m_quotas ? &m_quotas->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.quotas = m_quotas ?  &m_quotas->Model() : nullptr;
    }

    StdExtra::optional<PFMultiplayerServerTitleMultiplayerServersQuotasWrapper<Alloc>> m_quotas;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListMultiplayerServersRequestWrapper : public ModelWrapper<PFMultiplayerServerListMultiplayerServersRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListMultiplayerServersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListMultiplayerServersRequestWrapper() = default;

    PFMultiplayerServerListMultiplayerServersRequestWrapper(const PFMultiplayerServerListMultiplayerServersRequest& model) :
        ModelWrapper<PFMultiplayerServerListMultiplayerServersRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_region{ SafeString(model.region) },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListMultiplayerServersRequestWrapper(const PFMultiplayerServerListMultiplayerServersRequestWrapper& src) :
        PFMultiplayerServerListMultiplayerServersRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListMultiplayerServersRequestWrapper(PFMultiplayerServerListMultiplayerServersRequestWrapper&& src) :
        PFMultiplayerServerListMultiplayerServersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListMultiplayerServersRequestWrapper& operator=(PFMultiplayerServerListMultiplayerServersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListMultiplayerServersRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListMultiplayerServersRequestWrapper& lhs, PFMultiplayerServerListMultiplayerServersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_region;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerMultiplayerServerSummaryWrapper : public ModelWrapper<PFMultiplayerServerMultiplayerServerSummary, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerMultiplayerServerSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerMultiplayerServerSummaryWrapper() = default;

    PFMultiplayerServerMultiplayerServerSummaryWrapper(const PFMultiplayerServerMultiplayerServerSummary& model) :
        ModelWrapper<PFMultiplayerServerMultiplayerServerSummary, Alloc>{ model },
        m_connectedPlayers{ model.connectedPlayers, model.connectedPlayers + model.connectedPlayersCount },
        m_lastStateTransitionTime{ model.lastStateTransitionTime ? StdExtra::optional<time_t>{ *model.lastStateTransitionTime } : StdExtra::nullopt },
        m_region{ SafeString(model.region) },
        m_serverId{ SafeString(model.serverId) },
        m_sessionId{ SafeString(model.sessionId) },
        m_state{ SafeString(model.state) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerMultiplayerServerSummaryWrapper(const PFMultiplayerServerMultiplayerServerSummaryWrapper& src) :
        PFMultiplayerServerMultiplayerServerSummaryWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerMultiplayerServerSummaryWrapper(PFMultiplayerServerMultiplayerServerSummaryWrapper&& src) :
        PFMultiplayerServerMultiplayerServerSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerMultiplayerServerSummaryWrapper& operator=(PFMultiplayerServerMultiplayerServerSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerMultiplayerServerSummaryWrapper() = default;

    friend void swap(PFMultiplayerServerMultiplayerServerSummaryWrapper& lhs, PFMultiplayerServerMultiplayerServerSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectedPlayers, rhs.m_connectedPlayers);
        swap(lhs.m_lastStateTransitionTime, rhs.m_lastStateTransitionTime);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_serverId, rhs.m_serverId);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        swap(lhs.m_state, rhs.m_state);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectedPlayers(ModelVector<PFMultiplayerServerConnectedPlayerWrapper<Alloc>, Alloc> value)
    {
        m_connectedPlayers = std::move(value);
        this->m_model.connectedPlayers =  m_connectedPlayers.empty() ? nullptr : m_connectedPlayers.data();
        this->m_model.connectedPlayersCount =  static_cast<uint32_t>(m_connectedPlayers.size());
    }

    void SetLastStateTransitionTime(StdExtra::optional<time_t> value)
    {
        m_lastStateTransitionTime = std::move(value);
        this->m_model.lastStateTransitionTime = m_lastStateTransitionTime ? m_lastStateTransitionTime.operator->() : nullptr;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetServerId(String value)
    {
        m_serverId = std::move(value);
        this->m_model.serverId =  m_serverId.empty() ? nullptr : m_serverId.data();
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    void SetState(String value)
    {
        m_state = std::move(value);
        this->m_model.state =  m_state.empty() ? nullptr : m_state.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectedPlayers = m_connectedPlayers.empty() ? nullptr : m_connectedPlayers.data();
        this->m_model.lastStateTransitionTime = m_lastStateTransitionTime ? m_lastStateTransitionTime.operator->() : nullptr;
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.serverId = m_serverId.empty() ? nullptr : m_serverId.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
        this->m_model.state = m_state.empty() ? nullptr : m_state.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    ModelVector<PFMultiplayerServerConnectedPlayerWrapper<Alloc>, Alloc> m_connectedPlayers;
    StdExtra::optional<time_t> m_lastStateTransitionTime;
    String m_region;
    String m_serverId;
    String m_sessionId;
    String m_state;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListMultiplayerServersResponseWrapper : public ModelWrapper<PFMultiplayerServerListMultiplayerServersResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListMultiplayerServersResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListMultiplayerServersResponseWrapper() = default;

    PFMultiplayerServerListMultiplayerServersResponseWrapper(const PFMultiplayerServerListMultiplayerServersResponse& model) :
        ModelWrapper<PFMultiplayerServerListMultiplayerServersResponse, Alloc>{ model },
        m_multiplayerServerSummaries{ model.multiplayerServerSummaries, model.multiplayerServerSummaries + model.multiplayerServerSummariesCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListMultiplayerServersResponseWrapper(const PFMultiplayerServerListMultiplayerServersResponseWrapper& src) :
        PFMultiplayerServerListMultiplayerServersResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListMultiplayerServersResponseWrapper(PFMultiplayerServerListMultiplayerServersResponseWrapper&& src) :
        PFMultiplayerServerListMultiplayerServersResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListMultiplayerServersResponseWrapper& operator=(PFMultiplayerServerListMultiplayerServersResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListMultiplayerServersResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListMultiplayerServersResponseWrapper& lhs, PFMultiplayerServerListMultiplayerServersResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_multiplayerServerSummaries, rhs.m_multiplayerServerSummaries);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMultiplayerServerSummaries(ModelVector<PFMultiplayerServerMultiplayerServerSummaryWrapper<Alloc>, Alloc> value)
    {
        m_multiplayerServerSummaries = std::move(value);
        this->m_model.multiplayerServerSummaries =  m_multiplayerServerSummaries.empty() ? nullptr : m_multiplayerServerSummaries.data();
        this->m_model.multiplayerServerSummariesCount =  static_cast<uint32_t>(m_multiplayerServerSummaries.size());
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.multiplayerServerSummaries = m_multiplayerServerSummaries.empty() ? nullptr : m_multiplayerServerSummaries.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerMultiplayerServerSummaryWrapper<Alloc>, Alloc> m_multiplayerServerSummaries;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListAssetSummariesRequestWrapper : public ModelWrapper<PFMultiplayerServerListAssetSummariesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListAssetSummariesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListAssetSummariesRequestWrapper() = default;

    PFMultiplayerServerListAssetSummariesRequestWrapper(const PFMultiplayerServerListAssetSummariesRequest& model) :
        ModelWrapper<PFMultiplayerServerListAssetSummariesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListAssetSummariesRequestWrapper(const PFMultiplayerServerListAssetSummariesRequestWrapper& src) :
        PFMultiplayerServerListAssetSummariesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListAssetSummariesRequestWrapper(PFMultiplayerServerListAssetSummariesRequestWrapper&& src) :
        PFMultiplayerServerListAssetSummariesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListAssetSummariesRequestWrapper& operator=(PFMultiplayerServerListAssetSummariesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListAssetSummariesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListAssetSummariesRequestWrapper& lhs, PFMultiplayerServerListAssetSummariesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerAssetSummaryWrapper : public ModelWrapper<PFMultiplayerServerAssetSummary, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerAssetSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerAssetSummaryWrapper() = default;

    PFMultiplayerServerAssetSummaryWrapper(const PFMultiplayerServerAssetSummary& model) :
        ModelWrapper<PFMultiplayerServerAssetSummary, Alloc>{ model },
        m_fileName{ SafeString(model.fileName) },
        m_metadata{ model.metadata, model.metadata + model.metadataCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerAssetSummaryWrapper(const PFMultiplayerServerAssetSummaryWrapper& src) :
        PFMultiplayerServerAssetSummaryWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerAssetSummaryWrapper(PFMultiplayerServerAssetSummaryWrapper&& src) :
        PFMultiplayerServerAssetSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerAssetSummaryWrapper& operator=(PFMultiplayerServerAssetSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerAssetSummaryWrapper() = default;

    friend void swap(PFMultiplayerServerAssetSummaryWrapper& lhs, PFMultiplayerServerAssetSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fileName, rhs.m_fileName);
        swap(lhs.m_metadata, rhs.m_metadata);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
    }

    String m_fileName;
    StringDictionaryEntryVector<Alloc> m_metadata;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListAssetSummariesResponseWrapper : public ModelWrapper<PFMultiplayerServerListAssetSummariesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListAssetSummariesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListAssetSummariesResponseWrapper() = default;

    PFMultiplayerServerListAssetSummariesResponseWrapper(const PFMultiplayerServerListAssetSummariesResponse& model) :
        ModelWrapper<PFMultiplayerServerListAssetSummariesResponse, Alloc>{ model },
        m_assetSummaries{ model.assetSummaries, model.assetSummaries + model.assetSummariesCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListAssetSummariesResponseWrapper(const PFMultiplayerServerListAssetSummariesResponseWrapper& src) :
        PFMultiplayerServerListAssetSummariesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListAssetSummariesResponseWrapper(PFMultiplayerServerListAssetSummariesResponseWrapper&& src) :
        PFMultiplayerServerListAssetSummariesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListAssetSummariesResponseWrapper& operator=(PFMultiplayerServerListAssetSummariesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListAssetSummariesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListAssetSummariesResponseWrapper& lhs, PFMultiplayerServerListAssetSummariesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assetSummaries, rhs.m_assetSummaries);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssetSummaries(ModelVector<PFMultiplayerServerAssetSummaryWrapper<Alloc>, Alloc> value)
    {
        m_assetSummaries = std::move(value);
        this->m_model.assetSummaries =  m_assetSummaries.empty() ? nullptr : m_assetSummaries.data();
        this->m_model.assetSummariesCount =  static_cast<uint32_t>(m_assetSummaries.size());
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.assetSummaries = m_assetSummaries.empty() ? nullptr : m_assetSummaries.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerAssetSummaryWrapper<Alloc>, Alloc> m_assetSummaries;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListBuildAliasesRequestWrapper : public ModelWrapper<PFMultiplayerServerListBuildAliasesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListBuildAliasesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListBuildAliasesRequestWrapper() = default;

    PFMultiplayerServerListBuildAliasesRequestWrapper(const PFMultiplayerServerListBuildAliasesRequest& model) :
        ModelWrapper<PFMultiplayerServerListBuildAliasesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListBuildAliasesRequestWrapper(const PFMultiplayerServerListBuildAliasesRequestWrapper& src) :
        PFMultiplayerServerListBuildAliasesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListBuildAliasesRequestWrapper(PFMultiplayerServerListBuildAliasesRequestWrapper&& src) :
        PFMultiplayerServerListBuildAliasesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListBuildAliasesRequestWrapper& operator=(PFMultiplayerServerListBuildAliasesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListBuildAliasesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListBuildAliasesRequestWrapper& lhs, PFMultiplayerServerListBuildAliasesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListBuildAliasesResponseWrapper : public ModelWrapper<PFMultiplayerServerListBuildAliasesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListBuildAliasesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListBuildAliasesResponseWrapper() = default;

    PFMultiplayerServerListBuildAliasesResponseWrapper(const PFMultiplayerServerListBuildAliasesResponse& model) :
        ModelWrapper<PFMultiplayerServerListBuildAliasesResponse, Alloc>{ model },
        m_buildAliases{ model.buildAliases, model.buildAliases + model.buildAliasesCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListBuildAliasesResponseWrapper(const PFMultiplayerServerListBuildAliasesResponseWrapper& src) :
        PFMultiplayerServerListBuildAliasesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListBuildAliasesResponseWrapper(PFMultiplayerServerListBuildAliasesResponseWrapper&& src) :
        PFMultiplayerServerListBuildAliasesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListBuildAliasesResponseWrapper& operator=(PFMultiplayerServerListBuildAliasesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListBuildAliasesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListBuildAliasesResponseWrapper& lhs, PFMultiplayerServerListBuildAliasesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildAliases, rhs.m_buildAliases);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildAliases(ModelVector<PFMultiplayerServerBuildAliasDetailsResponseWrapper<Alloc>, Alloc> value)
    {
        m_buildAliases = std::move(value);
        this->m_model.buildAliases =  m_buildAliases.empty() ? nullptr : m_buildAliases.data();
        this->m_model.buildAliasesCount =  static_cast<uint32_t>(m_buildAliases.size());
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildAliases = m_buildAliases.empty() ? nullptr : m_buildAliases.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerBuildAliasDetailsResponseWrapper<Alloc>, Alloc> m_buildAliases;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListBuildSummariesRequestWrapper : public ModelWrapper<PFMultiplayerServerListBuildSummariesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListBuildSummariesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListBuildSummariesRequestWrapper() = default;

    PFMultiplayerServerListBuildSummariesRequestWrapper(const PFMultiplayerServerListBuildSummariesRequest& model) :
        ModelWrapper<PFMultiplayerServerListBuildSummariesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListBuildSummariesRequestWrapper(const PFMultiplayerServerListBuildSummariesRequestWrapper& src) :
        PFMultiplayerServerListBuildSummariesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListBuildSummariesRequestWrapper(PFMultiplayerServerListBuildSummariesRequestWrapper&& src) :
        PFMultiplayerServerListBuildSummariesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListBuildSummariesRequestWrapper& operator=(PFMultiplayerServerListBuildSummariesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListBuildSummariesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListBuildSummariesRequestWrapper& lhs, PFMultiplayerServerListBuildSummariesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerBuildSummaryWrapper : public ModelWrapper<PFMultiplayerServerBuildSummary, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerBuildSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerBuildSummaryWrapper() = default;

    PFMultiplayerServerBuildSummaryWrapper(const PFMultiplayerServerBuildSummary& model) :
        ModelWrapper<PFMultiplayerServerBuildSummary, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_buildName{ SafeString(model.buildName) },
        m_creationTime{ model.creationTime ? StdExtra::optional<time_t>{ *model.creationTime } : StdExtra::nullopt },
        m_metadata{ model.metadata, model.metadata + model.metadataCount },
        m_regionConfigurations{ model.regionConfigurations, model.regionConfigurations + model.regionConfigurationsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerBuildSummaryWrapper(const PFMultiplayerServerBuildSummaryWrapper& src) :
        PFMultiplayerServerBuildSummaryWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerBuildSummaryWrapper(PFMultiplayerServerBuildSummaryWrapper&& src) :
        PFMultiplayerServerBuildSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerBuildSummaryWrapper& operator=(PFMultiplayerServerBuildSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerBuildSummaryWrapper() = default;

    friend void swap(PFMultiplayerServerBuildSummaryWrapper& lhs, PFMultiplayerServerBuildSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_creationTime, rhs.m_creationTime);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_regionConfigurations, rhs.m_regionConfigurations);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
    }

    void SetCreationTime(StdExtra::optional<time_t> value)
    {
        m_creationTime = std::move(value);
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
    }

    void SetMetadata(StringDictionaryEntryVector<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.metadataCount =  static_cast<uint32_t>(m_metadata.size());
    }

    void SetRegionConfigurations(ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> value)
    {
        m_regionConfigurations = std::move(value);
        this->m_model.regionConfigurations =  m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
        this->m_model.regionConfigurationsCount =  static_cast<uint32_t>(m_regionConfigurations.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.creationTime = m_creationTime ? m_creationTime.operator->() : nullptr;
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.regionConfigurations = m_regionConfigurations.empty() ? nullptr : m_regionConfigurations.data();
    }

    String m_buildId;
    String m_buildName;
    StdExtra::optional<time_t> m_creationTime;
    StringDictionaryEntryVector<Alloc> m_metadata;
    ModelVector<PFMultiplayerServerBuildRegionWrapper<Alloc>, Alloc> m_regionConfigurations;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListBuildSummariesResponseWrapper : public ModelWrapper<PFMultiplayerServerListBuildSummariesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListBuildSummariesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListBuildSummariesResponseWrapper() = default;

    PFMultiplayerServerListBuildSummariesResponseWrapper(const PFMultiplayerServerListBuildSummariesResponse& model) :
        ModelWrapper<PFMultiplayerServerListBuildSummariesResponse, Alloc>{ model },
        m_buildSummaries{ model.buildSummaries, model.buildSummaries + model.buildSummariesCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListBuildSummariesResponseWrapper(const PFMultiplayerServerListBuildSummariesResponseWrapper& src) :
        PFMultiplayerServerListBuildSummariesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListBuildSummariesResponseWrapper(PFMultiplayerServerListBuildSummariesResponseWrapper&& src) :
        PFMultiplayerServerListBuildSummariesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListBuildSummariesResponseWrapper& operator=(PFMultiplayerServerListBuildSummariesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListBuildSummariesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListBuildSummariesResponseWrapper& lhs, PFMultiplayerServerListBuildSummariesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildSummaries, rhs.m_buildSummaries);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildSummaries(ModelVector<PFMultiplayerServerBuildSummaryWrapper<Alloc>, Alloc> value)
    {
        m_buildSummaries = std::move(value);
        this->m_model.buildSummaries =  m_buildSummaries.empty() ? nullptr : m_buildSummaries.data();
        this->m_model.buildSummariesCount =  static_cast<uint32_t>(m_buildSummaries.size());
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildSummaries = m_buildSummaries.empty() ? nullptr : m_buildSummaries.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerBuildSummaryWrapper<Alloc>, Alloc> m_buildSummaries;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListCertificateSummariesRequestWrapper : public ModelWrapper<PFMultiplayerServerListCertificateSummariesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListCertificateSummariesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListCertificateSummariesRequestWrapper() = default;

    PFMultiplayerServerListCertificateSummariesRequestWrapper(const PFMultiplayerServerListCertificateSummariesRequest& model) :
        ModelWrapper<PFMultiplayerServerListCertificateSummariesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListCertificateSummariesRequestWrapper(const PFMultiplayerServerListCertificateSummariesRequestWrapper& src) :
        PFMultiplayerServerListCertificateSummariesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListCertificateSummariesRequestWrapper(PFMultiplayerServerListCertificateSummariesRequestWrapper&& src) :
        PFMultiplayerServerListCertificateSummariesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListCertificateSummariesRequestWrapper& operator=(PFMultiplayerServerListCertificateSummariesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListCertificateSummariesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListCertificateSummariesRequestWrapper& lhs, PFMultiplayerServerListCertificateSummariesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCertificateSummaryWrapper : public ModelWrapper<PFMultiplayerServerCertificateSummary, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCertificateSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCertificateSummaryWrapper() = default;

    PFMultiplayerServerCertificateSummaryWrapper(const PFMultiplayerServerCertificateSummary& model) :
        ModelWrapper<PFMultiplayerServerCertificateSummary, Alloc>{ model },
        m_name{ SafeString(model.name) },
        m_thumbprint{ SafeString(model.thumbprint) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCertificateSummaryWrapper(const PFMultiplayerServerCertificateSummaryWrapper& src) :
        PFMultiplayerServerCertificateSummaryWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCertificateSummaryWrapper(PFMultiplayerServerCertificateSummaryWrapper&& src) :
        PFMultiplayerServerCertificateSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCertificateSummaryWrapper& operator=(PFMultiplayerServerCertificateSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCertificateSummaryWrapper() = default;

    friend void swap(PFMultiplayerServerCertificateSummaryWrapper& lhs, PFMultiplayerServerCertificateSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_thumbprint, rhs.m_thumbprint);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetThumbprint(String value)
    {
        m_thumbprint = std::move(value);
        this->m_model.thumbprint =  m_thumbprint.empty() ? nullptr : m_thumbprint.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.thumbprint = m_thumbprint.empty() ? nullptr : m_thumbprint.data();
    }

    String m_name;
    String m_thumbprint;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListCertificateSummariesResponseWrapper : public ModelWrapper<PFMultiplayerServerListCertificateSummariesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListCertificateSummariesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListCertificateSummariesResponseWrapper() = default;

    PFMultiplayerServerListCertificateSummariesResponseWrapper(const PFMultiplayerServerListCertificateSummariesResponse& model) :
        ModelWrapper<PFMultiplayerServerListCertificateSummariesResponse, Alloc>{ model },
        m_certificateSummaries{ model.certificateSummaries, model.certificateSummaries + model.certificateSummariesCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListCertificateSummariesResponseWrapper(const PFMultiplayerServerListCertificateSummariesResponseWrapper& src) :
        PFMultiplayerServerListCertificateSummariesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListCertificateSummariesResponseWrapper(PFMultiplayerServerListCertificateSummariesResponseWrapper&& src) :
        PFMultiplayerServerListCertificateSummariesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListCertificateSummariesResponseWrapper& operator=(PFMultiplayerServerListCertificateSummariesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListCertificateSummariesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListCertificateSummariesResponseWrapper& lhs, PFMultiplayerServerListCertificateSummariesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_certificateSummaries, rhs.m_certificateSummaries);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCertificateSummaries(ModelVector<PFMultiplayerServerCertificateSummaryWrapper<Alloc>, Alloc> value)
    {
        m_certificateSummaries = std::move(value);
        this->m_model.certificateSummaries =  m_certificateSummaries.empty() ? nullptr : m_certificateSummaries.data();
        this->m_model.certificateSummariesCount =  static_cast<uint32_t>(m_certificateSummaries.size());
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.certificateSummaries = m_certificateSummaries.empty() ? nullptr : m_certificateSummaries.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerCertificateSummaryWrapper<Alloc>, Alloc> m_certificateSummaries;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListContainerImagesRequestWrapper : public ModelWrapper<PFMultiplayerServerListContainerImagesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListContainerImagesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListContainerImagesRequestWrapper() = default;

    PFMultiplayerServerListContainerImagesRequestWrapper(const PFMultiplayerServerListContainerImagesRequest& model) :
        ModelWrapper<PFMultiplayerServerListContainerImagesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListContainerImagesRequestWrapper(const PFMultiplayerServerListContainerImagesRequestWrapper& src) :
        PFMultiplayerServerListContainerImagesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListContainerImagesRequestWrapper(PFMultiplayerServerListContainerImagesRequestWrapper&& src) :
        PFMultiplayerServerListContainerImagesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListContainerImagesRequestWrapper& operator=(PFMultiplayerServerListContainerImagesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListContainerImagesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListContainerImagesRequestWrapper& lhs, PFMultiplayerServerListContainerImagesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListContainerImagesResponseWrapper : public ModelWrapper<PFMultiplayerServerListContainerImagesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListContainerImagesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListContainerImagesResponseWrapper() = default;

    PFMultiplayerServerListContainerImagesResponseWrapper(const PFMultiplayerServerListContainerImagesResponse& model) :
        ModelWrapper<PFMultiplayerServerListContainerImagesResponse, Alloc>{ model },
        m_images{ model.images, model.images + model.imagesCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListContainerImagesResponseWrapper(const PFMultiplayerServerListContainerImagesResponseWrapper& src) :
        PFMultiplayerServerListContainerImagesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListContainerImagesResponseWrapper(PFMultiplayerServerListContainerImagesResponseWrapper&& src) :
        PFMultiplayerServerListContainerImagesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListContainerImagesResponseWrapper& operator=(PFMultiplayerServerListContainerImagesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListContainerImagesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListContainerImagesResponseWrapper& lhs, PFMultiplayerServerListContainerImagesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_images, rhs.m_images);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetImages(CStringVector<Alloc> value)
    {
        m_images = std::move(value);
        this->m_model.images =  m_images.empty() ? nullptr : m_images.data();
        this->m_model.imagesCount =  static_cast<uint32_t>(m_images.size());
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.images = m_images.empty() ? nullptr : m_images.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    CStringVector<Alloc> m_images;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListContainerImageTagsRequestWrapper : public ModelWrapper<PFMultiplayerServerListContainerImageTagsRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListContainerImageTagsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListContainerImageTagsRequestWrapper() = default;

    PFMultiplayerServerListContainerImageTagsRequestWrapper(const PFMultiplayerServerListContainerImageTagsRequest& model) :
        ModelWrapper<PFMultiplayerServerListContainerImageTagsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_imageName{ SafeString(model.imageName) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListContainerImageTagsRequestWrapper(const PFMultiplayerServerListContainerImageTagsRequestWrapper& src) :
        PFMultiplayerServerListContainerImageTagsRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListContainerImageTagsRequestWrapper(PFMultiplayerServerListContainerImageTagsRequestWrapper&& src) :
        PFMultiplayerServerListContainerImageTagsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListContainerImageTagsRequestWrapper& operator=(PFMultiplayerServerListContainerImageTagsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListContainerImageTagsRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListContainerImageTagsRequestWrapper& lhs, PFMultiplayerServerListContainerImageTagsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_imageName, rhs.m_imageName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetImageName(String value)
    {
        m_imageName = std::move(value);
        this->m_model.imageName =  m_imageName.empty() ? nullptr : m_imageName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.imageName = m_imageName.empty() ? nullptr : m_imageName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_imageName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListContainerImageTagsResponseWrapper : public ModelWrapper<PFMultiplayerServerListContainerImageTagsResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListContainerImageTagsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListContainerImageTagsResponseWrapper() = default;

    PFMultiplayerServerListContainerImageTagsResponseWrapper(const PFMultiplayerServerListContainerImageTagsResponse& model) :
        ModelWrapper<PFMultiplayerServerListContainerImageTagsResponse, Alloc>{ model },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListContainerImageTagsResponseWrapper(const PFMultiplayerServerListContainerImageTagsResponseWrapper& src) :
        PFMultiplayerServerListContainerImageTagsResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListContainerImageTagsResponseWrapper(PFMultiplayerServerListContainerImageTagsResponseWrapper&& src) :
        PFMultiplayerServerListContainerImageTagsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListContainerImageTagsResponseWrapper& operator=(PFMultiplayerServerListContainerImageTagsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListContainerImageTagsResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListContainerImageTagsResponseWrapper& lhs, PFMultiplayerServerListContainerImageTagsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTags(CStringVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    CStringVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListPartyQosServersRequestWrapper : public ModelWrapper<PFMultiplayerServerListPartyQosServersRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListPartyQosServersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListPartyQosServersRequestWrapper() = default;

    PFMultiplayerServerListPartyQosServersRequestWrapper(const PFMultiplayerServerListPartyQosServersRequest& model) :
        ModelWrapper<PFMultiplayerServerListPartyQosServersRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListPartyQosServersRequestWrapper(const PFMultiplayerServerListPartyQosServersRequestWrapper& src) :
        PFMultiplayerServerListPartyQosServersRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListPartyQosServersRequestWrapper(PFMultiplayerServerListPartyQosServersRequestWrapper&& src) :
        PFMultiplayerServerListPartyQosServersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListPartyQosServersRequestWrapper& operator=(PFMultiplayerServerListPartyQosServersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListPartyQosServersRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListPartyQosServersRequestWrapper& lhs, PFMultiplayerServerListPartyQosServersRequestWrapper& rhs)
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
class PFMultiplayerServerQosServerWrapper : public ModelWrapper<PFMultiplayerServerQosServer, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerQosServer;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerQosServerWrapper() = default;

    PFMultiplayerServerQosServerWrapper(const PFMultiplayerServerQosServer& model) :
        ModelWrapper<PFMultiplayerServerQosServer, Alloc>{ model },
        m_region{ SafeString(model.region) },
        m_serverUrl{ SafeString(model.serverUrl) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerQosServerWrapper(const PFMultiplayerServerQosServerWrapper& src) :
        PFMultiplayerServerQosServerWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerQosServerWrapper(PFMultiplayerServerQosServerWrapper&& src) :
        PFMultiplayerServerQosServerWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerQosServerWrapper& operator=(PFMultiplayerServerQosServerWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerQosServerWrapper() = default;

    friend void swap(PFMultiplayerServerQosServerWrapper& lhs, PFMultiplayerServerQosServerWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_serverUrl, rhs.m_serverUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetServerUrl(String value)
    {
        m_serverUrl = std::move(value);
        this->m_model.serverUrl =  m_serverUrl.empty() ? nullptr : m_serverUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.serverUrl = m_serverUrl.empty() ? nullptr : m_serverUrl.data();
    }

    String m_region;
    String m_serverUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListPartyQosServersResponseWrapper : public ModelWrapper<PFMultiplayerServerListPartyQosServersResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListPartyQosServersResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListPartyQosServersResponseWrapper() = default;

    PFMultiplayerServerListPartyQosServersResponseWrapper(const PFMultiplayerServerListPartyQosServersResponse& model) :
        ModelWrapper<PFMultiplayerServerListPartyQosServersResponse, Alloc>{ model },
        m_qosServers{ model.qosServers, model.qosServers + model.qosServersCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListPartyQosServersResponseWrapper(const PFMultiplayerServerListPartyQosServersResponseWrapper& src) :
        PFMultiplayerServerListPartyQosServersResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListPartyQosServersResponseWrapper(PFMultiplayerServerListPartyQosServersResponseWrapper&& src) :
        PFMultiplayerServerListPartyQosServersResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListPartyQosServersResponseWrapper& operator=(PFMultiplayerServerListPartyQosServersResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListPartyQosServersResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListPartyQosServersResponseWrapper& lhs, PFMultiplayerServerListPartyQosServersResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_qosServers, rhs.m_qosServers);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetQosServers(ModelVector<PFMultiplayerServerQosServerWrapper<Alloc>, Alloc> value)
    {
        m_qosServers = std::move(value);
        this->m_model.qosServers =  m_qosServers.empty() ? nullptr : m_qosServers.data();
        this->m_model.qosServersCount =  static_cast<uint32_t>(m_qosServers.size());
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.qosServers = m_qosServers.empty() ? nullptr : m_qosServers.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerQosServerWrapper<Alloc>, Alloc> m_qosServers;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListQosServersForTitleRequestWrapper : public ModelWrapper<PFMultiplayerServerListQosServersForTitleRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListQosServersForTitleRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListQosServersForTitleRequestWrapper() = default;

    PFMultiplayerServerListQosServersForTitleRequestWrapper(const PFMultiplayerServerListQosServersForTitleRequest& model) :
        ModelWrapper<PFMultiplayerServerListQosServersForTitleRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_includeAllRegions{ model.includeAllRegions ? StdExtra::optional<bool>{ *model.includeAllRegions } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListQosServersForTitleRequestWrapper(const PFMultiplayerServerListQosServersForTitleRequestWrapper& src) :
        PFMultiplayerServerListQosServersForTitleRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListQosServersForTitleRequestWrapper(PFMultiplayerServerListQosServersForTitleRequestWrapper&& src) :
        PFMultiplayerServerListQosServersForTitleRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListQosServersForTitleRequestWrapper& operator=(PFMultiplayerServerListQosServersForTitleRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListQosServersForTitleRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListQosServersForTitleRequestWrapper& lhs, PFMultiplayerServerListQosServersForTitleRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_includeAllRegions, rhs.m_includeAllRegions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetIncludeAllRegions(StdExtra::optional<bool> value)
    {
        m_includeAllRegions = std::move(value);
        this->m_model.includeAllRegions = m_includeAllRegions ? m_includeAllRegions.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.includeAllRegions = m_includeAllRegions ? m_includeAllRegions.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_includeAllRegions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListQosServersForTitleResponseWrapper : public ModelWrapper<PFMultiplayerServerListQosServersForTitleResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListQosServersForTitleResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListQosServersForTitleResponseWrapper() = default;

    PFMultiplayerServerListQosServersForTitleResponseWrapper(const PFMultiplayerServerListQosServersForTitleResponse& model) :
        ModelWrapper<PFMultiplayerServerListQosServersForTitleResponse, Alloc>{ model },
        m_qosServers{ model.qosServers, model.qosServers + model.qosServersCount },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListQosServersForTitleResponseWrapper(const PFMultiplayerServerListQosServersForTitleResponseWrapper& src) :
        PFMultiplayerServerListQosServersForTitleResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListQosServersForTitleResponseWrapper(PFMultiplayerServerListQosServersForTitleResponseWrapper&& src) :
        PFMultiplayerServerListQosServersForTitleResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListQosServersForTitleResponseWrapper& operator=(PFMultiplayerServerListQosServersForTitleResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListQosServersForTitleResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListQosServersForTitleResponseWrapper& lhs, PFMultiplayerServerListQosServersForTitleResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_qosServers, rhs.m_qosServers);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetQosServers(ModelVector<PFMultiplayerServerQosServerWrapper<Alloc>, Alloc> value)
    {
        m_qosServers = std::move(value);
        this->m_model.qosServers =  m_qosServers.empty() ? nullptr : m_qosServers.data();
        this->m_model.qosServersCount =  static_cast<uint32_t>(m_qosServers.size());
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.qosServers = m_qosServers.empty() ? nullptr : m_qosServers.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    ModelVector<PFMultiplayerServerQosServerWrapper<Alloc>, Alloc> m_qosServers;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper : public ModelWrapper<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper() = default;

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest& model) :
        ModelWrapper<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper& src) :
        PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper&& src) :
        PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper& operator=(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper& lhs, PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper& rhs)
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
class PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper : public ModelWrapper<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper() = default;

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& model) :
        ModelWrapper<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse, Alloc>{ model },
        m_changes{ model.changes, model.changes + model.changesCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper& src) :
        PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper&& src) :
        PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper& operator=(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper& lhs, PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_changes, rhs.m_changes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChanges(ModelVector<PFMultiplayerServerQuotaChangeWrapper<Alloc>, Alloc> value)
    {
        m_changes = std::move(value);
        this->m_model.changes =  m_changes.empty() ? nullptr : m_changes.data();
        this->m_model.changesCount =  static_cast<uint32_t>(m_changes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.changes = m_changes.empty() ? nullptr : m_changes.data();
    }

    ModelVector<PFMultiplayerServerQuotaChangeWrapper<Alloc>, Alloc> m_changes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListVirtualMachineSummariesRequestWrapper : public ModelWrapper<PFMultiplayerServerListVirtualMachineSummariesRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListVirtualMachineSummariesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListVirtualMachineSummariesRequestWrapper() = default;

    PFMultiplayerServerListVirtualMachineSummariesRequestWrapper(const PFMultiplayerServerListVirtualMachineSummariesRequest& model) :
        ModelWrapper<PFMultiplayerServerListVirtualMachineSummariesRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pageSize{ model.pageSize ? StdExtra::optional<int32_t>{ *model.pageSize } : StdExtra::nullopt },
        m_region{ SafeString(model.region) },
        m_skipToken{ SafeString(model.skipToken) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListVirtualMachineSummariesRequestWrapper(const PFMultiplayerServerListVirtualMachineSummariesRequestWrapper& src) :
        PFMultiplayerServerListVirtualMachineSummariesRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListVirtualMachineSummariesRequestWrapper(PFMultiplayerServerListVirtualMachineSummariesRequestWrapper&& src) :
        PFMultiplayerServerListVirtualMachineSummariesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListVirtualMachineSummariesRequestWrapper& operator=(PFMultiplayerServerListVirtualMachineSummariesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListVirtualMachineSummariesRequestWrapper() = default;

    friend void swap(PFMultiplayerServerListVirtualMachineSummariesRequestWrapper& lhs, PFMultiplayerServerListVirtualMachineSummariesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pageSize, rhs.m_pageSize);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPageSize(StdExtra::optional<int32_t> value)
    {
        m_pageSize = std::move(value);
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pageSize = m_pageSize ? m_pageSize.operator->() : nullptr;
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_pageSize;
    String m_region;
    String m_skipToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerVirtualMachineSummaryWrapper : public ModelWrapper<PFMultiplayerServerVirtualMachineSummary, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerVirtualMachineSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerVirtualMachineSummaryWrapper() = default;

    PFMultiplayerServerVirtualMachineSummaryWrapper(const PFMultiplayerServerVirtualMachineSummary& model) :
        ModelWrapper<PFMultiplayerServerVirtualMachineSummary, Alloc>{ model },
        m_healthStatus{ SafeString(model.healthStatus) },
        m_state{ SafeString(model.state) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerVirtualMachineSummaryWrapper(const PFMultiplayerServerVirtualMachineSummaryWrapper& src) :
        PFMultiplayerServerVirtualMachineSummaryWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerVirtualMachineSummaryWrapper(PFMultiplayerServerVirtualMachineSummaryWrapper&& src) :
        PFMultiplayerServerVirtualMachineSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerVirtualMachineSummaryWrapper& operator=(PFMultiplayerServerVirtualMachineSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerVirtualMachineSummaryWrapper() = default;

    friend void swap(PFMultiplayerServerVirtualMachineSummaryWrapper& lhs, PFMultiplayerServerVirtualMachineSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_healthStatus, rhs.m_healthStatus);
        swap(lhs.m_state, rhs.m_state);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetHealthStatus(String value)
    {
        m_healthStatus = std::move(value);
        this->m_model.healthStatus =  m_healthStatus.empty() ? nullptr : m_healthStatus.data();
    }

    void SetState(String value)
    {
        m_state = std::move(value);
        this->m_model.state =  m_state.empty() ? nullptr : m_state.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.healthStatus = m_healthStatus.empty() ? nullptr : m_healthStatus.data();
        this->m_model.state = m_state.empty() ? nullptr : m_state.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    String m_healthStatus;
    String m_state;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerListVirtualMachineSummariesResponseWrapper : public ModelWrapper<PFMultiplayerServerListVirtualMachineSummariesResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerListVirtualMachineSummariesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerListVirtualMachineSummariesResponseWrapper() = default;

    PFMultiplayerServerListVirtualMachineSummariesResponseWrapper(const PFMultiplayerServerListVirtualMachineSummariesResponse& model) :
        ModelWrapper<PFMultiplayerServerListVirtualMachineSummariesResponse, Alloc>{ model },
        m_skipToken{ SafeString(model.skipToken) },
        m_virtualMachines{ model.virtualMachines, model.virtualMachines + model.virtualMachinesCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerListVirtualMachineSummariesResponseWrapper(const PFMultiplayerServerListVirtualMachineSummariesResponseWrapper& src) :
        PFMultiplayerServerListVirtualMachineSummariesResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerListVirtualMachineSummariesResponseWrapper(PFMultiplayerServerListVirtualMachineSummariesResponseWrapper&& src) :
        PFMultiplayerServerListVirtualMachineSummariesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerListVirtualMachineSummariesResponseWrapper& operator=(PFMultiplayerServerListVirtualMachineSummariesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerListVirtualMachineSummariesResponseWrapper() = default;

    friend void swap(PFMultiplayerServerListVirtualMachineSummariesResponseWrapper& lhs, PFMultiplayerServerListVirtualMachineSummariesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_skipToken, rhs.m_skipToken);
        swap(lhs.m_virtualMachines, rhs.m_virtualMachines);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPageSize(int32_t value)
    {
        this->m_model.pageSize = value;
    }

    void SetSkipToken(String value)
    {
        m_skipToken = std::move(value);
        this->m_model.skipToken =  m_skipToken.empty() ? nullptr : m_skipToken.data();
    }

    void SetVirtualMachines(ModelVector<PFMultiplayerServerVirtualMachineSummaryWrapper<Alloc>, Alloc> value)
    {
        m_virtualMachines = std::move(value);
        this->m_model.virtualMachines =  m_virtualMachines.empty() ? nullptr : m_virtualMachines.data();
        this->m_model.virtualMachinesCount =  static_cast<uint32_t>(m_virtualMachines.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.skipToken = m_skipToken.empty() ? nullptr : m_skipToken.data();
        this->m_model.virtualMachines = m_virtualMachines.empty() ? nullptr : m_virtualMachines.data();
    }

    String m_skipToken;
    ModelVector<PFMultiplayerServerVirtualMachineSummaryWrapper<Alloc>, Alloc> m_virtualMachines;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerBuildAliasParamsWrapper : public ModelWrapper<PFMultiplayerServerBuildAliasParams, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerBuildAliasParams;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerBuildAliasParamsWrapper() = default;

    PFMultiplayerServerBuildAliasParamsWrapper(const PFMultiplayerServerBuildAliasParams& model) :
        ModelWrapper<PFMultiplayerServerBuildAliasParams, Alloc>{ model },
        m_aliasId{ SafeString(model.aliasId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerBuildAliasParamsWrapper(const PFMultiplayerServerBuildAliasParamsWrapper& src) :
        PFMultiplayerServerBuildAliasParamsWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerBuildAliasParamsWrapper(PFMultiplayerServerBuildAliasParamsWrapper&& src) :
        PFMultiplayerServerBuildAliasParamsWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerBuildAliasParamsWrapper& operator=(PFMultiplayerServerBuildAliasParamsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerBuildAliasParamsWrapper() = default;

    friend void swap(PFMultiplayerServerBuildAliasParamsWrapper& lhs, PFMultiplayerServerBuildAliasParamsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aliasId, rhs.m_aliasId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAliasId(String value)
    {
        m_aliasId = std::move(value);
        this->m_model.aliasId =  m_aliasId.empty() ? nullptr : m_aliasId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.aliasId = m_aliasId.empty() ? nullptr : m_aliasId.data();
    }

    String m_aliasId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerRequestMultiplayerServerRequestWrapper : public ModelWrapper<PFMultiplayerServerRequestMultiplayerServerRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerRequestMultiplayerServerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerRequestMultiplayerServerRequestWrapper() = default;

    PFMultiplayerServerRequestMultiplayerServerRequestWrapper(const PFMultiplayerServerRequestMultiplayerServerRequest& model) :
        ModelWrapper<PFMultiplayerServerRequestMultiplayerServerRequest, Alloc>{ model },
        m_buildAliasParams{ model.buildAliasParams ? StdExtra::optional<PFMultiplayerServerBuildAliasParamsWrapper<Alloc>>{ *model.buildAliasParams } : StdExtra::nullopt },
        m_buildId{ SafeString(model.buildId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_initialPlayers{ model.initialPlayers, model.initialPlayers + model.initialPlayersCount },
        m_preferredRegions{ model.preferredRegions, model.preferredRegions + model.preferredRegionsCount },
        m_sessionCookie{ SafeString(model.sessionCookie) },
        m_sessionId{ SafeString(model.sessionId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerRequestMultiplayerServerRequestWrapper(const PFMultiplayerServerRequestMultiplayerServerRequestWrapper& src) :
        PFMultiplayerServerRequestMultiplayerServerRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerRequestMultiplayerServerRequestWrapper(PFMultiplayerServerRequestMultiplayerServerRequestWrapper&& src) :
        PFMultiplayerServerRequestMultiplayerServerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerRequestMultiplayerServerRequestWrapper& operator=(PFMultiplayerServerRequestMultiplayerServerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerRequestMultiplayerServerRequestWrapper() = default;

    friend void swap(PFMultiplayerServerRequestMultiplayerServerRequestWrapper& lhs, PFMultiplayerServerRequestMultiplayerServerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildAliasParams, rhs.m_buildAliasParams);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_initialPlayers, rhs.m_initialPlayers);
        swap(lhs.m_preferredRegions, rhs.m_preferredRegions);
        swap(lhs.m_sessionCookie, rhs.m_sessionCookie);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildAliasParams(StdExtra::optional<PFMultiplayerServerBuildAliasParamsWrapper<Alloc>> value)
    {
        m_buildAliasParams = std::move(value);
        this->m_model.buildAliasParams = m_buildAliasParams ? &m_buildAliasParams->Model() : nullptr;
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInitialPlayers(CStringVector<Alloc> value)
    {
        m_initialPlayers = std::move(value);
        this->m_model.initialPlayers =  m_initialPlayers.empty() ? nullptr : m_initialPlayers.data();
        this->m_model.initialPlayersCount =  static_cast<uint32_t>(m_initialPlayers.size());
    }

    void SetPreferredRegions(CStringVector<Alloc> value)
    {
        m_preferredRegions = std::move(value);
        this->m_model.preferredRegions =  m_preferredRegions.empty() ? nullptr : m_preferredRegions.data();
        this->m_model.preferredRegionsCount =  static_cast<uint32_t>(m_preferredRegions.size());
    }

    void SetSessionCookie(String value)
    {
        m_sessionCookie = std::move(value);
        this->m_model.sessionCookie =  m_sessionCookie.empty() ? nullptr : m_sessionCookie.data();
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildAliasParams = m_buildAliasParams ?  &m_buildAliasParams->Model() : nullptr;
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.initialPlayers = m_initialPlayers.empty() ? nullptr : m_initialPlayers.data();
        this->m_model.preferredRegions = m_preferredRegions.empty() ? nullptr : m_preferredRegions.data();
        this->m_model.sessionCookie = m_sessionCookie.empty() ? nullptr : m_sessionCookie.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    StdExtra::optional<PFMultiplayerServerBuildAliasParamsWrapper<Alloc>> m_buildAliasParams;
    String m_buildId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    CStringVector<Alloc> m_initialPlayers;
    CStringVector<Alloc> m_preferredRegions;
    String m_sessionCookie;
    String m_sessionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerRequestMultiplayerServerResponseWrapper : public ModelWrapper<PFMultiplayerServerRequestMultiplayerServerResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerRequestMultiplayerServerResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerRequestMultiplayerServerResponseWrapper() = default;

    PFMultiplayerServerRequestMultiplayerServerResponseWrapper(const PFMultiplayerServerRequestMultiplayerServerResponse& model) :
        ModelWrapper<PFMultiplayerServerRequestMultiplayerServerResponse, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_connectedPlayers{ model.connectedPlayers, model.connectedPlayers + model.connectedPlayersCount },
        m_fQDN{ SafeString(model.fQDN) },
        m_iPV4Address{ SafeString(model.iPV4Address) },
        m_lastStateTransitionTime{ model.lastStateTransitionTime ? StdExtra::optional<time_t>{ *model.lastStateTransitionTime } : StdExtra::nullopt },
        m_ports{ model.ports, model.ports + model.portsCount },
        m_region{ SafeString(model.region) },
        m_serverId{ SafeString(model.serverId) },
        m_sessionId{ SafeString(model.sessionId) },
        m_state{ SafeString(model.state) },
        m_vmId{ SafeString(model.vmId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerRequestMultiplayerServerResponseWrapper(const PFMultiplayerServerRequestMultiplayerServerResponseWrapper& src) :
        PFMultiplayerServerRequestMultiplayerServerResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerRequestMultiplayerServerResponseWrapper(PFMultiplayerServerRequestMultiplayerServerResponseWrapper&& src) :
        PFMultiplayerServerRequestMultiplayerServerResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerRequestMultiplayerServerResponseWrapper& operator=(PFMultiplayerServerRequestMultiplayerServerResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerRequestMultiplayerServerResponseWrapper() = default;

    friend void swap(PFMultiplayerServerRequestMultiplayerServerResponseWrapper& lhs, PFMultiplayerServerRequestMultiplayerServerResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_connectedPlayers, rhs.m_connectedPlayers);
        swap(lhs.m_fQDN, rhs.m_fQDN);
        swap(lhs.m_iPV4Address, rhs.m_iPV4Address);
        swap(lhs.m_lastStateTransitionTime, rhs.m_lastStateTransitionTime);
        swap(lhs.m_ports, rhs.m_ports);
        swap(lhs.m_region, rhs.m_region);
        swap(lhs.m_serverId, rhs.m_serverId);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        swap(lhs.m_state, rhs.m_state);
        swap(lhs.m_vmId, rhs.m_vmId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetConnectedPlayers(ModelVector<PFMultiplayerServerConnectedPlayerWrapper<Alloc>, Alloc> value)
    {
        m_connectedPlayers = std::move(value);
        this->m_model.connectedPlayers =  m_connectedPlayers.empty() ? nullptr : m_connectedPlayers.data();
        this->m_model.connectedPlayersCount =  static_cast<uint32_t>(m_connectedPlayers.size());
    }

    void SetFQDN(String value)
    {
        m_fQDN = std::move(value);
        this->m_model.fQDN =  m_fQDN.empty() ? nullptr : m_fQDN.data();
    }

    void SetIPV4Address(String value)
    {
        m_iPV4Address = std::move(value);
        this->m_model.iPV4Address =  m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
    }

    void SetLastStateTransitionTime(StdExtra::optional<time_t> value)
    {
        m_lastStateTransitionTime = std::move(value);
        this->m_model.lastStateTransitionTime = m_lastStateTransitionTime ? m_lastStateTransitionTime.operator->() : nullptr;
    }

    void SetPorts(ModelVector<PFPortWrapper<Alloc>, Alloc> value)
    {
        m_ports = std::move(value);
        this->m_model.ports =  m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.portsCount =  static_cast<uint32_t>(m_ports.size());
    }

    void SetRegion(String value)
    {
        m_region = std::move(value);
        this->m_model.region =  m_region.empty() ? nullptr : m_region.data();
    }

    void SetServerId(String value)
    {
        m_serverId = std::move(value);
        this->m_model.serverId =  m_serverId.empty() ? nullptr : m_serverId.data();
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    void SetState(String value)
    {
        m_state = std::move(value);
        this->m_model.state =  m_state.empty() ? nullptr : m_state.data();
    }

    void SetVmId(String value)
    {
        m_vmId = std::move(value);
        this->m_model.vmId =  m_vmId.empty() ? nullptr : m_vmId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.connectedPlayers = m_connectedPlayers.empty() ? nullptr : m_connectedPlayers.data();
        this->m_model.fQDN = m_fQDN.empty() ? nullptr : m_fQDN.data();
        this->m_model.iPV4Address = m_iPV4Address.empty() ? nullptr : m_iPV4Address.data();
        this->m_model.lastStateTransitionTime = m_lastStateTransitionTime ? m_lastStateTransitionTime.operator->() : nullptr;
        this->m_model.ports = m_ports.empty() ? nullptr : m_ports.data();
        this->m_model.region = m_region.empty() ? nullptr : m_region.data();
        this->m_model.serverId = m_serverId.empty() ? nullptr : m_serverId.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
        this->m_model.state = m_state.empty() ? nullptr : m_state.data();
        this->m_model.vmId = m_vmId.empty() ? nullptr : m_vmId.data();
    }

    String m_buildId;
    ModelVector<PFMultiplayerServerConnectedPlayerWrapper<Alloc>, Alloc> m_connectedPlayers;
    String m_fQDN;
    String m_iPV4Address;
    StdExtra::optional<time_t> m_lastStateTransitionTime;
    ModelVector<PFPortWrapper<Alloc>, Alloc> m_ports;
    String m_region;
    String m_serverId;
    String m_sessionId;
    String m_state;
    String m_vmId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper : public ModelWrapper<PFMultiplayerServerRolloverContainerRegistryCredentialsRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerRolloverContainerRegistryCredentialsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper() = default;

    PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper(const PFMultiplayerServerRolloverContainerRegistryCredentialsRequest& model) :
        ModelWrapper<PFMultiplayerServerRolloverContainerRegistryCredentialsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper(const PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper& src) :
        PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper(PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper&& src) :
        PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper& operator=(PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper() = default;

    friend void swap(PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper& lhs, PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper& rhs)
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
class PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper : public ModelWrapper<PFMultiplayerServerRolloverContainerRegistryCredentialsResponse, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerRolloverContainerRegistryCredentialsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper() = default;

    PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper(const PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& model) :
        ModelWrapper<PFMultiplayerServerRolloverContainerRegistryCredentialsResponse, Alloc>{ model },
        m_dnsName{ SafeString(model.dnsName) },
        m_password{ SafeString(model.password) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper(const PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper& src) :
        PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper(PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper&& src) :
        PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper& operator=(PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper() = default;

    friend void swap(PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper& lhs, PFMultiplayerServerRolloverContainerRegistryCredentialsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dnsName, rhs.m_dnsName);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDnsName(String value)
    {
        m_dnsName = std::move(value);
        this->m_model.dnsName =  m_dnsName.empty() ? nullptr : m_dnsName.data();
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
        this->m_model.dnsName = m_dnsName.empty() ? nullptr : m_dnsName.data();
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    String m_dnsName;
    String m_password;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerShutdownMultiplayerServerRequestWrapper : public ModelWrapper<PFMultiplayerServerShutdownMultiplayerServerRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerShutdownMultiplayerServerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerShutdownMultiplayerServerRequestWrapper() = default;

    PFMultiplayerServerShutdownMultiplayerServerRequestWrapper(const PFMultiplayerServerShutdownMultiplayerServerRequest& model) :
        ModelWrapper<PFMultiplayerServerShutdownMultiplayerServerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_sessionId{ SafeString(model.sessionId) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerShutdownMultiplayerServerRequestWrapper(const PFMultiplayerServerShutdownMultiplayerServerRequestWrapper& src) :
        PFMultiplayerServerShutdownMultiplayerServerRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerShutdownMultiplayerServerRequestWrapper(PFMultiplayerServerShutdownMultiplayerServerRequestWrapper&& src) :
        PFMultiplayerServerShutdownMultiplayerServerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerShutdownMultiplayerServerRequestWrapper& operator=(PFMultiplayerServerShutdownMultiplayerServerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerShutdownMultiplayerServerRequestWrapper() = default;

    friend void swap(PFMultiplayerServerShutdownMultiplayerServerRequestWrapper& lhs, PFMultiplayerServerShutdownMultiplayerServerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_sessionId, rhs.m_sessionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetSessionId(String value)
    {
        m_sessionId = std::move(value);
        this->m_model.sessionId =  m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.sessionId = m_sessionId.empty() ? nullptr : m_sessionId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_sessionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerUntagContainerImageRequestWrapper : public ModelWrapper<PFMultiplayerServerUntagContainerImageRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerUntagContainerImageRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerUntagContainerImageRequestWrapper() = default;

    PFMultiplayerServerUntagContainerImageRequestWrapper(const PFMultiplayerServerUntagContainerImageRequest& model) :
        ModelWrapper<PFMultiplayerServerUntagContainerImageRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_imageName{ SafeString(model.imageName) },
        m_tag{ SafeString(model.tag) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerUntagContainerImageRequestWrapper(const PFMultiplayerServerUntagContainerImageRequestWrapper& src) :
        PFMultiplayerServerUntagContainerImageRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerUntagContainerImageRequestWrapper(PFMultiplayerServerUntagContainerImageRequestWrapper&& src) :
        PFMultiplayerServerUntagContainerImageRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerUntagContainerImageRequestWrapper& operator=(PFMultiplayerServerUntagContainerImageRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerUntagContainerImageRequestWrapper() = default;

    friend void swap(PFMultiplayerServerUntagContainerImageRequestWrapper& lhs, PFMultiplayerServerUntagContainerImageRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_imageName, rhs.m_imageName);
        swap(lhs.m_tag, rhs.m_tag);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetImageName(String value)
    {
        m_imageName = std::move(value);
        this->m_model.imageName =  m_imageName.empty() ? nullptr : m_imageName.data();
    }

    void SetTag(String value)
    {
        m_tag = std::move(value);
        this->m_model.tag =  m_tag.empty() ? nullptr : m_tag.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.imageName = m_imageName.empty() ? nullptr : m_imageName.data();
        this->m_model.tag = m_tag.empty() ? nullptr : m_tag.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_imageName;
    String m_tag;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerUpdateBuildAliasRequestWrapper : public ModelWrapper<PFMultiplayerServerUpdateBuildAliasRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerUpdateBuildAliasRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerUpdateBuildAliasRequestWrapper() = default;

    PFMultiplayerServerUpdateBuildAliasRequestWrapper(const PFMultiplayerServerUpdateBuildAliasRequest& model) :
        ModelWrapper<PFMultiplayerServerUpdateBuildAliasRequest, Alloc>{ model },
        m_aliasId{ SafeString(model.aliasId) },
        m_aliasName{ SafeString(model.aliasName) },
        m_buildSelectionCriteria{ model.buildSelectionCriteria, model.buildSelectionCriteria + model.buildSelectionCriteriaCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerUpdateBuildAliasRequestWrapper(const PFMultiplayerServerUpdateBuildAliasRequestWrapper& src) :
        PFMultiplayerServerUpdateBuildAliasRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerUpdateBuildAliasRequestWrapper(PFMultiplayerServerUpdateBuildAliasRequestWrapper&& src) :
        PFMultiplayerServerUpdateBuildAliasRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerUpdateBuildAliasRequestWrapper& operator=(PFMultiplayerServerUpdateBuildAliasRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerUpdateBuildAliasRequestWrapper() = default;

    friend void swap(PFMultiplayerServerUpdateBuildAliasRequestWrapper& lhs, PFMultiplayerServerUpdateBuildAliasRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aliasId, rhs.m_aliasId);
        swap(lhs.m_aliasName, rhs.m_aliasName);
        swap(lhs.m_buildSelectionCriteria, rhs.m_buildSelectionCriteria);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAliasId(String value)
    {
        m_aliasId = std::move(value);
        this->m_model.aliasId =  m_aliasId.empty() ? nullptr : m_aliasId.data();
    }

    void SetAliasName(String value)
    {
        m_aliasName = std::move(value);
        this->m_model.aliasName =  m_aliasName.empty() ? nullptr : m_aliasName.data();
    }

    void SetBuildSelectionCriteria(ModelVector<PFMultiplayerServerBuildSelectionCriterionWrapper<Alloc>, Alloc> value)
    {
        m_buildSelectionCriteria = std::move(value);
        this->m_model.buildSelectionCriteria =  m_buildSelectionCriteria.empty() ? nullptr : m_buildSelectionCriteria.data();
        this->m_model.buildSelectionCriteriaCount =  static_cast<uint32_t>(m_buildSelectionCriteria.size());
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
        this->m_model.aliasId = m_aliasId.empty() ? nullptr : m_aliasId.data();
        this->m_model.aliasName = m_aliasName.empty() ? nullptr : m_aliasName.data();
        this->m_model.buildSelectionCriteria = m_buildSelectionCriteria.empty() ? nullptr : m_buildSelectionCriteria.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_aliasId;
    String m_aliasName;
    ModelVector<PFMultiplayerServerBuildSelectionCriterionWrapper<Alloc>, Alloc> m_buildSelectionCriteria;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerUpdateBuildNameRequestWrapper : public ModelWrapper<PFMultiplayerServerUpdateBuildNameRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerUpdateBuildNameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerUpdateBuildNameRequestWrapper() = default;

    PFMultiplayerServerUpdateBuildNameRequestWrapper(const PFMultiplayerServerUpdateBuildNameRequest& model) :
        ModelWrapper<PFMultiplayerServerUpdateBuildNameRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_buildName{ SafeString(model.buildName) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerUpdateBuildNameRequestWrapper(const PFMultiplayerServerUpdateBuildNameRequestWrapper& src) :
        PFMultiplayerServerUpdateBuildNameRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerUpdateBuildNameRequestWrapper(PFMultiplayerServerUpdateBuildNameRequestWrapper&& src) :
        PFMultiplayerServerUpdateBuildNameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerUpdateBuildNameRequestWrapper& operator=(PFMultiplayerServerUpdateBuildNameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerUpdateBuildNameRequestWrapper() = default;

    friend void swap(PFMultiplayerServerUpdateBuildNameRequestWrapper& lhs, PFMultiplayerServerUpdateBuildNameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildName, rhs.m_buildName);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildName(String value)
    {
        m_buildName = std::move(value);
        this->m_model.buildName =  m_buildName.empty() ? nullptr : m_buildName.data();
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
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildName = m_buildName.empty() ? nullptr : m_buildName.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_buildId;
    String m_buildName;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerUpdateBuildRegionRequestWrapper : public ModelWrapper<PFMultiplayerServerUpdateBuildRegionRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerUpdateBuildRegionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerUpdateBuildRegionRequestWrapper() = default;

    PFMultiplayerServerUpdateBuildRegionRequestWrapper(const PFMultiplayerServerUpdateBuildRegionRequest& model) :
        ModelWrapper<PFMultiplayerServerUpdateBuildRegionRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_buildRegion{ model.buildRegion ? *model.buildRegion : decltype(*model.buildRegion){} },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerUpdateBuildRegionRequestWrapper(const PFMultiplayerServerUpdateBuildRegionRequestWrapper& src) :
        PFMultiplayerServerUpdateBuildRegionRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerUpdateBuildRegionRequestWrapper(PFMultiplayerServerUpdateBuildRegionRequestWrapper&& src) :
        PFMultiplayerServerUpdateBuildRegionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerUpdateBuildRegionRequestWrapper& operator=(PFMultiplayerServerUpdateBuildRegionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerUpdateBuildRegionRequestWrapper() = default;

    friend void swap(PFMultiplayerServerUpdateBuildRegionRequestWrapper& lhs, PFMultiplayerServerUpdateBuildRegionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildRegion, rhs.m_buildRegion);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildRegion(PFMultiplayerServerBuildRegionParamsWrapper<Alloc> value)
    {
        m_buildRegion = std::move(value);
        this->m_model.buildRegion = &m_buildRegion.Model();
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
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildRegion = &m_buildRegion.Model();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_buildId;
    PFMultiplayerServerBuildRegionParamsWrapper<Alloc> m_buildRegion;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerUpdateBuildRegionsRequestWrapper : public ModelWrapper<PFMultiplayerServerUpdateBuildRegionsRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerUpdateBuildRegionsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerUpdateBuildRegionsRequestWrapper() = default;

    PFMultiplayerServerUpdateBuildRegionsRequestWrapper(const PFMultiplayerServerUpdateBuildRegionsRequest& model) :
        ModelWrapper<PFMultiplayerServerUpdateBuildRegionsRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) },
        m_buildRegions{ model.buildRegions, model.buildRegions + model.buildRegionsCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFMultiplayerServerUpdateBuildRegionsRequestWrapper(const PFMultiplayerServerUpdateBuildRegionsRequestWrapper& src) :
        PFMultiplayerServerUpdateBuildRegionsRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerUpdateBuildRegionsRequestWrapper(PFMultiplayerServerUpdateBuildRegionsRequestWrapper&& src) :
        PFMultiplayerServerUpdateBuildRegionsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerUpdateBuildRegionsRequestWrapper& operator=(PFMultiplayerServerUpdateBuildRegionsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerUpdateBuildRegionsRequestWrapper() = default;

    friend void swap(PFMultiplayerServerUpdateBuildRegionsRequestWrapper& lhs, PFMultiplayerServerUpdateBuildRegionsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_buildRegions, rhs.m_buildRegions);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetBuildRegions(ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> value)
    {
        m_buildRegions = std::move(value);
        this->m_model.buildRegions =  m_buildRegions.empty() ? nullptr : m_buildRegions.data();
        this->m_model.buildRegionsCount =  static_cast<uint32_t>(m_buildRegions.size());
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
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.buildRegions = m_buildRegions.empty() ? nullptr : m_buildRegions.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_buildId;
    ModelVector<PFMultiplayerServerBuildRegionParamsWrapper<Alloc>, Alloc> m_buildRegions;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerCertificateWrapper : public ModelWrapper<PFMultiplayerServerCertificate, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerCertificate;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerCertificateWrapper() = default;

    PFMultiplayerServerCertificateWrapper(const PFMultiplayerServerCertificate& model) :
        ModelWrapper<PFMultiplayerServerCertificate, Alloc>{ model },
        m_base64EncodedValue{ SafeString(model.base64EncodedValue) },
        m_name{ SafeString(model.name) },
        m_password{ SafeString(model.password) }
    {
        SetModelPointers();
    }

    PFMultiplayerServerCertificateWrapper(const PFMultiplayerServerCertificateWrapper& src) :
        PFMultiplayerServerCertificateWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerCertificateWrapper(PFMultiplayerServerCertificateWrapper&& src) :
        PFMultiplayerServerCertificateWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerCertificateWrapper& operator=(PFMultiplayerServerCertificateWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerCertificateWrapper() = default;

    friend void swap(PFMultiplayerServerCertificateWrapper& lhs, PFMultiplayerServerCertificateWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_base64EncodedValue, rhs.m_base64EncodedValue);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_password, rhs.m_password);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBase64EncodedValue(String value)
    {
        m_base64EncodedValue = std::move(value);
        this->m_model.base64EncodedValue =  m_base64EncodedValue.empty() ? nullptr : m_base64EncodedValue.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.base64EncodedValue = m_base64EncodedValue.empty() ? nullptr : m_base64EncodedValue.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
    }

    String m_base64EncodedValue;
    String m_name;
    String m_password;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFMultiplayerServerUploadCertificateRequestWrapper : public ModelWrapper<PFMultiplayerServerUploadCertificateRequest, Alloc>
{
public:
    using ModelType = typename PFMultiplayerServerUploadCertificateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFMultiplayerServerUploadCertificateRequestWrapper() = default;

    PFMultiplayerServerUploadCertificateRequestWrapper(const PFMultiplayerServerUploadCertificateRequest& model) :
        ModelWrapper<PFMultiplayerServerUploadCertificateRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_gameCertificate{ model.gameCertificate ? *model.gameCertificate : decltype(*model.gameCertificate){} }
    {
        SetModelPointers();
    }

    PFMultiplayerServerUploadCertificateRequestWrapper(const PFMultiplayerServerUploadCertificateRequestWrapper& src) :
        PFMultiplayerServerUploadCertificateRequestWrapper{ src.Model() }
    {
    }

    PFMultiplayerServerUploadCertificateRequestWrapper(PFMultiplayerServerUploadCertificateRequestWrapper&& src) :
        PFMultiplayerServerUploadCertificateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFMultiplayerServerUploadCertificateRequestWrapper& operator=(PFMultiplayerServerUploadCertificateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFMultiplayerServerUploadCertificateRequestWrapper() = default;

    friend void swap(PFMultiplayerServerUploadCertificateRequestWrapper& lhs, PFMultiplayerServerUploadCertificateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_gameCertificate, rhs.m_gameCertificate);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetGameCertificate(PFMultiplayerServerCertificateWrapper<Alloc> value)
    {
        m_gameCertificate = std::move(value);
        this->m_model.gameCertificate = &m_gameCertificate.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.gameCertificate = &m_gameCertificate.Model();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFMultiplayerServerCertificateWrapper<Alloc> m_gameCertificate;
};

} // namespace Wrappers
} // namespace PlayFab
