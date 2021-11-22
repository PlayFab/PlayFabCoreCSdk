// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFTradingDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingAcceptTradeRequestWrapper : public ModelWrapper<PFTradingAcceptTradeRequest, Alloc>
{
public:
    using ModelType = typename PFTradingAcceptTradeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingAcceptTradeRequestWrapper() = default;

    PFTradingAcceptTradeRequestWrapper(const PFTradingAcceptTradeRequest& model) :
        ModelWrapper<PFTradingAcceptTradeRequest, Alloc>{ model },
        m_acceptedInventoryInstanceIds{ model.acceptedInventoryInstanceIds, model.acceptedInventoryInstanceIds + model.acceptedInventoryInstanceIdsCount },
        m_offeringPlayerId{ SafeString(model.offeringPlayerId) },
        m_tradeId{ SafeString(model.tradeId) }
    {
        SetModelPointers();
    }

    PFTradingAcceptTradeRequestWrapper(const PFTradingAcceptTradeRequestWrapper& src) :
        PFTradingAcceptTradeRequestWrapper{ src.Model() }
    {
    }

    PFTradingAcceptTradeRequestWrapper(PFTradingAcceptTradeRequestWrapper&& src) :
        PFTradingAcceptTradeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTradingAcceptTradeRequestWrapper& operator=(PFTradingAcceptTradeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingAcceptTradeRequestWrapper() = default;

    friend void swap(PFTradingAcceptTradeRequestWrapper& lhs, PFTradingAcceptTradeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_acceptedInventoryInstanceIds, rhs.m_acceptedInventoryInstanceIds);
        swap(lhs.m_offeringPlayerId, rhs.m_offeringPlayerId);
        swap(lhs.m_tradeId, rhs.m_tradeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAcceptedInventoryInstanceIds(CStringVector<Alloc> value)
    {
        m_acceptedInventoryInstanceIds = std::move(value);
        this->m_model.acceptedInventoryInstanceIds =  m_acceptedInventoryInstanceIds.empty() ? nullptr : m_acceptedInventoryInstanceIds.data();
        this->m_model.acceptedInventoryInstanceIdsCount =  static_cast<uint32_t>(m_acceptedInventoryInstanceIds.size());
    }

    void SetOfferingPlayerId(String value)
    {
        m_offeringPlayerId = std::move(value);
        this->m_model.offeringPlayerId =  m_offeringPlayerId.empty() ? nullptr : m_offeringPlayerId.data();
    }

    void SetTradeId(String value)
    {
        m_tradeId = std::move(value);
        this->m_model.tradeId =  m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.acceptedInventoryInstanceIds = m_acceptedInventoryInstanceIds.empty() ? nullptr : m_acceptedInventoryInstanceIds.data();
        this->m_model.offeringPlayerId = m_offeringPlayerId.empty() ? nullptr : m_offeringPlayerId.data();
        this->m_model.tradeId = m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

    CStringVector<Alloc> m_acceptedInventoryInstanceIds;
    String m_offeringPlayerId;
    String m_tradeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingTradeInfoWrapper : public ModelWrapper<PFTradingTradeInfo, Alloc>
{
public:
    using ModelType = typename PFTradingTradeInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingTradeInfoWrapper() = default;

    PFTradingTradeInfoWrapper(const PFTradingTradeInfo& model) :
        ModelWrapper<PFTradingTradeInfo, Alloc>{ model },
        m_acceptedInventoryInstanceIds{ model.acceptedInventoryInstanceIds, model.acceptedInventoryInstanceIds + model.acceptedInventoryInstanceIdsCount },
        m_acceptedPlayerId{ SafeString(model.acceptedPlayerId) },
        m_allowedPlayerIds{ model.allowedPlayerIds, model.allowedPlayerIds + model.allowedPlayerIdsCount },
        m_cancelledAt{ model.cancelledAt ? StdExtra::optional<time_t>{ *model.cancelledAt } : StdExtra::nullopt },
        m_filledAt{ model.filledAt ? StdExtra::optional<time_t>{ *model.filledAt } : StdExtra::nullopt },
        m_invalidatedAt{ model.invalidatedAt ? StdExtra::optional<time_t>{ *model.invalidatedAt } : StdExtra::nullopt },
        m_offeredCatalogItemIds{ model.offeredCatalogItemIds, model.offeredCatalogItemIds + model.offeredCatalogItemIdsCount },
        m_offeredInventoryInstanceIds{ model.offeredInventoryInstanceIds, model.offeredInventoryInstanceIds + model.offeredInventoryInstanceIdsCount },
        m_offeringPlayerId{ SafeString(model.offeringPlayerId) },
        m_openedAt{ model.openedAt ? StdExtra::optional<time_t>{ *model.openedAt } : StdExtra::nullopt },
        m_requestedCatalogItemIds{ model.requestedCatalogItemIds, model.requestedCatalogItemIds + model.requestedCatalogItemIdsCount },
        m_status{ model.status ? StdExtra::optional<PFTradingTradeStatus>{ *model.status } : StdExtra::nullopt },
        m_tradeId{ SafeString(model.tradeId) }
    {
        SetModelPointers();
    }

    PFTradingTradeInfoWrapper(const PFTradingTradeInfoWrapper& src) :
        PFTradingTradeInfoWrapper{ src.Model() }
    {
    }

    PFTradingTradeInfoWrapper(PFTradingTradeInfoWrapper&& src) :
        PFTradingTradeInfoWrapper{}
    {
        swap(*this, src);
    }

    PFTradingTradeInfoWrapper& operator=(PFTradingTradeInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingTradeInfoWrapper() = default;

    friend void swap(PFTradingTradeInfoWrapper& lhs, PFTradingTradeInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_acceptedInventoryInstanceIds, rhs.m_acceptedInventoryInstanceIds);
        swap(lhs.m_acceptedPlayerId, rhs.m_acceptedPlayerId);
        swap(lhs.m_allowedPlayerIds, rhs.m_allowedPlayerIds);
        swap(lhs.m_cancelledAt, rhs.m_cancelledAt);
        swap(lhs.m_filledAt, rhs.m_filledAt);
        swap(lhs.m_invalidatedAt, rhs.m_invalidatedAt);
        swap(lhs.m_offeredCatalogItemIds, rhs.m_offeredCatalogItemIds);
        swap(lhs.m_offeredInventoryInstanceIds, rhs.m_offeredInventoryInstanceIds);
        swap(lhs.m_offeringPlayerId, rhs.m_offeringPlayerId);
        swap(lhs.m_openedAt, rhs.m_openedAt);
        swap(lhs.m_requestedCatalogItemIds, rhs.m_requestedCatalogItemIds);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_tradeId, rhs.m_tradeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAcceptedInventoryInstanceIds(CStringVector<Alloc> value)
    {
        m_acceptedInventoryInstanceIds = std::move(value);
        this->m_model.acceptedInventoryInstanceIds =  m_acceptedInventoryInstanceIds.empty() ? nullptr : m_acceptedInventoryInstanceIds.data();
        this->m_model.acceptedInventoryInstanceIdsCount =  static_cast<uint32_t>(m_acceptedInventoryInstanceIds.size());
    }

    void SetAcceptedPlayerId(String value)
    {
        m_acceptedPlayerId = std::move(value);
        this->m_model.acceptedPlayerId =  m_acceptedPlayerId.empty() ? nullptr : m_acceptedPlayerId.data();
    }

    void SetAllowedPlayerIds(CStringVector<Alloc> value)
    {
        m_allowedPlayerIds = std::move(value);
        this->m_model.allowedPlayerIds =  m_allowedPlayerIds.empty() ? nullptr : m_allowedPlayerIds.data();
        this->m_model.allowedPlayerIdsCount =  static_cast<uint32_t>(m_allowedPlayerIds.size());
    }

    void SetCancelledAt(StdExtra::optional<time_t> value)
    {
        m_cancelledAt = std::move(value);
        this->m_model.cancelledAt = m_cancelledAt ? m_cancelledAt.operator->() : nullptr;
    }

    void SetFilledAt(StdExtra::optional<time_t> value)
    {
        m_filledAt = std::move(value);
        this->m_model.filledAt = m_filledAt ? m_filledAt.operator->() : nullptr;
    }

    void SetInvalidatedAt(StdExtra::optional<time_t> value)
    {
        m_invalidatedAt = std::move(value);
        this->m_model.invalidatedAt = m_invalidatedAt ? m_invalidatedAt.operator->() : nullptr;
    }

    void SetOfferedCatalogItemIds(CStringVector<Alloc> value)
    {
        m_offeredCatalogItemIds = std::move(value);
        this->m_model.offeredCatalogItemIds =  m_offeredCatalogItemIds.empty() ? nullptr : m_offeredCatalogItemIds.data();
        this->m_model.offeredCatalogItemIdsCount =  static_cast<uint32_t>(m_offeredCatalogItemIds.size());
    }

    void SetOfferedInventoryInstanceIds(CStringVector<Alloc> value)
    {
        m_offeredInventoryInstanceIds = std::move(value);
        this->m_model.offeredInventoryInstanceIds =  m_offeredInventoryInstanceIds.empty() ? nullptr : m_offeredInventoryInstanceIds.data();
        this->m_model.offeredInventoryInstanceIdsCount =  static_cast<uint32_t>(m_offeredInventoryInstanceIds.size());
    }

    void SetOfferingPlayerId(String value)
    {
        m_offeringPlayerId = std::move(value);
        this->m_model.offeringPlayerId =  m_offeringPlayerId.empty() ? nullptr : m_offeringPlayerId.data();
    }

    void SetOpenedAt(StdExtra::optional<time_t> value)
    {
        m_openedAt = std::move(value);
        this->m_model.openedAt = m_openedAt ? m_openedAt.operator->() : nullptr;
    }

    void SetRequestedCatalogItemIds(CStringVector<Alloc> value)
    {
        m_requestedCatalogItemIds = std::move(value);
        this->m_model.requestedCatalogItemIds =  m_requestedCatalogItemIds.empty() ? nullptr : m_requestedCatalogItemIds.data();
        this->m_model.requestedCatalogItemIdsCount =  static_cast<uint32_t>(m_requestedCatalogItemIds.size());
    }

    void SetStatus(StdExtra::optional<PFTradingTradeStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetTradeId(String value)
    {
        m_tradeId = std::move(value);
        this->m_model.tradeId =  m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.acceptedInventoryInstanceIds = m_acceptedInventoryInstanceIds.empty() ? nullptr : m_acceptedInventoryInstanceIds.data();
        this->m_model.acceptedPlayerId = m_acceptedPlayerId.empty() ? nullptr : m_acceptedPlayerId.data();
        this->m_model.allowedPlayerIds = m_allowedPlayerIds.empty() ? nullptr : m_allowedPlayerIds.data();
        this->m_model.cancelledAt = m_cancelledAt ? m_cancelledAt.operator->() : nullptr;
        this->m_model.filledAt = m_filledAt ? m_filledAt.operator->() : nullptr;
        this->m_model.invalidatedAt = m_invalidatedAt ? m_invalidatedAt.operator->() : nullptr;
        this->m_model.offeredCatalogItemIds = m_offeredCatalogItemIds.empty() ? nullptr : m_offeredCatalogItemIds.data();
        this->m_model.offeredInventoryInstanceIds = m_offeredInventoryInstanceIds.empty() ? nullptr : m_offeredInventoryInstanceIds.data();
        this->m_model.offeringPlayerId = m_offeringPlayerId.empty() ? nullptr : m_offeringPlayerId.data();
        this->m_model.openedAt = m_openedAt ? m_openedAt.operator->() : nullptr;
        this->m_model.requestedCatalogItemIds = m_requestedCatalogItemIds.empty() ? nullptr : m_requestedCatalogItemIds.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.tradeId = m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

    CStringVector<Alloc> m_acceptedInventoryInstanceIds;
    String m_acceptedPlayerId;
    CStringVector<Alloc> m_allowedPlayerIds;
    StdExtra::optional<time_t> m_cancelledAt;
    StdExtra::optional<time_t> m_filledAt;
    StdExtra::optional<time_t> m_invalidatedAt;
    CStringVector<Alloc> m_offeredCatalogItemIds;
    CStringVector<Alloc> m_offeredInventoryInstanceIds;
    String m_offeringPlayerId;
    StdExtra::optional<time_t> m_openedAt;
    CStringVector<Alloc> m_requestedCatalogItemIds;
    StdExtra::optional<PFTradingTradeStatus> m_status;
    String m_tradeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingAcceptTradeResponseWrapper : public ModelWrapper<PFTradingAcceptTradeResponse, Alloc>
{
public:
    using ModelType = typename PFTradingAcceptTradeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingAcceptTradeResponseWrapper() = default;

    PFTradingAcceptTradeResponseWrapper(const PFTradingAcceptTradeResponse& model) :
        ModelWrapper<PFTradingAcceptTradeResponse, Alloc>{ model },
        m_trade{ model.trade ? StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>>{ *model.trade } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTradingAcceptTradeResponseWrapper(const PFTradingAcceptTradeResponseWrapper& src) :
        PFTradingAcceptTradeResponseWrapper{ src.Model() }
    {
    }

    PFTradingAcceptTradeResponseWrapper(PFTradingAcceptTradeResponseWrapper&& src) :
        PFTradingAcceptTradeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFTradingAcceptTradeResponseWrapper& operator=(PFTradingAcceptTradeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingAcceptTradeResponseWrapper() = default;

    friend void swap(PFTradingAcceptTradeResponseWrapper& lhs, PFTradingAcceptTradeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_trade, rhs.m_trade);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTrade(StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> value)
    {
        m_trade = std::move(value);
        this->m_model.trade = m_trade ? &m_trade->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.trade = m_trade ?  &m_trade->Model() : nullptr;
    }

    StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> m_trade;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingCancelTradeRequestWrapper : public ModelWrapper<PFTradingCancelTradeRequest, Alloc>
{
public:
    using ModelType = typename PFTradingCancelTradeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingCancelTradeRequestWrapper() = default;

    PFTradingCancelTradeRequestWrapper(const PFTradingCancelTradeRequest& model) :
        ModelWrapper<PFTradingCancelTradeRequest, Alloc>{ model },
        m_tradeId{ SafeString(model.tradeId) }
    {
        SetModelPointers();
    }

    PFTradingCancelTradeRequestWrapper(const PFTradingCancelTradeRequestWrapper& src) :
        PFTradingCancelTradeRequestWrapper{ src.Model() }
    {
    }

    PFTradingCancelTradeRequestWrapper(PFTradingCancelTradeRequestWrapper&& src) :
        PFTradingCancelTradeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTradingCancelTradeRequestWrapper& operator=(PFTradingCancelTradeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingCancelTradeRequestWrapper() = default;

    friend void swap(PFTradingCancelTradeRequestWrapper& lhs, PFTradingCancelTradeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_tradeId, rhs.m_tradeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTradeId(String value)
    {
        m_tradeId = std::move(value);
        this->m_model.tradeId =  m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.tradeId = m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

    String m_tradeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingCancelTradeResponseWrapper : public ModelWrapper<PFTradingCancelTradeResponse, Alloc>
{
public:
    using ModelType = typename PFTradingCancelTradeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingCancelTradeResponseWrapper() = default;

    PFTradingCancelTradeResponseWrapper(const PFTradingCancelTradeResponse& model) :
        ModelWrapper<PFTradingCancelTradeResponse, Alloc>{ model },
        m_trade{ model.trade ? StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>>{ *model.trade } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTradingCancelTradeResponseWrapper(const PFTradingCancelTradeResponseWrapper& src) :
        PFTradingCancelTradeResponseWrapper{ src.Model() }
    {
    }

    PFTradingCancelTradeResponseWrapper(PFTradingCancelTradeResponseWrapper&& src) :
        PFTradingCancelTradeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFTradingCancelTradeResponseWrapper& operator=(PFTradingCancelTradeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingCancelTradeResponseWrapper() = default;

    friend void swap(PFTradingCancelTradeResponseWrapper& lhs, PFTradingCancelTradeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_trade, rhs.m_trade);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTrade(StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> value)
    {
        m_trade = std::move(value);
        this->m_model.trade = m_trade ? &m_trade->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.trade = m_trade ?  &m_trade->Model() : nullptr;
    }

    StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> m_trade;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingGetPlayerTradesRequestWrapper : public ModelWrapper<PFTradingGetPlayerTradesRequest, Alloc>
{
public:
    using ModelType = typename PFTradingGetPlayerTradesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingGetPlayerTradesRequestWrapper() = default;

    PFTradingGetPlayerTradesRequestWrapper(const PFTradingGetPlayerTradesRequest& model) :
        ModelWrapper<PFTradingGetPlayerTradesRequest, Alloc>{ model },
        m_statusFilter{ model.statusFilter ? StdExtra::optional<PFTradingTradeStatus>{ *model.statusFilter } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTradingGetPlayerTradesRequestWrapper(const PFTradingGetPlayerTradesRequestWrapper& src) :
        PFTradingGetPlayerTradesRequestWrapper{ src.Model() }
    {
    }

    PFTradingGetPlayerTradesRequestWrapper(PFTradingGetPlayerTradesRequestWrapper&& src) :
        PFTradingGetPlayerTradesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTradingGetPlayerTradesRequestWrapper& operator=(PFTradingGetPlayerTradesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingGetPlayerTradesRequestWrapper() = default;

    friend void swap(PFTradingGetPlayerTradesRequestWrapper& lhs, PFTradingGetPlayerTradesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statusFilter, rhs.m_statusFilter);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatusFilter(StdExtra::optional<PFTradingTradeStatus> value)
    {
        m_statusFilter = std::move(value);
        this->m_model.statusFilter = m_statusFilter ? m_statusFilter.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statusFilter = m_statusFilter ? m_statusFilter.operator->() : nullptr;
    }

    StdExtra::optional<PFTradingTradeStatus> m_statusFilter;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingGetPlayerTradesResponseWrapper : public ModelWrapper<PFTradingGetPlayerTradesResponse, Alloc>
{
public:
    using ModelType = typename PFTradingGetPlayerTradesResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingGetPlayerTradesResponseWrapper() = default;

    PFTradingGetPlayerTradesResponseWrapper(const PFTradingGetPlayerTradesResponse& model) :
        ModelWrapper<PFTradingGetPlayerTradesResponse, Alloc>{ model },
        m_acceptedTrades{ model.acceptedTrades, model.acceptedTrades + model.acceptedTradesCount },
        m_openedTrades{ model.openedTrades, model.openedTrades + model.openedTradesCount }
    {
        SetModelPointers();
    }

    PFTradingGetPlayerTradesResponseWrapper(const PFTradingGetPlayerTradesResponseWrapper& src) :
        PFTradingGetPlayerTradesResponseWrapper{ src.Model() }
    {
    }

    PFTradingGetPlayerTradesResponseWrapper(PFTradingGetPlayerTradesResponseWrapper&& src) :
        PFTradingGetPlayerTradesResponseWrapper{}
    {
        swap(*this, src);
    }

    PFTradingGetPlayerTradesResponseWrapper& operator=(PFTradingGetPlayerTradesResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingGetPlayerTradesResponseWrapper() = default;

    friend void swap(PFTradingGetPlayerTradesResponseWrapper& lhs, PFTradingGetPlayerTradesResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_acceptedTrades, rhs.m_acceptedTrades);
        swap(lhs.m_openedTrades, rhs.m_openedTrades);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAcceptedTrades(ModelVector<PFTradingTradeInfoWrapper<Alloc>, Alloc> value)
    {
        m_acceptedTrades = std::move(value);
        this->m_model.acceptedTrades =  m_acceptedTrades.empty() ? nullptr : m_acceptedTrades.data();
        this->m_model.acceptedTradesCount =  static_cast<uint32_t>(m_acceptedTrades.size());
    }

    void SetOpenedTrades(ModelVector<PFTradingTradeInfoWrapper<Alloc>, Alloc> value)
    {
        m_openedTrades = std::move(value);
        this->m_model.openedTrades =  m_openedTrades.empty() ? nullptr : m_openedTrades.data();
        this->m_model.openedTradesCount =  static_cast<uint32_t>(m_openedTrades.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.acceptedTrades = m_acceptedTrades.empty() ? nullptr : m_acceptedTrades.data();
        this->m_model.openedTrades = m_openedTrades.empty() ? nullptr : m_openedTrades.data();
    }

    ModelVector<PFTradingTradeInfoWrapper<Alloc>, Alloc> m_acceptedTrades;
    ModelVector<PFTradingTradeInfoWrapper<Alloc>, Alloc> m_openedTrades;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingGetTradeStatusRequestWrapper : public ModelWrapper<PFTradingGetTradeStatusRequest, Alloc>
{
public:
    using ModelType = typename PFTradingGetTradeStatusRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingGetTradeStatusRequestWrapper() = default;

    PFTradingGetTradeStatusRequestWrapper(const PFTradingGetTradeStatusRequest& model) :
        ModelWrapper<PFTradingGetTradeStatusRequest, Alloc>{ model },
        m_offeringPlayerId{ SafeString(model.offeringPlayerId) },
        m_tradeId{ SafeString(model.tradeId) }
    {
        SetModelPointers();
    }

    PFTradingGetTradeStatusRequestWrapper(const PFTradingGetTradeStatusRequestWrapper& src) :
        PFTradingGetTradeStatusRequestWrapper{ src.Model() }
    {
    }

    PFTradingGetTradeStatusRequestWrapper(PFTradingGetTradeStatusRequestWrapper&& src) :
        PFTradingGetTradeStatusRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTradingGetTradeStatusRequestWrapper& operator=(PFTradingGetTradeStatusRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingGetTradeStatusRequestWrapper() = default;

    friend void swap(PFTradingGetTradeStatusRequestWrapper& lhs, PFTradingGetTradeStatusRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_offeringPlayerId, rhs.m_offeringPlayerId);
        swap(lhs.m_tradeId, rhs.m_tradeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOfferingPlayerId(String value)
    {
        m_offeringPlayerId = std::move(value);
        this->m_model.offeringPlayerId =  m_offeringPlayerId.empty() ? nullptr : m_offeringPlayerId.data();
    }

    void SetTradeId(String value)
    {
        m_tradeId = std::move(value);
        this->m_model.tradeId =  m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.offeringPlayerId = m_offeringPlayerId.empty() ? nullptr : m_offeringPlayerId.data();
        this->m_model.tradeId = m_tradeId.empty() ? nullptr : m_tradeId.data();
    }

    String m_offeringPlayerId;
    String m_tradeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingGetTradeStatusResponseWrapper : public ModelWrapper<PFTradingGetTradeStatusResponse, Alloc>
{
public:
    using ModelType = typename PFTradingGetTradeStatusResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingGetTradeStatusResponseWrapper() = default;

    PFTradingGetTradeStatusResponseWrapper(const PFTradingGetTradeStatusResponse& model) :
        ModelWrapper<PFTradingGetTradeStatusResponse, Alloc>{ model },
        m_trade{ model.trade ? StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>>{ *model.trade } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTradingGetTradeStatusResponseWrapper(const PFTradingGetTradeStatusResponseWrapper& src) :
        PFTradingGetTradeStatusResponseWrapper{ src.Model() }
    {
    }

    PFTradingGetTradeStatusResponseWrapper(PFTradingGetTradeStatusResponseWrapper&& src) :
        PFTradingGetTradeStatusResponseWrapper{}
    {
        swap(*this, src);
    }

    PFTradingGetTradeStatusResponseWrapper& operator=(PFTradingGetTradeStatusResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingGetTradeStatusResponseWrapper() = default;

    friend void swap(PFTradingGetTradeStatusResponseWrapper& lhs, PFTradingGetTradeStatusResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_trade, rhs.m_trade);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTrade(StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> value)
    {
        m_trade = std::move(value);
        this->m_model.trade = m_trade ? &m_trade->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.trade = m_trade ?  &m_trade->Model() : nullptr;
    }

    StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> m_trade;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingOpenTradeRequestWrapper : public ModelWrapper<PFTradingOpenTradeRequest, Alloc>
{
public:
    using ModelType = typename PFTradingOpenTradeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingOpenTradeRequestWrapper() = default;

    PFTradingOpenTradeRequestWrapper(const PFTradingOpenTradeRequest& model) :
        ModelWrapper<PFTradingOpenTradeRequest, Alloc>{ model },
        m_allowedPlayerIds{ model.allowedPlayerIds, model.allowedPlayerIds + model.allowedPlayerIdsCount },
        m_offeredInventoryInstanceIds{ model.offeredInventoryInstanceIds, model.offeredInventoryInstanceIds + model.offeredInventoryInstanceIdsCount },
        m_requestedCatalogItemIds{ model.requestedCatalogItemIds, model.requestedCatalogItemIds + model.requestedCatalogItemIdsCount }
    {
        SetModelPointers();
    }

    PFTradingOpenTradeRequestWrapper(const PFTradingOpenTradeRequestWrapper& src) :
        PFTradingOpenTradeRequestWrapper{ src.Model() }
    {
    }

    PFTradingOpenTradeRequestWrapper(PFTradingOpenTradeRequestWrapper&& src) :
        PFTradingOpenTradeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTradingOpenTradeRequestWrapper& operator=(PFTradingOpenTradeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingOpenTradeRequestWrapper() = default;

    friend void swap(PFTradingOpenTradeRequestWrapper& lhs, PFTradingOpenTradeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_allowedPlayerIds, rhs.m_allowedPlayerIds);
        swap(lhs.m_offeredInventoryInstanceIds, rhs.m_offeredInventoryInstanceIds);
        swap(lhs.m_requestedCatalogItemIds, rhs.m_requestedCatalogItemIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAllowedPlayerIds(CStringVector<Alloc> value)
    {
        m_allowedPlayerIds = std::move(value);
        this->m_model.allowedPlayerIds =  m_allowedPlayerIds.empty() ? nullptr : m_allowedPlayerIds.data();
        this->m_model.allowedPlayerIdsCount =  static_cast<uint32_t>(m_allowedPlayerIds.size());
    }

    void SetOfferedInventoryInstanceIds(CStringVector<Alloc> value)
    {
        m_offeredInventoryInstanceIds = std::move(value);
        this->m_model.offeredInventoryInstanceIds =  m_offeredInventoryInstanceIds.empty() ? nullptr : m_offeredInventoryInstanceIds.data();
        this->m_model.offeredInventoryInstanceIdsCount =  static_cast<uint32_t>(m_offeredInventoryInstanceIds.size());
    }

    void SetRequestedCatalogItemIds(CStringVector<Alloc> value)
    {
        m_requestedCatalogItemIds = std::move(value);
        this->m_model.requestedCatalogItemIds =  m_requestedCatalogItemIds.empty() ? nullptr : m_requestedCatalogItemIds.data();
        this->m_model.requestedCatalogItemIdsCount =  static_cast<uint32_t>(m_requestedCatalogItemIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.allowedPlayerIds = m_allowedPlayerIds.empty() ? nullptr : m_allowedPlayerIds.data();
        this->m_model.offeredInventoryInstanceIds = m_offeredInventoryInstanceIds.empty() ? nullptr : m_offeredInventoryInstanceIds.data();
        this->m_model.requestedCatalogItemIds = m_requestedCatalogItemIds.empty() ? nullptr : m_requestedCatalogItemIds.data();
    }

    CStringVector<Alloc> m_allowedPlayerIds;
    CStringVector<Alloc> m_offeredInventoryInstanceIds;
    CStringVector<Alloc> m_requestedCatalogItemIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTradingOpenTradeResponseWrapper : public ModelWrapper<PFTradingOpenTradeResponse, Alloc>
{
public:
    using ModelType = typename PFTradingOpenTradeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTradingOpenTradeResponseWrapper() = default;

    PFTradingOpenTradeResponseWrapper(const PFTradingOpenTradeResponse& model) :
        ModelWrapper<PFTradingOpenTradeResponse, Alloc>{ model },
        m_trade{ model.trade ? StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>>{ *model.trade } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTradingOpenTradeResponseWrapper(const PFTradingOpenTradeResponseWrapper& src) :
        PFTradingOpenTradeResponseWrapper{ src.Model() }
    {
    }

    PFTradingOpenTradeResponseWrapper(PFTradingOpenTradeResponseWrapper&& src) :
        PFTradingOpenTradeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFTradingOpenTradeResponseWrapper& operator=(PFTradingOpenTradeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTradingOpenTradeResponseWrapper() = default;

    friend void swap(PFTradingOpenTradeResponseWrapper& lhs, PFTradingOpenTradeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_trade, rhs.m_trade);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTrade(StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> value)
    {
        m_trade = std::move(value);
        this->m_model.trade = m_trade ? &m_trade->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.trade = m_trade ?  &m_trade->Model() : nullptr;
    }

    StdExtra::optional<PFTradingTradeInfoWrapper<Alloc>> m_trade;
};

} // namespace Wrappers
} // namespace PlayFab
