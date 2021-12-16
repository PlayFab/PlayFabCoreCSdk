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
    static void FillAndroidDevicePushNotificationRegistrationRequest(PlayFab::Wrappers::PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper<>& request);

    static void LogConsumeMicrosoftStoreEntitlementsRequest(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest const* request, const char* testName);
    static void FillConsumeMicrosoftStoreEntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse const* result);
    static HRESULT ValidatePFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse* result);

    static void LogConsumePS5EntitlementsRequest(PFPlatformSpecificConsumePS5EntitlementsRequest const* request, const char* testName);
    static void FillConsumePS5EntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumePS5EntitlementsRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificConsumePS5EntitlementsResult(PFPlatformSpecificConsumePS5EntitlementsResult const* result);
    static HRESULT ValidatePFPlatformSpecificConsumePS5EntitlementsResult(PFPlatformSpecificConsumePS5EntitlementsResult* result);

    static void LogConsumePSNEntitlementsRequest(PFPlatformSpecificConsumePSNEntitlementsRequest const* request, const char* testName);
    static void FillConsumePSNEntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumePSNEntitlementsRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificConsumePSNEntitlementsResult(PFPlatformSpecificConsumePSNEntitlementsResult const* result);
    static HRESULT ValidatePFPlatformSpecificConsumePSNEntitlementsResult(PFPlatformSpecificConsumePSNEntitlementsResult* result);

    static void LogConsumeXboxEntitlementsRequest(PFPlatformSpecificConsumeXboxEntitlementsRequest const* request, const char* testName);
    static void FillConsumeXboxEntitlementsRequest(PlayFab::Wrappers::PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificConsumeXboxEntitlementsResult(PFPlatformSpecificConsumeXboxEntitlementsResult const* result);
    static HRESULT ValidatePFPlatformSpecificConsumeXboxEntitlementsResult(PFPlatformSpecificConsumeXboxEntitlementsResult* result);

    static void LogRefreshPSNAuthTokenRequest(PFPlatformSpecificRefreshPSNAuthTokenRequest const* request, const char* testName);
    static void FillRefreshPSNAuthTokenRequest(PlayFab::Wrappers::PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper<>& request);

    static void LogRegisterForIOSPushNotificationRequest(PFPlatformSpecificRegisterForIOSPushNotificationRequest const* request, const char* testName);
    static void FillRegisterForIOSPushNotificationRequest(PlayFab::Wrappers::PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper<>& request);

    static void LogRestoreIOSPurchasesRequest(PFPlatformSpecificRestoreIOSPurchasesRequest const* request, const char* testName);
    static void FillRestoreIOSPurchasesRequest(PlayFab::Wrappers::PFPlatformSpecificRestoreIOSPurchasesRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificRestoreIOSPurchasesResult(PFPlatformSpecificRestoreIOSPurchasesResult const* result);
    static HRESULT ValidatePFPlatformSpecificRestoreIOSPurchasesResult(PFPlatformSpecificRestoreIOSPurchasesResult* result);

    static void LogValidateAmazonReceiptRequest(PFPlatformSpecificValidateAmazonReceiptRequest const* request, const char* testName);
    static void FillValidateAmazonReceiptRequest(PlayFab::Wrappers::PFPlatformSpecificValidateAmazonReceiptRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificValidateAmazonReceiptResult(PFPlatformSpecificValidateAmazonReceiptResult const* result);
    static HRESULT ValidatePFPlatformSpecificValidateAmazonReceiptResult(PFPlatformSpecificValidateAmazonReceiptResult* result);

    static void LogValidateGooglePlayPurchaseRequest(PFPlatformSpecificValidateGooglePlayPurchaseRequest const* request, const char* testName);
    static void FillValidateGooglePlayPurchaseRequest(PlayFab::Wrappers::PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificValidateGooglePlayPurchaseResult(PFPlatformSpecificValidateGooglePlayPurchaseResult const* result);
    static HRESULT ValidatePFPlatformSpecificValidateGooglePlayPurchaseResult(PFPlatformSpecificValidateGooglePlayPurchaseResult* result);

    static void LogValidateIOSReceiptRequest(PFPlatformSpecificValidateIOSReceiptRequest const* request, const char* testName);
    static void FillValidateIOSReceiptRequest(PlayFab::Wrappers::PFPlatformSpecificValidateIOSReceiptRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificValidateIOSReceiptResult(PFPlatformSpecificValidateIOSReceiptResult const* result);
    static HRESULT ValidatePFPlatformSpecificValidateIOSReceiptResult(PFPlatformSpecificValidateIOSReceiptResult* result);

    static void LogValidateWindowsReceiptRequest(PFPlatformSpecificValidateWindowsReceiptRequest const* request, const char* testName);
    static void FillValidateWindowsReceiptRequest(PlayFab::Wrappers::PFPlatformSpecificValidateWindowsReceiptRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificValidateWindowsReceiptResult(PFPlatformSpecificValidateWindowsReceiptResult const* result);
    static HRESULT ValidatePFPlatformSpecificValidateWindowsReceiptResult(PFPlatformSpecificValidateWindowsReceiptResult* result);

    static void LogAwardSteamAchievementRequest(PFPlatformSpecificAwardSteamAchievementRequest const* request, const char* testName);
    static void FillAwardSteamAchievementRequest(PlayFab::Wrappers::PFPlatformSpecificAwardSteamAchievementRequestWrapper<>& request);
    static HRESULT LogPFPlatformSpecificAwardSteamAchievementResult(PFPlatformSpecificAwardSteamAchievementResult const* result);
    static HRESULT ValidatePFPlatformSpecificAwardSteamAchievementResult(PFPlatformSpecificAwardSteamAchievementResult* result);

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
