// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFEventsDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsAddPlayerTagRequestWrapper : public ModelWrapper<PFEventsAddPlayerTagRequest, Alloc>
{
public:
    using ModelType = typename PFEventsAddPlayerTagRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsAddPlayerTagRequestWrapper() = default;

    PFEventsAddPlayerTagRequestWrapper(const PFEventsAddPlayerTagRequest& model) :
        ModelWrapper<PFEventsAddPlayerTagRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_tagName{ SafeString(model.tagName) }
    {
        SetModelPointers();
    }

    PFEventsAddPlayerTagRequestWrapper(const PFEventsAddPlayerTagRequestWrapper& src) :
        PFEventsAddPlayerTagRequestWrapper{ src.Model() }
    {
    }

    PFEventsAddPlayerTagRequestWrapper(PFEventsAddPlayerTagRequestWrapper&& src) :
        PFEventsAddPlayerTagRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsAddPlayerTagRequestWrapper& operator=(PFEventsAddPlayerTagRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsAddPlayerTagRequestWrapper() = default;

    friend void swap(PFEventsAddPlayerTagRequestWrapper& lhs, PFEventsAddPlayerTagRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_tagName, rhs.m_tagName);
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

    void SetTagName(String value)
    {
        m_tagName = std::move(value);
        this->m_model.tagName =  m_tagName.empty() ? nullptr : m_tagName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.tagName = m_tagName.empty() ? nullptr : m_tagName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_tagName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsGetPlayerTagsRequestWrapper : public ModelWrapper<PFEventsGetPlayerTagsRequest, Alloc>
{
public:
    using ModelType = typename PFEventsGetPlayerTagsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsGetPlayerTagsRequestWrapper() = default;

    PFEventsGetPlayerTagsRequestWrapper(const PFEventsGetPlayerTagsRequest& model) :
        ModelWrapper<PFEventsGetPlayerTagsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playfabNamespace{ SafeString(model.playfabNamespace) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFEventsGetPlayerTagsRequestWrapper(const PFEventsGetPlayerTagsRequestWrapper& src) :
        PFEventsGetPlayerTagsRequestWrapper{ src.Model() }
    {
    }

    PFEventsGetPlayerTagsRequestWrapper(PFEventsGetPlayerTagsRequestWrapper&& src) :
        PFEventsGetPlayerTagsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsGetPlayerTagsRequestWrapper& operator=(PFEventsGetPlayerTagsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsGetPlayerTagsRequestWrapper() = default;

    friend void swap(PFEventsGetPlayerTagsRequestWrapper& lhs, PFEventsGetPlayerTagsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playfabNamespace, rhs.m_playfabNamespace);
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

    void SetplayfabNamespace(String value)
    {
        m_playfabNamespace = std::move(value);
        this->m_model.playfabNamespace =  m_playfabNamespace.empty() ? nullptr : m_playfabNamespace.data();
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
        this->m_model.playfabNamespace = m_playfabNamespace.empty() ? nullptr : m_playfabNamespace.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playfabNamespace;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsGetPlayerTagsResultWrapper : public ModelWrapper<PFEventsGetPlayerTagsResult, Alloc>
{
public:
    using ModelType = typename PFEventsGetPlayerTagsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsGetPlayerTagsResultWrapper() = default;

    PFEventsGetPlayerTagsResultWrapper(const PFEventsGetPlayerTagsResult& model) :
        ModelWrapper<PFEventsGetPlayerTagsResult, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_tags{ model.tags, model.tags + model.tagsCount }
    {
        SetModelPointers();
    }

    PFEventsGetPlayerTagsResultWrapper(const PFEventsGetPlayerTagsResultWrapper& src) :
        PFEventsGetPlayerTagsResultWrapper{ src.Model() }
    {
    }

    PFEventsGetPlayerTagsResultWrapper(PFEventsGetPlayerTagsResultWrapper&& src) :
        PFEventsGetPlayerTagsResultWrapper{}
    {
        swap(*this, src);
    }

    PFEventsGetPlayerTagsResultWrapper& operator=(PFEventsGetPlayerTagsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsGetPlayerTagsResultWrapper() = default;

    friend void swap(PFEventsGetPlayerTagsResultWrapper& lhs, PFEventsGetPlayerTagsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_tags, rhs.m_tags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
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
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
    }

    String m_playFabId;
    CStringVector<Alloc> m_tags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsRemovePlayerTagRequestWrapper : public ModelWrapper<PFEventsRemovePlayerTagRequest, Alloc>
{
public:
    using ModelType = typename PFEventsRemovePlayerTagRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsRemovePlayerTagRequestWrapper() = default;

    PFEventsRemovePlayerTagRequestWrapper(const PFEventsRemovePlayerTagRequest& model) :
        ModelWrapper<PFEventsRemovePlayerTagRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_tagName{ SafeString(model.tagName) }
    {
        SetModelPointers();
    }

    PFEventsRemovePlayerTagRequestWrapper(const PFEventsRemovePlayerTagRequestWrapper& src) :
        PFEventsRemovePlayerTagRequestWrapper{ src.Model() }
    {
    }

    PFEventsRemovePlayerTagRequestWrapper(PFEventsRemovePlayerTagRequestWrapper&& src) :
        PFEventsRemovePlayerTagRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsRemovePlayerTagRequestWrapper& operator=(PFEventsRemovePlayerTagRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsRemovePlayerTagRequestWrapper() = default;

    friend void swap(PFEventsRemovePlayerTagRequestWrapper& lhs, PFEventsRemovePlayerTagRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_tagName, rhs.m_tagName);
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

    void SetTagName(String value)
    {
        m_tagName = std::move(value);
        this->m_model.tagName =  m_tagName.empty() ? nullptr : m_tagName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.tagName = m_tagName.empty() ? nullptr : m_tagName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_tagName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsWriteClientCharacterEventRequestWrapper : public ModelWrapper<PFEventsWriteClientCharacterEventRequest, Alloc>
{
public:
    using ModelType = typename PFEventsWriteClientCharacterEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteClientCharacterEventRequestWrapper() = default;

    PFEventsWriteClientCharacterEventRequestWrapper(const PFEventsWriteClientCharacterEventRequest& model) :
        ModelWrapper<PFEventsWriteClientCharacterEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFEventsWriteClientCharacterEventRequestWrapper(const PFEventsWriteClientCharacterEventRequestWrapper& src) :
        PFEventsWriteClientCharacterEventRequestWrapper{ src.Model() }
    {
    }

    PFEventsWriteClientCharacterEventRequestWrapper(PFEventsWriteClientCharacterEventRequestWrapper&& src) :
        PFEventsWriteClientCharacterEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteClientCharacterEventRequestWrapper& operator=(PFEventsWriteClientCharacterEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteClientCharacterEventRequestWrapper() = default;

    friend void swap(PFEventsWriteClientCharacterEventRequestWrapper& lhs, PFEventsWriteClientCharacterEventRequestWrapper& rhs)
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
class PFEventsWriteEventResponseWrapper : public ModelWrapper<PFEventsWriteEventResponse, Alloc>
{
public:
    using ModelType = typename PFEventsWriteEventResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteEventResponseWrapper() = default;

    PFEventsWriteEventResponseWrapper(const PFEventsWriteEventResponse& model) :
        ModelWrapper<PFEventsWriteEventResponse, Alloc>{ model },
        m_eventId{ SafeString(model.eventId) }
    {
        SetModelPointers();
    }

    PFEventsWriteEventResponseWrapper(const PFEventsWriteEventResponseWrapper& src) :
        PFEventsWriteEventResponseWrapper{ src.Model() }
    {
    }

    PFEventsWriteEventResponseWrapper(PFEventsWriteEventResponseWrapper&& src) :
        PFEventsWriteEventResponseWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteEventResponseWrapper& operator=(PFEventsWriteEventResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteEventResponseWrapper() = default;

    friend void swap(PFEventsWriteEventResponseWrapper& lhs, PFEventsWriteEventResponseWrapper& rhs)
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
class PFEventsWriteClientPlayerEventRequestWrapper : public ModelWrapper<PFEventsWriteClientPlayerEventRequest, Alloc>
{
public:
    using ModelType = typename PFEventsWriteClientPlayerEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteClientPlayerEventRequestWrapper() = default;

    PFEventsWriteClientPlayerEventRequestWrapper(const PFEventsWriteClientPlayerEventRequest& model) :
        ModelWrapper<PFEventsWriteClientPlayerEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFEventsWriteClientPlayerEventRequestWrapper(const PFEventsWriteClientPlayerEventRequestWrapper& src) :
        PFEventsWriteClientPlayerEventRequestWrapper{ src.Model() }
    {
    }

    PFEventsWriteClientPlayerEventRequestWrapper(PFEventsWriteClientPlayerEventRequestWrapper&& src) :
        PFEventsWriteClientPlayerEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteClientPlayerEventRequestWrapper& operator=(PFEventsWriteClientPlayerEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteClientPlayerEventRequestWrapper() = default;

    friend void swap(PFEventsWriteClientPlayerEventRequestWrapper& lhs, PFEventsWriteClientPlayerEventRequestWrapper& rhs)
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
class PFEventsWriteTitleEventRequestWrapper : public ModelWrapper<PFEventsWriteTitleEventRequest, Alloc>
{
public:
    using ModelType = typename PFEventsWriteTitleEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteTitleEventRequestWrapper() = default;

    PFEventsWriteTitleEventRequestWrapper(const PFEventsWriteTitleEventRequest& model) :
        ModelWrapper<PFEventsWriteTitleEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFEventsWriteTitleEventRequestWrapper(const PFEventsWriteTitleEventRequestWrapper& src) :
        PFEventsWriteTitleEventRequestWrapper{ src.Model() }
    {
    }

    PFEventsWriteTitleEventRequestWrapper(PFEventsWriteTitleEventRequestWrapper&& src) :
        PFEventsWriteTitleEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteTitleEventRequestWrapper& operator=(PFEventsWriteTitleEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteTitleEventRequestWrapper() = default;

    friend void swap(PFEventsWriteTitleEventRequestWrapper& lhs, PFEventsWriteTitleEventRequestWrapper& rhs)
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
class PFEventsWriteServerCharacterEventRequestWrapper : public ModelWrapper<PFEventsWriteServerCharacterEventRequest, Alloc>
{
public:
    using ModelType = typename PFEventsWriteServerCharacterEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteServerCharacterEventRequestWrapper() = default;

    PFEventsWriteServerCharacterEventRequestWrapper(const PFEventsWriteServerCharacterEventRequest& model) :
        ModelWrapper<PFEventsWriteServerCharacterEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_playFabId{ SafeString(model.playFabId) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFEventsWriteServerCharacterEventRequestWrapper(const PFEventsWriteServerCharacterEventRequestWrapper& src) :
        PFEventsWriteServerCharacterEventRequestWrapper{ src.Model() }
    {
    }

    PFEventsWriteServerCharacterEventRequestWrapper(PFEventsWriteServerCharacterEventRequestWrapper&& src) :
        PFEventsWriteServerCharacterEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteServerCharacterEventRequestWrapper& operator=(PFEventsWriteServerCharacterEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteServerCharacterEventRequestWrapper() = default;

    friend void swap(PFEventsWriteServerCharacterEventRequestWrapper& lhs, PFEventsWriteServerCharacterEventRequestWrapper& rhs)
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
class PFEventsWriteServerPlayerEventRequestWrapper : public ModelWrapper<PFEventsWriteServerPlayerEventRequest, Alloc>
{
public:
    using ModelType = typename PFEventsWriteServerPlayerEventRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteServerPlayerEventRequestWrapper() = default;

    PFEventsWriteServerPlayerEventRequestWrapper(const PFEventsWriteServerPlayerEventRequest& model) :
        ModelWrapper<PFEventsWriteServerPlayerEventRequest, Alloc>{ model },
        m_body{ model.body },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_eventName{ SafeString(model.eventName) },
        m_playFabId{ SafeString(model.playFabId) },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFEventsWriteServerPlayerEventRequestWrapper(const PFEventsWriteServerPlayerEventRequestWrapper& src) :
        PFEventsWriteServerPlayerEventRequestWrapper{ src.Model() }
    {
    }

    PFEventsWriteServerPlayerEventRequestWrapper(PFEventsWriteServerPlayerEventRequestWrapper&& src) :
        PFEventsWriteServerPlayerEventRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteServerPlayerEventRequestWrapper& operator=(PFEventsWriteServerPlayerEventRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteServerPlayerEventRequestWrapper() = default;

    friend void swap(PFEventsWriteServerPlayerEventRequestWrapper& lhs, PFEventsWriteServerPlayerEventRequestWrapper& rhs)
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
class PFEventsEventContentsWrapper : public ModelWrapper<PFEventsEventContents, Alloc>
{
public:
    using ModelType = typename PFEventsEventContents;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsEventContentsWrapper() = default;

    PFEventsEventContentsWrapper(const PFEventsEventContents& model) :
        ModelWrapper<PFEventsEventContents, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_eventNamespace{ SafeString(model.eventNamespace) },
        m_name{ SafeString(model.name) },
        m_originalId{ SafeString(model.originalId) },
        m_originalTimestamp{ model.originalTimestamp ? StdExtra::optional<time_t>{ *model.originalTimestamp } : StdExtra::nullopt },
        m_payload{ model.payload },
        m_payloadJSON{ SafeString(model.payloadJSON) }
    {
        SetModelPointers();
    }

    PFEventsEventContentsWrapper(const PFEventsEventContentsWrapper& src) :
        PFEventsEventContentsWrapper{ src.Model() }
    {
    }

    PFEventsEventContentsWrapper(PFEventsEventContentsWrapper&& src) :
        PFEventsEventContentsWrapper{}
    {
        swap(*this, src);
    }

    PFEventsEventContentsWrapper& operator=(PFEventsEventContentsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsEventContentsWrapper() = default;

    friend void swap(PFEventsEventContentsWrapper& lhs, PFEventsEventContentsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_eventNamespace, rhs.m_eventNamespace);
        swap(lhs.m_name, rhs.m_name);
        swap(lhs.m_originalId, rhs.m_originalId);
        swap(lhs.m_originalTimestamp, rhs.m_originalTimestamp);
        swap(lhs.m_payload, rhs.m_payload);
        swap(lhs.m_payloadJSON, rhs.m_payloadJSON);
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

    void SetEventNamespace(String value)
    {
        m_eventNamespace = std::move(value);
        this->m_model.eventNamespace =  m_eventNamespace.empty() ? nullptr : m_eventNamespace.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetOriginalId(String value)
    {
        m_originalId = std::move(value);
        this->m_model.originalId =  m_originalId.empty() ? nullptr : m_originalId.data();
    }

    void SetOriginalTimestamp(StdExtra::optional<time_t> value)
    {
        m_originalTimestamp = std::move(value);
        this->m_model.originalTimestamp = m_originalTimestamp ? m_originalTimestamp.operator->() : nullptr;
    }

    void SetPayload(JsonObject<Alloc> value)
    {
        m_payload = std::move(value);
        this->m_model.payload.stringValue = m_payload.stringValue.empty() ? nullptr : m_payload.stringValue.data();
    }

    void SetPayloadJSON(String value)
    {
        m_payloadJSON = std::move(value);
        this->m_model.payloadJSON =  m_payloadJSON.empty() ? nullptr : m_payloadJSON.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.eventNamespace = m_eventNamespace.empty() ? nullptr : m_eventNamespace.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
        this->m_model.originalId = m_originalId.empty() ? nullptr : m_originalId.data();
        this->m_model.originalTimestamp = m_originalTimestamp ? m_originalTimestamp.operator->() : nullptr;
        this->m_model.payload.stringValue = m_payload.stringValue.empty() ? nullptr : m_payload.stringValue.data();
        this->m_model.payloadJSON = m_payloadJSON.empty() ? nullptr : m_payloadJSON.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_eventNamespace;
    String m_name;
    String m_originalId;
    StdExtra::optional<time_t> m_originalTimestamp;
    JsonObject<Alloc> m_payload;
    String m_payloadJSON;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsWriteEventsRequestWrapper : public ModelWrapper<PFEventsWriteEventsRequest, Alloc>
{
public:
    using ModelType = typename PFEventsWriteEventsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteEventsRequestWrapper() = default;

    PFEventsWriteEventsRequestWrapper(const PFEventsWriteEventsRequest& model) :
        ModelWrapper<PFEventsWriteEventsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_events{ model.events, model.events + model.eventsCount }
    {
        SetModelPointers();
    }

    PFEventsWriteEventsRequestWrapper(const PFEventsWriteEventsRequestWrapper& src) :
        PFEventsWriteEventsRequestWrapper{ src.Model() }
    {
    }

    PFEventsWriteEventsRequestWrapper(PFEventsWriteEventsRequestWrapper&& src) :
        PFEventsWriteEventsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteEventsRequestWrapper& operator=(PFEventsWriteEventsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteEventsRequestWrapper() = default;

    friend void swap(PFEventsWriteEventsRequestWrapper& lhs, PFEventsWriteEventsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_events, rhs.m_events);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEvents(ModelVector<PFEventsEventContentsWrapper<Alloc>, Alloc> value)
    {
        m_events = std::move(value);
        this->m_model.events =  m_events.empty() ? nullptr : m_events.data();
        this->m_model.eventsCount =  static_cast<uint32_t>(m_events.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.events = m_events.empty() ? nullptr : m_events.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFEventsEventContentsWrapper<Alloc>, Alloc> m_events;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEventsWriteEventsResponseWrapper : public ModelWrapper<PFEventsWriteEventsResponse, Alloc>
{
public:
    using ModelType = typename PFEventsWriteEventsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEventsWriteEventsResponseWrapper() = default;

    PFEventsWriteEventsResponseWrapper(const PFEventsWriteEventsResponse& model) :
        ModelWrapper<PFEventsWriteEventsResponse, Alloc>{ model },
        m_assignedEventIds{ model.assignedEventIds, model.assignedEventIds + model.assignedEventIdsCount }
    {
        SetModelPointers();
    }

    PFEventsWriteEventsResponseWrapper(const PFEventsWriteEventsResponseWrapper& src) :
        PFEventsWriteEventsResponseWrapper{ src.Model() }
    {
    }

    PFEventsWriteEventsResponseWrapper(PFEventsWriteEventsResponseWrapper&& src) :
        PFEventsWriteEventsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFEventsWriteEventsResponseWrapper& operator=(PFEventsWriteEventsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEventsWriteEventsResponseWrapper() = default;

    friend void swap(PFEventsWriteEventsResponseWrapper& lhs, PFEventsWriteEventsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_assignedEventIds, rhs.m_assignedEventIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAssignedEventIds(CStringVector<Alloc> value)
    {
        m_assignedEventIds = std::move(value);
        this->m_model.assignedEventIds =  m_assignedEventIds.empty() ? nullptr : m_assignedEventIds.data();
        this->m_model.assignedEventIdsCount =  static_cast<uint32_t>(m_assignedEventIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.assignedEventIds = m_assignedEventIds.empty() ? nullptr : m_assignedEventIds.data();
    }

    CStringVector<Alloc> m_assignedEventIds;
};

} // namespace Wrappers
} // namespace PlayFab
