#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct SavePushNotificationTemplateResultHolder : public XAsyncResult, public std::enable_shared_from_this<SavePushNotificationTemplateResultHolder>
{
    SavePushNotificationTemplateResultHolder() = default;
    SavePushNotificationTemplateResultHolder(const SavePushNotificationTemplateResultHolder&) = delete;
    SavePushNotificationTemplateResultHolder(SavePushNotificationTemplateResultHolder&&) = default;
    SavePushNotificationTemplateResultHolder& operator=(const SavePushNotificationTemplateResultHolder&) = delete;
    SavePushNotificationTemplateResultHolder& operator=(SavePushNotificationTemplateResultHolder&&) = default;
    ~SavePushNotificationTemplateResultHolder() = default;

    PFPushNotificationsSavePushNotificationTemplateResult* result{ nullptr };
};


}
