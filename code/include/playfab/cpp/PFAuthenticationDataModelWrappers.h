// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFAuthenticationDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper : public ModelWrapper<PFAuthenticationAuthenticateCustomIdIdentityRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationAuthenticateCustomIdIdentityRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper() = default;

    PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper(const PFAuthenticationAuthenticateCustomIdIdentityRequest& model) :
        ModelWrapper<PFAuthenticationAuthenticateCustomIdIdentityRequest, Alloc>{ model },
        m_customId{ SafeString(model.customId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_existingMasterPlayerAccountId{ SafeString(model.existingMasterPlayerAccountId) }
    {
        SetModelPointers();
    }

    PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper(const PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper& src) :
        PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper(PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper&& src) :
        PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper& operator=(PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper() = default;

    friend void swap(PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper& lhs, PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customId, rhs.m_customId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_existingMasterPlayerAccountId, rhs.m_existingMasterPlayerAccountId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBehaviorIfIdentityNotLinked(PFAuthenticationAccountLinkAction value)
    {
        this->m_model.behaviorIfIdentityNotLinked = value;
    }

    void SetCustomId(String value)
    {
        m_customId = std::move(value);
        this->m_model.customId =  m_customId.empty() ? nullptr : m_customId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExistingMasterPlayerAccountId(String value)
    {
        m_existingMasterPlayerAccountId = std::move(value);
        this->m_model.existingMasterPlayerAccountId =  m_existingMasterPlayerAccountId.empty() ? nullptr : m_existingMasterPlayerAccountId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customId = m_customId.empty() ? nullptr : m_customId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.existingMasterPlayerAccountId = m_existingMasterPlayerAccountId.empty() ? nullptr : m_existingMasterPlayerAccountId.data();
    }

    String m_customId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_existingMasterPlayerAccountId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper : public ModelWrapper<PFAuthenticationGetLinkedPlayerIdentitiesRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetLinkedPlayerIdentitiesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper() = default;

    PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper(const PFAuthenticationGetLinkedPlayerIdentitiesRequest& model) :
        ModelWrapper<PFAuthenticationGetLinkedPlayerIdentitiesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_masterPlayerAccountId{ SafeString(model.masterPlayerAccountId) }
    {
        SetModelPointers();
    }

    PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper(const PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper& src) :
        PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper(PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper&& src) :
        PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper& operator=(PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper() = default;

    friend void swap(PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper& lhs, PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_masterPlayerAccountId, rhs.m_masterPlayerAccountId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMasterPlayerAccountId(String value)
    {
        m_masterPlayerAccountId = std::move(value);
        this->m_model.masterPlayerAccountId =  m_masterPlayerAccountId.empty() ? nullptr : m_masterPlayerAccountId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.masterPlayerAccountId = m_masterPlayerAccountId.empty() ? nullptr : m_masterPlayerAccountId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_masterPlayerAccountId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLinkedPlayerIdentityWrapper : public ModelWrapper<PFAuthenticationLinkedPlayerIdentity, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLinkedPlayerIdentity;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLinkedPlayerIdentityWrapper() = default;

    PFAuthenticationLinkedPlayerIdentityWrapper(const PFAuthenticationLinkedPlayerIdentity& model) :
        ModelWrapper<PFAuthenticationLinkedPlayerIdentity, Alloc>{ model },
        m_identityLinkId{ SafeString(model.identityLinkId) },
        m_identityProviderIssuedId{ SafeString(model.identityProviderIssuedId) }
    {
        SetModelPointers();
    }

    PFAuthenticationLinkedPlayerIdentityWrapper(const PFAuthenticationLinkedPlayerIdentityWrapper& src) :
        PFAuthenticationLinkedPlayerIdentityWrapper{ src.Model() }
    {
    }

    PFAuthenticationLinkedPlayerIdentityWrapper(PFAuthenticationLinkedPlayerIdentityWrapper&& src) :
        PFAuthenticationLinkedPlayerIdentityWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLinkedPlayerIdentityWrapper& operator=(PFAuthenticationLinkedPlayerIdentityWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLinkedPlayerIdentityWrapper() = default;

    friend void swap(PFAuthenticationLinkedPlayerIdentityWrapper& lhs, PFAuthenticationLinkedPlayerIdentityWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_identityLinkId, rhs.m_identityLinkId);
        swap(lhs.m_identityProviderIssuedId, rhs.m_identityProviderIssuedId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIdentityLinkId(String value)
    {
        m_identityLinkId = std::move(value);
        this->m_model.identityLinkId =  m_identityLinkId.empty() ? nullptr : m_identityLinkId.data();
    }

    void SetIdentityProvider(PFAuthenticationPlayerIdentityProvider value)
    {
        this->m_model.identityProvider = value;
    }

    void SetIdentityProviderIssuedId(String value)
    {
        m_identityProviderIssuedId = std::move(value);
        this->m_model.identityProviderIssuedId =  m_identityProviderIssuedId.empty() ? nullptr : m_identityProviderIssuedId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.identityLinkId = m_identityLinkId.empty() ? nullptr : m_identityLinkId.data();
        this->m_model.identityProviderIssuedId = m_identityProviderIssuedId.empty() ? nullptr : m_identityProviderIssuedId.data();
    }

    String m_identityLinkId;
    String m_identityProviderIssuedId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper : public ModelWrapper<PFAuthenticationGetLinkedPlayerIdentitiesResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetLinkedPlayerIdentitiesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper() = default;

    PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper(const PFAuthenticationGetLinkedPlayerIdentitiesResult& model) :
        ModelWrapper<PFAuthenticationGetLinkedPlayerIdentitiesResult, Alloc>{ model },
        m_linkedIdentities{ model.linkedIdentities, model.linkedIdentities + model.linkedIdentitiesCount }
    {
        SetModelPointers();
    }

    PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper(const PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper& src) :
        PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper(PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper&& src) :
        PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper& operator=(PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper() = default;

    friend void swap(PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper& lhs, PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_linkedIdentities, rhs.m_linkedIdentities);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLinkedIdentities(ModelVector<PFAuthenticationLinkedPlayerIdentityWrapper<Alloc>, Alloc> value)
    {
        m_linkedIdentities = std::move(value);
        this->m_model.linkedIdentities =  m_linkedIdentities.empty() ? nullptr : m_linkedIdentities.data();
        this->m_model.linkedIdentitiesCount =  static_cast<uint32_t>(m_linkedIdentities.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.linkedIdentities = m_linkedIdentities.empty() ? nullptr : m_linkedIdentities.data();
    }

    ModelVector<PFAuthenticationLinkedPlayerIdentityWrapper<Alloc>, Alloc> m_linkedIdentities;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationUnlinkPlayerIdentityRequestWrapper : public ModelWrapper<PFAuthenticationUnlinkPlayerIdentityRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationUnlinkPlayerIdentityRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationUnlinkPlayerIdentityRequestWrapper() = default;

    PFAuthenticationUnlinkPlayerIdentityRequestWrapper(const PFAuthenticationUnlinkPlayerIdentityRequest& model) :
        ModelWrapper<PFAuthenticationUnlinkPlayerIdentityRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_identityLinkId{ SafeString(model.identityLinkId) },
        m_masterPlayerAccountId{ SafeString(model.masterPlayerAccountId) }
    {
        SetModelPointers();
    }

    PFAuthenticationUnlinkPlayerIdentityRequestWrapper(const PFAuthenticationUnlinkPlayerIdentityRequestWrapper& src) :
        PFAuthenticationUnlinkPlayerIdentityRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationUnlinkPlayerIdentityRequestWrapper(PFAuthenticationUnlinkPlayerIdentityRequestWrapper&& src) :
        PFAuthenticationUnlinkPlayerIdentityRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationUnlinkPlayerIdentityRequestWrapper& operator=(PFAuthenticationUnlinkPlayerIdentityRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationUnlinkPlayerIdentityRequestWrapper() = default;

    friend void swap(PFAuthenticationUnlinkPlayerIdentityRequestWrapper& lhs, PFAuthenticationUnlinkPlayerIdentityRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_identityLinkId, rhs.m_identityLinkId);
        swap(lhs.m_masterPlayerAccountId, rhs.m_masterPlayerAccountId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetIdentityLinkId(String value)
    {
        m_identityLinkId = std::move(value);
        this->m_model.identityLinkId =  m_identityLinkId.empty() ? nullptr : m_identityLinkId.data();
    }

    void SetMasterPlayerAccountId(String value)
    {
        m_masterPlayerAccountId = std::move(value);
        this->m_model.masterPlayerAccountId =  m_masterPlayerAccountId.empty() ? nullptr : m_masterPlayerAccountId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.identityLinkId = m_identityLinkId.empty() ? nullptr : m_identityLinkId.data();
        this->m_model.masterPlayerAccountId = m_masterPlayerAccountId.empty() ? nullptr : m_masterPlayerAccountId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_identityLinkId;
    String m_masterPlayerAccountId;
};

} // namespace Wrappers
} // namespace PlayFab
