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
class PFAuthenticationOpenIdIssuerInformationWrapper : public ModelWrapper<PFAuthenticationOpenIdIssuerInformation, Alloc>
{
public:
    using ModelType = typename PFAuthenticationOpenIdIssuerInformation;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationOpenIdIssuerInformationWrapper() = default;

    PFAuthenticationOpenIdIssuerInformationWrapper(const PFAuthenticationOpenIdIssuerInformation& model) :
        ModelWrapper<PFAuthenticationOpenIdIssuerInformation, Alloc>{ model },
        m_authorizationUrl{ SafeString(model.authorizationUrl) },
        m_issuer{ SafeString(model.issuer) },
        m_jsonWebKeySet{ model.jsonWebKeySet },
        m_tokenUrl{ SafeString(model.tokenUrl) }
    {
        SetModelPointers();
    }

    PFAuthenticationOpenIdIssuerInformationWrapper(const PFAuthenticationOpenIdIssuerInformationWrapper& src) :
        PFAuthenticationOpenIdIssuerInformationWrapper{ src.Model() }
    {
    }

    PFAuthenticationOpenIdIssuerInformationWrapper(PFAuthenticationOpenIdIssuerInformationWrapper&& src) :
        PFAuthenticationOpenIdIssuerInformationWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationOpenIdIssuerInformationWrapper& operator=(PFAuthenticationOpenIdIssuerInformationWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationOpenIdIssuerInformationWrapper() = default;

    friend void swap(PFAuthenticationOpenIdIssuerInformationWrapper& lhs, PFAuthenticationOpenIdIssuerInformationWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authorizationUrl, rhs.m_authorizationUrl);
        swap(lhs.m_issuer, rhs.m_issuer);
        swap(lhs.m_jsonWebKeySet, rhs.m_jsonWebKeySet);
        swap(lhs.m_tokenUrl, rhs.m_tokenUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthorizationUrl(String value)
    {
        m_authorizationUrl = std::move(value);
        this->m_model.authorizationUrl =  m_authorizationUrl.empty() ? nullptr : m_authorizationUrl.data();
    }

    void SetIssuer(String value)
    {
        m_issuer = std::move(value);
        this->m_model.issuer =  m_issuer.empty() ? nullptr : m_issuer.data();
    }

    void SetJsonWebKeySet(JsonObject<Alloc> value)
    {
        m_jsonWebKeySet = std::move(value);
        this->m_model.jsonWebKeySet.stringValue = m_jsonWebKeySet.stringValue.empty() ? nullptr : m_jsonWebKeySet.stringValue.data();
    }

    void SetTokenUrl(String value)
    {
        m_tokenUrl = std::move(value);
        this->m_model.tokenUrl =  m_tokenUrl.empty() ? nullptr : m_tokenUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authorizationUrl = m_authorizationUrl.empty() ? nullptr : m_authorizationUrl.data();
        this->m_model.issuer = m_issuer.empty() ? nullptr : m_issuer.data();
        this->m_model.jsonWebKeySet.stringValue = m_jsonWebKeySet.stringValue.empty() ? nullptr : m_jsonWebKeySet.stringValue.data();
        this->m_model.tokenUrl = m_tokenUrl.empty() ? nullptr : m_tokenUrl.data();
    }

    String m_authorizationUrl;
    String m_issuer;
    JsonObject<Alloc> m_jsonWebKeySet;
    String m_tokenUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationCreateOpenIdConnectionRequestWrapper : public ModelWrapper<PFAuthenticationCreateOpenIdConnectionRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationCreateOpenIdConnectionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationCreateOpenIdConnectionRequestWrapper() = default;

    PFAuthenticationCreateOpenIdConnectionRequestWrapper(const PFAuthenticationCreateOpenIdConnectionRequest& model) :
        ModelWrapper<PFAuthenticationCreateOpenIdConnectionRequest, Alloc>{ model },
        m_clientId{ SafeString(model.clientId) },
        m_clientSecret{ SafeString(model.clientSecret) },
        m_connectionId{ SafeString(model.connectionId) },
        m_ignoreNonce{ model.ignoreNonce ? StdExtra::optional<bool>{ *model.ignoreNonce } : StdExtra::nullopt },
        m_issuerDiscoveryUrl{ SafeString(model.issuerDiscoveryUrl) },
        m_issuerInformation{ model.issuerInformation ? StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>>{ *model.issuerInformation } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationCreateOpenIdConnectionRequestWrapper(const PFAuthenticationCreateOpenIdConnectionRequestWrapper& src) :
        PFAuthenticationCreateOpenIdConnectionRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationCreateOpenIdConnectionRequestWrapper(PFAuthenticationCreateOpenIdConnectionRequestWrapper&& src) :
        PFAuthenticationCreateOpenIdConnectionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationCreateOpenIdConnectionRequestWrapper& operator=(PFAuthenticationCreateOpenIdConnectionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationCreateOpenIdConnectionRequestWrapper() = default;

    friend void swap(PFAuthenticationCreateOpenIdConnectionRequestWrapper& lhs, PFAuthenticationCreateOpenIdConnectionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_clientId, rhs.m_clientId);
        swap(lhs.m_clientSecret, rhs.m_clientSecret);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_ignoreNonce, rhs.m_ignoreNonce);
        swap(lhs.m_issuerDiscoveryUrl, rhs.m_issuerDiscoveryUrl);
        swap(lhs.m_issuerInformation, rhs.m_issuerInformation);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetClientId(String value)
    {
        m_clientId = std::move(value);
        this->m_model.clientId =  m_clientId.empty() ? nullptr : m_clientId.data();
    }

    void SetClientSecret(String value)
    {
        m_clientSecret = std::move(value);
        this->m_model.clientSecret =  m_clientSecret.empty() ? nullptr : m_clientSecret.data();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetIgnoreNonce(StdExtra::optional<bool> value)
    {
        m_ignoreNonce = std::move(value);
        this->m_model.ignoreNonce = m_ignoreNonce ? m_ignoreNonce.operator->() : nullptr;
    }

    void SetIssuerDiscoveryUrl(String value)
    {
        m_issuerDiscoveryUrl = std::move(value);
        this->m_model.issuerDiscoveryUrl =  m_issuerDiscoveryUrl.empty() ? nullptr : m_issuerDiscoveryUrl.data();
    }

    void SetIssuerInformation(StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>> value)
    {
        m_issuerInformation = std::move(value);
        this->m_model.issuerInformation = m_issuerInformation ? &m_issuerInformation->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.clientId = m_clientId.empty() ? nullptr : m_clientId.data();
        this->m_model.clientSecret = m_clientSecret.empty() ? nullptr : m_clientSecret.data();
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.ignoreNonce = m_ignoreNonce ? m_ignoreNonce.operator->() : nullptr;
        this->m_model.issuerDiscoveryUrl = m_issuerDiscoveryUrl.empty() ? nullptr : m_issuerDiscoveryUrl.data();
        this->m_model.issuerInformation = m_issuerInformation ?  &m_issuerInformation->Model() : nullptr;
    }

    String m_clientId;
    String m_clientSecret;
    String m_connectionId;
    StdExtra::optional<bool> m_ignoreNonce;
    String m_issuerDiscoveryUrl;
    StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>> m_issuerInformation;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationCreatePlayerSharedSecretRequestWrapper : public ModelWrapper<PFAuthenticationCreatePlayerSharedSecretRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationCreatePlayerSharedSecretRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper() = default;

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper(const PFAuthenticationCreatePlayerSharedSecretRequest& model) :
        ModelWrapper<PFAuthenticationCreatePlayerSharedSecretRequest, Alloc>{ model },
        m_friendlyName{ SafeString(model.friendlyName) }
    {
        SetModelPointers();
    }

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper(const PFAuthenticationCreatePlayerSharedSecretRequestWrapper& src) :
        PFAuthenticationCreatePlayerSharedSecretRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper(PFAuthenticationCreatePlayerSharedSecretRequestWrapper&& src) :
        PFAuthenticationCreatePlayerSharedSecretRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper& operator=(PFAuthenticationCreatePlayerSharedSecretRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationCreatePlayerSharedSecretRequestWrapper() = default;

    friend void swap(PFAuthenticationCreatePlayerSharedSecretRequestWrapper& lhs, PFAuthenticationCreatePlayerSharedSecretRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_friendlyName, rhs.m_friendlyName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFriendlyName(String value)
    {
        m_friendlyName = std::move(value);
        this->m_model.friendlyName =  m_friendlyName.empty() ? nullptr : m_friendlyName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.friendlyName = m_friendlyName.empty() ? nullptr : m_friendlyName.data();
    }

    String m_friendlyName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationCreatePlayerSharedSecretResultWrapper : public ModelWrapper<PFAuthenticationCreatePlayerSharedSecretResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationCreatePlayerSharedSecretResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationCreatePlayerSharedSecretResultWrapper() = default;

    PFAuthenticationCreatePlayerSharedSecretResultWrapper(const PFAuthenticationCreatePlayerSharedSecretResult& model) :
        ModelWrapper<PFAuthenticationCreatePlayerSharedSecretResult, Alloc>{ model },
        m_secretKey{ SafeString(model.secretKey) }
    {
        SetModelPointers();
    }

    PFAuthenticationCreatePlayerSharedSecretResultWrapper(const PFAuthenticationCreatePlayerSharedSecretResultWrapper& src) :
        PFAuthenticationCreatePlayerSharedSecretResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationCreatePlayerSharedSecretResultWrapper(PFAuthenticationCreatePlayerSharedSecretResultWrapper&& src) :
        PFAuthenticationCreatePlayerSharedSecretResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationCreatePlayerSharedSecretResultWrapper& operator=(PFAuthenticationCreatePlayerSharedSecretResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationCreatePlayerSharedSecretResultWrapper() = default;

    friend void swap(PFAuthenticationCreatePlayerSharedSecretResultWrapper& lhs, PFAuthenticationCreatePlayerSharedSecretResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_secretKey, rhs.m_secretKey);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSecretKey(String value)
    {
        m_secretKey = std::move(value);
        this->m_model.secretKey =  m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.secretKey = m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

    String m_secretKey;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationDeleteOpenIdConnectionRequestWrapper : public ModelWrapper<PFAuthenticationDeleteOpenIdConnectionRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationDeleteOpenIdConnectionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper() = default;

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper(const PFAuthenticationDeleteOpenIdConnectionRequest& model) :
        ModelWrapper<PFAuthenticationDeleteOpenIdConnectionRequest, Alloc>{ model },
        m_connectionId{ SafeString(model.connectionId) }
    {
        SetModelPointers();
    }

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper(const PFAuthenticationDeleteOpenIdConnectionRequestWrapper& src) :
        PFAuthenticationDeleteOpenIdConnectionRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper(PFAuthenticationDeleteOpenIdConnectionRequestWrapper&& src) :
        PFAuthenticationDeleteOpenIdConnectionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper& operator=(PFAuthenticationDeleteOpenIdConnectionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationDeleteOpenIdConnectionRequestWrapper() = default;

    friend void swap(PFAuthenticationDeleteOpenIdConnectionRequestWrapper& lhs, PFAuthenticationDeleteOpenIdConnectionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    String m_connectionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationDeletePlayerSharedSecretRequestWrapper : public ModelWrapper<PFAuthenticationDeletePlayerSharedSecretRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationDeletePlayerSharedSecretRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper() = default;

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper(const PFAuthenticationDeletePlayerSharedSecretRequest& model) :
        ModelWrapper<PFAuthenticationDeletePlayerSharedSecretRequest, Alloc>{ model },
        m_secretKey{ SafeString(model.secretKey) }
    {
        SetModelPointers();
    }

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper(const PFAuthenticationDeletePlayerSharedSecretRequestWrapper& src) :
        PFAuthenticationDeletePlayerSharedSecretRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper(PFAuthenticationDeletePlayerSharedSecretRequestWrapper&& src) :
        PFAuthenticationDeletePlayerSharedSecretRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper& operator=(PFAuthenticationDeletePlayerSharedSecretRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationDeletePlayerSharedSecretRequestWrapper() = default;

    friend void swap(PFAuthenticationDeletePlayerSharedSecretRequestWrapper& lhs, PFAuthenticationDeletePlayerSharedSecretRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_secretKey, rhs.m_secretKey);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSecretKey(String value)
    {
        m_secretKey = std::move(value);
        this->m_model.secretKey =  m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.secretKey = m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

    String m_secretKey;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationSharedSecretWrapper : public ModelWrapper<PFAuthenticationSharedSecret, Alloc>
{
public:
    using ModelType = typename PFAuthenticationSharedSecret;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationSharedSecretWrapper() = default;

    PFAuthenticationSharedSecretWrapper(const PFAuthenticationSharedSecret& model) :
        ModelWrapper<PFAuthenticationSharedSecret, Alloc>{ model },
        m_friendlyName{ SafeString(model.friendlyName) },
        m_secretKey{ SafeString(model.secretKey) }
    {
        SetModelPointers();
    }

    PFAuthenticationSharedSecretWrapper(const PFAuthenticationSharedSecretWrapper& src) :
        PFAuthenticationSharedSecretWrapper{ src.Model() }
    {
    }

    PFAuthenticationSharedSecretWrapper(PFAuthenticationSharedSecretWrapper&& src) :
        PFAuthenticationSharedSecretWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationSharedSecretWrapper& operator=(PFAuthenticationSharedSecretWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationSharedSecretWrapper() = default;

    friend void swap(PFAuthenticationSharedSecretWrapper& lhs, PFAuthenticationSharedSecretWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_friendlyName, rhs.m_friendlyName);
        swap(lhs.m_secretKey, rhs.m_secretKey);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDisabled(bool value)
    {
        this->m_model.disabled = value;
    }

    void SetFriendlyName(String value)
    {
        m_friendlyName = std::move(value);
        this->m_model.friendlyName =  m_friendlyName.empty() ? nullptr : m_friendlyName.data();
    }

    void SetSecretKey(String value)
    {
        m_secretKey = std::move(value);
        this->m_model.secretKey =  m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.friendlyName = m_friendlyName.empty() ? nullptr : m_friendlyName.data();
        this->m_model.secretKey = m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

    String m_friendlyName;
    String m_secretKey;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetPlayerSharedSecretsResultWrapper : public ModelWrapper<PFAuthenticationGetPlayerSharedSecretsResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetPlayerSharedSecretsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetPlayerSharedSecretsResultWrapper() = default;

    PFAuthenticationGetPlayerSharedSecretsResultWrapper(const PFAuthenticationGetPlayerSharedSecretsResult& model) :
        ModelWrapper<PFAuthenticationGetPlayerSharedSecretsResult, Alloc>{ model },
        m_sharedSecrets{ model.sharedSecrets, model.sharedSecrets + model.sharedSecretsCount }
    {
        SetModelPointers();
    }

    PFAuthenticationGetPlayerSharedSecretsResultWrapper(const PFAuthenticationGetPlayerSharedSecretsResultWrapper& src) :
        PFAuthenticationGetPlayerSharedSecretsResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetPlayerSharedSecretsResultWrapper(PFAuthenticationGetPlayerSharedSecretsResultWrapper&& src) :
        PFAuthenticationGetPlayerSharedSecretsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetPlayerSharedSecretsResultWrapper& operator=(PFAuthenticationGetPlayerSharedSecretsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetPlayerSharedSecretsResultWrapper() = default;

    friend void swap(PFAuthenticationGetPlayerSharedSecretsResultWrapper& lhs, PFAuthenticationGetPlayerSharedSecretsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_sharedSecrets, rhs.m_sharedSecrets);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSharedSecrets(ModelVector<PFAuthenticationSharedSecretWrapper<Alloc>, Alloc> value)
    {
        m_sharedSecrets = std::move(value);
        this->m_model.sharedSecrets =  m_sharedSecrets.empty() ? nullptr : m_sharedSecrets.data();
        this->m_model.sharedSecretsCount =  static_cast<uint32_t>(m_sharedSecrets.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.sharedSecrets = m_sharedSecrets.empty() ? nullptr : m_sharedSecrets.data();
    }

    ModelVector<PFAuthenticationSharedSecretWrapper<Alloc>, Alloc> m_sharedSecrets;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetPolicyRequestWrapper : public ModelWrapper<PFAuthenticationGetPolicyRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetPolicyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetPolicyRequestWrapper() = default;

    PFAuthenticationGetPolicyRequestWrapper(const PFAuthenticationGetPolicyRequest& model) :
        ModelWrapper<PFAuthenticationGetPolicyRequest, Alloc>{ model },
        m_policyName{ SafeString(model.policyName) }
    {
        SetModelPointers();
    }

    PFAuthenticationGetPolicyRequestWrapper(const PFAuthenticationGetPolicyRequestWrapper& src) :
        PFAuthenticationGetPolicyRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetPolicyRequestWrapper(PFAuthenticationGetPolicyRequestWrapper&& src) :
        PFAuthenticationGetPolicyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetPolicyRequestWrapper& operator=(PFAuthenticationGetPolicyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetPolicyRequestWrapper() = default;

    friend void swap(PFAuthenticationGetPolicyRequestWrapper& lhs, PFAuthenticationGetPolicyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_policyName, rhs.m_policyName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPolicyName(String value)
    {
        m_policyName = std::move(value);
        this->m_model.policyName =  m_policyName.empty() ? nullptr : m_policyName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.policyName = m_policyName.empty() ? nullptr : m_policyName.data();
    }

    String m_policyName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationApiConditionWrapper : public ModelWrapper<PFAuthenticationApiCondition, Alloc>
{
public:
    using ModelType = typename PFAuthenticationApiCondition;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationApiConditionWrapper() = default;

    PFAuthenticationApiConditionWrapper(const PFAuthenticationApiCondition& model) :
        ModelWrapper<PFAuthenticationApiCondition, Alloc>{ model },
        m_hasSignatureOrEncryption{ model.hasSignatureOrEncryption ? StdExtra::optional<PFAuthenticationConditionals>{ *model.hasSignatureOrEncryption } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationApiConditionWrapper(const PFAuthenticationApiConditionWrapper& src) :
        PFAuthenticationApiConditionWrapper{ src.Model() }
    {
    }

    PFAuthenticationApiConditionWrapper(PFAuthenticationApiConditionWrapper&& src) :
        PFAuthenticationApiConditionWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationApiConditionWrapper& operator=(PFAuthenticationApiConditionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationApiConditionWrapper() = default;

    friend void swap(PFAuthenticationApiConditionWrapper& lhs, PFAuthenticationApiConditionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_hasSignatureOrEncryption, rhs.m_hasSignatureOrEncryption);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetHasSignatureOrEncryption(StdExtra::optional<PFAuthenticationConditionals> value)
    {
        m_hasSignatureOrEncryption = std::move(value);
        this->m_model.hasSignatureOrEncryption = m_hasSignatureOrEncryption ? m_hasSignatureOrEncryption.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.hasSignatureOrEncryption = m_hasSignatureOrEncryption ? m_hasSignatureOrEncryption.operator->() : nullptr;
    }

    StdExtra::optional<PFAuthenticationConditionals> m_hasSignatureOrEncryption;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationPermissionStatementWrapper : public ModelWrapper<PFAuthenticationPermissionStatement, Alloc>
{
public:
    using ModelType = typename PFAuthenticationPermissionStatement;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationPermissionStatementWrapper() = default;

    PFAuthenticationPermissionStatementWrapper(const PFAuthenticationPermissionStatement& model) :
        ModelWrapper<PFAuthenticationPermissionStatement, Alloc>{ model },
        m_action{ SafeString(model.action) },
        m_apiConditions{ model.apiConditions ? StdExtra::optional<PFAuthenticationApiConditionWrapper<Alloc>>{ *model.apiConditions } : StdExtra::nullopt },
        m_comment{ SafeString(model.comment) },
        m_principal{ SafeString(model.principal) },
        m_resource{ SafeString(model.resource) }
    {
        SetModelPointers();
    }

    PFAuthenticationPermissionStatementWrapper(const PFAuthenticationPermissionStatementWrapper& src) :
        PFAuthenticationPermissionStatementWrapper{ src.Model() }
    {
    }

    PFAuthenticationPermissionStatementWrapper(PFAuthenticationPermissionStatementWrapper&& src) :
        PFAuthenticationPermissionStatementWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationPermissionStatementWrapper& operator=(PFAuthenticationPermissionStatementWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationPermissionStatementWrapper() = default;

    friend void swap(PFAuthenticationPermissionStatementWrapper& lhs, PFAuthenticationPermissionStatementWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_action, rhs.m_action);
        swap(lhs.m_apiConditions, rhs.m_apiConditions);
        swap(lhs.m_comment, rhs.m_comment);
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

    void SetApiConditions(StdExtra::optional<PFAuthenticationApiConditionWrapper<Alloc>> value)
    {
        m_apiConditions = std::move(value);
        this->m_model.apiConditions = m_apiConditions ? &m_apiConditions->Model() : nullptr;
    }

    void SetComment(String value)
    {
        m_comment = std::move(value);
        this->m_model.comment =  m_comment.empty() ? nullptr : m_comment.data();
    }

    void SetEffect(PFEffectType value)
    {
        this->m_model.effect = value;
    }

    void SetPrincipal(String value)
    {
        m_principal = std::move(value);
        this->m_model.principal =  m_principal.empty() ? nullptr : m_principal.data();
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
        this->m_model.apiConditions = m_apiConditions ?  &m_apiConditions->Model() : nullptr;
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.principal = m_principal.empty() ? nullptr : m_principal.data();
        this->m_model.resource = m_resource.empty() ? nullptr : m_resource.data();
    }

    String m_action;
    StdExtra::optional<PFAuthenticationApiConditionWrapper<Alloc>> m_apiConditions;
    String m_comment;
    String m_principal;
    String m_resource;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetPolicyResponseWrapper : public ModelWrapper<PFAuthenticationGetPolicyResponse, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetPolicyResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetPolicyResponseWrapper() = default;

    PFAuthenticationGetPolicyResponseWrapper(const PFAuthenticationGetPolicyResponse& model) :
        ModelWrapper<PFAuthenticationGetPolicyResponse, Alloc>{ model },
        m_policyName{ SafeString(model.policyName) },
        m_statements{ model.statements, model.statements + model.statementsCount }
    {
        SetModelPointers();
    }

    PFAuthenticationGetPolicyResponseWrapper(const PFAuthenticationGetPolicyResponseWrapper& src) :
        PFAuthenticationGetPolicyResponseWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetPolicyResponseWrapper(PFAuthenticationGetPolicyResponseWrapper&& src) :
        PFAuthenticationGetPolicyResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetPolicyResponseWrapper& operator=(PFAuthenticationGetPolicyResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetPolicyResponseWrapper() = default;

    friend void swap(PFAuthenticationGetPolicyResponseWrapper& lhs, PFAuthenticationGetPolicyResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_policyName, rhs.m_policyName);
        swap(lhs.m_statements, rhs.m_statements);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPolicyName(String value)
    {
        m_policyName = std::move(value);
        this->m_model.policyName =  m_policyName.empty() ? nullptr : m_policyName.data();
    }

    void SetPolicyVersion(int32_t value)
    {
        this->m_model.policyVersion = value;
    }

    void SetStatements(ModelVector<PFAuthenticationPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_statements = std::move(value);
        this->m_model.statements =  m_statements.empty() ? nullptr : m_statements.data();
        this->m_model.statementsCount =  static_cast<uint32_t>(m_statements.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.policyName = m_policyName.empty() ? nullptr : m_policyName.data();
        this->m_model.statements = m_statements.empty() ? nullptr : m_statements.data();
    }

    String m_policyName;
    ModelVector<PFAuthenticationPermissionStatementWrapper<Alloc>, Alloc> m_statements;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationOpenIdConnectionWrapper : public ModelWrapper<PFAuthenticationOpenIdConnection, Alloc>
{
public:
    using ModelType = typename PFAuthenticationOpenIdConnection;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationOpenIdConnectionWrapper() = default;

    PFAuthenticationOpenIdConnectionWrapper(const PFAuthenticationOpenIdConnection& model) :
        ModelWrapper<PFAuthenticationOpenIdConnection, Alloc>{ model },
        m_clientId{ SafeString(model.clientId) },
        m_clientSecret{ SafeString(model.clientSecret) },
        m_connectionId{ SafeString(model.connectionId) },
        m_issuerInformation{ model.issuerInformation ? StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>>{ *model.issuerInformation } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationOpenIdConnectionWrapper(const PFAuthenticationOpenIdConnectionWrapper& src) :
        PFAuthenticationOpenIdConnectionWrapper{ src.Model() }
    {
    }

    PFAuthenticationOpenIdConnectionWrapper(PFAuthenticationOpenIdConnectionWrapper&& src) :
        PFAuthenticationOpenIdConnectionWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationOpenIdConnectionWrapper& operator=(PFAuthenticationOpenIdConnectionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationOpenIdConnectionWrapper() = default;

    friend void swap(PFAuthenticationOpenIdConnectionWrapper& lhs, PFAuthenticationOpenIdConnectionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_clientId, rhs.m_clientId);
        swap(lhs.m_clientSecret, rhs.m_clientSecret);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_issuerInformation, rhs.m_issuerInformation);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetClientId(String value)
    {
        m_clientId = std::move(value);
        this->m_model.clientId =  m_clientId.empty() ? nullptr : m_clientId.data();
    }

    void SetClientSecret(String value)
    {
        m_clientSecret = std::move(value);
        this->m_model.clientSecret =  m_clientSecret.empty() ? nullptr : m_clientSecret.data();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetDiscoverConfiguration(bool value)
    {
        this->m_model.discoverConfiguration = value;
    }

    void SetIssuerInformation(StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>> value)
    {
        m_issuerInformation = std::move(value);
        this->m_model.issuerInformation = m_issuerInformation ? &m_issuerInformation->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.clientId = m_clientId.empty() ? nullptr : m_clientId.data();
        this->m_model.clientSecret = m_clientSecret.empty() ? nullptr : m_clientSecret.data();
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.issuerInformation = m_issuerInformation ?  &m_issuerInformation->Model() : nullptr;
    }

    String m_clientId;
    String m_clientSecret;
    String m_connectionId;
    StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>> m_issuerInformation;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationListOpenIdConnectionResponseWrapper : public ModelWrapper<PFAuthenticationListOpenIdConnectionResponse, Alloc>
{
public:
    using ModelType = typename PFAuthenticationListOpenIdConnectionResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationListOpenIdConnectionResponseWrapper() = default;

    PFAuthenticationListOpenIdConnectionResponseWrapper(const PFAuthenticationListOpenIdConnectionResponse& model) :
        ModelWrapper<PFAuthenticationListOpenIdConnectionResponse, Alloc>{ model },
        m_connections{ model.connections, model.connections + model.connectionsCount }
    {
        SetModelPointers();
    }

    PFAuthenticationListOpenIdConnectionResponseWrapper(const PFAuthenticationListOpenIdConnectionResponseWrapper& src) :
        PFAuthenticationListOpenIdConnectionResponseWrapper{ src.Model() }
    {
    }

    PFAuthenticationListOpenIdConnectionResponseWrapper(PFAuthenticationListOpenIdConnectionResponseWrapper&& src) :
        PFAuthenticationListOpenIdConnectionResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationListOpenIdConnectionResponseWrapper& operator=(PFAuthenticationListOpenIdConnectionResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationListOpenIdConnectionResponseWrapper() = default;

    friend void swap(PFAuthenticationListOpenIdConnectionResponseWrapper& lhs, PFAuthenticationListOpenIdConnectionResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connections, rhs.m_connections);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnections(ModelVector<PFAuthenticationOpenIdConnectionWrapper<Alloc>, Alloc> value)
    {
        m_connections = std::move(value);
        this->m_model.connections =  m_connections.empty() ? nullptr : m_connections.data();
        this->m_model.connectionsCount =  static_cast<uint32_t>(m_connections.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.connections = m_connections.empty() ? nullptr : m_connections.data();
    }

    ModelVector<PFAuthenticationOpenIdConnectionWrapper<Alloc>, Alloc> m_connections;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationAdminSetPlayerSecretRequestWrapper : public ModelWrapper<PFAuthenticationAdminSetPlayerSecretRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationAdminSetPlayerSecretRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationAdminSetPlayerSecretRequestWrapper() = default;

    PFAuthenticationAdminSetPlayerSecretRequestWrapper(const PFAuthenticationAdminSetPlayerSecretRequest& model) :
        ModelWrapper<PFAuthenticationAdminSetPlayerSecretRequest, Alloc>{ model },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAuthenticationAdminSetPlayerSecretRequestWrapper(const PFAuthenticationAdminSetPlayerSecretRequestWrapper& src) :
        PFAuthenticationAdminSetPlayerSecretRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationAdminSetPlayerSecretRequestWrapper(PFAuthenticationAdminSetPlayerSecretRequestWrapper&& src) :
        PFAuthenticationAdminSetPlayerSecretRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationAdminSetPlayerSecretRequestWrapper& operator=(PFAuthenticationAdminSetPlayerSecretRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationAdminSetPlayerSecretRequestWrapper() = default;

    friend void swap(PFAuthenticationAdminSetPlayerSecretRequestWrapper& lhs, PFAuthenticationAdminSetPlayerSecretRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playerSecret;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationUpdateOpenIdConnectionRequestWrapper : public ModelWrapper<PFAuthenticationUpdateOpenIdConnectionRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationUpdateOpenIdConnectionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper() = default;

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper(const PFAuthenticationUpdateOpenIdConnectionRequest& model) :
        ModelWrapper<PFAuthenticationUpdateOpenIdConnectionRequest, Alloc>{ model },
        m_clientId{ SafeString(model.clientId) },
        m_clientSecret{ SafeString(model.clientSecret) },
        m_connectionId{ SafeString(model.connectionId) },
        m_issuerDiscoveryUrl{ SafeString(model.issuerDiscoveryUrl) },
        m_issuerInformation{ model.issuerInformation ? StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>>{ *model.issuerInformation } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper(const PFAuthenticationUpdateOpenIdConnectionRequestWrapper& src) :
        PFAuthenticationUpdateOpenIdConnectionRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper(PFAuthenticationUpdateOpenIdConnectionRequestWrapper&& src) :
        PFAuthenticationUpdateOpenIdConnectionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper& operator=(PFAuthenticationUpdateOpenIdConnectionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationUpdateOpenIdConnectionRequestWrapper() = default;

    friend void swap(PFAuthenticationUpdateOpenIdConnectionRequestWrapper& lhs, PFAuthenticationUpdateOpenIdConnectionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_clientId, rhs.m_clientId);
        swap(lhs.m_clientSecret, rhs.m_clientSecret);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_issuerDiscoveryUrl, rhs.m_issuerDiscoveryUrl);
        swap(lhs.m_issuerInformation, rhs.m_issuerInformation);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetClientId(String value)
    {
        m_clientId = std::move(value);
        this->m_model.clientId =  m_clientId.empty() ? nullptr : m_clientId.data();
    }

    void SetClientSecret(String value)
    {
        m_clientSecret = std::move(value);
        this->m_model.clientSecret =  m_clientSecret.empty() ? nullptr : m_clientSecret.data();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetIssuerDiscoveryUrl(String value)
    {
        m_issuerDiscoveryUrl = std::move(value);
        this->m_model.issuerDiscoveryUrl =  m_issuerDiscoveryUrl.empty() ? nullptr : m_issuerDiscoveryUrl.data();
    }

    void SetIssuerInformation(StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>> value)
    {
        m_issuerInformation = std::move(value);
        this->m_model.issuerInformation = m_issuerInformation ? &m_issuerInformation->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.clientId = m_clientId.empty() ? nullptr : m_clientId.data();
        this->m_model.clientSecret = m_clientSecret.empty() ? nullptr : m_clientSecret.data();
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.issuerDiscoveryUrl = m_issuerDiscoveryUrl.empty() ? nullptr : m_issuerDiscoveryUrl.data();
        this->m_model.issuerInformation = m_issuerInformation ?  &m_issuerInformation->Model() : nullptr;
    }

    String m_clientId;
    String m_clientSecret;
    String m_connectionId;
    String m_issuerDiscoveryUrl;
    StdExtra::optional<PFAuthenticationOpenIdIssuerInformationWrapper<Alloc>> m_issuerInformation;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationUpdatePlayerSharedSecretRequestWrapper : public ModelWrapper<PFAuthenticationUpdatePlayerSharedSecretRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationUpdatePlayerSharedSecretRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper() = default;

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper(const PFAuthenticationUpdatePlayerSharedSecretRequest& model) :
        ModelWrapper<PFAuthenticationUpdatePlayerSharedSecretRequest, Alloc>{ model },
        m_friendlyName{ SafeString(model.friendlyName) },
        m_secretKey{ SafeString(model.secretKey) }
    {
        SetModelPointers();
    }

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper(const PFAuthenticationUpdatePlayerSharedSecretRequestWrapper& src) :
        PFAuthenticationUpdatePlayerSharedSecretRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper(PFAuthenticationUpdatePlayerSharedSecretRequestWrapper&& src) :
        PFAuthenticationUpdatePlayerSharedSecretRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper& operator=(PFAuthenticationUpdatePlayerSharedSecretRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationUpdatePlayerSharedSecretRequestWrapper() = default;

    friend void swap(PFAuthenticationUpdatePlayerSharedSecretRequestWrapper& lhs, PFAuthenticationUpdatePlayerSharedSecretRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_friendlyName, rhs.m_friendlyName);
        swap(lhs.m_secretKey, rhs.m_secretKey);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDisabled(bool value)
    {
        this->m_model.disabled = value;
    }

    void SetFriendlyName(String value)
    {
        m_friendlyName = std::move(value);
        this->m_model.friendlyName =  m_friendlyName.empty() ? nullptr : m_friendlyName.data();
    }

    void SetSecretKey(String value)
    {
        m_secretKey = std::move(value);
        this->m_model.secretKey =  m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.friendlyName = m_friendlyName.empty() ? nullptr : m_friendlyName.data();
        this->m_model.secretKey = m_secretKey.empty() ? nullptr : m_secretKey.data();
    }

    String m_friendlyName;
    String m_secretKey;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationUpdatePolicyRequestWrapper : public ModelWrapper<PFAuthenticationUpdatePolicyRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationUpdatePolicyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationUpdatePolicyRequestWrapper() = default;

    PFAuthenticationUpdatePolicyRequestWrapper(const PFAuthenticationUpdatePolicyRequest& model) :
        ModelWrapper<PFAuthenticationUpdatePolicyRequest, Alloc>{ model },
        m_policyName{ SafeString(model.policyName) },
        m_statements{ model.statements, model.statements + model.statementsCount }
    {
        SetModelPointers();
    }

    PFAuthenticationUpdatePolicyRequestWrapper(const PFAuthenticationUpdatePolicyRequestWrapper& src) :
        PFAuthenticationUpdatePolicyRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationUpdatePolicyRequestWrapper(PFAuthenticationUpdatePolicyRequestWrapper&& src) :
        PFAuthenticationUpdatePolicyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationUpdatePolicyRequestWrapper& operator=(PFAuthenticationUpdatePolicyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationUpdatePolicyRequestWrapper() = default;

    friend void swap(PFAuthenticationUpdatePolicyRequestWrapper& lhs, PFAuthenticationUpdatePolicyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_policyName, rhs.m_policyName);
        swap(lhs.m_statements, rhs.m_statements);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOverwritePolicy(bool value)
    {
        this->m_model.overwritePolicy = value;
    }

    void SetPolicyName(String value)
    {
        m_policyName = std::move(value);
        this->m_model.policyName =  m_policyName.empty() ? nullptr : m_policyName.data();
    }

    void SetPolicyVersion(int32_t value)
    {
        this->m_model.policyVersion = value;
    }

    void SetStatements(ModelVector<PFAuthenticationPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_statements = std::move(value);
        this->m_model.statements =  m_statements.empty() ? nullptr : m_statements.data();
        this->m_model.statementsCount =  static_cast<uint32_t>(m_statements.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.policyName = m_policyName.empty() ? nullptr : m_policyName.data();
        this->m_model.statements = m_statements.empty() ? nullptr : m_statements.data();
    }

    String m_policyName;
    ModelVector<PFAuthenticationPermissionStatementWrapper<Alloc>, Alloc> m_statements;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationUpdatePolicyResponseWrapper : public ModelWrapper<PFAuthenticationUpdatePolicyResponse, Alloc>
{
public:
    using ModelType = typename PFAuthenticationUpdatePolicyResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationUpdatePolicyResponseWrapper() = default;

    PFAuthenticationUpdatePolicyResponseWrapper(const PFAuthenticationUpdatePolicyResponse& model) :
        ModelWrapper<PFAuthenticationUpdatePolicyResponse, Alloc>{ model },
        m_policyName{ SafeString(model.policyName) },
        m_statements{ model.statements, model.statements + model.statementsCount }
    {
        SetModelPointers();
    }

    PFAuthenticationUpdatePolicyResponseWrapper(const PFAuthenticationUpdatePolicyResponseWrapper& src) :
        PFAuthenticationUpdatePolicyResponseWrapper{ src.Model() }
    {
    }

    PFAuthenticationUpdatePolicyResponseWrapper(PFAuthenticationUpdatePolicyResponseWrapper&& src) :
        PFAuthenticationUpdatePolicyResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationUpdatePolicyResponseWrapper& operator=(PFAuthenticationUpdatePolicyResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationUpdatePolicyResponseWrapper() = default;

    friend void swap(PFAuthenticationUpdatePolicyResponseWrapper& lhs, PFAuthenticationUpdatePolicyResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_policyName, rhs.m_policyName);
        swap(lhs.m_statements, rhs.m_statements);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPolicyName(String value)
    {
        m_policyName = std::move(value);
        this->m_model.policyName =  m_policyName.empty() ? nullptr : m_policyName.data();
    }

    void SetStatements(ModelVector<PFAuthenticationPermissionStatementWrapper<Alloc>, Alloc> value)
    {
        m_statements = std::move(value);
        this->m_model.statements =  m_statements.empty() ? nullptr : m_statements.data();
        this->m_model.statementsCount =  static_cast<uint32_t>(m_statements.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.policyName = m_policyName.empty() ? nullptr : m_policyName.data();
        this->m_model.statements = m_statements.empty() ? nullptr : m_statements.data();
    }

    String m_policyName;
    ModelVector<PFAuthenticationPermissionStatementWrapper<Alloc>, Alloc> m_statements;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper : public ModelWrapper<PFAuthenticationGetPhotonAuthenticationTokenRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetPhotonAuthenticationTokenRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper() = default;

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper(const PFAuthenticationGetPhotonAuthenticationTokenRequest& model) :
        ModelWrapper<PFAuthenticationGetPhotonAuthenticationTokenRequest, Alloc>{ model },
        m_photonApplicationId{ SafeString(model.photonApplicationId) }
    {
        SetModelPointers();
    }

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper(const PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper& src) :
        PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper(PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper&& src) :
        PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper& operator=(PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper() = default;

    friend void swap(PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper& lhs, PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_photonApplicationId, rhs.m_photonApplicationId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPhotonApplicationId(String value)
    {
        m_photonApplicationId = std::move(value);
        this->m_model.photonApplicationId =  m_photonApplicationId.empty() ? nullptr : m_photonApplicationId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.photonApplicationId = m_photonApplicationId.empty() ? nullptr : m_photonApplicationId.data();
    }

    String m_photonApplicationId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetPhotonAuthenticationTokenResultWrapper : public ModelWrapper<PFAuthenticationGetPhotonAuthenticationTokenResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetPhotonAuthenticationTokenResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetPhotonAuthenticationTokenResultWrapper() = default;

    PFAuthenticationGetPhotonAuthenticationTokenResultWrapper(const PFAuthenticationGetPhotonAuthenticationTokenResult& model) :
        ModelWrapper<PFAuthenticationGetPhotonAuthenticationTokenResult, Alloc>{ model },
        m_photonCustomAuthenticationToken{ SafeString(model.photonCustomAuthenticationToken) }
    {
        SetModelPointers();
    }

    PFAuthenticationGetPhotonAuthenticationTokenResultWrapper(const PFAuthenticationGetPhotonAuthenticationTokenResultWrapper& src) :
        PFAuthenticationGetPhotonAuthenticationTokenResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetPhotonAuthenticationTokenResultWrapper(PFAuthenticationGetPhotonAuthenticationTokenResultWrapper&& src) :
        PFAuthenticationGetPhotonAuthenticationTokenResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetPhotonAuthenticationTokenResultWrapper& operator=(PFAuthenticationGetPhotonAuthenticationTokenResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetPhotonAuthenticationTokenResultWrapper() = default;

    friend void swap(PFAuthenticationGetPhotonAuthenticationTokenResultWrapper& lhs, PFAuthenticationGetPhotonAuthenticationTokenResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_photonCustomAuthenticationToken, rhs.m_photonCustomAuthenticationToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPhotonCustomAuthenticationToken(String value)
    {
        m_photonCustomAuthenticationToken = std::move(value);
        this->m_model.photonCustomAuthenticationToken =  m_photonCustomAuthenticationToken.empty() ? nullptr : m_photonCustomAuthenticationToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.photonCustomAuthenticationToken = m_photonCustomAuthenticationToken.empty() ? nullptr : m_photonCustomAuthenticationToken.data();
    }

    String m_photonCustomAuthenticationToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetTitlePublicKeyRequestWrapper : public ModelWrapper<PFAuthenticationGetTitlePublicKeyRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetTitlePublicKeyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetTitlePublicKeyRequestWrapper() = default;

    PFAuthenticationGetTitlePublicKeyRequestWrapper(const PFAuthenticationGetTitlePublicKeyRequest& model) :
        ModelWrapper<PFAuthenticationGetTitlePublicKeyRequest, Alloc>{ model },
        m_titleId{ SafeString(model.titleId) },
        m_titleSharedSecret{ SafeString(model.titleSharedSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationGetTitlePublicKeyRequestWrapper(const PFAuthenticationGetTitlePublicKeyRequestWrapper& src) :
        PFAuthenticationGetTitlePublicKeyRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetTitlePublicKeyRequestWrapper(PFAuthenticationGetTitlePublicKeyRequestWrapper&& src) :
        PFAuthenticationGetTitlePublicKeyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetTitlePublicKeyRequestWrapper& operator=(PFAuthenticationGetTitlePublicKeyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetTitlePublicKeyRequestWrapper() = default;

    friend void swap(PFAuthenticationGetTitlePublicKeyRequestWrapper& lhs, PFAuthenticationGetTitlePublicKeyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_titleId, rhs.m_titleId);
        swap(lhs.m_titleSharedSecret, rhs.m_titleSharedSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

    void SetTitleSharedSecret(String value)
    {
        m_titleSharedSecret = std::move(value);
        this->m_model.titleSharedSecret =  m_titleSharedSecret.empty() ? nullptr : m_titleSharedSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
        this->m_model.titleSharedSecret = m_titleSharedSecret.empty() ? nullptr : m_titleSharedSecret.data();
    }

    String m_titleId;
    String m_titleSharedSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetTitlePublicKeyResultWrapper : public ModelWrapper<PFAuthenticationGetTitlePublicKeyResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetTitlePublicKeyResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetTitlePublicKeyResultWrapper() = default;

    PFAuthenticationGetTitlePublicKeyResultWrapper(const PFAuthenticationGetTitlePublicKeyResult& model) :
        ModelWrapper<PFAuthenticationGetTitlePublicKeyResult, Alloc>{ model },
        m_RSAPublicKey{ SafeString(model.RSAPublicKey) }
    {
        SetModelPointers();
    }

    PFAuthenticationGetTitlePublicKeyResultWrapper(const PFAuthenticationGetTitlePublicKeyResultWrapper& src) :
        PFAuthenticationGetTitlePublicKeyResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetTitlePublicKeyResultWrapper(PFAuthenticationGetTitlePublicKeyResultWrapper&& src) :
        PFAuthenticationGetTitlePublicKeyResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetTitlePublicKeyResultWrapper& operator=(PFAuthenticationGetTitlePublicKeyResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetTitlePublicKeyResultWrapper() = default;

    friend void swap(PFAuthenticationGetTitlePublicKeyResultWrapper& lhs, PFAuthenticationGetTitlePublicKeyResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_RSAPublicKey, rhs.m_RSAPublicKey);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetRSAPublicKey(String value)
    {
        m_RSAPublicKey = std::move(value);
        this->m_model.RSAPublicKey =  m_RSAPublicKey.empty() ? nullptr : m_RSAPublicKey.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.RSAPublicKey = m_RSAPublicKey.empty() ? nullptr : m_RSAPublicKey.data();
    }

    String m_RSAPublicKey;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithAndroidDeviceIDRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithAndroidDeviceIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper() = default;

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper(const PFAuthenticationLoginWithAndroidDeviceIDRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithAndroidDeviceIDRequest, Alloc>{ model },
        m_androidDevice{ SafeString(model.androidDevice) },
        m_androidDeviceId{ SafeString(model.androidDeviceId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_OS{ SafeString(model.OS) },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper(const PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper& src) :
        PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper(PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper&& src) :
        PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper& operator=(PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper& lhs, PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidDevice, rhs.m_androidDevice);
        swap(lhs.m_androidDeviceId, rhs.m_androidDeviceId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_OS, rhs.m_OS);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidDevice(String value)
    {
        m_androidDevice = std::move(value);
        this->m_model.androidDevice =  m_androidDevice.empty() ? nullptr : m_androidDevice.data();
    }

    void SetAndroidDeviceId(String value)
    {
        m_androidDeviceId = std::move(value);
        this->m_model.androidDeviceId =  m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetOS(String value)
    {
        m_OS = std::move(value);
        this->m_model.OS =  m_OS.empty() ? nullptr : m_OS.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidDevice = m_androidDevice.empty() ? nullptr : m_androidDevice.data();
        this->m_model.androidDeviceId = m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.OS = m_OS.empty() ? nullptr : m_OS.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_androidDevice;
    String m_androidDeviceId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_OS;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationEntityTokenResponseWrapper : public ModelWrapper<PFAuthenticationEntityTokenResponse, Alloc>
{
public:
    using ModelType = typename PFAuthenticationEntityTokenResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationEntityTokenResponseWrapper() = default;

    PFAuthenticationEntityTokenResponseWrapper(const PFAuthenticationEntityTokenResponse& model) :
        ModelWrapper<PFAuthenticationEntityTokenResponse, Alloc>{ model },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_entityToken{ SafeString(model.entityToken) },
        m_tokenExpiration{ model.tokenExpiration ? StdExtra::optional<time_t>{ *model.tokenExpiration } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationEntityTokenResponseWrapper(const PFAuthenticationEntityTokenResponseWrapper& src) :
        PFAuthenticationEntityTokenResponseWrapper{ src.Model() }
    {
    }

    PFAuthenticationEntityTokenResponseWrapper(PFAuthenticationEntityTokenResponseWrapper&& src) :
        PFAuthenticationEntityTokenResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationEntityTokenResponseWrapper& operator=(PFAuthenticationEntityTokenResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationEntityTokenResponseWrapper() = default;

    friend void swap(PFAuthenticationEntityTokenResponseWrapper& lhs, PFAuthenticationEntityTokenResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_entityToken, rhs.m_entityToken);
        swap(lhs.m_tokenExpiration, rhs.m_tokenExpiration);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetEntityToken(String value)
    {
        m_entityToken = std::move(value);
        this->m_model.entityToken =  m_entityToken.empty() ? nullptr : m_entityToken.data();
    }

    void SetTokenExpiration(StdExtra::optional<time_t> value)
    {
        m_tokenExpiration = std::move(value);
        this->m_model.tokenExpiration = m_tokenExpiration ? m_tokenExpiration.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.entityToken = m_entityToken.empty() ? nullptr : m_entityToken.data();
        this->m_model.tokenExpiration = m_tokenExpiration ? m_tokenExpiration.operator->() : nullptr;
    }

    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    String m_entityToken;
    StdExtra::optional<time_t> m_tokenExpiration;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationUserSettingsWrapper : public ModelWrapper<PFAuthenticationUserSettings, Alloc>
{
public:
    using ModelType = typename PFAuthenticationUserSettings;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFAuthenticationUserSettings, Alloc>::ModelWrapper;

    void SetGatherDeviceInfo(bool value)
    {
        this->m_model.gatherDeviceInfo = value;
    }

    void SetGatherFocusInfo(bool value)
    {
        this->m_model.gatherFocusInfo = value;
    }

    void SetNeedsAttribution(bool value)
    {
        this->m_model.needsAttribution = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithAppleRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithAppleRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithAppleRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithAppleRequestWrapper() = default;

    PFAuthenticationLoginWithAppleRequestWrapper(const PFAuthenticationLoginWithAppleRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithAppleRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_identityToken{ SafeString(model.identityToken) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithAppleRequestWrapper(const PFAuthenticationLoginWithAppleRequestWrapper& src) :
        PFAuthenticationLoginWithAppleRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithAppleRequestWrapper(PFAuthenticationLoginWithAppleRequestWrapper&& src) :
        PFAuthenticationLoginWithAppleRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithAppleRequestWrapper& operator=(PFAuthenticationLoginWithAppleRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithAppleRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithAppleRequestWrapper& lhs, PFAuthenticationLoginWithAppleRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_identityToken, rhs.m_identityToken);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetIdentityToken(String value)
    {
        m_identityToken = std::move(value);
        this->m_model.identityToken =  m_identityToken.empty() ? nullptr : m_identityToken.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.identityToken = m_identityToken.empty() ? nullptr : m_identityToken.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_identityToken;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithCustomIDRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithCustomIDRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithCustomIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithCustomIDRequestWrapper() = default;

    PFAuthenticationLoginWithCustomIDRequestWrapper(const PFAuthenticationLoginWithCustomIDRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithCustomIDRequest, Alloc>{ model },
        m_customId{ SafeString(model.customId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithCustomIDRequestWrapper(const PFAuthenticationLoginWithCustomIDRequestWrapper& src) :
        PFAuthenticationLoginWithCustomIDRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithCustomIDRequestWrapper(PFAuthenticationLoginWithCustomIDRequestWrapper&& src) :
        PFAuthenticationLoginWithCustomIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithCustomIDRequestWrapper& operator=(PFAuthenticationLoginWithCustomIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithCustomIDRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithCustomIDRequestWrapper& lhs, PFAuthenticationLoginWithCustomIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customId, rhs.m_customId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
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

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customId = m_customId.empty() ? nullptr : m_customId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_customId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithEmailAddressRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithEmailAddressRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithEmailAddressRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithEmailAddressRequestWrapper() = default;

    PFAuthenticationLoginWithEmailAddressRequestWrapper(const PFAuthenticationLoginWithEmailAddressRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithEmailAddressRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_email{ SafeString(model.email) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_password{ SafeString(model.password) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithEmailAddressRequestWrapper(const PFAuthenticationLoginWithEmailAddressRequestWrapper& src) :
        PFAuthenticationLoginWithEmailAddressRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithEmailAddressRequestWrapper(PFAuthenticationLoginWithEmailAddressRequestWrapper&& src) :
        PFAuthenticationLoginWithEmailAddressRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithEmailAddressRequestWrapper& operator=(PFAuthenticationLoginWithEmailAddressRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithEmailAddressRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithEmailAddressRequestWrapper& lhs, PFAuthenticationLoginWithEmailAddressRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_password, rhs.m_password);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_email;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_password;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithFacebookRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithFacebookRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithFacebookRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithFacebookRequestWrapper() = default;

    PFAuthenticationLoginWithFacebookRequestWrapper(const PFAuthenticationLoginWithFacebookRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithFacebookRequest, Alloc>{ model },
        m_accessToken{ SafeString(model.accessToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithFacebookRequestWrapper(const PFAuthenticationLoginWithFacebookRequestWrapper& src) :
        PFAuthenticationLoginWithFacebookRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithFacebookRequestWrapper(PFAuthenticationLoginWithFacebookRequestWrapper&& src) :
        PFAuthenticationLoginWithFacebookRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithFacebookRequestWrapper& operator=(PFAuthenticationLoginWithFacebookRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithFacebookRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithFacebookRequestWrapper& lhs, PFAuthenticationLoginWithFacebookRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessToken, rhs.m_accessToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessToken(String value)
    {
        m_accessToken = std::move(value);
        this->m_model.accessToken =  m_accessToken.empty() ? nullptr : m_accessToken.data();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessToken = m_accessToken.empty() ? nullptr : m_accessToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_accessToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithFacebookInstantGamesIdRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithFacebookInstantGamesIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper() = default;

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper(const PFAuthenticationLoginWithFacebookInstantGamesIdRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithFacebookInstantGamesIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_facebookInstantGamesSignature{ SafeString(model.facebookInstantGamesSignature) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper(const PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper& src) :
        PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper(PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper&& src) :
        PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper& operator=(PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper& lhs, PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_facebookInstantGamesSignature, rhs.m_facebookInstantGamesSignature);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFacebookInstantGamesSignature(String value)
    {
        m_facebookInstantGamesSignature = std::move(value);
        this->m_model.facebookInstantGamesSignature =  m_facebookInstantGamesSignature.empty() ? nullptr : m_facebookInstantGamesSignature.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.facebookInstantGamesSignature = m_facebookInstantGamesSignature.empty() ? nullptr : m_facebookInstantGamesSignature.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_facebookInstantGamesSignature;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithGameCenterRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithGameCenterRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithGameCenterRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithGameCenterRequestWrapper() = default;

    PFAuthenticationLoginWithGameCenterRequestWrapper(const PFAuthenticationLoginWithGameCenterRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithGameCenterRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerId{ SafeString(model.playerId) },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_publicKeyUrl{ SafeString(model.publicKeyUrl) },
        m_salt{ SafeString(model.salt) },
        m_signature{ SafeString(model.signature) },
        m_timestamp{ SafeString(model.timestamp) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithGameCenterRequestWrapper(const PFAuthenticationLoginWithGameCenterRequestWrapper& src) :
        PFAuthenticationLoginWithGameCenterRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithGameCenterRequestWrapper(PFAuthenticationLoginWithGameCenterRequestWrapper&& src) :
        PFAuthenticationLoginWithGameCenterRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithGameCenterRequestWrapper& operator=(PFAuthenticationLoginWithGameCenterRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithGameCenterRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithGameCenterRequestWrapper& lhs, PFAuthenticationLoginWithGameCenterRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerId, rhs.m_playerId);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_publicKeyUrl, rhs.m_publicKeyUrl);
        swap(lhs.m_salt, rhs.m_salt);
        swap(lhs.m_signature, rhs.m_signature);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerId(String value)
    {
        m_playerId = std::move(value);
        this->m_model.playerId =  m_playerId.empty() ? nullptr : m_playerId.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetPublicKeyUrl(String value)
    {
        m_publicKeyUrl = std::move(value);
        this->m_model.publicKeyUrl =  m_publicKeyUrl.empty() ? nullptr : m_publicKeyUrl.data();
    }

    void SetSalt(String value)
    {
        m_salt = std::move(value);
        this->m_model.salt =  m_salt.empty() ? nullptr : m_salt.data();
    }

    void SetSignature(String value)
    {
        m_signature = std::move(value);
        this->m_model.signature =  m_signature.empty() ? nullptr : m_signature.data();
    }

    void SetTimestamp(String value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp =  m_timestamp.empty() ? nullptr : m_timestamp.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerId = m_playerId.empty() ? nullptr : m_playerId.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.publicKeyUrl = m_publicKeyUrl.empty() ? nullptr : m_publicKeyUrl.data();
        this->m_model.salt = m_salt.empty() ? nullptr : m_salt.data();
        this->m_model.signature = m_signature.empty() ? nullptr : m_signature.data();
        this->m_model.timestamp = m_timestamp.empty() ? nullptr : m_timestamp.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerId;
    String m_playerSecret;
    String m_publicKeyUrl;
    String m_salt;
    String m_signature;
    String m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithGoogleAccountRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithGoogleAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithGoogleAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithGoogleAccountRequestWrapper() = default;

    PFAuthenticationLoginWithGoogleAccountRequestWrapper(const PFAuthenticationLoginWithGoogleAccountRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithGoogleAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_serverAuthCode{ SafeString(model.serverAuthCode) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithGoogleAccountRequestWrapper(const PFAuthenticationLoginWithGoogleAccountRequestWrapper& src) :
        PFAuthenticationLoginWithGoogleAccountRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithGoogleAccountRequestWrapper(PFAuthenticationLoginWithGoogleAccountRequestWrapper&& src) :
        PFAuthenticationLoginWithGoogleAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithGoogleAccountRequestWrapper& operator=(PFAuthenticationLoginWithGoogleAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithGoogleAccountRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithGoogleAccountRequestWrapper& lhs, PFAuthenticationLoginWithGoogleAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_serverAuthCode, rhs.m_serverAuthCode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetServerAuthCode(String value)
    {
        m_serverAuthCode = std::move(value);
        this->m_model.serverAuthCode =  m_serverAuthCode.empty() ? nullptr : m_serverAuthCode.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.serverAuthCode = m_serverAuthCode.empty() ? nullptr : m_serverAuthCode.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
    String m_serverAuthCode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithGooglePlayGamesServicesRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithGooglePlayGamesServicesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper() = default;

    PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper(const PFAuthenticationLoginWithGooglePlayGamesServicesRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithGooglePlayGamesServicesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_serverAuthCode{ SafeString(model.serverAuthCode) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper(const PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper& src) :
        PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper(PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper&& src) :
        PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper& operator=(PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper& lhs, PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_serverAuthCode, rhs.m_serverAuthCode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetServerAuthCode(String value)
    {
        m_serverAuthCode = std::move(value);
        this->m_model.serverAuthCode =  m_serverAuthCode.empty() ? nullptr : m_serverAuthCode.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.serverAuthCode = m_serverAuthCode.empty() ? nullptr : m_serverAuthCode.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
    String m_serverAuthCode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithIOSDeviceIDRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithIOSDeviceIDRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithIOSDeviceIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper() = default;

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper(const PFAuthenticationLoginWithIOSDeviceIDRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithIOSDeviceIDRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_deviceId{ SafeString(model.deviceId) },
        m_deviceModel{ SafeString(model.deviceModel) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_OS{ SafeString(model.OS) },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper(const PFAuthenticationLoginWithIOSDeviceIDRequestWrapper& src) :
        PFAuthenticationLoginWithIOSDeviceIDRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper(PFAuthenticationLoginWithIOSDeviceIDRequestWrapper&& src) :
        PFAuthenticationLoginWithIOSDeviceIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper& operator=(PFAuthenticationLoginWithIOSDeviceIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithIOSDeviceIDRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithIOSDeviceIDRequestWrapper& lhs, PFAuthenticationLoginWithIOSDeviceIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_deviceId, rhs.m_deviceId);
        swap(lhs.m_deviceModel, rhs.m_deviceModel);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_OS, rhs.m_OS);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDeviceId(String value)
    {
        m_deviceId = std::move(value);
        this->m_model.deviceId =  m_deviceId.empty() ? nullptr : m_deviceId.data();
    }

    void SetDeviceModel(String value)
    {
        m_deviceModel = std::move(value);
        this->m_model.deviceModel =  m_deviceModel.empty() ? nullptr : m_deviceModel.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetOS(String value)
    {
        m_OS = std::move(value);
        this->m_model.OS =  m_OS.empty() ? nullptr : m_OS.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.deviceId = m_deviceId.empty() ? nullptr : m_deviceId.data();
        this->m_model.deviceModel = m_deviceModel.empty() ? nullptr : m_deviceModel.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.OS = m_OS.empty() ? nullptr : m_OS.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_deviceId;
    String m_deviceModel;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_OS;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithKongregateRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithKongregateRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithKongregateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithKongregateRequestWrapper() = default;

    PFAuthenticationLoginWithKongregateRequestWrapper(const PFAuthenticationLoginWithKongregateRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithKongregateRequest, Alloc>{ model },
        m_authTicket{ SafeString(model.authTicket) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_kongregateId{ SafeString(model.kongregateId) },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithKongregateRequestWrapper(const PFAuthenticationLoginWithKongregateRequestWrapper& src) :
        PFAuthenticationLoginWithKongregateRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithKongregateRequestWrapper(PFAuthenticationLoginWithKongregateRequestWrapper&& src) :
        PFAuthenticationLoginWithKongregateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithKongregateRequestWrapper& operator=(PFAuthenticationLoginWithKongregateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithKongregateRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithKongregateRequestWrapper& lhs, PFAuthenticationLoginWithKongregateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authTicket, rhs.m_authTicket);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_kongregateId, rhs.m_kongregateId);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthTicket(String value)
    {
        m_authTicket = std::move(value);
        this->m_model.authTicket =  m_authTicket.empty() ? nullptr : m_authTicket.data();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetKongregateId(String value)
    {
        m_kongregateId = std::move(value);
        this->m_model.kongregateId =  m_kongregateId.empty() ? nullptr : m_kongregateId.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authTicket = m_authTicket.empty() ? nullptr : m_authTicket.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.kongregateId = m_kongregateId.empty() ? nullptr : m_kongregateId.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_authTicket;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_kongregateId;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithNintendoServiceAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithNintendoServiceAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper() = default;

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper(const PFAuthenticationLoginWithNintendoServiceAccountRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithNintendoServiceAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_identityToken{ SafeString(model.identityToken) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper(const PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper& src) :
        PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper(PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper&& src) :
        PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper& operator=(PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper& lhs, PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_identityToken, rhs.m_identityToken);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetIdentityToken(String value)
    {
        m_identityToken = std::move(value);
        this->m_model.identityToken =  m_identityToken.empty() ? nullptr : m_identityToken.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.identityToken = m_identityToken.empty() ? nullptr : m_identityToken.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_identityToken;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper() = default;

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper(const PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_nintendoSwitchDeviceId{ SafeString(model.nintendoSwitchDeviceId) },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper(const PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper& src) :
        PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper(PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper&& src) :
        PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper& operator=(PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper& lhs, PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_nintendoSwitchDeviceId, rhs.m_nintendoSwitchDeviceId);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetNintendoSwitchDeviceId(String value)
    {
        m_nintendoSwitchDeviceId = std::move(value);
        this->m_model.nintendoSwitchDeviceId =  m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.nintendoSwitchDeviceId = m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_nintendoSwitchDeviceId;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithOpenIdConnectRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithOpenIdConnectRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithOpenIdConnectRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper() = default;

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper(const PFAuthenticationLoginWithOpenIdConnectRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithOpenIdConnectRequest, Alloc>{ model },
        m_connectionId{ SafeString(model.connectionId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_idToken{ SafeString(model.idToken) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper(const PFAuthenticationLoginWithOpenIdConnectRequestWrapper& src) :
        PFAuthenticationLoginWithOpenIdConnectRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper(PFAuthenticationLoginWithOpenIdConnectRequestWrapper&& src) :
        PFAuthenticationLoginWithOpenIdConnectRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper& operator=(PFAuthenticationLoginWithOpenIdConnectRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithOpenIdConnectRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithOpenIdConnectRequestWrapper& lhs, PFAuthenticationLoginWithOpenIdConnectRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_idToken, rhs.m_idToken);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetIdToken(String value)
    {
        m_idToken = std::move(value);
        this->m_model.idToken =  m_idToken.empty() ? nullptr : m_idToken.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.idToken = m_idToken.empty() ? nullptr : m_idToken.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_connectionId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_idToken;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithPlayFabRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithPlayFabRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithPlayFabRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithPlayFabRequestWrapper() = default;

    PFAuthenticationLoginWithPlayFabRequestWrapper(const PFAuthenticationLoginWithPlayFabRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithPlayFabRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_password{ SafeString(model.password) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithPlayFabRequestWrapper(const PFAuthenticationLoginWithPlayFabRequestWrapper& src) :
        PFAuthenticationLoginWithPlayFabRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithPlayFabRequestWrapper(PFAuthenticationLoginWithPlayFabRequestWrapper&& src) :
        PFAuthenticationLoginWithPlayFabRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithPlayFabRequestWrapper& operator=(PFAuthenticationLoginWithPlayFabRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithPlayFabRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithPlayFabRequestWrapper& lhs, PFAuthenticationLoginWithPlayFabRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_password;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithPSNRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithPSNRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithPSNRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithPSNRequestWrapper() = default;

    PFAuthenticationLoginWithPSNRequestWrapper(const PFAuthenticationLoginWithPSNRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithPSNRequest, Alloc>{ model },
        m_authCode{ SafeString(model.authCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_issuerId{ model.issuerId ? StdExtra::optional<int32_t>{ *model.issuerId } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_redirectUri{ SafeString(model.redirectUri) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithPSNRequestWrapper(const PFAuthenticationLoginWithPSNRequestWrapper& src) :
        PFAuthenticationLoginWithPSNRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithPSNRequestWrapper(PFAuthenticationLoginWithPSNRequestWrapper&& src) :
        PFAuthenticationLoginWithPSNRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithPSNRequestWrapper& operator=(PFAuthenticationLoginWithPSNRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithPSNRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithPSNRequestWrapper& lhs, PFAuthenticationLoginWithPSNRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authCode, rhs.m_authCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_issuerId, rhs.m_issuerId);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_redirectUri, rhs.m_redirectUri);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthCode(String value)
    {
        m_authCode = std::move(value);
        this->m_model.authCode =  m_authCode.empty() ? nullptr : m_authCode.data();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetIssuerId(StdExtra::optional<int32_t> value)
    {
        m_issuerId = std::move(value);
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
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
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.redirectUri = m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

    String m_authCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    StdExtra::optional<int32_t> m_issuerId;
    String m_playerSecret;
    String m_redirectUri;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithSteamRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithSteamRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithSteamRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithSteamRequestWrapper() = default;

    PFAuthenticationLoginWithSteamRequestWrapper(const PFAuthenticationLoginWithSteamRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithSteamRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_steamTicket{ SafeString(model.steamTicket) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithSteamRequestWrapper(const PFAuthenticationLoginWithSteamRequestWrapper& src) :
        PFAuthenticationLoginWithSteamRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithSteamRequestWrapper(PFAuthenticationLoginWithSteamRequestWrapper&& src) :
        PFAuthenticationLoginWithSteamRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithSteamRequestWrapper& operator=(PFAuthenticationLoginWithSteamRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithSteamRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithSteamRequestWrapper& lhs, PFAuthenticationLoginWithSteamRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_steamTicket, rhs.m_steamTicket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetSteamTicket(String value)
    {
        m_steamTicket = std::move(value);
        this->m_model.steamTicket =  m_steamTicket.empty() ? nullptr : m_steamTicket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.steamTicket = m_steamTicket.empty() ? nullptr : m_steamTicket.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
    String m_steamTicket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithTwitchRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithTwitchRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithTwitchRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithTwitchRequestWrapper() = default;

    PFAuthenticationLoginWithTwitchRequestWrapper(const PFAuthenticationLoginWithTwitchRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithTwitchRequest, Alloc>{ model },
        m_accessToken{ SafeString(model.accessToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithTwitchRequestWrapper(const PFAuthenticationLoginWithTwitchRequestWrapper& src) :
        PFAuthenticationLoginWithTwitchRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithTwitchRequestWrapper(PFAuthenticationLoginWithTwitchRequestWrapper&& src) :
        PFAuthenticationLoginWithTwitchRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithTwitchRequestWrapper& operator=(PFAuthenticationLoginWithTwitchRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithTwitchRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithTwitchRequestWrapper& lhs, PFAuthenticationLoginWithTwitchRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessToken, rhs.m_accessToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessToken(String value)
    {
        m_accessToken = std::move(value);
        this->m_model.accessToken =  m_accessToken.empty() ? nullptr : m_accessToken.data();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessToken = m_accessToken.empty() ? nullptr : m_accessToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_accessToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationClientLoginWithXboxRequestWrapper : public ModelWrapper<PFAuthenticationClientLoginWithXboxRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationClientLoginWithXboxRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationClientLoginWithXboxRequestWrapper() = default;

    PFAuthenticationClientLoginWithXboxRequestWrapper(const PFAuthenticationClientLoginWithXboxRequest& model) :
        ModelWrapper<PFAuthenticationClientLoginWithXboxRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFAuthenticationClientLoginWithXboxRequestWrapper(const PFAuthenticationClientLoginWithXboxRequestWrapper& src) :
        PFAuthenticationClientLoginWithXboxRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationClientLoginWithXboxRequestWrapper(PFAuthenticationClientLoginWithXboxRequestWrapper&& src) :
        PFAuthenticationClientLoginWithXboxRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationClientLoginWithXboxRequestWrapper& operator=(PFAuthenticationClientLoginWithXboxRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationClientLoginWithXboxRequestWrapper() = default;

    friend void swap(PFAuthenticationClientLoginWithXboxRequestWrapper& lhs, PFAuthenticationClientLoginWithXboxRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_xboxToken, rhs.m_xboxToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetXboxToken(String value)
    {
        m_xboxToken = std::move(value);
        this->m_model.xboxToken =  m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationRegisterPlayFabUserRequestWrapper : public ModelWrapper<PFAuthenticationRegisterPlayFabUserRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationRegisterPlayFabUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationRegisterPlayFabUserRequestWrapper() = default;

    PFAuthenticationRegisterPlayFabUserRequestWrapper(const PFAuthenticationRegisterPlayFabUserRequest& model) :
        ModelWrapper<PFAuthenticationRegisterPlayFabUserRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_displayName{ SafeString(model.displayName) },
        m_email{ SafeString(model.email) },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_password{ SafeString(model.password) },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_requireBothUsernameAndEmail{ model.requireBothUsernameAndEmail ? StdExtra::optional<bool>{ *model.requireBothUsernameAndEmail } : StdExtra::nullopt },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAuthenticationRegisterPlayFabUserRequestWrapper(const PFAuthenticationRegisterPlayFabUserRequestWrapper& src) :
        PFAuthenticationRegisterPlayFabUserRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationRegisterPlayFabUserRequestWrapper(PFAuthenticationRegisterPlayFabUserRequestWrapper&& src) :
        PFAuthenticationRegisterPlayFabUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationRegisterPlayFabUserRequestWrapper& operator=(PFAuthenticationRegisterPlayFabUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationRegisterPlayFabUserRequestWrapper() = default;

    friend void swap(PFAuthenticationRegisterPlayFabUserRequestWrapper& lhs, PFAuthenticationRegisterPlayFabUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_requireBothUsernameAndEmail, rhs.m_requireBothUsernameAndEmail);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetRequireBothUsernameAndEmail(StdExtra::optional<bool> value)
    {
        m_requireBothUsernameAndEmail = std::move(value);
        this->m_model.requireBothUsernameAndEmail = m_requireBothUsernameAndEmail ? m_requireBothUsernameAndEmail.operator->() : nullptr;
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.requireBothUsernameAndEmail = m_requireBothUsernameAndEmail ? m_requireBothUsernameAndEmail.operator->() : nullptr;
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_displayName;
    String m_email;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_password;
    String m_playerSecret;
    StdExtra::optional<bool> m_requireBothUsernameAndEmail;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationClientSetPlayerSecretRequestWrapper : public ModelWrapper<PFAuthenticationClientSetPlayerSecretRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationClientSetPlayerSecretRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationClientSetPlayerSecretRequestWrapper() = default;

    PFAuthenticationClientSetPlayerSecretRequestWrapper(const PFAuthenticationClientSetPlayerSecretRequest& model) :
        ModelWrapper<PFAuthenticationClientSetPlayerSecretRequest, Alloc>{ model },
        m_encryptedRequest{ SafeString(model.encryptedRequest) },
        m_playerSecret{ SafeString(model.playerSecret) }
    {
        SetModelPointers();
    }

    PFAuthenticationClientSetPlayerSecretRequestWrapper(const PFAuthenticationClientSetPlayerSecretRequestWrapper& src) :
        PFAuthenticationClientSetPlayerSecretRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationClientSetPlayerSecretRequestWrapper(PFAuthenticationClientSetPlayerSecretRequestWrapper&& src) :
        PFAuthenticationClientSetPlayerSecretRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationClientSetPlayerSecretRequestWrapper& operator=(PFAuthenticationClientSetPlayerSecretRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationClientSetPlayerSecretRequestWrapper() = default;

    friend void swap(PFAuthenticationClientSetPlayerSecretRequestWrapper& lhs, PFAuthenticationClientSetPlayerSecretRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_encryptedRequest, rhs.m_encryptedRequest);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEncryptedRequest(String value)
    {
        m_encryptedRequest = std::move(value);
        this->m_model.encryptedRequest =  m_encryptedRequest.empty() ? nullptr : m_encryptedRequest.data();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.encryptedRequest = m_encryptedRequest.empty() ? nullptr : m_encryptedRequest.data();
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    String m_encryptedRequest;
    String m_playerSecret;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationAuthenticateSessionTicketRequestWrapper : public ModelWrapper<PFAuthenticationAuthenticateSessionTicketRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationAuthenticateSessionTicketRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationAuthenticateSessionTicketRequestWrapper() = default;

    PFAuthenticationAuthenticateSessionTicketRequestWrapper(const PFAuthenticationAuthenticateSessionTicketRequest& model) :
        ModelWrapper<PFAuthenticationAuthenticateSessionTicketRequest, Alloc>{ model },
        m_sessionTicket{ SafeString(model.sessionTicket) }
    {
        SetModelPointers();
    }

    PFAuthenticationAuthenticateSessionTicketRequestWrapper(const PFAuthenticationAuthenticateSessionTicketRequestWrapper& src) :
        PFAuthenticationAuthenticateSessionTicketRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationAuthenticateSessionTicketRequestWrapper(PFAuthenticationAuthenticateSessionTicketRequestWrapper&& src) :
        PFAuthenticationAuthenticateSessionTicketRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationAuthenticateSessionTicketRequestWrapper& operator=(PFAuthenticationAuthenticateSessionTicketRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationAuthenticateSessionTicketRequestWrapper() = default;

    friend void swap(PFAuthenticationAuthenticateSessionTicketRequestWrapper& lhs, PFAuthenticationAuthenticateSessionTicketRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_sessionTicket, rhs.m_sessionTicket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSessionTicket(String value)
    {
        m_sessionTicket = std::move(value);
        this->m_model.sessionTicket =  m_sessionTicket.empty() ? nullptr : m_sessionTicket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.sessionTicket = m_sessionTicket.empty() ? nullptr : m_sessionTicket.data();
    }

    String m_sessionTicket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationAuthenticateSessionTicketResultWrapper : public ModelWrapper<PFAuthenticationAuthenticateSessionTicketResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationAuthenticateSessionTicketResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationAuthenticateSessionTicketResultWrapper() = default;

    PFAuthenticationAuthenticateSessionTicketResultWrapper(const PFAuthenticationAuthenticateSessionTicketResult& model) :
        ModelWrapper<PFAuthenticationAuthenticateSessionTicketResult, Alloc>{ model },
        m_isSessionTicketExpired{ model.isSessionTicketExpired ? StdExtra::optional<bool>{ *model.isSessionTicketExpired } : StdExtra::nullopt },
        m_userInfo{ model.userInfo ? StdExtra::optional<PFUserAccountInfoWrapper<Alloc>>{ *model.userInfo } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationAuthenticateSessionTicketResultWrapper(const PFAuthenticationAuthenticateSessionTicketResultWrapper& src) :
        PFAuthenticationAuthenticateSessionTicketResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationAuthenticateSessionTicketResultWrapper(PFAuthenticationAuthenticateSessionTicketResultWrapper&& src) :
        PFAuthenticationAuthenticateSessionTicketResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationAuthenticateSessionTicketResultWrapper& operator=(PFAuthenticationAuthenticateSessionTicketResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationAuthenticateSessionTicketResultWrapper() = default;

    friend void swap(PFAuthenticationAuthenticateSessionTicketResultWrapper& lhs, PFAuthenticationAuthenticateSessionTicketResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_isSessionTicketExpired, rhs.m_isSessionTicketExpired);
        swap(lhs.m_userInfo, rhs.m_userInfo);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIsSessionTicketExpired(StdExtra::optional<bool> value)
    {
        m_isSessionTicketExpired = std::move(value);
        this->m_model.isSessionTicketExpired = m_isSessionTicketExpired ? m_isSessionTicketExpired.operator->() : nullptr;
    }

    void SetUserInfo(StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> value)
    {
        m_userInfo = std::move(value);
        this->m_model.userInfo = m_userInfo ? &m_userInfo->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.isSessionTicketExpired = m_isSessionTicketExpired ? m_isSessionTicketExpired.operator->() : nullptr;
        this->m_model.userInfo = m_userInfo ?  &m_userInfo->Model() : nullptr;
    }

    StdExtra::optional<bool> m_isSessionTicketExpired;
    StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> m_userInfo;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithServerCustomIdRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithServerCustomIdRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithServerCustomIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithServerCustomIdRequestWrapper() = default;

    PFAuthenticationLoginWithServerCustomIdRequestWrapper(const PFAuthenticationLoginWithServerCustomIdRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithServerCustomIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_serverCustomId{ SafeString(model.serverCustomId) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithServerCustomIdRequestWrapper(const PFAuthenticationLoginWithServerCustomIdRequestWrapper& src) :
        PFAuthenticationLoginWithServerCustomIdRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithServerCustomIdRequestWrapper(PFAuthenticationLoginWithServerCustomIdRequestWrapper&& src) :
        PFAuthenticationLoginWithServerCustomIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithServerCustomIdRequestWrapper& operator=(PFAuthenticationLoginWithServerCustomIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithServerCustomIdRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithServerCustomIdRequestWrapper& lhs, PFAuthenticationLoginWithServerCustomIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_serverCustomId, rhs.m_serverCustomId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetServerCustomId(String value)
    {
        m_serverCustomId = std::move(value);
        this->m_model.serverCustomId =  m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.serverCustomId = m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_playerSecret;
    String m_serverCustomId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithSteamIdRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithSteamIdRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithSteamIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithSteamIdRequestWrapper() = default;

    PFAuthenticationLoginWithSteamIdRequestWrapper(const PFAuthenticationLoginWithSteamIdRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithSteamIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_steamId{ SafeString(model.steamId) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithSteamIdRequestWrapper(const PFAuthenticationLoginWithSteamIdRequestWrapper& src) :
        PFAuthenticationLoginWithSteamIdRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithSteamIdRequestWrapper(PFAuthenticationLoginWithSteamIdRequestWrapper&& src) :
        PFAuthenticationLoginWithSteamIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithSteamIdRequestWrapper& operator=(PFAuthenticationLoginWithSteamIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithSteamIdRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithSteamIdRequestWrapper& lhs, PFAuthenticationLoginWithSteamIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_steamId, rhs.m_steamId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetSteamId(String value)
    {
        m_steamId = std::move(value);
        this->m_model.steamId =  m_steamId.empty() ? nullptr : m_steamId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.steamId = m_steamId.empty() ? nullptr : m_steamId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_steamId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationServerLoginWithXboxRequestWrapper : public ModelWrapper<PFAuthenticationServerLoginWithXboxRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationServerLoginWithXboxRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationServerLoginWithXboxRequestWrapper() = default;

    PFAuthenticationServerLoginWithXboxRequestWrapper(const PFAuthenticationServerLoginWithXboxRequest& model) :
        ModelWrapper<PFAuthenticationServerLoginWithXboxRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFAuthenticationServerLoginWithXboxRequestWrapper(const PFAuthenticationServerLoginWithXboxRequestWrapper& src) :
        PFAuthenticationServerLoginWithXboxRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationServerLoginWithXboxRequestWrapper(PFAuthenticationServerLoginWithXboxRequestWrapper&& src) :
        PFAuthenticationServerLoginWithXboxRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationServerLoginWithXboxRequestWrapper& operator=(PFAuthenticationServerLoginWithXboxRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationServerLoginWithXboxRequestWrapper() = default;

    friend void swap(PFAuthenticationServerLoginWithXboxRequestWrapper& lhs, PFAuthenticationServerLoginWithXboxRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_xboxToken, rhs.m_xboxToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetXboxToken(String value)
    {
        m_xboxToken = std::move(value);
        this->m_model.xboxToken =  m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationLoginWithXboxIdRequestWrapper : public ModelWrapper<PFAuthenticationLoginWithXboxIdRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationLoginWithXboxIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationLoginWithXboxIdRequestWrapper() = default;

    PFAuthenticationLoginWithXboxIdRequestWrapper(const PFAuthenticationLoginWithXboxIdRequest& model) :
        ModelWrapper<PFAuthenticationLoginWithXboxIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_infoRequestParameters{ model.infoRequestParameters ? StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>>{ *model.infoRequestParameters } : StdExtra::nullopt },
        m_sandbox{ SafeString(model.sandbox) },
        m_xboxId{ SafeString(model.xboxId) }
    {
        SetModelPointers();
    }

    PFAuthenticationLoginWithXboxIdRequestWrapper(const PFAuthenticationLoginWithXboxIdRequestWrapper& src) :
        PFAuthenticationLoginWithXboxIdRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationLoginWithXboxIdRequestWrapper(PFAuthenticationLoginWithXboxIdRequestWrapper&& src) :
        PFAuthenticationLoginWithXboxIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationLoginWithXboxIdRequestWrapper& operator=(PFAuthenticationLoginWithXboxIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationLoginWithXboxIdRequestWrapper() = default;

    friend void swap(PFAuthenticationLoginWithXboxIdRequestWrapper& lhs, PFAuthenticationLoginWithXboxIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_infoRequestParameters, rhs.m_infoRequestParameters);
        swap(lhs.m_sandbox, rhs.m_sandbox);
        swap(lhs.m_xboxId, rhs.m_xboxId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreateAccount(bool value)
    {
        this->m_model.createAccount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInfoRequestParameters(StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> value)
    {
        m_infoRequestParameters = std::move(value);
        this->m_model.infoRequestParameters = m_infoRequestParameters ? &m_infoRequestParameters->Model() : nullptr;
    }

    void SetSandbox(String value)
    {
        m_sandbox = std::move(value);
        this->m_model.sandbox =  m_sandbox.empty() ? nullptr : m_sandbox.data();
    }

    void SetXboxId(String value)
    {
        m_xboxId = std::move(value);
        this->m_model.xboxId =  m_xboxId.empty() ? nullptr : m_xboxId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.infoRequestParameters = m_infoRequestParameters ?  &m_infoRequestParameters->Model() : nullptr;
        this->m_model.sandbox = m_sandbox.empty() ? nullptr : m_sandbox.data();
        this->m_model.xboxId = m_xboxId.empty() ? nullptr : m_xboxId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFGetPlayerCombinedInfoRequestParamsWrapper<Alloc>> m_infoRequestParameters;
    String m_sandbox;
    String m_xboxId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationServerSetPlayerSecretRequestWrapper : public ModelWrapper<PFAuthenticationServerSetPlayerSecretRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationServerSetPlayerSecretRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationServerSetPlayerSecretRequestWrapper() = default;

    PFAuthenticationServerSetPlayerSecretRequestWrapper(const PFAuthenticationServerSetPlayerSecretRequest& model) :
        ModelWrapper<PFAuthenticationServerSetPlayerSecretRequest, Alloc>{ model },
        m_playerSecret{ SafeString(model.playerSecret) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAuthenticationServerSetPlayerSecretRequestWrapper(const PFAuthenticationServerSetPlayerSecretRequestWrapper& src) :
        PFAuthenticationServerSetPlayerSecretRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationServerSetPlayerSecretRequestWrapper(PFAuthenticationServerSetPlayerSecretRequestWrapper&& src) :
        PFAuthenticationServerSetPlayerSecretRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationServerSetPlayerSecretRequestWrapper& operator=(PFAuthenticationServerSetPlayerSecretRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationServerSetPlayerSecretRequestWrapper() = default;

    friend void swap(PFAuthenticationServerSetPlayerSecretRequestWrapper& lhs, PFAuthenticationServerSetPlayerSecretRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playerSecret, rhs.m_playerSecret);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayerSecret(String value)
    {
        m_playerSecret = std::move(value);
        this->m_model.playerSecret =  m_playerSecret.empty() ? nullptr : m_playerSecret.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playerSecret = m_playerSecret.empty() ? nullptr : m_playerSecret.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playerSecret;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationAuthenticateCustomIdRequestWrapper : public ModelWrapper<PFAuthenticationAuthenticateCustomIdRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationAuthenticateCustomIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationAuthenticateCustomIdRequestWrapper() = default;

    PFAuthenticationAuthenticateCustomIdRequestWrapper(const PFAuthenticationAuthenticateCustomIdRequest& model) :
        ModelWrapper<PFAuthenticationAuthenticateCustomIdRequest, Alloc>{ model },
        m_customId{ SafeString(model.customId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAuthenticationAuthenticateCustomIdRequestWrapper(const PFAuthenticationAuthenticateCustomIdRequestWrapper& src) :
        PFAuthenticationAuthenticateCustomIdRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationAuthenticateCustomIdRequestWrapper(PFAuthenticationAuthenticateCustomIdRequestWrapper&& src) :
        PFAuthenticationAuthenticateCustomIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationAuthenticateCustomIdRequestWrapper& operator=(PFAuthenticationAuthenticateCustomIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationAuthenticateCustomIdRequestWrapper() = default;

    friend void swap(PFAuthenticationAuthenticateCustomIdRequestWrapper& lhs, PFAuthenticationAuthenticateCustomIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customId, rhs.m_customId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
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

private:
    void SetModelPointers()
    {
        this->m_model.customId = m_customId.empty() ? nullptr : m_customId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_customId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationAuthenticateCustomIdResultWrapper : public ModelWrapper<PFAuthenticationAuthenticateCustomIdResult, Alloc>
{
public:
    using ModelType = typename PFAuthenticationAuthenticateCustomIdResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationAuthenticateCustomIdResultWrapper() = default;

    PFAuthenticationAuthenticateCustomIdResultWrapper(const PFAuthenticationAuthenticateCustomIdResult& model) :
        ModelWrapper<PFAuthenticationAuthenticateCustomIdResult, Alloc>{ model },
        m_entityToken{ model.entityToken ? StdExtra::optional<PFAuthenticationEntityTokenResponseWrapper<Alloc>>{ *model.entityToken } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationAuthenticateCustomIdResultWrapper(const PFAuthenticationAuthenticateCustomIdResultWrapper& src) :
        PFAuthenticationAuthenticateCustomIdResultWrapper{ src.Model() }
    {
    }

    PFAuthenticationAuthenticateCustomIdResultWrapper(PFAuthenticationAuthenticateCustomIdResultWrapper&& src) :
        PFAuthenticationAuthenticateCustomIdResultWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationAuthenticateCustomIdResultWrapper& operator=(PFAuthenticationAuthenticateCustomIdResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationAuthenticateCustomIdResultWrapper() = default;

    friend void swap(PFAuthenticationAuthenticateCustomIdResultWrapper& lhs, PFAuthenticationAuthenticateCustomIdResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_entityToken, rhs.m_entityToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEntityToken(StdExtra::optional<PFAuthenticationEntityTokenResponseWrapper<Alloc>> value)
    {
        m_entityToken = std::move(value);
        this->m_model.entityToken = m_entityToken ? &m_entityToken->Model() : nullptr;
    }

    void SetNewlyCreated(bool value)
    {
        this->m_model.newlyCreated = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.entityToken = m_entityToken ?  &m_entityToken->Model() : nullptr;
    }

    StdExtra::optional<PFAuthenticationEntityTokenResponseWrapper<Alloc>> m_entityToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationDeleteRequestWrapper : public ModelWrapper<PFAuthenticationDeleteRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationDeleteRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationDeleteRequestWrapper() = default;

    PFAuthenticationDeleteRequestWrapper(const PFAuthenticationDeleteRequest& model) :
        ModelWrapper<PFAuthenticationDeleteRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? *model.entity : decltype(*model.entity){} }
    {
        SetModelPointers();
    }

    PFAuthenticationDeleteRequestWrapper(const PFAuthenticationDeleteRequestWrapper& src) :
        PFAuthenticationDeleteRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationDeleteRequestWrapper(PFAuthenticationDeleteRequestWrapper&& src) :
        PFAuthenticationDeleteRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationDeleteRequestWrapper& operator=(PFAuthenticationDeleteRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationDeleteRequestWrapper() = default;

    friend void swap(PFAuthenticationDeleteRequestWrapper& lhs, PFAuthenticationDeleteRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
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

    void SetEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = &m_entity.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = &m_entity.Model();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationGetEntityTokenRequestWrapper : public ModelWrapper<PFAuthenticationGetEntityTokenRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationGetEntityTokenRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationGetEntityTokenRequestWrapper() = default;

    PFAuthenticationGetEntityTokenRequestWrapper(const PFAuthenticationGetEntityTokenRequest& model) :
        ModelWrapper<PFAuthenticationGetEntityTokenRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationGetEntityTokenRequestWrapper(const PFAuthenticationGetEntityTokenRequestWrapper& src) :
        PFAuthenticationGetEntityTokenRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationGetEntityTokenRequestWrapper(PFAuthenticationGetEntityTokenRequestWrapper&& src) :
        PFAuthenticationGetEntityTokenRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationGetEntityTokenRequestWrapper& operator=(PFAuthenticationGetEntityTokenRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationGetEntityTokenRequestWrapper() = default;

    friend void swap(PFAuthenticationGetEntityTokenRequestWrapper& lhs, PFAuthenticationGetEntityTokenRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
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

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationValidateEntityTokenRequestWrapper : public ModelWrapper<PFAuthenticationValidateEntityTokenRequest, Alloc>
{
public:
    using ModelType = typename PFAuthenticationValidateEntityTokenRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationValidateEntityTokenRequestWrapper() = default;

    PFAuthenticationValidateEntityTokenRequestWrapper(const PFAuthenticationValidateEntityTokenRequest& model) :
        ModelWrapper<PFAuthenticationValidateEntityTokenRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entityToken{ SafeString(model.entityToken) }
    {
        SetModelPointers();
    }

    PFAuthenticationValidateEntityTokenRequestWrapper(const PFAuthenticationValidateEntityTokenRequestWrapper& src) :
        PFAuthenticationValidateEntityTokenRequestWrapper{ src.Model() }
    {
    }

    PFAuthenticationValidateEntityTokenRequestWrapper(PFAuthenticationValidateEntityTokenRequestWrapper&& src) :
        PFAuthenticationValidateEntityTokenRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationValidateEntityTokenRequestWrapper& operator=(PFAuthenticationValidateEntityTokenRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationValidateEntityTokenRequestWrapper() = default;

    friend void swap(PFAuthenticationValidateEntityTokenRequestWrapper& lhs, PFAuthenticationValidateEntityTokenRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entityToken, rhs.m_entityToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntityToken(String value)
    {
        m_entityToken = std::move(value);
        this->m_model.entityToken =  m_entityToken.empty() ? nullptr : m_entityToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entityToken = m_entityToken.empty() ? nullptr : m_entityToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_entityToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAuthenticationValidateEntityTokenResponseWrapper : public ModelWrapper<PFAuthenticationValidateEntityTokenResponse, Alloc>
{
public:
    using ModelType = typename PFAuthenticationValidateEntityTokenResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAuthenticationValidateEntityTokenResponseWrapper() = default;

    PFAuthenticationValidateEntityTokenResponseWrapper(const PFAuthenticationValidateEntityTokenResponse& model) :
        ModelWrapper<PFAuthenticationValidateEntityTokenResponse, Alloc>{ model },
        m_entity{ model.entity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.entity } : StdExtra::nullopt },
        m_identifiedDeviceType{ model.identifiedDeviceType ? StdExtra::optional<PFAuthenticationIdentifiedDeviceType>{ *model.identifiedDeviceType } : StdExtra::nullopt },
        m_identityProvider{ model.identityProvider ? StdExtra::optional<PFLoginIdentityProvider>{ *model.identityProvider } : StdExtra::nullopt },
        m_identityProviderIssuedId{ SafeString(model.identityProviderIssuedId) },
        m_lineage{ model.lineage ? StdExtra::optional<PFEntityLineageWrapper<Alloc>>{ *model.lineage } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAuthenticationValidateEntityTokenResponseWrapper(const PFAuthenticationValidateEntityTokenResponseWrapper& src) :
        PFAuthenticationValidateEntityTokenResponseWrapper{ src.Model() }
    {
    }

    PFAuthenticationValidateEntityTokenResponseWrapper(PFAuthenticationValidateEntityTokenResponseWrapper&& src) :
        PFAuthenticationValidateEntityTokenResponseWrapper{}
    {
        swap(*this, src);
    }

    PFAuthenticationValidateEntityTokenResponseWrapper& operator=(PFAuthenticationValidateEntityTokenResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAuthenticationValidateEntityTokenResponseWrapper() = default;

    friend void swap(PFAuthenticationValidateEntityTokenResponseWrapper& lhs, PFAuthenticationValidateEntityTokenResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_entity, rhs.m_entity);
        swap(lhs.m_identifiedDeviceType, rhs.m_identifiedDeviceType);
        swap(lhs.m_identityProvider, rhs.m_identityProvider);
        swap(lhs.m_identityProviderIssuedId, rhs.m_identityProviderIssuedId);
        swap(lhs.m_lineage, rhs.m_lineage);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_entity = std::move(value);
        this->m_model.entity = m_entity ? &m_entity->Model() : nullptr;
    }

    void SetIdentifiedDeviceType(StdExtra::optional<PFAuthenticationIdentifiedDeviceType> value)
    {
        m_identifiedDeviceType = std::move(value);
        this->m_model.identifiedDeviceType = m_identifiedDeviceType ? m_identifiedDeviceType.operator->() : nullptr;
    }

    void SetIdentityProvider(StdExtra::optional<PFLoginIdentityProvider> value)
    {
        m_identityProvider = std::move(value);
        this->m_model.identityProvider = m_identityProvider ? m_identityProvider.operator->() : nullptr;
    }

    void SetIdentityProviderIssuedId(String value)
    {
        m_identityProviderIssuedId = std::move(value);
        this->m_model.identityProviderIssuedId =  m_identityProviderIssuedId.empty() ? nullptr : m_identityProviderIssuedId.data();
    }

    void SetLineage(StdExtra::optional<PFEntityLineageWrapper<Alloc>> value)
    {
        m_lineage = std::move(value);
        this->m_model.lineage = m_lineage ? &m_lineage->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.entity = m_entity ?  &m_entity->Model() : nullptr;
        this->m_model.identifiedDeviceType = m_identifiedDeviceType ? m_identifiedDeviceType.operator->() : nullptr;
        this->m_model.identityProvider = m_identityProvider ? m_identityProvider.operator->() : nullptr;
        this->m_model.identityProviderIssuedId = m_identityProviderIssuedId.empty() ? nullptr : m_identityProviderIssuedId.data();
        this->m_model.lineage = m_lineage ?  &m_lineage->Model() : nullptr;
    }

    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_entity;
    StdExtra::optional<PFAuthenticationIdentifiedDeviceType> m_identifiedDeviceType;
    StdExtra::optional<PFLoginIdentityProvider> m_identityProvider;
    String m_identityProviderIssuedId;
    StdExtra::optional<PFEntityLineageWrapper<Alloc>> m_lineage;
};

} // namespace Wrappers
} // namespace PlayFab
