// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFExperimentationDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationCreateExclusionGroupRequestWrapper : public ModelWrapper<PFExperimentationCreateExclusionGroupRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationCreateExclusionGroupRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationCreateExclusionGroupRequestWrapper() = default;

    PFExperimentationCreateExclusionGroupRequestWrapper(const PFExperimentationCreateExclusionGroupRequest& model) :
        ModelWrapper<PFExperimentationCreateExclusionGroupRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFExperimentationCreateExclusionGroupRequestWrapper(const PFExperimentationCreateExclusionGroupRequestWrapper& src) :
        PFExperimentationCreateExclusionGroupRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationCreateExclusionGroupRequestWrapper(PFExperimentationCreateExclusionGroupRequestWrapper&& src) :
        PFExperimentationCreateExclusionGroupRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationCreateExclusionGroupRequestWrapper& operator=(PFExperimentationCreateExclusionGroupRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationCreateExclusionGroupRequestWrapper() = default;

    friend void swap(PFExperimentationCreateExclusionGroupRequestWrapper& lhs, PFExperimentationCreateExclusionGroupRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
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

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
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
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationCreateExclusionGroupResultWrapper : public ModelWrapper<PFExperimentationCreateExclusionGroupResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationCreateExclusionGroupResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationCreateExclusionGroupResultWrapper() = default;

    PFExperimentationCreateExclusionGroupResultWrapper(const PFExperimentationCreateExclusionGroupResult& model) :
        ModelWrapper<PFExperimentationCreateExclusionGroupResult, Alloc>{ model },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) }
    {
        SetModelPointers();
    }

    PFExperimentationCreateExclusionGroupResultWrapper(const PFExperimentationCreateExclusionGroupResultWrapper& src) :
        PFExperimentationCreateExclusionGroupResultWrapper{ src.Model() }
    {
    }

    PFExperimentationCreateExclusionGroupResultWrapper(PFExperimentationCreateExclusionGroupResultWrapper&& src) :
        PFExperimentationCreateExclusionGroupResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationCreateExclusionGroupResultWrapper& operator=(PFExperimentationCreateExclusionGroupResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationCreateExclusionGroupResultWrapper() = default;

    friend void swap(PFExperimentationCreateExclusionGroupResultWrapper& lhs, PFExperimentationCreateExclusionGroupResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    String m_exclusionGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationVariantWrapper : public ModelWrapper<PFExperimentationVariant, Alloc>
{
public:
    using ModelType = typename PFExperimentationVariant;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationVariantWrapper() = default;

    PFExperimentationVariantWrapper(const PFExperimentationVariant& model) :
        ModelWrapper<PFExperimentationVariant, Alloc>{ model },
        m_description{ SafeString(model.description) },
        m_id{ SafeString(model.id) },
        m_name{ SafeString(model.name) },
        m_titleDataOverrideLabel{ SafeString(model.titleDataOverrideLabel) },
        m_variables{ model.variables, model.variables + model.variablesCount }
    {
        SetModelPointers();
    }

    PFExperimentationVariantWrapper(const PFExperimentationVariantWrapper& src) :
        PFExperimentationVariantWrapper{ src.Model() }
    {
    }

    PFExperimentationVariantWrapper(PFExperimentationVariantWrapper&& src) :
        PFExperimentationVariantWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationVariantWrapper& operator=(PFExperimentationVariantWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationVariantWrapper() = default;

    friend void swap(PFExperimentationVariantWrapper& lhs, PFExperimentationVariantWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_titleDataOverrideLabel, rhs.m_titleDataOverrideLabel);
        swap(lhs.m_variables, rhs.m_variables);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetIsControl(bool value)
    {
        this->m_model.isControl = value;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetTitleDataOverrideLabel(String value)
    {
        m_titleDataOverrideLabel = std::move(value);
        this->m_model.titleDataOverrideLabel =  m_titleDataOverrideLabel.empty() ? nullptr : m_titleDataOverrideLabel.data();
    }

    void SetTrafficPercentage(uint32_t value)
    {
        this->m_model.trafficPercentage = value;
    }

    void SetVariables(ModelVector<PFVariableWrapper<Alloc>, Alloc> value)
    {
        m_variables = std::move(value);
        this->m_model.variables =  m_variables.empty() ? nullptr : m_variables.data();
        this->m_model.variablesCount =  static_cast<uint32_t>(m_variables.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.titleDataOverrideLabel = m_titleDataOverrideLabel.empty() ? nullptr : m_titleDataOverrideLabel.data();
        this->m_model.variables = m_variables.empty() ? nullptr : m_variables.data();
    }

    String m_description;
    String m_id;
    String m_name;
    String m_titleDataOverrideLabel;
    ModelVector<PFVariableWrapper<Alloc>, Alloc> m_variables;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationCreateExperimentRequestWrapper : public ModelWrapper<PFExperimentationCreateExperimentRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationCreateExperimentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationCreateExperimentRequestWrapper() = default;

    PFExperimentationCreateExperimentRequestWrapper(const PFExperimentationCreateExperimentRequest& model) :
        ModelWrapper<PFExperimentationCreateExperimentRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_endDate{ model.endDate ? StdExtra::optional<time_t>{ *model.endDate } : StdExtra::nullopt },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) },
        m_exclusionGroupTrafficAllocation{ model.exclusionGroupTrafficAllocation ? StdExtra::optional<uint32_t>{ *model.exclusionGroupTrafficAllocation } : StdExtra::nullopt },
        m_experimentType{ model.experimentType ? StdExtra::optional<PFExperimentationExperimentType>{ *model.experimentType } : StdExtra::nullopt },
        m_name{ SafeString(model.name) },
        m_segmentId{ SafeString(model.segmentId) },
        m_titlePlayerAccountTestIds{ model.titlePlayerAccountTestIds, model.titlePlayerAccountTestIds + model.titlePlayerAccountTestIdsCount },
        m_variants{ model.variants, model.variants + model.variantsCount }
    {
        SetModelPointers();
    }

    PFExperimentationCreateExperimentRequestWrapper(const PFExperimentationCreateExperimentRequestWrapper& src) :
        PFExperimentationCreateExperimentRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationCreateExperimentRequestWrapper(PFExperimentationCreateExperimentRequestWrapper&& src) :
        PFExperimentationCreateExperimentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationCreateExperimentRequestWrapper& operator=(PFExperimentationCreateExperimentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationCreateExperimentRequestWrapper() = default;

    friend void swap(PFExperimentationCreateExperimentRequestWrapper& lhs, PFExperimentationCreateExperimentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_endDate, rhs.m_endDate);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        swap(lhs.m_exclusionGroupTrafficAllocation, rhs.m_exclusionGroupTrafficAllocation);
        swap(lhs.m_experimentType, rhs.m_experimentType);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        swap(lhs.m_titlePlayerAccountTestIds, rhs.m_titlePlayerAccountTestIds);
        swap(lhs.m_variants, rhs.m_variants);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetEndDate(StdExtra::optional<time_t> value)
    {
        m_endDate = std::move(value);
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    void SetExclusionGroupTrafficAllocation(StdExtra::optional<uint32_t> value)
    {
        m_exclusionGroupTrafficAllocation = std::move(value);
        this->m_model.exclusionGroupTrafficAllocation = m_exclusionGroupTrafficAllocation ? m_exclusionGroupTrafficAllocation.operator->() : nullptr;
    }

    void SetExperimentType(StdExtra::optional<PFExperimentationExperimentType> value)
    {
        m_experimentType = std::move(value);
        this->m_model.experimentType = m_experimentType ? m_experimentType.operator->() : nullptr;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    void SetStartDate(time_t value)
    {
        this->m_model.startDate = value;
    }

    void SetTitlePlayerAccountTestIds(CStringVector<Alloc> value)
    {
        m_titlePlayerAccountTestIds = std::move(value);
        this->m_model.titlePlayerAccountTestIds =  m_titlePlayerAccountTestIds.empty() ? nullptr : m_titlePlayerAccountTestIds.data();
        this->m_model.titlePlayerAccountTestIdsCount =  static_cast<uint32_t>(m_titlePlayerAccountTestIds.size());
    }

    void SetVariants(ModelVector<PFExperimentationVariantWrapper<Alloc>, Alloc> value)
    {
        m_variants = std::move(value);
        this->m_model.variants =  m_variants.empty() ? nullptr : m_variants.data();
        this->m_model.variantsCount =  static_cast<uint32_t>(m_variants.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
        this->m_model.exclusionGroupTrafficAllocation = m_exclusionGroupTrafficAllocation ? m_exclusionGroupTrafficAllocation.operator->() : nullptr;
        this->m_model.experimentType = m_experimentType ? m_experimentType.operator->() : nullptr;
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
        this->m_model.titlePlayerAccountTestIds = m_titlePlayerAccountTestIds.empty() ? nullptr : m_titlePlayerAccountTestIds.data();
        this->m_model.variants = m_variants.empty() ? nullptr : m_variants.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    StdExtra::optional<time_t> m_endDate;
    String m_exclusionGroupId;
    StdExtra::optional<uint32_t> m_exclusionGroupTrafficAllocation;
    StdExtra::optional<PFExperimentationExperimentType> m_experimentType;
    String m_name;
    String m_segmentId;
    CStringVector<Alloc> m_titlePlayerAccountTestIds;
    ModelVector<PFExperimentationVariantWrapper<Alloc>, Alloc> m_variants;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationCreateExperimentResultWrapper : public ModelWrapper<PFExperimentationCreateExperimentResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationCreateExperimentResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationCreateExperimentResultWrapper() = default;

    PFExperimentationCreateExperimentResultWrapper(const PFExperimentationCreateExperimentResult& model) :
        ModelWrapper<PFExperimentationCreateExperimentResult, Alloc>{ model },
        m_experimentId{ SafeString(model.experimentId) }
    {
        SetModelPointers();
    }

    PFExperimentationCreateExperimentResultWrapper(const PFExperimentationCreateExperimentResultWrapper& src) :
        PFExperimentationCreateExperimentResultWrapper{ src.Model() }
    {
    }

    PFExperimentationCreateExperimentResultWrapper(PFExperimentationCreateExperimentResultWrapper&& src) :
        PFExperimentationCreateExperimentResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationCreateExperimentResultWrapper& operator=(PFExperimentationCreateExperimentResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationCreateExperimentResultWrapper() = default;

    friend void swap(PFExperimentationCreateExperimentResultWrapper& lhs, PFExperimentationCreateExperimentResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    String m_experimentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationDeleteExclusionGroupRequestWrapper : public ModelWrapper<PFExperimentationDeleteExclusionGroupRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationDeleteExclusionGroupRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationDeleteExclusionGroupRequestWrapper() = default;

    PFExperimentationDeleteExclusionGroupRequestWrapper(const PFExperimentationDeleteExclusionGroupRequest& model) :
        ModelWrapper<PFExperimentationDeleteExclusionGroupRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) }
    {
        SetModelPointers();
    }

    PFExperimentationDeleteExclusionGroupRequestWrapper(const PFExperimentationDeleteExclusionGroupRequestWrapper& src) :
        PFExperimentationDeleteExclusionGroupRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationDeleteExclusionGroupRequestWrapper(PFExperimentationDeleteExclusionGroupRequestWrapper&& src) :
        PFExperimentationDeleteExclusionGroupRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationDeleteExclusionGroupRequestWrapper& operator=(PFExperimentationDeleteExclusionGroupRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationDeleteExclusionGroupRequestWrapper() = default;

    friend void swap(PFExperimentationDeleteExclusionGroupRequestWrapper& lhs, PFExperimentationDeleteExclusionGroupRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_exclusionGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationDeleteExperimentRequestWrapper : public ModelWrapper<PFExperimentationDeleteExperimentRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationDeleteExperimentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationDeleteExperimentRequestWrapper() = default;

    PFExperimentationDeleteExperimentRequestWrapper(const PFExperimentationDeleteExperimentRequest& model) :
        ModelWrapper<PFExperimentationDeleteExperimentRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_experimentId{ SafeString(model.experimentId) }
    {
        SetModelPointers();
    }

    PFExperimentationDeleteExperimentRequestWrapper(const PFExperimentationDeleteExperimentRequestWrapper& src) :
        PFExperimentationDeleteExperimentRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationDeleteExperimentRequestWrapper(PFExperimentationDeleteExperimentRequestWrapper&& src) :
        PFExperimentationDeleteExperimentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationDeleteExperimentRequestWrapper& operator=(PFExperimentationDeleteExperimentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationDeleteExperimentRequestWrapper() = default;

    friend void swap(PFExperimentationDeleteExperimentRequestWrapper& lhs, PFExperimentationDeleteExperimentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_experimentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetExclusionGroupsRequestWrapper : public ModelWrapper<PFExperimentationGetExclusionGroupsRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetExclusionGroupsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetExclusionGroupsRequestWrapper() = default;

    PFExperimentationGetExclusionGroupsRequestWrapper(const PFExperimentationGetExclusionGroupsRequest& model) :
        ModelWrapper<PFExperimentationGetExclusionGroupsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFExperimentationGetExclusionGroupsRequestWrapper(const PFExperimentationGetExclusionGroupsRequestWrapper& src) :
        PFExperimentationGetExclusionGroupsRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationGetExclusionGroupsRequestWrapper(PFExperimentationGetExclusionGroupsRequestWrapper&& src) :
        PFExperimentationGetExclusionGroupsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetExclusionGroupsRequestWrapper& operator=(PFExperimentationGetExclusionGroupsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetExclusionGroupsRequestWrapper() = default;

    friend void swap(PFExperimentationGetExclusionGroupsRequestWrapper& lhs, PFExperimentationGetExclusionGroupsRequestWrapper& rhs)
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
class PFExperimentationExperimentExclusionGroupWrapper : public ModelWrapper<PFExperimentationExperimentExclusionGroup, Alloc>
{
public:
    using ModelType = typename PFExperimentationExperimentExclusionGroup;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationExperimentExclusionGroupWrapper() = default;

    PFExperimentationExperimentExclusionGroupWrapper(const PFExperimentationExperimentExclusionGroup& model) :
        ModelWrapper<PFExperimentationExperimentExclusionGroup, Alloc>{ model },
        m_description{ SafeString(model.description) },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFExperimentationExperimentExclusionGroupWrapper(const PFExperimentationExperimentExclusionGroupWrapper& src) :
        PFExperimentationExperimentExclusionGroupWrapper{ src.Model() }
    {
    }

    PFExperimentationExperimentExclusionGroupWrapper(PFExperimentationExperimentExclusionGroupWrapper&& src) :
        PFExperimentationExperimentExclusionGroupWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationExperimentExclusionGroupWrapper& operator=(PFExperimentationExperimentExclusionGroupWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationExperimentExclusionGroupWrapper() = default;

    friend void swap(PFExperimentationExperimentExclusionGroupWrapper& lhs, PFExperimentationExperimentExclusionGroupWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_description;
    String m_exclusionGroupId;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetExclusionGroupsResultWrapper : public ModelWrapper<PFExperimentationGetExclusionGroupsResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetExclusionGroupsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetExclusionGroupsResultWrapper() = default;

    PFExperimentationGetExclusionGroupsResultWrapper(const PFExperimentationGetExclusionGroupsResult& model) :
        ModelWrapper<PFExperimentationGetExclusionGroupsResult, Alloc>{ model },
        m_exclusionGroups{ model.exclusionGroups, model.exclusionGroups + model.exclusionGroupsCount }
    {
        SetModelPointers();
    }

    PFExperimentationGetExclusionGroupsResultWrapper(const PFExperimentationGetExclusionGroupsResultWrapper& src) :
        PFExperimentationGetExclusionGroupsResultWrapper{ src.Model() }
    {
    }

    PFExperimentationGetExclusionGroupsResultWrapper(PFExperimentationGetExclusionGroupsResultWrapper&& src) :
        PFExperimentationGetExclusionGroupsResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetExclusionGroupsResultWrapper& operator=(PFExperimentationGetExclusionGroupsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetExclusionGroupsResultWrapper() = default;

    friend void swap(PFExperimentationGetExclusionGroupsResultWrapper& lhs, PFExperimentationGetExclusionGroupsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_exclusionGroups, rhs.m_exclusionGroups);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExclusionGroups(ModelVector<PFExperimentationExperimentExclusionGroupWrapper<Alloc>, Alloc> value)
    {
        m_exclusionGroups = std::move(value);
        this->m_model.exclusionGroups =  m_exclusionGroups.empty() ? nullptr : m_exclusionGroups.data();
        this->m_model.exclusionGroupsCount =  static_cast<uint32_t>(m_exclusionGroups.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.exclusionGroups = m_exclusionGroups.empty() ? nullptr : m_exclusionGroups.data();
    }

    ModelVector<PFExperimentationExperimentExclusionGroupWrapper<Alloc>, Alloc> m_exclusionGroups;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetExclusionGroupTrafficRequestWrapper : public ModelWrapper<PFExperimentationGetExclusionGroupTrafficRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetExclusionGroupTrafficRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetExclusionGroupTrafficRequestWrapper() = default;

    PFExperimentationGetExclusionGroupTrafficRequestWrapper(const PFExperimentationGetExclusionGroupTrafficRequest& model) :
        ModelWrapper<PFExperimentationGetExclusionGroupTrafficRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) }
    {
        SetModelPointers();
    }

    PFExperimentationGetExclusionGroupTrafficRequestWrapper(const PFExperimentationGetExclusionGroupTrafficRequestWrapper& src) :
        PFExperimentationGetExclusionGroupTrafficRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationGetExclusionGroupTrafficRequestWrapper(PFExperimentationGetExclusionGroupTrafficRequestWrapper&& src) :
        PFExperimentationGetExclusionGroupTrafficRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetExclusionGroupTrafficRequestWrapper& operator=(PFExperimentationGetExclusionGroupTrafficRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetExclusionGroupTrafficRequestWrapper() = default;

    friend void swap(PFExperimentationGetExclusionGroupTrafficRequestWrapper& lhs, PFExperimentationGetExclusionGroupTrafficRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_exclusionGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationExclusionGroupTrafficAllocationWrapper : public ModelWrapper<PFExperimentationExclusionGroupTrafficAllocation, Alloc>
{
public:
    using ModelType = typename PFExperimentationExclusionGroupTrafficAllocation;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationExclusionGroupTrafficAllocationWrapper() = default;

    PFExperimentationExclusionGroupTrafficAllocationWrapper(const PFExperimentationExclusionGroupTrafficAllocation& model) :
        ModelWrapper<PFExperimentationExclusionGroupTrafficAllocation, Alloc>{ model },
        m_experimentId{ SafeString(model.experimentId) }
    {
        SetModelPointers();
    }

    PFExperimentationExclusionGroupTrafficAllocationWrapper(const PFExperimentationExclusionGroupTrafficAllocationWrapper& src) :
        PFExperimentationExclusionGroupTrafficAllocationWrapper{ src.Model() }
    {
    }

    PFExperimentationExclusionGroupTrafficAllocationWrapper(PFExperimentationExclusionGroupTrafficAllocationWrapper&& src) :
        PFExperimentationExclusionGroupTrafficAllocationWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationExclusionGroupTrafficAllocationWrapper& operator=(PFExperimentationExclusionGroupTrafficAllocationWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationExclusionGroupTrafficAllocationWrapper() = default;

    friend void swap(PFExperimentationExclusionGroupTrafficAllocationWrapper& lhs, PFExperimentationExclusionGroupTrafficAllocationWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    void SetTrafficAllocation(uint32_t value)
    {
        this->m_model.trafficAllocation = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    String m_experimentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetExclusionGroupTrafficResultWrapper : public ModelWrapper<PFExperimentationGetExclusionGroupTrafficResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetExclusionGroupTrafficResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetExclusionGroupTrafficResultWrapper() = default;

    PFExperimentationGetExclusionGroupTrafficResultWrapper(const PFExperimentationGetExclusionGroupTrafficResult& model) :
        ModelWrapper<PFExperimentationGetExclusionGroupTrafficResult, Alloc>{ model },
        m_trafficAllocations{ model.trafficAllocations, model.trafficAllocations + model.trafficAllocationsCount }
    {
        SetModelPointers();
    }

    PFExperimentationGetExclusionGroupTrafficResultWrapper(const PFExperimentationGetExclusionGroupTrafficResultWrapper& src) :
        PFExperimentationGetExclusionGroupTrafficResultWrapper{ src.Model() }
    {
    }

    PFExperimentationGetExclusionGroupTrafficResultWrapper(PFExperimentationGetExclusionGroupTrafficResultWrapper&& src) :
        PFExperimentationGetExclusionGroupTrafficResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetExclusionGroupTrafficResultWrapper& operator=(PFExperimentationGetExclusionGroupTrafficResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetExclusionGroupTrafficResultWrapper() = default;

    friend void swap(PFExperimentationGetExclusionGroupTrafficResultWrapper& lhs, PFExperimentationGetExclusionGroupTrafficResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_trafficAllocations, rhs.m_trafficAllocations);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTrafficAllocations(ModelVector<PFExperimentationExclusionGroupTrafficAllocationWrapper<Alloc>, Alloc> value)
    {
        m_trafficAllocations = std::move(value);
        this->m_model.trafficAllocations =  m_trafficAllocations.empty() ? nullptr : m_trafficAllocations.data();
        this->m_model.trafficAllocationsCount =  static_cast<uint32_t>(m_trafficAllocations.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.trafficAllocations = m_trafficAllocations.empty() ? nullptr : m_trafficAllocations.data();
    }

    ModelVector<PFExperimentationExclusionGroupTrafficAllocationWrapper<Alloc>, Alloc> m_trafficAllocations;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetExperimentsRequestWrapper : public ModelWrapper<PFExperimentationGetExperimentsRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetExperimentsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetExperimentsRequestWrapper() = default;

    PFExperimentationGetExperimentsRequestWrapper(const PFExperimentationGetExperimentsRequest& model) :
        ModelWrapper<PFExperimentationGetExperimentsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFExperimentationGetExperimentsRequestWrapper(const PFExperimentationGetExperimentsRequestWrapper& src) :
        PFExperimentationGetExperimentsRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationGetExperimentsRequestWrapper(PFExperimentationGetExperimentsRequestWrapper&& src) :
        PFExperimentationGetExperimentsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetExperimentsRequestWrapper& operator=(PFExperimentationGetExperimentsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetExperimentsRequestWrapper() = default;

    friend void swap(PFExperimentationGetExperimentsRequestWrapper& lhs, PFExperimentationGetExperimentsRequestWrapper& rhs)
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
class PFExperimentationExperimentWrapper : public ModelWrapper<PFExperimentationExperiment, Alloc>
{
public:
    using ModelType = typename PFExperimentationExperiment;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationExperimentWrapper() = default;

    PFExperimentationExperimentWrapper(const PFExperimentationExperiment& model) :
        ModelWrapper<PFExperimentationExperiment, Alloc>{ model },
        m_description{ SafeString(model.description) },
        m_endDate{ model.endDate ? StdExtra::optional<time_t>{ *model.endDate } : StdExtra::nullopt },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) },
        m_exclusionGroupTrafficAllocation{ model.exclusionGroupTrafficAllocation ? StdExtra::optional<uint32_t>{ *model.exclusionGroupTrafficAllocation } : StdExtra::nullopt },
        m_experimentType{ model.experimentType ? StdExtra::optional<PFExperimentationExperimentType>{ *model.experimentType } : StdExtra::nullopt },
        m_id{ SafeString(model.id) },
        m_name{ SafeString(model.name) },
        m_segmentId{ SafeString(model.segmentId) },
        m_state{ model.state ? StdExtra::optional<PFExperimentationExperimentState>{ *model.state } : StdExtra::nullopt },
        m_titlePlayerAccountTestIds{ model.titlePlayerAccountTestIds, model.titlePlayerAccountTestIds + model.titlePlayerAccountTestIdsCount },
        m_variants{ model.variants, model.variants + model.variantsCount }
    {
        SetModelPointers();
    }

    PFExperimentationExperimentWrapper(const PFExperimentationExperimentWrapper& src) :
        PFExperimentationExperimentWrapper{ src.Model() }
    {
    }

    PFExperimentationExperimentWrapper(PFExperimentationExperimentWrapper&& src) :
        PFExperimentationExperimentWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationExperimentWrapper& operator=(PFExperimentationExperimentWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationExperimentWrapper() = default;

    friend void swap(PFExperimentationExperimentWrapper& lhs, PFExperimentationExperimentWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_endDate, rhs.m_endDate);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        swap(lhs.m_exclusionGroupTrafficAllocation, rhs.m_exclusionGroupTrafficAllocation);
        swap(lhs.m_experimentType, rhs.m_experimentType);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        swap(lhs.m_state, rhs.m_state);
        swap(lhs.m_titlePlayerAccountTestIds, rhs.m_titlePlayerAccountTestIds);
        swap(lhs.m_variants, rhs.m_variants);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetEndDate(StdExtra::optional<time_t> value)
    {
        m_endDate = std::move(value);
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    void SetExclusionGroupTrafficAllocation(StdExtra::optional<uint32_t> value)
    {
        m_exclusionGroupTrafficAllocation = std::move(value);
        this->m_model.exclusionGroupTrafficAllocation = m_exclusionGroupTrafficAllocation ? m_exclusionGroupTrafficAllocation.operator->() : nullptr;
    }

    void SetExperimentType(StdExtra::optional<PFExperimentationExperimentType> value)
    {
        m_experimentType = std::move(value);
        this->m_model.experimentType = m_experimentType ? m_experimentType.operator->() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    void SetStartDate(time_t value)
    {
        this->m_model.startDate = value;
    }

    void SetState(StdExtra::optional<PFExperimentationExperimentState> value)
    {
        m_state = std::move(value);
        this->m_model.state = m_state ? m_state.operator->() : nullptr;
    }

    void SetTitlePlayerAccountTestIds(CStringVector<Alloc> value)
    {
        m_titlePlayerAccountTestIds = std::move(value);
        this->m_model.titlePlayerAccountTestIds =  m_titlePlayerAccountTestIds.empty() ? nullptr : m_titlePlayerAccountTestIds.data();
        this->m_model.titlePlayerAccountTestIdsCount =  static_cast<uint32_t>(m_titlePlayerAccountTestIds.size());
    }

    void SetVariants(ModelVector<PFExperimentationVariantWrapper<Alloc>, Alloc> value)
    {
        m_variants = std::move(value);
        this->m_model.variants =  m_variants.empty() ? nullptr : m_variants.data();
        this->m_model.variantsCount =  static_cast<uint32_t>(m_variants.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
        this->m_model.exclusionGroupTrafficAllocation = m_exclusionGroupTrafficAllocation ? m_exclusionGroupTrafficAllocation.operator->() : nullptr;
        this->m_model.experimentType = m_experimentType ? m_experimentType.operator->() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
        this->m_model.state = m_state ? m_state.operator->() : nullptr;
        this->m_model.titlePlayerAccountTestIds = m_titlePlayerAccountTestIds.empty() ? nullptr : m_titlePlayerAccountTestIds.data();
        this->m_model.variants = m_variants.empty() ? nullptr : m_variants.data();
    }

    String m_description;
    StdExtra::optional<time_t> m_endDate;
    String m_exclusionGroupId;
    StdExtra::optional<uint32_t> m_exclusionGroupTrafficAllocation;
    StdExtra::optional<PFExperimentationExperimentType> m_experimentType;
    String m_id;
    String m_name;
    String m_segmentId;
    StdExtra::optional<PFExperimentationExperimentState> m_state;
    CStringVector<Alloc> m_titlePlayerAccountTestIds;
    ModelVector<PFExperimentationVariantWrapper<Alloc>, Alloc> m_variants;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetExperimentsResultWrapper : public ModelWrapper<PFExperimentationGetExperimentsResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetExperimentsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetExperimentsResultWrapper() = default;

    PFExperimentationGetExperimentsResultWrapper(const PFExperimentationGetExperimentsResult& model) :
        ModelWrapper<PFExperimentationGetExperimentsResult, Alloc>{ model },
        m_experiments{ model.experiments, model.experiments + model.experimentsCount }
    {
        SetModelPointers();
    }

    PFExperimentationGetExperimentsResultWrapper(const PFExperimentationGetExperimentsResultWrapper& src) :
        PFExperimentationGetExperimentsResultWrapper{ src.Model() }
    {
    }

    PFExperimentationGetExperimentsResultWrapper(PFExperimentationGetExperimentsResultWrapper&& src) :
        PFExperimentationGetExperimentsResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetExperimentsResultWrapper& operator=(PFExperimentationGetExperimentsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetExperimentsResultWrapper() = default;

    friend void swap(PFExperimentationGetExperimentsResultWrapper& lhs, PFExperimentationGetExperimentsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_experiments, rhs.m_experiments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetExperiments(ModelVector<PFExperimentationExperimentWrapper<Alloc>, Alloc> value)
    {
        m_experiments = std::move(value);
        this->m_model.experiments =  m_experiments.empty() ? nullptr : m_experiments.data();
        this->m_model.experimentsCount =  static_cast<uint32_t>(m_experiments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.experiments = m_experiments.empty() ? nullptr : m_experiments.data();
    }

    ModelVector<PFExperimentationExperimentWrapper<Alloc>, Alloc> m_experiments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetLatestScorecardRequestWrapper : public ModelWrapper<PFExperimentationGetLatestScorecardRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetLatestScorecardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetLatestScorecardRequestWrapper() = default;

    PFExperimentationGetLatestScorecardRequestWrapper(const PFExperimentationGetLatestScorecardRequest& model) :
        ModelWrapper<PFExperimentationGetLatestScorecardRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_experimentId{ SafeString(model.experimentId) }
    {
        SetModelPointers();
    }

    PFExperimentationGetLatestScorecardRequestWrapper(const PFExperimentationGetLatestScorecardRequestWrapper& src) :
        PFExperimentationGetLatestScorecardRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationGetLatestScorecardRequestWrapper(PFExperimentationGetLatestScorecardRequestWrapper&& src) :
        PFExperimentationGetLatestScorecardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetLatestScorecardRequestWrapper& operator=(PFExperimentationGetLatestScorecardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetLatestScorecardRequestWrapper() = default;

    friend void swap(PFExperimentationGetLatestScorecardRequestWrapper& lhs, PFExperimentationGetLatestScorecardRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_experimentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationMetricDataWrapper : public ModelWrapper<PFExperimentationMetricData, Alloc>
{
public:
    using ModelType = typename PFExperimentationMetricData;
    using DictionaryEntryType = typename PFExperimentationMetricDataDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationMetricDataWrapper() = default;

    PFExperimentationMetricDataWrapper(const PFExperimentationMetricData& model) :
        ModelWrapper<PFExperimentationMetricData, Alloc>{ model },
        m_internalName{ SafeString(model.internalName) },
        m_movement{ SafeString(model.movement) },
        m_name{ SafeString(model.name) },
        m_statSigLevel{ SafeString(model.statSigLevel) }
    {
        SetModelPointers();
    }

    PFExperimentationMetricDataWrapper(const PFExperimentationMetricDataWrapper& src) :
        PFExperimentationMetricDataWrapper{ src.Model() }
    {
    }

    PFExperimentationMetricDataWrapper(PFExperimentationMetricDataWrapper&& src) :
        PFExperimentationMetricDataWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationMetricDataWrapper& operator=(PFExperimentationMetricDataWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationMetricDataWrapper() = default;

    friend void swap(PFExperimentationMetricDataWrapper& lhs, PFExperimentationMetricDataWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_internalName, rhs.m_internalName);
        swap(lhs.m_movement, rhs.m_movement);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_statSigLevel, rhs.m_statSigLevel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConfidenceIntervalEnd(double value)
    {
        this->m_model.confidenceIntervalEnd = value;
    }

    void SetConfidenceIntervalStart(double value)
    {
        this->m_model.confidenceIntervalStart = value;
    }

    void SetDeltaAbsoluteChange(float value)
    {
        this->m_model.deltaAbsoluteChange = value;
    }

    void SetDeltaRelativeChange(float value)
    {
        this->m_model.deltaRelativeChange = value;
    }

    void SetInternalName(String value)
    {
        m_internalName = std::move(value);
        this->m_model.internalName =  m_internalName.empty() ? nullptr : m_internalName.data();
    }

    void SetMovement(String value)
    {
        m_movement = std::move(value);
        this->m_model.movement =  m_movement.empty() ? nullptr : m_movement.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetPMove(float value)
    {
        this->m_model.pMove = value;
    }

    void SetPValue(float value)
    {
        this->m_model.pValue = value;
    }

    void SetPValueThreshold(float value)
    {
        this->m_model.pValueThreshold = value;
    }

    void SetStatSigLevel(String value)
    {
        m_statSigLevel = std::move(value);
        this->m_model.statSigLevel =  m_statSigLevel.empty() ? nullptr : m_statSigLevel.data();
    }

    void SetStdDev(float value)
    {
        this->m_model.stdDev = value;
    }

    void SetValue(float value)
    {
        this->m_model.value = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.internalName = m_internalName.empty() ? nullptr : m_internalName.data();
        this->m_model.movement = m_movement.empty() ? nullptr : m_movement.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.statSigLevel = m_statSigLevel.empty() ? nullptr : m_statSigLevel.data();
    }

    String m_internalName;
    String m_movement;
    String m_name;
    String m_statSigLevel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationScorecardDataRowWrapper : public ModelWrapper<PFExperimentationScorecardDataRow, Alloc>
{
public:
    using ModelType = typename PFExperimentationScorecardDataRow;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationScorecardDataRowWrapper() = default;

    PFExperimentationScorecardDataRowWrapper(const PFExperimentationScorecardDataRow& model) :
        ModelWrapper<PFExperimentationScorecardDataRow, Alloc>{ model },
        m_metricDataRows{ model.metricDataRows, model.metricDataRows + model.metricDataRowsCount },
        m_variantName{ SafeString(model.variantName) }
    {
        SetModelPointers();
    }

    PFExperimentationScorecardDataRowWrapper(const PFExperimentationScorecardDataRowWrapper& src) :
        PFExperimentationScorecardDataRowWrapper{ src.Model() }
    {
    }

    PFExperimentationScorecardDataRowWrapper(PFExperimentationScorecardDataRowWrapper&& src) :
        PFExperimentationScorecardDataRowWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationScorecardDataRowWrapper& operator=(PFExperimentationScorecardDataRowWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationScorecardDataRowWrapper() = default;

    friend void swap(PFExperimentationScorecardDataRowWrapper& lhs, PFExperimentationScorecardDataRowWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_metricDataRows, rhs.m_metricDataRows);
        swap(lhs.m_variantName, rhs.m_variantName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIsControl(bool value)
    {
        this->m_model.isControl = value;
    }

    void SetMetricDataRows(ModelDictionaryEntryVector<PFExperimentationMetricDataWrapper<Alloc>, Alloc> value)
    {
        m_metricDataRows = std::move(value);
        this->m_model.metricDataRows =  m_metricDataRows.empty() ? nullptr : m_metricDataRows.data();
        this->m_model.metricDataRowsCount =  static_cast<uint32_t>(m_metricDataRows.size());
    }

    void SetPlayerCount(uint32_t value)
    {
        this->m_model.playerCount = value;
    }

    void SetVariantName(String value)
    {
        m_variantName = std::move(value);
        this->m_model.variantName =  m_variantName.empty() ? nullptr : m_variantName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.metricDataRows = m_metricDataRows.empty() ? nullptr : m_metricDataRows.data();
        this->m_model.variantName = m_variantName.empty() ? nullptr : m_variantName.data();
    }

    ModelDictionaryEntryVector<PFExperimentationMetricDataWrapper<Alloc>, Alloc> m_metricDataRows;
    String m_variantName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationScorecardWrapper : public ModelWrapper<PFExperimentationScorecard, Alloc>
{
public:
    using ModelType = typename PFExperimentationScorecard;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationScorecardWrapper() = default;

    PFExperimentationScorecardWrapper(const PFExperimentationScorecard& model) :
        ModelWrapper<PFExperimentationScorecard, Alloc>{ model },
        m_dateGenerated{ SafeString(model.dateGenerated) },
        m_duration{ SafeString(model.duration) },
        m_experimentId{ SafeString(model.experimentId) },
        m_experimentName{ SafeString(model.experimentName) },
        m_latestJobStatus{ model.latestJobStatus ? StdExtra::optional<PFExperimentationAnalysisTaskState>{ *model.latestJobStatus } : StdExtra::nullopt },
        m_scorecardDataRows{ model.scorecardDataRows, model.scorecardDataRows + model.scorecardDataRowsCount }
    {
        SetModelPointers();
    }

    PFExperimentationScorecardWrapper(const PFExperimentationScorecardWrapper& src) :
        PFExperimentationScorecardWrapper{ src.Model() }
    {
    }

    PFExperimentationScorecardWrapper(PFExperimentationScorecardWrapper&& src) :
        PFExperimentationScorecardWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationScorecardWrapper& operator=(PFExperimentationScorecardWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationScorecardWrapper() = default;

    friend void swap(PFExperimentationScorecardWrapper& lhs, PFExperimentationScorecardWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dateGenerated, rhs.m_dateGenerated);
        swap(lhs.m_duration, rhs.m_duration);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        swap(lhs.m_experimentName, rhs.m_experimentName);
        swap(lhs.m_latestJobStatus, rhs.m_latestJobStatus);
        swap(lhs.m_scorecardDataRows, rhs.m_scorecardDataRows);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDateGenerated(String value)
    {
        m_dateGenerated = std::move(value);
        this->m_model.dateGenerated =  m_dateGenerated.empty() ? nullptr : m_dateGenerated.data();
    }

    void SetDuration(String value)
    {
        m_duration = std::move(value);
        this->m_model.duration =  m_duration.empty() ? nullptr : m_duration.data();
    }

    void SetEventsProcessed(double value)
    {
        this->m_model.eventsProcessed = value;
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    void SetExperimentName(String value)
    {
        m_experimentName = std::move(value);
        this->m_model.experimentName =  m_experimentName.empty() ? nullptr : m_experimentName.data();
    }

    void SetLatestJobStatus(StdExtra::optional<PFExperimentationAnalysisTaskState> value)
    {
        m_latestJobStatus = std::move(value);
        this->m_model.latestJobStatus = m_latestJobStatus ? m_latestJobStatus.operator->() : nullptr;
    }

    void SetSampleRatioMismatch(bool value)
    {
        this->m_model.sampleRatioMismatch = value;
    }

    void SetScorecardDataRows(ModelVector<PFExperimentationScorecardDataRowWrapper<Alloc>, Alloc> value)
    {
        m_scorecardDataRows = std::move(value);
        this->m_model.scorecardDataRows =  m_scorecardDataRows.empty() ? nullptr : m_scorecardDataRows.data();
        this->m_model.scorecardDataRowsCount =  static_cast<uint32_t>(m_scorecardDataRows.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.dateGenerated = m_dateGenerated.empty() ? nullptr : m_dateGenerated.data();
        this->m_model.duration = m_duration.empty() ? nullptr : m_duration.data();
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
        this->m_model.experimentName = m_experimentName.empty() ? nullptr : m_experimentName.data();
        this->m_model.latestJobStatus = m_latestJobStatus ? m_latestJobStatus.operator->() : nullptr;
        this->m_model.scorecardDataRows = m_scorecardDataRows.empty() ? nullptr : m_scorecardDataRows.data();
    }

    String m_dateGenerated;
    String m_duration;
    String m_experimentId;
    String m_experimentName;
    StdExtra::optional<PFExperimentationAnalysisTaskState> m_latestJobStatus;
    ModelVector<PFExperimentationScorecardDataRowWrapper<Alloc>, Alloc> m_scorecardDataRows;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetLatestScorecardResultWrapper : public ModelWrapper<PFExperimentationGetLatestScorecardResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetLatestScorecardResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetLatestScorecardResultWrapper() = default;

    PFExperimentationGetLatestScorecardResultWrapper(const PFExperimentationGetLatestScorecardResult& model) :
        ModelWrapper<PFExperimentationGetLatestScorecardResult, Alloc>{ model },
        m_scorecard{ model.scorecard ? StdExtra::optional<PFExperimentationScorecardWrapper<Alloc>>{ *model.scorecard } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFExperimentationGetLatestScorecardResultWrapper(const PFExperimentationGetLatestScorecardResultWrapper& src) :
        PFExperimentationGetLatestScorecardResultWrapper{ src.Model() }
    {
    }

    PFExperimentationGetLatestScorecardResultWrapper(PFExperimentationGetLatestScorecardResultWrapper&& src) :
        PFExperimentationGetLatestScorecardResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetLatestScorecardResultWrapper& operator=(PFExperimentationGetLatestScorecardResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetLatestScorecardResultWrapper() = default;

    friend void swap(PFExperimentationGetLatestScorecardResultWrapper& lhs, PFExperimentationGetLatestScorecardResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_scorecard, rhs.m_scorecard);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetScorecard(StdExtra::optional<PFExperimentationScorecardWrapper<Alloc>> value)
    {
        m_scorecard = std::move(value);
        this->m_model.scorecard = m_scorecard ? &m_scorecard->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.scorecard = m_scorecard ?  &m_scorecard->Model() : nullptr;
    }

    StdExtra::optional<PFExperimentationScorecardWrapper<Alloc>> m_scorecard;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetTreatmentAssignmentRequestWrapper : public ModelWrapper<PFExperimentationGetTreatmentAssignmentRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetTreatmentAssignmentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetTreatmentAssignmentRequestWrapper() = default;

    PFExperimentationGetTreatmentAssignmentRequestWrapper(const PFExperimentationGetTreatmentAssignmentRequest& model) :
        ModelWrapper<PFExperimentationGetTreatmentAssignmentRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFExperimentationGetTreatmentAssignmentRequestWrapper(const PFExperimentationGetTreatmentAssignmentRequestWrapper& src) :
        PFExperimentationGetTreatmentAssignmentRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationGetTreatmentAssignmentRequestWrapper(PFExperimentationGetTreatmentAssignmentRequestWrapper&& src) :
        PFExperimentationGetTreatmentAssignmentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetTreatmentAssignmentRequestWrapper& operator=(PFExperimentationGetTreatmentAssignmentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetTreatmentAssignmentRequestWrapper() = default;

    friend void swap(PFExperimentationGetTreatmentAssignmentRequestWrapper& lhs, PFExperimentationGetTreatmentAssignmentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationGetTreatmentAssignmentResultWrapper : public ModelWrapper<PFExperimentationGetTreatmentAssignmentResult, Alloc>
{
public:
    using ModelType = typename PFExperimentationGetTreatmentAssignmentResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationGetTreatmentAssignmentResultWrapper() = default;

    PFExperimentationGetTreatmentAssignmentResultWrapper(const PFExperimentationGetTreatmentAssignmentResult& model) :
        ModelWrapper<PFExperimentationGetTreatmentAssignmentResult, Alloc>{ model },
        m_treatmentAssignment{ model.treatmentAssignment ? StdExtra::optional<PFTreatmentAssignmentWrapper<Alloc>>{ *model.treatmentAssignment } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFExperimentationGetTreatmentAssignmentResultWrapper(const PFExperimentationGetTreatmentAssignmentResultWrapper& src) :
        PFExperimentationGetTreatmentAssignmentResultWrapper{ src.Model() }
    {
    }

    PFExperimentationGetTreatmentAssignmentResultWrapper(PFExperimentationGetTreatmentAssignmentResultWrapper&& src) :
        PFExperimentationGetTreatmentAssignmentResultWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationGetTreatmentAssignmentResultWrapper& operator=(PFExperimentationGetTreatmentAssignmentResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationGetTreatmentAssignmentResultWrapper() = default;

    friend void swap(PFExperimentationGetTreatmentAssignmentResultWrapper& lhs, PFExperimentationGetTreatmentAssignmentResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_treatmentAssignment, rhs.m_treatmentAssignment);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTreatmentAssignment(StdExtra::optional<PFTreatmentAssignmentWrapper<Alloc>> value)
    {
        m_treatmentAssignment = std::move(value);
        this->m_model.treatmentAssignment = m_treatmentAssignment ? &m_treatmentAssignment->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.treatmentAssignment = m_treatmentAssignment ?  &m_treatmentAssignment->Model() : nullptr;
    }

    StdExtra::optional<PFTreatmentAssignmentWrapper<Alloc>> m_treatmentAssignment;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationStartExperimentRequestWrapper : public ModelWrapper<PFExperimentationStartExperimentRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationStartExperimentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationStartExperimentRequestWrapper() = default;

    PFExperimentationStartExperimentRequestWrapper(const PFExperimentationStartExperimentRequest& model) :
        ModelWrapper<PFExperimentationStartExperimentRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_experimentId{ SafeString(model.experimentId) }
    {
        SetModelPointers();
    }

    PFExperimentationStartExperimentRequestWrapper(const PFExperimentationStartExperimentRequestWrapper& src) :
        PFExperimentationStartExperimentRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationStartExperimentRequestWrapper(PFExperimentationStartExperimentRequestWrapper&& src) :
        PFExperimentationStartExperimentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationStartExperimentRequestWrapper& operator=(PFExperimentationStartExperimentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationStartExperimentRequestWrapper() = default;

    friend void swap(PFExperimentationStartExperimentRequestWrapper& lhs, PFExperimentationStartExperimentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_experimentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationStopExperimentRequestWrapper : public ModelWrapper<PFExperimentationStopExperimentRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationStopExperimentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationStopExperimentRequestWrapper() = default;

    PFExperimentationStopExperimentRequestWrapper(const PFExperimentationStopExperimentRequest& model) :
        ModelWrapper<PFExperimentationStopExperimentRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_experimentId{ SafeString(model.experimentId) }
    {
        SetModelPointers();
    }

    PFExperimentationStopExperimentRequestWrapper(const PFExperimentationStopExperimentRequestWrapper& src) :
        PFExperimentationStopExperimentRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationStopExperimentRequestWrapper(PFExperimentationStopExperimentRequestWrapper&& src) :
        PFExperimentationStopExperimentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationStopExperimentRequestWrapper& operator=(PFExperimentationStopExperimentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationStopExperimentRequestWrapper() = default;

    friend void swap(PFExperimentationStopExperimentRequestWrapper& lhs, PFExperimentationStopExperimentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_experimentId, rhs.m_experimentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExperimentId(String value)
    {
        m_experimentId = std::move(value);
        this->m_model.experimentId =  m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.experimentId = m_experimentId.empty() ? nullptr : m_experimentId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_experimentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationUpdateExclusionGroupRequestWrapper : public ModelWrapper<PFExperimentationUpdateExclusionGroupRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationUpdateExclusionGroupRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationUpdateExclusionGroupRequestWrapper() = default;

    PFExperimentationUpdateExclusionGroupRequestWrapper(const PFExperimentationUpdateExclusionGroupRequest& model) :
        ModelWrapper<PFExperimentationUpdateExclusionGroupRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFExperimentationUpdateExclusionGroupRequestWrapper(const PFExperimentationUpdateExclusionGroupRequestWrapper& src) :
        PFExperimentationUpdateExclusionGroupRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationUpdateExclusionGroupRequestWrapper(PFExperimentationUpdateExclusionGroupRequestWrapper&& src) :
        PFExperimentationUpdateExclusionGroupRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationUpdateExclusionGroupRequestWrapper& operator=(PFExperimentationUpdateExclusionGroupRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationUpdateExclusionGroupRequestWrapper() = default;

    friend void swap(PFExperimentationUpdateExclusionGroupRequestWrapper& lhs, PFExperimentationUpdateExclusionGroupRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
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

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
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
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    String m_exclusionGroupId;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFExperimentationUpdateExperimentRequestWrapper : public ModelWrapper<PFExperimentationUpdateExperimentRequest, Alloc>
{
public:
    using ModelType = typename PFExperimentationUpdateExperimentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFExperimentationUpdateExperimentRequestWrapper() = default;

    PFExperimentationUpdateExperimentRequestWrapper(const PFExperimentationUpdateExperimentRequest& model) :
        ModelWrapper<PFExperimentationUpdateExperimentRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_endDate{ model.endDate ? StdExtra::optional<time_t>{ *model.endDate } : StdExtra::nullopt },
        m_exclusionGroupId{ SafeString(model.exclusionGroupId) },
        m_exclusionGroupTrafficAllocation{ model.exclusionGroupTrafficAllocation ? StdExtra::optional<uint32_t>{ *model.exclusionGroupTrafficAllocation } : StdExtra::nullopt },
        m_experimentType{ model.experimentType ? StdExtra::optional<PFExperimentationExperimentType>{ *model.experimentType } : StdExtra::nullopt },
        m_id{ SafeString(model.id) },
        m_name{ SafeString(model.name) },
        m_segmentId{ SafeString(model.segmentId) },
        m_titlePlayerAccountTestIds{ model.titlePlayerAccountTestIds, model.titlePlayerAccountTestIds + model.titlePlayerAccountTestIdsCount },
        m_variants{ model.variants, model.variants + model.variantsCount }
    {
        SetModelPointers();
    }

    PFExperimentationUpdateExperimentRequestWrapper(const PFExperimentationUpdateExperimentRequestWrapper& src) :
        PFExperimentationUpdateExperimentRequestWrapper{ src.Model() }
    {
    }

    PFExperimentationUpdateExperimentRequestWrapper(PFExperimentationUpdateExperimentRequestWrapper&& src) :
        PFExperimentationUpdateExperimentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFExperimentationUpdateExperimentRequestWrapper& operator=(PFExperimentationUpdateExperimentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFExperimentationUpdateExperimentRequestWrapper() = default;

    friend void swap(PFExperimentationUpdateExperimentRequestWrapper& lhs, PFExperimentationUpdateExperimentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_endDate, rhs.m_endDate);
        swap(lhs.m_exclusionGroupId, rhs.m_exclusionGroupId);
        swap(lhs.m_exclusionGroupTrafficAllocation, rhs.m_exclusionGroupTrafficAllocation);
        swap(lhs.m_experimentType, rhs.m_experimentType);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        swap(lhs.m_titlePlayerAccountTestIds, rhs.m_titlePlayerAccountTestIds);
        swap(lhs.m_variants, rhs.m_variants);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetEndDate(StdExtra::optional<time_t> value)
    {
        m_endDate = std::move(value);
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
    }

    void SetExclusionGroupId(String value)
    {
        m_exclusionGroupId = std::move(value);
        this->m_model.exclusionGroupId =  m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
    }

    void SetExclusionGroupTrafficAllocation(StdExtra::optional<uint32_t> value)
    {
        m_exclusionGroupTrafficAllocation = std::move(value);
        this->m_model.exclusionGroupTrafficAllocation = m_exclusionGroupTrafficAllocation ? m_exclusionGroupTrafficAllocation.operator->() : nullptr;
    }

    void SetExperimentType(StdExtra::optional<PFExperimentationExperimentType> value)
    {
        m_experimentType = std::move(value);
        this->m_model.experimentType = m_experimentType ? m_experimentType.operator->() : nullptr;
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    void SetStartDate(time_t value)
    {
        this->m_model.startDate = value;
    }

    void SetTitlePlayerAccountTestIds(CStringVector<Alloc> value)
    {
        m_titlePlayerAccountTestIds = std::move(value);
        this->m_model.titlePlayerAccountTestIds =  m_titlePlayerAccountTestIds.empty() ? nullptr : m_titlePlayerAccountTestIds.data();
        this->m_model.titlePlayerAccountTestIdsCount =  static_cast<uint32_t>(m_titlePlayerAccountTestIds.size());
    }

    void SetVariants(ModelVector<PFExperimentationVariantWrapper<Alloc>, Alloc> value)
    {
        m_variants = std::move(value);
        this->m_model.variants =  m_variants.empty() ? nullptr : m_variants.data();
        this->m_model.variantsCount =  static_cast<uint32_t>(m_variants.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.endDate = m_endDate ? m_endDate.operator->() : nullptr;
        this->m_model.exclusionGroupId = m_exclusionGroupId.empty() ? nullptr : m_exclusionGroupId.data();
        this->m_model.exclusionGroupTrafficAllocation = m_exclusionGroupTrafficAllocation ? m_exclusionGroupTrafficAllocation.operator->() : nullptr;
        this->m_model.experimentType = m_experimentType ? m_experimentType.operator->() : nullptr;
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
        this->m_model.titlePlayerAccountTestIds = m_titlePlayerAccountTestIds.empty() ? nullptr : m_titlePlayerAccountTestIds.data();
        this->m_model.variants = m_variants.empty() ? nullptr : m_variants.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    StdExtra::optional<time_t> m_endDate;
    String m_exclusionGroupId;
    StdExtra::optional<uint32_t> m_exclusionGroupTrafficAllocation;
    StdExtra::optional<PFExperimentationExperimentType> m_experimentType;
    String m_id;
    String m_name;
    String m_segmentId;
    CStringVector<Alloc> m_titlePlayerAccountTestIds;
    ModelVector<PFExperimentationVariantWrapper<Alloc>, Alloc> m_variants;
};

} // namespace Wrappers
} // namespace PlayFab
