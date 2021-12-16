#pragma once

#include "AnalyticsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Analytics
{

class AnalyticsAPI
{
public:
    AnalyticsAPI() = delete;
    AnalyticsAPI(const AnalyticsAPI& source) = delete;
    AnalyticsAPI& operator=(const AnalyticsAPI& source) = delete;
    ~AnalyticsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> ClientReportDeviceInfo(SharedPtr<TitlePlayer> entity, const DeviceInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetDetailsResponse> GetDetails(SharedPtr<Entity> entity, const InsightsEmptyRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetLimitsResponse> GetLimits(SharedPtr<Entity> entity, const InsightsEmptyRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetOperationStatusResponse> GetOperationStatus(SharedPtr<Entity> entity, const InsightsGetOperationStatusRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetPendingOperationsResponse> GetPendingOperations(SharedPtr<Entity> entity, const InsightsGetPendingOperationsRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsOperationResponse> SetPerformance(SharedPtr<Entity> entity, const InsightsSetPerformanceRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsOperationResponse> SetStorageRetention(SharedPtr<Entity> entity, const InsightsSetStorageRetentionRequest& request, const TaskQueue& queue);
};

} // namespace Analytics
} // namespace PlayFab
