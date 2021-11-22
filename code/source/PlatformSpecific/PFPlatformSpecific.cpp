#include "stdafx.h"
#include <playfab/PFPlatformSpecific.h>
#include "PlatformSpecific.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::PlatformSpecific;

HRESULT PFPlatformSpecificClientAndroidDevicePushNotificationRegistrationAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientAndroidDevicePushNotificationRegistration, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientConsumeMicrosoftStoreEntitlementsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientConsumeMicrosoftStoreEntitlements, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientConsumeMicrosoftStoreEntitlementsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientConsumeMicrosoftStoreEntitlementsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientConsumePS5EntitlementsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificConsumePS5EntitlementsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientConsumePS5Entitlements, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientConsumePS5EntitlementsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientConsumePS5EntitlementsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificConsumePS5EntitlementsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificConsumePS5EntitlementsResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientConsumePSNEntitlementsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificConsumePSNEntitlementsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientConsumePSNEntitlements, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientConsumePSNEntitlementsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientConsumePSNEntitlementsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificConsumePSNEntitlementsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificConsumePSNEntitlementsResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientConsumeXboxEntitlementsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificConsumeXboxEntitlementsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientConsumeXboxEntitlements, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientConsumeXboxEntitlementsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientConsumeXboxEntitlementsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificConsumeXboxEntitlementsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificConsumeXboxEntitlementsResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientRefreshPSNAuthTokenAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificRefreshPSNAuthTokenRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientRefreshPSNAuthToken, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientRegisterForIOSPushNotificationAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificRegisterForIOSPushNotificationRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientRegisterForIOSPushNotification, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientRestoreIOSPurchasesAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificRestoreIOSPurchasesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientRestoreIOSPurchases, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientRestoreIOSPurchasesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientRestoreIOSPurchasesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificRestoreIOSPurchasesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificRestoreIOSPurchasesResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientValidateAmazonIAPReceiptAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificValidateAmazonReceiptRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientValidateAmazonIAPReceipt, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientValidateAmazonIAPReceiptGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientValidateAmazonIAPReceiptGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificValidateAmazonReceiptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificValidateAmazonReceiptResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientValidateGooglePlayPurchaseAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificValidateGooglePlayPurchaseRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientValidateGooglePlayPurchase, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientValidateGooglePlayPurchaseGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientValidateGooglePlayPurchaseGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificValidateGooglePlayPurchaseResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificValidateGooglePlayPurchaseResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientValidateIOSReceiptAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificValidateIOSReceiptRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientValidateIOSReceipt, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientValidateIOSReceiptGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientValidateIOSReceiptGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificValidateIOSReceiptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificValidateIOSReceiptResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificClientValidateWindowsStoreReceiptAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFPlatformSpecificValidateWindowsReceiptRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ClientValidateWindowsStoreReceipt, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificClientValidateWindowsStoreReceiptGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificClientValidateWindowsStoreReceiptGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificValidateWindowsReceiptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificValidateWindowsReceiptResult*>(buffer);

    return S_OK;
}

HRESULT PFPlatformSpecificServerAwardSteamAchievementAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFPlatformSpecificAwardSteamAchievementRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&PlatformSpecificAPI::ServerAwardSteamAchievement, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFPlatformSpecificServerAwardSteamAchievementGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFPlatformSpecificServerAwardSteamAchievementGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlatformSpecificAwardSteamAchievementResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFPlatformSpecificAwardSteamAchievementResult*>(buffer);

    return S_OK;
}

