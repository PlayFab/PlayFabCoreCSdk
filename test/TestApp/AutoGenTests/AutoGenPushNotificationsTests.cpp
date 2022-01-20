#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPushNotificationsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenPushNotificationsTests::PushNotificationsTestData AutoGenPushNotificationsTests::testData;

void AutoGenPushNotificationsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenPushNotificationsTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPushNotificationsTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPushNotificationsServerDeletePushNotificationTemplate", &AutoGenPushNotificationsTests::TestPushNotificationsServerDeletePushNotificationTemplate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPushNotificationsServerSavePushNotificationTemplate", &AutoGenPushNotificationsTests::TestPushNotificationsServerSavePushNotificationTemplate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPushNotificationsServerSendPushNotification", &AutoGenPushNotificationsTests::TestPushNotificationsServerSendPushNotification);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPushNotificationsServerSendPushNotificationFromTemplate", &AutoGenPushNotificationsTests::TestPushNotificationsServerSendPushNotificationFromTemplate);
#endif
}

void AutoGenPushNotificationsTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), testTitleData.connectionString.data(), nullptr, &stateHandle);
    assert(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        PFAuthenticationLoginWithCustomIDRequest request{};
        request.customId = "CustomId";
        request.createAccount = true;

        PFGetPlayerCombinedInfoRequestParams combinedInfoRequestParams{};
        combinedInfoRequestParams.getCharacterInventories = true;
        combinedInfoRequestParams.getCharacterList = true;
        combinedInfoRequestParams.getPlayerProfile = true;
        combinedInfoRequestParams.getPlayerStatistics = true;
        combinedInfoRequestParams.getTitleData = true;
        combinedInfoRequestParams.getUserAccountInfo = true;
        combinedInfoRequestParams.getUserData = true;
        combinedInfoRequestParams.getUserInventory = true;
        combinedInfoRequestParams.getUserReadOnlyData = true;
        combinedInfoRequestParams.getUserVirtualCurrency = true;
        request.infoRequestParameters = &combinedInfoRequestParams;

        XAsyncBlock async{};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle);
                assert(SUCCEEDED(hr) && titlePlayerHandle);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle, &entityHandle);
                assert(SUCCEEDED(hr) && entityHandle);
            }
        }

        request.customId = "CustomId2";
        async = {};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously what for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle2);
                assert(SUCCEEDED(hr) && titlePlayerHandle2);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle2, &entityHandle2);
                assert(SUCCEEDED(hr) && entityHandle2);
            }
        }

        PFAuthenticationGetEntityTokenRequest titleTokenRequest{};
        async = {};
        hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &titleTokenRequest, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationGetEntityTokenGetResult(&async, &titleEntityHandle);
                assert(SUCCEEDED(hr));
            }
        }
    }
}

void AutoGenPushNotificationsTests::ClassTearDown()
{
    PFTitlePlayerCloseHandle(titlePlayerHandle);
    PFEntityCloseHandle(entityHandle);
    PFEntityCloseHandle(titleEntityHandle);

    XAsyncBlock async{};
    HRESULT hr = PFUninitializeAsync(stateHandle, &async);
    assert(SUCCEEDED(hr));

    hr = XAsyncGetStatus(&async, true);
    assert(SUCCEEDED(hr));

    UNREFERENCED_PARAMETER(hr);
}

void AutoGenPushNotificationsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ServerDeletePushNotificationTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPushNotificationsTests::TestPushNotificationsServerDeletePushNotificationTemplate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPushNotificationsDeletePushNotificationTemplateRequestWrapper<> request;
    FillServerDeletePushNotificationTemplateRequest(request);
    LogDeletePushNotificationTemplateRequest(&request.Model(), "TestPushNotificationsServerDeletePushNotificationTemplate");
    HRESULT hr = PFPushNotificationsServerDeletePushNotificationTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPushNotificationsPushNotificationsServerDeletePushNotificationTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSavePushNotificationTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPushNotificationsTests::TestPushNotificationsServerSavePushNotificationTemplate(TestContext& testContext)
{
    struct ServerSavePushNotificationTemplateResultHolderStruct : public SavePushNotificationTemplateResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPushNotificationsServerSavePushNotificationTemplateGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPushNotificationsServerSavePushNotificationTemplateGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogSavePushNotificationTemplateResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerSavePushNotificationTemplateResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSavePushNotificationTemplateResultHolderStruct>>(testContext);

    PFPushNotificationsSavePushNotificationTemplateRequestWrapper<> request;
    FillServerSavePushNotificationTemplateRequest(request);
    LogSavePushNotificationTemplateRequest(&request.Model(), "TestPushNotificationsServerSavePushNotificationTemplate");
    HRESULT hr = PFPushNotificationsServerSavePushNotificationTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPushNotificationsPushNotificationsServerSavePushNotificationTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSendPushNotification

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPushNotificationsTests::TestPushNotificationsServerSendPushNotification(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPushNotificationsSendPushNotificationRequestWrapper<> request;
    FillServerSendPushNotificationRequest(request);
    LogSendPushNotificationRequest(&request.Model(), "TestPushNotificationsServerSendPushNotification");
    HRESULT hr = PFPushNotificationsServerSendPushNotificationAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPushNotificationsPushNotificationsServerSendPushNotificationAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSendPushNotificationFromTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPushNotificationsTests::TestPushNotificationsServerSendPushNotificationFromTemplate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper<> request;
    FillServerSendPushNotificationFromTemplateRequest(request);
    LogSendPushNotificationFromTemplateRequest(&request.Model(), "TestPushNotificationsServerSendPushNotificationFromTemplate");
    HRESULT hr = PFPushNotificationsServerSendPushNotificationFromTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPushNotificationsPushNotificationsServerSendPushNotificationFromTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
