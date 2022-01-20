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

    void TestAccountManagementClientGetPlayFabIDsFromKongregateIDs(TestContext& testContext);

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
    void TestAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIds(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromPSNAccountIDs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerGetPlayFabIDsFromSteamIDs(TestContext& testContext);
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
    static void LogGetPlayFabIDsFromKongregateIDsRequest(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest const* request, const char* testName);
    static HRESULT LogGetPlayFabIDsFromKongregateIDsResult(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult const* result);
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
    static void LogLinkIOSDeviceIDRequest(PFAccountManagementLinkIOSDeviceIDRequest const* request, const char* testName);
    static void LogLinkKongregateAccountRequest(PFAccountManagementLinkKongregateAccountRequest const* request, const char* testName);
    static void LogLinkNintendoServiceAccountRequest(PFAccountManagementLinkNintendoServiceAccountRequest const* request, const char* testName);
    static void LogLinkNintendoSwitchDeviceIdRequest(PFAccountManagementLinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
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
    static void LogUnlinkIOSDeviceIDRequest(PFAccountManagementUnlinkIOSDeviceIDRequest const* request, const char* testName);
    static void LogUnlinkKongregateAccountRequest(PFAccountManagementUnlinkKongregateAccountRequest const* request, const char* testName);
    static void LogUnlinkNintendoServiceAccountRequest(PFAccountManagementUnlinkNintendoServiceAccountRequest const* request, const char* testName);
    static void LogUnlinkNintendoSwitchDeviceIdRequest(PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
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
    static void LogServerLinkPSNAccountRequest(PFAccountManagementServerLinkPSNAccountRequest const* request, const char* testName);
    static void LogLinkServerCustomIdRequest(PFAccountManagementLinkServerCustomIdRequest const* request, const char* testName);
    static void LogServerLinkXboxAccountRequest(PFAccountManagementServerLinkXboxAccountRequest const* request, const char* testName);
    static void LogServerRemoveGenericIDRequest(PFAccountManagementServerRemoveGenericIDRequest const* request, const char* testName);
    static void LogSendCustomAccountRecoveryEmailRequest(PFAccountManagementSendCustomAccountRecoveryEmailRequest const* request, const char* testName);
    static void LogSendEmailFromTemplateRequest(PFAccountManagementSendEmailFromTemplateRequest const* request, const char* testName);
    static void LogServerUnlinkPSNAccountRequest(PFAccountManagementServerUnlinkPSNAccountRequest const* request, const char* testName);
    static void LogUnlinkServerCustomIdRequest(PFAccountManagementUnlinkServerCustomIdRequest const* request, const char* testName);
    static void LogServerUnlinkXboxAccountRequest(PFAccountManagementServerUnlinkXboxAccountRequest const* request, const char* testName);
    static void LogServerUpdateAvatarUrlRequest(PFAccountManagementServerUpdateAvatarUrlRequest const* request, const char* testName);

    static void FillAdminBanUsersRequest(PlayFab::Wrappers::PFAccountManagementBanUsersRequestWrapper<>& request);
    static HRESULT ValidateAdminBanUsersResponse(PFAccountManagementBanUsersResult* result);

    static void FillAdminDeleteMasterPlayerAccountRequest(PlayFab::Wrappers::PFAccountManagementDeleteMasterPlayerAccountRequestWrapper<>& request);
    static HRESULT ValidateAdminDeleteMasterPlayerAccountResponse(PFAccountManagementDeleteMasterPlayerAccountResult* result);

    static void FillAdminDeleteMembershipSubscriptionRequest(PlayFab::Wrappers::PFAccountManagementDeleteMembershipSubscriptionRequestWrapper<>& request);

    static void FillAdminDeletePlayerRequest(PlayFab::Wrappers::PFAccountManagementDeletePlayerRequestWrapper<>& request);


    static void FillAdminExportMasterPlayerDataRequest(PlayFab::Wrappers::PFAccountManagementExportMasterPlayerDataRequestWrapper<>& request);
    static HRESULT ValidateAdminExportMasterPlayerDataResponse(PFAccountManagementExportMasterPlayerDataResult* result);

    static void FillAdminGetPlayedTitleListRequest(PlayFab::Wrappers::PFAccountManagementGetPlayedTitleListRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayedTitleListResponse(PFAccountManagementGetPlayedTitleListResult* result);

    static void FillAdminGetPlayerIdFromAuthTokenRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerIdFromAuthTokenResponse(PFAccountManagementGetPlayerIdFromAuthTokenResult* result);

    static void FillAdminGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerProfileResponse(PFAccountManagementGetPlayerProfileResult* result);

    static void FillAdminGetUserAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementLookupUserAccountInfoRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserAccountInfoResponse(PFAccountManagementLookupUserAccountInfoResult* result);

    static void FillAdminGetUserBansRequest(PlayFab::Wrappers::PFAccountManagementGetUserBansRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserBansResponse(PFAccountManagementGetUserBansResult* result);

    static void FillAdminResetPasswordRequest(PlayFab::Wrappers::PFAccountManagementResetPasswordRequestWrapper<>& request);

    static void FillAdminRevokeAllBansForUserRequest(PlayFab::Wrappers::PFAccountManagementRevokeAllBansForUserRequestWrapper<>& request);
    static HRESULT ValidateAdminRevokeAllBansForUserResponse(PFAccountManagementRevokeAllBansForUserResult* result);

    static void FillAdminRevokeBansRequest(PlayFab::Wrappers::PFAccountManagementRevokeBansRequestWrapper<>& request);
    static HRESULT ValidateAdminRevokeBansResponse(PFAccountManagementRevokeBansResult* result);

    static void FillAdminSendAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper<>& request);

    static void FillAdminSetMembershipOverrideRequest(PlayFab::Wrappers::PFAccountManagementSetMembershipOverrideRequestWrapper<>& request);

    static void FillAdminUpdateBansRequest(PlayFab::Wrappers::PFAccountManagementUpdateBansRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateBansResponse(PFAccountManagementUpdateBansResult* result);

    static void FillAdminUpdateUserTitleDisplayNameRequest(PlayFab::Wrappers::PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserTitleDisplayNameResponse(PFAccountManagementUpdateUserTitleDisplayNameResult* result);

    static void FillClientAddGenericIDRequest(PlayFab::Wrappers::PFAccountManagementClientAddGenericIDRequestWrapper<>& request);

    static void FillClientAddOrUpdateContactEmailRequest(PlayFab::Wrappers::PFAccountManagementAddOrUpdateContactEmailRequestWrapper<>& request);

    static void FillClientAddUsernamePasswordRequest(PlayFab::Wrappers::PFAccountManagementAddUsernamePasswordRequestWrapper<>& request);
    static HRESULT ValidateClientAddUsernamePasswordResponse(PFAccountManagementAddUsernamePasswordResult* result);

    static void FillClientGetAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementGetAccountInfoRequestWrapper<>& request);
    static HRESULT ValidateClientGetAccountInfoResponse(PFAccountManagementGetAccountInfoResult* result);

    static void FillClientGetPlayerCombinedInfoRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerCombinedInfoRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerCombinedInfoResponse(PFAccountManagementGetPlayerCombinedInfoResult* result);

    static void FillClientGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayerProfileResponse(PFAccountManagementGetPlayerProfileResult* result);

    static void FillClientGetPlayFabIDsFromFacebookIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromFacebookIDsResponse(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult* result);

    static void FillClientGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromFacebookInstantGamesIdsResponse(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult* result);

    static void FillClientGetPlayFabIDsFromGameCenterIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGameCenterIDsResponse(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult* result);

    static void FillClientGetPlayFabIDsFromGenericIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGenericIDsResponse(PFAccountManagementGetPlayFabIDsFromGenericIDsResult* result);

    static void FillClientGetPlayFabIDsFromGoogleIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromGoogleIDsResponse(PFAccountManagementGetPlayFabIDsFromGoogleIDsResult* result);

    static void FillClientGetPlayFabIDsFromKongregateIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromKongregateIDsResponse(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult* result);

    static void FillClientGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromNintendoSwitchDeviceIdsResponse(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult* result);

    static void FillClientGetPlayFabIDsFromPSNAccountIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromPSNAccountIDsResponse(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult* result);

    static void FillClientGetPlayFabIDsFromSteamIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromSteamIDsResponse(PFAccountManagementGetPlayFabIDsFromSteamIDsResult* result);

    static void FillClientGetPlayFabIDsFromTwitchIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromTwitchIDsResponse(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult* result);

    static void FillClientGetPlayFabIDsFromXboxLiveIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<>& request);
    static HRESULT ValidateClientGetPlayFabIDsFromXboxLiveIDsResponse(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult* result);

    static void FillClientLinkAndroidDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementLinkAndroidDeviceIDRequestWrapper<>& request);

    static void FillClientLinkAppleRequest(PlayFab::Wrappers::PFAccountManagementLinkAppleRequestWrapper<>& request);

    static void FillClientLinkCustomIDRequest(PlayFab::Wrappers::PFAccountManagementLinkCustomIDRequestWrapper<>& request);

    static void FillClientLinkFacebookAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkFacebookAccountRequestWrapper<>& request);

    static void FillClientLinkFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper<>& request);

    static void FillClientLinkGameCenterAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGameCenterAccountRequestWrapper<>& request);

    static void FillClientLinkGoogleAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGoogleAccountRequestWrapper<>& request);

    static void FillClientLinkIOSDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementLinkIOSDeviceIDRequestWrapper<>& request);

    static void FillClientLinkKongregateRequest(PlayFab::Wrappers::PFAccountManagementLinkKongregateAccountRequestWrapper<>& request);

    static void FillClientLinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkNintendoServiceAccountRequestWrapper<>& request);

    static void FillClientLinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    static void FillClientLinkOpenIdConnectRequest(PlayFab::Wrappers::PFAccountManagementLinkOpenIdConnectRequestWrapper<>& request);

    static void FillClientLinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkPSNAccountRequestWrapper<>& request);

    static void FillClientLinkSteamAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkSteamAccountRequestWrapper<>& request);

    static void FillClientLinkTwitchRequest(PlayFab::Wrappers::PFAccountManagementLinkTwitchAccountRequestWrapper<>& request);

    static void FillClientLinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkXboxAccountRequestWrapper<>& request);

    static void FillClientRemoveContactEmailRequest(PlayFab::Wrappers::PFAccountManagementRemoveContactEmailRequestWrapper<>& request);

    static void FillClientRemoveGenericIDRequest(PlayFab::Wrappers::PFAccountManagementClientRemoveGenericIDRequestWrapper<>& request);

    static void FillClientReportPlayerRequest(PlayFab::Wrappers::PFAccountManagementReportPlayerClientRequestWrapper<>& request);
    static HRESULT ValidateClientReportPlayerResponse(PFAccountManagementReportPlayerClientResult* result);

    static void FillClientSendAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper<>& request);

    static void FillClientUnlinkAndroidDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper<>& request);

    static void FillClientUnlinkAppleRequest(PlayFab::Wrappers::PFAccountManagementUnlinkAppleRequestWrapper<>& request);

    static void FillClientUnlinkCustomIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkCustomIDRequestWrapper<>& request);

    static void FillClientUnlinkFacebookAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkFacebookAccountRequestWrapper<>& request);

    static void FillClientUnlinkFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper<>& request);

    static void FillClientUnlinkGameCenterAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGameCenterAccountRequestWrapper<>& request);

    static void FillClientUnlinkGoogleAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGoogleAccountRequestWrapper<>& request);

    static void FillClientUnlinkIOSDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkIOSDeviceIDRequestWrapper<>& request);

    static void FillClientUnlinkKongregateRequest(PlayFab::Wrappers::PFAccountManagementUnlinkKongregateAccountRequestWrapper<>& request);

    static void FillClientUnlinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper<>& request);

    static void FillClientUnlinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    static void FillClientUnlinkOpenIdConnectRequest(PlayFab::Wrappers::PFAccountManagementUnlinkOpenIdConnectRequestWrapper<>& request);

    static void FillClientUnlinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkPSNAccountRequestWrapper<>& request);

    static void FillClientUnlinkSteamAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkSteamAccountRequestWrapper<>& request);

    static void FillClientUnlinkTwitchRequest(PlayFab::Wrappers::PFAccountManagementUnlinkTwitchAccountRequestWrapper<>& request);

    static void FillClientUnlinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkXboxAccountRequestWrapper<>& request);

    static void FillClientUpdateAvatarUrlRequest(PlayFab::Wrappers::PFAccountManagementClientUpdateAvatarUrlRequestWrapper<>& request);

    static void FillClientUpdateUserTitleDisplayNameRequest(PlayFab::Wrappers::PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper<>& request);
    static HRESULT ValidateClientUpdateUserTitleDisplayNameResponse(PFAccountManagementUpdateUserTitleDisplayNameResult* result);

    static void FillServerAddGenericIDRequest(PlayFab::Wrappers::PFAccountManagementServerAddGenericIDRequestWrapper<>& request);

    static void FillServerBanUsersRequest(PlayFab::Wrappers::PFAccountManagementBanUsersRequestWrapper<>& request);
    static HRESULT ValidateServerBanUsersResponse(PFAccountManagementBanUsersResult* result);

    static void FillServerDeletePlayerRequest(PlayFab::Wrappers::PFAccountManagementDeletePlayerRequestWrapper<>& request);

    static void FillServerGetPlayerCombinedInfoRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerCombinedInfoRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerCombinedInfoResponse(PFAccountManagementGetPlayerCombinedInfoResult* result);

    static void FillServerGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerProfileResponse(PFAccountManagementGetPlayerProfileResult* result);

    static void FillServerGetPlayFabIDsFromFacebookIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromFacebookIDsResponse(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult* result);

    static void FillServerGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromFacebookInstantGamesIdsResponse(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult* result);

    static void FillServerGetPlayFabIDsFromGenericIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromGenericIDsResponse(PFAccountManagementGetPlayFabIDsFromGenericIDsResult* result);

    static void FillServerGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromNintendoSwitchDeviceIdsResponse(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult* result);

    static void FillServerGetPlayFabIDsFromPSNAccountIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromPSNAccountIDsResponse(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult* result);

    static void FillServerGetPlayFabIDsFromSteamIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromSteamIDsResponse(PFAccountManagementGetPlayFabIDsFromSteamIDsResult* result);

    static void FillServerGetPlayFabIDsFromXboxLiveIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayFabIDsFromXboxLiveIDsResponse(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult* result);

    static void FillServerGetServerCustomIDsFromPlayFabIDsRequest(PlayFab::Wrappers::PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper<>& request);
    static HRESULT ValidateServerGetServerCustomIDsFromPlayFabIDsResponse(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult* result);

    static void FillServerGetUserAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementGetUserAccountInfoRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserAccountInfoResponse(PFAccountManagementGetUserAccountInfoResult* result);

    static void FillServerGetUserBansRequest(PlayFab::Wrappers::PFAccountManagementGetUserBansRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserBansResponse(PFAccountManagementGetUserBansResult* result);

    static void FillServerLinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkPSNAccountRequestWrapper<>& request);

    static void FillServerLinkServerCustomIdRequest(PlayFab::Wrappers::PFAccountManagementLinkServerCustomIdRequestWrapper<>& request);

    static void FillServerLinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkXboxAccountRequestWrapper<>& request);

    static void FillServerRemoveGenericIDRequest(PlayFab::Wrappers::PFAccountManagementServerRemoveGenericIDRequestWrapper<>& request);

    static void FillServerRevokeAllBansForUserRequest(PlayFab::Wrappers::PFAccountManagementRevokeAllBansForUserRequestWrapper<>& request);
    static HRESULT ValidateServerRevokeAllBansForUserResponse(PFAccountManagementRevokeAllBansForUserResult* result);

    static void FillServerRevokeBansRequest(PlayFab::Wrappers::PFAccountManagementRevokeBansRequestWrapper<>& request);
    static HRESULT ValidateServerRevokeBansResponse(PFAccountManagementRevokeBansResult* result);

    static void FillServerSendCustomAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper<>& request);

    static void FillServerSendEmailFromTemplateRequest(PlayFab::Wrappers::PFAccountManagementSendEmailFromTemplateRequestWrapper<>& request);

    static void FillServerUnlinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkPSNAccountRequestWrapper<>& request);

    static void FillServerUnlinkServerCustomIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkServerCustomIdRequestWrapper<>& request);

    static void FillServerUnlinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkXboxAccountRequestWrapper<>& request);

    static void FillServerUpdateAvatarUrlRequest(PlayFab::Wrappers::PFAccountManagementServerUpdateAvatarUrlRequestWrapper<>& request);

    static void FillServerUpdateBansRequest(PlayFab::Wrappers::PFAccountManagementUpdateBansRequestWrapper<>& request);
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
