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

} // namespace Wrappers
} // namespace PlayFab
