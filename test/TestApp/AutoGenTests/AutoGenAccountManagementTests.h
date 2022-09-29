#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFAccountManagementDataModelWrappers.h>
#include "AutoGenAccountManagementResultHolders.h"

namespace PlayFabUnit
{

class AutoGenAccountManagementTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminBanUsers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminDeleteMasterPlayerAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminDeleteMembershipSubscription(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminDeletePlayer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminDeleteTitle(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminExportMasterPlayerData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminGetPlayedTitleList(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminGetPlayerIdFromAuthToken(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminGetPlayerProfile(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminGetUserAccountInfo(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminGetUserBans(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminResetPassword(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminRevokeAllBansForUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminRevokeBans(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminSendAccountRecoveryEmail(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminSetMembershipOverride(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminUpdateBans(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementAdminUpdateUserTitleDisplayName(TestContext& testContext);
#endif

    void TestAccountManagementClientAddGenericID(TestContext& testContext);

    void TestAccountManagementClientAddOrUpdateContactEmail(TestContext& testContext);

    void TestAccountManagementClientAddUsernamePassword(TestContext& testContext);

    void TestAccountManagementClientGetAccountInfo(TestContext& testContext);

    void TestAccountManagementClientGetPlayerCombinedInfo(TestContext& testContext);

    void TestAccountManagementClientGetPlayerProfile(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromFacebookIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIds(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromGameCenterIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromGenericIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromGoogleIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromGooglePlayGamesPlayerIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromKongregateIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromNintendoServiceAccountIds(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIds(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromPSNAccountIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromSteamIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromTwitchIDs(TestContext& testContext);

    void TestAccountManagementClientGetPlayFabIDsFromXboxLiveIDs(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkAndroidDeviceID(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkApple(TestContext& testContext);
#endif

    void TestAccountManagementClientLinkCustomID(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkFacebookAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkFacebookInstantGamesId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkGameCenterAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkGoogleAccount(TestContext& testContext);
#endif

    void TestAccountManagementClientLinkGooglePlayGamesServicesAccount(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkIOSDeviceID(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkKongregate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkNintendoServiceAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkNintendoSwitchDeviceId(TestContext& testContext);
#endif

    void TestAccountManagementClientLinkOpenIdConnect(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkPSNAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkSteamAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientLinkTwitch(TestContext& testContext);
#endif

    void TestAccountManagementClientLinkXboxAccount(TestContext& testContext);

    void TestAccountManagementClientRemoveContactEmail(TestContext& testContext);

    void TestAccountManagementClientRemoveGenericID(TestContext& testContext);

    void TestAccountManagementClientReportPlayer(TestContext& testContext);

    void TestAccountManagementClientSendAccountRecoveryEmail(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkAndroidDeviceID(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkApple(TestContext& testContext);
#endif

    void TestAccountManagementClientUnlinkCustomID(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkFacebookAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkFacebookInstantGamesId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkGameCenterAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkGoogleAccount(TestContext& testContext);
#endif

    void TestAccountManagementClientUnlinkGooglePlayGamesServicesAccount(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkIOSDeviceID(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkKongregate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkNintendoServiceAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkNintendoSwitchDeviceId(TestContext& testContext);
#endif

    void TestAccountManagementClientUnlinkOpenIdConnect(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkPSNAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkSteamAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementClientUnlinkTwitch(TestContext& testContext);
#endif

    void TestAccountManagementClientUnlinkXboxAccount(TestContext& testContext);

    void TestAccountManagementClientUpdateAvatarUrl(TestContext& testContext);

    void TestAccountManagementClientUpdateUserTitleDisplayName(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerAddGenericID(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerBanUsers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerDeletePlayer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayerCombinedInfo(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayerProfile(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromFacebookIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIds(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromGenericIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromNintendoServiceAccountIds(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIds(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromPSNAccountIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromSteamIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromTwitchIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromXboxLiveIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetServerCustomIDsFromPlayFabIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetUserAccountInfo(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetUserBans(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerLinkNintendoServiceAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerLinkNintendoSwitchDeviceId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerLinkPSNAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerLinkServerCustomId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerLinkXboxAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerRemoveGenericID(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerRevokeAllBansForUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerRevokeBans(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerSendCustomAccountRecoveryEmail(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerSendEmailFromTemplate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUnlinkNintendoServiceAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUnlinkNintendoSwitchDeviceId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUnlinkPSNAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUnlinkServerCustomId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUnlinkXboxAccount(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUpdateAvatarUrl(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerUpdateBans(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogBanUsersRequest(PFAccountManagementBanUsersRequest const* request, const char* testName);
    static HRESULT LogBanUsersResult(PFAccountManagementBanUsersResult const* result);
    static void LogDeleteMasterPlayerAccountRequest(PFAccountManagementDeleteMasterPlayerAccountRequest const* request, const char* testName);
    static HRESULT LogDeleteMasterPlayerAccountResult(PFAccountManagementDeleteMasterPlayerAccountResult const* result);
    static void LogDeleteMembershipSubscriptionRequest(PFAccountManagementDeleteMembershipSubscriptionRequest const* request, const char* testName);
    static void LogDeletePlayerRequest(PFAccountManagementDeletePlayerRequest const* request, const char* testName);
    static void LogExportMasterPlayerDataRequest(PFAccountManagementExportMasterPlayerDataRequest const* request, const char* testName);
    static HRESULT LogExportMasterPlayerDataResult(PFAccountManagementExportMasterPlayerDataResult const* result);
    static void LogGetPlayedTitleListRequest(PFAccountManagementGetPlayedTitleListRequest const* request, const char* testName);
    static HRESULT LogGetPlayedTitleListResult(PFAccountManagementGetPlayedTitleListResult const* result);
    static void LogGetPlayerIdFromAuthTokenRequest(PFAccountManagementGetPlayerIdFromAuthTokenRequest const* request, const char* testName);
    static HRESULT LogGetPlayerIdFromAuthTokenResult(PFAccountManagementGetPlayerIdFromAuthTokenResult const* result);
    static void LogGetPlayerProfileRequest(PFAccountManagementGetPlayerProfileRequest const* request, const char* testName);
    static HRESULT LogGetPlayerProfileResult(PFAccountManagementGetPlayerProfileResult const* result);
    static void LogLookupUserAccountInfoRequest(PFAccountManagementLookupUserAccountInfoRequest const* request, const char* testName);
    static HRESULT LogLookupUserAccountInfoResult(PFAccountManagementLookupUserAccountInfoResult const* result);
    static void LogGetUserBansRequest(PFAccountManagementGetUserBansRequest const* request, const char* testName);
    static HRESULT LogGetUserBansResult(PFAccountManagementGetUserBansResult const* result);
    static void LogResetPasswordRequest(PFAccountManagementResetPasswordRequest const* request, const char* testName);
    static void LogRevokeAllBansForUserRequest(PFAccountManagementRevokeAllBansForUserRequest const* request, const char* testName);
    static HRESULT LogRevokeAllBansForUserResult(PFAccountManagementRevokeAllBansForUserResult const* result);
    static void LogRevokeBansRequest(PFAccountManagementRevokeBansRequest const* request, const char* testName);
    static HRESULT LogRevokeBansResult(PFAccountManagementRevokeBansResult const* result);
    static void LogAdminSendAccountRecoveryEmailRequest(PFAccountManagementAdminSendAccountRecoveryEmailRequest const* request, const char* testName);
    static void LogSetMembershipOverrideRequest(PFAccountManagementSetMembershipOverrideRequest const* request, const char* testName);
    static void LogUpdateBansRequest(PFAccountManagementUpdateBansRequest const* request, const char* testName);
    static HRESULT LogUpdateBansResult(PFAccountManagementUpdateBansResult const* result);
    static void LogAdminUpdateUserTitleDisplayNameRequest(PFAccountManagementAdminUpdateUserTitleDisplayNameRequest const* request, const char* testName);
    static HRESULT LogUpdateUserTitleDisplayNameResult(PFAccountManagementUpdateUserTitleDisplayNameResult const* result);
    static void LogClientAddGenericIDRequest(PFAccountManagementClientAddGenericIDRequest const* request, const char* testName);
    static void LogAddOrUpdateContactEmailRequest(PFAccountManagementAddOrUpdateContactEmailRequest const* request, const char* testName);
    static void LogAddUsernamePasswordRequest(PFAccountManagementAddUsernamePasswordRequest const* request, const char* testName);
    static HRESULT LogAddUsernamePasswordResult(PFAccountManagementAddUsernamePasswordResult const* result);
    static void LogGetAccountInfoRequest(PFAccountManagementGetAccountInfoRequest const* request, const char* testName);
    static HRESULT LogGetAccountInfoResult(PFAccountManagementGetAccountInfoResult const* result);
    static void LogGetPlayerCombinedInfoRequest(PFAccountManagementGetPlayerCombinedInfoRequest const* request, const char* testName);
    static HRESULT LogGetPlayerCombinedInfoResult(PFAccountManagementGetPlayerCombinedInfoResult const* result);
    static void LogGetPlayFabIDsFromFacebookIDsRequest(PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromFacebookIDsResult(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult const* result);
    static void LogGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromFacebookInstantGamesIdsResult(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult const* result);
    static void LogGetPlayFabIDsFromGameCenterIDsRequest(PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromGameCenterIDsResult(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult const* result);
    static void LogGetPlayFabIDsFromGenericIDsRequest(PFAccountManagementGetPlayFabIDsFromGenericIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromGenericIDsResult(PFAccountManagementGetPlayFabIDsFromGenericIDsResult const* result);
    static void LogGetPlayFabIDsFromGoogleIDsRequest(PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromGoogleIDsResult(PFAccountManagementGetPlayFabIDsFromGoogleIDsResult const* result);
    static void LogGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest(PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult(PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult const* result);
    static void LogGetPlayFabIDsFromKongregateIDsRequest(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromKongregateIDsResult(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult const* result);
    static void LogGetPlayFabIDsFromNintendoServiceAccountIdsRequest(PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromNintendoServiceAccountIdsResult(PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult const* result);
    static void LogGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult const* result);
    static void LogGetPlayFabIDsFromPSNAccountIDsRequest(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromPSNAccountIDsResult(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult const* result);
    static void LogGetPlayFabIDsFromSteamIDsRequest(PFAccountManagementGetPlayFabIDsFromSteamIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromSteamIDsResult(PFAccountManagementGetPlayFabIDsFromSteamIDsResult const* result);
    static void LogGetPlayFabIDsFromTwitchIDsRequest(PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromTwitchIDsResult(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult const* result);
    static void LogGetPlayFabIDsFromXboxLiveIDsRequest(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromXboxLiveIDsResult(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult const* result);
    static void LogLinkAndroidDeviceIDRequest(PFAccountManagementLinkAndroidDeviceIDRequest const* request, const char* testName);
    static void LogLinkAppleRequest(PFAccountManagementLinkAppleRequest const* request, const char* testName);
    static void LogLinkCustomIDRequest(PFAccountManagementLinkCustomIDRequest const* request, const char* testName);
    static void LogLinkFacebookAccountRequest(PFAccountManagementLinkFacebookAccountRequest const* request, const char* testName);
    static void LogLinkFacebookInstantGamesIdRequest(PFAccountManagementLinkFacebookInstantGamesIdRequest const* request, const char* testName);
    static void LogLinkGameCenterAccountRequest(PFAccountManagementLinkGameCenterAccountRequest const* request, const char* testName);
    static void LogLinkGoogleAccountRequest(PFAccountManagementLinkGoogleAccountRequest const* request, const char* testName);
    static void LogLinkGooglePlayGamesServicesAccountRequest(PFAccountManagementLinkGooglePlayGamesServicesAccountRequest const* request, const char* testName);
    static void LogLinkIOSDeviceIDRequest(PFAccountManagementLinkIOSDeviceIDRequest const* request, const char* testName);
    static void LogLinkKongregateAccountRequest(PFAccountManagementLinkKongregateAccountRequest const* request, const char* testName);
    static void LogClientLinkNintendoServiceAccountRequest(PFAccountManagementClientLinkNintendoServiceAccountRequest const* request, const char* testName);
    static void LogClientLinkNintendoSwitchDeviceIdRequest(PFAccountManagementClientLinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void LogLinkOpenIdConnectRequest(PFAccountManagementLinkOpenIdConnectRequest const* request, const char* testName);
    static void LogClientLinkPSNAccountRequest(PFAccountManagementClientLinkPSNAccountRequest const* request, const char* testName);
    static void LogLinkSteamAccountRequest(PFAccountManagementLinkSteamAccountRequest const* request, const char* testName);
    static void LogLinkTwitchAccountRequest(PFAccountManagementLinkTwitchAccountRequest const* request, const char* testName);
    static void LogClientLinkXboxAccountRequest(PFAccountManagementClientLinkXboxAccountRequest const* request, const char* testName);
    static void LogRemoveContactEmailRequest(PFAccountManagementRemoveContactEmailRequest const* request, const char* testName);
    static void LogClientRemoveGenericIDRequest(PFAccountManagementClientRemoveGenericIDRequest const* request, const char* testName);
    static void LogReportPlayerClientRequest(PFAccountManagementReportPlayerClientRequest const* request, const char* testName);
    static HRESULT LogReportPlayerClientResult(PFAccountManagementReportPlayerClientResult const* result);
    static void LogClientSendAccountRecoveryEmailRequest(PFAccountManagementClientSendAccountRecoveryEmailRequest const* request, const char* testName);
    static void LogUnlinkAndroidDeviceIDRequest(PFAccountManagementUnlinkAndroidDeviceIDRequest const* request, const char* testName);
    static void LogUnlinkAppleRequest(PFAccountManagementUnlinkAppleRequest const* request, const char* testName);
    static void LogUnlinkCustomIDRequest(PFAccountManagementUnlinkCustomIDRequest const* request, const char* testName);
    static void LogUnlinkFacebookAccountRequest(PFAccountManagementUnlinkFacebookAccountRequest const* request, const char* testName);
    static void LogUnlinkFacebookInstantGamesIdRequest(PFAccountManagementUnlinkFacebookInstantGamesIdRequest const* request, const char* testName);
    static void LogUnlinkGameCenterAccountRequest(PFAccountManagementUnlinkGameCenterAccountRequest const* request, const char* testName);
    static void LogUnlinkGoogleAccountRequest(PFAccountManagementUnlinkGoogleAccountRequest const* request, const char* testName);
    static void LogUnlinkGooglePlayGamesServicesAccountRequest(PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequest const* request, const char* testName);
    static void LogUnlinkIOSDeviceIDRequest(PFAccountManagementUnlinkIOSDeviceIDRequest const* request, const char* testName);
    static void LogUnlinkKongregateAccountRequest(PFAccountManagementUnlinkKongregateAccountRequest const* request, const char* testName);
    static void LogClientUnlinkNintendoServiceAccountRequest(PFAccountManagementClientUnlinkNintendoServiceAccountRequest const* request, const char* testName);
    static void LogClientUnlinkNintendoSwitchDeviceIdRequest(PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void LogUnlinkOpenIdConnectRequest(PFAccountManagementUnlinkOpenIdConnectRequest const* request, const char* testName);
    static void LogClientUnlinkPSNAccountRequest(PFAccountManagementClientUnlinkPSNAccountRequest const* request, const char* testName);
    static void LogUnlinkSteamAccountRequest(PFAccountManagementUnlinkSteamAccountRequest const* request, const char* testName);
    static void LogUnlinkTwitchAccountRequest(PFAccountManagementUnlinkTwitchAccountRequest const* request, const char* testName);
    static void LogClientUnlinkXboxAccountRequest(PFAccountManagementClientUnlinkXboxAccountRequest const* request, const char* testName);
    static void LogClientUpdateAvatarUrlRequest(PFAccountManagementClientUpdateAvatarUrlRequest const* request, const char* testName);
    static void LogClientUpdateUserTitleDisplayNameRequest(PFAccountManagementClientUpdateUserTitleDisplayNameRequest const* request, const char* testName);
    static void LogServerAddGenericIDRequest(PFAccountManagementServerAddGenericIDRequest const* request, const char* testName);
    static void LogGetServerCustomIDsFromPlayFabIDsRequest(PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest const* request, const char* testName);
    static HRESULT LogGetServerCustomIDsFromPlayFabIDsResult(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult const* result);
    static void LogGetUserAccountInfoRequest(PFAccountManagementGetUserAccountInfoRequest const* request, const char* testName);
    static HRESULT LogGetUserAccountInfoResult(PFAccountManagementGetUserAccountInfoResult const* result);
    static void LogServerLinkNintendoServiceAccountRequest(PFAccountManagementServerLinkNintendoServiceAccountRequest const* request, const char* testName);
    static void LogServerLinkNintendoSwitchDeviceIdRequest(PFAccountManagementServerLinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void LogServerLinkPSNAccountRequest(PFAccountManagementServerLinkPSNAccountRequest const* request, const char* testName);
    static void LogLinkServerCustomIdRequest(PFAccountManagementLinkServerCustomIdRequest const* request, const char* testName);
    static void LogServerLinkXboxAccountRequest(PFAccountManagementServerLinkXboxAccountRequest const* request, const char* testName);
    static void LogServerRemoveGenericIDRequest(PFAccountManagementServerRemoveGenericIDRequest const* request, const char* testName);
    static void LogSendCustomAccountRecoveryEmailRequest(PFAccountManagementSendCustomAccountRecoveryEmailRequest const* request, const char* testName);
    static void LogSendEmailFromTemplateRequest(PFAccountManagementSendEmailFromTemplateRequest const* request, const char* testName);
    static void LogServerUnlinkNintendoServiceAccountRequest(PFAccountManagementServerUnlinkNintendoServiceAccountRequest const* request, const char* testName);
    static void LogServerUnlinkNintendoSwitchDeviceIdRequest(PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void LogServerUnlinkPSNAccountRequest(PFAccountManagementServerUnlinkPSNAccountRequest const* request, const char* testName);
    static void LogUnlinkServerCustomIdRequest(PFAccountManagementUnlinkServerCustomIdRequest const* request, const char* testName);
    static void LogServerUnlinkXboxAccountRequest(PFAccountManagementServerUnlinkXboxAccountRequest const* request, const char* testName);
    static void LogServerUpdateAvatarUrlRequest(PFAccountManagementServerUpdateAvatarUrlRequest const* request, const char* testName);

    void FillAdminBanUsersRequest(PlayFab::Wrappers::PFAccountManagementBanUsersRequestWrapper<>& request);
    static HRESULT ValidateAdminBanUsersResponse(PFAccountManagementBanUsersResult* result);

    void FillAdminDeleteMasterPlayerAccountRequest(PlayFab::Wrappers::PFAccountManagementDeleteMasterPlayerAccountRequestWrapper<>& request);
    static HRESULT ValidateAdminDeleteMasterPlayerAccountResponse(PFAccountManagementDeleteMasterPlayerAccountResult* result);

    void FillAdminDeleteMembershipSubscriptionRequest(PlayFab::Wrappers::PFAccountManagementDeleteMembershipSubscriptionRequestWrapper<>& request);

    void FillAdminDeletePlayerRequest(PlayFab::Wrappers::PFAccountManagementDeletePlayerRequestWrapper<>& request);


    void FillAdminExportMasterPlayerDataRequest(PlayFab::Wrappers::PFAccountManagementExportMasterPlayerDataRequestWrapper<>& request);
    static HRESULT ValidateAdminExportMasterPlayerDataResponse(PFAccountManagementExportMasterPlayerDataResult* result);

    void FillAdminGetPlayedTitleListRequest(PlayFab::Wrappers::PFAccountManagementGetPlayedTitleListRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayedTitleListResponse(PFAccountManagementGetPlayedTitleListResult* result);

    void FillAdminGetPlayerIdFromAuthTokenRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerIdFromAuthTokenResponse(PFAccountManagementGetPlayerIdFromAuthTokenResult* result);

    void FillAdminGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerProfileResponse(PFAccountManagementGetPlayerProfileResult* result);

    void FillAdminGetUserAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementLookupUserAccountInfoRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserAccountInfoResponse(PFAccountManagementLookupUserAccountInfoResult* result);

    void FillAdminGetUserBansRequest(PlayFab::Wrappers::PFAccountManagementGetUserBansRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserBansResponse(PFAccountManagementGetUserBansResult* result);

    void FillAdminResetPasswordRequest(PlayFab::Wrappers::PFAccountManagementResetPasswordRequestWrapper<>& request);

    void FillAdminRevokeAllBansForUserRequest(PlayFab::Wrappers::PFAccountManagementRevokeAllBansForUserRequestWrapper<>& request);
    static HRESULT ValidateAdminRevokeAllBansForUserResponse(PFAccountManagementRevokeAllBansForUserResult* result);

    void FillAdminRevokeBansRequest(PlayFab::Wrappers::PFAccountManagementRevokeBansRequestWrapper<>& request);
    static HRESULT ValidateAdminRevokeBansResponse(PFAccountManagementRevokeBansResult* result);

    void FillAdminSendAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper<>& request);

    void FillAdminSetMembershipOverrideRequest(PlayFab::Wrappers::PFAccountManagementSetMembershipOverrideRequestWrapper<>& request);

    void FillAdminUpdateBansRequest(PlayFab::Wrappers::PFAccountManagementUpdateBansRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateBansResponse(PFAccountManagementUpdateBansResult* result);

    void FillAdminUpdateUserTitleDisplayNameRequest(PlayFab::Wrappers::PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserTitleDisplayNameResponse(PFAccountManagementUpdateUserTitleDisplayNameResult* result);

    void FillClientAddGenericIDRequest(PlayFab::Wrappers::PFAccountManagementClientAddGenericIDRequestWrapper<>& request);

    void FillClientAddOrUpdateContactEmailRequest(PlayFab::Wrappers::PFAccountManagementAddOrUpdateContactEmailRequestWrapper<>& request);

    void FillClientAddUsernamePasswordRequest(PlayFab::Wrappers::PFAccountManagementAddUsernamePasswordRequestWrapper<>& request);
    static HRESULT ValidateClientAddUsernamePasswordResponse(PFAccountManagementAddUsernamePasswordResult* result);

    void FillClientGetAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementGetAccountInfoRequestWrapper<>& request);
    static HRESULT ValidateClientGetAccountInfoResponse(PFAccountManagementGetAccountInfoResult* result);

    void FillClientGetPlayerCombinedInfoRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerCombinedInfoRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerCombinedInfoResponse(PFAccountManagementGetPlayerCombinedInfoResult* result);

    void FillClientGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerProfileResponse(PFAccountManagementGetPlayerProfileResult* result);

    void FillClientGetPlayFabIDsFromFacebookIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromFacebookIDsResponse(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult* result);

    void FillClientGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromFacebookInstantGamesIdsResponse(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult* result);

    void FillClientGetPlayFabIDsFromGameCenterIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGameCenterIDsResponse(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult* result);

    void FillClientGetPlayFabIDsFromGenericIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGenericIDsResponse(PFAccountManagementGetPlayFabIDsFromGenericIDsResult* result);

    void FillClientGetPlayFabIDsFromGoogleIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGoogleIDsResponse(PFAccountManagementGetPlayFabIDsFromGoogleIDsResult* result);

    void FillClientGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGooglePlayGamesPlayerIDsResponse(PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult* result);

    void FillClientGetPlayFabIDsFromKongregateIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromKongregateIDsResponse(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult* result);

    void FillClientGetPlayFabIDsFromNintendoServiceAccountIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromNintendoServiceAccountIdsResponse(PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult* result);

    void FillClientGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResponse(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult* result);

    void FillClientGetPlayFabIDsFromPSNAccountIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromPSNAccountIDsResponse(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult* result);

    void FillClientGetPlayFabIDsFromSteamIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromSteamIDsResponse(PFAccountManagementGetPlayFabIDsFromSteamIDsResult* result);

    void FillClientGetPlayFabIDsFromTwitchIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromTwitchIDsResponse(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult* result);

    void FillClientGetPlayFabIDsFromXboxLiveIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromXboxLiveIDsResponse(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult* result);

    void FillClientLinkAndroidDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementLinkAndroidDeviceIDRequestWrapper<>& request);

    void FillClientLinkAppleRequest(PlayFab::Wrappers::PFAccountManagementLinkAppleRequestWrapper<>& request);

    void FillClientLinkCustomIDRequest(PlayFab::Wrappers::PFAccountManagementLinkCustomIDRequestWrapper<>& request);

    void FillClientLinkFacebookAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkFacebookAccountRequestWrapper<>& request);

    void FillClientLinkFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper<>& request);

    void FillClientLinkGameCenterAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGameCenterAccountRequestWrapper<>& request);

    void FillClientLinkGoogleAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGoogleAccountRequestWrapper<>& request);

    void FillClientLinkGooglePlayGamesServicesAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGooglePlayGamesServicesAccountRequestWrapper<>& request);

    void FillClientLinkIOSDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementLinkIOSDeviceIDRequestWrapper<>& request);

    void FillClientLinkKongregateRequest(PlayFab::Wrappers::PFAccountManagementLinkKongregateAccountRequestWrapper<>& request);

    void FillClientLinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkNintendoServiceAccountRequestWrapper<>& request);

    void FillClientLinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementClientLinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    void FillClientLinkOpenIdConnectRequest(PlayFab::Wrappers::PFAccountManagementLinkOpenIdConnectRequestWrapper<>& request);

    void FillClientLinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkPSNAccountRequestWrapper<>& request);

    void FillClientLinkSteamAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkSteamAccountRequestWrapper<>& request);

    void FillClientLinkTwitchRequest(PlayFab::Wrappers::PFAccountManagementLinkTwitchAccountRequestWrapper<>& request);

    void FillClientLinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkXboxAccountRequestWrapper<>& request);

    void FillClientRemoveContactEmailRequest(PlayFab::Wrappers::PFAccountManagementRemoveContactEmailRequestWrapper<>& request);

    void FillClientRemoveGenericIDRequest(PlayFab::Wrappers::PFAccountManagementClientRemoveGenericIDRequestWrapper<>& request);

    void FillClientReportPlayerRequest(PlayFab::Wrappers::PFAccountManagementReportPlayerClientRequestWrapper<>& request);
    static HRESULT ValidateClientReportPlayerResponse(PFAccountManagementReportPlayerClientResult* result);

    void FillClientSendAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper<>& request);

    void FillClientUnlinkAndroidDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper<>& request);

    void FillClientUnlinkAppleRequest(PlayFab::Wrappers::PFAccountManagementUnlinkAppleRequestWrapper<>& request);

    void FillClientUnlinkCustomIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkCustomIDRequestWrapper<>& request);

    void FillClientUnlinkFacebookAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkFacebookAccountRequestWrapper<>& request);

    void FillClientUnlinkFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper<>& request);

    void FillClientUnlinkGameCenterAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGameCenterAccountRequestWrapper<>& request);

    void FillClientUnlinkGoogleAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGoogleAccountRequestWrapper<>& request);

    void FillClientUnlinkGooglePlayGamesServicesAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequestWrapper<>& request);

    void FillClientUnlinkIOSDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkIOSDeviceIDRequestWrapper<>& request);

    void FillClientUnlinkKongregateRequest(PlayFab::Wrappers::PFAccountManagementUnlinkKongregateAccountRequestWrapper<>& request);

    void FillClientUnlinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkNintendoServiceAccountRequestWrapper<>& request);

    void FillClientUnlinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    void FillClientUnlinkOpenIdConnectRequest(PlayFab::Wrappers::PFAccountManagementUnlinkOpenIdConnectRequestWrapper<>& request);

    void FillClientUnlinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkPSNAccountRequestWrapper<>& request);

    void FillClientUnlinkSteamAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkSteamAccountRequestWrapper<>& request);

    void FillClientUnlinkTwitchRequest(PlayFab::Wrappers::PFAccountManagementUnlinkTwitchAccountRequestWrapper<>& request);

    void FillClientUnlinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkXboxAccountRequestWrapper<>& request);

    void FillClientUpdateAvatarUrlRequest(PlayFab::Wrappers::PFAccountManagementClientUpdateAvatarUrlRequestWrapper<>& request);

    void FillClientUpdateUserTitleDisplayNameRequest(PlayFab::Wrappers::PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper<>& request);
    static HRESULT ValidateClientUpdateUserTitleDisplayNameResponse(PFAccountManagementUpdateUserTitleDisplayNameResult* result);

    void FillServerAddGenericIDRequest(PlayFab::Wrappers::PFAccountManagementServerAddGenericIDRequestWrapper<>& request);

    void FillServerBanUsersRequest(PlayFab::Wrappers::PFAccountManagementBanUsersRequestWrapper<>& request);
    static HRESULT ValidateServerBanUsersResponse(PFAccountManagementBanUsersResult* result);

    void FillServerDeletePlayerRequest(PlayFab::Wrappers::PFAccountManagementDeletePlayerRequestWrapper<>& request);

    void FillServerGetPlayerCombinedInfoRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerCombinedInfoRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerCombinedInfoResponse(PFAccountManagementGetPlayerCombinedInfoResult* result);

    void FillServerGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerProfileResponse(PFAccountManagementGetPlayerProfileResult* result);

    void FillServerGetPlayFabIDsFromFacebookIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromFacebookIDsResponse(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult* result);

    void FillServerGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromFacebookInstantGamesIdsResponse(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult* result);

    void FillServerGetPlayFabIDsFromGenericIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromGenericIDsResponse(PFAccountManagementGetPlayFabIDsFromGenericIDsResult* result);

    void FillServerGetPlayFabIDsFromNintendoServiceAccountIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromNintendoServiceAccountIdsResponse(PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult* result);

    void FillServerGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResponse(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult* result);

    void FillServerGetPlayFabIDsFromPSNAccountIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromPSNAccountIDsResponse(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult* result);

    void FillServerGetPlayFabIDsFromSteamIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromSteamIDsResponse(PFAccountManagementGetPlayFabIDsFromSteamIDsResult* result);

    void FillServerGetPlayFabIDsFromTwitchIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromTwitchIDsResponse(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult* result);

    void FillServerGetPlayFabIDsFromXboxLiveIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromXboxLiveIDsResponse(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult* result);

    void FillServerGetServerCustomIDsFromPlayFabIDsRequest(PlayFab::Wrappers::PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetServerCustomIDsFromPlayFabIDsResponse(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult* result);

    void FillServerGetUserAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementGetUserAccountInfoRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserAccountInfoResponse(PFAccountManagementGetUserAccountInfoResult* result);

    void FillServerGetUserBansRequest(PlayFab::Wrappers::PFAccountManagementGetUserBansRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserBansResponse(PFAccountManagementGetUserBansResult* result);

    void FillServerLinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkNintendoServiceAccountRequestWrapper<>& request);

    void FillServerLinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementServerLinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    void FillServerLinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkPSNAccountRequestWrapper<>& request);

    void FillServerLinkServerCustomIdRequest(PlayFab::Wrappers::PFAccountManagementLinkServerCustomIdRequestWrapper<>& request);

    void FillServerLinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkXboxAccountRequestWrapper<>& request);

    void FillServerRemoveGenericIDRequest(PlayFab::Wrappers::PFAccountManagementServerRemoveGenericIDRequestWrapper<>& request);

    void FillServerRevokeAllBansForUserRequest(PlayFab::Wrappers::PFAccountManagementRevokeAllBansForUserRequestWrapper<>& request);
    static HRESULT ValidateServerRevokeAllBansForUserResponse(PFAccountManagementRevokeAllBansForUserResult* result);

    void FillServerRevokeBansRequest(PlayFab::Wrappers::PFAccountManagementRevokeBansRequestWrapper<>& request);
    static HRESULT ValidateServerRevokeBansResponse(PFAccountManagementRevokeBansResult* result);

    void FillServerSendCustomAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper<>& request);

    void FillServerSendEmailFromTemplateRequest(PlayFab::Wrappers::PFAccountManagementSendEmailFromTemplateRequestWrapper<>& request);

    void FillServerUnlinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkNintendoServiceAccountRequestWrapper<>& request);

    void FillServerUnlinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    void FillServerUnlinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkPSNAccountRequestWrapper<>& request);

    void FillServerUnlinkServerCustomIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkServerCustomIdRequestWrapper<>& request);

    void FillServerUnlinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkXboxAccountRequestWrapper<>& request);

    void FillServerUpdateAvatarUrlRequest(PlayFab::Wrappers::PFAccountManagementServerUpdateAvatarUrlRequestWrapper<>& request);

    void FillServerUpdateBansRequest(PlayFab::Wrappers::PFAccountManagementUpdateBansRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateBansResponse(PFAccountManagementUpdateBansResult* result);

    struct AccountManagementTestData
    {
        ~AccountManagementTestData() = default;

    };

    static AccountManagementTestData testData;

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
