#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFPushNotificationsDataModelWrappers.h>
#include "AutoGenPushNotificationsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenPushNotificationsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPushNotificationsServerDeletePushNotificationTemplate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPushNotificationsServerSavePushNotificationTemplate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPushNotificationsServerSendPushNotification(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPushNotificationsServerSendPushNotificationFromTemplate(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogDeletePushNotificationTemplateRequest(PFPushNotificationsDeletePushNotificationTemplateRequest const* request, const char* testName);
    static void LogSavePushNotificationTemplateRequest(PFPushNotificationsSavePushNotificationTemplateRequest const* request, const char* testName);
    static HRESULT LogSavePushNotificationTemplateResult(PFPushNotificationsSavePushNotificationTemplateResult const* result);
    static void LogSendPushNotificationRequest(PFPushNotificationsSendPushNotificationRequest const* request, const char* testName);
    static void LogSendPushNotificationFromTemplateRequest(PFPushNotificationsSendPushNotificationFromTemplateRequest const* request, const char* testName);

    static void FillServerDeletePushNotificationTemplateRequest(PlayFab::Wrappers::PFPushNotificationsDeletePushNotificationTemplateRequestWrapper<>& request);

    static void FillServerSavePushNotificationTemplateRequest(PlayFab::Wrappers::PFPushNotificationsSavePushNotificationTemplateRequestWrapper<>& request);
    static HRESULT ValidateServerSavePushNotificationTemplateResponse(PFPushNotificationsSavePushNotificationTemplateResult* result);

    static void FillServerSendPushNotificationRequest(PlayFab::Wrappers::PFPushNotificationsSendPushNotificationRequestWrapper<>& request);

    static void FillServerSendPushNotificationFromTemplateRequest(PlayFab::Wrappers::PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper<>& request);

    struct PushNotificationsTestData
    {
        ~PushNotificationsTestData() = default;

    };

    static PushNotificationsTestData testData;

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
