// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFCloudScriptDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptGetCloudScriptRevisionRequestWrapper : public ModelWrapper<PFCloudScriptGetCloudScriptRevisionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptGetCloudScriptRevisionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptGetCloudScriptRevisionRequestWrapper() = default;

    PFCloudScriptGetCloudScriptRevisionRequestWrapper(const PFCloudScriptGetCloudScriptRevisionRequest& model) :
        ModelWrapper<PFCloudScriptGetCloudScriptRevisionRequest, Alloc>{ model },
        m_revision{ model.revision ? StdExtra::optional<int32_t>{ *model.revision } : StdExtra::nullopt },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptGetCloudScriptRevisionRequestWrapper(const PFCloudScriptGetCloudScriptRevisionRequestWrapper& src) :
        PFCloudScriptGetCloudScriptRevisionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptGetCloudScriptRevisionRequestWrapper(PFCloudScriptGetCloudScriptRevisionRequestWrapper&& src) :
        PFCloudScriptGetCloudScriptRevisionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptGetCloudScriptRevisionRequestWrapper& operator=(PFCloudScriptGetCloudScriptRevisionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptGetCloudScriptRevisionRequestWrapper() = default;

    friend void swap(PFCloudScriptGetCloudScriptRevisionRequestWrapper& lhs, PFCloudScriptGetCloudScriptRevisionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_revision, rhs.m_revision);
        swap(lhs.m_version, rhs.m_version);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetRevision(StdExtra::optional<int32_t> value)
    {
        m_revision = std::move(value);
        this->m_model.revision = m_revision ? m_revision.operator->() : nullptr;
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.revision = m_revision ? m_revision.operator->() : nullptr;
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

    StdExtra::optional<int32_t> m_revision;
    StdExtra::optional<int32_t> m_version;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptCloudScriptFileWrapper : public ModelWrapper<PFCloudScriptCloudScriptFile, Alloc>
{
public:
    using ModelType = typename PFCloudScriptCloudScriptFile;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptCloudScriptFileWrapper() = default;

    PFCloudScriptCloudScriptFileWrapper(const PFCloudScriptCloudScriptFile& model) :
        ModelWrapper<PFCloudScriptCloudScriptFile, Alloc>{ model },
        m_fileContents{ SafeString(model.fileContents) },
        m_filename{ SafeString(model.filename) }
    {
        SetModelPointers();
    }

    PFCloudScriptCloudScriptFileWrapper(const PFCloudScriptCloudScriptFileWrapper& src) :
        PFCloudScriptCloudScriptFileWrapper{ src.Model() }
    {
    }

    PFCloudScriptCloudScriptFileWrapper(PFCloudScriptCloudScriptFileWrapper&& src) :
        PFCloudScriptCloudScriptFileWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptCloudScriptFileWrapper& operator=(PFCloudScriptCloudScriptFileWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptCloudScriptFileWrapper() = default;

    friend void swap(PFCloudScriptCloudScriptFileWrapper& lhs, PFCloudScriptCloudScriptFileWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fileContents, rhs.m_fileContents);
        swap(lhs.m_filename, rhs.m_filename);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFileContents(String value)
    {
        m_fileContents = std::move(value);
        this->m_model.fileContents =  m_fileContents.empty() ? nullptr : m_fileContents.data();
    }

    void SetFilename(String value)
    {
        m_filename = std::move(value);
        this->m_model.filename =  m_filename.empty() ? nullptr : m_filename.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.fileContents = m_fileContents.empty() ? nullptr : m_fileContents.data();
        this->m_model.filename = m_filename.empty() ? nullptr : m_filename.data();
    }

    String m_fileContents;
    String m_filename;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptGetCloudScriptRevisionResultWrapper : public ModelWrapper<PFCloudScriptGetCloudScriptRevisionResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptGetCloudScriptRevisionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptGetCloudScriptRevisionResultWrapper() = default;

    PFCloudScriptGetCloudScriptRevisionResultWrapper(const PFCloudScriptGetCloudScriptRevisionResult& model) :
        ModelWrapper<PFCloudScriptGetCloudScriptRevisionResult, Alloc>{ model },
        m_files{ model.files, model.files + model.filesCount }
    {
        SetModelPointers();
    }

    PFCloudScriptGetCloudScriptRevisionResultWrapper(const PFCloudScriptGetCloudScriptRevisionResultWrapper& src) :
        PFCloudScriptGetCloudScriptRevisionResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptGetCloudScriptRevisionResultWrapper(PFCloudScriptGetCloudScriptRevisionResultWrapper&& src) :
        PFCloudScriptGetCloudScriptRevisionResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptGetCloudScriptRevisionResultWrapper& operator=(PFCloudScriptGetCloudScriptRevisionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptGetCloudScriptRevisionResultWrapper() = default;

    friend void swap(PFCloudScriptGetCloudScriptRevisionResultWrapper& lhs, PFCloudScriptGetCloudScriptRevisionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_files, rhs.m_files);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreatedAt(time_t value)
    {
        this->m_model.createdAt = value;
    }

    void SetFiles(ModelVector<PFCloudScriptCloudScriptFileWrapper<Alloc>, Alloc> value)
    {
        m_files = std::move(value);
        this->m_model.files =  m_files.empty() ? nullptr : m_files.data();
        this->m_model.filesCount =  static_cast<uint32_t>(m_files.size());
    }

    void SetIsPublished(bool value)
    {
        this->m_model.isPublished = value;
    }

    void SetRevision(int32_t value)
    {
        this->m_model.revision = value;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.files = m_files.empty() ? nullptr : m_files.data();
    }

    ModelVector<PFCloudScriptCloudScriptFileWrapper<Alloc>, Alloc> m_files;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptCloudScriptVersionStatusWrapper : public ModelWrapper<PFCloudScriptCloudScriptVersionStatus, Alloc>
{
public:
    using ModelType = typename PFCloudScriptCloudScriptVersionStatus;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFCloudScriptCloudScriptVersionStatus, Alloc>::ModelWrapper;

    void SetLatestRevision(int32_t value)
    {
        this->m_model.latestRevision = value;
    }

    void SetPublishedRevision(int32_t value)
    {
        this->m_model.publishedRevision = value;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptGetCloudScriptVersionsResultWrapper : public ModelWrapper<PFCloudScriptGetCloudScriptVersionsResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptGetCloudScriptVersionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptGetCloudScriptVersionsResultWrapper() = default;

    PFCloudScriptGetCloudScriptVersionsResultWrapper(const PFCloudScriptGetCloudScriptVersionsResult& model) :
        ModelWrapper<PFCloudScriptGetCloudScriptVersionsResult, Alloc>{ model },
        m_versions{ model.versions, model.versions + model.versionsCount }
    {
        SetModelPointers();
    }

    PFCloudScriptGetCloudScriptVersionsResultWrapper(const PFCloudScriptGetCloudScriptVersionsResultWrapper& src) :
        PFCloudScriptGetCloudScriptVersionsResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptGetCloudScriptVersionsResultWrapper(PFCloudScriptGetCloudScriptVersionsResultWrapper&& src) :
        PFCloudScriptGetCloudScriptVersionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptGetCloudScriptVersionsResultWrapper& operator=(PFCloudScriptGetCloudScriptVersionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptGetCloudScriptVersionsResultWrapper() = default;

    friend void swap(PFCloudScriptGetCloudScriptVersionsResultWrapper& lhs, PFCloudScriptGetCloudScriptVersionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_versions, rhs.m_versions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetVersions(ModelVector<PFCloudScriptCloudScriptVersionStatusWrapper<Alloc>, Alloc> value)
    {
        m_versions = std::move(value);
        this->m_model.versions =  m_versions.empty() ? nullptr : m_versions.data();
        this->m_model.versionsCount =  static_cast<uint32_t>(m_versions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.versions = m_versions.empty() ? nullptr : m_versions.data();
    }

    ModelVector<PFCloudScriptCloudScriptVersionStatusWrapper<Alloc>, Alloc> m_versions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptSetPublishedRevisionRequestWrapper : public ModelWrapper<PFCloudScriptSetPublishedRevisionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptSetPublishedRevisionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptSetPublishedRevisionRequestWrapper() = default;

    PFCloudScriptSetPublishedRevisionRequestWrapper(const PFCloudScriptSetPublishedRevisionRequest& model) :
        ModelWrapper<PFCloudScriptSetPublishedRevisionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFCloudScriptSetPublishedRevisionRequestWrapper(const PFCloudScriptSetPublishedRevisionRequestWrapper& src) :
        PFCloudScriptSetPublishedRevisionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptSetPublishedRevisionRequestWrapper(PFCloudScriptSetPublishedRevisionRequestWrapper&& src) :
        PFCloudScriptSetPublishedRevisionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptSetPublishedRevisionRequestWrapper& operator=(PFCloudScriptSetPublishedRevisionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptSetPublishedRevisionRequestWrapper() = default;

    friend void swap(PFCloudScriptSetPublishedRevisionRequestWrapper& lhs, PFCloudScriptSetPublishedRevisionRequestWrapper& rhs)
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

    void SetRevision(int32_t value)
    {
        this->m_model.revision = value;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptUpdateCloudScriptRequestWrapper : public ModelWrapper<PFCloudScriptUpdateCloudScriptRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptUpdateCloudScriptRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptUpdateCloudScriptRequestWrapper() = default;

    PFCloudScriptUpdateCloudScriptRequestWrapper(const PFCloudScriptUpdateCloudScriptRequest& model) :
        ModelWrapper<PFCloudScriptUpdateCloudScriptRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_developerPlayFabId{ SafeString(model.developerPlayFabId) },
        m_files{ model.files, model.files + model.filesCount }
    {
        SetModelPointers();
    }

    PFCloudScriptUpdateCloudScriptRequestWrapper(const PFCloudScriptUpdateCloudScriptRequestWrapper& src) :
        PFCloudScriptUpdateCloudScriptRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptUpdateCloudScriptRequestWrapper(PFCloudScriptUpdateCloudScriptRequestWrapper&& src) :
        PFCloudScriptUpdateCloudScriptRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptUpdateCloudScriptRequestWrapper& operator=(PFCloudScriptUpdateCloudScriptRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptUpdateCloudScriptRequestWrapper() = default;

    friend void swap(PFCloudScriptUpdateCloudScriptRequestWrapper& lhs, PFCloudScriptUpdateCloudScriptRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_developerPlayFabId, rhs.m_developerPlayFabId);
        swap(lhs.m_files, rhs.m_files);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDeveloperPlayFabId(String value)
    {
        m_developerPlayFabId = std::move(value);
        this->m_model.developerPlayFabId =  m_developerPlayFabId.empty() ? nullptr : m_developerPlayFabId.data();
    }

    void SetFiles(ModelVector<PFCloudScriptCloudScriptFileWrapper<Alloc>, Alloc> value)
    {
        m_files = std::move(value);
        this->m_model.files =  m_files.empty() ? nullptr : m_files.data();
        this->m_model.filesCount =  static_cast<uint32_t>(m_files.size());
    }

    void SetPublish(bool value)
    {
        this->m_model.publish = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.developerPlayFabId = m_developerPlayFabId.empty() ? nullptr : m_developerPlayFabId.data();
        this->m_model.files = m_files.empty() ? nullptr : m_files.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_developerPlayFabId;
    ModelVector<PFCloudScriptCloudScriptFileWrapper<Alloc>, Alloc> m_files;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptUpdateCloudScriptResultWrapper : public ModelWrapper<PFCloudScriptUpdateCloudScriptResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptUpdateCloudScriptResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFCloudScriptUpdateCloudScriptResult, Alloc>::ModelWrapper;

    void SetRevision(int32_t value)
    {
        this->m_model.revision = value;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptExecuteCloudScriptRequestWrapper : public ModelWrapper<PFCloudScriptExecuteCloudScriptRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptExecuteCloudScriptRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptExecuteCloudScriptRequestWrapper() = default;

    PFCloudScriptExecuteCloudScriptRequestWrapper(const PFCloudScriptExecuteCloudScriptRequest& model) :
        ModelWrapper<PFCloudScriptExecuteCloudScriptRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_functionName{ SafeString(model.functionName) },
        m_functionParameter{ model.functionParameter },
        m_generatePlayStreamEvent{ model.generatePlayStreamEvent ? StdExtra::optional<bool>{ *model.generatePlayStreamEvent } : StdExtra::nullopt },
        m_revisionSelection{ model.revisionSelection ? StdExtra::optional<PFCloudScriptCloudScriptRevisionOption>{ *model.revisionSelection } : StdExtra::nullopt },
        m_specificRevision{ model.specificRevision ? StdExtra::optional<int32_t>{ *model.specificRevision } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptExecuteCloudScriptRequestWrapper(const PFCloudScriptExecuteCloudScriptRequestWrapper& src) :
        PFCloudScriptExecuteCloudScriptRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptExecuteCloudScriptRequestWrapper(PFCloudScriptExecuteCloudScriptRequestWrapper&& src) :
        PFCloudScriptExecuteCloudScriptRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptExecuteCloudScriptRequestWrapper& operator=(PFCloudScriptExecuteCloudScriptRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptExecuteCloudScriptRequestWrapper() = default;

    friend void swap(PFCloudScriptExecuteCloudScriptRequestWrapper& lhs, PFCloudScriptExecuteCloudScriptRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionParameter, rhs.m_functionParameter);
        swap(lhs.m_generatePlayStreamEvent, rhs.m_generatePlayStreamEvent);
        swap(lhs.m_revisionSelection, rhs.m_revisionSelection);
        swap(lhs.m_specificRevision, rhs.m_specificRevision);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionParameter(JsonObject<Alloc> value)
    {
        m_functionParameter = std::move(value);
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    void SetGeneratePlayStreamEvent(StdExtra::optional<bool> value)
    {
        m_generatePlayStreamEvent = std::move(value);
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
    }

    void SetRevisionSelection(StdExtra::optional<PFCloudScriptCloudScriptRevisionOption> value)
    {
        m_revisionSelection = std::move(value);
        this->m_model.revisionSelection = m_revisionSelection ? m_revisionSelection.operator->() : nullptr;
    }

    void SetSpecificRevision(StdExtra::optional<int32_t> value)
    {
        m_specificRevision = std::move(value);
        this->m_model.specificRevision = m_specificRevision ? m_specificRevision.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
        this->m_model.revisionSelection = m_revisionSelection ? m_revisionSelection.operator->() : nullptr;
        this->m_model.specificRevision = m_specificRevision ? m_specificRevision.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_functionName;
    JsonObject<Alloc> m_functionParameter;
    StdExtra::optional<bool> m_generatePlayStreamEvent;
    StdExtra::optional<PFCloudScriptCloudScriptRevisionOption> m_revisionSelection;
    StdExtra::optional<int32_t> m_specificRevision;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptExecuteCloudScriptServerRequestWrapper : public ModelWrapper<PFCloudScriptExecuteCloudScriptServerRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptExecuteCloudScriptServerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptExecuteCloudScriptServerRequestWrapper() = default;

    PFCloudScriptExecuteCloudScriptServerRequestWrapper(const PFCloudScriptExecuteCloudScriptServerRequest& model) :
        ModelWrapper<PFCloudScriptExecuteCloudScriptServerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_functionName{ SafeString(model.functionName) },
        m_functionParameter{ model.functionParameter },
        m_generatePlayStreamEvent{ model.generatePlayStreamEvent ? StdExtra::optional<bool>{ *model.generatePlayStreamEvent } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_revisionSelection{ model.revisionSelection ? StdExtra::optional<PFCloudScriptCloudScriptRevisionOption>{ *model.revisionSelection } : StdExtra::nullopt },
        m_specificRevision{ model.specificRevision ? StdExtra::optional<int32_t>{ *model.specificRevision } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptExecuteCloudScriptServerRequestWrapper(const PFCloudScriptExecuteCloudScriptServerRequestWrapper& src) :
        PFCloudScriptExecuteCloudScriptServerRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptExecuteCloudScriptServerRequestWrapper(PFCloudScriptExecuteCloudScriptServerRequestWrapper&& src) :
        PFCloudScriptExecuteCloudScriptServerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptExecuteCloudScriptServerRequestWrapper& operator=(PFCloudScriptExecuteCloudScriptServerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptExecuteCloudScriptServerRequestWrapper() = default;

    friend void swap(PFCloudScriptExecuteCloudScriptServerRequestWrapper& lhs, PFCloudScriptExecuteCloudScriptServerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionParameter, rhs.m_functionParameter);
        swap(lhs.m_generatePlayStreamEvent, rhs.m_generatePlayStreamEvent);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_revisionSelection, rhs.m_revisionSelection);
        swap(lhs.m_specificRevision, rhs.m_specificRevision);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionParameter(JsonObject<Alloc> value)
    {
        m_functionParameter = std::move(value);
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    void SetGeneratePlayStreamEvent(StdExtra::optional<bool> value)
    {
        m_generatePlayStreamEvent = std::move(value);
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetRevisionSelection(StdExtra::optional<PFCloudScriptCloudScriptRevisionOption> value)
    {
        m_revisionSelection = std::move(value);
        this->m_model.revisionSelection = m_revisionSelection ? m_revisionSelection.operator->() : nullptr;
    }

    void SetSpecificRevision(StdExtra::optional<int32_t> value)
    {
        m_specificRevision = std::move(value);
        this->m_model.specificRevision = m_specificRevision ? m_specificRevision.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.revisionSelection = m_revisionSelection ? m_revisionSelection.operator->() : nullptr;
        this->m_model.specificRevision = m_specificRevision ? m_specificRevision.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_functionName;
    JsonObject<Alloc> m_functionParameter;
    StdExtra::optional<bool> m_generatePlayStreamEvent;
    String m_playFabId;
    StdExtra::optional<PFCloudScriptCloudScriptRevisionOption> m_revisionSelection;
    StdExtra::optional<int32_t> m_specificRevision;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptExecuteEntityCloudScriptRequestWrapper : public ModelWrapper<PFCloudScriptExecuteEntityCloudScriptRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptExecuteEntityCloudScriptRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper() = default;

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper(const PFCloudScriptExecuteEntityCloudScriptRequest& model) :
        ModelWrapper<PFCloudScriptExecuteEntityCloudScriptRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_functionName{ SafeString(model.functionName) },
        m_functionParameter{ model.functionParameter },
        m_generatePlayStreamEvent{ model.generatePlayStreamEvent ? StdExtra::optional<bool>{ *model.generatePlayStreamEvent } : StdExtra::nullopt },
        m_revisionSelection{ model.revisionSelection ? StdExtra::optional<PFCloudScriptCloudScriptRevisionOption>{ *model.revisionSelection } : StdExtra::nullopt },
        m_specificRevision{ model.specificRevision ? StdExtra::optional<int32_t>{ *model.specificRevision } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper(const PFCloudScriptExecuteEntityCloudScriptRequestWrapper& src) :
        PFCloudScriptExecuteEntityCloudScriptRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper(PFCloudScriptExecuteEntityCloudScriptRequestWrapper&& src) :
        PFCloudScriptExecuteEntityCloudScriptRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper& operator=(PFCloudScriptExecuteEntityCloudScriptRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptExecuteEntityCloudScriptRequestWrapper() = default;

    friend void swap(PFCloudScriptExecuteEntityCloudScriptRequestWrapper& lhs, PFCloudScriptExecuteEntityCloudScriptRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionParameter, rhs.m_functionParameter);
        swap(lhs.m_generatePlayStreamEvent, rhs.m_generatePlayStreamEvent);
        swap(lhs.m_revisionSelection, rhs.m_revisionSelection);
        swap(lhs.m_specificRevision, rhs.m_specificRevision);
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

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionParameter(JsonObject<Alloc> value)
    {
        m_functionParameter = std::move(value);
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    void SetGeneratePlayStreamEvent(StdExtra::optional<bool> value)
    {
        m_generatePlayStreamEvent = std::move(value);
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
    }

    void SetRevisionSelection(StdExtra::optional<PFCloudScriptCloudScriptRevisionOption> value)
    {
        m_revisionSelection = std::move(value);
        this->m_model.revisionSelection = m_revisionSelection ? m_revisionSelection.operator->() : nullptr;
    }

    void SetSpecificRevision(StdExtra::optional<int32_t> value)
    {
        m_specificRevision = std::move(value);
        this->m_model.specificRevision = m_specificRevision ? m_specificRevision.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
        this->m_model.revisionSelection = m_revisionSelection ? m_revisionSelection.operator->() : nullptr;
        this->m_model.specificRevision = m_specificRevision ? m_specificRevision.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_functionName;
    JsonObject<Alloc> m_functionParameter;
    StdExtra::optional<bool> m_generatePlayStreamEvent;
    StdExtra::optional<PFCloudScriptCloudScriptRevisionOption> m_revisionSelection;
    StdExtra::optional<int32_t> m_specificRevision;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptExecuteFunctionRequestWrapper : public ModelWrapper<PFCloudScriptExecuteFunctionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptExecuteFunctionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptExecuteFunctionRequestWrapper() = default;

    PFCloudScriptExecuteFunctionRequestWrapper(const PFCloudScriptExecuteFunctionRequest& model) :
        ModelWrapper<PFCloudScriptExecuteFunctionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_functionName{ SafeString(model.functionName) },
        m_functionParameter{ model.functionParameter },
        m_generatePlayStreamEvent{ model.generatePlayStreamEvent ? StdExtra::optional<bool>{ *model.generatePlayStreamEvent } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptExecuteFunctionRequestWrapper(const PFCloudScriptExecuteFunctionRequestWrapper& src) :
        PFCloudScriptExecuteFunctionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptExecuteFunctionRequestWrapper(PFCloudScriptExecuteFunctionRequestWrapper&& src) :
        PFCloudScriptExecuteFunctionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptExecuteFunctionRequestWrapper& operator=(PFCloudScriptExecuteFunctionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptExecuteFunctionRequestWrapper() = default;

    friend void swap(PFCloudScriptExecuteFunctionRequestWrapper& lhs, PFCloudScriptExecuteFunctionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionParameter, rhs.m_functionParameter);
        swap(lhs.m_generatePlayStreamEvent, rhs.m_generatePlayStreamEvent);
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

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionParameter(JsonObject<Alloc> value)
    {
        m_functionParameter = std::move(value);
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
    }

    void SetGeneratePlayStreamEvent(StdExtra::optional<bool> value)
    {
        m_generatePlayStreamEvent = std::move(value);
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionParameter.stringValue = m_functionParameter.stringValue.empty() ? nullptr : m_functionParameter.stringValue.data();
        this->m_model.generatePlayStreamEvent = m_generatePlayStreamEvent ? m_generatePlayStreamEvent.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_functionName;
    JsonObject<Alloc> m_functionParameter;
    StdExtra::optional<bool> m_generatePlayStreamEvent;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptFunctionExecutionErrorWrapper : public ModelWrapper<PFCloudScriptFunctionExecutionError, Alloc>
{
public:
    using ModelType = typename PFCloudScriptFunctionExecutionError;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptFunctionExecutionErrorWrapper() = default;

    PFCloudScriptFunctionExecutionErrorWrapper(const PFCloudScriptFunctionExecutionError& model) :
        ModelWrapper<PFCloudScriptFunctionExecutionError, Alloc>{ model },
        m_error{ SafeString(model.error) },
        m_message{ SafeString(model.message) },
        m_stackTrace{ SafeString(model.stackTrace) }
    {
        SetModelPointers();
    }

    PFCloudScriptFunctionExecutionErrorWrapper(const PFCloudScriptFunctionExecutionErrorWrapper& src) :
        PFCloudScriptFunctionExecutionErrorWrapper{ src.Model() }
    {
    }

    PFCloudScriptFunctionExecutionErrorWrapper(PFCloudScriptFunctionExecutionErrorWrapper&& src) :
        PFCloudScriptFunctionExecutionErrorWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptFunctionExecutionErrorWrapper& operator=(PFCloudScriptFunctionExecutionErrorWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptFunctionExecutionErrorWrapper() = default;

    friend void swap(PFCloudScriptFunctionExecutionErrorWrapper& lhs, PFCloudScriptFunctionExecutionErrorWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_error, rhs.m_error);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_stackTrace, rhs.m_stackTrace);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetError(String value)
    {
        m_error = std::move(value);
        this->m_model.error =  m_error.empty() ? nullptr : m_error.data();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetStackTrace(String value)
    {
        m_stackTrace = std::move(value);
        this->m_model.stackTrace =  m_stackTrace.empty() ? nullptr : m_stackTrace.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.error = m_error.empty() ? nullptr : m_error.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.stackTrace = m_stackTrace.empty() ? nullptr : m_stackTrace.data();
    }

    String m_error;
    String m_message;
    String m_stackTrace;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptExecuteFunctionResultWrapper : public ModelWrapper<PFCloudScriptExecuteFunctionResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptExecuteFunctionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptExecuteFunctionResultWrapper() = default;

    PFCloudScriptExecuteFunctionResultWrapper(const PFCloudScriptExecuteFunctionResult& model) :
        ModelWrapper<PFCloudScriptExecuteFunctionResult, Alloc>{ model },
        m_error{ model.error ? StdExtra::optional<PFCloudScriptFunctionExecutionErrorWrapper<Alloc>>{ *model.error } : StdExtra::nullopt },
        m_functionName{ SafeString(model.functionName) },
        m_functionResult{ model.functionResult },
        m_functionResultTooLarge{ model.functionResultTooLarge ? StdExtra::optional<bool>{ *model.functionResultTooLarge } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptExecuteFunctionResultWrapper(const PFCloudScriptExecuteFunctionResultWrapper& src) :
        PFCloudScriptExecuteFunctionResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptExecuteFunctionResultWrapper(PFCloudScriptExecuteFunctionResultWrapper&& src) :
        PFCloudScriptExecuteFunctionResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptExecuteFunctionResultWrapper& operator=(PFCloudScriptExecuteFunctionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptExecuteFunctionResultWrapper() = default;

    friend void swap(PFCloudScriptExecuteFunctionResultWrapper& lhs, PFCloudScriptExecuteFunctionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_error, rhs.m_error);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionResult, rhs.m_functionResult);
        swap(lhs.m_functionResultTooLarge, rhs.m_functionResultTooLarge);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetError(StdExtra::optional<PFCloudScriptFunctionExecutionErrorWrapper<Alloc>> value)
    {
        m_error = std::move(value);
        this->m_model.error = m_error ? &m_error->Model() : nullptr;
    }

    void SetExecutionTimeMilliseconds(int32_t value)
    {
        this->m_model.executionTimeMilliseconds = value;
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionResult(JsonObject<Alloc> value)
    {
        m_functionResult = std::move(value);
        this->m_model.functionResult.stringValue = m_functionResult.stringValue.empty() ? nullptr : m_functionResult.stringValue.data();
    }

    void SetFunctionResultTooLarge(StdExtra::optional<bool> value)
    {
        m_functionResultTooLarge = std::move(value);
        this->m_model.functionResultTooLarge = m_functionResultTooLarge ? m_functionResultTooLarge.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.error = m_error ?  &m_error->Model() : nullptr;
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionResult.stringValue = m_functionResult.stringValue.empty() ? nullptr : m_functionResult.stringValue.data();
        this->m_model.functionResultTooLarge = m_functionResultTooLarge ? m_functionResultTooLarge.operator->() : nullptr;
    }

    StdExtra::optional<PFCloudScriptFunctionExecutionErrorWrapper<Alloc>> m_error;
    String m_functionName;
    JsonObject<Alloc> m_functionResult;
    StdExtra::optional<bool> m_functionResultTooLarge;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptGetFunctionRequestWrapper : public ModelWrapper<PFCloudScriptGetFunctionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptGetFunctionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptGetFunctionRequestWrapper() = default;

    PFCloudScriptGetFunctionRequestWrapper(const PFCloudScriptGetFunctionRequest& model) :
        ModelWrapper<PFCloudScriptGetFunctionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_functionName{ SafeString(model.functionName) }
    {
        SetModelPointers();
    }

    PFCloudScriptGetFunctionRequestWrapper(const PFCloudScriptGetFunctionRequestWrapper& src) :
        PFCloudScriptGetFunctionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptGetFunctionRequestWrapper(PFCloudScriptGetFunctionRequestWrapper&& src) :
        PFCloudScriptGetFunctionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptGetFunctionRequestWrapper& operator=(PFCloudScriptGetFunctionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptGetFunctionRequestWrapper() = default;

    friend void swap(PFCloudScriptGetFunctionRequestWrapper& lhs, PFCloudScriptGetFunctionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_functionName, rhs.m_functionName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_functionName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptGetFunctionResultWrapper : public ModelWrapper<PFCloudScriptGetFunctionResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptGetFunctionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptGetFunctionResultWrapper() = default;

    PFCloudScriptGetFunctionResultWrapper(const PFCloudScriptGetFunctionResult& model) :
        ModelWrapper<PFCloudScriptGetFunctionResult, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_functionUrl{ SafeString(model.functionUrl) },
        m_queueName{ SafeString(model.queueName) },
        m_triggerType{ SafeString(model.triggerType) }
    {
        SetModelPointers();
    }

    PFCloudScriptGetFunctionResultWrapper(const PFCloudScriptGetFunctionResultWrapper& src) :
        PFCloudScriptGetFunctionResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptGetFunctionResultWrapper(PFCloudScriptGetFunctionResultWrapper&& src) :
        PFCloudScriptGetFunctionResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptGetFunctionResultWrapper& operator=(PFCloudScriptGetFunctionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptGetFunctionResultWrapper() = default;

    friend void swap(PFCloudScriptGetFunctionResultWrapper& lhs, PFCloudScriptGetFunctionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_functionUrl, rhs.m_functionUrl);
        swap(lhs.m_queueName, rhs.m_queueName);
        swap(lhs.m_triggerType, rhs.m_triggerType);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetFunctionUrl(String value)
    {
        m_functionUrl = std::move(value);
        this->m_model.functionUrl =  m_functionUrl.empty() ? nullptr : m_functionUrl.data();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

    void SetTriggerType(String value)
    {
        m_triggerType = std::move(value);
        this->m_model.triggerType =  m_triggerType.empty() ? nullptr : m_triggerType.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.functionUrl = m_functionUrl.empty() ? nullptr : m_functionUrl.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
        this->m_model.triggerType = m_triggerType.empty() ? nullptr : m_triggerType.data();
    }

    String m_connectionString;
    String m_functionUrl;
    String m_queueName;
    String m_triggerType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptListFunctionsRequestWrapper : public ModelWrapper<PFCloudScriptListFunctionsRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptListFunctionsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptListFunctionsRequestWrapper() = default;

    PFCloudScriptListFunctionsRequestWrapper(const PFCloudScriptListFunctionsRequest& model) :
        ModelWrapper<PFCloudScriptListFunctionsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFCloudScriptListFunctionsRequestWrapper(const PFCloudScriptListFunctionsRequestWrapper& src) :
        PFCloudScriptListFunctionsRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptListFunctionsRequestWrapper(PFCloudScriptListFunctionsRequestWrapper&& src) :
        PFCloudScriptListFunctionsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptListFunctionsRequestWrapper& operator=(PFCloudScriptListFunctionsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptListFunctionsRequestWrapper() = default;

    friend void swap(PFCloudScriptListFunctionsRequestWrapper& lhs, PFCloudScriptListFunctionsRequestWrapper& rhs)
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
class PFCloudScriptFunctionModelWrapper : public ModelWrapper<PFCloudScriptFunctionModel, Alloc>
{
public:
    using ModelType = typename PFCloudScriptFunctionModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptFunctionModelWrapper() = default;

    PFCloudScriptFunctionModelWrapper(const PFCloudScriptFunctionModel& model) :
        ModelWrapper<PFCloudScriptFunctionModel, Alloc>{ model },
        m_functionAddress{ SafeString(model.functionAddress) },
        m_functionName{ SafeString(model.functionName) },
        m_triggerType{ SafeString(model.triggerType) }
    {
        SetModelPointers();
    }

    PFCloudScriptFunctionModelWrapper(const PFCloudScriptFunctionModelWrapper& src) :
        PFCloudScriptFunctionModelWrapper{ src.Model() }
    {
    }

    PFCloudScriptFunctionModelWrapper(PFCloudScriptFunctionModelWrapper&& src) :
        PFCloudScriptFunctionModelWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptFunctionModelWrapper& operator=(PFCloudScriptFunctionModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptFunctionModelWrapper() = default;

    friend void swap(PFCloudScriptFunctionModelWrapper& lhs, PFCloudScriptFunctionModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_functionAddress, rhs.m_functionAddress);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_triggerType, rhs.m_triggerType);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFunctionAddress(String value)
    {
        m_functionAddress = std::move(value);
        this->m_model.functionAddress =  m_functionAddress.empty() ? nullptr : m_functionAddress.data();
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetTriggerType(String value)
    {
        m_triggerType = std::move(value);
        this->m_model.triggerType =  m_triggerType.empty() ? nullptr : m_triggerType.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.functionAddress = m_functionAddress.empty() ? nullptr : m_functionAddress.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.triggerType = m_triggerType.empty() ? nullptr : m_triggerType.data();
    }

    String m_functionAddress;
    String m_functionName;
    String m_triggerType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptListFunctionsResultWrapper : public ModelWrapper<PFCloudScriptListFunctionsResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptListFunctionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptListFunctionsResultWrapper() = default;

    PFCloudScriptListFunctionsResultWrapper(const PFCloudScriptListFunctionsResult& model) :
        ModelWrapper<PFCloudScriptListFunctionsResult, Alloc>{ model },
        m_functions{ model.functions, model.functions + model.functionsCount }
    {
        SetModelPointers();
    }

    PFCloudScriptListFunctionsResultWrapper(const PFCloudScriptListFunctionsResultWrapper& src) :
        PFCloudScriptListFunctionsResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptListFunctionsResultWrapper(PFCloudScriptListFunctionsResultWrapper&& src) :
        PFCloudScriptListFunctionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptListFunctionsResultWrapper& operator=(PFCloudScriptListFunctionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptListFunctionsResultWrapper() = default;

    friend void swap(PFCloudScriptListFunctionsResultWrapper& lhs, PFCloudScriptListFunctionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_functions, rhs.m_functions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFunctions(ModelVector<PFCloudScriptFunctionModelWrapper<Alloc>, Alloc> value)
    {
        m_functions = std::move(value);
        this->m_model.functions =  m_functions.empty() ? nullptr : m_functions.data();
        this->m_model.functionsCount =  static_cast<uint32_t>(m_functions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.functions = m_functions.empty() ? nullptr : m_functions.data();
    }

    ModelVector<PFCloudScriptFunctionModelWrapper<Alloc>, Alloc> m_functions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptHttpFunctionModelWrapper : public ModelWrapper<PFCloudScriptHttpFunctionModel, Alloc>
{
public:
    using ModelType = typename PFCloudScriptHttpFunctionModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptHttpFunctionModelWrapper() = default;

    PFCloudScriptHttpFunctionModelWrapper(const PFCloudScriptHttpFunctionModel& model) :
        ModelWrapper<PFCloudScriptHttpFunctionModel, Alloc>{ model },
        m_functionName{ SafeString(model.functionName) },
        m_functionUrl{ SafeString(model.functionUrl) }
    {
        SetModelPointers();
    }

    PFCloudScriptHttpFunctionModelWrapper(const PFCloudScriptHttpFunctionModelWrapper& src) :
        PFCloudScriptHttpFunctionModelWrapper{ src.Model() }
    {
    }

    PFCloudScriptHttpFunctionModelWrapper(PFCloudScriptHttpFunctionModelWrapper&& src) :
        PFCloudScriptHttpFunctionModelWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptHttpFunctionModelWrapper& operator=(PFCloudScriptHttpFunctionModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptHttpFunctionModelWrapper() = default;

    friend void swap(PFCloudScriptHttpFunctionModelWrapper& lhs, PFCloudScriptHttpFunctionModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionUrl, rhs.m_functionUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionUrl(String value)
    {
        m_functionUrl = std::move(value);
        this->m_model.functionUrl =  m_functionUrl.empty() ? nullptr : m_functionUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionUrl = m_functionUrl.empty() ? nullptr : m_functionUrl.data();
    }

    String m_functionName;
    String m_functionUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptListHttpFunctionsResultWrapper : public ModelWrapper<PFCloudScriptListHttpFunctionsResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptListHttpFunctionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptListHttpFunctionsResultWrapper() = default;

    PFCloudScriptListHttpFunctionsResultWrapper(const PFCloudScriptListHttpFunctionsResult& model) :
        ModelWrapper<PFCloudScriptListHttpFunctionsResult, Alloc>{ model },
        m_functions{ model.functions, model.functions + model.functionsCount }
    {
        SetModelPointers();
    }

    PFCloudScriptListHttpFunctionsResultWrapper(const PFCloudScriptListHttpFunctionsResultWrapper& src) :
        PFCloudScriptListHttpFunctionsResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptListHttpFunctionsResultWrapper(PFCloudScriptListHttpFunctionsResultWrapper&& src) :
        PFCloudScriptListHttpFunctionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptListHttpFunctionsResultWrapper& operator=(PFCloudScriptListHttpFunctionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptListHttpFunctionsResultWrapper() = default;

    friend void swap(PFCloudScriptListHttpFunctionsResultWrapper& lhs, PFCloudScriptListHttpFunctionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_functions, rhs.m_functions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFunctions(ModelVector<PFCloudScriptHttpFunctionModelWrapper<Alloc>, Alloc> value)
    {
        m_functions = std::move(value);
        this->m_model.functions =  m_functions.empty() ? nullptr : m_functions.data();
        this->m_model.functionsCount =  static_cast<uint32_t>(m_functions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.functions = m_functions.empty() ? nullptr : m_functions.data();
    }

    ModelVector<PFCloudScriptHttpFunctionModelWrapper<Alloc>, Alloc> m_functions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptQueuedFunctionModelWrapper : public ModelWrapper<PFCloudScriptQueuedFunctionModel, Alloc>
{
public:
    using ModelType = typename PFCloudScriptQueuedFunctionModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptQueuedFunctionModelWrapper() = default;

    PFCloudScriptQueuedFunctionModelWrapper(const PFCloudScriptQueuedFunctionModel& model) :
        ModelWrapper<PFCloudScriptQueuedFunctionModel, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_functionName{ SafeString(model.functionName) },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFCloudScriptQueuedFunctionModelWrapper(const PFCloudScriptQueuedFunctionModelWrapper& src) :
        PFCloudScriptQueuedFunctionModelWrapper{ src.Model() }
    {
    }

    PFCloudScriptQueuedFunctionModelWrapper(PFCloudScriptQueuedFunctionModelWrapper&& src) :
        PFCloudScriptQueuedFunctionModelWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptQueuedFunctionModelWrapper& operator=(PFCloudScriptQueuedFunctionModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptQueuedFunctionModelWrapper() = default;

    friend void swap(PFCloudScriptQueuedFunctionModelWrapper& lhs, PFCloudScriptQueuedFunctionModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    String m_connectionString;
    String m_functionName;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptListQueuedFunctionsResultWrapper : public ModelWrapper<PFCloudScriptListQueuedFunctionsResult, Alloc>
{
public:
    using ModelType = typename PFCloudScriptListQueuedFunctionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptListQueuedFunctionsResultWrapper() = default;

    PFCloudScriptListQueuedFunctionsResultWrapper(const PFCloudScriptListQueuedFunctionsResult& model) :
        ModelWrapper<PFCloudScriptListQueuedFunctionsResult, Alloc>{ model },
        m_functions{ model.functions, model.functions + model.functionsCount }
    {
        SetModelPointers();
    }

    PFCloudScriptListQueuedFunctionsResultWrapper(const PFCloudScriptListQueuedFunctionsResultWrapper& src) :
        PFCloudScriptListQueuedFunctionsResultWrapper{ src.Model() }
    {
    }

    PFCloudScriptListQueuedFunctionsResultWrapper(PFCloudScriptListQueuedFunctionsResultWrapper&& src) :
        PFCloudScriptListQueuedFunctionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptListQueuedFunctionsResultWrapper& operator=(PFCloudScriptListQueuedFunctionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptListQueuedFunctionsResultWrapper() = default;

    friend void swap(PFCloudScriptListQueuedFunctionsResultWrapper& lhs, PFCloudScriptListQueuedFunctionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_functions, rhs.m_functions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFunctions(ModelVector<PFCloudScriptQueuedFunctionModelWrapper<Alloc>, Alloc> value)
    {
        m_functions = std::move(value);
        this->m_model.functions =  m_functions.empty() ? nullptr : m_functions.data();
        this->m_model.functionsCount =  static_cast<uint32_t>(m_functions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.functions = m_functions.empty() ? nullptr : m_functions.data();
    }

    ModelVector<PFCloudScriptQueuedFunctionModelWrapper<Alloc>, Alloc> m_functions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper : public ModelWrapper<PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper() = default;

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper(const PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest& model) :
        ModelWrapper<PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_functionResult{ model.functionResult ? *model.functionResult : decltype(*model.functionResult){} }
    {
        SetModelPointers();
    }

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper(const PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper& src) :
        PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper&& src) :
        PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper& operator=(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper() = default;

    friend void swap(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper& lhs, PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_functionResult, rhs.m_functionResult);
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

    void SetFunctionResult(PFCloudScriptExecuteFunctionResultWrapper<Alloc> value)
    {
        m_functionResult = std::move(value);
        this->m_model.functionResult = &m_functionResult.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
        this->m_model.functionResult = &m_functionResult.Model();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
    PFCloudScriptExecuteFunctionResultWrapper<Alloc> m_functionResult;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper : public ModelWrapper<PFCloudScriptPostFunctionResultForFunctionExecutionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptPostFunctionResultForFunctionExecutionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper() = default;

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper(const PFCloudScriptPostFunctionResultForFunctionExecutionRequest& model) :
        ModelWrapper<PFCloudScriptPostFunctionResultForFunctionExecutionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_functionResult{ model.functionResult ? *model.functionResult : decltype(*model.functionResult){} }
    {
        SetModelPointers();
    }

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper(const PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper& src) :
        PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper(PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper&& src) :
        PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper& operator=(PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper() = default;

    friend void swap(PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper& lhs, PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_functionResult, rhs.m_functionResult);
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

    void SetFunctionResult(PFCloudScriptExecuteFunctionResultWrapper<Alloc> value)
    {
        m_functionResult = std::move(value);
        this->m_model.functionResult = &m_functionResult.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
        this->m_model.functionResult = &m_functionResult.Model();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
    PFCloudScriptExecuteFunctionResultWrapper<Alloc> m_functionResult;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptPlayStreamEventEnvelopeModelWrapper : public ModelWrapper<PFCloudScriptPlayStreamEventEnvelopeModel, Alloc>
{
public:
    using ModelType = typename PFCloudScriptPlayStreamEventEnvelopeModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptPlayStreamEventEnvelopeModelWrapper() = default;

    PFCloudScriptPlayStreamEventEnvelopeModelWrapper(const PFCloudScriptPlayStreamEventEnvelopeModel& model) :
        ModelWrapper<PFCloudScriptPlayStreamEventEnvelopeModel, Alloc>{ model },
        m_entityId{ SafeString(model.entityId) },
        m_entityType{ SafeString(model.entityType) },
        m_eventData{ SafeString(model.eventData) },
        m_eventName{ SafeString(model.eventName) },
        m_eventNamespace{ SafeString(model.eventNamespace) },
        m_eventSettings{ SafeString(model.eventSettings) }
    {
        SetModelPointers();
    }

    PFCloudScriptPlayStreamEventEnvelopeModelWrapper(const PFCloudScriptPlayStreamEventEnvelopeModelWrapper& src) :
        PFCloudScriptPlayStreamEventEnvelopeModelWrapper{ src.Model() }
    {
    }

    PFCloudScriptPlayStreamEventEnvelopeModelWrapper(PFCloudScriptPlayStreamEventEnvelopeModelWrapper&& src) :
        PFCloudScriptPlayStreamEventEnvelopeModelWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptPlayStreamEventEnvelopeModelWrapper& operator=(PFCloudScriptPlayStreamEventEnvelopeModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptPlayStreamEventEnvelopeModelWrapper() = default;

    friend void swap(PFCloudScriptPlayStreamEventEnvelopeModelWrapper& lhs, PFCloudScriptPlayStreamEventEnvelopeModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_entityId, rhs.m_entityId);
        swap(lhs.m_entityType, rhs.m_entityType);
        swap(lhs.m_eventData, rhs.m_eventData);
        swap(lhs.m_eventName, rhs.m_eventName);
        swap(lhs.m_eventNamespace, rhs.m_eventNamespace);
        swap(lhs.m_eventSettings, rhs.m_eventSettings);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEntityId(String value)
    {
        m_entityId = std::move(value);
        this->m_model.entityId =  m_entityId.empty() ? nullptr : m_entityId.data();
    }

    void SetEntityType(String value)
    {
        m_entityType = std::move(value);
        this->m_model.entityType =  m_entityType.empty() ? nullptr : m_entityType.data();
    }

    void SetEventData(String value)
    {
        m_eventData = std::move(value);
        this->m_model.eventData =  m_eventData.empty() ? nullptr : m_eventData.data();
    }

    void SetEventName(String value)
    {
        m_eventName = std::move(value);
        this->m_model.eventName =  m_eventName.empty() ? nullptr : m_eventName.data();
    }

    void SetEventNamespace(String value)
    {
        m_eventNamespace = std::move(value);
        this->m_model.eventNamespace =  m_eventNamespace.empty() ? nullptr : m_eventNamespace.data();
    }

    void SetEventSettings(String value)
    {
        m_eventSettings = std::move(value);
        this->m_model.eventSettings =  m_eventSettings.empty() ? nullptr : m_eventSettings.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.entityId = m_entityId.empty() ? nullptr : m_entityId.data();
        this->m_model.entityType = m_entityType.empty() ? nullptr : m_entityType.data();
        this->m_model.eventData = m_eventData.empty() ? nullptr : m_eventData.data();
        this->m_model.eventName = m_eventName.empty() ? nullptr : m_eventName.data();
        this->m_model.eventNamespace = m_eventNamespace.empty() ? nullptr : m_eventNamespace.data();
        this->m_model.eventSettings = m_eventSettings.empty() ? nullptr : m_eventSettings.data();
    }

    String m_entityId;
    String m_entityType;
    String m_eventData;
    String m_eventName;
    String m_eventNamespace;
    String m_eventSettings;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper : public ModelWrapper<PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper() = default;

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper(const PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest& model) :
        ModelWrapper<PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_functionResult{ model.functionResult ? *model.functionResult : decltype(*model.functionResult){} },
        m_playerProfile{ model.playerProfile ? *model.playerProfile : decltype(*model.playerProfile){} },
        m_playStreamEventEnvelope{ model.playStreamEventEnvelope ? StdExtra::optional<PFCloudScriptPlayStreamEventEnvelopeModelWrapper<Alloc>>{ *model.playStreamEventEnvelope } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper(const PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper& src) :
        PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper(PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper&& src) :
        PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper& operator=(PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper() = default;

    friend void swap(PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper& lhs, PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_functionResult, rhs.m_functionResult);
        swap(lhs.m_playerProfile, rhs.m_playerProfile);
        swap(lhs.m_playStreamEventEnvelope, rhs.m_playStreamEventEnvelope);
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

    void SetFunctionResult(PFCloudScriptExecuteFunctionResultWrapper<Alloc> value)
    {
        m_functionResult = std::move(value);
        this->m_model.functionResult = &m_functionResult.Model();
    }

    void SetPlayerProfile(PFPlayerProfileModelWrapper<Alloc> value)
    {
        m_playerProfile = std::move(value);
        this->m_model.playerProfile = &m_playerProfile.Model();
    }

    void SetPlayStreamEventEnvelope(StdExtra::optional<PFCloudScriptPlayStreamEventEnvelopeModelWrapper<Alloc>> value)
    {
        m_playStreamEventEnvelope = std::move(value);
        this->m_model.playStreamEventEnvelope = m_playStreamEventEnvelope ? &m_playStreamEventEnvelope->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.functionResult = &m_functionResult.Model();
        this->m_model.playerProfile = &m_playerProfile.Model();
        this->m_model.playStreamEventEnvelope = m_playStreamEventEnvelope ?  &m_playStreamEventEnvelope->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    PFCloudScriptExecuteFunctionResultWrapper<Alloc> m_functionResult;
    PFPlayerProfileModelWrapper<Alloc> m_playerProfile;
    StdExtra::optional<PFCloudScriptPlayStreamEventEnvelopeModelWrapper<Alloc>> m_playStreamEventEnvelope;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper : public ModelWrapper<PFCloudScriptPostFunctionResultForScheduledTaskRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptPostFunctionResultForScheduledTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper() = default;

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper(const PFCloudScriptPostFunctionResultForScheduledTaskRequest& model) :
        ModelWrapper<PFCloudScriptPostFunctionResultForScheduledTaskRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} },
        m_functionResult{ model.functionResult ? *model.functionResult : decltype(*model.functionResult){} },
        m_scheduledTaskId{ model.scheduledTaskId ? *model.scheduledTaskId : decltype(*model.scheduledTaskId){} }
    {
        SetModelPointers();
    }

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper(const PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper& src) :
        PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper(PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper&& src) :
        PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper& operator=(PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper() = default;

    friend void swap(PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper& lhs, PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_functionResult, rhs.m_functionResult);
        swap(lhs.m_scheduledTaskId, rhs.m_scheduledTaskId);
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

    void SetFunctionResult(PFCloudScriptExecuteFunctionResultWrapper<Alloc> value)
    {
        m_functionResult = std::move(value);
        this->m_model.functionResult = &m_functionResult.Model();
    }

    void SetScheduledTaskId(PFNameIdentifierWrapper<Alloc> value)
    {
        m_scheduledTaskId = std::move(value);
        this->m_model.scheduledTaskId = &m_scheduledTaskId.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
        this->m_model.functionResult = &m_functionResult.Model();
        this->m_model.scheduledTaskId = &m_scheduledTaskId.Model();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
    PFCloudScriptExecuteFunctionResultWrapper<Alloc> m_functionResult;
    PFNameIdentifierWrapper<Alloc> m_scheduledTaskId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptRegisterHttpFunctionRequestWrapper : public ModelWrapper<PFCloudScriptRegisterHttpFunctionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptRegisterHttpFunctionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptRegisterHttpFunctionRequestWrapper() = default;

    PFCloudScriptRegisterHttpFunctionRequestWrapper(const PFCloudScriptRegisterHttpFunctionRequest& model) :
        ModelWrapper<PFCloudScriptRegisterHttpFunctionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_functionName{ SafeString(model.functionName) },
        m_functionUrl{ SafeString(model.functionUrl) }
    {
        SetModelPointers();
    }

    PFCloudScriptRegisterHttpFunctionRequestWrapper(const PFCloudScriptRegisterHttpFunctionRequestWrapper& src) :
        PFCloudScriptRegisterHttpFunctionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptRegisterHttpFunctionRequestWrapper(PFCloudScriptRegisterHttpFunctionRequestWrapper&& src) :
        PFCloudScriptRegisterHttpFunctionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptRegisterHttpFunctionRequestWrapper& operator=(PFCloudScriptRegisterHttpFunctionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptRegisterHttpFunctionRequestWrapper() = default;

    friend void swap(PFCloudScriptRegisterHttpFunctionRequestWrapper& lhs, PFCloudScriptRegisterHttpFunctionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_functionUrl, rhs.m_functionUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetFunctionUrl(String value)
    {
        m_functionUrl = std::move(value);
        this->m_model.functionUrl =  m_functionUrl.empty() ? nullptr : m_functionUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.functionUrl = m_functionUrl.empty() ? nullptr : m_functionUrl.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_functionName;
    String m_functionUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptRegisterQueuedFunctionRequestWrapper : public ModelWrapper<PFCloudScriptRegisterQueuedFunctionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptRegisterQueuedFunctionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptRegisterQueuedFunctionRequestWrapper() = default;

    PFCloudScriptRegisterQueuedFunctionRequestWrapper(const PFCloudScriptRegisterQueuedFunctionRequest& model) :
        ModelWrapper<PFCloudScriptRegisterQueuedFunctionRequest, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_functionName{ SafeString(model.functionName) },
        m_queueName{ SafeString(model.queueName) }
    {
        SetModelPointers();
    }

    PFCloudScriptRegisterQueuedFunctionRequestWrapper(const PFCloudScriptRegisterQueuedFunctionRequestWrapper& src) :
        PFCloudScriptRegisterQueuedFunctionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptRegisterQueuedFunctionRequestWrapper(PFCloudScriptRegisterQueuedFunctionRequestWrapper&& src) :
        PFCloudScriptRegisterQueuedFunctionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptRegisterQueuedFunctionRequestWrapper& operator=(PFCloudScriptRegisterQueuedFunctionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptRegisterQueuedFunctionRequestWrapper() = default;

    friend void swap(PFCloudScriptRegisterQueuedFunctionRequestWrapper& lhs, PFCloudScriptRegisterQueuedFunctionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_functionName, rhs.m_functionName);
        swap(lhs.m_queueName, rhs.m_queueName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

    void SetQueueName(String value)
    {
        m_queueName = std::move(value);
        this->m_model.queueName =  m_queueName.empty() ? nullptr : m_queueName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
        this->m_model.queueName = m_queueName.empty() ? nullptr : m_queueName.data();
    }

    String m_connectionString;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_functionName;
    String m_queueName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFCloudScriptUnregisterFunctionRequestWrapper : public ModelWrapper<PFCloudScriptUnregisterFunctionRequest, Alloc>
{
public:
    using ModelType = typename PFCloudScriptUnregisterFunctionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFCloudScriptUnregisterFunctionRequestWrapper() = default;

    PFCloudScriptUnregisterFunctionRequestWrapper(const PFCloudScriptUnregisterFunctionRequest& model) :
        ModelWrapper<PFCloudScriptUnregisterFunctionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_functionName{ SafeString(model.functionName) }
    {
        SetModelPointers();
    }

    PFCloudScriptUnregisterFunctionRequestWrapper(const PFCloudScriptUnregisterFunctionRequestWrapper& src) :
        PFCloudScriptUnregisterFunctionRequestWrapper{ src.Model() }
    {
    }

    PFCloudScriptUnregisterFunctionRequestWrapper(PFCloudScriptUnregisterFunctionRequestWrapper&& src) :
        PFCloudScriptUnregisterFunctionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFCloudScriptUnregisterFunctionRequestWrapper& operator=(PFCloudScriptUnregisterFunctionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFCloudScriptUnregisterFunctionRequestWrapper() = default;

    friend void swap(PFCloudScriptUnregisterFunctionRequestWrapper& lhs, PFCloudScriptUnregisterFunctionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_functionName, rhs.m_functionName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_functionName;
};

} // namespace Wrappers
} // namespace PlayFab
