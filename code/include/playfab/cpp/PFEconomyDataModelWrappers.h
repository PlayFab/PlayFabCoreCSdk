// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFEconomyDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFEconomyRefundPurchaseRequestWrapper : public ModelWrapper<PFEconomyRefundPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFEconomyRefundPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEconomyRefundPurchaseRequestWrapper() = default;

    PFEconomyRefundPurchaseRequestWrapper(const PFEconomyRefundPurchaseRequest& model) :
        ModelWrapper<PFEconomyRefundPurchaseRequest, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFEconomyRefundPurchaseRequestWrapper(const PFEconomyRefundPurchaseRequestWrapper& src) :
        PFEconomyRefundPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFEconomyRefundPurchaseRequestWrapper(PFEconomyRefundPurchaseRequestWrapper&& src) :
        PFEconomyRefundPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEconomyRefundPurchaseRequestWrapper& operator=(PFEconomyRefundPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEconomyRefundPurchaseRequestWrapper() = default;

    friend void swap(PFEconomyRefundPurchaseRequestWrapper& lhs, PFEconomyRefundPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    String m_orderId;
    String m_playFabId;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEconomyRefundPurchaseResponseWrapper : public ModelWrapper<PFEconomyRefundPurchaseResponse, Alloc>
{
public:
    using ModelType = typename PFEconomyRefundPurchaseResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEconomyRefundPurchaseResponseWrapper() = default;

    PFEconomyRefundPurchaseResponseWrapper(const PFEconomyRefundPurchaseResponse& model) :
        ModelWrapper<PFEconomyRefundPurchaseResponse, Alloc>{ model },
        m_purchaseStatus{ SafeString(model.purchaseStatus) }
    {
        SetModelPointers();
    }

    PFEconomyRefundPurchaseResponseWrapper(const PFEconomyRefundPurchaseResponseWrapper& src) :
        PFEconomyRefundPurchaseResponseWrapper{ src.Model() }
    {
    }

    PFEconomyRefundPurchaseResponseWrapper(PFEconomyRefundPurchaseResponseWrapper&& src) :
        PFEconomyRefundPurchaseResponseWrapper{}
    {
        swap(*this, src);
    }

    PFEconomyRefundPurchaseResponseWrapper& operator=(PFEconomyRefundPurchaseResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEconomyRefundPurchaseResponseWrapper() = default;

    friend void swap(PFEconomyRefundPurchaseResponseWrapper& lhs, PFEconomyRefundPurchaseResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_purchaseStatus, rhs.m_purchaseStatus);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPurchaseStatus(String value)
    {
        m_purchaseStatus = std::move(value);
        this->m_model.purchaseStatus =  m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.purchaseStatus = m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

    String m_purchaseStatus;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEconomyResolvePurchaseDisputeRequestWrapper : public ModelWrapper<PFEconomyResolvePurchaseDisputeRequest, Alloc>
{
public:
    using ModelType = typename PFEconomyResolvePurchaseDisputeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEconomyResolvePurchaseDisputeRequestWrapper() = default;

    PFEconomyResolvePurchaseDisputeRequestWrapper(const PFEconomyResolvePurchaseDisputeRequest& model) :
        ModelWrapper<PFEconomyResolvePurchaseDisputeRequest, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFEconomyResolvePurchaseDisputeRequestWrapper(const PFEconomyResolvePurchaseDisputeRequestWrapper& src) :
        PFEconomyResolvePurchaseDisputeRequestWrapper{ src.Model() }
    {
    }

    PFEconomyResolvePurchaseDisputeRequestWrapper(PFEconomyResolvePurchaseDisputeRequestWrapper&& src) :
        PFEconomyResolvePurchaseDisputeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFEconomyResolvePurchaseDisputeRequestWrapper& operator=(PFEconomyResolvePurchaseDisputeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEconomyResolvePurchaseDisputeRequestWrapper() = default;

    friend void swap(PFEconomyResolvePurchaseDisputeRequestWrapper& lhs, PFEconomyResolvePurchaseDisputeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetOutcome(PFEconomyResolutionOutcome value)
    {
        this->m_model.outcome = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    String m_orderId;
    String m_playFabId;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFEconomyResolvePurchaseDisputeResponseWrapper : public ModelWrapper<PFEconomyResolvePurchaseDisputeResponse, Alloc>
{
public:
    using ModelType = typename PFEconomyResolvePurchaseDisputeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFEconomyResolvePurchaseDisputeResponseWrapper() = default;

    PFEconomyResolvePurchaseDisputeResponseWrapper(const PFEconomyResolvePurchaseDisputeResponse& model) :
        ModelWrapper<PFEconomyResolvePurchaseDisputeResponse, Alloc>{ model },
        m_purchaseStatus{ SafeString(model.purchaseStatus) }
    {
        SetModelPointers();
    }

    PFEconomyResolvePurchaseDisputeResponseWrapper(const PFEconomyResolvePurchaseDisputeResponseWrapper& src) :
        PFEconomyResolvePurchaseDisputeResponseWrapper{ src.Model() }
    {
    }

    PFEconomyResolvePurchaseDisputeResponseWrapper(PFEconomyResolvePurchaseDisputeResponseWrapper&& src) :
        PFEconomyResolvePurchaseDisputeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFEconomyResolvePurchaseDisputeResponseWrapper& operator=(PFEconomyResolvePurchaseDisputeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFEconomyResolvePurchaseDisputeResponseWrapper() = default;

    friend void swap(PFEconomyResolvePurchaseDisputeResponseWrapper& lhs, PFEconomyResolvePurchaseDisputeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_purchaseStatus, rhs.m_purchaseStatus);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPurchaseStatus(String value)
    {
        m_purchaseStatus = std::move(value);
        this->m_model.purchaseStatus =  m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.purchaseStatus = m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

    String m_purchaseStatus;
};

} // namespace Wrappers
} // namespace PlayFab
