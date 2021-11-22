// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFContentDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentDeleteContentRequestWrapper : public ModelWrapper<PFContentDeleteContentRequest, Alloc>
{
public:
    using ModelType = typename PFContentDeleteContentRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentDeleteContentRequestWrapper() = default;

    PFContentDeleteContentRequestWrapper(const PFContentDeleteContentRequest& model) :
        ModelWrapper<PFContentDeleteContentRequest, Alloc>{ model },
        m_key{ SafeString(model.key) }
    {
        SetModelPointers();
    }

    PFContentDeleteContentRequestWrapper(const PFContentDeleteContentRequestWrapper& src) :
        PFContentDeleteContentRequestWrapper{ src.Model() }
    {
    }

    PFContentDeleteContentRequestWrapper(PFContentDeleteContentRequestWrapper&& src) :
        PFContentDeleteContentRequestWrapper{}
    {
        swap(*this, src);
    }

    PFContentDeleteContentRequestWrapper& operator=(PFContentDeleteContentRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentDeleteContentRequestWrapper() = default;

    friend void swap(PFContentDeleteContentRequestWrapper& lhs, PFContentDeleteContentRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_key, rhs.m_key);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
    }

    String m_key;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentGetContentListRequestWrapper : public ModelWrapper<PFContentGetContentListRequest, Alloc>
{
public:
    using ModelType = typename PFContentGetContentListRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentGetContentListRequestWrapper() = default;

    PFContentGetContentListRequestWrapper(const PFContentGetContentListRequest& model) :
        ModelWrapper<PFContentGetContentListRequest, Alloc>{ model },
        m_prefix{ SafeString(model.prefix) }
    {
        SetModelPointers();
    }

    PFContentGetContentListRequestWrapper(const PFContentGetContentListRequestWrapper& src) :
        PFContentGetContentListRequestWrapper{ src.Model() }
    {
    }

    PFContentGetContentListRequestWrapper(PFContentGetContentListRequestWrapper&& src) :
        PFContentGetContentListRequestWrapper{}
    {
        swap(*this, src);
    }

    PFContentGetContentListRequestWrapper& operator=(PFContentGetContentListRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentGetContentListRequestWrapper() = default;

    friend void swap(PFContentGetContentListRequestWrapper& lhs, PFContentGetContentListRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_prefix, rhs.m_prefix);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPrefix(String value)
    {
        m_prefix = std::move(value);
        this->m_model.prefix =  m_prefix.empty() ? nullptr : m_prefix.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.prefix = m_prefix.empty() ? nullptr : m_prefix.data();
    }

    String m_prefix;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentContentInfoWrapper : public ModelWrapper<PFContentContentInfo, Alloc>
{
public:
    using ModelType = typename PFContentContentInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentContentInfoWrapper() = default;

    PFContentContentInfoWrapper(const PFContentContentInfo& model) :
        ModelWrapper<PFContentContentInfo, Alloc>{ model },
        m_key{ SafeString(model.key) }
    {
        SetModelPointers();
    }

    PFContentContentInfoWrapper(const PFContentContentInfoWrapper& src) :
        PFContentContentInfoWrapper{ src.Model() }
    {
    }

    PFContentContentInfoWrapper(PFContentContentInfoWrapper&& src) :
        PFContentContentInfoWrapper{}
    {
        swap(*this, src);
    }

    PFContentContentInfoWrapper& operator=(PFContentContentInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentContentInfoWrapper() = default;

    friend void swap(PFContentContentInfoWrapper& lhs, PFContentContentInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_key, rhs.m_key);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

    void SetLastModified(time_t value)
    {
        this->m_model.lastModified = value;
    }

    void SetSize(double value)
    {
        this->m_model.size = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
    }

    String m_key;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentGetContentListResultWrapper : public ModelWrapper<PFContentGetContentListResult, Alloc>
{
public:
    using ModelType = typename PFContentGetContentListResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentGetContentListResultWrapper() = default;

    PFContentGetContentListResultWrapper(const PFContentGetContentListResult& model) :
        ModelWrapper<PFContentGetContentListResult, Alloc>{ model },
        m_contents{ model.contents, model.contents + model.contentsCount }
    {
        SetModelPointers();
    }

    PFContentGetContentListResultWrapper(const PFContentGetContentListResultWrapper& src) :
        PFContentGetContentListResultWrapper{ src.Model() }
    {
    }

    PFContentGetContentListResultWrapper(PFContentGetContentListResultWrapper&& src) :
        PFContentGetContentListResultWrapper{}
    {
        swap(*this, src);
    }

    PFContentGetContentListResultWrapper& operator=(PFContentGetContentListResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentGetContentListResultWrapper() = default;

    friend void swap(PFContentGetContentListResultWrapper& lhs, PFContentGetContentListResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_contents, rhs.m_contents);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContents(ModelVector<PFContentContentInfoWrapper<Alloc>, Alloc> value)
    {
        m_contents = std::move(value);
        this->m_model.contents =  m_contents.empty() ? nullptr : m_contents.data();
        this->m_model.contentsCount =  static_cast<uint32_t>(m_contents.size());
    }

    void SetItemCount(int32_t value)
    {
        this->m_model.itemCount = value;
    }

    void SetTotalSize(uint32_t value)
    {
        this->m_model.totalSize = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.contents = m_contents.empty() ? nullptr : m_contents.data();
    }

    ModelVector<PFContentContentInfoWrapper<Alloc>, Alloc> m_contents;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentGetContentUploadUrlRequestWrapper : public ModelWrapper<PFContentGetContentUploadUrlRequest, Alloc>
{
public:
    using ModelType = typename PFContentGetContentUploadUrlRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentGetContentUploadUrlRequestWrapper() = default;

    PFContentGetContentUploadUrlRequestWrapper(const PFContentGetContentUploadUrlRequest& model) :
        ModelWrapper<PFContentGetContentUploadUrlRequest, Alloc>{ model },
        m_contentType{ SafeString(model.contentType) },
        m_key{ SafeString(model.key) }
    {
        SetModelPointers();
    }

    PFContentGetContentUploadUrlRequestWrapper(const PFContentGetContentUploadUrlRequestWrapper& src) :
        PFContentGetContentUploadUrlRequestWrapper{ src.Model() }
    {
    }

    PFContentGetContentUploadUrlRequestWrapper(PFContentGetContentUploadUrlRequestWrapper&& src) :
        PFContentGetContentUploadUrlRequestWrapper{}
    {
        swap(*this, src);
    }

    PFContentGetContentUploadUrlRequestWrapper& operator=(PFContentGetContentUploadUrlRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentGetContentUploadUrlRequestWrapper() = default;

    friend void swap(PFContentGetContentUploadUrlRequestWrapper& lhs, PFContentGetContentUploadUrlRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_contentType, rhs.m_contentType);
        swap(lhs.m_key, rhs.m_key);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContentType(String value)
    {
        m_contentType = std::move(value);
        this->m_model.contentType =  m_contentType.empty() ? nullptr : m_contentType.data();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.contentType = m_contentType.empty() ? nullptr : m_contentType.data();
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
    }

    String m_contentType;
    String m_key;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentGetContentUploadUrlResultWrapper : public ModelWrapper<PFContentGetContentUploadUrlResult, Alloc>
{
public:
    using ModelType = typename PFContentGetContentUploadUrlResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentGetContentUploadUrlResultWrapper() = default;

    PFContentGetContentUploadUrlResultWrapper(const PFContentGetContentUploadUrlResult& model) :
        ModelWrapper<PFContentGetContentUploadUrlResult, Alloc>{ model },
        m_URL{ SafeString(model.URL) }
    {
        SetModelPointers();
    }

    PFContentGetContentUploadUrlResultWrapper(const PFContentGetContentUploadUrlResultWrapper& src) :
        PFContentGetContentUploadUrlResultWrapper{ src.Model() }
    {
    }

    PFContentGetContentUploadUrlResultWrapper(PFContentGetContentUploadUrlResultWrapper&& src) :
        PFContentGetContentUploadUrlResultWrapper{}
    {
        swap(*this, src);
    }

    PFContentGetContentUploadUrlResultWrapper& operator=(PFContentGetContentUploadUrlResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentGetContentUploadUrlResultWrapper() = default;

    friend void swap(PFContentGetContentUploadUrlResultWrapper& lhs, PFContentGetContentUploadUrlResultWrapper& rhs)
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
class PFContentGetContentDownloadUrlRequestWrapper : public ModelWrapper<PFContentGetContentDownloadUrlRequest, Alloc>
{
public:
    using ModelType = typename PFContentGetContentDownloadUrlRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentGetContentDownloadUrlRequestWrapper() = default;

    PFContentGetContentDownloadUrlRequestWrapper(const PFContentGetContentDownloadUrlRequest& model) :
        ModelWrapper<PFContentGetContentDownloadUrlRequest, Alloc>{ model },
        m_httpMethod{ SafeString(model.httpMethod) },
        m_key{ SafeString(model.key) },
        m_thruCDN{ model.thruCDN ? StdExtra::optional<bool>{ *model.thruCDN } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFContentGetContentDownloadUrlRequestWrapper(const PFContentGetContentDownloadUrlRequestWrapper& src) :
        PFContentGetContentDownloadUrlRequestWrapper{ src.Model() }
    {
    }

    PFContentGetContentDownloadUrlRequestWrapper(PFContentGetContentDownloadUrlRequestWrapper&& src) :
        PFContentGetContentDownloadUrlRequestWrapper{}
    {
        swap(*this, src);
    }

    PFContentGetContentDownloadUrlRequestWrapper& operator=(PFContentGetContentDownloadUrlRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentGetContentDownloadUrlRequestWrapper() = default;

    friend void swap(PFContentGetContentDownloadUrlRequestWrapper& lhs, PFContentGetContentDownloadUrlRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_httpMethod, rhs.m_httpMethod);
        swap(lhs.m_key, rhs.m_key);
        swap(lhs.m_thruCDN, rhs.m_thruCDN);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetHttpMethod(String value)
    {
        m_httpMethod = std::move(value);
        this->m_model.httpMethod =  m_httpMethod.empty() ? nullptr : m_httpMethod.data();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

    void SetThruCDN(StdExtra::optional<bool> value)
    {
        m_thruCDN = std::move(value);
        this->m_model.thruCDN = m_thruCDN ? m_thruCDN.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.httpMethod = m_httpMethod.empty() ? nullptr : m_httpMethod.data();
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
        this->m_model.thruCDN = m_thruCDN ? m_thruCDN.operator->() : nullptr;
    }

    String m_httpMethod;
    String m_key;
    StdExtra::optional<bool> m_thruCDN;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFContentGetContentDownloadUrlResultWrapper : public ModelWrapper<PFContentGetContentDownloadUrlResult, Alloc>
{
public:
    using ModelType = typename PFContentGetContentDownloadUrlResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFContentGetContentDownloadUrlResultWrapper() = default;

    PFContentGetContentDownloadUrlResultWrapper(const PFContentGetContentDownloadUrlResult& model) :
        ModelWrapper<PFContentGetContentDownloadUrlResult, Alloc>{ model },
        m_URL{ SafeString(model.URL) }
    {
        SetModelPointers();
    }

    PFContentGetContentDownloadUrlResultWrapper(const PFContentGetContentDownloadUrlResultWrapper& src) :
        PFContentGetContentDownloadUrlResultWrapper{ src.Model() }
    {
    }

    PFContentGetContentDownloadUrlResultWrapper(PFContentGetContentDownloadUrlResultWrapper&& src) :
        PFContentGetContentDownloadUrlResultWrapper{}
    {
        swap(*this, src);
    }

    PFContentGetContentDownloadUrlResultWrapper& operator=(PFContentGetContentDownloadUrlResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFContentGetContentDownloadUrlResultWrapper() = default;

    friend void swap(PFContentGetContentDownloadUrlResultWrapper& lhs, PFContentGetContentDownloadUrlResultWrapper& rhs)
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

} // namespace Wrappers
} // namespace PlayFab
