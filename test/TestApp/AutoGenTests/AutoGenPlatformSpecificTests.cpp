#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlatformSpecificTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenPlatformSpecificTests::PlatformSpecificTestData AutoGenPlatformSpecificTests::testData;

void AutoGenPlatformSpecificTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenPlatformSpecificTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPlatformSpecificTests::AddTests()
{
    // Generated tests 
    AddTest("TestPlatformSpecificClientAndroidDevicePushNotificationRegistration", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientAndroidDevicePushNotificationRegistration);

    AddTest("TestPlatformSpecificClientConsumeMicrosoftStoreEntitlements", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumeMicrosoftStoreEntitlements);

    AddTest("TestPlatformSpecificClientConsumePS5Entitlements", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumePS5Entitlements);

    AddTest("TestPlatformSpecificClientConsumePSNEntitlements", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumePSNEntitlements);

    AddTest("TestPlatformSpecificClientConsumeXboxEntitlements", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumeXboxEntitlements);

    AddTest("TestPlatformSpecificClientRefreshPSNAuthToken", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientRefreshPSNAuthToken);

    AddTest("TestPlatformSpecificClientRegisterForIOSPushNotification", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientRegisterForIOSPushNotification);

    AddTest("TestPlatformSpecificClientRestoreIOSPurchases", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientRestoreIOSPurchases);

    AddTest("TestPlatformSpecificClientValidateAmazonIAPReceipt", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateAmazonIAPReceipt);

    AddTest("TestPlatformSpecificClientValidateGooglePlayPurchase", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateGooglePlayPurchase);

    AddTest("TestPlatformSpecificClientValidateIOSReceipt", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateIOSReceipt);

    AddTest("TestPlatformSpecificClientValidateWindowsStoreReceipt", &AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateWindowsStoreReceipt);

    AddTest("TestPlatformSpecificServerAwardSteamAchievement", &AutoGenPlatformSpecificTests::TestPlatformSpecificServerAwardSteamAchievement);
}

void AutoGenPlatformSpecificTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), nullptr, &stateHandle);
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

void AutoGenPlatformSpecificTests::ClassTearDown()
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

void AutoGenPlatformSpecificTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ClientAndroidDevicePushNotificationRegistration

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientAndroidDevicePushNotificationRegistration(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper<> request;
    FillAndroidDevicePushNotificationRegistrationRequest(request);
    LogAndroidDevicePushNotificationRegistrationRequest(&request.Model(), "TestPlatformSpecificClientAndroidDevicePushNotificationRegistration");
    HRESULT hr = PFPlatformSpecificClientAndroidDevicePushNotificationRegistrationAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientAndroidDevicePushNotificationRegistrationAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientConsumeMicrosoftStoreEntitlements

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumeMicrosoftStoreEntitlements(TestContext& testContext)
{
    struct ClientConsumeMicrosoftStoreEntitlementsResultHolder : public ConsumeMicrosoftStoreEntitlementsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumeMicrosoftStoreEntitlementsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumeMicrosoftStoreEntitlementsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConsumeMicrosoftStoreEntitlementsResultHolder>>(testContext);

    PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper<> request;
    FillConsumeMicrosoftStoreEntitlementsRequest(request);
    LogConsumeMicrosoftStoreEntitlementsRequest(&request.Model(), "TestPlatformSpecificClientConsumeMicrosoftStoreEntitlements");
    HRESULT hr = PFPlatformSpecificClientConsumeMicrosoftStoreEntitlementsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientConsumeMicrosoftStoreEntitlementsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientConsumePS5Entitlements

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumePS5Entitlements(TestContext& testContext)
{
    struct ClientConsumePS5EntitlementsResultHolder : public ConsumePS5EntitlementsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumePS5EntitlementsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumePS5EntitlementsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificConsumePS5EntitlementsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificConsumePS5EntitlementsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConsumePS5EntitlementsResultHolder>>(testContext);

    PFPlatformSpecificConsumePS5EntitlementsRequestWrapper<> request;
    FillConsumePS5EntitlementsRequest(request);
    LogConsumePS5EntitlementsRequest(&request.Model(), "TestPlatformSpecificClientConsumePS5Entitlements");
    HRESULT hr = PFPlatformSpecificClientConsumePS5EntitlementsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientConsumePS5EntitlementsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientConsumePSNEntitlements

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumePSNEntitlements(TestContext& testContext)
{
    struct ClientConsumePSNEntitlementsResultHolder : public ConsumePSNEntitlementsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumePSNEntitlementsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumePSNEntitlementsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificConsumePSNEntitlementsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificConsumePSNEntitlementsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConsumePSNEntitlementsResultHolder>>(testContext);

    PFPlatformSpecificConsumePSNEntitlementsRequestWrapper<> request;
    FillConsumePSNEntitlementsRequest(request);
    LogConsumePSNEntitlementsRequest(&request.Model(), "TestPlatformSpecificClientConsumePSNEntitlements");
    HRESULT hr = PFPlatformSpecificClientConsumePSNEntitlementsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientConsumePSNEntitlementsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientConsumeXboxEntitlements

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientConsumeXboxEntitlements(TestContext& testContext)
{
    struct ClientConsumeXboxEntitlementsResultHolder : public ConsumeXboxEntitlementsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumeXboxEntitlementsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientConsumeXboxEntitlementsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificConsumeXboxEntitlementsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificConsumeXboxEntitlementsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientConsumeXboxEntitlementsResultHolder>>(testContext);

    PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper<> request;
    FillConsumeXboxEntitlementsRequest(request);
    LogConsumeXboxEntitlementsRequest(&request.Model(), "TestPlatformSpecificClientConsumeXboxEntitlements");
    HRESULT hr = PFPlatformSpecificClientConsumeXboxEntitlementsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientConsumeXboxEntitlementsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRefreshPSNAuthToken

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientRefreshPSNAuthToken(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper<> request;
    FillRefreshPSNAuthTokenRequest(request);
    LogRefreshPSNAuthTokenRequest(&request.Model(), "TestPlatformSpecificClientRefreshPSNAuthToken");
    HRESULT hr = PFPlatformSpecificClientRefreshPSNAuthTokenAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientRefreshPSNAuthTokenAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRegisterForIOSPushNotification

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientRegisterForIOSPushNotification(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper<> request;
    FillRegisterForIOSPushNotificationRequest(request);
    LogRegisterForIOSPushNotificationRequest(&request.Model(), "TestPlatformSpecificClientRegisterForIOSPushNotification");
    HRESULT hr = PFPlatformSpecificClientRegisterForIOSPushNotificationAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientRegisterForIOSPushNotificationAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRestoreIOSPurchases

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientRestoreIOSPurchases(TestContext& testContext)
{
    struct ClientRestoreIOSPurchasesResultHolder : public RestoreIOSPurchasesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientRestoreIOSPurchasesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientRestoreIOSPurchasesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificRestoreIOSPurchasesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificRestoreIOSPurchasesResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientRestoreIOSPurchasesResultHolder>>(testContext);

    PFPlatformSpecificRestoreIOSPurchasesRequestWrapper<> request;
    FillRestoreIOSPurchasesRequest(request);
    LogRestoreIOSPurchasesRequest(&request.Model(), "TestPlatformSpecificClientRestoreIOSPurchases");
    HRESULT hr = PFPlatformSpecificClientRestoreIOSPurchasesAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientRestoreIOSPurchasesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientValidateAmazonIAPReceipt

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateAmazonIAPReceipt(TestContext& testContext)
{
    struct ClientValidateAmazonIAPReceiptResultHolder : public ValidateAmazonReceiptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateAmazonIAPReceiptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateAmazonIAPReceiptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificValidateAmazonReceiptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificValidateAmazonReceiptResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientValidateAmazonIAPReceiptResultHolder>>(testContext);

    PFPlatformSpecificValidateAmazonReceiptRequestWrapper<> request;
    FillValidateAmazonReceiptRequest(request);
    LogValidateAmazonReceiptRequest(&request.Model(), "TestPlatformSpecificClientValidateAmazonIAPReceipt");
    HRESULT hr = PFPlatformSpecificClientValidateAmazonIAPReceiptAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientValidateAmazonIAPReceiptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientValidateGooglePlayPurchase

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateGooglePlayPurchase(TestContext& testContext)
{
    struct ClientValidateGooglePlayPurchaseResultHolder : public ValidateGooglePlayPurchaseResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateGooglePlayPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateGooglePlayPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificValidateGooglePlayPurchaseResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificValidateGooglePlayPurchaseResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientValidateGooglePlayPurchaseResultHolder>>(testContext);

    PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper<> request;
    FillValidateGooglePlayPurchaseRequest(request);
    LogValidateGooglePlayPurchaseRequest(&request.Model(), "TestPlatformSpecificClientValidateGooglePlayPurchase");
    HRESULT hr = PFPlatformSpecificClientValidateGooglePlayPurchaseAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientValidateGooglePlayPurchaseAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientValidateIOSReceipt

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateIOSReceipt(TestContext& testContext)
{
    struct ClientValidateIOSReceiptResultHolder : public ValidateIOSReceiptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateIOSReceiptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateIOSReceiptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificValidateIOSReceiptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificValidateIOSReceiptResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientValidateIOSReceiptResultHolder>>(testContext);

    PFPlatformSpecificValidateIOSReceiptRequestWrapper<> request;
    FillValidateIOSReceiptRequest(request);
    LogValidateIOSReceiptRequest(&request.Model(), "TestPlatformSpecificClientValidateIOSReceipt");
    HRESULT hr = PFPlatformSpecificClientValidateIOSReceiptAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientValidateIOSReceiptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientValidateWindowsStoreReceipt

void AutoGenPlatformSpecificTests::TestPlatformSpecificClientValidateWindowsStoreReceipt(TestContext& testContext)
{
    struct ClientValidateWindowsStoreReceiptResultHolder : public ValidateWindowsReceiptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateWindowsStoreReceiptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificClientValidateWindowsStoreReceiptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificValidateWindowsReceiptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificValidateWindowsReceiptResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientValidateWindowsStoreReceiptResultHolder>>(testContext);

    PFPlatformSpecificValidateWindowsReceiptRequestWrapper<> request;
    FillValidateWindowsReceiptRequest(request);
    LogValidateWindowsReceiptRequest(&request.Model(), "TestPlatformSpecificClientValidateWindowsStoreReceipt");
    HRESULT hr = PFPlatformSpecificClientValidateWindowsStoreReceiptAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificClientValidateWindowsStoreReceiptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAwardSteamAchievement

void AutoGenPlatformSpecificTests::TestPlatformSpecificServerAwardSteamAchievement(TestContext& testContext)
{
    struct ServerAwardSteamAchievementResultHolder : public AwardSteamAchievementResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificServerAwardSteamAchievementGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlatformSpecificServerAwardSteamAchievementGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlatformSpecificAwardSteamAchievementResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlatformSpecificAwardSteamAchievementResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAwardSteamAchievementResultHolder>>(testContext);

    PFPlatformSpecificAwardSteamAchievementRequestWrapper<> request;
    FillAwardSteamAchievementRequest(request);
    LogAwardSteamAchievementRequest(&request.Model(), "TestPlatformSpecificServerAwardSteamAchievement");
    HRESULT hr = PFPlatformSpecificServerAwardSteamAchievementAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlatformSpecificPlatformSpecificServerAwardSteamAchievementAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
