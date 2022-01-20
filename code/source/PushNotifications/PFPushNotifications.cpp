#include "stdafx.h"
#include <playfab/PFPushNotifications.h>
#include "PushNotifications.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::PushNotifications;

HRESULT PFPushNotificationsServerDeletePushNotificationTemplateAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFPushNotificationsDeletePushNotificationTemplateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PushNotificationsAPI::ServerDeletePushNotificationTemplate, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPushNotificationsServerSavePushNotificationTemplateAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFPushNotificationsSavePushNotificationTemplateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PushNotificationsAPI::ServerSavePushNotificationTemplate, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPushNotificationsServerSavePushNotificationTemplateGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPushNotificationsServerSavePushNotificationTemplateGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPushNotificationsSavePushNotificationTemplateResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPushNotificationsSavePushNotificationTemplateResult*>(buffer);

    return S_OK;
}

HRESULT PFPushNotificationsServerSendPushNotificationAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFPushNotificationsSendPushNotificationRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PushNotificationsAPI::ServerSendPushNotification, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPushNotificationsServerSendPushNotificationFromTemplateAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFPushNotificationsSendPushNotificationFromTemplateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PushNotificationsAPI::ServerSendPushNotificationFromTemplate, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

