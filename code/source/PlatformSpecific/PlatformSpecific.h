#pragma once

#include "PlatformSpecificDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace PlatformSpecific
{

class PlatformSpecificAPI
{
public:
    PlatformSpecificAPI() = delete;
    PlatformSpecificAPI(const PlatformSpecificAPI& source) = delete;
    PlatformSpecificAPI& operator=(const PlatformSpecificAPI& source) = delete;
    ~PlatformSpecificAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> ClientAndroidDevicePushNotificationRegistration(SharedPtr<TitlePlayer> entity, const AndroidDevicePushNotificationRegistrationRequest& request, const TaskQueue& queue);
    static AsyncOp<ConsumeMicrosoftStoreEntitlementsResponse> ClientConsumeMicrosoftStoreEntitlements(SharedPtr<TitlePlayer> entity, const ConsumeMicrosoftStoreEntitlementsRequest& request, const TaskQueue& queue);
    static AsyncOp<ConsumePS5EntitlementsResult> ClientConsumePS5Entitlements(SharedPtr<TitlePlayer> entity, const ConsumePS5EntitlementsRequest& request, const TaskQueue& queue);
    static AsyncOp<ConsumePSNEntitlementsResult> ClientConsumePSNEntitlements(SharedPtr<TitlePlayer> entity, const ConsumePSNEntitlementsRequest& request, const TaskQueue& queue);
    static AsyncOp<ConsumeXboxEntitlementsResult> ClientConsumeXboxEntitlements(SharedPtr<TitlePlayer> entity, const ConsumeXboxEntitlementsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientRefreshPSNAuthToken(SharedPtr<TitlePlayer> entity, const RefreshPSNAuthTokenRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientRegisterForIOSPushNotification(SharedPtr<TitlePlayer> entity, const RegisterForIOSPushNotificationRequest& request, const TaskQueue& queue);
    static AsyncOp<RestoreIOSPurchasesResult> ClientRestoreIOSPurchases(SharedPtr<TitlePlayer> entity, const RestoreIOSPurchasesRequest& request, const TaskQueue& queue);
    static AsyncOp<ValidateAmazonReceiptResult> ClientValidateAmazonIAPReceipt(SharedPtr<TitlePlayer> entity, const ValidateAmazonReceiptRequest& request, const TaskQueue& queue);
    static AsyncOp<ValidateGooglePlayPurchaseResult> ClientValidateGooglePlayPurchase(SharedPtr<TitlePlayer> entity, const ValidateGooglePlayPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<ValidateIOSReceiptResult> ClientValidateIOSReceipt(SharedPtr<TitlePlayer> entity, const ValidateIOSReceiptRequest& request, const TaskQueue& queue);
    static AsyncOp<ValidateWindowsReceiptResult> ClientValidateWindowsStoreReceipt(SharedPtr<TitlePlayer> entity, const ValidateWindowsReceiptRequest& request, const TaskQueue& queue);
    static AsyncOp<AwardSteamAchievementResult> ServerAwardSteamAchievement(SharedPtr<GlobalState const> state, const AwardSteamAchievementRequest& request, const TaskQueue& queue);
};

} // namespace PlatformSpecific
} // namespace PlayFab
