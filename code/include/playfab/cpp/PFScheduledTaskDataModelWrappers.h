// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFScheduledTaskDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskAbortTaskInstanceRequestWrapper : public ModelWrapper<PFScheduledTaskAbortTaskInstanceRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskAbortTaskInstanceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskAbortTaskInstanceRequestWrapper() = default;

    PFScheduledTaskAbortTaskInstanceRequestWrapper(const PFScheduledTaskAbortTaskInstanceRequest& model) :
        ModelWrapper<PFScheduledTaskAbortTaskInstanceRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_taskInstanceId{ SafeString(model.taskInstanceId) }
    {
        SetModelPointers();
    }

    PFScheduledTaskAbortTaskInstanceRequestWrapper(const PFScheduledTaskAbortTaskInstanceRequestWrapper& src) :
        PFScheduledTaskAbortTaskInstanceRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskAbortTaskInstanceRequestWrapper(PFScheduledTaskAbortTaskInstanceRequestWrapper&& src) :
        PFScheduledTaskAbortTaskInstanceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskAbortTaskInstanceRequestWrapper& operator=(PFScheduledTaskAbortTaskInstanceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskAbortTaskInstanceRequestWrapper() = default;

    friend void swap(PFScheduledTaskAbortTaskInstanceRequestWrapper& lhs, PFScheduledTaskAbortTaskInstanceRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_taskInstanceId, rhs.m_taskInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetTaskInstanceId(String value)
    {
        m_taskInstanceId = std::move(value);
        this->m_model.taskInstanceId =  m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.taskInstanceId = m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_taskInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper : public ModelWrapper<PFScheduledTaskActionsOnPlayersInSegmentTaskParameter, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskActionsOnPlayersInSegmentTaskParameter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper() = default;

    PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& model) :
        ModelWrapper<PFScheduledTaskActionsOnPlayersInSegmentTaskParameter, Alloc>{ model },
        m_actionId{ SafeString(model.actionId) },
        m_segmentId{ SafeString(model.segmentId) }
    {
        SetModelPointers();
    }

    PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper& src) :
        PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper{ src.Model() }
    {
    }

    PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper(PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper&& src) :
        PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper& operator=(PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper() = default;

    friend void swap(PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper& lhs, PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_actionId, rhs.m_actionId);
        swap(lhs.m_segmentId, rhs.m_segmentId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActionId(String value)
    {
        m_actionId = std::move(value);
        this->m_model.actionId =  m_actionId.empty() ? nullptr : m_actionId.data();
    }

    void SetSegmentId(String value)
    {
        m_segmentId = std::move(value);
        this->m_model.segmentId =  m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.actionId = m_actionId.empty() ? nullptr : m_actionId.data();
        this->m_model.segmentId = m_segmentId.empty() ? nullptr : m_segmentId.data();
    }

    String m_actionId;
    String m_segmentId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper : public ModelWrapper<PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper() = default;

    PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper(const PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest& model) :
        ModelWrapper<PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_name{ SafeString(model.name) },
        m_parameter{ model.parameter ? *model.parameter : decltype(*model.parameter){} },
        m_schedule{ SafeString(model.schedule) }
    {
        SetModelPointers();
    }

    PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper(const PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper& src) :
        PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper(PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper&& src) :
        PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper& operator=(PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper() = default;

    friend void swap(PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper& lhs, PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_schedule, rhs.m_schedule);
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

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetParameter(PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Alloc> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter = &m_parameter.Model();
    }

    void SetSchedule(String value)
    {
        m_schedule = std::move(value);
        this->m_model.schedule =  m_schedule.empty() ? nullptr : m_schedule.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.parameter = &m_parameter.Model();
        this->m_model.schedule = m_schedule.empty() ? nullptr : m_schedule.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    String m_name;
    PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Alloc> m_parameter;
    String m_schedule;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskCreateTaskResultWrapper : public ModelWrapper<PFScheduledTaskCreateTaskResult, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskCreateTaskResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskCreateTaskResultWrapper() = default;

    PFScheduledTaskCreateTaskResultWrapper(const PFScheduledTaskCreateTaskResult& model) :
        ModelWrapper<PFScheduledTaskCreateTaskResult, Alloc>{ model },
        m_taskId{ SafeString(model.taskId) }
    {
        SetModelPointers();
    }

    PFScheduledTaskCreateTaskResultWrapper(const PFScheduledTaskCreateTaskResultWrapper& src) :
        PFScheduledTaskCreateTaskResultWrapper{ src.Model() }
    {
    }

    PFScheduledTaskCreateTaskResultWrapper(PFScheduledTaskCreateTaskResultWrapper&& src) :
        PFScheduledTaskCreateTaskResultWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskCreateTaskResultWrapper& operator=(PFScheduledTaskCreateTaskResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskCreateTaskResultWrapper() = default;

    friend void swap(PFScheduledTaskCreateTaskResultWrapper& lhs, PFScheduledTaskCreateTaskResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_taskId, rhs.m_taskId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTaskId(String value)
    {
        m_taskId = std::move(value);
        this->m_model.taskId =  m_taskId.empty() ? nullptr : m_taskId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.taskId = m_taskId.empty() ? nullptr : m_taskId.data();
    }

    String m_taskId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskCloudScriptTaskParameterWrapper : public ModelWrapper<PFScheduledTaskCloudScriptTaskParameter, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskCloudScriptTaskParameter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskCloudScriptTaskParameterWrapper() = default;

    PFScheduledTaskCloudScriptTaskParameterWrapper(const PFScheduledTaskCloudScriptTaskParameter& model) :
        ModelWrapper<PFScheduledTaskCloudScriptTaskParameter, Alloc>{ model },
        m_argument{ model.argument },
        m_functionName{ SafeString(model.functionName) }
    {
        SetModelPointers();
    }

    PFScheduledTaskCloudScriptTaskParameterWrapper(const PFScheduledTaskCloudScriptTaskParameterWrapper& src) :
        PFScheduledTaskCloudScriptTaskParameterWrapper{ src.Model() }
    {
    }

    PFScheduledTaskCloudScriptTaskParameterWrapper(PFScheduledTaskCloudScriptTaskParameterWrapper&& src) :
        PFScheduledTaskCloudScriptTaskParameterWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskCloudScriptTaskParameterWrapper& operator=(PFScheduledTaskCloudScriptTaskParameterWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskCloudScriptTaskParameterWrapper() = default;

    friend void swap(PFScheduledTaskCloudScriptTaskParameterWrapper& lhs, PFScheduledTaskCloudScriptTaskParameterWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_argument, rhs.m_argument);
        swap(lhs.m_functionName, rhs.m_functionName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetArgument(JsonObject<Alloc> value)
    {
        m_argument = std::move(value);
        this->m_model.argument.stringValue = m_argument.stringValue.empty() ? nullptr : m_argument.stringValue.data();
    }

    void SetFunctionName(String value)
    {
        m_functionName = std::move(value);
        this->m_model.functionName =  m_functionName.empty() ? nullptr : m_functionName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.argument.stringValue = m_argument.stringValue.empty() ? nullptr : m_argument.stringValue.data();
        this->m_model.functionName = m_functionName.empty() ? nullptr : m_functionName.data();
    }

    JsonObject<Alloc> m_argument;
    String m_functionName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskCreateCloudScriptTaskRequestWrapper : public ModelWrapper<PFScheduledTaskCreateCloudScriptTaskRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskCreateCloudScriptTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskCreateCloudScriptTaskRequestWrapper() = default;

    PFScheduledTaskCreateCloudScriptTaskRequestWrapper(const PFScheduledTaskCreateCloudScriptTaskRequest& model) :
        ModelWrapper<PFScheduledTaskCreateCloudScriptTaskRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_name{ SafeString(model.name) },
        m_parameter{ model.parameter ? *model.parameter : decltype(*model.parameter){} },
        m_schedule{ SafeString(model.schedule) }
    {
        SetModelPointers();
    }

    PFScheduledTaskCreateCloudScriptTaskRequestWrapper(const PFScheduledTaskCreateCloudScriptTaskRequestWrapper& src) :
        PFScheduledTaskCreateCloudScriptTaskRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskCreateCloudScriptTaskRequestWrapper(PFScheduledTaskCreateCloudScriptTaskRequestWrapper&& src) :
        PFScheduledTaskCreateCloudScriptTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskCreateCloudScriptTaskRequestWrapper& operator=(PFScheduledTaskCreateCloudScriptTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskCreateCloudScriptTaskRequestWrapper() = default;

    friend void swap(PFScheduledTaskCreateCloudScriptTaskRequestWrapper& lhs, PFScheduledTaskCreateCloudScriptTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_schedule, rhs.m_schedule);
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

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetParameter(PFScheduledTaskCloudScriptTaskParameterWrapper<Alloc> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter = &m_parameter.Model();
    }

    void SetSchedule(String value)
    {
        m_schedule = std::move(value);
        this->m_model.schedule =  m_schedule.empty() ? nullptr : m_schedule.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.parameter = &m_parameter.Model();
        this->m_model.schedule = m_schedule.empty() ? nullptr : m_schedule.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    String m_name;
    PFScheduledTaskCloudScriptTaskParameterWrapper<Alloc> m_parameter;
    String m_schedule;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskInsightsScalingTaskParameterWrapper : public ModelWrapper<PFScheduledTaskInsightsScalingTaskParameter, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskInsightsScalingTaskParameter;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFScheduledTaskInsightsScalingTaskParameter, Alloc>::ModelWrapper;

    void SetLevel(int32_t value)
    {
        this->m_model.level = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper : public ModelWrapper<PFScheduledTaskCreateInsightsScheduledScalingTaskRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskCreateInsightsScheduledScalingTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper() = default;

    PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper(const PFScheduledTaskCreateInsightsScheduledScalingTaskRequest& model) :
        ModelWrapper<PFScheduledTaskCreateInsightsScheduledScalingTaskRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_name{ SafeString(model.name) },
        m_parameter{ model.parameter ? *model.parameter : decltype(*model.parameter){} },
        m_schedule{ SafeString(model.schedule) }
    {
        SetModelPointers();
    }

    PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper(const PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper& src) :
        PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper(PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper&& src) :
        PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper& operator=(PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper() = default;

    friend void swap(PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper& lhs, PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_schedule, rhs.m_schedule);
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

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetParameter(PFScheduledTaskInsightsScalingTaskParameterWrapper<Alloc> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter = &m_parameter.Model();
    }

    void SetSchedule(String value)
    {
        m_schedule = std::move(value);
        this->m_model.schedule =  m_schedule.empty() ? nullptr : m_schedule.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.parameter = &m_parameter.Model();
        this->m_model.schedule = m_schedule.empty() ? nullptr : m_schedule.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    String m_name;
    PFScheduledTaskInsightsScalingTaskParameterWrapper<Alloc> m_parameter;
    String m_schedule;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskDeleteTaskRequestWrapper : public ModelWrapper<PFScheduledTaskDeleteTaskRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskDeleteTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskDeleteTaskRequestWrapper() = default;

    PFScheduledTaskDeleteTaskRequestWrapper(const PFScheduledTaskDeleteTaskRequest& model) :
        ModelWrapper<PFScheduledTaskDeleteTaskRequest, Alloc>{ model },
        m_identifier{ model.identifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.identifier } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskDeleteTaskRequestWrapper(const PFScheduledTaskDeleteTaskRequestWrapper& src) :
        PFScheduledTaskDeleteTaskRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskDeleteTaskRequestWrapper(PFScheduledTaskDeleteTaskRequestWrapper&& src) :
        PFScheduledTaskDeleteTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskDeleteTaskRequestWrapper& operator=(PFScheduledTaskDeleteTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskDeleteTaskRequestWrapper() = default;

    friend void swap(PFScheduledTaskDeleteTaskRequestWrapper& lhs, PFScheduledTaskDeleteTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_identifier, rhs.m_identifier);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_identifier = std::move(value);
        this->m_model.identifier = m_identifier ? &m_identifier->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.identifier = m_identifier ?  &m_identifier->Model() : nullptr;
    }

    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_identifier;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetTaskInstanceRequestWrapper : public ModelWrapper<PFScheduledTaskGetTaskInstanceRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetTaskInstanceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetTaskInstanceRequestWrapper() = default;

    PFScheduledTaskGetTaskInstanceRequestWrapper(const PFScheduledTaskGetTaskInstanceRequest& model) :
        ModelWrapper<PFScheduledTaskGetTaskInstanceRequest, Alloc>{ model },
        m_taskInstanceId{ SafeString(model.taskInstanceId) }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetTaskInstanceRequestWrapper(const PFScheduledTaskGetTaskInstanceRequestWrapper& src) :
        PFScheduledTaskGetTaskInstanceRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetTaskInstanceRequestWrapper(PFScheduledTaskGetTaskInstanceRequestWrapper&& src) :
        PFScheduledTaskGetTaskInstanceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetTaskInstanceRequestWrapper& operator=(PFScheduledTaskGetTaskInstanceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetTaskInstanceRequestWrapper() = default;

    friend void swap(PFScheduledTaskGetTaskInstanceRequestWrapper& lhs, PFScheduledTaskGetTaskInstanceRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_taskInstanceId, rhs.m_taskInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTaskInstanceId(String value)
    {
        m_taskInstanceId = std::move(value);
        this->m_model.taskInstanceId =  m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.taskInstanceId = m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

    String m_taskInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper : public ModelWrapper<PFScheduledTaskActionsOnPlayersInSegmentTaskSummary, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskActionsOnPlayersInSegmentTaskSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper() = default;

    PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper(const PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& model) :
        ModelWrapper<PFScheduledTaskActionsOnPlayersInSegmentTaskSummary, Alloc>{ model },
        m_completedAt{ model.completedAt ? StdExtra::optional<time_t>{ *model.completedAt } : StdExtra::nullopt },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_errorWasFatal{ model.errorWasFatal ? StdExtra::optional<bool>{ *model.errorWasFatal } : StdExtra::nullopt },
        m_estimatedSecondsRemaining{ model.estimatedSecondsRemaining ? StdExtra::optional<double>{ *model.estimatedSecondsRemaining } : StdExtra::nullopt },
        m_percentComplete{ model.percentComplete ? StdExtra::optional<double>{ *model.percentComplete } : StdExtra::nullopt },
        m_scheduledByUserId{ SafeString(model.scheduledByUserId) },
        m_status{ model.status ? StdExtra::optional<PFScheduledTaskTaskInstanceStatus>{ *model.status } : StdExtra::nullopt },
        m_taskIdentifier{ model.taskIdentifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.taskIdentifier } : StdExtra::nullopt },
        m_taskInstanceId{ SafeString(model.taskInstanceId) },
        m_totalPlayersInSegment{ model.totalPlayersInSegment ? StdExtra::optional<int32_t>{ *model.totalPlayersInSegment } : StdExtra::nullopt },
        m_totalPlayersProcessed{ model.totalPlayersProcessed ? StdExtra::optional<int32_t>{ *model.totalPlayersProcessed } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper(const PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper& src) :
        PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper{ src.Model() }
    {
    }

    PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper(PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper&& src) :
        PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper& operator=(PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper() = default;

    friend void swap(PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper& lhs, PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_completedAt, rhs.m_completedAt);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_errorWasFatal, rhs.m_errorWasFatal);
        swap(lhs.m_estimatedSecondsRemaining, rhs.m_estimatedSecondsRemaining);
        swap(lhs.m_percentComplete, rhs.m_percentComplete);
        swap(lhs.m_scheduledByUserId, rhs.m_scheduledByUserId);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_taskIdentifier, rhs.m_taskIdentifier);
        swap(lhs.m_taskInstanceId, rhs.m_taskInstanceId);
        swap(lhs.m_totalPlayersInSegment, rhs.m_totalPlayersInSegment);
        swap(lhs.m_totalPlayersProcessed, rhs.m_totalPlayersProcessed);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCompletedAt(StdExtra::optional<time_t> value)
    {
        m_completedAt = std::move(value);
        this->m_model.completedAt = m_completedAt ? m_completedAt.operator->() : nullptr;
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetErrorWasFatal(StdExtra::optional<bool> value)
    {
        m_errorWasFatal = std::move(value);
        this->m_model.errorWasFatal = m_errorWasFatal ? m_errorWasFatal.operator->() : nullptr;
    }

    void SetEstimatedSecondsRemaining(StdExtra::optional<double> value)
    {
        m_estimatedSecondsRemaining = std::move(value);
        this->m_model.estimatedSecondsRemaining = m_estimatedSecondsRemaining ? m_estimatedSecondsRemaining.operator->() : nullptr;
    }

    void SetPercentComplete(StdExtra::optional<double> value)
    {
        m_percentComplete = std::move(value);
        this->m_model.percentComplete = m_percentComplete ? m_percentComplete.operator->() : nullptr;
    }

    void SetScheduledByUserId(String value)
    {
        m_scheduledByUserId = std::move(value);
        this->m_model.scheduledByUserId =  m_scheduledByUserId.empty() ? nullptr : m_scheduledByUserId.data();
    }

    void SetStartedAt(time_t value)
    {
        this->m_model.startedAt = value;
    }

    void SetStatus(StdExtra::optional<PFScheduledTaskTaskInstanceStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTaskIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_taskIdentifier = std::move(value);
        this->m_model.taskIdentifier = m_taskIdentifier ? &m_taskIdentifier->Model() : nullptr;
    }

    void SetTaskInstanceId(String value)
    {
        m_taskInstanceId = std::move(value);
        this->m_model.taskInstanceId =  m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

    void SetTotalPlayersInSegment(StdExtra::optional<int32_t> value)
    {
        m_totalPlayersInSegment = std::move(value);
        this->m_model.totalPlayersInSegment = m_totalPlayersInSegment ? m_totalPlayersInSegment.operator->() : nullptr;
    }

    void SetTotalPlayersProcessed(StdExtra::optional<int32_t> value)
    {
        m_totalPlayersProcessed = std::move(value);
        this->m_model.totalPlayersProcessed = m_totalPlayersProcessed ? m_totalPlayersProcessed.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.completedAt = m_completedAt ? m_completedAt.operator->() : nullptr;
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.errorWasFatal = m_errorWasFatal ? m_errorWasFatal.operator->() : nullptr;
        this->m_model.estimatedSecondsRemaining = m_estimatedSecondsRemaining ? m_estimatedSecondsRemaining.operator->() : nullptr;
        this->m_model.percentComplete = m_percentComplete ? m_percentComplete.operator->() : nullptr;
        this->m_model.scheduledByUserId = m_scheduledByUserId.empty() ? nullptr : m_scheduledByUserId.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.taskIdentifier = m_taskIdentifier ?  &m_taskIdentifier->Model() : nullptr;
        this->m_model.taskInstanceId = m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
        this->m_model.totalPlayersInSegment = m_totalPlayersInSegment ? m_totalPlayersInSegment.operator->() : nullptr;
        this->m_model.totalPlayersProcessed = m_totalPlayersProcessed ? m_totalPlayersProcessed.operator->() : nullptr;
    }

    StdExtra::optional<time_t> m_completedAt;
    String m_errorMessage;
    StdExtra::optional<bool> m_errorWasFatal;
    StdExtra::optional<double> m_estimatedSecondsRemaining;
    StdExtra::optional<double> m_percentComplete;
    String m_scheduledByUserId;
    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> m_status;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_taskIdentifier;
    String m_taskInstanceId;
    StdExtra::optional<int32_t> m_totalPlayersInSegment;
    StdExtra::optional<int32_t> m_totalPlayersProcessed;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper : public ModelWrapper<PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper() = default;

    PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper(const PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& model) :
        ModelWrapper<PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult, Alloc>{ model },
        m_parameter{ model.parameter ? StdExtra::optional<PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Alloc>>{ *model.parameter } : StdExtra::nullopt },
        m_summary{ model.summary ? StdExtra::optional<PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper<Alloc>>{ *model.summary } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper(const PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper& src) :
        PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper&& src) :
        PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper& operator=(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper() = default;

    friend void swap(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper& lhs, PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_summary, rhs.m_summary);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetParameter(StdExtra::optional<PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Alloc>> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter = m_parameter ? &m_parameter->Model() : nullptr;
    }

    void SetSummary(StdExtra::optional<PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper<Alloc>> value)
    {
        m_summary = std::move(value);
        this->m_model.summary = m_summary ? &m_summary->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.parameter = m_parameter ?  &m_parameter->Model() : nullptr;
        this->m_model.summary = m_summary ?  &m_summary->Model() : nullptr;
    }

    StdExtra::optional<PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Alloc>> m_parameter;
    StdExtra::optional<PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper<Alloc>> m_summary;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskCloudScriptTaskSummaryWrapper : public ModelWrapper<PFScheduledTaskCloudScriptTaskSummary, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskCloudScriptTaskSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskCloudScriptTaskSummaryWrapper() = default;

    PFScheduledTaskCloudScriptTaskSummaryWrapper(const PFScheduledTaskCloudScriptTaskSummary& model) :
        ModelWrapper<PFScheduledTaskCloudScriptTaskSummary, Alloc>{ model },
        m_completedAt{ model.completedAt ? StdExtra::optional<time_t>{ *model.completedAt } : StdExtra::nullopt },
        m_estimatedSecondsRemaining{ model.estimatedSecondsRemaining ? StdExtra::optional<double>{ *model.estimatedSecondsRemaining } : StdExtra::nullopt },
        m_percentComplete{ model.percentComplete ? StdExtra::optional<double>{ *model.percentComplete } : StdExtra::nullopt },
        m_result{ model.result ? StdExtra::optional<PFExecuteCloudScriptResultWrapper<Alloc>>{ *model.result } : StdExtra::nullopt },
        m_scheduledByUserId{ SafeString(model.scheduledByUserId) },
        m_status{ model.status ? StdExtra::optional<PFScheduledTaskTaskInstanceStatus>{ *model.status } : StdExtra::nullopt },
        m_taskIdentifier{ model.taskIdentifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.taskIdentifier } : StdExtra::nullopt },
        m_taskInstanceId{ SafeString(model.taskInstanceId) }
    {
        SetModelPointers();
    }

    PFScheduledTaskCloudScriptTaskSummaryWrapper(const PFScheduledTaskCloudScriptTaskSummaryWrapper& src) :
        PFScheduledTaskCloudScriptTaskSummaryWrapper{ src.Model() }
    {
    }

    PFScheduledTaskCloudScriptTaskSummaryWrapper(PFScheduledTaskCloudScriptTaskSummaryWrapper&& src) :
        PFScheduledTaskCloudScriptTaskSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskCloudScriptTaskSummaryWrapper& operator=(PFScheduledTaskCloudScriptTaskSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskCloudScriptTaskSummaryWrapper() = default;

    friend void swap(PFScheduledTaskCloudScriptTaskSummaryWrapper& lhs, PFScheduledTaskCloudScriptTaskSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_completedAt, rhs.m_completedAt);
        swap(lhs.m_estimatedSecondsRemaining, rhs.m_estimatedSecondsRemaining);
        swap(lhs.m_percentComplete, rhs.m_percentComplete);
        swap(lhs.m_result, rhs.m_result);
        swap(lhs.m_scheduledByUserId, rhs.m_scheduledByUserId);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_taskIdentifier, rhs.m_taskIdentifier);
        swap(lhs.m_taskInstanceId, rhs.m_taskInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCompletedAt(StdExtra::optional<time_t> value)
    {
        m_completedAt = std::move(value);
        this->m_model.completedAt = m_completedAt ? m_completedAt.operator->() : nullptr;
    }

    void SetEstimatedSecondsRemaining(StdExtra::optional<double> value)
    {
        m_estimatedSecondsRemaining = std::move(value);
        this->m_model.estimatedSecondsRemaining = m_estimatedSecondsRemaining ? m_estimatedSecondsRemaining.operator->() : nullptr;
    }

    void SetPercentComplete(StdExtra::optional<double> value)
    {
        m_percentComplete = std::move(value);
        this->m_model.percentComplete = m_percentComplete ? m_percentComplete.operator->() : nullptr;
    }

    void SetResult(StdExtra::optional<PFExecuteCloudScriptResultWrapper<Alloc>> value)
    {
        m_result = std::move(value);
        this->m_model.result = m_result ? &m_result->Model() : nullptr;
    }

    void SetScheduledByUserId(String value)
    {
        m_scheduledByUserId = std::move(value);
        this->m_model.scheduledByUserId =  m_scheduledByUserId.empty() ? nullptr : m_scheduledByUserId.data();
    }

    void SetStartedAt(time_t value)
    {
        this->m_model.startedAt = value;
    }

    void SetStatus(StdExtra::optional<PFScheduledTaskTaskInstanceStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTaskIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_taskIdentifier = std::move(value);
        this->m_model.taskIdentifier = m_taskIdentifier ? &m_taskIdentifier->Model() : nullptr;
    }

    void SetTaskInstanceId(String value)
    {
        m_taskInstanceId = std::move(value);
        this->m_model.taskInstanceId =  m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.completedAt = m_completedAt ? m_completedAt.operator->() : nullptr;
        this->m_model.estimatedSecondsRemaining = m_estimatedSecondsRemaining ? m_estimatedSecondsRemaining.operator->() : nullptr;
        this->m_model.percentComplete = m_percentComplete ? m_percentComplete.operator->() : nullptr;
        this->m_model.result = m_result ?  &m_result->Model() : nullptr;
        this->m_model.scheduledByUserId = m_scheduledByUserId.empty() ? nullptr : m_scheduledByUserId.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.taskIdentifier = m_taskIdentifier ?  &m_taskIdentifier->Model() : nullptr;
        this->m_model.taskInstanceId = m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

    StdExtra::optional<time_t> m_completedAt;
    StdExtra::optional<double> m_estimatedSecondsRemaining;
    StdExtra::optional<double> m_percentComplete;
    StdExtra::optional<PFExecuteCloudScriptResultWrapper<Alloc>> m_result;
    String m_scheduledByUserId;
    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> m_status;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_taskIdentifier;
    String m_taskInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper : public ModelWrapper<PFScheduledTaskGetCloudScriptTaskInstanceResult, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetCloudScriptTaskInstanceResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper() = default;

    PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper(const PFScheduledTaskGetCloudScriptTaskInstanceResult& model) :
        ModelWrapper<PFScheduledTaskGetCloudScriptTaskInstanceResult, Alloc>{ model },
        m_parameter{ model.parameter ? StdExtra::optional<PFScheduledTaskCloudScriptTaskParameterWrapper<Alloc>>{ *model.parameter } : StdExtra::nullopt },
        m_summary{ model.summary ? StdExtra::optional<PFScheduledTaskCloudScriptTaskSummaryWrapper<Alloc>>{ *model.summary } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper(const PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper& src) :
        PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper(PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper&& src) :
        PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper& operator=(PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper() = default;

    friend void swap(PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper& lhs, PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_summary, rhs.m_summary);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetParameter(StdExtra::optional<PFScheduledTaskCloudScriptTaskParameterWrapper<Alloc>> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter = m_parameter ? &m_parameter->Model() : nullptr;
    }

    void SetSummary(StdExtra::optional<PFScheduledTaskCloudScriptTaskSummaryWrapper<Alloc>> value)
    {
        m_summary = std::move(value);
        this->m_model.summary = m_summary ? &m_summary->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.parameter = m_parameter ?  &m_parameter->Model() : nullptr;
        this->m_model.summary = m_summary ?  &m_summary->Model() : nullptr;
    }

    StdExtra::optional<PFScheduledTaskCloudScriptTaskParameterWrapper<Alloc>> m_parameter;
    StdExtra::optional<PFScheduledTaskCloudScriptTaskSummaryWrapper<Alloc>> m_summary;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetTaskInstancesRequestWrapper : public ModelWrapper<PFScheduledTaskGetTaskInstancesRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetTaskInstancesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetTaskInstancesRequestWrapper() = default;

    PFScheduledTaskGetTaskInstancesRequestWrapper(const PFScheduledTaskGetTaskInstancesRequest& model) :
        ModelWrapper<PFScheduledTaskGetTaskInstancesRequest, Alloc>{ model },
        m_startedAtRangeFrom{ model.startedAtRangeFrom ? StdExtra::optional<time_t>{ *model.startedAtRangeFrom } : StdExtra::nullopt },
        m_startedAtRangeTo{ model.startedAtRangeTo ? StdExtra::optional<time_t>{ *model.startedAtRangeTo } : StdExtra::nullopt },
        m_statusFilter{ model.statusFilter ? StdExtra::optional<PFScheduledTaskTaskInstanceStatus>{ *model.statusFilter } : StdExtra::nullopt },
        m_taskIdentifier{ model.taskIdentifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.taskIdentifier } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetTaskInstancesRequestWrapper(const PFScheduledTaskGetTaskInstancesRequestWrapper& src) :
        PFScheduledTaskGetTaskInstancesRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetTaskInstancesRequestWrapper(PFScheduledTaskGetTaskInstancesRequestWrapper&& src) :
        PFScheduledTaskGetTaskInstancesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetTaskInstancesRequestWrapper& operator=(PFScheduledTaskGetTaskInstancesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetTaskInstancesRequestWrapper() = default;

    friend void swap(PFScheduledTaskGetTaskInstancesRequestWrapper& lhs, PFScheduledTaskGetTaskInstancesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_startedAtRangeFrom, rhs.m_startedAtRangeFrom);
        swap(lhs.m_startedAtRangeTo, rhs.m_startedAtRangeTo);
        swap(lhs.m_statusFilter, rhs.m_statusFilter);
        swap(lhs.m_taskIdentifier, rhs.m_taskIdentifier);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStartedAtRangeFrom(StdExtra::optional<time_t> value)
    {
        m_startedAtRangeFrom = std::move(value);
        this->m_model.startedAtRangeFrom = m_startedAtRangeFrom ? m_startedAtRangeFrom.operator->() : nullptr;
    }

    void SetStartedAtRangeTo(StdExtra::optional<time_t> value)
    {
        m_startedAtRangeTo = std::move(value);
        this->m_model.startedAtRangeTo = m_startedAtRangeTo ? m_startedAtRangeTo.operator->() : nullptr;
    }

    void SetStatusFilter(StdExtra::optional<PFScheduledTaskTaskInstanceStatus> value)
    {
        m_statusFilter = std::move(value);
        this->m_model.statusFilter = m_statusFilter ? m_statusFilter.operator->() : nullptr;
    }

    void SetTaskIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_taskIdentifier = std::move(value);
        this->m_model.taskIdentifier = m_taskIdentifier ? &m_taskIdentifier->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.startedAtRangeFrom = m_startedAtRangeFrom ? m_startedAtRangeFrom.operator->() : nullptr;
        this->m_model.startedAtRangeTo = m_startedAtRangeTo ? m_startedAtRangeTo.operator->() : nullptr;
        this->m_model.statusFilter = m_statusFilter ? m_statusFilter.operator->() : nullptr;
        this->m_model.taskIdentifier = m_taskIdentifier ?  &m_taskIdentifier->Model() : nullptr;
    }

    StdExtra::optional<time_t> m_startedAtRangeFrom;
    StdExtra::optional<time_t> m_startedAtRangeTo;
    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> m_statusFilter;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_taskIdentifier;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskTaskInstanceBasicSummaryWrapper : public ModelWrapper<PFScheduledTaskTaskInstanceBasicSummary, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskTaskInstanceBasicSummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskTaskInstanceBasicSummaryWrapper() = default;

    PFScheduledTaskTaskInstanceBasicSummaryWrapper(const PFScheduledTaskTaskInstanceBasicSummary& model) :
        ModelWrapper<PFScheduledTaskTaskInstanceBasicSummary, Alloc>{ model },
        m_completedAt{ model.completedAt ? StdExtra::optional<time_t>{ *model.completedAt } : StdExtra::nullopt },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_estimatedSecondsRemaining{ model.estimatedSecondsRemaining ? StdExtra::optional<double>{ *model.estimatedSecondsRemaining } : StdExtra::nullopt },
        m_percentComplete{ model.percentComplete ? StdExtra::optional<double>{ *model.percentComplete } : StdExtra::nullopt },
        m_scheduledByUserId{ SafeString(model.scheduledByUserId) },
        m_status{ model.status ? StdExtra::optional<PFScheduledTaskTaskInstanceStatus>{ *model.status } : StdExtra::nullopt },
        m_taskIdentifier{ model.taskIdentifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.taskIdentifier } : StdExtra::nullopt },
        m_taskInstanceId{ SafeString(model.taskInstanceId) },
        m_type{ model.type ? StdExtra::optional<PFScheduledTaskScheduledTaskType>{ *model.type } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskTaskInstanceBasicSummaryWrapper(const PFScheduledTaskTaskInstanceBasicSummaryWrapper& src) :
        PFScheduledTaskTaskInstanceBasicSummaryWrapper{ src.Model() }
    {
    }

    PFScheduledTaskTaskInstanceBasicSummaryWrapper(PFScheduledTaskTaskInstanceBasicSummaryWrapper&& src) :
        PFScheduledTaskTaskInstanceBasicSummaryWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskTaskInstanceBasicSummaryWrapper& operator=(PFScheduledTaskTaskInstanceBasicSummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskTaskInstanceBasicSummaryWrapper() = default;

    friend void swap(PFScheduledTaskTaskInstanceBasicSummaryWrapper& lhs, PFScheduledTaskTaskInstanceBasicSummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_completedAt, rhs.m_completedAt);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_estimatedSecondsRemaining, rhs.m_estimatedSecondsRemaining);
        swap(lhs.m_percentComplete, rhs.m_percentComplete);
        swap(lhs.m_scheduledByUserId, rhs.m_scheduledByUserId);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_taskIdentifier, rhs.m_taskIdentifier);
        swap(lhs.m_taskInstanceId, rhs.m_taskInstanceId);
        swap(lhs.m_type, rhs.m_type);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCompletedAt(StdExtra::optional<time_t> value)
    {
        m_completedAt = std::move(value);
        this->m_model.completedAt = m_completedAt ? m_completedAt.operator->() : nullptr;
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetEstimatedSecondsRemaining(StdExtra::optional<double> value)
    {
        m_estimatedSecondsRemaining = std::move(value);
        this->m_model.estimatedSecondsRemaining = m_estimatedSecondsRemaining ? m_estimatedSecondsRemaining.operator->() : nullptr;
    }

    void SetPercentComplete(StdExtra::optional<double> value)
    {
        m_percentComplete = std::move(value);
        this->m_model.percentComplete = m_percentComplete ? m_percentComplete.operator->() : nullptr;
    }

    void SetScheduledByUserId(String value)
    {
        m_scheduledByUserId = std::move(value);
        this->m_model.scheduledByUserId =  m_scheduledByUserId.empty() ? nullptr : m_scheduledByUserId.data();
    }

    void SetStartedAt(time_t value)
    {
        this->m_model.startedAt = value;
    }

    void SetStatus(StdExtra::optional<PFScheduledTaskTaskInstanceStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTaskIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_taskIdentifier = std::move(value);
        this->m_model.taskIdentifier = m_taskIdentifier ? &m_taskIdentifier->Model() : nullptr;
    }

    void SetTaskInstanceId(String value)
    {
        m_taskInstanceId = std::move(value);
        this->m_model.taskInstanceId =  m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

    void SetType(StdExtra::optional<PFScheduledTaskScheduledTaskType> value)
    {
        m_type = std::move(value);
        this->m_model.type = m_type ? m_type.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.completedAt = m_completedAt ? m_completedAt.operator->() : nullptr;
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.estimatedSecondsRemaining = m_estimatedSecondsRemaining ? m_estimatedSecondsRemaining.operator->() : nullptr;
        this->m_model.percentComplete = m_percentComplete ? m_percentComplete.operator->() : nullptr;
        this->m_model.scheduledByUserId = m_scheduledByUserId.empty() ? nullptr : m_scheduledByUserId.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.taskIdentifier = m_taskIdentifier ?  &m_taskIdentifier->Model() : nullptr;
        this->m_model.taskInstanceId = m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
        this->m_model.type = m_type ? m_type.operator->() : nullptr;
    }

    StdExtra::optional<time_t> m_completedAt;
    String m_errorMessage;
    StdExtra::optional<double> m_estimatedSecondsRemaining;
    StdExtra::optional<double> m_percentComplete;
    String m_scheduledByUserId;
    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> m_status;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_taskIdentifier;
    String m_taskInstanceId;
    StdExtra::optional<PFScheduledTaskScheduledTaskType> m_type;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetTaskInstancesResultWrapper : public ModelWrapper<PFScheduledTaskGetTaskInstancesResult, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetTaskInstancesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetTaskInstancesResultWrapper() = default;

    PFScheduledTaskGetTaskInstancesResultWrapper(const PFScheduledTaskGetTaskInstancesResult& model) :
        ModelWrapper<PFScheduledTaskGetTaskInstancesResult, Alloc>{ model },
        m_summaries{ model.summaries, model.summaries + model.summariesCount }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetTaskInstancesResultWrapper(const PFScheduledTaskGetTaskInstancesResultWrapper& src) :
        PFScheduledTaskGetTaskInstancesResultWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetTaskInstancesResultWrapper(PFScheduledTaskGetTaskInstancesResultWrapper&& src) :
        PFScheduledTaskGetTaskInstancesResultWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetTaskInstancesResultWrapper& operator=(PFScheduledTaskGetTaskInstancesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetTaskInstancesResultWrapper() = default;

    friend void swap(PFScheduledTaskGetTaskInstancesResultWrapper& lhs, PFScheduledTaskGetTaskInstancesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_summaries, rhs.m_summaries);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSummaries(ModelVector<PFScheduledTaskTaskInstanceBasicSummaryWrapper<Alloc>, Alloc> value)
    {
        m_summaries = std::move(value);
        this->m_model.summaries =  m_summaries.empty() ? nullptr : m_summaries.data();
        this->m_model.summariesCount =  static_cast<uint32_t>(m_summaries.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.summaries = m_summaries.empty() ? nullptr : m_summaries.data();
    }

    ModelVector<PFScheduledTaskTaskInstanceBasicSummaryWrapper<Alloc>, Alloc> m_summaries;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetTasksRequestWrapper : public ModelWrapper<PFScheduledTaskGetTasksRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetTasksRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetTasksRequestWrapper() = default;

    PFScheduledTaskGetTasksRequestWrapper(const PFScheduledTaskGetTasksRequest& model) :
        ModelWrapper<PFScheduledTaskGetTasksRequest, Alloc>{ model },
        m_identifier{ model.identifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.identifier } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetTasksRequestWrapper(const PFScheduledTaskGetTasksRequestWrapper& src) :
        PFScheduledTaskGetTasksRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetTasksRequestWrapper(PFScheduledTaskGetTasksRequestWrapper&& src) :
        PFScheduledTaskGetTasksRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetTasksRequestWrapper& operator=(PFScheduledTaskGetTasksRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetTasksRequestWrapper() = default;

    friend void swap(PFScheduledTaskGetTasksRequestWrapper& lhs, PFScheduledTaskGetTasksRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_identifier, rhs.m_identifier);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_identifier = std::move(value);
        this->m_model.identifier = m_identifier ? &m_identifier->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.identifier = m_identifier ?  &m_identifier->Model() : nullptr;
    }

    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_identifier;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskScheduledTaskWrapper : public ModelWrapper<PFScheduledTaskScheduledTask, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskScheduledTask;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskScheduledTaskWrapper() = default;

    PFScheduledTaskScheduledTaskWrapper(const PFScheduledTaskScheduledTask& model) :
        ModelWrapper<PFScheduledTaskScheduledTask, Alloc>{ model },
        m_description{ SafeString(model.description) },
        m_lastRunTime{ model.lastRunTime ? StdExtra::optional<time_t>{ *model.lastRunTime } : StdExtra::nullopt },
        m_name{ SafeString(model.name) },
        m_nextRunTime{ model.nextRunTime ? StdExtra::optional<time_t>{ *model.nextRunTime } : StdExtra::nullopt },
        m_parameter{ model.parameter },
        m_schedule{ SafeString(model.schedule) },
        m_taskId{ SafeString(model.taskId) },
        m_type{ model.type ? StdExtra::optional<PFScheduledTaskScheduledTaskType>{ *model.type } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskScheduledTaskWrapper(const PFScheduledTaskScheduledTaskWrapper& src) :
        PFScheduledTaskScheduledTaskWrapper{ src.Model() }
    {
    }

    PFScheduledTaskScheduledTaskWrapper(PFScheduledTaskScheduledTaskWrapper&& src) :
        PFScheduledTaskScheduledTaskWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskScheduledTaskWrapper& operator=(PFScheduledTaskScheduledTaskWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskScheduledTaskWrapper() = default;

    friend void swap(PFScheduledTaskScheduledTaskWrapper& lhs, PFScheduledTaskScheduledTaskWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_lastRunTime, rhs.m_lastRunTime);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_nextRunTime, rhs.m_nextRunTime);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_schedule, rhs.m_schedule);
        swap(lhs.m_taskId, rhs.m_taskId);
        swap(lhs.m_type, rhs.m_type);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetLastRunTime(StdExtra::optional<time_t> value)
    {
        m_lastRunTime = std::move(value);
        this->m_model.lastRunTime = m_lastRunTime ? m_lastRunTime.operator->() : nullptr;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetNextRunTime(StdExtra::optional<time_t> value)
    {
        m_nextRunTime = std::move(value);
        this->m_model.nextRunTime = m_nextRunTime ? m_nextRunTime.operator->() : nullptr;
    }

    void SetParameter(JsonObject<Alloc> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter.stringValue = m_parameter.stringValue.empty() ? nullptr : m_parameter.stringValue.data();
    }

    void SetSchedule(String value)
    {
        m_schedule = std::move(value);
        this->m_model.schedule =  m_schedule.empty() ? nullptr : m_schedule.data();
    }

    void SetTaskId(String value)
    {
        m_taskId = std::move(value);
        this->m_model.taskId =  m_taskId.empty() ? nullptr : m_taskId.data();
    }

    void SetType(StdExtra::optional<PFScheduledTaskScheduledTaskType> value)
    {
        m_type = std::move(value);
        this->m_model.type = m_type ? m_type.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.lastRunTime = m_lastRunTime ? m_lastRunTime.operator->() : nullptr;
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.nextRunTime = m_nextRunTime ? m_nextRunTime.operator->() : nullptr;
        this->m_model.parameter.stringValue = m_parameter.stringValue.empty() ? nullptr : m_parameter.stringValue.data();
        this->m_model.schedule = m_schedule.empty() ? nullptr : m_schedule.data();
        this->m_model.taskId = m_taskId.empty() ? nullptr : m_taskId.data();
        this->m_model.type = m_type ? m_type.operator->() : nullptr;
    }

    String m_description;
    StdExtra::optional<time_t> m_lastRunTime;
    String m_name;
    StdExtra::optional<time_t> m_nextRunTime;
    JsonObject<Alloc> m_parameter;
    String m_schedule;
    String m_taskId;
    StdExtra::optional<PFScheduledTaskScheduledTaskType> m_type;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskGetTasksResultWrapper : public ModelWrapper<PFScheduledTaskGetTasksResult, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskGetTasksResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskGetTasksResultWrapper() = default;

    PFScheduledTaskGetTasksResultWrapper(const PFScheduledTaskGetTasksResult& model) :
        ModelWrapper<PFScheduledTaskGetTasksResult, Alloc>{ model },
        m_tasks{ model.tasks, model.tasks + model.tasksCount }
    {
        SetModelPointers();
    }

    PFScheduledTaskGetTasksResultWrapper(const PFScheduledTaskGetTasksResultWrapper& src) :
        PFScheduledTaskGetTasksResultWrapper{ src.Model() }
    {
    }

    PFScheduledTaskGetTasksResultWrapper(PFScheduledTaskGetTasksResultWrapper&& src) :
        PFScheduledTaskGetTasksResultWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskGetTasksResultWrapper& operator=(PFScheduledTaskGetTasksResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskGetTasksResultWrapper() = default;

    friend void swap(PFScheduledTaskGetTasksResultWrapper& lhs, PFScheduledTaskGetTasksResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_tasks, rhs.m_tasks);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTasks(ModelVector<PFScheduledTaskScheduledTaskWrapper<Alloc>, Alloc> value)
    {
        m_tasks = std::move(value);
        this->m_model.tasks =  m_tasks.empty() ? nullptr : m_tasks.data();
        this->m_model.tasksCount =  static_cast<uint32_t>(m_tasks.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.tasks = m_tasks.empty() ? nullptr : m_tasks.data();
    }

    ModelVector<PFScheduledTaskScheduledTaskWrapper<Alloc>, Alloc> m_tasks;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskRunTaskRequestWrapper : public ModelWrapper<PFScheduledTaskRunTaskRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskRunTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskRunTaskRequestWrapper() = default;

    PFScheduledTaskRunTaskRequestWrapper(const PFScheduledTaskRunTaskRequest& model) :
        ModelWrapper<PFScheduledTaskRunTaskRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_identifier{ model.identifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.identifier } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFScheduledTaskRunTaskRequestWrapper(const PFScheduledTaskRunTaskRequestWrapper& src) :
        PFScheduledTaskRunTaskRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskRunTaskRequestWrapper(PFScheduledTaskRunTaskRequestWrapper&& src) :
        PFScheduledTaskRunTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskRunTaskRequestWrapper& operator=(PFScheduledTaskRunTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskRunTaskRequestWrapper() = default;

    friend void swap(PFScheduledTaskRunTaskRequestWrapper& lhs, PFScheduledTaskRunTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_identifier, rhs.m_identifier);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_identifier = std::move(value);
        this->m_model.identifier = m_identifier ? &m_identifier->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.identifier = m_identifier ?  &m_identifier->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_identifier;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskRunTaskResultWrapper : public ModelWrapper<PFScheduledTaskRunTaskResult, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskRunTaskResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskRunTaskResultWrapper() = default;

    PFScheduledTaskRunTaskResultWrapper(const PFScheduledTaskRunTaskResult& model) :
        ModelWrapper<PFScheduledTaskRunTaskResult, Alloc>{ model },
        m_taskInstanceId{ SafeString(model.taskInstanceId) }
    {
        SetModelPointers();
    }

    PFScheduledTaskRunTaskResultWrapper(const PFScheduledTaskRunTaskResultWrapper& src) :
        PFScheduledTaskRunTaskResultWrapper{ src.Model() }
    {
    }

    PFScheduledTaskRunTaskResultWrapper(PFScheduledTaskRunTaskResultWrapper&& src) :
        PFScheduledTaskRunTaskResultWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskRunTaskResultWrapper& operator=(PFScheduledTaskRunTaskResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskRunTaskResultWrapper() = default;

    friend void swap(PFScheduledTaskRunTaskResultWrapper& lhs, PFScheduledTaskRunTaskResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_taskInstanceId, rhs.m_taskInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTaskInstanceId(String value)
    {
        m_taskInstanceId = std::move(value);
        this->m_model.taskInstanceId =  m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.taskInstanceId = m_taskInstanceId.empty() ? nullptr : m_taskInstanceId.data();
    }

    String m_taskInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFScheduledTaskUpdateTaskRequestWrapper : public ModelWrapper<PFScheduledTaskUpdateTaskRequest, Alloc>
{
public:
    using ModelType = typename PFScheduledTaskUpdateTaskRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFScheduledTaskUpdateTaskRequestWrapper() = default;

    PFScheduledTaskUpdateTaskRequestWrapper(const PFScheduledTaskUpdateTaskRequest& model) :
        ModelWrapper<PFScheduledTaskUpdateTaskRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_description{ SafeString(model.description) },
        m_identifier{ model.identifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.identifier } : StdExtra::nullopt },
        m_name{ SafeString(model.name) },
        m_parameter{ model.parameter },
        m_schedule{ SafeString(model.schedule) }
    {
        SetModelPointers();
    }

    PFScheduledTaskUpdateTaskRequestWrapper(const PFScheduledTaskUpdateTaskRequestWrapper& src) :
        PFScheduledTaskUpdateTaskRequestWrapper{ src.Model() }
    {
    }

    PFScheduledTaskUpdateTaskRequestWrapper(PFScheduledTaskUpdateTaskRequestWrapper&& src) :
        PFScheduledTaskUpdateTaskRequestWrapper{}
    {
        swap(*this, src);
    }

    PFScheduledTaskUpdateTaskRequestWrapper& operator=(PFScheduledTaskUpdateTaskRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFScheduledTaskUpdateTaskRequestWrapper() = default;

    friend void swap(PFScheduledTaskUpdateTaskRequestWrapper& lhs, PFScheduledTaskUpdateTaskRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_identifier, rhs.m_identifier);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_parameter, rhs.m_parameter);
        swap(lhs.m_schedule, rhs.m_schedule);
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

    void SetIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_identifier = std::move(value);
        this->m_model.identifier = m_identifier ? &m_identifier->Model() : nullptr;
    }

    void SetIsActive(bool value)
    {
        this->m_model.isActive = value;
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetParameter(JsonObject<Alloc> value)
    {
        m_parameter = std::move(value);
        this->m_model.parameter.stringValue = m_parameter.stringValue.empty() ? nullptr : m_parameter.stringValue.data();
    }

    void SetSchedule(String value)
    {
        m_schedule = std::move(value);
        this->m_model.schedule =  m_schedule.empty() ? nullptr : m_schedule.data();
    }

    void SetType(PFScheduledTaskScheduledTaskType value)
    {
        this->m_model.type = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.identifier = m_identifier ?  &m_identifier->Model() : nullptr;
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.parameter.stringValue = m_parameter.stringValue.empty() ? nullptr : m_parameter.stringValue.data();
        this->m_model.schedule = m_schedule.empty() ? nullptr : m_schedule.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_description;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_identifier;
    String m_name;
    JsonObject<Alloc> m_parameter;
    String m_schedule;
};

} // namespace Wrappers
} // namespace PlayFab
