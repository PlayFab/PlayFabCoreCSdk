#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAccountManagementTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenAccountManagementTests::AccountManagementTestData AutoGenAccountManagementTests::testData;

void AutoGenAccountManagementTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenAccountManagementTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenAccountManagementTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminBanUsers", &AutoGenAccountManagementTests::TestAccountManagementAdminBanUsers);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminDeleteMasterPlayerAccount", &AutoGenAccountManagementTests::TestAccountManagementAdminDeleteMasterPlayerAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminDeleteMembershipSubscription", &AutoGenAccountManagementTests::TestAccountManagementAdminDeleteMembershipSubscription);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminDeletePlayer", &AutoGenAccountManagementTests::TestAccountManagementAdminDeletePlayer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminDeleteTitle", &AutoGenAccountManagementTests::TestAccountManagementAdminDeleteTitle);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminExportMasterPlayerData", &AutoGenAccountManagementTests::TestAccountManagementAdminExportMasterPlayerData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminGetPlayedTitleList", &AutoGenAccountManagementTests::TestAccountManagementAdminGetPlayedTitleList);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminGetPlayerIdFromAuthToken", &AutoGenAccountManagementTests::TestAccountManagementAdminGetPlayerIdFromAuthToken);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminGetPlayerProfile", &AutoGenAccountManagementTests::TestAccountManagementAdminGetPlayerProfile);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminGetUserAccountInfo", &AutoGenAccountManagementTests::TestAccountManagementAdminGetUserAccountInfo);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminGetUserBans", &AutoGenAccountManagementTests::TestAccountManagementAdminGetUserBans);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminResetPassword", &AutoGenAccountManagementTests::TestAccountManagementAdminResetPassword);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminRevokeAllBansForUser", &AutoGenAccountManagementTests::TestAccountManagementAdminRevokeAllBansForUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminRevokeBans", &AutoGenAccountManagementTests::TestAccountManagementAdminRevokeBans);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminSendAccountRecoveryEmail", &AutoGenAccountManagementTests::TestAccountManagementAdminSendAccountRecoveryEmail);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminSetMembershipOverride", &AutoGenAccountManagementTests::TestAccountManagementAdminSetMembershipOverride);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminUpdateBans", &AutoGenAccountManagementTests::TestAccountManagementAdminUpdateBans);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementAdminUpdateUserTitleDisplayName", &AutoGenAccountManagementTests::TestAccountManagementAdminUpdateUserTitleDisplayName);
#endif

    AddTest("TestAccountManagementClientAddGenericID", &AutoGenAccountManagementTests::TestAccountManagementClientAddGenericID);

    AddTest("TestAccountManagementClientAddOrUpdateContactEmail", &AutoGenAccountManagementTests::TestAccountManagementClientAddOrUpdateContactEmail);

    AddTest("TestAccountManagementClientAddUsernamePassword", &AutoGenAccountManagementTests::TestAccountManagementClientAddUsernamePassword);

    AddTest("TestAccountManagementClientGetAccountInfo", &AutoGenAccountManagementTests::TestAccountManagementClientGetAccountInfo);

    AddTest("TestAccountManagementClientGetPlayerCombinedInfo", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayerCombinedInfo);

    AddTest("TestAccountManagementClientGetPlayerProfile", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayerProfile);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromFacebookIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromFacebookIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIds", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIds);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromGameCenterIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromGameCenterIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromGenericIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromGenericIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromGoogleIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromGoogleIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromKongregateIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromKongregateIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIds", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIds);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromPSNAccountIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromPSNAccountIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromSteamIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromSteamIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromTwitchIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromTwitchIDs);

    AddTest("TestAccountManagementClientGetPlayFabIDsFromXboxLiveIDs", &AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromXboxLiveIDs);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkAndroidDeviceID", &AutoGenAccountManagementTests::TestAccountManagementClientLinkAndroidDeviceID);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkApple", &AutoGenAccountManagementTests::TestAccountManagementClientLinkApple);
#endif

    AddTest("TestAccountManagementClientLinkCustomID", &AutoGenAccountManagementTests::TestAccountManagementClientLinkCustomID);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkFacebookAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkFacebookAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkFacebookInstantGamesId", &AutoGenAccountManagementTests::TestAccountManagementClientLinkFacebookInstantGamesId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkGameCenterAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkGameCenterAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkGoogleAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkGoogleAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkIOSDeviceID", &AutoGenAccountManagementTests::TestAccountManagementClientLinkIOSDeviceID);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkKongregate", &AutoGenAccountManagementTests::TestAccountManagementClientLinkKongregate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkNintendoServiceAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkNintendoServiceAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkNintendoSwitchDeviceId", &AutoGenAccountManagementTests::TestAccountManagementClientLinkNintendoSwitchDeviceId);
#endif

    AddTest("TestAccountManagementClientLinkOpenIdConnect", &AutoGenAccountManagementTests::TestAccountManagementClientLinkOpenIdConnect);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkPSNAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkPSNAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkSteamAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkSteamAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientLinkTwitch", &AutoGenAccountManagementTests::TestAccountManagementClientLinkTwitch);
#endif

    AddTest("TestAccountManagementClientLinkXboxAccount", &AutoGenAccountManagementTests::TestAccountManagementClientLinkXboxAccount);

    AddTest("TestAccountManagementClientRemoveContactEmail", &AutoGenAccountManagementTests::TestAccountManagementClientRemoveContactEmail);

    AddTest("TestAccountManagementClientRemoveGenericID", &AutoGenAccountManagementTests::TestAccountManagementClientRemoveGenericID);

    AddTest("TestAccountManagementClientReportPlayer", &AutoGenAccountManagementTests::TestAccountManagementClientReportPlayer);

    AddTest("TestAccountManagementClientSendAccountRecoveryEmail", &AutoGenAccountManagementTests::TestAccountManagementClientSendAccountRecoveryEmail);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkAndroidDeviceID", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkAndroidDeviceID);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkApple", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkApple);
#endif

    AddTest("TestAccountManagementClientUnlinkCustomID", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkCustomID);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkFacebookAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkFacebookAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkFacebookInstantGamesId", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkFacebookInstantGamesId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkGameCenterAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkGameCenterAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkGoogleAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkGoogleAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkIOSDeviceID", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkIOSDeviceID);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkKongregate", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkKongregate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkNintendoServiceAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkNintendoServiceAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkNintendoSwitchDeviceId", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkNintendoSwitchDeviceId);
#endif

    AddTest("TestAccountManagementClientUnlinkOpenIdConnect", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkOpenIdConnect);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkPSNAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkPSNAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkSteamAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkSteamAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementClientUnlinkTwitch", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkTwitch);
#endif

    AddTest("TestAccountManagementClientUnlinkXboxAccount", &AutoGenAccountManagementTests::TestAccountManagementClientUnlinkXboxAccount);

    AddTest("TestAccountManagementClientUpdateAvatarUrl", &AutoGenAccountManagementTests::TestAccountManagementClientUpdateAvatarUrl);

    AddTest("TestAccountManagementClientUpdateUserTitleDisplayName", &AutoGenAccountManagementTests::TestAccountManagementClientUpdateUserTitleDisplayName);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerAddGenericID", &AutoGenAccountManagementTests::TestAccountManagementServerAddGenericID);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerBanUsers", &AutoGenAccountManagementTests::TestAccountManagementServerBanUsers);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerDeletePlayer", &AutoGenAccountManagementTests::TestAccountManagementServerDeletePlayer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerDeletePushNotificationTemplate", &AutoGenAccountManagementTests::TestAccountManagementServerDeletePushNotificationTemplate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayerProfile", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayerProfile);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromFacebookIDs", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromFacebookIDs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIds", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIds);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromGenericIDs", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromGenericIDs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIds", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIds);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromPSNAccountIDs", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromPSNAccountIDs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromSteamIDs", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromSteamIDs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetPlayFabIDsFromXboxLiveIDs", &AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromXboxLiveIDs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetServerCustomIDsFromPlayFabIDs", &AutoGenAccountManagementTests::TestAccountManagementServerGetServerCustomIDsFromPlayFabIDs);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetUserAccountInfo", &AutoGenAccountManagementTests::TestAccountManagementServerGetUserAccountInfo);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerGetUserBans", &AutoGenAccountManagementTests::TestAccountManagementServerGetUserBans);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerLinkPSNAccount", &AutoGenAccountManagementTests::TestAccountManagementServerLinkPSNAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerLinkServerCustomId", &AutoGenAccountManagementTests::TestAccountManagementServerLinkServerCustomId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerLinkXboxAccount", &AutoGenAccountManagementTests::TestAccountManagementServerLinkXboxAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerRemoveGenericID", &AutoGenAccountManagementTests::TestAccountManagementServerRemoveGenericID);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerRevokeAllBansForUser", &AutoGenAccountManagementTests::TestAccountManagementServerRevokeAllBansForUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerRevokeBans", &AutoGenAccountManagementTests::TestAccountManagementServerRevokeBans);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerSavePushNotificationTemplate", &AutoGenAccountManagementTests::TestAccountManagementServerSavePushNotificationTemplate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerSendCustomAccountRecoveryEmail", &AutoGenAccountManagementTests::TestAccountManagementServerSendCustomAccountRecoveryEmail);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerSendEmailFromTemplate", &AutoGenAccountManagementTests::TestAccountManagementServerSendEmailFromTemplate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerSendPushNotification", &AutoGenAccountManagementTests::TestAccountManagementServerSendPushNotification);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerSendPushNotificationFromTemplate", &AutoGenAccountManagementTests::TestAccountManagementServerSendPushNotificationFromTemplate);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerUnlinkPSNAccount", &AutoGenAccountManagementTests::TestAccountManagementServerUnlinkPSNAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerUnlinkServerCustomId", &AutoGenAccountManagementTests::TestAccountManagementServerUnlinkServerCustomId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerUnlinkXboxAccount", &AutoGenAccountManagementTests::TestAccountManagementServerUnlinkXboxAccount);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerUpdateAvatarUrl", &AutoGenAccountManagementTests::TestAccountManagementServerUpdateAvatarUrl);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAccountManagementServerUpdateBans", &AutoGenAccountManagementTests::TestAccountManagementServerUpdateBans);
#endif
}

void AutoGenAccountManagementTests::ClassSetUp()
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

void AutoGenAccountManagementTests::ClassTearDown()
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

void AutoGenAccountManagementTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminBanUsers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminBanUsers(TestContext& testContext)
{
    struct AdminBanUsersResultHolderStruct : public BanUsersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminBanUsersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminBanUsersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementBanUsersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementBanUsersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminBanUsersResultHolderStruct>>(testContext);

    PFAccountManagementBanUsersRequestWrapper<> request;
    FillBanUsersRequest(request);
    LogBanUsersRequest(&request.Model(), "TestAccountManagementAdminBanUsers");
    HRESULT hr = PFAccountManagementAdminBanUsersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminBanUsersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteMasterPlayerAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminDeleteMasterPlayerAccount(TestContext& testContext)
{
    struct AdminDeleteMasterPlayerAccountResultHolderStruct : public DeleteMasterPlayerAccountResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminDeleteMasterPlayerAccountGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminDeleteMasterPlayerAccountGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementDeleteMasterPlayerAccountResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementDeleteMasterPlayerAccountResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminDeleteMasterPlayerAccountResultHolderStruct>>(testContext);

    PFAccountManagementDeleteMasterPlayerAccountRequestWrapper<> request;
    FillDeleteMasterPlayerAccountRequest(request);
    LogDeleteMasterPlayerAccountRequest(&request.Model(), "TestAccountManagementAdminDeleteMasterPlayerAccount");
    HRESULT hr = PFAccountManagementAdminDeleteMasterPlayerAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminDeleteMasterPlayerAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteMembershipSubscription

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminDeleteMembershipSubscription(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementDeleteMembershipSubscriptionRequestWrapper<> request;
    FillDeleteMembershipSubscriptionRequest(request);
    LogDeleteMembershipSubscriptionRequest(&request.Model(), "TestAccountManagementAdminDeleteMembershipSubscription");
    HRESULT hr = PFAccountManagementAdminDeleteMembershipSubscriptionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminDeleteMembershipSubscriptionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeletePlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminDeletePlayer(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementDeletePlayerRequestWrapper<> request;
    FillDeletePlayerRequest(request);
    LogDeletePlayerRequest(&request.Model(), "TestAccountManagementAdminDeletePlayer");
    HRESULT hr = PFAccountManagementAdminDeletePlayerAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminDeletePlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteTitle

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminDeleteTitle(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    HRESULT hr = PFAccountManagementAdminDeleteTitleAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminDeleteTitleAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminExportMasterPlayerData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminExportMasterPlayerData(TestContext& testContext)
{
    struct AdminExportMasterPlayerDataResultHolderStruct : public ExportMasterPlayerDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminExportMasterPlayerDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminExportMasterPlayerDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementExportMasterPlayerDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementExportMasterPlayerDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminExportMasterPlayerDataResultHolderStruct>>(testContext);

    PFAccountManagementExportMasterPlayerDataRequestWrapper<> request;
    FillExportMasterPlayerDataRequest(request);
    LogExportMasterPlayerDataRequest(&request.Model(), "TestAccountManagementAdminExportMasterPlayerData");
    HRESULT hr = PFAccountManagementAdminExportMasterPlayerDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminExportMasterPlayerDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayedTitleList

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminGetPlayedTitleList(TestContext& testContext)
{
    struct AdminGetPlayedTitleListResultHolderStruct : public GetPlayedTitleListResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetPlayedTitleListGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetPlayedTitleListGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayedTitleListResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayedTitleListResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayedTitleListResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayedTitleListRequestWrapper<> request;
    FillGetPlayedTitleListRequest(request);
    LogGetPlayedTitleListRequest(&request.Model(), "TestAccountManagementAdminGetPlayedTitleList");
    HRESULT hr = PFAccountManagementAdminGetPlayedTitleListAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminGetPlayedTitleListAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerIdFromAuthToken

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminGetPlayerIdFromAuthToken(TestContext& testContext)
{
    struct AdminGetPlayerIdFromAuthTokenResultHolderStruct : public GetPlayerIdFromAuthTokenResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetPlayerIdFromAuthTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetPlayerIdFromAuthTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayerIdFromAuthTokenResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayerIdFromAuthTokenResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerIdFromAuthTokenResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper<> request;
    FillGetPlayerIdFromAuthTokenRequest(request);
    LogGetPlayerIdFromAuthTokenRequest(&request.Model(), "TestAccountManagementAdminGetPlayerIdFromAuthToken");
    HRESULT hr = PFAccountManagementAdminGetPlayerIdFromAuthTokenAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminGetPlayerIdFromAuthTokenAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerProfile

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminGetPlayerProfile(TestContext& testContext)
{
    struct AdminGetPlayerProfileResultHolderStruct : public GetPlayerProfileResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetPlayerProfileGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetPlayerProfileGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayerProfileResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayerProfileResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerProfileResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayerProfileRequestWrapper<> request;
    FillGetPlayerProfileRequest(request);
    LogGetPlayerProfileRequest(&request.Model(), "TestAccountManagementAdminGetPlayerProfile");
    HRESULT hr = PFAccountManagementAdminGetPlayerProfileAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminGetPlayerProfileAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserAccountInfo

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminGetUserAccountInfo(TestContext& testContext)
{
    struct AdminGetUserAccountInfoResultHolderStruct : public LookupUserAccountInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetUserAccountInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetUserAccountInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementLookupUserAccountInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementLookupUserAccountInfoResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserAccountInfoResultHolderStruct>>(testContext);

    PFAccountManagementLookupUserAccountInfoRequestWrapper<> request;
    FillLookupUserAccountInfoRequest(request);
    LogLookupUserAccountInfoRequest(&request.Model(), "TestAccountManagementAdminGetUserAccountInfo");
    HRESULT hr = PFAccountManagementAdminGetUserAccountInfoAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminGetUserAccountInfoAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserBans

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminGetUserBans(TestContext& testContext)
{
    struct AdminGetUserBansResultHolderStruct : public GetUserBansResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetUserBansGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminGetUserBansGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetUserBansResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetUserBansResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserBansResultHolderStruct>>(testContext);

    PFAccountManagementGetUserBansRequestWrapper<> request;
    FillGetUserBansRequest(request);
    LogGetUserBansRequest(&request.Model(), "TestAccountManagementAdminGetUserBans");
    HRESULT hr = PFAccountManagementAdminGetUserBansAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminGetUserBansAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminResetPassword

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminResetPassword(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementResetPasswordRequestWrapper<> request;
    FillResetPasswordRequest(request);
    LogResetPasswordRequest(&request.Model(), "TestAccountManagementAdminResetPassword");
    HRESULT hr = PFAccountManagementAdminResetPasswordAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminResetPasswordAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRevokeAllBansForUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminRevokeAllBansForUser(TestContext& testContext)
{
    struct AdminRevokeAllBansForUserResultHolderStruct : public RevokeAllBansForUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminRevokeAllBansForUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminRevokeAllBansForUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementRevokeAllBansForUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementRevokeAllBansForUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRevokeAllBansForUserResultHolderStruct>>(testContext);

    PFAccountManagementRevokeAllBansForUserRequestWrapper<> request;
    FillRevokeAllBansForUserRequest(request);
    LogRevokeAllBansForUserRequest(&request.Model(), "TestAccountManagementAdminRevokeAllBansForUser");
    HRESULT hr = PFAccountManagementAdminRevokeAllBansForUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminRevokeAllBansForUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRevokeBans

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminRevokeBans(TestContext& testContext)
{
    struct AdminRevokeBansResultHolderStruct : public RevokeBansResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminRevokeBansGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminRevokeBansGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementRevokeBansResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementRevokeBansResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRevokeBansResultHolderStruct>>(testContext);

    PFAccountManagementRevokeBansRequestWrapper<> request;
    FillRevokeBansRequest(request);
    LogRevokeBansRequest(&request.Model(), "TestAccountManagementAdminRevokeBans");
    HRESULT hr = PFAccountManagementAdminRevokeBansAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminRevokeBansAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSendAccountRecoveryEmail

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminSendAccountRecoveryEmail(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper<> request;
    FillAdminSendAccountRecoveryEmailRequest(request);
    LogAdminSendAccountRecoveryEmailRequest(&request.Model(), "TestAccountManagementAdminSendAccountRecoveryEmail");
    HRESULT hr = PFAccountManagementAdminSendAccountRecoveryEmailAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminSendAccountRecoveryEmailAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetMembershipOverride

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminSetMembershipOverride(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementSetMembershipOverrideRequestWrapper<> request;
    FillSetMembershipOverrideRequest(request);
    LogSetMembershipOverrideRequest(&request.Model(), "TestAccountManagementAdminSetMembershipOverride");
    HRESULT hr = PFAccountManagementAdminSetMembershipOverrideAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminSetMembershipOverrideAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateBans

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminUpdateBans(TestContext& testContext)
{
    struct AdminUpdateBansResultHolderStruct : public UpdateBansResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminUpdateBansGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminUpdateBansGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementUpdateBansResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementUpdateBansResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateBansResultHolderStruct>>(testContext);

    PFAccountManagementUpdateBansRequestWrapper<> request;
    FillUpdateBansRequest(request);
    LogUpdateBansRequest(&request.Model(), "TestAccountManagementAdminUpdateBans");
    HRESULT hr = PFAccountManagementAdminUpdateBansAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminUpdateBansAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserTitleDisplayName

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementAdminUpdateUserTitleDisplayName(TestContext& testContext)
{
    struct AdminUpdateUserTitleDisplayNameResultHolderStruct : public UpdateUserTitleDisplayNameResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminUpdateUserTitleDisplayNameGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementAdminUpdateUserTitleDisplayNameGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementUpdateUserTitleDisplayNameResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementUpdateUserTitleDisplayNameResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserTitleDisplayNameResultHolderStruct>>(testContext);

    PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper<> request;
    FillAdminUpdateUserTitleDisplayNameRequest(request);
    LogAdminUpdateUserTitleDisplayNameRequest(&request.Model(), "TestAccountManagementAdminUpdateUserTitleDisplayName");
    HRESULT hr = PFAccountManagementAdminUpdateUserTitleDisplayNameAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementAdminUpdateUserTitleDisplayNameAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientAddGenericID

void AutoGenAccountManagementTests::TestAccountManagementClientAddGenericID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientAddGenericIDRequestWrapper<> request;
    FillClientAddGenericIDRequest(request);
    LogClientAddGenericIDRequest(&request.Model(), "TestAccountManagementClientAddGenericID");
    HRESULT hr = PFAccountManagementClientAddGenericIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientAddGenericIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientAddOrUpdateContactEmail

void AutoGenAccountManagementTests::TestAccountManagementClientAddOrUpdateContactEmail(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementAddOrUpdateContactEmailRequestWrapper<> request;
    FillAddOrUpdateContactEmailRequest(request);
    LogAddOrUpdateContactEmailRequest(&request.Model(), "TestAccountManagementClientAddOrUpdateContactEmail");
    HRESULT hr = PFAccountManagementClientAddOrUpdateContactEmailAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientAddOrUpdateContactEmailAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientAddUsernamePassword

void AutoGenAccountManagementTests::TestAccountManagementClientAddUsernamePassword(TestContext& testContext)
{
    struct ClientAddUsernamePasswordResultHolderStruct : public AddUsernamePasswordResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientAddUsernamePasswordGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientAddUsernamePasswordGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementAddUsernamePasswordResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementAddUsernamePasswordResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientAddUsernamePasswordResultHolderStruct>>(testContext);

    PFAccountManagementAddUsernamePasswordRequestWrapper<> request;
    FillAddUsernamePasswordRequest(request);
    LogAddUsernamePasswordRequest(&request.Model(), "TestAccountManagementClientAddUsernamePassword");
    HRESULT hr = PFAccountManagementClientAddUsernamePasswordAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientAddUsernamePasswordAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetAccountInfo

void AutoGenAccountManagementTests::TestAccountManagementClientGetAccountInfo(TestContext& testContext)
{
    struct ClientGetAccountInfoResultHolderStruct : public GetAccountInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetAccountInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetAccountInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetAccountInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetAccountInfoResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetAccountInfoResultHolderStruct>>(testContext);

    PFAccountManagementGetAccountInfoRequestWrapper<> request;
    FillGetAccountInfoRequest(request);
    LogGetAccountInfoRequest(&request.Model(), "TestAccountManagementClientGetAccountInfo");
    HRESULT hr = PFAccountManagementClientGetAccountInfoAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetAccountInfoAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerCombinedInfo

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayerCombinedInfo(TestContext& testContext)
{
    struct ClientGetPlayerCombinedInfoResultHolderStruct : public GetPlayerCombinedInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayerCombinedInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayerCombinedInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGetPlayerCombinedInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGetPlayerCombinedInfoResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerCombinedInfoResultHolderStruct>>(testContext);

    PFGetPlayerCombinedInfoRequestWrapper<> request;
    FillGetPlayerCombinedInfoRequest(request);
    LogGetPlayerCombinedInfoRequest(&request.Model(), "TestAccountManagementClientGetPlayerCombinedInfo");
    HRESULT hr = PFAccountManagementClientGetPlayerCombinedInfoAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayerCombinedInfoAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerProfile

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayerProfile(TestContext& testContext)
{
    struct ClientGetPlayerProfileResultHolderStruct : public GetPlayerProfileResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayerProfileGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayerProfileGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayerProfileResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayerProfileResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerProfileResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayerProfileRequestWrapper<> request;
    FillGetPlayerProfileRequest(request);
    LogGetPlayerProfileRequest(&request.Model(), "TestAccountManagementClientGetPlayerProfile");
    HRESULT hr = PFAccountManagementClientGetPlayerProfileAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayerProfileAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromFacebookIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromFacebookIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromFacebookIDsResultHolderStruct : public GetPlayFabIDsFromFacebookIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromFacebookIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromFacebookIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromFacebookIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromFacebookIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromFacebookIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromFacebookIDsRequest(request);
    LogGetPlayFabIDsFromFacebookIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromFacebookIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromFacebookIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromFacebookIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromFacebookInstantGamesIds

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIds(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromFacebookInstantGamesIdsResultHolderStruct : public GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromFacebookInstantGamesIdsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<> request;
    FillGetPlayFabIDsFromFacebookInstantGamesIdsRequest(request);
    LogGetPlayFabIDsFromFacebookInstantGamesIdsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIds");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromGameCenterIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromGameCenterIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromGameCenterIDsResultHolderStruct : public GetPlayFabIDsFromGameCenterIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromGameCenterIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromGameCenterIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromGameCenterIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromGameCenterIDsRequest(request);
    LogGetPlayFabIDsFromGameCenterIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromGameCenterIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromGameCenterIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromGenericIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromGenericIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromGenericIDsResultHolderStruct : public GetPlayFabIDsFromGenericIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromGenericIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromGenericIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromGenericIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromGenericIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromGenericIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromGenericIDsRequest(request);
    LogGetPlayFabIDsFromGenericIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromGenericIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromGenericIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromGenericIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromGoogleIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromGoogleIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromGoogleIDsResultHolderStruct : public GetPlayFabIDsFromGoogleIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromGoogleIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromGoogleIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromGoogleIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromGoogleIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromGoogleIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromGoogleIDsRequest(request);
    LogGetPlayFabIDsFromGoogleIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromGoogleIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromGoogleIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromGoogleIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromKongregateIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromKongregateIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromKongregateIDsResultHolderStruct : public GetPlayFabIDsFromKongregateIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromKongregateIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromKongregateIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromKongregateIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromKongregateIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromKongregateIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromKongregateIDsRequest(request);
    LogGetPlayFabIDsFromKongregateIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromKongregateIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromKongregateIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromKongregateIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromNintendoSwitchDeviceIds

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIds(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolderStruct : public GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<> request;
    FillGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(request);
    LogGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIds");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromPSNAccountIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromPSNAccountIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromPSNAccountIDsResultHolderStruct : public GetPlayFabIDsFromPSNAccountIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromPSNAccountIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromPSNAccountIDsRequest(request);
    LogGetPlayFabIDsFromPSNAccountIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromPSNAccountIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromPSNAccountIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromSteamIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromSteamIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromSteamIDsResultHolderStruct : public GetPlayFabIDsFromSteamIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromSteamIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromSteamIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromSteamIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromSteamIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromSteamIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromSteamIDsRequest(request);
    LogGetPlayFabIDsFromSteamIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromSteamIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromSteamIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromSteamIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromTwitchIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromTwitchIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromTwitchIDsResultHolderStruct : public GetPlayFabIDsFromTwitchIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromTwitchIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromTwitchIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromTwitchIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromTwitchIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromTwitchIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromTwitchIDsRequest(request);
    LogGetPlayFabIDsFromTwitchIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromTwitchIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromTwitchIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromTwitchIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayFabIDsFromXboxLiveIDs

void AutoGenAccountManagementTests::TestAccountManagementClientGetPlayFabIDsFromXboxLiveIDs(TestContext& testContext)
{
    struct ClientGetPlayFabIDsFromXboxLiveIDsResultHolderStruct : public GetPlayFabIDsFromXboxLiveIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayFabIDsFromXboxLiveIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromXboxLiveIDsRequest(request);
    LogGetPlayFabIDsFromXboxLiveIDsRequest(&request.Model(), "TestAccountManagementClientGetPlayFabIDsFromXboxLiveIDs");
    HRESULT hr = PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientGetPlayFabIDsFromXboxLiveIDsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLinkAndroidDeviceID

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkAndroidDeviceID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkAndroidDeviceIDRequestWrapper<> request;
    FillLinkAndroidDeviceIDRequest(request);
    LogLinkAndroidDeviceIDRequest(&request.Model(), "TestAccountManagementClientLinkAndroidDeviceID");
    HRESULT hr = PFAccountManagementClientLinkAndroidDeviceIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkAndroidDeviceIDAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkApple

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkApple(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkAppleRequestWrapper<> request;
    FillLinkAppleRequest(request);
    LogLinkAppleRequest(&request.Model(), "TestAccountManagementClientLinkApple");
    HRESULT hr = PFAccountManagementClientLinkAppleAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkAppleAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkCustomID

void AutoGenAccountManagementTests::TestAccountManagementClientLinkCustomID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkCustomIDRequestWrapper<> request;
    FillLinkCustomIDRequest(request);
    LogLinkCustomIDRequest(&request.Model(), "TestAccountManagementClientLinkCustomID");
    HRESULT hr = PFAccountManagementClientLinkCustomIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkCustomIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLinkFacebookAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkFacebookAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkFacebookAccountRequestWrapper<> request;
    FillLinkFacebookAccountRequest(request);
    LogLinkFacebookAccountRequest(&request.Model(), "TestAccountManagementClientLinkFacebookAccount");
    HRESULT hr = PFAccountManagementClientLinkFacebookAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkFacebookAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkFacebookInstantGamesId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkFacebookInstantGamesId(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper<> request;
    FillLinkFacebookInstantGamesIdRequest(request);
    LogLinkFacebookInstantGamesIdRequest(&request.Model(), "TestAccountManagementClientLinkFacebookInstantGamesId");
    HRESULT hr = PFAccountManagementClientLinkFacebookInstantGamesIdAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkFacebookInstantGamesIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkGameCenterAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkGameCenterAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkGameCenterAccountRequestWrapper<> request;
    FillLinkGameCenterAccountRequest(request);
    LogLinkGameCenterAccountRequest(&request.Model(), "TestAccountManagementClientLinkGameCenterAccount");
    HRESULT hr = PFAccountManagementClientLinkGameCenterAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkGameCenterAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkGoogleAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkGoogleAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkGoogleAccountRequestWrapper<> request;
    FillLinkGoogleAccountRequest(request);
    LogLinkGoogleAccountRequest(&request.Model(), "TestAccountManagementClientLinkGoogleAccount");
    HRESULT hr = PFAccountManagementClientLinkGoogleAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkGoogleAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkIOSDeviceID

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkIOSDeviceID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkIOSDeviceIDRequestWrapper<> request;
    FillLinkIOSDeviceIDRequest(request);
    LogLinkIOSDeviceIDRequest(&request.Model(), "TestAccountManagementClientLinkIOSDeviceID");
    HRESULT hr = PFAccountManagementClientLinkIOSDeviceIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkIOSDeviceIDAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkKongregate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkKongregate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkKongregateAccountRequestWrapper<> request;
    FillLinkKongregateAccountRequest(request);
    LogLinkKongregateAccountRequest(&request.Model(), "TestAccountManagementClientLinkKongregate");
    HRESULT hr = PFAccountManagementClientLinkKongregateAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkKongregateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkNintendoServiceAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkNintendoServiceAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkNintendoServiceAccountRequestWrapper<> request;
    FillLinkNintendoServiceAccountRequest(request);
    LogLinkNintendoServiceAccountRequest(&request.Model(), "TestAccountManagementClientLinkNintendoServiceAccount");
    HRESULT hr = PFAccountManagementClientLinkNintendoServiceAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkNintendoServiceAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkNintendoSwitchDeviceId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkNintendoSwitchDeviceId(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper<> request;
    FillLinkNintendoSwitchDeviceIdRequest(request);
    LogLinkNintendoSwitchDeviceIdRequest(&request.Model(), "TestAccountManagementClientLinkNintendoSwitchDeviceId");
    HRESULT hr = PFAccountManagementClientLinkNintendoSwitchDeviceIdAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkNintendoSwitchDeviceIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkOpenIdConnect

void AutoGenAccountManagementTests::TestAccountManagementClientLinkOpenIdConnect(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkOpenIdConnectRequestWrapper<> request;
    FillLinkOpenIdConnectRequest(request);
    LogLinkOpenIdConnectRequest(&request.Model(), "TestAccountManagementClientLinkOpenIdConnect");
    HRESULT hr = PFAccountManagementClientLinkOpenIdConnectAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkOpenIdConnectAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLinkPSNAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkPSNAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientLinkPSNAccountRequestWrapper<> request;
    FillClientLinkPSNAccountRequest(request);
    LogClientLinkPSNAccountRequest(&request.Model(), "TestAccountManagementClientLinkPSNAccount");
    HRESULT hr = PFAccountManagementClientLinkPSNAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkPSNAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkSteamAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkSteamAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkSteamAccountRequestWrapper<> request;
    FillLinkSteamAccountRequest(request);
    LogLinkSteamAccountRequest(&request.Model(), "TestAccountManagementClientLinkSteamAccount");
    HRESULT hr = PFAccountManagementClientLinkSteamAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkSteamAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkTwitch

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientLinkTwitch(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkTwitchAccountRequestWrapper<> request;
    FillLinkTwitchAccountRequest(request);
    LogLinkTwitchAccountRequest(&request.Model(), "TestAccountManagementClientLinkTwitch");
    HRESULT hr = PFAccountManagementClientLinkTwitchAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkTwitchAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientLinkXboxAccount

void AutoGenAccountManagementTests::TestAccountManagementClientLinkXboxAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientLinkXboxAccountRequestWrapper<> request;
    FillClientLinkXboxAccountRequest(request);
    LogClientLinkXboxAccountRequest(&request.Model(), "TestAccountManagementClientLinkXboxAccount");
    HRESULT hr = PFAccountManagementClientLinkXboxAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientLinkXboxAccountAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRemoveContactEmail

void AutoGenAccountManagementTests::TestAccountManagementClientRemoveContactEmail(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementRemoveContactEmailRequestWrapper<> request;
    FillRemoveContactEmailRequest(request);
    LogRemoveContactEmailRequest(&request.Model(), "TestAccountManagementClientRemoveContactEmail");
    HRESULT hr = PFAccountManagementClientRemoveContactEmailAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientRemoveContactEmailAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRemoveGenericID

void AutoGenAccountManagementTests::TestAccountManagementClientRemoveGenericID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientRemoveGenericIDRequestWrapper<> request;
    FillClientRemoveGenericIDRequest(request);
    LogClientRemoveGenericIDRequest(&request.Model(), "TestAccountManagementClientRemoveGenericID");
    HRESULT hr = PFAccountManagementClientRemoveGenericIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientRemoveGenericIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientReportPlayer

void AutoGenAccountManagementTests::TestAccountManagementClientReportPlayer(TestContext& testContext)
{
    struct ClientReportPlayerResultHolderStruct : public ReportPlayerClientResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientReportPlayerGetResult(async, &result)));
            LogPFAccountManagementReportPlayerClientResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementReportPlayerClientResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientReportPlayerResultHolderStruct>>(testContext);

    PFAccountManagementReportPlayerClientRequestWrapper<> request;
    FillReportPlayerClientRequest(request);
    LogReportPlayerClientRequest(&request.Model(), "TestAccountManagementClientReportPlayer");
    HRESULT hr = PFAccountManagementClientReportPlayerAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientReportPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientSendAccountRecoveryEmail

void AutoGenAccountManagementTests::TestAccountManagementClientSendAccountRecoveryEmail(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper<> request;
    FillClientSendAccountRecoveryEmailRequest(request);
    LogClientSendAccountRecoveryEmailRequest(&request.Model(), "TestAccountManagementClientSendAccountRecoveryEmail");
    HRESULT hr = PFAccountManagementClientSendAccountRecoveryEmailAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientSendAccountRecoveryEmailAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUnlinkAndroidDeviceID

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkAndroidDeviceID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper<> request;
    FillUnlinkAndroidDeviceIDRequest(request);
    LogUnlinkAndroidDeviceIDRequest(&request.Model(), "TestAccountManagementClientUnlinkAndroidDeviceID");
    HRESULT hr = PFAccountManagementClientUnlinkAndroidDeviceIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkAndroidDeviceIDAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkApple

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkApple(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkAppleRequestWrapper<> request;
    FillUnlinkAppleRequest(request);
    LogUnlinkAppleRequest(&request.Model(), "TestAccountManagementClientUnlinkApple");
    HRESULT hr = PFAccountManagementClientUnlinkAppleAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkAppleAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkCustomID

void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkCustomID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkCustomIDRequestWrapper<> request;
    FillUnlinkCustomIDRequest(request);
    LogUnlinkCustomIDRequest(&request.Model(), "TestAccountManagementClientUnlinkCustomID");
    HRESULT hr = PFAccountManagementClientUnlinkCustomIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkCustomIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUnlinkFacebookAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkFacebookAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkFacebookAccountRequestWrapper<> request;
    FillUnlinkFacebookAccountRequest(request);
    LogUnlinkFacebookAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkFacebookAccount");
    HRESULT hr = PFAccountManagementClientUnlinkFacebookAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkFacebookAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkFacebookInstantGamesId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkFacebookInstantGamesId(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper<> request;
    FillUnlinkFacebookInstantGamesIdRequest(request);
    LogUnlinkFacebookInstantGamesIdRequest(&request.Model(), "TestAccountManagementClientUnlinkFacebookInstantGamesId");
    HRESULT hr = PFAccountManagementClientUnlinkFacebookInstantGamesIdAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkFacebookInstantGamesIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkGameCenterAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkGameCenterAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkGameCenterAccountRequestWrapper<> request;
    FillUnlinkGameCenterAccountRequest(request);
    LogUnlinkGameCenterAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkGameCenterAccount");
    HRESULT hr = PFAccountManagementClientUnlinkGameCenterAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkGameCenterAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkGoogleAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkGoogleAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkGoogleAccountRequestWrapper<> request;
    FillUnlinkGoogleAccountRequest(request);
    LogUnlinkGoogleAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkGoogleAccount");
    HRESULT hr = PFAccountManagementClientUnlinkGoogleAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkGoogleAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkIOSDeviceID

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkIOSDeviceID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkIOSDeviceIDRequestWrapper<> request;
    FillUnlinkIOSDeviceIDRequest(request);
    LogUnlinkIOSDeviceIDRequest(&request.Model(), "TestAccountManagementClientUnlinkIOSDeviceID");
    HRESULT hr = PFAccountManagementClientUnlinkIOSDeviceIDAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkIOSDeviceIDAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkKongregate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkKongregate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkKongregateAccountRequestWrapper<> request;
    FillUnlinkKongregateAccountRequest(request);
    LogUnlinkKongregateAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkKongregate");
    HRESULT hr = PFAccountManagementClientUnlinkKongregateAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkKongregateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkNintendoServiceAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkNintendoServiceAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper<> request;
    FillUnlinkNintendoServiceAccountRequest(request);
    LogUnlinkNintendoServiceAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkNintendoServiceAccount");
    HRESULT hr = PFAccountManagementClientUnlinkNintendoServiceAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkNintendoServiceAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkNintendoSwitchDeviceId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkNintendoSwitchDeviceId(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper<> request;
    FillUnlinkNintendoSwitchDeviceIdRequest(request);
    LogUnlinkNintendoSwitchDeviceIdRequest(&request.Model(), "TestAccountManagementClientUnlinkNintendoSwitchDeviceId");
    HRESULT hr = PFAccountManagementClientUnlinkNintendoSwitchDeviceIdAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkNintendoSwitchDeviceIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkOpenIdConnect

void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkOpenIdConnect(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkOpenIdConnectRequestWrapper<> request;
    FillUnlinkOpenIdConnectRequest(request);
    LogUnlinkOpenIdConnectRequest(&request.Model(), "TestAccountManagementClientUnlinkOpenIdConnect");
    HRESULT hr = PFAccountManagementClientUnlinkOpenIdConnectAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkOpenIdConnectAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUnlinkPSNAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkPSNAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientUnlinkPSNAccountRequestWrapper<> request;
    FillClientUnlinkPSNAccountRequest(request);
    LogClientUnlinkPSNAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkPSNAccount");
    HRESULT hr = PFAccountManagementClientUnlinkPSNAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkPSNAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkSteamAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkSteamAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkSteamAccountRequestWrapper<> request;
    FillUnlinkSteamAccountRequest(request);
    LogUnlinkSteamAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkSteamAccount");
    HRESULT hr = PFAccountManagementClientUnlinkSteamAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkSteamAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkTwitch

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkTwitch(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkTwitchAccountRequestWrapper<> request;
    FillUnlinkTwitchAccountRequest(request);
    LogUnlinkTwitchAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkTwitch");
    HRESULT hr = PFAccountManagementClientUnlinkTwitchAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkTwitchAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientUnlinkXboxAccount

void AutoGenAccountManagementTests::TestAccountManagementClientUnlinkXboxAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientUnlinkXboxAccountRequestWrapper<> request;
    FillClientUnlinkXboxAccountRequest(request);
    LogClientUnlinkXboxAccountRequest(&request.Model(), "TestAccountManagementClientUnlinkXboxAccount");
    HRESULT hr = PFAccountManagementClientUnlinkXboxAccountAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUnlinkXboxAccountAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateAvatarUrl

void AutoGenAccountManagementTests::TestAccountManagementClientUpdateAvatarUrl(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementClientUpdateAvatarUrlRequestWrapper<> request;
    FillClientUpdateAvatarUrlRequest(request);
    LogClientUpdateAvatarUrlRequest(&request.Model(), "TestAccountManagementClientUpdateAvatarUrl");
    HRESULT hr = PFAccountManagementClientUpdateAvatarUrlAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUpdateAvatarUrlAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateUserTitleDisplayName

void AutoGenAccountManagementTests::TestAccountManagementClientUpdateUserTitleDisplayName(TestContext& testContext)
{
    struct ClientUpdateUserTitleDisplayNameResultHolderStruct : public UpdateUserTitleDisplayNameResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientUpdateUserTitleDisplayNameGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementClientUpdateUserTitleDisplayNameGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementUpdateUserTitleDisplayNameResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementUpdateUserTitleDisplayNameResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateUserTitleDisplayNameResultHolderStruct>>(testContext);

    PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper<> request;
    FillClientUpdateUserTitleDisplayNameRequest(request);
    LogClientUpdateUserTitleDisplayNameRequest(&request.Model(), "TestAccountManagementClientUpdateUserTitleDisplayName");
    HRESULT hr = PFAccountManagementClientUpdateUserTitleDisplayNameAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementClientUpdateUserTitleDisplayNameAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddGenericID

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerAddGenericID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerAddGenericIDRequestWrapper<> request;
    FillServerAddGenericIDRequest(request);
    LogServerAddGenericIDRequest(&request.Model(), "TestAccountManagementServerAddGenericID");
    HRESULT hr = PFAccountManagementServerAddGenericIDAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerAddGenericIDAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerBanUsers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerBanUsers(TestContext& testContext)
{
    struct ServerBanUsersResultHolderStruct : public BanUsersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerBanUsersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerBanUsersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementBanUsersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementBanUsersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerBanUsersResultHolderStruct>>(testContext);

    PFAccountManagementBanUsersRequestWrapper<> request;
    FillBanUsersRequest(request);
    LogBanUsersRequest(&request.Model(), "TestAccountManagementServerBanUsers");
    HRESULT hr = PFAccountManagementServerBanUsersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerBanUsersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerDeletePlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerDeletePlayer(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementDeletePlayerRequestWrapper<> request;
    FillDeletePlayerRequest(request);
    LogDeletePlayerRequest(&request.Model(), "TestAccountManagementServerDeletePlayer");
    HRESULT hr = PFAccountManagementServerDeletePlayerAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerDeletePlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerDeletePushNotificationTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerDeletePushNotificationTemplate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementDeletePushNotificationTemplateRequestWrapper<> request;
    FillDeletePushNotificationTemplateRequest(request);
    LogDeletePushNotificationTemplateRequest(&request.Model(), "TestAccountManagementServerDeletePushNotificationTemplate");
    HRESULT hr = PFAccountManagementServerDeletePushNotificationTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerDeletePushNotificationTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayerProfile

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayerProfile(TestContext& testContext)
{
    struct ServerGetPlayerProfileResultHolderStruct : public GetPlayerProfileResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayerProfileGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayerProfileGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayerProfileResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayerProfileResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerProfileResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayerProfileRequestWrapper<> request;
    FillGetPlayerProfileRequest(request);
    LogGetPlayerProfileRequest(&request.Model(), "TestAccountManagementServerGetPlayerProfile");
    HRESULT hr = PFAccountManagementServerGetPlayerProfileAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayerProfileAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromFacebookIDs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromFacebookIDs(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromFacebookIDsResultHolderStruct : public GetPlayFabIDsFromFacebookIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromFacebookIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromFacebookIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromFacebookIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromFacebookIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromFacebookIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromFacebookIDsRequest(request);
    LogGetPlayFabIDsFromFacebookIDsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromFacebookIDs");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromFacebookIDsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromFacebookIDsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromFacebookInstantGamesIds

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIds(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromFacebookInstantGamesIdsResultHolderStruct : public GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromFacebookInstantGamesIdsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<> request;
    FillGetPlayFabIDsFromFacebookInstantGamesIdsRequest(request);
    LogGetPlayFabIDsFromFacebookInstantGamesIdsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIds");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromGenericIDs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromGenericIDs(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromGenericIDsResultHolderStruct : public GetPlayFabIDsFromGenericIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromGenericIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromGenericIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromGenericIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromGenericIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromGenericIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromGenericIDsRequest(request);
    LogGetPlayFabIDsFromGenericIDsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromGenericIDs");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromGenericIDsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromGenericIDsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromNintendoSwitchDeviceIds

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIds(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolderStruct : public GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<> request;
    FillGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(request);
    LogGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIds");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromPSNAccountIDs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromPSNAccountIDs(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromPSNAccountIDsResultHolderStruct : public GetPlayFabIDsFromPSNAccountIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromPSNAccountIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromPSNAccountIDsRequest(request);
    LogGetPlayFabIDsFromPSNAccountIDsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromPSNAccountIDs");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromPSNAccountIDsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromSteamIDs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromSteamIDs(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromSteamIDsResultHolderStruct : public GetPlayFabIDsFromSteamIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromSteamIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromSteamIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromSteamIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromSteamIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromSteamIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromSteamIDsRequest(request);
    LogGetPlayFabIDsFromSteamIDsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromSteamIDs");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromSteamIDsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromSteamIDsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayFabIDsFromXboxLiveIDs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetPlayFabIDsFromXboxLiveIDs(TestContext& testContext)
{
    struct ServerGetPlayFabIDsFromXboxLiveIDsResultHolderStruct : public GetPlayFabIDsFromXboxLiveIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayFabIDsFromXboxLiveIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<> request;
    FillGetPlayFabIDsFromXboxLiveIDsRequest(request);
    LogGetPlayFabIDsFromXboxLiveIDsRequest(&request.Model(), "TestAccountManagementServerGetPlayFabIDsFromXboxLiveIDs");
    HRESULT hr = PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetPlayFabIDsFromXboxLiveIDsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetServerCustomIDsFromPlayFabIDs

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetServerCustomIDsFromPlayFabIDs(TestContext& testContext)
{
    struct ServerGetServerCustomIDsFromPlayFabIDsResultHolderStruct : public GetServerCustomIDsFromPlayFabIDsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetServerCustomIDsFromPlayFabIDsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetServerCustomIDsFromPlayFabIDsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetServerCustomIDsFromPlayFabIDsResultHolderStruct>>(testContext);

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper<> request;
    FillGetServerCustomIDsFromPlayFabIDsRequest(request);
    LogGetServerCustomIDsFromPlayFabIDsRequest(&request.Model(), "TestAccountManagementServerGetServerCustomIDsFromPlayFabIDs");
    HRESULT hr = PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetServerCustomIDsFromPlayFabIDsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserAccountInfo

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetUserAccountInfo(TestContext& testContext)
{
    struct ServerGetUserAccountInfoResultHolderStruct : public GetUserAccountInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetUserAccountInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetUserAccountInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetUserAccountInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetUserAccountInfoResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserAccountInfoResultHolderStruct>>(testContext);

    PFAccountManagementGetUserAccountInfoRequestWrapper<> request;
    FillGetUserAccountInfoRequest(request);
    LogGetUserAccountInfoRequest(&request.Model(), "TestAccountManagementServerGetUserAccountInfo");
    HRESULT hr = PFAccountManagementServerGetUserAccountInfoAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetUserAccountInfoAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserBans

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerGetUserBans(TestContext& testContext)
{
    struct ServerGetUserBansResultHolderStruct : public GetUserBansResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetUserBansGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerGetUserBansGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementGetUserBansResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementGetUserBansResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserBansResultHolderStruct>>(testContext);

    PFAccountManagementGetUserBansRequestWrapper<> request;
    FillGetUserBansRequest(request);
    LogGetUserBansRequest(&request.Model(), "TestAccountManagementServerGetUserBans");
    HRESULT hr = PFAccountManagementServerGetUserBansAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerGetUserBansAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLinkPSNAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerLinkPSNAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerLinkPSNAccountRequestWrapper<> request;
    FillServerLinkPSNAccountRequest(request);
    LogServerLinkPSNAccountRequest(&request.Model(), "TestAccountManagementServerLinkPSNAccount");
    HRESULT hr = PFAccountManagementServerLinkPSNAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerLinkPSNAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLinkServerCustomId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerLinkServerCustomId(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementLinkServerCustomIdRequestWrapper<> request;
    FillLinkServerCustomIdRequest(request);
    LogLinkServerCustomIdRequest(&request.Model(), "TestAccountManagementServerLinkServerCustomId");
    HRESULT hr = PFAccountManagementServerLinkServerCustomIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerLinkServerCustomIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLinkXboxAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerLinkXboxAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerLinkXboxAccountRequestWrapper<> request;
    FillServerLinkXboxAccountRequest(request);
    LogServerLinkXboxAccountRequest(&request.Model(), "TestAccountManagementServerLinkXboxAccount");
    HRESULT hr = PFAccountManagementServerLinkXboxAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerLinkXboxAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRemoveGenericID

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerRemoveGenericID(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerRemoveGenericIDRequestWrapper<> request;
    FillServerRemoveGenericIDRequest(request);
    LogServerRemoveGenericIDRequest(&request.Model(), "TestAccountManagementServerRemoveGenericID");
    HRESULT hr = PFAccountManagementServerRemoveGenericIDAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerRemoveGenericIDAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRevokeAllBansForUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerRevokeAllBansForUser(TestContext& testContext)
{
    struct ServerRevokeAllBansForUserResultHolderStruct : public RevokeAllBansForUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerRevokeAllBansForUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerRevokeAllBansForUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementRevokeAllBansForUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementRevokeAllBansForUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerRevokeAllBansForUserResultHolderStruct>>(testContext);

    PFAccountManagementRevokeAllBansForUserRequestWrapper<> request;
    FillRevokeAllBansForUserRequest(request);
    LogRevokeAllBansForUserRequest(&request.Model(), "TestAccountManagementServerRevokeAllBansForUser");
    HRESULT hr = PFAccountManagementServerRevokeAllBansForUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerRevokeAllBansForUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRevokeBans

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerRevokeBans(TestContext& testContext)
{
    struct ServerRevokeBansResultHolderStruct : public RevokeBansResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerRevokeBansGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerRevokeBansGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementRevokeBansResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementRevokeBansResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerRevokeBansResultHolderStruct>>(testContext);

    PFAccountManagementRevokeBansRequestWrapper<> request;
    FillRevokeBansRequest(request);
    LogRevokeBansRequest(&request.Model(), "TestAccountManagementServerRevokeBans");
    HRESULT hr = PFAccountManagementServerRevokeBansAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerRevokeBansAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSavePushNotificationTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerSavePushNotificationTemplate(TestContext& testContext)
{
    struct ServerSavePushNotificationTemplateResultHolderStruct : public SavePushNotificationTemplateResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerSavePushNotificationTemplateGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerSavePushNotificationTemplateGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementSavePushNotificationTemplateResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementSavePushNotificationTemplateResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSavePushNotificationTemplateResultHolderStruct>>(testContext);

    PFAccountManagementSavePushNotificationTemplateRequestWrapper<> request;
    FillSavePushNotificationTemplateRequest(request);
    LogSavePushNotificationTemplateRequest(&request.Model(), "TestAccountManagementServerSavePushNotificationTemplate");
    HRESULT hr = PFAccountManagementServerSavePushNotificationTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerSavePushNotificationTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSendCustomAccountRecoveryEmail

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerSendCustomAccountRecoveryEmail(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper<> request;
    FillSendCustomAccountRecoveryEmailRequest(request);
    LogSendCustomAccountRecoveryEmailRequest(&request.Model(), "TestAccountManagementServerSendCustomAccountRecoveryEmail");
    HRESULT hr = PFAccountManagementServerSendCustomAccountRecoveryEmailAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerSendCustomAccountRecoveryEmailAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSendEmailFromTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerSendEmailFromTemplate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementSendEmailFromTemplateRequestWrapper<> request;
    FillSendEmailFromTemplateRequest(request);
    LogSendEmailFromTemplateRequest(&request.Model(), "TestAccountManagementServerSendEmailFromTemplate");
    HRESULT hr = PFAccountManagementServerSendEmailFromTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerSendEmailFromTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSendPushNotification

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerSendPushNotification(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementSendPushNotificationRequestWrapper<> request;
    FillSendPushNotificationRequest(request);
    LogSendPushNotificationRequest(&request.Model(), "TestAccountManagementServerSendPushNotification");
    HRESULT hr = PFAccountManagementServerSendPushNotificationAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerSendPushNotificationAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSendPushNotificationFromTemplate

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerSendPushNotificationFromTemplate(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementSendPushNotificationFromTemplateRequestWrapper<> request;
    FillSendPushNotificationFromTemplateRequest(request);
    LogSendPushNotificationFromTemplateRequest(&request.Model(), "TestAccountManagementServerSendPushNotificationFromTemplate");
    HRESULT hr = PFAccountManagementServerSendPushNotificationFromTemplateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerSendPushNotificationFromTemplateAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUnlinkPSNAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerUnlinkPSNAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerUnlinkPSNAccountRequestWrapper<> request;
    FillServerUnlinkPSNAccountRequest(request);
    LogServerUnlinkPSNAccountRequest(&request.Model(), "TestAccountManagementServerUnlinkPSNAccount");
    HRESULT hr = PFAccountManagementServerUnlinkPSNAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerUnlinkPSNAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUnlinkServerCustomId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerUnlinkServerCustomId(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementUnlinkServerCustomIdRequestWrapper<> request;
    FillUnlinkServerCustomIdRequest(request);
    LogUnlinkServerCustomIdRequest(&request.Model(), "TestAccountManagementServerUnlinkServerCustomId");
    HRESULT hr = PFAccountManagementServerUnlinkServerCustomIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerUnlinkServerCustomIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUnlinkXboxAccount

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerUnlinkXboxAccount(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerUnlinkXboxAccountRequestWrapper<> request;
    FillServerUnlinkXboxAccountRequest(request);
    LogServerUnlinkXboxAccountRequest(&request.Model(), "TestAccountManagementServerUnlinkXboxAccount");
    HRESULT hr = PFAccountManagementServerUnlinkXboxAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerUnlinkXboxAccountAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateAvatarUrl

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerUpdateAvatarUrl(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAccountManagementServerUpdateAvatarUrlRequestWrapper<> request;
    FillServerUpdateAvatarUrlRequest(request);
    LogServerUpdateAvatarUrlRequest(&request.Model(), "TestAccountManagementServerUpdateAvatarUrl");
    HRESULT hr = PFAccountManagementServerUpdateAvatarUrlAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerUpdateAvatarUrlAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateBans

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAccountManagementTests::TestAccountManagementServerUpdateBans(TestContext& testContext)
{
    struct ServerUpdateBansResultHolderStruct : public UpdateBansResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerUpdateBansGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAccountManagementServerUpdateBansGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAccountManagementUpdateBansResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAccountManagementUpdateBansResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateBansResultHolderStruct>>(testContext);

    PFAccountManagementUpdateBansRequestWrapper<> request;
    FillUpdateBansRequest(request);
    LogUpdateBansRequest(&request.Model(), "TestAccountManagementServerUpdateBans");
    HRESULT hr = PFAccountManagementServerUpdateBansAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAccountManagementAccountManagementServerUpdateBansAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
