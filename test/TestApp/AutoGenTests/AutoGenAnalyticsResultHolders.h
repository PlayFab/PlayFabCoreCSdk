#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct InsightsGetDetailsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InsightsGetDetailsResponseHolder>
{
    InsightsGetDetailsResponseHolder() = default;
    InsightsGetDetailsResponseHolder(const InsightsGetDetailsResponseHolder&) = delete;
    InsightsGetDetailsResponseHolder(InsightsGetDetailsResponseHolder&&) = default;
    InsightsGetDetailsResponseHolder& operator=(const InsightsGetDetailsResponseHolder&) = delete;
    InsightsGetDetailsResponseHolder& operator=(InsightsGetDetailsResponseHolder&&) = default;
    ~InsightsGetDetailsResponseHolder() = default;

    PFAnalyticsInsightsGetDetailsResponse* result{ nullptr };
};

struct InsightsGetLimitsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InsightsGetLimitsResponseHolder>
{
    InsightsGetLimitsResponseHolder() = default;
    InsightsGetLimitsResponseHolder(const InsightsGetLimitsResponseHolder&) = delete;
    InsightsGetLimitsResponseHolder(InsightsGetLimitsResponseHolder&&) = default;
    InsightsGetLimitsResponseHolder& operator=(const InsightsGetLimitsResponseHolder&) = delete;
    InsightsGetLimitsResponseHolder& operator=(InsightsGetLimitsResponseHolder&&) = default;
    ~InsightsGetLimitsResponseHolder() = default;

    PFAnalyticsInsightsGetLimitsResponse* result{ nullptr };
};

struct InsightsGetOperationStatusResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InsightsGetOperationStatusResponseHolder>
{
    InsightsGetOperationStatusResponseHolder() = default;
    InsightsGetOperationStatusResponseHolder(const InsightsGetOperationStatusResponseHolder&) = delete;
    InsightsGetOperationStatusResponseHolder(InsightsGetOperationStatusResponseHolder&&) = default;
    InsightsGetOperationStatusResponseHolder& operator=(const InsightsGetOperationStatusResponseHolder&) = delete;
    InsightsGetOperationStatusResponseHolder& operator=(InsightsGetOperationStatusResponseHolder&&) = default;
    ~InsightsGetOperationStatusResponseHolder() = default;

    PFAnalyticsInsightsGetOperationStatusResponse* result{ nullptr };
};

struct InsightsGetPendingOperationsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InsightsGetPendingOperationsResponseHolder>
{
    InsightsGetPendingOperationsResponseHolder() = default;
    InsightsGetPendingOperationsResponseHolder(const InsightsGetPendingOperationsResponseHolder&) = delete;
    InsightsGetPendingOperationsResponseHolder(InsightsGetPendingOperationsResponseHolder&&) = default;
    InsightsGetPendingOperationsResponseHolder& operator=(const InsightsGetPendingOperationsResponseHolder&) = delete;
    InsightsGetPendingOperationsResponseHolder& operator=(InsightsGetPendingOperationsResponseHolder&&) = default;
    ~InsightsGetPendingOperationsResponseHolder() = default;

    PFAnalyticsInsightsGetPendingOperationsResponse* result{ nullptr };
};

struct InsightsOperationResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InsightsOperationResponseHolder>
{
    InsightsOperationResponseHolder() = default;
    InsightsOperationResponseHolder(const InsightsOperationResponseHolder&) = delete;
    InsightsOperationResponseHolder(InsightsOperationResponseHolder&&) = default;
    InsightsOperationResponseHolder& operator=(const InsightsOperationResponseHolder&) = delete;
    InsightsOperationResponseHolder& operator=(InsightsOperationResponseHolder&&) = default;
    ~InsightsOperationResponseHolder() = default;

    PFAnalyticsInsightsOperationResponse* result{ nullptr };
};


}
