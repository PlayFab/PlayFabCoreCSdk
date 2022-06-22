// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFSharedDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFEntityKeyWrapper : public ModelWrapper<PFEntityKey, Alloc>
{
public:
    using ModelType = typename PFEntityKey;
    using DictionaryEntryType = typename PFEntityKeyDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEntityKeyWrapper() = default;

    PFEntityKeyWrapper(const PFEntityKey& model) :
        ModelWrapper<PFEntityKey, Alloc>{ model },
        m_id{ SafeString(model.id) },
        m_type{ SafeString(model.type) }
    {
        SetModelPointers();
    }

    PFEntityKeyWrapper(const PFEntityKeyWrapper& src) :
        PFEntityKeyWrapper{ src.Model() }
    {
    }

    PFEntityKeyWrapper(PFEntityKeyWrapper&& src) :
        PFEntityKeyWrapper{}
    {
        swap(*this, src);
    }

    PFEntityKeyWrapper& operator=(PFEntityKeyWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEntityKeyWrapper() = default;

    friend void swap(PFEntityKeyWrapper& lhs, PFEntityKeyWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_type, rhs.m_type);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetType(String value)
    {
        m_type = std::move(value);
        this->m_model.type =  m_type.empty() ? nullptr : m_type.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.type = m_type.empty() ? nullptr : m_type.data();
    }

    String m_id;
    String m_type;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPortWrapper : public ModelWrapper<PFPort, Alloc>
{
public:
    using ModelType = typename PFPort;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPortWrapper() = default;

    PFPortWrapper(const PFPort& model) :
        ModelWrapper<PFPort, Alloc>{ model },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFPortWrapper(const PFPortWrapper& src) :
        PFPortWrapper{ src.Model() }
    {
    }

    PFPortWrapper(PFPortWrapper&& src) :
        PFPortWrapper{}
    {
        swap(*this, src);
    }

    PFPortWrapper& operator=(PFPortWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPortWrapper() = default;

    friend void swap(PFPortWrapper& lhs, PFPortWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetNum(int32_t value)
    {
        this->m_model.num = value;
    }

    void SetProtocol(PFProtocolType value)
    {
        this->m_model.protocol = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_name;
};

} // namespace Wrappers
} // namespace PlayFab
