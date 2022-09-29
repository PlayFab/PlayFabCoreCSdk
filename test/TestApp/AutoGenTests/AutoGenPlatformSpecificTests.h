#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFPlatformSpecificDataModelWrappers.h>
#include "AutoGenPlatformSpecificResultHolders.h"

namespace PlayFabUnit
{

class AutoGenPlatformSpecificTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientAndroidDevicePushNotificationRegistration(TestContext& testContext);
#endif

    void TestPlatformSpecificClientConsumeMicrosoftStoreEntitlements(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientConsumePS5Entitlements(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientConsumePSNEntitlements(TestContext& testContext);
#endif

    void TestPlatformSpecificClientConsumeXboxEntitlements(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientRefreshPSNAuthToken(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientRegisterForIOSPushNotification(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientRestoreIOSPurchases(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientValidateAmazonIAPReceipt(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientValidateGooglePlayPurchase(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificClientValidateIOSReceipt(TestContext& testContext);
#endif

    void TestPlatformSpecificClientValidateWindowsStoreReceipt(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlatformSpecificServerAwardSteamAchievement(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogAndroidDevicePushNotificationRegistrationRequest(PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest const* request, const char* testName);
    static void LogConsumeMicrosoftStoreEntitlementsRequest(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest const* request, const char* testName);
    static HRESULT LogConsumeMicrosoftStoreEntitlementsResponse(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse const* result);
    static void LogConsumePS5EntitlementsRequest(PFPlatformSpecificConsumePS5EntitlementsRequest const* request, const char* testName);
    static HRESULT LogConsumePS5EntitlementsResult(PFPlatformSpecificConsumePS5EntitlementsResult const* result);
    static void LogConsumePSNEntitlementsRequest(PFPlatformSpecificConsumePSNEntitlementsRequest const* request, const char* testName);
    static HRESULT LogConsumePSNEntitlementsResult(PFPlatformSpecificConsumePSNEntitlementsResult const* result);
    static void LogConsumeXboxEntitlementsRequest(PFPlatformSpecificConsumeXboxEntitlementsRequest const* request, const char* testName);
    static HRESULT LogConsumeXboxEntitlementsResult(PFPlatformSpecificConsumeXboxEntitlementsResult const* result);
    static void LogRefreshPSNAuthTokenRequest(PFPlatformSpecificRefreshPSNAuthTokenRequest const* request, const char* testName);
    static void LogRegisterForIOSPushNotificationRequest(PFPlatformSpecificRegisterForIOSPushNotificationRequest const* request, const char* testName);
    static void LogRestoreIOSPurchasesRequest(PFPlatformSpecificRestoreIOSPurchasesRequest const* request, const char* testName);
    static HRESULT LogRestoreIOSPurchasesResult(PFPlatformSpecificRestoreIOSPurchasesResult const* result);
    static void LogValidateAmazonReceiptRequest(PFPlatformSpecificValidateAmazonReceiptRequest const* request, const char* testName);
    static HRESULT LogValidateAmazonReceiptResult(PFPlatformSpecificValidateAmazonReceiptResult const* result);
    static void LogValidateGooglePlayPurchaseRequest(PFPlatformSpecificValidateGooglePlayPurchaseRequest const* request, const char* testName);
    static HRESULT LogValidateGooglePlayPurchaseResult(PFPlatformSpecificValidateGooglePlayPurchaseResult const* result);
    static void LogValidateIOSReceiptRequest(PFPlatformSpecificValidateIOSReceiptRequest const* request, const char* testName);
    static HRESULT LogValidateIOSReceiptResult(PFPlatformSpecificValidateIOSReceiptResult const* result);
    static void LogValidateWindowsReceiptRequest(PFPlatformSpecificValidateWindowsReceiptRequest const* request, const char* testName);
    static HRESULT LogValidateWindowsReceiptResult(PFPlatformSpecificValidateWindowsReceiptResult const* result);
    static void LogAwardSteamAchievementRequest(PFPlatformSpecificAwardSteamAchievementRequest const* request, const char* testName);
    static HRESULT LogAwardSteamAchievementResult(PFPlatformSpecificAwardSteamAchievementResult const* result);

    void FillClientAndroidDevicePushNotificationRegistrationRequest(PlayFab::Wrappers::PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper<>& request);

    void FillClientConsumeMicrosoftStoreEntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper<>& request);
    static HRESULT ValidateClientConsumeMicrosoftStoreEntitlementsResponse(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse* result);

    void FillClientConsumePS5EntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumePS5EntitlementsRequestWrapper<>& request);
    static HRESULT ValidateClientConsumePS5EntitlementsResponse(PFPlatformSpecificConsumePS5EntitlementsResult* result);

    void FillClientConsumePSNEntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumePSNEntitlementsRequestWrapper<>& request);
    static HRESULT ValidateClientConsumePSNEntitlementsResponse(PFPlatformSpecificConsumePSNEntitlementsResult* result);

    void FillClientConsumeXboxEntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper<>& request);
    static HRESULT ValidateClientConsumeXboxEntitlementsResponse(PFPlatformSpecificConsumeXboxEntitlementsResult* result);

    void FillClientRefreshPSNAuthTokenRequest(PlayFab::Wrappers::PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper<>& request);

    void FillClientRegisterForIOSPushNotificationRequest(PlayFab::Wrappers::PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper<>& request);

    void FillClientRestoreIOSPurchasesRequest(PlayFab::Wrappers::PFPlatformSpecificRestoreIOSPurchasesRequestWrapper<>& request);
    static HRESULT ValidateClientRestoreIOSPurchasesResponse(PFPlatformSpecificRestoreIOSPurchasesResult* result);

    void FillClientValidateAmazonIAPReceiptRequest(PlayFab::Wrappers::PFPlatformSpecificValidateAmazonReceiptRequestWrapper<>& request);
    static HRESULT ValidateClientValidateAmazonIAPReceiptResponse(PFPlatformSpecificValidateAmazonReceiptResult* result);

    void FillClientValidateGooglePlayPurchaseRequest(PlayFab::Wrappers::PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper<>& request);
    static HRESULT ValidateClientValidateGooglePlayPurchaseResponse(PFPlatformSpecificValidateGooglePlayPurchaseResult* result);

    void FillClientValidateIOSReceiptRequest(PlayFab::Wrappers::PFPlatformSpecificValidateIOSReceiptRequestWrapper<>& request);
    static HRESULT ValidateClientValidateIOSReceiptResponse(PFPlatformSpecificValidateIOSReceiptResult* result);

    void FillClientValidateWindowsStoreReceiptRequest(PlayFab::Wrappers::PFPlatformSpecificValidateWindowsReceiptRequestWrapper<>& request);
    static HRESULT ValidateClientValidateWindowsStoreReceiptResponse(PFPlatformSpecificValidateWindowsReceiptResult* result);

    void FillServerAwardSteamAchievementRequest(PlayFab::Wrappers::PFPlatformSpecificAwardSteamAchievementRequestWrapper<>& request);
    static HRESULT ValidateServerAwardSteamAchievementResponse(PFPlatformSpecificAwardSteamAchievementResult* result);

    struct PlatformSpecificTestData
    {
        ~PlatformSpecificTestData() = default;

    };

    static PlatformSpecificTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
