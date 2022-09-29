#pragma once

#include "PushNotificationsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace PushNotifications
{

class PushNotificationsAPI
{
public:
    PushNotificationsAPI() = delete;
    PushNotificationsAPI(const PushNotificationsAPI& source) = delete;
    PushNotificationsAPI& operator=(const PushNotificationsAPI& source) = delete;
    ~PushNotificationsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> ServerDeletePushNotificationTemplate(SharedPtr<GlobalState const> state, const DeletePushNotificationTemplateRequest& request, const TaskQueue& queue);
    static AsyncOp<SavePushNotificationTemplateResult> ServerSavePushNotificationTemplate(SharedPtr<GlobalState const> state, const SavePushNotificationTemplateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSendPushNotification(SharedPtr<GlobalState const> state, const SendPushNotificationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSendPushNotificationFromTemplate(SharedPtr<GlobalState const> state, const SendPushNotificationFromTemplateRequest& request, const TaskQueue& queue);
};

} // namespace PushNotifications
} // namespace PlayFab
