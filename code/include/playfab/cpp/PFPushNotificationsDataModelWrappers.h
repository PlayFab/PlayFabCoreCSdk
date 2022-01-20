// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFPushNotificationsDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsDeletePushNotificationTemplateRequestWrapper : public ModelWrapper<PFPushNotificationsDeletePushNotificationTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsDeletePushNotificationTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsDeletePushNotificationTemplateRequestWrapper() = default;

    PFPushNotificationsDeletePushNotificationTemplateRequestWrapper(const PFPushNotificationsDeletePushNotificationTemplateRequest& model) :
        ModelWrapper<PFPushNotificationsDeletePushNotificationTemplateRequest, Alloc>{ model },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) }
    {
        SetModelPointers();
    }

    PFPushNotificationsDeletePushNotificationTemplateRequestWrapper(const PFPushNotificationsDeletePushNotificationTemplateRequestWrapper& src) :
        PFPushNotificationsDeletePushNotificationTemplateRequestWrapper{ src.Model() }
    {
    }

    PFPushNotificationsDeletePushNotificationTemplateRequestWrapper(PFPushNotificationsDeletePushNotificationTemplateRequestWrapper&& src) :
        PFPushNotificationsDeletePushNotificationTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsDeletePushNotificationTemplateRequestWrapper& operator=(PFPushNotificationsDeletePushNotificationTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsDeletePushNotificationTemplateRequestWrapper() = default;

    friend void swap(PFPushNotificationsDeletePushNotificationTemplateRequestWrapper& lhs, PFPushNotificationsDeletePushNotificationTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    String m_pushNotificationTemplateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsLocalizedPushNotificationPropertiesWrapper : public ModelWrapper<PFPushNotificationsLocalizedPushNotificationProperties, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsLocalizedPushNotificationProperties;
    using DictionaryEntryType = typename PFPushNotificationsLocalizedPushNotificationPropertiesDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsLocalizedPushNotificationPropertiesWrapper() = default;

    PFPushNotificationsLocalizedPushNotificationPropertiesWrapper(const PFPushNotificationsLocalizedPushNotificationProperties& model) :
        ModelWrapper<PFPushNotificationsLocalizedPushNotificationProperties, Alloc>{ model },
        m_message{ SafeString(model.message) },
        m_subject{ SafeString(model.subject) }
    {
        SetModelPointers();
    }

    PFPushNotificationsLocalizedPushNotificationPropertiesWrapper(const PFPushNotificationsLocalizedPushNotificationPropertiesWrapper& src) :
        PFPushNotificationsLocalizedPushNotificationPropertiesWrapper{ src.Model() }
    {
    }

    PFPushNotificationsLocalizedPushNotificationPropertiesWrapper(PFPushNotificationsLocalizedPushNotificationPropertiesWrapper&& src) :
        PFPushNotificationsLocalizedPushNotificationPropertiesWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsLocalizedPushNotificationPropertiesWrapper& operator=(PFPushNotificationsLocalizedPushNotificationPropertiesWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsLocalizedPushNotificationPropertiesWrapper() = default;

    friend void swap(PFPushNotificationsLocalizedPushNotificationPropertiesWrapper& lhs, PFPushNotificationsLocalizedPushNotificationPropertiesWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_subject, rhs.m_subject);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetSubject(String value)
    {
        m_subject = std::move(value);
        this->m_model.subject =  m_subject.empty() ? nullptr : m_subject.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.subject = m_subject.empty() ? nullptr : m_subject.data();
    }

    String m_message;
    String m_subject;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsSavePushNotificationTemplateRequestWrapper : public ModelWrapper<PFPushNotificationsSavePushNotificationTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsSavePushNotificationTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsSavePushNotificationTemplateRequestWrapper() = default;

    PFPushNotificationsSavePushNotificationTemplateRequestWrapper(const PFPushNotificationsSavePushNotificationTemplateRequest& model) :
        ModelWrapper<PFPushNotificationsSavePushNotificationTemplateRequest, Alloc>{ model },
        m_androidPayload{ SafeString(model.androidPayload) },
        m_id{ SafeString(model.id) },
        m_iOSPayload{ SafeString(model.iOSPayload) },
        m_localizedPushNotificationTemplates{ model.localizedPushNotificationTemplates, model.localizedPushNotificationTemplates + model.localizedPushNotificationTemplatesCount },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFPushNotificationsSavePushNotificationTemplateRequestWrapper(const PFPushNotificationsSavePushNotificationTemplateRequestWrapper& src) :
        PFPushNotificationsSavePushNotificationTemplateRequestWrapper{ src.Model() }
    {
    }

    PFPushNotificationsSavePushNotificationTemplateRequestWrapper(PFPushNotificationsSavePushNotificationTemplateRequestWrapper&& src) :
        PFPushNotificationsSavePushNotificationTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsSavePushNotificationTemplateRequestWrapper& operator=(PFPushNotificationsSavePushNotificationTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsSavePushNotificationTemplateRequestWrapper() = default;

    friend void swap(PFPushNotificationsSavePushNotificationTemplateRequestWrapper& lhs, PFPushNotificationsSavePushNotificationTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidPayload, rhs.m_androidPayload);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_iOSPayload, rhs.m_iOSPayload);
        swap(lhs.m_localizedPushNotificationTemplates, rhs.m_localizedPushNotificationTemplates);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidPayload(String value)
    {
        m_androidPayload = std::move(value);
        this->m_model.androidPayload =  m_androidPayload.empty() ? nullptr : m_androidPayload.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetIOSPayload(String value)
    {
        m_iOSPayload = std::move(value);
        this->m_model.iOSPayload =  m_iOSPayload.empty() ? nullptr : m_iOSPayload.data();
    }

    void SetLocalizedPushNotificationTemplates(ModelDictionaryEntryVector<PFPushNotificationsLocalizedPushNotificationPropertiesWrapper<Alloc>, Alloc> value)
    {
        m_localizedPushNotificationTemplates = std::move(value);
        this->m_model.localizedPushNotificationTemplates =  m_localizedPushNotificationTemplates.empty() ? nullptr : m_localizedPushNotificationTemplates.data();
        this->m_model.localizedPushNotificationTemplatesCount =  static_cast<uint32_t>(m_localizedPushNotificationTemplates.size());
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidPayload = m_androidPayload.empty() ? nullptr : m_androidPayload.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.iOSPayload = m_iOSPayload.empty() ? nullptr : m_iOSPayload.data();
        this->m_model.localizedPushNotificationTemplates = m_localizedPushNotificationTemplates.empty() ? nullptr : m_localizedPushNotificationTemplates.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_androidPayload;
    String m_id;
    String m_iOSPayload;
    ModelDictionaryEntryVector<PFPushNotificationsLocalizedPushNotificationPropertiesWrapper<Alloc>, Alloc> m_localizedPushNotificationTemplates;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsSavePushNotificationTemplateResultWrapper : public ModelWrapper<PFPushNotificationsSavePushNotificationTemplateResult, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsSavePushNotificationTemplateResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsSavePushNotificationTemplateResultWrapper() = default;

    PFPushNotificationsSavePushNotificationTemplateResultWrapper(const PFPushNotificationsSavePushNotificationTemplateResult& model) :
        ModelWrapper<PFPushNotificationsSavePushNotificationTemplateResult, Alloc>{ model },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) }
    {
        SetModelPointers();
    }

    PFPushNotificationsSavePushNotificationTemplateResultWrapper(const PFPushNotificationsSavePushNotificationTemplateResultWrapper& src) :
        PFPushNotificationsSavePushNotificationTemplateResultWrapper{ src.Model() }
    {
    }

    PFPushNotificationsSavePushNotificationTemplateResultWrapper(PFPushNotificationsSavePushNotificationTemplateResultWrapper&& src) :
        PFPushNotificationsSavePushNotificationTemplateResultWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsSavePushNotificationTemplateResultWrapper& operator=(PFPushNotificationsSavePushNotificationTemplateResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsSavePushNotificationTemplateResultWrapper() = default;

    friend void swap(PFPushNotificationsSavePushNotificationTemplateResultWrapper& lhs, PFPushNotificationsSavePushNotificationTemplateResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    String m_pushNotificationTemplateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsAdvancedPushPlatformMsgWrapper : public ModelWrapper<PFPushNotificationsAdvancedPushPlatformMsg, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsAdvancedPushPlatformMsg;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsAdvancedPushPlatformMsgWrapper() = default;

    PFPushNotificationsAdvancedPushPlatformMsgWrapper(const PFPushNotificationsAdvancedPushPlatformMsg& model) :
        ModelWrapper<PFPushNotificationsAdvancedPushPlatformMsg, Alloc>{ model },
        m_gCMDataOnly{ model.gCMDataOnly ? StdExtra::optional<bool>{ *model.gCMDataOnly } : StdExtra::nullopt },
        m_json{ SafeString(model.json) }
    {
        SetModelPointers();
    }

    PFPushNotificationsAdvancedPushPlatformMsgWrapper(const PFPushNotificationsAdvancedPushPlatformMsgWrapper& src) :
        PFPushNotificationsAdvancedPushPlatformMsgWrapper{ src.Model() }
    {
    }

    PFPushNotificationsAdvancedPushPlatformMsgWrapper(PFPushNotificationsAdvancedPushPlatformMsgWrapper&& src) :
        PFPushNotificationsAdvancedPushPlatformMsgWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsAdvancedPushPlatformMsgWrapper& operator=(PFPushNotificationsAdvancedPushPlatformMsgWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsAdvancedPushPlatformMsgWrapper() = default;

    friend void swap(PFPushNotificationsAdvancedPushPlatformMsgWrapper& lhs, PFPushNotificationsAdvancedPushPlatformMsgWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gCMDataOnly, rhs.m_gCMDataOnly);
        swap(lhs.m_json, rhs.m_json);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGCMDataOnly(StdExtra::optional<bool> value)
    {
        m_gCMDataOnly = std::move(value);
        this->m_model.gCMDataOnly = m_gCMDataOnly ? m_gCMDataOnly.operator->() : nullptr;
    }

    void SetJson(String value)
    {
        m_json = std::move(value);
        this->m_model.json =  m_json.empty() ? nullptr : m_json.data();
    }

    void SetPlatform(PFPushNotificationPlatform value)
    {
        this->m_model.platform = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.gCMDataOnly = m_gCMDataOnly ? m_gCMDataOnly.operator->() : nullptr;
        this->m_model.json = m_json.empty() ? nullptr : m_json.data();
    }

    StdExtra::optional<bool> m_gCMDataOnly;
    String m_json;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsPushNotificationPackageWrapper : public ModelWrapper<PFPushNotificationsPushNotificationPackage, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsPushNotificationPackage;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsPushNotificationPackageWrapper() = default;

    PFPushNotificationsPushNotificationPackageWrapper(const PFPushNotificationsPushNotificationPackage& model) :
        ModelWrapper<PFPushNotificationsPushNotificationPackage, Alloc>{ model },
        m_customData{ SafeString(model.customData) },
        m_icon{ SafeString(model.icon) },
        m_message{ SafeString(model.message) },
        m_sound{ SafeString(model.sound) },
        m_title{ SafeString(model.title) }
    {
        SetModelPointers();
    }

    PFPushNotificationsPushNotificationPackageWrapper(const PFPushNotificationsPushNotificationPackageWrapper& src) :
        PFPushNotificationsPushNotificationPackageWrapper{ src.Model() }
    {
    }

    PFPushNotificationsPushNotificationPackageWrapper(PFPushNotificationsPushNotificationPackageWrapper&& src) :
        PFPushNotificationsPushNotificationPackageWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsPushNotificationPackageWrapper& operator=(PFPushNotificationsPushNotificationPackageWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsPushNotificationPackageWrapper() = default;

    friend void swap(PFPushNotificationsPushNotificationPackageWrapper& lhs, PFPushNotificationsPushNotificationPackageWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customData, rhs.m_customData);
        swap(lhs.m_icon, rhs.m_icon);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_sound, rhs.m_sound);
        swap(lhs.m_title, rhs.m_title);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBadge(int32_t value)
    {
        this->m_model.badge = value;
    }

    void SetCustomData(String value)
    {
        m_customData = std::move(value);
        this->m_model.customData =  m_customData.empty() ? nullptr : m_customData.data();
    }

    void SetIcon(String value)
    {
        m_icon = std::move(value);
        this->m_model.icon =  m_icon.empty() ? nullptr : m_icon.data();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetSound(String value)
    {
        m_sound = std::move(value);
        this->m_model.sound =  m_sound.empty() ? nullptr : m_sound.data();
    }

    void SetTitle(String value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customData = m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.icon = m_icon.empty() ? nullptr : m_icon.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.sound = m_sound.empty() ? nullptr : m_sound.data();
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
    }

    String m_customData;
    String m_icon;
    String m_message;
    String m_sound;
    String m_title;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsSendPushNotificationRequestWrapper : public ModelWrapper<PFPushNotificationsSendPushNotificationRequest, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsSendPushNotificationRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsSendPushNotificationRequestWrapper() = default;

    PFPushNotificationsSendPushNotificationRequestWrapper(const PFPushNotificationsSendPushNotificationRequest& model) :
        ModelWrapper<PFPushNotificationsSendPushNotificationRequest, Alloc>{ model },
        m_advancedPlatformDelivery{ model.advancedPlatformDelivery, model.advancedPlatformDelivery + model.advancedPlatformDeliveryCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_message{ SafeString(model.message) },
        m_package{ model.package ? StdExtra::optional<PFPushNotificationsPushNotificationPackageWrapper<Alloc>>{ *model.package } : StdExtra::nullopt },
        m_recipient{ SafeString(model.recipient) },
        m_subject{ SafeString(model.subject) },
        m_targetPlatforms{ model.targetPlatforms, model.targetPlatforms + model.targetPlatformsCount }
    {
        SetModelPointers();
    }

    PFPushNotificationsSendPushNotificationRequestWrapper(const PFPushNotificationsSendPushNotificationRequestWrapper& src) :
        PFPushNotificationsSendPushNotificationRequestWrapper{ src.Model() }
    {
    }

    PFPushNotificationsSendPushNotificationRequestWrapper(PFPushNotificationsSendPushNotificationRequestWrapper&& src) :
        PFPushNotificationsSendPushNotificationRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsSendPushNotificationRequestWrapper& operator=(PFPushNotificationsSendPushNotificationRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsSendPushNotificationRequestWrapper() = default;

    friend void swap(PFPushNotificationsSendPushNotificationRequestWrapper& lhs, PFPushNotificationsSendPushNotificationRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_advancedPlatformDelivery, rhs.m_advancedPlatformDelivery);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_package, rhs.m_package);
        swap(lhs.m_recipient, rhs.m_recipient);
        swap(lhs.m_subject, rhs.m_subject);
        swap(lhs.m_targetPlatforms, rhs.m_targetPlatforms);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdvancedPlatformDelivery(ModelVector<PFPushNotificationsAdvancedPushPlatformMsgWrapper<Alloc>, Alloc> value)
    {
        m_advancedPlatformDelivery = std::move(value);
        this->m_model.advancedPlatformDelivery =  m_advancedPlatformDelivery.empty() ? nullptr : m_advancedPlatformDelivery.data();
        this->m_model.advancedPlatformDeliveryCount =  static_cast<uint32_t>(m_advancedPlatformDelivery.size());
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetPackage(StdExtra::optional<PFPushNotificationsPushNotificationPackageWrapper<Alloc>> value)
    {
        m_package = std::move(value);
        this->m_model.package = m_package ? &m_package->Model() : nullptr;
    }

    void SetRecipient(String value)
    {
        m_recipient = std::move(value);
        this->m_model.recipient =  m_recipient.empty() ? nullptr : m_recipient.data();
    }

    void SetSubject(String value)
    {
        m_subject = std::move(value);
        this->m_model.subject =  m_subject.empty() ? nullptr : m_subject.data();
    }

    void SetTargetPlatforms(Vector<PFPushNotificationPlatform> value)
    {
        m_targetPlatforms = std::move(value);
        this->m_model.targetPlatforms =  m_targetPlatforms.empty() ? nullptr : m_targetPlatforms.data();
        this->m_model.targetPlatformsCount =  static_cast<uint32_t>(m_targetPlatforms.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.advancedPlatformDelivery = m_advancedPlatformDelivery.empty() ? nullptr : m_advancedPlatformDelivery.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.package = m_package ?  &m_package->Model() : nullptr;
        this->m_model.recipient = m_recipient.empty() ? nullptr : m_recipient.data();
        this->m_model.subject = m_subject.empty() ? nullptr : m_subject.data();
        this->m_model.targetPlatforms = m_targetPlatforms.empty() ? nullptr : m_targetPlatforms.data();
    }

    ModelVector<PFPushNotificationsAdvancedPushPlatformMsgWrapper<Alloc>, Alloc> m_advancedPlatformDelivery;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_message;
    StdExtra::optional<PFPushNotificationsPushNotificationPackageWrapper<Alloc>> m_package;
    String m_recipient;
    String m_subject;
    Vector<PFPushNotificationPlatform> m_targetPlatforms;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper : public ModelWrapper<PFPushNotificationsSendPushNotificationFromTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFPushNotificationsSendPushNotificationFromTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper() = default;

    PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper(const PFPushNotificationsSendPushNotificationFromTemplateRequest& model) :
        ModelWrapper<PFPushNotificationsSendPushNotificationFromTemplateRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) },
        m_recipient{ SafeString(model.recipient) }
    {
        SetModelPointers();
    }

    PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper(const PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper& src) :
        PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper{ src.Model() }
    {
    }

    PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper(PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper&& src) :
        PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper& operator=(PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper() = default;

    friend void swap(PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper& lhs, PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        swap(lhs.m_recipient, rhs.m_recipient);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    void SetRecipient(String value)
    {
        m_recipient = std::move(value);
        this->m_model.recipient =  m_recipient.empty() ? nullptr : m_recipient.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
        this->m_model.recipient = m_recipient.empty() ? nullptr : m_recipient.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_pushNotificationTemplateId;
    String m_recipient;
};

} // namespace Wrappers
} // namespace PlayFab
