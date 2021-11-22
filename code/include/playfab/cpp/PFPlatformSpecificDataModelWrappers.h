// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFPlatformSpecificDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper : public ModelWrapper<PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper() = default;

    PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper(const PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest& model) :
        ModelWrapper<PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest, Alloc>{ model },
        m_confirmationMessage{ SafeString(model.confirmationMessage) },
        m_deviceToken{ SafeString(model.deviceToken) },
        m_sendPushNotificationConfirmation{ model.sendPushNotificationConfirmation ? StdExtra::optional<bool>{ *model.sendPushNotificationConfirmation } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper(const PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper& src) :
        PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper(PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper&& src) :
        PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper& operator=(PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper() = default;

    friend void swap(PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper& lhs, PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_confirmationMessage, rhs.m_confirmationMessage);
        swap(lhs.m_deviceToken, rhs.m_deviceToken);
        swap(lhs.m_sendPushNotificationConfirmation, rhs.m_sendPushNotificationConfirmation);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConfirmationMessage(String value)
    {
        m_confirmationMessage = std::move(value);
        this->m_model.confirmationMessage =  m_confirmationMessage.empty() ? nullptr : m_confirmationMessage.data();
    }

    void SetDeviceToken(String value)
    {
        m_deviceToken = std::move(value);
        this->m_model.deviceToken =  m_deviceToken.empty() ? nullptr : m_deviceToken.data();
    }

    void SetSendPushNotificationConfirmation(StdExtra::optional<bool> value)
    {
        m_sendPushNotificationConfirmation = std::move(value);
        this->m_model.sendPushNotificationConfirmation = m_sendPushNotificationConfirmation ? m_sendPushNotificationConfirmation.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.confirmationMessage = m_confirmationMessage.empty() ? nullptr : m_confirmationMessage.data();
        this->m_model.deviceToken = m_deviceToken.empty() ? nullptr : m_deviceToken.data();
        this->m_model.sendPushNotificationConfirmation = m_sendPushNotificationConfirmation ? m_sendPushNotificationConfirmation.operator->() : nullptr;
    }

    String m_confirmationMessage;
    String m_deviceToken;
    StdExtra::optional<bool> m_sendPushNotificationConfirmation;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificMicrosoftStorePayloadWrapper : public ModelWrapper<PFPlatformSpecificMicrosoftStorePayload, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificMicrosoftStorePayload;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificMicrosoftStorePayloadWrapper() = default;

    PFPlatformSpecificMicrosoftStorePayloadWrapper(const PFPlatformSpecificMicrosoftStorePayload& model) :
        ModelWrapper<PFPlatformSpecificMicrosoftStorePayload, Alloc>{ model },
        m_collectionsMsIdKey{ SafeString(model.collectionsMsIdKey) },
        m_userId{ SafeString(model.userId) },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificMicrosoftStorePayloadWrapper(const PFPlatformSpecificMicrosoftStorePayloadWrapper& src) :
        PFPlatformSpecificMicrosoftStorePayloadWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificMicrosoftStorePayloadWrapper(PFPlatformSpecificMicrosoftStorePayloadWrapper&& src) :
        PFPlatformSpecificMicrosoftStorePayloadWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificMicrosoftStorePayloadWrapper& operator=(PFPlatformSpecificMicrosoftStorePayloadWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificMicrosoftStorePayloadWrapper() = default;

    friend void swap(PFPlatformSpecificMicrosoftStorePayloadWrapper& lhs, PFPlatformSpecificMicrosoftStorePayloadWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_collectionsMsIdKey, rhs.m_collectionsMsIdKey);
        swap(lhs.m_userId, rhs.m_userId);
        swap(lhs.m_xboxToken, rhs.m_xboxToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCollectionsMsIdKey(String value)
    {
        m_collectionsMsIdKey = std::move(value);
        this->m_model.collectionsMsIdKey =  m_collectionsMsIdKey.empty() ? nullptr : m_collectionsMsIdKey.data();
    }

    void SetUserId(String value)
    {
        m_userId = std::move(value);
        this->m_model.userId =  m_userId.empty() ? nullptr : m_userId.data();
    }

    void SetXboxToken(String value)
    {
        m_xboxToken = std::move(value);
        this->m_model.xboxToken =  m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.collectionsMsIdKey = m_collectionsMsIdKey.empty() ? nullptr : m_collectionsMsIdKey.data();
        this->m_model.userId = m_userId.empty() ? nullptr : m_userId.data();
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    String m_collectionsMsIdKey;
    String m_userId;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper : public ModelWrapper<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper() = default;

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest& model) :
        ModelWrapper<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_marketplaceSpecificData{ model.marketplaceSpecificData ? *model.marketplaceSpecificData : decltype(*model.marketplaceSpecificData){} }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper& src) :
        PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper&& src) :
        PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper& operator=(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper() = default;

    friend void swap(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper& lhs, PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_marketplaceSpecificData, rhs.m_marketplaceSpecificData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMarketplaceSpecificData(PFPlatformSpecificMicrosoftStorePayloadWrapper<Alloc> value)
    {
        m_marketplaceSpecificData = std::move(value);
        this->m_model.marketplaceSpecificData = &m_marketplaceSpecificData.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.marketplaceSpecificData = &m_marketplaceSpecificData.Model();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    PFPlatformSpecificMicrosoftStorePayloadWrapper<Alloc> m_marketplaceSpecificData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper : public ModelWrapper<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper() = default;

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& model) :
        ModelWrapper<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse, Alloc>{ model },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper& src) :
        PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper&& src) :
        PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper& operator=(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper() = default;

    friend void swap(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper& lhs, PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificPlayStation5PayloadWrapper : public ModelWrapper<PFPlatformSpecificPlayStation5Payload, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificPlayStation5Payload;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificPlayStation5PayloadWrapper() = default;

    PFPlatformSpecificPlayStation5PayloadWrapper(const PFPlatformSpecificPlayStation5Payload& model) :
        ModelWrapper<PFPlatformSpecificPlayStation5Payload, Alloc>{ model },
        m_ids{ model.ids, model.ids + model.idsCount },
        m_serviceLabel{ SafeString(model.serviceLabel) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificPlayStation5PayloadWrapper(const PFPlatformSpecificPlayStation5PayloadWrapper& src) :
        PFPlatformSpecificPlayStation5PayloadWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificPlayStation5PayloadWrapper(PFPlatformSpecificPlayStation5PayloadWrapper&& src) :
        PFPlatformSpecificPlayStation5PayloadWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificPlayStation5PayloadWrapper& operator=(PFPlatformSpecificPlayStation5PayloadWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificPlayStation5PayloadWrapper() = default;

    friend void swap(PFPlatformSpecificPlayStation5PayloadWrapper& lhs, PFPlatformSpecificPlayStation5PayloadWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_ids, rhs.m_ids);
        swap(lhs.m_serviceLabel, rhs.m_serviceLabel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIds(CStringVector<Alloc> value)
    {
        m_ids = std::move(value);
        this->m_model.ids =  m_ids.empty() ? nullptr : m_ids.data();
        this->m_model.idsCount =  static_cast<uint32_t>(m_ids.size());
    }

    void SetServiceLabel(String value)
    {
        m_serviceLabel = std::move(value);
        this->m_model.serviceLabel =  m_serviceLabel.empty() ? nullptr : m_serviceLabel.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.ids = m_ids.empty() ? nullptr : m_ids.data();
        this->m_model.serviceLabel = m_serviceLabel.empty() ? nullptr : m_serviceLabel.data();
    }

    CStringVector<Alloc> m_ids;
    String m_serviceLabel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumePS5EntitlementsRequestWrapper : public ModelWrapper<PFPlatformSpecificConsumePS5EntitlementsRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumePS5EntitlementsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumePS5EntitlementsRequestWrapper() = default;

    PFPlatformSpecificConsumePS5EntitlementsRequestWrapper(const PFPlatformSpecificConsumePS5EntitlementsRequest& model) :
        ModelWrapper<PFPlatformSpecificConsumePS5EntitlementsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_marketplaceSpecificData{ model.marketplaceSpecificData ? *model.marketplaceSpecificData : decltype(*model.marketplaceSpecificData){} }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumePS5EntitlementsRequestWrapper(const PFPlatformSpecificConsumePS5EntitlementsRequestWrapper& src) :
        PFPlatformSpecificConsumePS5EntitlementsRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumePS5EntitlementsRequestWrapper(PFPlatformSpecificConsumePS5EntitlementsRequestWrapper&& src) :
        PFPlatformSpecificConsumePS5EntitlementsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumePS5EntitlementsRequestWrapper& operator=(PFPlatformSpecificConsumePS5EntitlementsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumePS5EntitlementsRequestWrapper() = default;

    friend void swap(PFPlatformSpecificConsumePS5EntitlementsRequestWrapper& lhs, PFPlatformSpecificConsumePS5EntitlementsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_marketplaceSpecificData, rhs.m_marketplaceSpecificData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMarketplaceSpecificData(PFPlatformSpecificPlayStation5PayloadWrapper<Alloc> value)
    {
        m_marketplaceSpecificData = std::move(value);
        this->m_model.marketplaceSpecificData = &m_marketplaceSpecificData.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.marketplaceSpecificData = &m_marketplaceSpecificData.Model();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    PFPlatformSpecificPlayStation5PayloadWrapper<Alloc> m_marketplaceSpecificData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumePS5EntitlementsResultWrapper : public ModelWrapper<PFPlatformSpecificConsumePS5EntitlementsResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumePS5EntitlementsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumePS5EntitlementsResultWrapper() = default;

    PFPlatformSpecificConsumePS5EntitlementsResultWrapper(const PFPlatformSpecificConsumePS5EntitlementsResult& model) :
        ModelWrapper<PFPlatformSpecificConsumePS5EntitlementsResult, Alloc>{ model },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumePS5EntitlementsResultWrapper(const PFPlatformSpecificConsumePS5EntitlementsResultWrapper& src) :
        PFPlatformSpecificConsumePS5EntitlementsResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumePS5EntitlementsResultWrapper(PFPlatformSpecificConsumePS5EntitlementsResultWrapper&& src) :
        PFPlatformSpecificConsumePS5EntitlementsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumePS5EntitlementsResultWrapper& operator=(PFPlatformSpecificConsumePS5EntitlementsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumePS5EntitlementsResultWrapper() = default;

    friend void swap(PFPlatformSpecificConsumePS5EntitlementsResultWrapper& lhs, PFPlatformSpecificConsumePS5EntitlementsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumePSNEntitlementsRequestWrapper : public ModelWrapper<PFPlatformSpecificConsumePSNEntitlementsRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumePSNEntitlementsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumePSNEntitlementsRequestWrapper() = default;

    PFPlatformSpecificConsumePSNEntitlementsRequestWrapper(const PFPlatformSpecificConsumePSNEntitlementsRequest& model) :
        ModelWrapper<PFPlatformSpecificConsumePSNEntitlementsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumePSNEntitlementsRequestWrapper(const PFPlatformSpecificConsumePSNEntitlementsRequestWrapper& src) :
        PFPlatformSpecificConsumePSNEntitlementsRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumePSNEntitlementsRequestWrapper(PFPlatformSpecificConsumePSNEntitlementsRequestWrapper&& src) :
        PFPlatformSpecificConsumePSNEntitlementsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumePSNEntitlementsRequestWrapper& operator=(PFPlatformSpecificConsumePSNEntitlementsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumePSNEntitlementsRequestWrapper() = default;

    friend void swap(PFPlatformSpecificConsumePSNEntitlementsRequestWrapper& lhs, PFPlatformSpecificConsumePSNEntitlementsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetServiceLabel(int32_t value)
    {
        this->m_model.serviceLabel = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumePSNEntitlementsResultWrapper : public ModelWrapper<PFPlatformSpecificConsumePSNEntitlementsResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumePSNEntitlementsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumePSNEntitlementsResultWrapper() = default;

    PFPlatformSpecificConsumePSNEntitlementsResultWrapper(const PFPlatformSpecificConsumePSNEntitlementsResult& model) :
        ModelWrapper<PFPlatformSpecificConsumePSNEntitlementsResult, Alloc>{ model },
        m_itemsGranted{ model.itemsGranted, model.itemsGranted + model.itemsGrantedCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumePSNEntitlementsResultWrapper(const PFPlatformSpecificConsumePSNEntitlementsResultWrapper& src) :
        PFPlatformSpecificConsumePSNEntitlementsResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumePSNEntitlementsResultWrapper(PFPlatformSpecificConsumePSNEntitlementsResultWrapper&& src) :
        PFPlatformSpecificConsumePSNEntitlementsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumePSNEntitlementsResultWrapper& operator=(PFPlatformSpecificConsumePSNEntitlementsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumePSNEntitlementsResultWrapper() = default;

    friend void swap(PFPlatformSpecificConsumePSNEntitlementsResultWrapper& lhs, PFPlatformSpecificConsumePSNEntitlementsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemsGranted, rhs.m_itemsGranted);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemsGranted(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_itemsGranted = std::move(value);
        this->m_model.itemsGranted =  m_itemsGranted.empty() ? nullptr : m_itemsGranted.data();
        this->m_model.itemsGrantedCount =  static_cast<uint32_t>(m_itemsGranted.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemsGranted = m_itemsGranted.empty() ? nullptr : m_itemsGranted.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_itemsGranted;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper : public ModelWrapper<PFPlatformSpecificConsumeXboxEntitlementsRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumeXboxEntitlementsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper() = default;

    PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper(const PFPlatformSpecificConsumeXboxEntitlementsRequest& model) :
        ModelWrapper<PFPlatformSpecificConsumeXboxEntitlementsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper(const PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper& src) :
        PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper(PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper&& src) :
        PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper& operator=(PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper() = default;

    friend void swap(PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper& lhs, PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_xboxToken, rhs.m_xboxToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetXboxToken(String value)
    {
        m_xboxToken = std::move(value);
        this->m_model.xboxToken =  m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificConsumeXboxEntitlementsResultWrapper : public ModelWrapper<PFPlatformSpecificConsumeXboxEntitlementsResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificConsumeXboxEntitlementsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificConsumeXboxEntitlementsResultWrapper() = default;

    PFPlatformSpecificConsumeXboxEntitlementsResultWrapper(const PFPlatformSpecificConsumeXboxEntitlementsResult& model) :
        ModelWrapper<PFPlatformSpecificConsumeXboxEntitlementsResult, Alloc>{ model },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificConsumeXboxEntitlementsResultWrapper(const PFPlatformSpecificConsumeXboxEntitlementsResultWrapper& src) :
        PFPlatformSpecificConsumeXboxEntitlementsResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificConsumeXboxEntitlementsResultWrapper(PFPlatformSpecificConsumeXboxEntitlementsResultWrapper&& src) :
        PFPlatformSpecificConsumeXboxEntitlementsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificConsumeXboxEntitlementsResultWrapper& operator=(PFPlatformSpecificConsumeXboxEntitlementsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificConsumeXboxEntitlementsResultWrapper() = default;

    friend void swap(PFPlatformSpecificConsumeXboxEntitlementsResultWrapper& lhs, PFPlatformSpecificConsumeXboxEntitlementsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper : public ModelWrapper<PFPlatformSpecificRefreshPSNAuthTokenRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificRefreshPSNAuthTokenRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper() = default;

    PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper(const PFPlatformSpecificRefreshPSNAuthTokenRequest& model) :
        ModelWrapper<PFPlatformSpecificRefreshPSNAuthTokenRequest, Alloc>{ model },
        m_authCode{ SafeString(model.authCode) },
        m_issuerId{ model.issuerId ? StdExtra::optional<int32_t>{ *model.issuerId } : StdExtra::nullopt },
        m_redirectUri{ SafeString(model.redirectUri) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper(const PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper& src) :
        PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper(PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper&& src) :
        PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper& operator=(PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper() = default;

    friend void swap(PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper& lhs, PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authCode, rhs.m_authCode);
        swap(lhs.m_issuerId, rhs.m_issuerId);
        swap(lhs.m_redirectUri, rhs.m_redirectUri);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthCode(String value)
    {
        m_authCode = std::move(value);
        this->m_model.authCode =  m_authCode.empty() ? nullptr : m_authCode.data();
    }

    void SetIssuerId(StdExtra::optional<int32_t> value)
    {
        m_issuerId = std::move(value);
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
    }

    void SetRedirectUri(String value)
    {
        m_redirectUri = std::move(value);
        this->m_model.redirectUri =  m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authCode = m_authCode.empty() ? nullptr : m_authCode.data();
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
        this->m_model.redirectUri = m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

    String m_authCode;
    StdExtra::optional<int32_t> m_issuerId;
    String m_redirectUri;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper : public ModelWrapper<PFPlatformSpecificRegisterForIOSPushNotificationRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificRegisterForIOSPushNotificationRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper() = default;

    PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper(const PFPlatformSpecificRegisterForIOSPushNotificationRequest& model) :
        ModelWrapper<PFPlatformSpecificRegisterForIOSPushNotificationRequest, Alloc>{ model },
        m_confirmationMessage{ SafeString(model.confirmationMessage) },
        m_deviceToken{ SafeString(model.deviceToken) },
        m_sendPushNotificationConfirmation{ model.sendPushNotificationConfirmation ? StdExtra::optional<bool>{ *model.sendPushNotificationConfirmation } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper(const PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper& src) :
        PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper(PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper&& src) :
        PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper& operator=(PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper() = default;

    friend void swap(PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper& lhs, PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_confirmationMessage, rhs.m_confirmationMessage);
        swap(lhs.m_deviceToken, rhs.m_deviceToken);
        swap(lhs.m_sendPushNotificationConfirmation, rhs.m_sendPushNotificationConfirmation);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConfirmationMessage(String value)
    {
        m_confirmationMessage = std::move(value);
        this->m_model.confirmationMessage =  m_confirmationMessage.empty() ? nullptr : m_confirmationMessage.data();
    }

    void SetDeviceToken(String value)
    {
        m_deviceToken = std::move(value);
        this->m_model.deviceToken =  m_deviceToken.empty() ? nullptr : m_deviceToken.data();
    }

    void SetSendPushNotificationConfirmation(StdExtra::optional<bool> value)
    {
        m_sendPushNotificationConfirmation = std::move(value);
        this->m_model.sendPushNotificationConfirmation = m_sendPushNotificationConfirmation ? m_sendPushNotificationConfirmation.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.confirmationMessage = m_confirmationMessage.empty() ? nullptr : m_confirmationMessage.data();
        this->m_model.deviceToken = m_deviceToken.empty() ? nullptr : m_deviceToken.data();
        this->m_model.sendPushNotificationConfirmation = m_sendPushNotificationConfirmation ? m_sendPushNotificationConfirmation.operator->() : nullptr;
    }

    String m_confirmationMessage;
    String m_deviceToken;
    StdExtra::optional<bool> m_sendPushNotificationConfirmation;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificRestoreIOSPurchasesRequestWrapper : public ModelWrapper<PFPlatformSpecificRestoreIOSPurchasesRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificRestoreIOSPurchasesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificRestoreIOSPurchasesRequestWrapper() = default;

    PFPlatformSpecificRestoreIOSPurchasesRequestWrapper(const PFPlatformSpecificRestoreIOSPurchasesRequest& model) :
        ModelWrapper<PFPlatformSpecificRestoreIOSPurchasesRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_receiptData{ SafeString(model.receiptData) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificRestoreIOSPurchasesRequestWrapper(const PFPlatformSpecificRestoreIOSPurchasesRequestWrapper& src) :
        PFPlatformSpecificRestoreIOSPurchasesRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificRestoreIOSPurchasesRequestWrapper(PFPlatformSpecificRestoreIOSPurchasesRequestWrapper&& src) :
        PFPlatformSpecificRestoreIOSPurchasesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificRestoreIOSPurchasesRequestWrapper& operator=(PFPlatformSpecificRestoreIOSPurchasesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificRestoreIOSPurchasesRequestWrapper() = default;

    friend void swap(PFPlatformSpecificRestoreIOSPurchasesRequestWrapper& lhs, PFPlatformSpecificRestoreIOSPurchasesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_receiptData, rhs.m_receiptData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetReceiptData(String value)
    {
        m_receiptData = std::move(value);
        this->m_model.receiptData =  m_receiptData.empty() ? nullptr : m_receiptData.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.receiptData = m_receiptData.empty() ? nullptr : m_receiptData.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_receiptData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificPurchaseReceiptFulfillmentWrapper : public ModelWrapper<PFPlatformSpecificPurchaseReceiptFulfillment, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificPurchaseReceiptFulfillment;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificPurchaseReceiptFulfillmentWrapper() = default;

    PFPlatformSpecificPurchaseReceiptFulfillmentWrapper(const PFPlatformSpecificPurchaseReceiptFulfillment& model) :
        ModelWrapper<PFPlatformSpecificPurchaseReceiptFulfillment, Alloc>{ model },
        m_fulfilledItems{ model.fulfilledItems, model.fulfilledItems + model.fulfilledItemsCount },
        m_recordedPriceSource{ SafeString(model.recordedPriceSource) },
        m_recordedTransactionCurrency{ SafeString(model.recordedTransactionCurrency) },
        m_recordedTransactionTotal{ model.recordedTransactionTotal ? StdExtra::optional<uint32_t>{ *model.recordedTransactionTotal } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlatformSpecificPurchaseReceiptFulfillmentWrapper(const PFPlatformSpecificPurchaseReceiptFulfillmentWrapper& src) :
        PFPlatformSpecificPurchaseReceiptFulfillmentWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificPurchaseReceiptFulfillmentWrapper(PFPlatformSpecificPurchaseReceiptFulfillmentWrapper&& src) :
        PFPlatformSpecificPurchaseReceiptFulfillmentWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificPurchaseReceiptFulfillmentWrapper& operator=(PFPlatformSpecificPurchaseReceiptFulfillmentWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificPurchaseReceiptFulfillmentWrapper() = default;

    friend void swap(PFPlatformSpecificPurchaseReceiptFulfillmentWrapper& lhs, PFPlatformSpecificPurchaseReceiptFulfillmentWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fulfilledItems, rhs.m_fulfilledItems);
        swap(lhs.m_recordedPriceSource, rhs.m_recordedPriceSource);
        swap(lhs.m_recordedTransactionCurrency, rhs.m_recordedTransactionCurrency);
        swap(lhs.m_recordedTransactionTotal, rhs.m_recordedTransactionTotal);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFulfilledItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_fulfilledItems = std::move(value);
        this->m_model.fulfilledItems =  m_fulfilledItems.empty() ? nullptr : m_fulfilledItems.data();
        this->m_model.fulfilledItemsCount =  static_cast<uint32_t>(m_fulfilledItems.size());
    }

    void SetRecordedPriceSource(String value)
    {
        m_recordedPriceSource = std::move(value);
        this->m_model.recordedPriceSource =  m_recordedPriceSource.empty() ? nullptr : m_recordedPriceSource.data();
    }

    void SetRecordedTransactionCurrency(String value)
    {
        m_recordedTransactionCurrency = std::move(value);
        this->m_model.recordedTransactionCurrency =  m_recordedTransactionCurrency.empty() ? nullptr : m_recordedTransactionCurrency.data();
    }

    void SetRecordedTransactionTotal(StdExtra::optional<uint32_t> value)
    {
        m_recordedTransactionTotal = std::move(value);
        this->m_model.recordedTransactionTotal = m_recordedTransactionTotal ? m_recordedTransactionTotal.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.fulfilledItems = m_fulfilledItems.empty() ? nullptr : m_fulfilledItems.data();
        this->m_model.recordedPriceSource = m_recordedPriceSource.empty() ? nullptr : m_recordedPriceSource.data();
        this->m_model.recordedTransactionCurrency = m_recordedTransactionCurrency.empty() ? nullptr : m_recordedTransactionCurrency.data();
        this->m_model.recordedTransactionTotal = m_recordedTransactionTotal ? m_recordedTransactionTotal.operator->() : nullptr;
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_fulfilledItems;
    String m_recordedPriceSource;
    String m_recordedTransactionCurrency;
    StdExtra::optional<uint32_t> m_recordedTransactionTotal;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificRestoreIOSPurchasesResultWrapper : public ModelWrapper<PFPlatformSpecificRestoreIOSPurchasesResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificRestoreIOSPurchasesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificRestoreIOSPurchasesResultWrapper() = default;

    PFPlatformSpecificRestoreIOSPurchasesResultWrapper(const PFPlatformSpecificRestoreIOSPurchasesResult& model) :
        ModelWrapper<PFPlatformSpecificRestoreIOSPurchasesResult, Alloc>{ model },
        m_fulfillments{ model.fulfillments, model.fulfillments + model.fulfillmentsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificRestoreIOSPurchasesResultWrapper(const PFPlatformSpecificRestoreIOSPurchasesResultWrapper& src) :
        PFPlatformSpecificRestoreIOSPurchasesResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificRestoreIOSPurchasesResultWrapper(PFPlatformSpecificRestoreIOSPurchasesResultWrapper&& src) :
        PFPlatformSpecificRestoreIOSPurchasesResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificRestoreIOSPurchasesResultWrapper& operator=(PFPlatformSpecificRestoreIOSPurchasesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificRestoreIOSPurchasesResultWrapper() = default;

    friend void swap(PFPlatformSpecificRestoreIOSPurchasesResultWrapper& lhs, PFPlatformSpecificRestoreIOSPurchasesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fulfillments, rhs.m_fulfillments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFulfillments(ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> value)
    {
        m_fulfillments = std::move(value);
        this->m_model.fulfillments =  m_fulfillments.empty() ? nullptr : m_fulfillments.data();
        this->m_model.fulfillmentsCount =  static_cast<uint32_t>(m_fulfillments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.fulfillments = m_fulfillments.empty() ? nullptr : m_fulfillments.data();
    }

    ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> m_fulfillments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateAmazonReceiptRequestWrapper : public ModelWrapper<PFPlatformSpecificValidateAmazonReceiptRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateAmazonReceiptRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateAmazonReceiptRequestWrapper() = default;

    PFPlatformSpecificValidateAmazonReceiptRequestWrapper(const PFPlatformSpecificValidateAmazonReceiptRequest& model) :
        ModelWrapper<PFPlatformSpecificValidateAmazonReceiptRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_currencyCode{ SafeString(model.currencyCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_receiptId{ SafeString(model.receiptId) },
        m_userId{ SafeString(model.userId) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateAmazonReceiptRequestWrapper(const PFPlatformSpecificValidateAmazonReceiptRequestWrapper& src) :
        PFPlatformSpecificValidateAmazonReceiptRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateAmazonReceiptRequestWrapper(PFPlatformSpecificValidateAmazonReceiptRequestWrapper&& src) :
        PFPlatformSpecificValidateAmazonReceiptRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateAmazonReceiptRequestWrapper& operator=(PFPlatformSpecificValidateAmazonReceiptRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateAmazonReceiptRequestWrapper() = default;

    friend void swap(PFPlatformSpecificValidateAmazonReceiptRequestWrapper& lhs, PFPlatformSpecificValidateAmazonReceiptRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_receiptId, rhs.m_receiptId);
        swap(lhs.m_userId, rhs.m_userId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPurchasePrice(int32_t value)
    {
        this->m_model.purchasePrice = value;
    }

    void SetReceiptId(String value)
    {
        m_receiptId = std::move(value);
        this->m_model.receiptId =  m_receiptId.empty() ? nullptr : m_receiptId.data();
    }

    void SetUserId(String value)
    {
        m_userId = std::move(value);
        this->m_model.userId =  m_userId.empty() ? nullptr : m_userId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.receiptId = m_receiptId.empty() ? nullptr : m_receiptId.data();
        this->m_model.userId = m_userId.empty() ? nullptr : m_userId.data();
    }

    String m_catalogVersion;
    String m_currencyCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_receiptId;
    String m_userId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateAmazonReceiptResultWrapper : public ModelWrapper<PFPlatformSpecificValidateAmazonReceiptResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateAmazonReceiptResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateAmazonReceiptResultWrapper() = default;

    PFPlatformSpecificValidateAmazonReceiptResultWrapper(const PFPlatformSpecificValidateAmazonReceiptResult& model) :
        ModelWrapper<PFPlatformSpecificValidateAmazonReceiptResult, Alloc>{ model },
        m_fulfillments{ model.fulfillments, model.fulfillments + model.fulfillmentsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateAmazonReceiptResultWrapper(const PFPlatformSpecificValidateAmazonReceiptResultWrapper& src) :
        PFPlatformSpecificValidateAmazonReceiptResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateAmazonReceiptResultWrapper(PFPlatformSpecificValidateAmazonReceiptResultWrapper&& src) :
        PFPlatformSpecificValidateAmazonReceiptResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateAmazonReceiptResultWrapper& operator=(PFPlatformSpecificValidateAmazonReceiptResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateAmazonReceiptResultWrapper() = default;

    friend void swap(PFPlatformSpecificValidateAmazonReceiptResultWrapper& lhs, PFPlatformSpecificValidateAmazonReceiptResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fulfillments, rhs.m_fulfillments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFulfillments(ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> value)
    {
        m_fulfillments = std::move(value);
        this->m_model.fulfillments =  m_fulfillments.empty() ? nullptr : m_fulfillments.data();
        this->m_model.fulfillmentsCount =  static_cast<uint32_t>(m_fulfillments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.fulfillments = m_fulfillments.empty() ? nullptr : m_fulfillments.data();
    }

    ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> m_fulfillments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper : public ModelWrapper<PFPlatformSpecificValidateGooglePlayPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateGooglePlayPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper() = default;

    PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper(const PFPlatformSpecificValidateGooglePlayPurchaseRequest& model) :
        ModelWrapper<PFPlatformSpecificValidateGooglePlayPurchaseRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_currencyCode{ SafeString(model.currencyCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_purchasePrice{ model.purchasePrice ? StdExtra::optional<uint32_t>{ *model.purchasePrice } : StdExtra::nullopt },
        m_receiptJson{ SafeString(model.receiptJson) },
        m_signature{ SafeString(model.signature) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper(const PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper& src) :
        PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper(PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper&& src) :
        PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper& operator=(PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper() = default;

    friend void swap(PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper& lhs, PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_purchasePrice, rhs.m_purchasePrice);
        swap(lhs.m_receiptJson, rhs.m_receiptJson);
        swap(lhs.m_signature, rhs.m_signature);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPurchasePrice(StdExtra::optional<uint32_t> value)
    {
        m_purchasePrice = std::move(value);
        this->m_model.purchasePrice = m_purchasePrice ? m_purchasePrice.operator->() : nullptr;
    }

    void SetReceiptJson(String value)
    {
        m_receiptJson = std::move(value);
        this->m_model.receiptJson =  m_receiptJson.empty() ? nullptr : m_receiptJson.data();
    }

    void SetSignature(String value)
    {
        m_signature = std::move(value);
        this->m_model.signature =  m_signature.empty() ? nullptr : m_signature.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.purchasePrice = m_purchasePrice ? m_purchasePrice.operator->() : nullptr;
        this->m_model.receiptJson = m_receiptJson.empty() ? nullptr : m_receiptJson.data();
        this->m_model.signature = m_signature.empty() ? nullptr : m_signature.data();
    }

    String m_catalogVersion;
    String m_currencyCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<uint32_t> m_purchasePrice;
    String m_receiptJson;
    String m_signature;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper : public ModelWrapper<PFPlatformSpecificValidateGooglePlayPurchaseResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateGooglePlayPurchaseResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper() = default;

    PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper(const PFPlatformSpecificValidateGooglePlayPurchaseResult& model) :
        ModelWrapper<PFPlatformSpecificValidateGooglePlayPurchaseResult, Alloc>{ model },
        m_fulfillments{ model.fulfillments, model.fulfillments + model.fulfillmentsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper(const PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper& src) :
        PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper(PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper&& src) :
        PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper& operator=(PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper() = default;

    friend void swap(PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper& lhs, PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fulfillments, rhs.m_fulfillments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFulfillments(ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> value)
    {
        m_fulfillments = std::move(value);
        this->m_model.fulfillments =  m_fulfillments.empty() ? nullptr : m_fulfillments.data();
        this->m_model.fulfillmentsCount =  static_cast<uint32_t>(m_fulfillments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.fulfillments = m_fulfillments.empty() ? nullptr : m_fulfillments.data();
    }

    ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> m_fulfillments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateIOSReceiptRequestWrapper : public ModelWrapper<PFPlatformSpecificValidateIOSReceiptRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateIOSReceiptRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateIOSReceiptRequestWrapper() = default;

    PFPlatformSpecificValidateIOSReceiptRequestWrapper(const PFPlatformSpecificValidateIOSReceiptRequest& model) :
        ModelWrapper<PFPlatformSpecificValidateIOSReceiptRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_currencyCode{ SafeString(model.currencyCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_receiptData{ SafeString(model.receiptData) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateIOSReceiptRequestWrapper(const PFPlatformSpecificValidateIOSReceiptRequestWrapper& src) :
        PFPlatformSpecificValidateIOSReceiptRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateIOSReceiptRequestWrapper(PFPlatformSpecificValidateIOSReceiptRequestWrapper&& src) :
        PFPlatformSpecificValidateIOSReceiptRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateIOSReceiptRequestWrapper& operator=(PFPlatformSpecificValidateIOSReceiptRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateIOSReceiptRequestWrapper() = default;

    friend void swap(PFPlatformSpecificValidateIOSReceiptRequestWrapper& lhs, PFPlatformSpecificValidateIOSReceiptRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_receiptData, rhs.m_receiptData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPurchasePrice(int32_t value)
    {
        this->m_model.purchasePrice = value;
    }

    void SetReceiptData(String value)
    {
        m_receiptData = std::move(value);
        this->m_model.receiptData =  m_receiptData.empty() ? nullptr : m_receiptData.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.receiptData = m_receiptData.empty() ? nullptr : m_receiptData.data();
    }

    String m_catalogVersion;
    String m_currencyCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_receiptData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateIOSReceiptResultWrapper : public ModelWrapper<PFPlatformSpecificValidateIOSReceiptResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateIOSReceiptResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateIOSReceiptResultWrapper() = default;

    PFPlatformSpecificValidateIOSReceiptResultWrapper(const PFPlatformSpecificValidateIOSReceiptResult& model) :
        ModelWrapper<PFPlatformSpecificValidateIOSReceiptResult, Alloc>{ model },
        m_fulfillments{ model.fulfillments, model.fulfillments + model.fulfillmentsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateIOSReceiptResultWrapper(const PFPlatformSpecificValidateIOSReceiptResultWrapper& src) :
        PFPlatformSpecificValidateIOSReceiptResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateIOSReceiptResultWrapper(PFPlatformSpecificValidateIOSReceiptResultWrapper&& src) :
        PFPlatformSpecificValidateIOSReceiptResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateIOSReceiptResultWrapper& operator=(PFPlatformSpecificValidateIOSReceiptResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateIOSReceiptResultWrapper() = default;

    friend void swap(PFPlatformSpecificValidateIOSReceiptResultWrapper& lhs, PFPlatformSpecificValidateIOSReceiptResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fulfillments, rhs.m_fulfillments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFulfillments(ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> value)
    {
        m_fulfillments = std::move(value);
        this->m_model.fulfillments =  m_fulfillments.empty() ? nullptr : m_fulfillments.data();
        this->m_model.fulfillmentsCount =  static_cast<uint32_t>(m_fulfillments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.fulfillments = m_fulfillments.empty() ? nullptr : m_fulfillments.data();
    }

    ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> m_fulfillments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateWindowsReceiptRequestWrapper : public ModelWrapper<PFPlatformSpecificValidateWindowsReceiptRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateWindowsReceiptRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateWindowsReceiptRequestWrapper() = default;

    PFPlatformSpecificValidateWindowsReceiptRequestWrapper(const PFPlatformSpecificValidateWindowsReceiptRequest& model) :
        ModelWrapper<PFPlatformSpecificValidateWindowsReceiptRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_currencyCode{ SafeString(model.currencyCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_receipt{ SafeString(model.receipt) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateWindowsReceiptRequestWrapper(const PFPlatformSpecificValidateWindowsReceiptRequestWrapper& src) :
        PFPlatformSpecificValidateWindowsReceiptRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateWindowsReceiptRequestWrapper(PFPlatformSpecificValidateWindowsReceiptRequestWrapper&& src) :
        PFPlatformSpecificValidateWindowsReceiptRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateWindowsReceiptRequestWrapper& operator=(PFPlatformSpecificValidateWindowsReceiptRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateWindowsReceiptRequestWrapper() = default;

    friend void swap(PFPlatformSpecificValidateWindowsReceiptRequestWrapper& lhs, PFPlatformSpecificValidateWindowsReceiptRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_receipt, rhs.m_receipt);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPurchasePrice(uint32_t value)
    {
        this->m_model.purchasePrice = value;
    }

    void SetReceipt(String value)
    {
        m_receipt = std::move(value);
        this->m_model.receipt =  m_receipt.empty() ? nullptr : m_receipt.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.receipt = m_receipt.empty() ? nullptr : m_receipt.data();
    }

    String m_catalogVersion;
    String m_currencyCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_receipt;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificValidateWindowsReceiptResultWrapper : public ModelWrapper<PFPlatformSpecificValidateWindowsReceiptResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificValidateWindowsReceiptResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificValidateWindowsReceiptResultWrapper() = default;

    PFPlatformSpecificValidateWindowsReceiptResultWrapper(const PFPlatformSpecificValidateWindowsReceiptResult& model) :
        ModelWrapper<PFPlatformSpecificValidateWindowsReceiptResult, Alloc>{ model },
        m_fulfillments{ model.fulfillments, model.fulfillments + model.fulfillmentsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificValidateWindowsReceiptResultWrapper(const PFPlatformSpecificValidateWindowsReceiptResultWrapper& src) :
        PFPlatformSpecificValidateWindowsReceiptResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificValidateWindowsReceiptResultWrapper(PFPlatformSpecificValidateWindowsReceiptResultWrapper&& src) :
        PFPlatformSpecificValidateWindowsReceiptResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificValidateWindowsReceiptResultWrapper& operator=(PFPlatformSpecificValidateWindowsReceiptResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificValidateWindowsReceiptResultWrapper() = default;

    friend void swap(PFPlatformSpecificValidateWindowsReceiptResultWrapper& lhs, PFPlatformSpecificValidateWindowsReceiptResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_fulfillments, rhs.m_fulfillments);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFulfillments(ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> value)
    {
        m_fulfillments = std::move(value);
        this->m_model.fulfillments =  m_fulfillments.empty() ? nullptr : m_fulfillments.data();
        this->m_model.fulfillmentsCount =  static_cast<uint32_t>(m_fulfillments.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.fulfillments = m_fulfillments.empty() ? nullptr : m_fulfillments.data();
    }

    ModelVector<PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Alloc>, Alloc> m_fulfillments;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificAwardSteamAchievementItemWrapper : public ModelWrapper<PFPlatformSpecificAwardSteamAchievementItem, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificAwardSteamAchievementItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificAwardSteamAchievementItemWrapper() = default;

    PFPlatformSpecificAwardSteamAchievementItemWrapper(const PFPlatformSpecificAwardSteamAchievementItem& model) :
        ModelWrapper<PFPlatformSpecificAwardSteamAchievementItem, Alloc>{ model },
        m_achievementName{ SafeString(model.achievementName) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlatformSpecificAwardSteamAchievementItemWrapper(const PFPlatformSpecificAwardSteamAchievementItemWrapper& src) :
        PFPlatformSpecificAwardSteamAchievementItemWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificAwardSteamAchievementItemWrapper(PFPlatformSpecificAwardSteamAchievementItemWrapper&& src) :
        PFPlatformSpecificAwardSteamAchievementItemWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificAwardSteamAchievementItemWrapper& operator=(PFPlatformSpecificAwardSteamAchievementItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificAwardSteamAchievementItemWrapper() = default;

    friend void swap(PFPlatformSpecificAwardSteamAchievementItemWrapper& lhs, PFPlatformSpecificAwardSteamAchievementItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_achievementName, rhs.m_achievementName);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAchievementName(String value)
    {
        m_achievementName = std::move(value);
        this->m_model.achievementName =  m_achievementName.empty() ? nullptr : m_achievementName.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetResult(bool value)
    {
        this->m_model.result = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.achievementName = m_achievementName.empty() ? nullptr : m_achievementName.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_achievementName;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificAwardSteamAchievementRequestWrapper : public ModelWrapper<PFPlatformSpecificAwardSteamAchievementRequest, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificAwardSteamAchievementRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificAwardSteamAchievementRequestWrapper() = default;

    PFPlatformSpecificAwardSteamAchievementRequestWrapper(const PFPlatformSpecificAwardSteamAchievementRequest& model) :
        ModelWrapper<PFPlatformSpecificAwardSteamAchievementRequest, Alloc>{ model },
        m_achievements{ model.achievements, model.achievements + model.achievementsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificAwardSteamAchievementRequestWrapper(const PFPlatformSpecificAwardSteamAchievementRequestWrapper& src) :
        PFPlatformSpecificAwardSteamAchievementRequestWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificAwardSteamAchievementRequestWrapper(PFPlatformSpecificAwardSteamAchievementRequestWrapper&& src) :
        PFPlatformSpecificAwardSteamAchievementRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificAwardSteamAchievementRequestWrapper& operator=(PFPlatformSpecificAwardSteamAchievementRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificAwardSteamAchievementRequestWrapper() = default;

    friend void swap(PFPlatformSpecificAwardSteamAchievementRequestWrapper& lhs, PFPlatformSpecificAwardSteamAchievementRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_achievements, rhs.m_achievements);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAchievements(ModelVector<PFPlatformSpecificAwardSteamAchievementItemWrapper<Alloc>, Alloc> value)
    {
        m_achievements = std::move(value);
        this->m_model.achievements =  m_achievements.empty() ? nullptr : m_achievements.data();
        this->m_model.achievementsCount =  static_cast<uint32_t>(m_achievements.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.achievements = m_achievements.empty() ? nullptr : m_achievements.data();
    }

    ModelVector<PFPlatformSpecificAwardSteamAchievementItemWrapper<Alloc>, Alloc> m_achievements;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlatformSpecificAwardSteamAchievementResultWrapper : public ModelWrapper<PFPlatformSpecificAwardSteamAchievementResult, Alloc>
{
public:
    using ModelType = typename PFPlatformSpecificAwardSteamAchievementResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlatformSpecificAwardSteamAchievementResultWrapper() = default;

    PFPlatformSpecificAwardSteamAchievementResultWrapper(const PFPlatformSpecificAwardSteamAchievementResult& model) :
        ModelWrapper<PFPlatformSpecificAwardSteamAchievementResult, Alloc>{ model },
        m_achievementResults{ model.achievementResults, model.achievementResults + model.achievementResultsCount }
    {
        SetModelPointers();
    }

    PFPlatformSpecificAwardSteamAchievementResultWrapper(const PFPlatformSpecificAwardSteamAchievementResultWrapper& src) :
        PFPlatformSpecificAwardSteamAchievementResultWrapper{ src.Model() }
    {
    }

    PFPlatformSpecificAwardSteamAchievementResultWrapper(PFPlatformSpecificAwardSteamAchievementResultWrapper&& src) :
        PFPlatformSpecificAwardSteamAchievementResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlatformSpecificAwardSteamAchievementResultWrapper& operator=(PFPlatformSpecificAwardSteamAchievementResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlatformSpecificAwardSteamAchievementResultWrapper() = default;

    friend void swap(PFPlatformSpecificAwardSteamAchievementResultWrapper& lhs, PFPlatformSpecificAwardSteamAchievementResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_achievementResults, rhs.m_achievementResults);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAchievementResults(ModelVector<PFPlatformSpecificAwardSteamAchievementItemWrapper<Alloc>, Alloc> value)
    {
        m_achievementResults = std::move(value);
        this->m_model.achievementResults =  m_achievementResults.empty() ? nullptr : m_achievementResults.data();
        this->m_model.achievementResultsCount =  static_cast<uint32_t>(m_achievementResults.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.achievementResults = m_achievementResults.empty() ? nullptr : m_achievementResults.data();
    }

    ModelVector<PFPlatformSpecificAwardSteamAchievementItemWrapper<Alloc>, Alloc> m_achievementResults;
};

} // namespace Wrappers
} // namespace PlayFab
