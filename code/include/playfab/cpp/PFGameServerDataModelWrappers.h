// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFGameServerDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerAddServerBuildRequestWrapper : public ModelWrapper<PFGameServerAddServerBuildRequest, Alloc>
{
public:
    using ModelType = typename PFGameServerAddServerBuildRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerAddServerBuildRequestWrapper() = default;

    PFGameServerAddServerBuildRequestWrapper(const PFGameServerAddServerBuildRequest& model) :
        ModelWrapper<PFGameServerAddServerBuildRequest, Alloc>{ model },
        m_activeRegions{ model.activeRegions, model.activeRegions + model.activeRegionsCount },
        m_buildId{ SafeString(model.buildId) },
        m_commandLineTemplate{ SafeString(model.commandLineTemplate) },
        m_comment{ SafeString(model.comment) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_executablePath{ SafeString(model.executablePath) }
    {
        SetModelPointers();
    }

    PFGameServerAddServerBuildRequestWrapper(const PFGameServerAddServerBuildRequestWrapper& src) :
        PFGameServerAddServerBuildRequestWrapper{ src.Model() }
    {
    }

    PFGameServerAddServerBuildRequestWrapper(PFGameServerAddServerBuildRequestWrapper&& src) :
        PFGameServerAddServerBuildRequestWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerAddServerBuildRequestWrapper& operator=(PFGameServerAddServerBuildRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerAddServerBuildRequestWrapper() = default;

    friend void swap(PFGameServerAddServerBuildRequestWrapper& lhs, PFGameServerAddServerBuildRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_activeRegions, rhs.m_activeRegions);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_commandLineTemplate, rhs.m_commandLineTemplate);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_executablePath, rhs.m_executablePath);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActiveRegions(Vector<PFRegion> value)
    {
        m_activeRegions = std::move(value);
        this->m_model.activeRegions =  m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.activeRegionsCount =  static_cast<uint32_t>(m_activeRegions.size());
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCommandLineTemplate(String value)
    {
        m_commandLineTemplate = std::move(value);
        this->m_model.commandLineTemplate =  m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
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

    void SetExecutablePath(String value)
    {
        m_executablePath = std::move(value);
        this->m_model.executablePath =  m_executablePath.empty() ? nullptr : m_executablePath.data();
    }

    void SetMaxGamesPerHost(int32_t value)
    {
        this->m_model.maxGamesPerHost = value;
    }

    void SetMinFreeGameSlots(int32_t value)
    {
        this->m_model.minFreeGameSlots = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.activeRegions = m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.commandLineTemplate = m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.executablePath = m_executablePath.empty() ? nullptr : m_executablePath.data();
    }

    Vector<PFRegion> m_activeRegions;
    String m_buildId;
    String m_commandLineTemplate;
    String m_comment;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_executablePath;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerAddServerBuildResultWrapper : public ModelWrapper<PFGameServerAddServerBuildResult, Alloc>
{
public:
    using ModelType = typename PFGameServerAddServerBuildResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerAddServerBuildResultWrapper() = default;

    PFGameServerAddServerBuildResultWrapper(const PFGameServerAddServerBuildResult& model) :
        ModelWrapper<PFGameServerAddServerBuildResult, Alloc>{ model },
        m_activeRegions{ model.activeRegions, model.activeRegions + model.activeRegionsCount },
        m_buildId{ SafeString(model.buildId) },
        m_commandLineTemplate{ SafeString(model.commandLineTemplate) },
        m_comment{ SafeString(model.comment) },
        m_executablePath{ SafeString(model.executablePath) },
        m_status{ model.status ? StdExtra::optional<PFGameServerGameBuildStatus>{ *model.status } : StdExtra::nullopt },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFGameServerAddServerBuildResultWrapper(const PFGameServerAddServerBuildResultWrapper& src) :
        PFGameServerAddServerBuildResultWrapper{ src.Model() }
    {
    }

    PFGameServerAddServerBuildResultWrapper(PFGameServerAddServerBuildResultWrapper&& src) :
        PFGameServerAddServerBuildResultWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerAddServerBuildResultWrapper& operator=(PFGameServerAddServerBuildResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerAddServerBuildResultWrapper() = default;

    friend void swap(PFGameServerAddServerBuildResultWrapper& lhs, PFGameServerAddServerBuildResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_activeRegions, rhs.m_activeRegions);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_commandLineTemplate, rhs.m_commandLineTemplate);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_executablePath, rhs.m_executablePath);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_titleId, rhs.m_titleId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActiveRegions(Vector<PFRegion> value)
    {
        m_activeRegions = std::move(value);
        this->m_model.activeRegions =  m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.activeRegionsCount =  static_cast<uint32_t>(m_activeRegions.size());
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCommandLineTemplate(String value)
    {
        m_commandLineTemplate = std::move(value);
        this->m_model.commandLineTemplate =  m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
    }

    void SetComment(String value)
    {
        m_comment = std::move(value);
        this->m_model.comment =  m_comment.empty() ? nullptr : m_comment.data();
    }

    void SetExecutablePath(String value)
    {
        m_executablePath = std::move(value);
        this->m_model.executablePath =  m_executablePath.empty() ? nullptr : m_executablePath.data();
    }

    void SetMaxGamesPerHost(int32_t value)
    {
        this->m_model.maxGamesPerHost = value;
    }

    void SetMinFreeGameSlots(int32_t value)
    {
        this->m_model.minFreeGameSlots = value;
    }

    void SetStatus(StdExtra::optional<PFGameServerGameBuildStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTimestamp(time_t value)
    {
        this->m_model.timestamp = value;
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.activeRegions = m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.commandLineTemplate = m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.executablePath = m_executablePath.empty() ? nullptr : m_executablePath.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    Vector<PFRegion> m_activeRegions;
    String m_buildId;
    String m_commandLineTemplate;
    String m_comment;
    String m_executablePath;
    StdExtra::optional<PFGameServerGameBuildStatus> m_status;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerGetServerBuildInfoRequestWrapper : public ModelWrapper<PFGameServerGetServerBuildInfoRequest, Alloc>
{
public:
    using ModelType = typename PFGameServerGetServerBuildInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerGetServerBuildInfoRequestWrapper() = default;

    PFGameServerGetServerBuildInfoRequestWrapper(const PFGameServerGetServerBuildInfoRequest& model) :
        ModelWrapper<PFGameServerGetServerBuildInfoRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) }
    {
        SetModelPointers();
    }

    PFGameServerGetServerBuildInfoRequestWrapper(const PFGameServerGetServerBuildInfoRequestWrapper& src) :
        PFGameServerGetServerBuildInfoRequestWrapper{ src.Model() }
    {
    }

    PFGameServerGetServerBuildInfoRequestWrapper(PFGameServerGetServerBuildInfoRequestWrapper&& src) :
        PFGameServerGetServerBuildInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerGetServerBuildInfoRequestWrapper& operator=(PFGameServerGetServerBuildInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerGetServerBuildInfoRequestWrapper() = default;

    friend void swap(PFGameServerGetServerBuildInfoRequestWrapper& lhs, PFGameServerGetServerBuildInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
    }

    String m_buildId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerGetServerBuildInfoResultWrapper : public ModelWrapper<PFGameServerGetServerBuildInfoResult, Alloc>
{
public:
    using ModelType = typename PFGameServerGetServerBuildInfoResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerGetServerBuildInfoResultWrapper() = default;

    PFGameServerGetServerBuildInfoResultWrapper(const PFGameServerGetServerBuildInfoResult& model) :
        ModelWrapper<PFGameServerGetServerBuildInfoResult, Alloc>{ model },
        m_activeRegions{ model.activeRegions, model.activeRegions + model.activeRegionsCount },
        m_buildId{ SafeString(model.buildId) },
        m_comment{ SafeString(model.comment) },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_status{ model.status ? StdExtra::optional<PFGameServerGameBuildStatus>{ *model.status } : StdExtra::nullopt },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFGameServerGetServerBuildInfoResultWrapper(const PFGameServerGetServerBuildInfoResultWrapper& src) :
        PFGameServerGetServerBuildInfoResultWrapper{ src.Model() }
    {
    }

    PFGameServerGetServerBuildInfoResultWrapper(PFGameServerGetServerBuildInfoResultWrapper&& src) :
        PFGameServerGetServerBuildInfoResultWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerGetServerBuildInfoResultWrapper& operator=(PFGameServerGetServerBuildInfoResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerGetServerBuildInfoResultWrapper() = default;

    friend void swap(PFGameServerGetServerBuildInfoResultWrapper& lhs, PFGameServerGetServerBuildInfoResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_activeRegions, rhs.m_activeRegions);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_titleId, rhs.m_titleId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActiveRegions(Vector<PFRegion> value)
    {
        m_activeRegions = std::move(value);
        this->m_model.activeRegions =  m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.activeRegionsCount =  static_cast<uint32_t>(m_activeRegions.size());
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetComment(String value)
    {
        m_comment = std::move(value);
        this->m_model.comment =  m_comment.empty() ? nullptr : m_comment.data();
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetMaxGamesPerHost(int32_t value)
    {
        this->m_model.maxGamesPerHost = value;
    }

    void SetMinFreeGameSlots(int32_t value)
    {
        this->m_model.minFreeGameSlots = value;
    }

    void SetStatus(StdExtra::optional<PFGameServerGameBuildStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTimestamp(time_t value)
    {
        this->m_model.timestamp = value;
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.activeRegions = m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    Vector<PFRegion> m_activeRegions;
    String m_buildId;
    String m_comment;
    String m_errorMessage;
    StdExtra::optional<PFGameServerGameBuildStatus> m_status;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerGetServerBuildUploadURLRequestWrapper : public ModelWrapper<PFGameServerGetServerBuildUploadURLRequest, Alloc>
{
public:
    using ModelType = typename PFGameServerGetServerBuildUploadURLRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerGetServerBuildUploadURLRequestWrapper() = default;

    PFGameServerGetServerBuildUploadURLRequestWrapper(const PFGameServerGetServerBuildUploadURLRequest& model) :
        ModelWrapper<PFGameServerGetServerBuildUploadURLRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) }
    {
        SetModelPointers();
    }

    PFGameServerGetServerBuildUploadURLRequestWrapper(const PFGameServerGetServerBuildUploadURLRequestWrapper& src) :
        PFGameServerGetServerBuildUploadURLRequestWrapper{ src.Model() }
    {
    }

    PFGameServerGetServerBuildUploadURLRequestWrapper(PFGameServerGetServerBuildUploadURLRequestWrapper&& src) :
        PFGameServerGetServerBuildUploadURLRequestWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerGetServerBuildUploadURLRequestWrapper& operator=(PFGameServerGetServerBuildUploadURLRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerGetServerBuildUploadURLRequestWrapper() = default;

    friend void swap(PFGameServerGetServerBuildUploadURLRequestWrapper& lhs, PFGameServerGetServerBuildUploadURLRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
    }

    String m_buildId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerGetServerBuildUploadURLResultWrapper : public ModelWrapper<PFGameServerGetServerBuildUploadURLResult, Alloc>
{
public:
    using ModelType = typename PFGameServerGetServerBuildUploadURLResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerGetServerBuildUploadURLResultWrapper() = default;

    PFGameServerGetServerBuildUploadURLResultWrapper(const PFGameServerGetServerBuildUploadURLResult& model) :
        ModelWrapper<PFGameServerGetServerBuildUploadURLResult, Alloc>{ model },
        m_URL{ SafeString(model.URL) }
    {
        SetModelPointers();
    }

    PFGameServerGetServerBuildUploadURLResultWrapper(const PFGameServerGetServerBuildUploadURLResultWrapper& src) :
        PFGameServerGetServerBuildUploadURLResultWrapper{ src.Model() }
    {
    }

    PFGameServerGetServerBuildUploadURLResultWrapper(PFGameServerGetServerBuildUploadURLResultWrapper&& src) :
        PFGameServerGetServerBuildUploadURLResultWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerGetServerBuildUploadURLResultWrapper& operator=(PFGameServerGetServerBuildUploadURLResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerGetServerBuildUploadURLResultWrapper() = default;

    friend void swap(PFGameServerGetServerBuildUploadURLResultWrapper& lhs, PFGameServerGetServerBuildUploadURLResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_URL, rhs.m_URL);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetURL(String value)
    {
        m_URL = std::move(value);
        this->m_model.URL =  m_URL.empty() ? nullptr : m_URL.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.URL = m_URL.empty() ? nullptr : m_URL.data();
    }

    String m_URL;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerListBuildsResultWrapper : public ModelWrapper<PFGameServerListBuildsResult, Alloc>
{
public:
    using ModelType = typename PFGameServerListBuildsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerListBuildsResultWrapper() = default;

    PFGameServerListBuildsResultWrapper(const PFGameServerListBuildsResult& model) :
        ModelWrapper<PFGameServerListBuildsResult, Alloc>{ model },
        m_builds{ model.builds, model.builds + model.buildsCount }
    {
        SetModelPointers();
    }

    PFGameServerListBuildsResultWrapper(const PFGameServerListBuildsResultWrapper& src) :
        PFGameServerListBuildsResultWrapper{ src.Model() }
    {
    }

    PFGameServerListBuildsResultWrapper(PFGameServerListBuildsResultWrapper&& src) :
        PFGameServerListBuildsResultWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerListBuildsResultWrapper& operator=(PFGameServerListBuildsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerListBuildsResultWrapper() = default;

    friend void swap(PFGameServerListBuildsResultWrapper& lhs, PFGameServerListBuildsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_builds, rhs.m_builds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuilds(ModelVector<PFGameServerGetServerBuildInfoResultWrapper<Alloc>, Alloc> value)
    {
        m_builds = std::move(value);
        this->m_model.builds =  m_builds.empty() ? nullptr : m_builds.data();
        this->m_model.buildsCount =  static_cast<uint32_t>(m_builds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.builds = m_builds.empty() ? nullptr : m_builds.data();
    }

    ModelVector<PFGameServerGetServerBuildInfoResultWrapper<Alloc>, Alloc> m_builds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerModifyServerBuildRequestWrapper : public ModelWrapper<PFGameServerModifyServerBuildRequest, Alloc>
{
public:
    using ModelType = typename PFGameServerModifyServerBuildRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerModifyServerBuildRequestWrapper() = default;

    PFGameServerModifyServerBuildRequestWrapper(const PFGameServerModifyServerBuildRequest& model) :
        ModelWrapper<PFGameServerModifyServerBuildRequest, Alloc>{ model },
        m_activeRegions{ model.activeRegions, model.activeRegions + model.activeRegionsCount },
        m_buildId{ SafeString(model.buildId) },
        m_commandLineTemplate{ SafeString(model.commandLineTemplate) },
        m_comment{ SafeString(model.comment) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_executablePath{ SafeString(model.executablePath) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFGameServerModifyServerBuildRequestWrapper(const PFGameServerModifyServerBuildRequestWrapper& src) :
        PFGameServerModifyServerBuildRequestWrapper{ src.Model() }
    {
    }

    PFGameServerModifyServerBuildRequestWrapper(PFGameServerModifyServerBuildRequestWrapper&& src) :
        PFGameServerModifyServerBuildRequestWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerModifyServerBuildRequestWrapper& operator=(PFGameServerModifyServerBuildRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerModifyServerBuildRequestWrapper() = default;

    friend void swap(PFGameServerModifyServerBuildRequestWrapper& lhs, PFGameServerModifyServerBuildRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_activeRegions, rhs.m_activeRegions);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_commandLineTemplate, rhs.m_commandLineTemplate);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_executablePath, rhs.m_executablePath);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActiveRegions(Vector<PFRegion> value)
    {
        m_activeRegions = std::move(value);
        this->m_model.activeRegions =  m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.activeRegionsCount =  static_cast<uint32_t>(m_activeRegions.size());
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCommandLineTemplate(String value)
    {
        m_commandLineTemplate = std::move(value);
        this->m_model.commandLineTemplate =  m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
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

    void SetExecutablePath(String value)
    {
        m_executablePath = std::move(value);
        this->m_model.executablePath =  m_executablePath.empty() ? nullptr : m_executablePath.data();
    }

    void SetMaxGamesPerHost(int32_t value)
    {
        this->m_model.maxGamesPerHost = value;
    }

    void SetMinFreeGameSlots(int32_t value)
    {
        this->m_model.minFreeGameSlots = value;
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.activeRegions = m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.commandLineTemplate = m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.executablePath = m_executablePath.empty() ? nullptr : m_executablePath.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    Vector<PFRegion> m_activeRegions;
    String m_buildId;
    String m_commandLineTemplate;
    String m_comment;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_executablePath;
    StdExtra::optional<time_t> m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerModifyServerBuildResultWrapper : public ModelWrapper<PFGameServerModifyServerBuildResult, Alloc>
{
public:
    using ModelType = typename PFGameServerModifyServerBuildResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerModifyServerBuildResultWrapper() = default;

    PFGameServerModifyServerBuildResultWrapper(const PFGameServerModifyServerBuildResult& model) :
        ModelWrapper<PFGameServerModifyServerBuildResult, Alloc>{ model },
        m_activeRegions{ model.activeRegions, model.activeRegions + model.activeRegionsCount },
        m_buildId{ SafeString(model.buildId) },
        m_commandLineTemplate{ SafeString(model.commandLineTemplate) },
        m_comment{ SafeString(model.comment) },
        m_executablePath{ SafeString(model.executablePath) },
        m_status{ model.status ? StdExtra::optional<PFGameServerGameBuildStatus>{ *model.status } : StdExtra::nullopt },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFGameServerModifyServerBuildResultWrapper(const PFGameServerModifyServerBuildResultWrapper& src) :
        PFGameServerModifyServerBuildResultWrapper{ src.Model() }
    {
    }

    PFGameServerModifyServerBuildResultWrapper(PFGameServerModifyServerBuildResultWrapper&& src) :
        PFGameServerModifyServerBuildResultWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerModifyServerBuildResultWrapper& operator=(PFGameServerModifyServerBuildResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerModifyServerBuildResultWrapper() = default;

    friend void swap(PFGameServerModifyServerBuildResultWrapper& lhs, PFGameServerModifyServerBuildResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_activeRegions, rhs.m_activeRegions);
        swap(lhs.m_buildId, rhs.m_buildId);
        swap(lhs.m_commandLineTemplate, rhs.m_commandLineTemplate);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_executablePath, rhs.m_executablePath);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_titleId, rhs.m_titleId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActiveRegions(Vector<PFRegion> value)
    {
        m_activeRegions = std::move(value);
        this->m_model.activeRegions =  m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.activeRegionsCount =  static_cast<uint32_t>(m_activeRegions.size());
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

    void SetCommandLineTemplate(String value)
    {
        m_commandLineTemplate = std::move(value);
        this->m_model.commandLineTemplate =  m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
    }

    void SetComment(String value)
    {
        m_comment = std::move(value);
        this->m_model.comment =  m_comment.empty() ? nullptr : m_comment.data();
    }

    void SetExecutablePath(String value)
    {
        m_executablePath = std::move(value);
        this->m_model.executablePath =  m_executablePath.empty() ? nullptr : m_executablePath.data();
    }

    void SetMaxGamesPerHost(int32_t value)
    {
        this->m_model.maxGamesPerHost = value;
    }

    void SetMinFreeGameSlots(int32_t value)
    {
        this->m_model.minFreeGameSlots = value;
    }

    void SetStatus(StdExtra::optional<PFGameServerGameBuildStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTimestamp(time_t value)
    {
        this->m_model.timestamp = value;
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.activeRegions = m_activeRegions.empty() ? nullptr : m_activeRegions.data();
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
        this->m_model.commandLineTemplate = m_commandLineTemplate.empty() ? nullptr : m_commandLineTemplate.data();
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.executablePath = m_executablePath.empty() ? nullptr : m_executablePath.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    Vector<PFRegion> m_activeRegions;
    String m_buildId;
    String m_commandLineTemplate;
    String m_comment;
    String m_executablePath;
    StdExtra::optional<PFGameServerGameBuildStatus> m_status;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFGameServerRemoveServerBuildRequestWrapper : public ModelWrapper<PFGameServerRemoveServerBuildRequest, Alloc>
{
public:
    using ModelType = typename PFGameServerRemoveServerBuildRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFGameServerRemoveServerBuildRequestWrapper() = default;

    PFGameServerRemoveServerBuildRequestWrapper(const PFGameServerRemoveServerBuildRequest& model) :
        ModelWrapper<PFGameServerRemoveServerBuildRequest, Alloc>{ model },
        m_buildId{ SafeString(model.buildId) }
    {
        SetModelPointers();
    }

    PFGameServerRemoveServerBuildRequestWrapper(const PFGameServerRemoveServerBuildRequestWrapper& src) :
        PFGameServerRemoveServerBuildRequestWrapper{ src.Model() }
    {
    }

    PFGameServerRemoveServerBuildRequestWrapper(PFGameServerRemoveServerBuildRequestWrapper&& src) :
        PFGameServerRemoveServerBuildRequestWrapper{}
    {
        swap(*this, src);
    }

    PFGameServerRemoveServerBuildRequestWrapper& operator=(PFGameServerRemoveServerBuildRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFGameServerRemoveServerBuildRequestWrapper() = default;

    friend void swap(PFGameServerRemoveServerBuildRequestWrapper& lhs, PFGameServerRemoveServerBuildRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_buildId, rhs.m_buildId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBuildId(String value)
    {
        m_buildId = std::move(value);
        this->m_model.buildId =  m_buildId.empty() ? nullptr : m_buildId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.buildId = m_buildId.empty() ? nullptr : m_buildId.data();
    }

    String m_buildId;
};

} // namespace Wrappers
} // namespace PlayFab
