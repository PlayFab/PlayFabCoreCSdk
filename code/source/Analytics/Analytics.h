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
    static AsyncOp<WriteEventResponse> ClientWriteCharacterEvent(SharedPtr<TitlePlayer> entity, const WriteClientCharacterEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ClientWritePlayerEvent(SharedPtr<TitlePlayer> entity, const WriteClientPlayerEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ClientWriteTitleEvent(SharedPtr<TitlePlayer> entity, const WriteTitleEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ServerWriteCharacterEvent(SharedPtr<GlobalState const> state, const WriteServerCharacterEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ServerWritePlayerEvent(SharedPtr<GlobalState const> state, const WriteServerPlayerEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ServerWriteTitleEvent(SharedPtr<GlobalState const> state, const WriteTitleEventRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetDetailsResponse> GetDetails(SharedPtr<Entity> entity, const InsightsEmptyRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetLimitsResponse> GetLimits(SharedPtr<Entity> entity, const InsightsEmptyRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetOperationStatusResponse> GetOperationStatus(SharedPtr<Entity> entity, const InsightsGetOperationStatusRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsGetPendingOperationsResponse> GetPendingOperations(SharedPtr<Entity> entity, const InsightsGetPendingOperationsRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsOperationResponse> SetPerformance(SharedPtr<Entity> entity, const InsightsSetPerformanceRequest& request, const TaskQueue& queue);
    static AsyncOp<InsightsOperationResponse> SetStorageRetention(SharedPtr<Entity> entity, const InsightsSetStorageRetentionRequest& request, const TaskQueue& queue);
};

} // namespace Analytics
} // namespace PlayFab
