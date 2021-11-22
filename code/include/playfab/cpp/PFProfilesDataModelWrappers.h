// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFProfilesDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetGlobalPolicyRequestWrapper : public ModelWrapper<PFProfilesGetGlobalPolicyRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesGetGlobalPolicyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetGlobalPolicyRequestWrapper() = default;

    PFProfilesGetGlobalPolicyRequestWrapper(const PFProfilesGetGlobalPolicyRequest& model) :
        ModelWrapper<PFProfilesGetGlobalPolicyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFProfilesGetGlobalPolicyRequestWrapper(const PFProfilesGetGlobalPolicyRequestWrapper& src) :
        PFProfilesGetGlobalPolicyRequestWrapper{ src.Model() }
    {
    }

    PFProfilesGetGlobalPolicyRequestWrapper(PFProfilesGetGlobalPolicyRequestWrapper&& src) :
        PFProfilesGetGlobalPolicyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetGlobalPolicyRequestWrapper& operator=(PFProfilesGetGlobalPolicyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetGlobalPolicyRequestWrapper() = default;

    friend void swap(PFProfilesGetGlobalPolicyRequestWrapper& lhs, PFProfilesGetGlobalPolicyRequestWrapper& rhs)
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
class PFProfilesEntityPermissionStatementWrapper : public ModelWrapper<PFProfilesEntityPermissionStatement, Alloc>
{
public:
    using ModelType = typename PFProfilesEntityPermissionStatement;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesEntityPermissionStatementWrapper() = default;

    PFProfilesEntityPermissionStatementWrapper(const PFProfilesEntityPermissionStatement& model) :
        ModelWrapper<PFProfilesEntityPermissionStatement, Alloc>{ model },
        m_action{ SafeString(model.action) },
        m_comment{ SafeString(model.comment) },
        m_condition{ model.condition },
        m_principal{ model.principal },
        m_resource{ SafeString(model.resource) }
    {
        SetModelPointers();
    }

    PFProfilesEntityPermissionStatementWrapper(const PFProfilesEntityPermissionStatementWrapper& src) :
        PFProfilesEntityPermissionStatementWrapper{ src.Model() }
    {
    }

    PFProfilesEntityPermissionStatementWrapper(PFProfilesEntityPermissionStatementWrapper&& src) :
        PFProfilesEntityPermissionStatementWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesEntityPermissionStatementWrapper& operator=(PFProfilesEntityPermissionStatementWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesEntityPermissionStatementWrapper() = default;

    friend void swap(PFProfilesEntityPermissionStatementWrapper& lhs, PFProfilesEntityPermissionStatementWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_action, rhs.m_action);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_condition, rhs.m_condition);
        swap(lhs.m_principal, rhs.m_principal);
        swap(lhs.m_resource, rhs.m_resource);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAction(String value)
    {
        m_action = std::move(value);
        this->m_model.action =  m_action.empty() ? nullptr : m_action.data();
    }

    void SetComment(String value)
    {
        m_comment = std::move(value);
        this->m_model.comment =  m_comment.empty() ? nullptr : m_comment.data();
    }

    void SetCondition(JsonObject<Alloc> value)
    {
        m_condition = std::move(value);
        this->m_model.condition.stringValue = m_condition.stringValue.empty() ? nullptr : m_condition.stringValue.data();
    }

    void SetEffect(PFEffectType value)
    {
        this->m_model.effect = value;
    }

    void SetPrincipal(JsonObject<Alloc> value)
    {
        m_principal = std::move(value);
        this->m_model.principal.stringValue = m_principal.stringValue.empty() ? nullptr : m_principal.stringValue.data();
    }

    void SetResource(String value)
    {
        m_resource = std::move(value);
        this->m_model.resource =  m_resource.empty() ? nullptr : m_resource.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.action = m_action.empty() ? nullptr : m_action.data();
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.condition.stringValue = m_condition.stringValue.empty() ? nullptr : m_condition.stringValue.data();
        this->m_model.principal.stringValue = m_principal.stringValue.empty() ? nullptr : m_principal.stringValue.data();
        this->m_model.resource = m_resource.empty() ? nullptr : m_resource.data();
    }

    String m_action;
    String m_comment;
    JsonObject<Alloc> m_condition;
    JsonObject<Alloc> m_principal;
    String m_resource;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetGlobalPolicyResponseWrapper : public ModelWrapper<PFProfilesGetGlobalPolicyResponse, Alloc>
{
public:
    using ModelType = typename PFProfilesGetGlobalPolicyResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetGlobalPolicyResponseWrapper() = default;

    PFProfilesGetGlobalPolicyResponseWrapper(const PFProfilesGetGlobalPolicyResponse& model) :
        ModelWrapper<PFProfilesGetGlobalPolicyResponse, Alloc>{ model },
        m_permissions{ model.permissions, model.permissions + model.permissionsCount }
    {
        SetModelPointers();
    }

    PFProfilesGetGlobalPolicyResponseWrapper(const PFProfilesGetGlobalPolicyResponseWrapper& src) :
        PFProfilesGetGlobalPolicyResponseWrapper{ src.Model() }
    {
    }

    PFProfilesGetGlobalPolicyResponseWrapper(PFProfilesGetGlobalPolicyResponseWrapper&& src) :
        PFProfilesGetGlobalPolicyResponseWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetGlobalPolicyResponseWrapper& operator=(PFProfilesGetGlobalPolicyResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetGlobalPolicyResponseWrapper() = default;

    friend void swap(PFProfilesGetGlobalPolicyResponseWrapper& lhs, PFProfilesGetGlobalPolicyResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_permissions, rhs.m_permissions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPermissions(ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_permissions = std::move(value);
        this->m_model.permissions =  m_permissions.empty() ? nullptr : m_permissions.data();
        this->m_model.permissionsCount =  static_cast<uint32_t>(m_permissions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.permissions = m_permissions.empty() ? nullptr : m_permissions.data();
    }

    ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> m_permissions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetEntityProfileRequestWrapper : public ModelWrapper<PFProfilesGetEntityProfileRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesGetEntityProfileRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetEntityProfileRequestWrapper() = default;

    PFProfilesGetEntityProfileRequestWrapper(const PFProfilesGetEntityProfileRequest& model) :
        ModelWrapper<PFProfilesGetEntityProfileRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_dataAsObject{ model.dataAsObject ? StdExtra::optional<bool>{ *model.dataAsObject } : StdExtra::nullopt },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFProfilesGetEntityProfileRequestWrapper(const PFProfilesGetEntityProfileRequestWrapper& src) :
        PFProfilesGetEntityProfileRequestWrapper{ src.Model() }
    {
    }

    PFProfilesGetEntityProfileRequestWrapper(PFProfilesGetEntityProfileRequestWrapper&& src) :
        PFProfilesGetEntityProfileRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetEntityProfileRequestWrapper& operator=(PFProfilesGetEntityProfileRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetEntityProfileRequestWrapper() = default;

    friend void swap(PFProfilesGetEntityProfileRequestWrapper& lhs, PFProfilesGetEntityProfileRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_dataAsObject, rhs.m_dataAsObject);
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

    void SetDataAsObject(StdExtra::optional<bool> value)
    {
        m_dataAsObject = std::move(value);
        this->m_model.dataAsObject = m_dataAsObject ? m_dataAsObject.operator->() : nullptr;
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
        this->m_model.dataAsObject = m_dataAsObject ? m_dataAsObject.operator->() : nullptr;
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_dataAsObject;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesEntityProfileFileMetadataWrapper : public ModelWrapper<PFProfilesEntityProfileFileMetadata, Alloc>
{
public:
    using ModelType = typename PFProfilesEntityProfileFileMetadata;
    using DictionaryEntryType = typename PFProfilesEntityProfileFileMetadataDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesEntityProfileFileMetadataWrapper() = default;

    PFProfilesEntityProfileFileMetadataWrapper(const PFProfilesEntityProfileFileMetadata& model) :
        ModelWrapper<PFProfilesEntityProfileFileMetadata, Alloc>{ model },
        m_checksum{ SafeString(model.checksum) },
        m_fileName{ SafeString(model.fileName) }
    {
        SetModelPointers();
    }

    PFProfilesEntityProfileFileMetadataWrapper(const PFProfilesEntityProfileFileMetadataWrapper& src) :
        PFProfilesEntityProfileFileMetadataWrapper{ src.Model() }
    {
    }

    PFProfilesEntityProfileFileMetadataWrapper(PFProfilesEntityProfileFileMetadataWrapper&& src) :
        PFProfilesEntityProfileFileMetadataWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesEntityProfileFileMetadataWrapper& operator=(PFProfilesEntityProfileFileMetadataWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesEntityProfileFileMetadataWrapper() = default;

    friend void swap(PFProfilesEntityProfileFileMetadataWrapper& lhs, PFProfilesEntityProfileFileMetadataWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_checksum, rhs.m_checksum);
        swap(lhs.m_fileName, rhs.m_fileName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChecksum(String value)
    {
        m_checksum = std::move(value);
        this->m_model.checksum =  m_checksum.empty() ? nullptr : m_checksum.data();
    }

    void SetFileName(String value)
    {
        m_fileName = std::move(value);
        this->m_model.fileName =  m_fileName.empty() ? nullptr : m_fileName.data();
    }

    void SetLastModified(time_t value)
    {
        this->m_model.lastModified = value;
    }

    void SetSize(int32_t value)
    {
        this->m_model.size = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.checksum = m_checksum.empty() ? nullptr : m_checksum.data();
        this->m_model.fileName = m_fileName.empty() ? nullptr : m_fileName.data();
    }

    String m_checksum;
    String m_fileName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesEntityDataObjectWrapper : public ModelWrapper<PFProfilesEntityDataObject, Alloc>
{
public:
    using ModelType = typename PFProfilesEntityDataObject;
    using DictionaryEntryType = typename PFProfilesEntityDataObjectDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesEntityDataObjectWrapper() = default;

    PFProfilesEntityDataObjectWrapper(const PFProfilesEntityDataObject& model) :
        ModelWrapper<PFProfilesEntityDataObject, Alloc>{ model },
        m_dataObject{ model.dataObject },
        m_escapedDataObject{ SafeString(model.escapedDataObject) },
        m_objectName{ SafeString(model.objectName) }
    {
        SetModelPointers();
    }

    PFProfilesEntityDataObjectWrapper(const PFProfilesEntityDataObjectWrapper& src) :
        PFProfilesEntityDataObjectWrapper{ src.Model() }
    {
    }

    PFProfilesEntityDataObjectWrapper(PFProfilesEntityDataObjectWrapper&& src) :
        PFProfilesEntityDataObjectWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesEntityDataObjectWrapper& operator=(PFProfilesEntityDataObjectWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesEntityDataObjectWrapper() = default;

    friend void swap(PFProfilesEntityDataObjectWrapper& lhs, PFProfilesEntityDataObjectWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_dataObject, rhs.m_dataObject);
        swap(lhs.m_escapedDataObject, rhs.m_escapedDataObject);
        swap(lhs.m_objectName, rhs.m_objectName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDataObject(JsonObject<Alloc> value)
    {
        m_dataObject = std::move(value);
        this->m_model.dataObject.stringValue = m_dataObject.stringValue.empty() ? nullptr : m_dataObject.stringValue.data();
    }

    void SetEscapedDataObject(String value)
    {
        m_escapedDataObject = std::move(value);
        this->m_model.escapedDataObject =  m_escapedDataObject.empty() ? nullptr : m_escapedDataObject.data();
    }

    void SetObjectName(String value)
    {
        m_objectName = std::move(value);
        this->m_model.objectName =  m_objectName.empty() ? nullptr : m_objectName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.dataObject.stringValue = m_dataObject.stringValue.empty() ? nullptr : m_dataObject.stringValue.data();
        this->m_model.escapedDataObject = m_escapedDataObject.empty() ? nullptr : m_escapedDataObject.data();
        this->m_model.objectName = m_objectName.empty() ? nullptr : m_objectName.data();
    }

    JsonObject<Alloc> m_dataObject;
    String m_escapedDataObject;
    String m_objectName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesEntityStatisticChildValueWrapper : public ModelWrapper<PFProfilesEntityStatisticChildValue, Alloc>
{
public:
    using ModelType = typename PFProfilesEntityStatisticChildValue;
    using DictionaryEntryType = typename PFProfilesEntityStatisticChildValueDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesEntityStatisticChildValueWrapper() = default;

    PFProfilesEntityStatisticChildValueWrapper(const PFProfilesEntityStatisticChildValue& model) :
        ModelWrapper<PFProfilesEntityStatisticChildValue, Alloc>{ model },
        m_childName{ SafeString(model.childName) },
        m_metadata{ SafeString(model.metadata) }
    {
        SetModelPointers();
    }

    PFProfilesEntityStatisticChildValueWrapper(const PFProfilesEntityStatisticChildValueWrapper& src) :
        PFProfilesEntityStatisticChildValueWrapper{ src.Model() }
    {
    }

    PFProfilesEntityStatisticChildValueWrapper(PFProfilesEntityStatisticChildValueWrapper&& src) :
        PFProfilesEntityStatisticChildValueWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesEntityStatisticChildValueWrapper& operator=(PFProfilesEntityStatisticChildValueWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesEntityStatisticChildValueWrapper() = default;

    friend void swap(PFProfilesEntityStatisticChildValueWrapper& lhs, PFProfilesEntityStatisticChildValueWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_childName, rhs.m_childName);
        swap(lhs.m_metadata, rhs.m_metadata);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChildName(String value)
    {
        m_childName = std::move(value);
        this->m_model.childName =  m_childName.empty() ? nullptr : m_childName.data();
    }

    void SetMetadata(String value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
    }

    void SetValue(int32_t value)
    {
        this->m_model.value = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.childName = m_childName.empty() ? nullptr : m_childName.data();
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
    }

    String m_childName;
    String m_metadata;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesEntityStatisticValueWrapper : public ModelWrapper<PFProfilesEntityStatisticValue, Alloc>
{
public:
    using ModelType = typename PFProfilesEntityStatisticValue;
    using DictionaryEntryType = typename PFProfilesEntityStatisticValueDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesEntityStatisticValueWrapper() = default;

    PFProfilesEntityStatisticValueWrapper(const PFProfilesEntityStatisticValue& model) :
        ModelWrapper<PFProfilesEntityStatisticValue, Alloc>{ model },
        m_childStatistics{ model.childStatistics, model.childStatistics + model.childStatisticsCount },
        m_metadata{ SafeString(model.metadata) },
        m_name{ SafeString(model.name) },
        m_value{ model.value ? StdExtra::optional<int32_t>{ *model.value } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFProfilesEntityStatisticValueWrapper(const PFProfilesEntityStatisticValueWrapper& src) :
        PFProfilesEntityStatisticValueWrapper{ src.Model() }
    {
    }

    PFProfilesEntityStatisticValueWrapper(PFProfilesEntityStatisticValueWrapper&& src) :
        PFProfilesEntityStatisticValueWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesEntityStatisticValueWrapper& operator=(PFProfilesEntityStatisticValueWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesEntityStatisticValueWrapper() = default;

    friend void swap(PFProfilesEntityStatisticValueWrapper& lhs, PFProfilesEntityStatisticValueWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_childStatistics, rhs.m_childStatistics);
        swap(lhs.m_metadata, rhs.m_metadata);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetChildStatistics(ModelDictionaryEntryVector<PFProfilesEntityStatisticChildValueWrapper<Alloc>, Alloc> value)
    {
        m_childStatistics = std::move(value);
        this->m_model.childStatistics =  m_childStatistics.empty() ? nullptr : m_childStatistics.data();
        this->m_model.childStatisticsCount =  static_cast<uint32_t>(m_childStatistics.size());
    }

    void SetMetadata(String value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata =  m_metadata.empty() ? nullptr : m_metadata.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetValue(StdExtra::optional<int32_t> value)
    {
        m_value = std::move(value);
        this->m_model.value = m_value ? m_value.operator->() : nullptr;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.childStatistics = m_childStatistics.empty() ? nullptr : m_childStatistics.data();
        this->m_model.metadata = m_metadata.empty() ? nullptr : m_metadata.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.value = m_value ? m_value.operator->() : nullptr;
    }

    ModelDictionaryEntryVector<PFProfilesEntityStatisticChildValueWrapper<Alloc>, Alloc> m_childStatistics;
    String m_metadata;
    String m_name;
    StdExtra::optional<int32_t> m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesEntityProfileBodyWrapper : public ModelWrapper<PFProfilesEntityProfileBody, Alloc>
{
public:
    using ModelType = typename PFProfilesEntityProfileBody;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesEntityProfileBodyWrapper() = default;

    PFProfilesEntityProfileBodyWrapper(const PFProfilesEntityProfileBody& model) :
        ModelWrapper<PFProfilesEntityProfileBody, Alloc>{ model },
        m_avatarUrl{ SafeString(model.avatarUrl) },
        m_displayName{ SafeString(model.displayName) },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_entityChain{ SafeString(model.entityChain) },
        m_experimentVariants{ model.experimentVariants, model.experimentVariants + model.experimentVariantsCount },
        m_files{ model.files, model.files + model.filesCount },
        m_language{ SafeString(model.language) },
        m_leaderboardMetadata{ SafeString(model.leaderboardMetadata) },
        m_lineage{ model.lineage ? StdExtra::optional<PFEntityLineageWrapper<Alloc>>{ *model.lineage } : StdExtra::nullopt },
        m_objects{ model.objects, model.objects + model.objectsCount },
        m_permissions{ model.permissions, model.permissions + model.permissionsCount },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFProfilesEntityProfileBodyWrapper(const PFProfilesEntityProfileBodyWrapper& src) :
        PFProfilesEntityProfileBodyWrapper{ src.Model() }
    {
    }

    PFProfilesEntityProfileBodyWrapper(PFProfilesEntityProfileBodyWrapper&& src) :
        PFProfilesEntityProfileBodyWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesEntityProfileBodyWrapper& operator=(PFProfilesEntityProfileBodyWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesEntityProfileBodyWrapper() = default;

    friend void swap(PFProfilesEntityProfileBodyWrapper& lhs, PFProfilesEntityProfileBodyWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_avatarUrl, rhs.m_avatarUrl);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_entityChain, rhs.m_entityChain);
        swap(lhs.m_experimentVariants, rhs.m_experimentVariants);
        swap(lhs.m_files, rhs.m_files);
        swap(lhs.m_language, rhs.m_language);
        swap(lhs.m_leaderboardMetadata, rhs.m_leaderboardMetadata);
        swap(lhs.m_lineage, rhs.m_lineage);
        swap(lhs.m_objects, rhs.m_objects);
        swap(lhs.m_permissions, rhs.m_permissions);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAvatarUrl(String value)
    {
        m_avatarUrl = std::move(value);
        this->m_model.avatarUrl =  m_avatarUrl.empty() ? nullptr : m_avatarUrl.data();
    }

    void SetCreated(time_t value)
    {
        this->m_model.created = value;
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetEntityChain(String value)
    {
        m_entityChain = std::move(value);
        this->m_model.entityChain =  m_entityChain.empty() ? nullptr : m_entityChain.data();
    }

    void SetExperimentVariants(CStringVector<Alloc> value)
    {
        m_experimentVariants = std::move(value);
        this->m_model.experimentVariants =  m_experimentVariants.empty() ? nullptr : m_experimentVariants.data();
        this->m_model.experimentVariantsCount =  static_cast<uint32_t>(m_experimentVariants.size());
    }

    void SetFiles(ModelDictionaryEntryVector<PFProfilesEntityProfileFileMetadataWrapper<Alloc>, Alloc> value)
    {
        m_files = std::move(value);
        this->m_model.files =  m_files.empty() ? nullptr : m_files.data();
        this->m_model.filesCount =  static_cast<uint32_t>(m_files.size());
    }

    void SetLanguage(String value)
    {
        m_language = std::move(value);
        this->m_model.language =  m_language.empty() ? nullptr : m_language.data();
    }

    void SetLeaderboardMetadata(String value)
    {
        m_leaderboardMetadata = std::move(value);
        this->m_model.leaderboardMetadata =  m_leaderboardMetadata.empty() ? nullptr : m_leaderboardMetadata.data();
    }

    void SetLineage(StdExtra::optional<PFEntityLineageWrapper<Alloc>> value)
    {
        m_lineage = std::move(value);
        this->m_model.lineage = m_lineage ? &m_lineage->Model() : nullptr;
    }

    void SetObjects(ModelDictionaryEntryVector<PFProfilesEntityDataObjectWrapper<Alloc>, Alloc> value)
    {
        m_objects = std::move(value);
        this->m_model.objects =  m_objects.empty() ? nullptr : m_objects.data();
        this->m_model.objectsCount =  static_cast<uint32_t>(m_objects.size());
    }

    void SetPermissions(ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_permissions = std::move(value);
        this->m_model.permissions =  m_permissions.empty() ? nullptr : m_permissions.data();
        this->m_model.permissionsCount =  static_cast<uint32_t>(m_permissions.size());
    }

    void SetStatistics(ModelDictionaryEntryVector<PFProfilesEntityStatisticValueWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

    void SetVersionNumber(int32_t value)
    {
        this->m_model.versionNumber = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.avatarUrl = m_avatarUrl.empty() ? nullptr : m_avatarUrl.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.entityChain = m_entityChain.empty() ? nullptr : m_entityChain.data();
        this->m_model.experimentVariants = m_experimentVariants.empty() ? nullptr : m_experimentVariants.data();
        this->m_model.files = m_files.empty() ? nullptr : m_files.data();
        this->m_model.language = m_language.empty() ? nullptr : m_language.data();
        this->m_model.leaderboardMetadata = m_leaderboardMetadata.empty() ? nullptr : m_leaderboardMetadata.data();
        this->m_model.lineage = m_lineage ?  &m_lineage->Model() : nullptr;
        this->m_model.objects = m_objects.empty() ? nullptr : m_objects.data();
        this->m_model.permissions = m_permissions.empty() ? nullptr : m_permissions.data();
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
    }

    String m_avatarUrl;
    String m_displayName;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_entityChain;
    CStringVector<Alloc> m_experimentVariants;
    ModelDictionaryEntryVector<PFProfilesEntityProfileFileMetadataWrapper<Alloc>, Alloc> m_files;
    String m_language;
    String m_leaderboardMetadata;
    StdExtra::optional<PFEntityLineageWrapper<Alloc>> m_lineage;
    ModelDictionaryEntryVector<PFProfilesEntityDataObjectWrapper<Alloc>, Alloc> m_objects;
    ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> m_permissions;
    ModelDictionaryEntryVector<PFProfilesEntityStatisticValueWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetEntityProfileResponseWrapper : public ModelWrapper<PFProfilesGetEntityProfileResponse, Alloc>
{
public:
    using ModelType = typename PFProfilesGetEntityProfileResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetEntityProfileResponseWrapper() = default;

    PFProfilesGetEntityProfileResponseWrapper(const PFProfilesGetEntityProfileResponse& model) :
        ModelWrapper<PFProfilesGetEntityProfileResponse, Alloc>{ model },
        m_profile{ model.profile ? StdExtra::optional<PFProfilesEntityProfileBodyWrapper<Alloc>>{ *model.profile } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFProfilesGetEntityProfileResponseWrapper(const PFProfilesGetEntityProfileResponseWrapper& src) :
        PFProfilesGetEntityProfileResponseWrapper{ src.Model() }
    {
    }

    PFProfilesGetEntityProfileResponseWrapper(PFProfilesGetEntityProfileResponseWrapper&& src) :
        PFProfilesGetEntityProfileResponseWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetEntityProfileResponseWrapper& operator=(PFProfilesGetEntityProfileResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetEntityProfileResponseWrapper() = default;

    friend void swap(PFProfilesGetEntityProfileResponseWrapper& lhs, PFProfilesGetEntityProfileResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_profile, rhs.m_profile);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetProfile(StdExtra::optional<PFProfilesEntityProfileBodyWrapper<Alloc>> value)
    {
        m_profile = std::move(value);
        this->m_model.profile = m_profile ? &m_profile->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.profile = m_profile ?  &m_profile->Model() : nullptr;
    }

    StdExtra::optional<PFProfilesEntityProfileBodyWrapper<Alloc>> m_profile;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetEntityProfilesRequestWrapper : public ModelWrapper<PFProfilesGetEntityProfilesRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesGetEntityProfilesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetEntityProfilesRequestWrapper() = default;

    PFProfilesGetEntityProfilesRequestWrapper(const PFProfilesGetEntityProfilesRequest& model) :
        ModelWrapper<PFProfilesGetEntityProfilesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_dataAsObject{ model.dataAsObject ? StdExtra::optional<bool>{ *model.dataAsObject } : StdExtra::nullopt },
        m_entities{ model.entities, model.entities + model.entitiesCount }
    {
        SetModelPointers();
    }

    PFProfilesGetEntityProfilesRequestWrapper(const PFProfilesGetEntityProfilesRequestWrapper& src) :
        PFProfilesGetEntityProfilesRequestWrapper{ src.Model() }
    {
    }

    PFProfilesGetEntityProfilesRequestWrapper(PFProfilesGetEntityProfilesRequestWrapper&& src) :
        PFProfilesGetEntityProfilesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetEntityProfilesRequestWrapper& operator=(PFProfilesGetEntityProfilesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetEntityProfilesRequestWrapper() = default;

    friend void swap(PFProfilesGetEntityProfilesRequestWrapper& lhs, PFProfilesGetEntityProfilesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_dataAsObject, rhs.m_dataAsObject);
        swap(lhs.m_entities, rhs.m_entities);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDataAsObject(StdExtra::optional<bool> value)
    {
        m_dataAsObject = std::move(value);
        this->m_model.dataAsObject = m_dataAsObject ? m_dataAsObject.operator->() : nullptr;
    }

    void SetEntities(ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_entities = std::move(value);
        this->m_model.entities =  m_entities.empty() ? nullptr : m_entities.data();
        this->m_model.entitiesCount =  static_cast<uint32_t>(m_entities.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.dataAsObject = m_dataAsObject ? m_dataAsObject.operator->() : nullptr;
        this->m_model.entities = m_entities.empty() ? nullptr : m_entities.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_dataAsObject;
    ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> m_entities;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetEntityProfilesResponseWrapper : public ModelWrapper<PFProfilesGetEntityProfilesResponse, Alloc>
{
public:
    using ModelType = typename PFProfilesGetEntityProfilesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetEntityProfilesResponseWrapper() = default;

    PFProfilesGetEntityProfilesResponseWrapper(const PFProfilesGetEntityProfilesResponse& model) :
        ModelWrapper<PFProfilesGetEntityProfilesResponse, Alloc>{ model },
        m_profiles{ model.profiles, model.profiles + model.profilesCount }
    {
        SetModelPointers();
    }

    PFProfilesGetEntityProfilesResponseWrapper(const PFProfilesGetEntityProfilesResponseWrapper& src) :
        PFProfilesGetEntityProfilesResponseWrapper{ src.Model() }
    {
    }

    PFProfilesGetEntityProfilesResponseWrapper(PFProfilesGetEntityProfilesResponseWrapper&& src) :
        PFProfilesGetEntityProfilesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetEntityProfilesResponseWrapper& operator=(PFProfilesGetEntityProfilesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetEntityProfilesResponseWrapper() = default;

    friend void swap(PFProfilesGetEntityProfilesResponseWrapper& lhs, PFProfilesGetEntityProfilesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_profiles, rhs.m_profiles);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetProfiles(ModelVector<PFProfilesEntityProfileBodyWrapper<Alloc>, Alloc> value)
    {
        m_profiles = std::move(value);
        this->m_model.profiles =  m_profiles.empty() ? nullptr : m_profiles.data();
        this->m_model.profilesCount =  static_cast<uint32_t>(m_profiles.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.profiles = m_profiles.empty() ? nullptr : m_profiles.data();
    }

    ModelVector<PFProfilesEntityProfileBodyWrapper<Alloc>, Alloc> m_profiles;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper : public ModelWrapper<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper() = default;

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest& model) :
        ModelWrapper<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_masterPlayerAccountIds{ model.masterPlayerAccountIds, model.masterPlayerAccountIds + model.masterPlayerAccountIdsCount },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper& src) :
        PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper{ src.Model() }
    {
    }

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper&& src) :
        PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper& operator=(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper() = default;

    friend void swap(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper& lhs, PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_masterPlayerAccountIds, rhs.m_masterPlayerAccountIds);
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

    void SetMasterPlayerAccountIds(CStringVector<Alloc> value)
    {
        m_masterPlayerAccountIds = std::move(value);
        this->m_model.masterPlayerAccountIds =  m_masterPlayerAccountIds.empty() ? nullptr : m_masterPlayerAccountIds.data();
        this->m_model.masterPlayerAccountIdsCount =  static_cast<uint32_t>(m_masterPlayerAccountIds.size());
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
        this->m_model.masterPlayerAccountIds = m_masterPlayerAccountIds.empty() ? nullptr : m_masterPlayerAccountIds.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    CStringVector<Alloc> m_masterPlayerAccountIds;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper : public ModelWrapper<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse, Alloc>
{
public:
    using ModelType = typename PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper() = default;

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& model) :
        ModelWrapper<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse, Alloc>{ model },
        m_titleId{ SafeString(model.titleId) },
        m_titlePlayerAccounts{ model.titlePlayerAccounts, model.titlePlayerAccounts + model.titlePlayerAccountsCount }
    {
        SetModelPointers();
    }

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper& src) :
        PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper{ src.Model() }
    {
    }

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper&& src) :
        PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper& operator=(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper() = default;

    friend void swap(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper& lhs, PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_titleId, rhs.m_titleId);
        swap(lhs.m_titlePlayerAccounts, rhs.m_titlePlayerAccounts);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

    void SetTitlePlayerAccounts(ModelDictionaryEntryVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_titlePlayerAccounts = std::move(value);
        this->m_model.titlePlayerAccounts =  m_titlePlayerAccounts.empty() ? nullptr : m_titlePlayerAccounts.data();
        this->m_model.titlePlayerAccountsCount =  static_cast<uint32_t>(m_titlePlayerAccounts.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
        this->m_model.titlePlayerAccounts = m_titlePlayerAccounts.empty() ? nullptr : m_titlePlayerAccounts.data();
    }

    String m_titleId;
    ModelDictionaryEntryVector<PFEntityKeyWrapper<Alloc>, Alloc> m_titlePlayerAccounts;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesSetGlobalPolicyRequestWrapper : public ModelWrapper<PFProfilesSetGlobalPolicyRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesSetGlobalPolicyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesSetGlobalPolicyRequestWrapper() = default;

    PFProfilesSetGlobalPolicyRequestWrapper(const PFProfilesSetGlobalPolicyRequest& model) :
        ModelWrapper<PFProfilesSetGlobalPolicyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_permissions{ model.permissions, model.permissions + model.permissionsCount }
    {
        SetModelPointers();
    }

    PFProfilesSetGlobalPolicyRequestWrapper(const PFProfilesSetGlobalPolicyRequestWrapper& src) :
        PFProfilesSetGlobalPolicyRequestWrapper{ src.Model() }
    {
    }

    PFProfilesSetGlobalPolicyRequestWrapper(PFProfilesSetGlobalPolicyRequestWrapper&& src) :
        PFProfilesSetGlobalPolicyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesSetGlobalPolicyRequestWrapper& operator=(PFProfilesSetGlobalPolicyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesSetGlobalPolicyRequestWrapper() = default;

    friend void swap(PFProfilesSetGlobalPolicyRequestWrapper& lhs, PFProfilesSetGlobalPolicyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_permissions, rhs.m_permissions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPermissions(ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_permissions = std::move(value);
        this->m_model.permissions =  m_permissions.empty() ? nullptr : m_permissions.data();
        this->m_model.permissionsCount =  static_cast<uint32_t>(m_permissions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.permissions = m_permissions.empty() ? nullptr : m_permissions.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> m_permissions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesSetProfileLanguageRequestWrapper : public ModelWrapper<PFProfilesSetProfileLanguageRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesSetProfileLanguageRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesSetProfileLanguageRequestWrapper() = default;

    PFProfilesSetProfileLanguageRequestWrapper(const PFProfilesSetProfileLanguageRequest& model) :
        ModelWrapper<PFProfilesSetProfileLanguageRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_expectedVersion{ model.expectedVersion ? StdExtra::optional<int32_t>{ *model.expectedVersion } : StdExtra::nullopt },
        m_language{ SafeString(model.language) }
    {
        SetModelPointers();
    }

    PFProfilesSetProfileLanguageRequestWrapper(const PFProfilesSetProfileLanguageRequestWrapper& src) :
        PFProfilesSetProfileLanguageRequestWrapper{ src.Model() }
    {
    }

    PFProfilesSetProfileLanguageRequestWrapper(PFProfilesSetProfileLanguageRequestWrapper&& src) :
        PFProfilesSetProfileLanguageRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesSetProfileLanguageRequestWrapper& operator=(PFProfilesSetProfileLanguageRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesSetProfileLanguageRequestWrapper() = default;

    friend void swap(PFProfilesSetProfileLanguageRequestWrapper& lhs, PFProfilesSetProfileLanguageRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_expectedVersion, rhs.m_expectedVersion);
        swap(lhs.m_language, rhs.m_language);
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

    void SetExpectedVersion(StdExtra::optional<int32_t> value)
    {
        m_expectedVersion = std::move(value);
        this->m_model.expectedVersion = m_expectedVersion ? m_expectedVersion.operator->() : nullptr;
    }

    void SetLanguage(String value)
    {
        m_language = std::move(value);
        this->m_model.language =  m_language.empty() ? nullptr : m_language.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.expectedVersion = m_expectedVersion ? m_expectedVersion.operator->() : nullptr;
        this->m_model.language = m_language.empty() ? nullptr : m_language.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    StdExtra::optional<int32_t> m_expectedVersion;
    String m_language;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesSetProfileLanguageResponseWrapper : public ModelWrapper<PFProfilesSetProfileLanguageResponse, Alloc>
{
public:
    using ModelType = typename PFProfilesSetProfileLanguageResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesSetProfileLanguageResponseWrapper() = default;

    PFProfilesSetProfileLanguageResponseWrapper(const PFProfilesSetProfileLanguageResponse& model) :
        ModelWrapper<PFProfilesSetProfileLanguageResponse, Alloc>{ model },
        m_operationResult{ model.operationResult ? StdExtra::optional<PFOperationTypes>{ *model.operationResult } : StdExtra::nullopt },
        m_versionNumber{ model.versionNumber ? StdExtra::optional<int32_t>{ *model.versionNumber } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFProfilesSetProfileLanguageResponseWrapper(const PFProfilesSetProfileLanguageResponseWrapper& src) :
        PFProfilesSetProfileLanguageResponseWrapper{ src.Model() }
    {
    }

    PFProfilesSetProfileLanguageResponseWrapper(PFProfilesSetProfileLanguageResponseWrapper&& src) :
        PFProfilesSetProfileLanguageResponseWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesSetProfileLanguageResponseWrapper& operator=(PFProfilesSetProfileLanguageResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesSetProfileLanguageResponseWrapper() = default;

    friend void swap(PFProfilesSetProfileLanguageResponseWrapper& lhs, PFProfilesSetProfileLanguageResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_operationResult, rhs.m_operationResult);
        swap(lhs.m_versionNumber, rhs.m_versionNumber);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOperationResult(StdExtra::optional<PFOperationTypes> value)
    {
        m_operationResult = std::move(value);
        this->m_model.operationResult = m_operationResult ? m_operationResult.operator->() : nullptr;
    }

    void SetVersionNumber(StdExtra::optional<int32_t> value)
    {
        m_versionNumber = std::move(value);
        this->m_model.versionNumber = m_versionNumber ? m_versionNumber.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.operationResult = m_operationResult ? m_operationResult.operator->() : nullptr;
        this->m_model.versionNumber = m_versionNumber ? m_versionNumber.operator->() : nullptr;
    }

    StdExtra::optional<PFOperationTypes> m_operationResult;
    StdExtra::optional<int32_t> m_versionNumber;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesSetEntityProfilePolicyRequestWrapper : public ModelWrapper<PFProfilesSetEntityProfilePolicyRequest, Alloc>
{
public:
    using ModelType = typename PFProfilesSetEntityProfilePolicyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesSetEntityProfilePolicyRequestWrapper() = default;

    PFProfilesSetEntityProfilePolicyRequestWrapper(const PFProfilesSetEntityProfilePolicyRequest& model) :
        ModelWrapper<PFProfilesSetEntityProfilePolicyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_statements{ model.statements, model.statements + model.statementsCount }
    {
        SetModelPointers();
    }

    PFProfilesSetEntityProfilePolicyRequestWrapper(const PFProfilesSetEntityProfilePolicyRequestWrapper& src) :
        PFProfilesSetEntityProfilePolicyRequestWrapper{ src.Model() }
    {
    }

    PFProfilesSetEntityProfilePolicyRequestWrapper(PFProfilesSetEntityProfilePolicyRequestWrapper&& src) :
        PFProfilesSetEntityProfilePolicyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesSetEntityProfilePolicyRequestWrapper& operator=(PFProfilesSetEntityProfilePolicyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesSetEntityProfilePolicyRequestWrapper() = default;

    friend void swap(PFProfilesSetEntityProfilePolicyRequestWrapper& lhs, PFProfilesSetEntityProfilePolicyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_statements, rhs.m_statements);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = &m_entity.Model();
    }

    void SetStatements(ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_statements = std::move(value);
        this->m_model.statements =  m_statements.empty() ? nullptr : m_statements.data();
        this->m_model.statementsCount =  static_cast<uint32_t>(m_statements.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
        this->m_model.statements = m_statements.empty() ? nullptr : m_statements.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
    ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> m_statements;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFProfilesSetEntityProfilePolicyResponseWrapper : public ModelWrapper<PFProfilesSetEntityProfilePolicyResponse, Alloc>
{
public:
    using ModelType = typename PFProfilesSetEntityProfilePolicyResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFProfilesSetEntityProfilePolicyResponseWrapper() = default;

    PFProfilesSetEntityProfilePolicyResponseWrapper(const PFProfilesSetEntityProfilePolicyResponse& model) :
        ModelWrapper<PFProfilesSetEntityProfilePolicyResponse, Alloc>{ model },
        m_permissions{ model.permissions, model.permissions + model.permissionsCount }
    {
        SetModelPointers();
    }

    PFProfilesSetEntityProfilePolicyResponseWrapper(const PFProfilesSetEntityProfilePolicyResponseWrapper& src) :
        PFProfilesSetEntityProfilePolicyResponseWrapper{ src.Model() }
    {
    }

    PFProfilesSetEntityProfilePolicyResponseWrapper(PFProfilesSetEntityProfilePolicyResponseWrapper&& src) :
        PFProfilesSetEntityProfilePolicyResponseWrapper{}
    {
        swap(*this, src);
    }

    PFProfilesSetEntityProfilePolicyResponseWrapper& operator=(PFProfilesSetEntityProfilePolicyResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFProfilesSetEntityProfilePolicyResponseWrapper() = default;

    friend void swap(PFProfilesSetEntityProfilePolicyResponseWrapper& lhs, PFProfilesSetEntityProfilePolicyResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_permissions, rhs.m_permissions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPermissions(ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_permissions = std::move(value);
        this->m_model.permissions =  m_permissions.empty() ? nullptr : m_permissions.data();
        this->m_model.permissionsCount =  static_cast<uint32_t>(m_permissions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.permissions = m_permissions.empty() ? nullptr : m_permissions.data();
    }

    ModelVector<PFProfilesEntityPermissionStatementWrapper<Alloc>, Alloc> m_permissions;
};

} // namespace Wrappers
} // namespace PlayFab
