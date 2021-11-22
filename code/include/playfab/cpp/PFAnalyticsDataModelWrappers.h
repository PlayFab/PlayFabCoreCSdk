// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFAnalyticsDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsDeviceInfoRequestWrapper : public ModelWrapper<PFAnalyticsDeviceInfoRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsDeviceInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsDeviceInfoRequestWrapper() = default;

    PFAnalyticsDeviceInfoRequestWrapper(const PFAnalyticsDeviceInfoRequest& model) :
        ModelWrapper<PFAnalyticsDeviceInfoRequest, Alloc>{ model },
        m_info{ model.info }
    {
        SetModelPointers();
    }

    PFAnalyticsDeviceInfoRequestWrapper(const PFAnalyticsDeviceInfoRequestWrapper& src) :
        PFAnalyticsDeviceInfoRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsDeviceInfoRequestWrapper(PFAnalyticsDeviceInfoRequestWrapper&& src) :
        PFAnalyticsDeviceInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsDeviceInfoRequestWrapper& operator=(PFAnalyticsDeviceInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsDeviceInfoRequestWrapper() = default;

    friend void swap(PFAnalyticsDeviceInfoRequestWrapper& lhs, PFAnalyticsDeviceInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_info, rhs.m_info);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetInfo(JsonObject<Alloc> value)
    {
        m_info = std::move(value);
        this->m_model.info.stringValue = m_info.stringValue.empty() ? nullptr : m_info.stringValue.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.info.stringValue = m_info.stringValue.empty() ? nullptr : m_info.stringValue.data();
    }

    JsonObject<Alloc> m_info;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsWriteClientCharacterEventRequestWrapper : public ModelWrapper<PFAnalyticsWriteClientCharacterEventRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsWriteClientCharacterEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsWriteClientCharacterEventRequestWrapper() = default;

    PFAnalyticsWriteClientCharacterEventRequestWrapper(const PFAnalyticsWriteClientCharacterEventRequest& model) :
        ModelWrapper<PFAnalyticsWriteClientCharacterEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAnalyticsWriteClientCharacterEventRequestWrapper(const PFAnalyticsWriteClientCharacterEventRequestWrapper& src) :
        PFAnalyticsWriteClientCharacterEventRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsWriteClientCharacterEventRequestWrapper(PFAnalyticsWriteClientCharacterEventRequestWrapper&& src) :
        PFAnalyticsWriteClientCharacterEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsWriteClientCharacterEventRequestWrapper& operator=(PFAnalyticsWriteClientCharacterEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsWriteClientCharacterEventRequestWrapper() = default;

    friend void swap(PFAnalyticsWriteClientCharacterEventRequestWrapper& lhs, PFAnalyticsWriteClientCharacterEventRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_eventName, rhs.m_eventName);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(JsonObject<Alloc> value)
    {
        m_body = std::move(value);
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEventName(String value)
    {
        m_eventName = std::move(value);
        this->m_model.eventName =  m_eventName.empty() ? nullptr : m_eventName.data();
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.eventName = m_eventName.empty() ? nullptr : m_eventName.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    JsonObject<Alloc> m_body;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_eventName;
    StdExtra::optional<time_t> m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsWriteEventResponseWrapper : public ModelWrapper<PFAnalyticsWriteEventResponse, Alloc>
{
public:
    using ModelType = typename PFAnalyticsWriteEventResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsWriteEventResponseWrapper() = default;

    PFAnalyticsWriteEventResponseWrapper(const PFAnalyticsWriteEventResponse& model) :
        ModelWrapper<PFAnalyticsWriteEventResponse, Alloc>{ model },
        m_eventId{ SafeString(model.eventId) }
    {
        SetModelPointers();
    }

    PFAnalyticsWriteEventResponseWrapper(const PFAnalyticsWriteEventResponseWrapper& src) :
        PFAnalyticsWriteEventResponseWrapper{ src.Model() }
    {
    }

    PFAnalyticsWriteEventResponseWrapper(PFAnalyticsWriteEventResponseWrapper&& src) :
        PFAnalyticsWriteEventResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsWriteEventResponseWrapper& operator=(PFAnalyticsWriteEventResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsWriteEventResponseWrapper() = default;

    friend void swap(PFAnalyticsWriteEventResponseWrapper& lhs, PFAnalyticsWriteEventResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_eventId, rhs.m_eventId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEventId(String value)
    {
        m_eventId = std::move(value);
        this->m_model.eventId =  m_eventId.empty() ? nullptr : m_eventId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.eventId = m_eventId.empty() ? nullptr : m_eventId.data();
    }

    String m_eventId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsWriteClientPlayerEventRequestWrapper : public ModelWrapper<PFAnalyticsWriteClientPlayerEventRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsWriteClientPlayerEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsWriteClientPlayerEventRequestWrapper() = default;

    PFAnalyticsWriteClientPlayerEventRequestWrapper(const PFAnalyticsWriteClientPlayerEventRequest& model) :
        ModelWrapper<PFAnalyticsWriteClientPlayerEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAnalyticsWriteClientPlayerEventRequestWrapper(const PFAnalyticsWriteClientPlayerEventRequestWrapper& src) :
        PFAnalyticsWriteClientPlayerEventRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsWriteClientPlayerEventRequestWrapper(PFAnalyticsWriteClientPlayerEventRequestWrapper&& src) :
        PFAnalyticsWriteClientPlayerEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsWriteClientPlayerEventRequestWrapper& operator=(PFAnalyticsWriteClientPlayerEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsWriteClientPlayerEventRequestWrapper() = default;

    friend void swap(PFAnalyticsWriteClientPlayerEventRequestWrapper& lhs, PFAnalyticsWriteClientPlayerEventRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_eventName, rhs.m_eventName);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(JsonObject<Alloc> value)
    {
        m_body = std::move(value);
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEventName(String value)
    {
        m_eventName = std::move(value);
        this->m_model.eventName =  m_eventName.empty() ? nullptr : m_eventName.data();
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.eventName = m_eventName.empty() ? nullptr : m_eventName.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    JsonObject<Alloc> m_body;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_eventName;
    StdExtra::optional<time_t> m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsWriteTitleEventRequestWrapper : public ModelWrapper<PFAnalyticsWriteTitleEventRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsWriteTitleEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsWriteTitleEventRequestWrapper() = default;

    PFAnalyticsWriteTitleEventRequestWrapper(const PFAnalyticsWriteTitleEventRequest& model) :
        ModelWrapper<PFAnalyticsWriteTitleEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAnalyticsWriteTitleEventRequestWrapper(const PFAnalyticsWriteTitleEventRequestWrapper& src) :
        PFAnalyticsWriteTitleEventRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsWriteTitleEventRequestWrapper(PFAnalyticsWriteTitleEventRequestWrapper&& src) :
        PFAnalyticsWriteTitleEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsWriteTitleEventRequestWrapper& operator=(PFAnalyticsWriteTitleEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsWriteTitleEventRequestWrapper() = default;

    friend void swap(PFAnalyticsWriteTitleEventRequestWrapper& lhs, PFAnalyticsWriteTitleEventRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_eventName, rhs.m_eventName);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(JsonObject<Alloc> value)
    {
        m_body = std::move(value);
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEventName(String value)
    {
        m_eventName = std::move(value);
        this->m_model.eventName =  m_eventName.empty() ? nullptr : m_eventName.data();
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.eventName = m_eventName.empty() ? nullptr : m_eventName.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    JsonObject<Alloc> m_body;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_eventName;
    StdExtra::optional<time_t> m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsWriteServerCharacterEventRequestWrapper : public ModelWrapper<PFAnalyticsWriteServerCharacterEventRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsWriteServerCharacterEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsWriteServerCharacterEventRequestWrapper() = default;

    PFAnalyticsWriteServerCharacterEventRequestWrapper(const PFAnalyticsWriteServerCharacterEventRequest& model) :
        ModelWrapper<PFAnalyticsWriteServerCharacterEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_playFabId{ SafeString(model.playFabId) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAnalyticsWriteServerCharacterEventRequestWrapper(const PFAnalyticsWriteServerCharacterEventRequestWrapper& src) :
        PFAnalyticsWriteServerCharacterEventRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsWriteServerCharacterEventRequestWrapper(PFAnalyticsWriteServerCharacterEventRequestWrapper&& src) :
        PFAnalyticsWriteServerCharacterEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsWriteServerCharacterEventRequestWrapper& operator=(PFAnalyticsWriteServerCharacterEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsWriteServerCharacterEventRequestWrapper() = default;

    friend void swap(PFAnalyticsWriteServerCharacterEventRequestWrapper& lhs, PFAnalyticsWriteServerCharacterEventRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_eventName, rhs.m_eventName);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(JsonObject<Alloc> value)
    {
        m_body = std::move(value);
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEventName(String value)
    {
        m_eventName = std::move(value);
        this->m_model.eventName =  m_eventName.empty() ? nullptr : m_eventName.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.eventName = m_eventName.empty() ? nullptr : m_eventName.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    JsonObject<Alloc> m_body;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_eventName;
    String m_playFabId;
    StdExtra::optional<time_t> m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsWriteServerPlayerEventRequestWrapper : public ModelWrapper<PFAnalyticsWriteServerPlayerEventRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsWriteServerPlayerEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsWriteServerPlayerEventRequestWrapper() = default;

    PFAnalyticsWriteServerPlayerEventRequestWrapper(const PFAnalyticsWriteServerPlayerEventRequest& model) :
        ModelWrapper<PFAnalyticsWriteServerPlayerEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_playFabId{ SafeString(model.playFabId) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAnalyticsWriteServerPlayerEventRequestWrapper(const PFAnalyticsWriteServerPlayerEventRequestWrapper& src) :
        PFAnalyticsWriteServerPlayerEventRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsWriteServerPlayerEventRequestWrapper(PFAnalyticsWriteServerPlayerEventRequestWrapper&& src) :
        PFAnalyticsWriteServerPlayerEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsWriteServerPlayerEventRequestWrapper& operator=(PFAnalyticsWriteServerPlayerEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsWriteServerPlayerEventRequestWrapper() = default;

    friend void swap(PFAnalyticsWriteServerPlayerEventRequestWrapper& lhs, PFAnalyticsWriteServerPlayerEventRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_eventName, rhs.m_eventName);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(JsonObject<Alloc> value)
    {
        m_body = std::move(value);
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEventName(String value)
    {
        m_eventName = std::move(value);
        this->m_model.eventName =  m_eventName.empty() ? nullptr : m_eventName.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.body.stringValue = m_body.stringValue.empty() ? nullptr : m_body.stringValue.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.eventName = m_eventName.empty() ? nullptr : m_eventName.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    JsonObject<Alloc> m_body;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_eventName;
    String m_playFabId;
    StdExtra::optional<time_t> m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsEmptyRequestWrapper : public ModelWrapper<PFAnalyticsInsightsEmptyRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsEmptyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsEmptyRequestWrapper() = default;

    PFAnalyticsInsightsEmptyRequestWrapper(const PFAnalyticsInsightsEmptyRequest& model) :
        ModelWrapper<PFAnalyticsInsightsEmptyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsEmptyRequestWrapper(const PFAnalyticsInsightsEmptyRequestWrapper& src) :
        PFAnalyticsInsightsEmptyRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsEmptyRequestWrapper(PFAnalyticsInsightsEmptyRequestWrapper&& src) :
        PFAnalyticsInsightsEmptyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsEmptyRequestWrapper& operator=(PFAnalyticsInsightsEmptyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsEmptyRequestWrapper() = default;

    friend void swap(PFAnalyticsInsightsEmptyRequestWrapper& lhs, PFAnalyticsInsightsEmptyRequestWrapper& rhs)
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
class PFAnalyticsInsightsPerformanceLevelWrapper : public ModelWrapper<PFAnalyticsInsightsPerformanceLevel, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsPerformanceLevel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFAnalyticsInsightsPerformanceLevel, Alloc>::ModelWrapper;

    void SetActiveEventExports(int32_t value)
    {
        this->m_model.activeEventExports = value;
    }

    void SetCacheSizeMB(int32_t value)
    {
        this->m_model.cacheSizeMB = value;
    }

    void SetConcurrency(int32_t value)
    {
        this->m_model.concurrency = value;
    }

    void SetCreditsPerMinute(double value)
    {
        this->m_model.creditsPerMinute = value;
    }

    void SetEventsPerSecond(int32_t value)
    {
        this->m_model.eventsPerSecond = value;
    }

    void SetLevel(int32_t value)
    {
        this->m_model.level = value;
    }

    void SetMaxMemoryPerQueryMB(int32_t value)
    {
        this->m_model.maxMemoryPerQueryMB = value;
    }

    void SetVirtualCpuCores(int32_t value)
    {
        this->m_model.virtualCpuCores = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsGetLimitsResponseWrapper : public ModelWrapper<PFAnalyticsInsightsGetLimitsResponse, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsGetLimitsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsGetLimitsResponseWrapper() = default;

    PFAnalyticsInsightsGetLimitsResponseWrapper(const PFAnalyticsInsightsGetLimitsResponse& model) :
        ModelWrapper<PFAnalyticsInsightsGetLimitsResponse, Alloc>{ model },
        m_subMeters{ model.subMeters, model.subMeters + model.subMetersCount }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsGetLimitsResponseWrapper(const PFAnalyticsInsightsGetLimitsResponseWrapper& src) :
        PFAnalyticsInsightsGetLimitsResponseWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsGetLimitsResponseWrapper(PFAnalyticsInsightsGetLimitsResponseWrapper&& src) :
        PFAnalyticsInsightsGetLimitsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsGetLimitsResponseWrapper& operator=(PFAnalyticsInsightsGetLimitsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsGetLimitsResponseWrapper() = default;

    friend void swap(PFAnalyticsInsightsGetLimitsResponseWrapper& lhs, PFAnalyticsInsightsGetLimitsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_subMeters, rhs.m_subMeters);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDefaultPerformanceLevel(int32_t value)
    {
        this->m_model.defaultPerformanceLevel = value;
    }

    void SetDefaultStorageRetentionDays(int32_t value)
    {
        this->m_model.defaultStorageRetentionDays = value;
    }

    void SetStorageMaxRetentionDays(int32_t value)
    {
        this->m_model.storageMaxRetentionDays = value;
    }

    void SetStorageMinRetentionDays(int32_t value)
    {
        this->m_model.storageMinRetentionDays = value;
    }

    void SetSubMeters(ModelVector<PFAnalyticsInsightsPerformanceLevelWrapper<Alloc>, Alloc> value)
    {
        m_subMeters = std::move(value);
        this->m_model.subMeters =  m_subMeters.empty() ? nullptr : m_subMeters.data();
        this->m_model.subMetersCount =  static_cast<uint32_t>(m_subMeters.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.subMeters = m_subMeters.empty() ? nullptr : m_subMeters.data();
    }

    ModelVector<PFAnalyticsInsightsPerformanceLevelWrapper<Alloc>, Alloc> m_subMeters;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsGetOperationStatusResponseWrapper : public ModelWrapper<PFAnalyticsInsightsGetOperationStatusResponse, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsGetOperationStatusResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsGetOperationStatusResponseWrapper() = default;

    PFAnalyticsInsightsGetOperationStatusResponseWrapper(const PFAnalyticsInsightsGetOperationStatusResponse& model) :
        ModelWrapper<PFAnalyticsInsightsGetOperationStatusResponse, Alloc>{ model },
        m_message{ SafeString(model.message) },
        m_operationId{ SafeString(model.operationId) },
        m_operationType{ SafeString(model.operationType) },
        m_status{ SafeString(model.status) }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsGetOperationStatusResponseWrapper(const PFAnalyticsInsightsGetOperationStatusResponseWrapper& src) :
        PFAnalyticsInsightsGetOperationStatusResponseWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsGetOperationStatusResponseWrapper(PFAnalyticsInsightsGetOperationStatusResponseWrapper&& src) :
        PFAnalyticsInsightsGetOperationStatusResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsGetOperationStatusResponseWrapper& operator=(PFAnalyticsInsightsGetOperationStatusResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsGetOperationStatusResponseWrapper() = default;

    friend void swap(PFAnalyticsInsightsGetOperationStatusResponseWrapper& lhs, PFAnalyticsInsightsGetOperationStatusResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_operationId, rhs.m_operationId);
        swap(lhs.m_operationType, rhs.m_operationType);
        swap(lhs.m_status, rhs.m_status);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetOperationCompletedTime(time_t value)
    {
        this->m_model.operationCompletedTime = value;
    }

    void SetOperationId(String value)
    {
        m_operationId = std::move(value);
        this->m_model.operationId =  m_operationId.empty() ? nullptr : m_operationId.data();
    }

    void SetOperationLastUpdated(time_t value)
    {
        this->m_model.operationLastUpdated = value;
    }

    void SetOperationStartedTime(time_t value)
    {
        this->m_model.operationStartedTime = value;
    }

    void SetOperationType(String value)
    {
        m_operationType = std::move(value);
        this->m_model.operationType =  m_operationType.empty() ? nullptr : m_operationType.data();
    }

    void SetOperationValue(int32_t value)
    {
        this->m_model.operationValue = value;
    }

    void SetStatus(String value)
    {
        m_status = std::move(value);
        this->m_model.status =  m_status.empty() ? nullptr : m_status.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.operationId = m_operationId.empty() ? nullptr : m_operationId.data();
        this->m_model.operationType = m_operationType.empty() ? nullptr : m_operationType.data();
        this->m_model.status = m_status.empty() ? nullptr : m_status.data();
    }

    String m_message;
    String m_operationId;
    String m_operationType;
    String m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsGetDetailsResponseWrapper : public ModelWrapper<PFAnalyticsInsightsGetDetailsResponse, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsGetDetailsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsGetDetailsResponseWrapper() = default;

    PFAnalyticsInsightsGetDetailsResponseWrapper(const PFAnalyticsInsightsGetDetailsResponse& model) :
        ModelWrapper<PFAnalyticsInsightsGetDetailsResponse, Alloc>{ model },
        m_errorMessage{ SafeString(model.errorMessage) },
        m_limits{ model.limits ? StdExtra::optional<PFAnalyticsInsightsGetLimitsResponseWrapper<Alloc>>{ *model.limits } : StdExtra::nullopt },
        m_pendingOperations{ model.pendingOperations, model.pendingOperations + model.pendingOperationsCount }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsGetDetailsResponseWrapper(const PFAnalyticsInsightsGetDetailsResponseWrapper& src) :
        PFAnalyticsInsightsGetDetailsResponseWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsGetDetailsResponseWrapper(PFAnalyticsInsightsGetDetailsResponseWrapper&& src) :
        PFAnalyticsInsightsGetDetailsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsGetDetailsResponseWrapper& operator=(PFAnalyticsInsightsGetDetailsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsGetDetailsResponseWrapper() = default;

    friend void swap(PFAnalyticsInsightsGetDetailsResponseWrapper& lhs, PFAnalyticsInsightsGetDetailsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_errorMessage, rhs.m_errorMessage);
        swap(lhs.m_limits, rhs.m_limits);
        swap(lhs.m_pendingOperations, rhs.m_pendingOperations);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDataUsageMb(uint32_t value)
    {
        this->m_model.dataUsageMb = value;
    }

    void SetErrorMessage(String value)
    {
        m_errorMessage = std::move(value);
        this->m_model.errorMessage =  m_errorMessage.empty() ? nullptr : m_errorMessage.data();
    }

    void SetLimits(StdExtra::optional<PFAnalyticsInsightsGetLimitsResponseWrapper<Alloc>> value)
    {
        m_limits = std::move(value);
        this->m_model.limits = m_limits ? &m_limits->Model() : nullptr;
    }

    void SetPendingOperations(ModelVector<PFAnalyticsInsightsGetOperationStatusResponseWrapper<Alloc>, Alloc> value)
    {
        m_pendingOperations = std::move(value);
        this->m_model.pendingOperations =  m_pendingOperations.empty() ? nullptr : m_pendingOperations.data();
        this->m_model.pendingOperationsCount =  static_cast<uint32_t>(m_pendingOperations.size());
    }

    void SetPerformanceLevel(int32_t value)
    {
        this->m_model.performanceLevel = value;
    }

    void SetRetentionDays(int32_t value)
    {
        this->m_model.retentionDays = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.errorMessage = m_errorMessage.empty() ? nullptr : m_errorMessage.data();
        this->m_model.limits = m_limits ?  &m_limits->Model() : nullptr;
        this->m_model.pendingOperations = m_pendingOperations.empty() ? nullptr : m_pendingOperations.data();
    }

    String m_errorMessage;
    StdExtra::optional<PFAnalyticsInsightsGetLimitsResponseWrapper<Alloc>> m_limits;
    ModelVector<PFAnalyticsInsightsGetOperationStatusResponseWrapper<Alloc>, Alloc> m_pendingOperations;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsGetOperationStatusRequestWrapper : public ModelWrapper<PFAnalyticsInsightsGetOperationStatusRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsGetOperationStatusRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsGetOperationStatusRequestWrapper() = default;

    PFAnalyticsInsightsGetOperationStatusRequestWrapper(const PFAnalyticsInsightsGetOperationStatusRequest& model) :
        ModelWrapper<PFAnalyticsInsightsGetOperationStatusRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_operationId{ SafeString(model.operationId) }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsGetOperationStatusRequestWrapper(const PFAnalyticsInsightsGetOperationStatusRequestWrapper& src) :
        PFAnalyticsInsightsGetOperationStatusRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsGetOperationStatusRequestWrapper(PFAnalyticsInsightsGetOperationStatusRequestWrapper&& src) :
        PFAnalyticsInsightsGetOperationStatusRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsGetOperationStatusRequestWrapper& operator=(PFAnalyticsInsightsGetOperationStatusRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsGetOperationStatusRequestWrapper() = default;

    friend void swap(PFAnalyticsInsightsGetOperationStatusRequestWrapper& lhs, PFAnalyticsInsightsGetOperationStatusRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_operationId, rhs.m_operationId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetOperationId(String value)
    {
        m_operationId = std::move(value);
        this->m_model.operationId =  m_operationId.empty() ? nullptr : m_operationId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.operationId = m_operationId.empty() ? nullptr : m_operationId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_operationId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsGetPendingOperationsRequestWrapper : public ModelWrapper<PFAnalyticsInsightsGetPendingOperationsRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsGetPendingOperationsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper() = default;

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper(const PFAnalyticsInsightsGetPendingOperationsRequest& model) :
        ModelWrapper<PFAnalyticsInsightsGetPendingOperationsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_operationType{ SafeString(model.operationType) }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper(const PFAnalyticsInsightsGetPendingOperationsRequestWrapper& src) :
        PFAnalyticsInsightsGetPendingOperationsRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper(PFAnalyticsInsightsGetPendingOperationsRequestWrapper&& src) :
        PFAnalyticsInsightsGetPendingOperationsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper& operator=(PFAnalyticsInsightsGetPendingOperationsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsGetPendingOperationsRequestWrapper() = default;

    friend void swap(PFAnalyticsInsightsGetPendingOperationsRequestWrapper& lhs, PFAnalyticsInsightsGetPendingOperationsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_operationType, rhs.m_operationType);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetOperationType(String value)
    {
        m_operationType = std::move(value);
        this->m_model.operationType =  m_operationType.empty() ? nullptr : m_operationType.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.operationType = m_operationType.empty() ? nullptr : m_operationType.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_operationType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsGetPendingOperationsResponseWrapper : public ModelWrapper<PFAnalyticsInsightsGetPendingOperationsResponse, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsGetPendingOperationsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsGetPendingOperationsResponseWrapper() = default;

    PFAnalyticsInsightsGetPendingOperationsResponseWrapper(const PFAnalyticsInsightsGetPendingOperationsResponse& model) :
        ModelWrapper<PFAnalyticsInsightsGetPendingOperationsResponse, Alloc>{ model },
        m_pendingOperations{ model.pendingOperations, model.pendingOperations + model.pendingOperationsCount }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsGetPendingOperationsResponseWrapper(const PFAnalyticsInsightsGetPendingOperationsResponseWrapper& src) :
        PFAnalyticsInsightsGetPendingOperationsResponseWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsGetPendingOperationsResponseWrapper(PFAnalyticsInsightsGetPendingOperationsResponseWrapper&& src) :
        PFAnalyticsInsightsGetPendingOperationsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsGetPendingOperationsResponseWrapper& operator=(PFAnalyticsInsightsGetPendingOperationsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsGetPendingOperationsResponseWrapper() = default;

    friend void swap(PFAnalyticsInsightsGetPendingOperationsResponseWrapper& lhs, PFAnalyticsInsightsGetPendingOperationsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pendingOperations, rhs.m_pendingOperations);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPendingOperations(ModelVector<PFAnalyticsInsightsGetOperationStatusResponseWrapper<Alloc>, Alloc> value)
    {
        m_pendingOperations = std::move(value);
        this->m_model.pendingOperations =  m_pendingOperations.empty() ? nullptr : m_pendingOperations.data();
        this->m_model.pendingOperationsCount =  static_cast<uint32_t>(m_pendingOperations.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.pendingOperations = m_pendingOperations.empty() ? nullptr : m_pendingOperations.data();
    }

    ModelVector<PFAnalyticsInsightsGetOperationStatusResponseWrapper<Alloc>, Alloc> m_pendingOperations;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsSetPerformanceRequestWrapper : public ModelWrapper<PFAnalyticsInsightsSetPerformanceRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsSetPerformanceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsSetPerformanceRequestWrapper() = default;

    PFAnalyticsInsightsSetPerformanceRequestWrapper(const PFAnalyticsInsightsSetPerformanceRequest& model) :
        ModelWrapper<PFAnalyticsInsightsSetPerformanceRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsSetPerformanceRequestWrapper(const PFAnalyticsInsightsSetPerformanceRequestWrapper& src) :
        PFAnalyticsInsightsSetPerformanceRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsSetPerformanceRequestWrapper(PFAnalyticsInsightsSetPerformanceRequestWrapper&& src) :
        PFAnalyticsInsightsSetPerformanceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsSetPerformanceRequestWrapper& operator=(PFAnalyticsInsightsSetPerformanceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsSetPerformanceRequestWrapper() = default;

    friend void swap(PFAnalyticsInsightsSetPerformanceRequestWrapper& lhs, PFAnalyticsInsightsSetPerformanceRequestWrapper& rhs)
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

    void SetPerformanceLevel(int32_t value)
    {
        this->m_model.performanceLevel = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsOperationResponseWrapper : public ModelWrapper<PFAnalyticsInsightsOperationResponse, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsOperationResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsOperationResponseWrapper() = default;

    PFAnalyticsInsightsOperationResponseWrapper(const PFAnalyticsInsightsOperationResponse& model) :
        ModelWrapper<PFAnalyticsInsightsOperationResponse, Alloc>{ model },
        m_message{ SafeString(model.message) },
        m_operationId{ SafeString(model.operationId) },
        m_operationType{ SafeString(model.operationType) }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsOperationResponseWrapper(const PFAnalyticsInsightsOperationResponseWrapper& src) :
        PFAnalyticsInsightsOperationResponseWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsOperationResponseWrapper(PFAnalyticsInsightsOperationResponseWrapper&& src) :
        PFAnalyticsInsightsOperationResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsOperationResponseWrapper& operator=(PFAnalyticsInsightsOperationResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsOperationResponseWrapper() = default;

    friend void swap(PFAnalyticsInsightsOperationResponseWrapper& lhs, PFAnalyticsInsightsOperationResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_operationId, rhs.m_operationId);
        swap(lhs.m_operationType, rhs.m_operationType);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetOperationId(String value)
    {
        m_operationId = std::move(value);
        this->m_model.operationId =  m_operationId.empty() ? nullptr : m_operationId.data();
    }

    void SetOperationType(String value)
    {
        m_operationType = std::move(value);
        this->m_model.operationType =  m_operationType.empty() ? nullptr : m_operationType.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.operationId = m_operationId.empty() ? nullptr : m_operationId.data();
        this->m_model.operationType = m_operationType.empty() ? nullptr : m_operationType.data();
    }

    String m_message;
    String m_operationId;
    String m_operationType;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAnalyticsInsightsSetStorageRetentionRequestWrapper : public ModelWrapper<PFAnalyticsInsightsSetStorageRetentionRequest, Alloc>
{
public:
    using ModelType = typename PFAnalyticsInsightsSetStorageRetentionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper() = default;

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper(const PFAnalyticsInsightsSetStorageRetentionRequest& model) :
        ModelWrapper<PFAnalyticsInsightsSetStorageRetentionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper(const PFAnalyticsInsightsSetStorageRetentionRequestWrapper& src) :
        PFAnalyticsInsightsSetStorageRetentionRequestWrapper{ src.Model() }
    {
    }

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper(PFAnalyticsInsightsSetStorageRetentionRequestWrapper&& src) :
        PFAnalyticsInsightsSetStorageRetentionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper& operator=(PFAnalyticsInsightsSetStorageRetentionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAnalyticsInsightsSetStorageRetentionRequestWrapper() = default;

    friend void swap(PFAnalyticsInsightsSetStorageRetentionRequestWrapper& lhs, PFAnalyticsInsightsSetStorageRetentionRequestWrapper& rhs)
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

    void SetRetentionDays(int32_t value)
    {
        this->m_model.retentionDays = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

} // namespace Wrappers
} // namespace PlayFab
