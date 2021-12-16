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
    void TestAccountManagementServerDeletePushNotificationTemplate(TestContext& testContext);
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
    void TestAccountManagementServerSavePushNotificationTemplate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerSendCustomAccountRecoveryEmail(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerSendEmailFromTemplate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerSendPushNotification(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAccountManagementServerSendPushNotificationFromTemplate(TestContext& testContext);
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
    static void FillBanUsersRequest(PlayFab::Wrappers::PFAccountManagementBanUsersRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementBanUsersResult(PFAccountManagementBanUsersResult const* result);
    static HRESULT ValidatePFAccountManagementBanUsersResult(PFAccountManagementBanUsersResult* result);

    static void LogDeleteMasterPlayerAccountRequest(PFAccountManagementDeleteMasterPlayerAccountRequest const* request, const char* testName);
    static void FillDeleteMasterPlayerAccountRequest(PlayFab::Wrappers::PFAccountManagementDeleteMasterPlayerAccountRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementDeleteMasterPlayerAccountResult(PFAccountManagementDeleteMasterPlayerAccountResult const* result);
    static HRESULT ValidatePFAccountManagementDeleteMasterPlayerAccountResult(PFAccountManagementDeleteMasterPlayerAccountResult* result);

    static void LogDeleteMembershipSubscriptionRequest(PFAccountManagementDeleteMembershipSubscriptionRequest const* request, const char* testName);
    static void FillDeleteMembershipSubscriptionRequest(PlayFab::Wrappers::PFAccountManagementDeleteMembershipSubscriptionRequestWrapper<>& request);

    static void LogDeletePlayerRequest(PFAccountManagementDeletePlayerRequest const* request, const char* testName);
    static void FillDeletePlayerRequest(PlayFab::Wrappers::PFAccountManagementDeletePlayerRequestWrapper<>& request);


    static void LogExportMasterPlayerDataRequest(PFAccountManagementExportMasterPlayerDataRequest const* request, const char* testName);
    static void FillExportMasterPlayerDataRequest(PlayFab::Wrappers::PFAccountManagementExportMasterPlayerDataRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementExportMasterPlayerDataResult(PFAccountManagementExportMasterPlayerDataResult const* result);
    static HRESULT ValidatePFAccountManagementExportMasterPlayerDataResult(PFAccountManagementExportMasterPlayerDataResult* result);

    static void LogGetPlayedTitleListRequest(PFAccountManagementGetPlayedTitleListRequest const* request, const char* testName);
    static void FillGetPlayedTitleListRequest(PlayFab::Wrappers::PFAccountManagementGetPlayedTitleListRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayedTitleListResult(PFAccountManagementGetPlayedTitleListResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayedTitleListResult(PFAccountManagementGetPlayedTitleListResult* result);

    static void LogGetPlayerIdFromAuthTokenRequest(PFAccountManagementGetPlayerIdFromAuthTokenRequest const* request, const char* testName);
    static void FillGetPlayerIdFromAuthTokenRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayerIdFromAuthTokenResult(PFAccountManagementGetPlayerIdFromAuthTokenResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayerIdFromAuthTokenResult(PFAccountManagementGetPlayerIdFromAuthTokenResult* result);

    static void LogGetPlayerProfileRequest(PFAccountManagementGetPlayerProfileRequest const* request, const char* testName);
    static void FillGetPlayerProfileRequest(PlayFab::Wrappers::PFAccountManagementGetPlayerProfileRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayerProfileResult(PFAccountManagementGetPlayerProfileResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayerProfileResult(PFAccountManagementGetPlayerProfileResult* result);

    static void LogLookupUserAccountInfoRequest(PFAccountManagementLookupUserAccountInfoRequest const* request, const char* testName);
    static void FillLookupUserAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementLookupUserAccountInfoRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementLookupUserAccountInfoResult(PFAccountManagementLookupUserAccountInfoResult const* result);
    static HRESULT ValidatePFAccountManagementLookupUserAccountInfoResult(PFAccountManagementLookupUserAccountInfoResult* result);

    static void LogGetUserBansRequest(PFAccountManagementGetUserBansRequest const* request, const char* testName);
    static void FillGetUserBansRequest(PlayFab::Wrappers::PFAccountManagementGetUserBansRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetUserBansResult(PFAccountManagementGetUserBansResult const* result);
    static HRESULT ValidatePFAccountManagementGetUserBansResult(PFAccountManagementGetUserBansResult* result);

    static void LogResetPasswordRequest(PFAccountManagementResetPasswordRequest const* request, const char* testName);
    static void FillResetPasswordRequest(PlayFab::Wrappers::PFAccountManagementResetPasswordRequestWrapper<>& request);

    static void LogRevokeAllBansForUserRequest(PFAccountManagementRevokeAllBansForUserRequest const* request, const char* testName);
    static void FillRevokeAllBansForUserRequest(PlayFab::Wrappers::PFAccountManagementRevokeAllBansForUserRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementRevokeAllBansForUserResult(PFAccountManagementRevokeAllBansForUserResult const* result);
    static HRESULT ValidatePFAccountManagementRevokeAllBansForUserResult(PFAccountManagementRevokeAllBansForUserResult* result);

    static void LogRevokeBansRequest(PFAccountManagementRevokeBansRequest const* request, const char* testName);
    static void FillRevokeBansRequest(PlayFab::Wrappers::PFAccountManagementRevokeBansRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementRevokeBansResult(PFAccountManagementRevokeBansResult const* result);
    static HRESULT ValidatePFAccountManagementRevokeBansResult(PFAccountManagementRevokeBansResult* result);

    static void LogAdminSendAccountRecoveryEmailRequest(PFAccountManagementAdminSendAccountRecoveryEmailRequest const* request, const char* testName);
    static void FillAdminSendAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper<>& request);

    static void LogSetMembershipOverrideRequest(PFAccountManagementSetMembershipOverrideRequest const* request, const char* testName);
    static void FillSetMembershipOverrideRequest(PlayFab::Wrappers::PFAccountManagementSetMembershipOverrideRequestWrapper<>& request);

    static void LogUpdateBansRequest(PFAccountManagementUpdateBansRequest const* request, const char* testName);
    static void FillUpdateBansRequest(PlayFab::Wrappers::PFAccountManagementUpdateBansRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementUpdateBansResult(PFAccountManagementUpdateBansResult const* result);
    static HRESULT ValidatePFAccountManagementUpdateBansResult(PFAccountManagementUpdateBansResult* result);

    static void LogAdminUpdateUserTitleDisplayNameRequest(PFAccountManagementAdminUpdateUserTitleDisplayNameRequest const* request, const char* testName);
    static void FillAdminUpdateUserTitleDisplayNameRequest(PlayFab::Wrappers::PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementUpdateUserTitleDisplayNameResult(PFAccountManagementUpdateUserTitleDisplayNameResult const* result);
    static HRESULT ValidatePFAccountManagementUpdateUserTitleDisplayNameResult(PFAccountManagementUpdateUserTitleDisplayNameResult* result);

    static void LogClientAddGenericIDRequest(PFAccountManagementClientAddGenericIDRequest const* request, const char* testName);
    static void FillClientAddGenericIDRequest(PlayFab::Wrappers::PFAccountManagementClientAddGenericIDRequestWrapper<>& request);

    static void LogAddOrUpdateContactEmailRequest(PFAccountManagementAddOrUpdateContactEmailRequest const* request, const char* testName);
    static void FillAddOrUpdateContactEmailRequest(PlayFab::Wrappers::PFAccountManagementAddOrUpdateContactEmailRequestWrapper<>& request);

    static void LogAddUsernamePasswordRequest(PFAccountManagementAddUsernamePasswordRequest const* request, const char* testName);
    static void FillAddUsernamePasswordRequest(PlayFab::Wrappers::PFAccountManagementAddUsernamePasswordRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementAddUsernamePasswordResult(PFAccountManagementAddUsernamePasswordResult const* result);
    static HRESULT ValidatePFAccountManagementAddUsernamePasswordResult(PFAccountManagementAddUsernamePasswordResult* result);

    static void LogGetAccountInfoRequest(PFAccountManagementGetAccountInfoRequest const* request, const char* testName);
    static void FillGetAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementGetAccountInfoRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetAccountInfoResult(PFAccountManagementGetAccountInfoResult const* result);
    static HRESULT ValidatePFAccountManagementGetAccountInfoResult(PFAccountManagementGetAccountInfoResult* result);

    static void LogGetPlayerCombinedInfoRequest(PFGetPlayerCombinedInfoRequest const* request, const char* testName);
    static void FillGetPlayerCombinedInfoRequest(PlayFab::Wrappers::PFGetPlayerCombinedInfoRequestWrapper<>& request);
    static HRESULT LogPFGetPlayerCombinedInfoResult(PFGetPlayerCombinedInfoResult const* result);
    static HRESULT ValidatePFGetPlayerCombinedInfoResult(PFGetPlayerCombinedInfoResult* result);


    static void LogGetPlayFabIDsFromFacebookIDsRequest(PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromFacebookIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromFacebookIDsResult(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromFacebookIDsResult(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult* result);

    static void LogGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult* result);

    static void LogGetPlayFabIDsFromGameCenterIDsRequest(PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromGameCenterIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromGameCenterIDsResult(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromGameCenterIDsResult(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult* result);

    static void LogGetPlayFabIDsFromGenericIDsRequest(PFAccountManagementGetPlayFabIDsFromGenericIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromGenericIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromGenericIDsResult(PFAccountManagementGetPlayFabIDsFromGenericIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromGenericIDsResult(PFAccountManagementGetPlayFabIDsFromGenericIDsResult* result);

    static void LogGetPlayFabIDsFromGoogleIDsRequest(PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromGoogleIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromGoogleIDsResult(PFAccountManagementGetPlayFabIDsFromGoogleIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromGoogleIDsResult(PFAccountManagementGetPlayFabIDsFromGoogleIDsResult* result);

    static void LogGetPlayFabIDsFromKongregateIDsRequest(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromKongregateIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromKongregateIDsResult(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromKongregateIDsResult(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult* result);

    static void LogGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult* result);

    static void LogGetPlayFabIDsFromPSNAccountIDsRequest(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromPSNAccountIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult* result);

    static void LogGetPlayFabIDsFromSteamIDsRequest(PFAccountManagementGetPlayFabIDsFromSteamIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromSteamIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromSteamIDsResult(PFAccountManagementGetPlayFabIDsFromSteamIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromSteamIDsResult(PFAccountManagementGetPlayFabIDsFromSteamIDsResult* result);

    static void LogGetPlayFabIDsFromTwitchIDsRequest(PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromTwitchIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromTwitchIDsResult(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromTwitchIDsResult(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult* result);

    static void LogGetPlayFabIDsFromXboxLiveIDsRequest(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest const* request, const char* testName);
    static void FillGetPlayFabIDsFromXboxLiveIDsRequest(PlayFab::Wrappers::PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult* result);

    static void LogLinkAndroidDeviceIDRequest(PFAccountManagementLinkAndroidDeviceIDRequest const* request, const char* testName);
    static void FillLinkAndroidDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementLinkAndroidDeviceIDRequestWrapper<>& request);

    static void LogLinkAppleRequest(PFAccountManagementLinkAppleRequest const* request, const char* testName);
    static void FillLinkAppleRequest(PlayFab::Wrappers::PFAccountManagementLinkAppleRequestWrapper<>& request);

    static void LogLinkCustomIDRequest(PFAccountManagementLinkCustomIDRequest const* request, const char* testName);
    static void FillLinkCustomIDRequest(PlayFab::Wrappers::PFAccountManagementLinkCustomIDRequestWrapper<>& request);

    static void LogLinkFacebookAccountRequest(PFAccountManagementLinkFacebookAccountRequest const* request, const char* testName);
    static void FillLinkFacebookAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkFacebookAccountRequestWrapper<>& request);

    static void LogLinkFacebookInstantGamesIdRequest(PFAccountManagementLinkFacebookInstantGamesIdRequest const* request, const char* testName);
    static void FillLinkFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper<>& request);

    static void LogLinkGameCenterAccountRequest(PFAccountManagementLinkGameCenterAccountRequest const* request, const char* testName);
    static void FillLinkGameCenterAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGameCenterAccountRequestWrapper<>& request);

    static void LogLinkGoogleAccountRequest(PFAccountManagementLinkGoogleAccountRequest const* request, const char* testName);
    static void FillLinkGoogleAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkGoogleAccountRequestWrapper<>& request);

    static void LogLinkIOSDeviceIDRequest(PFAccountManagementLinkIOSDeviceIDRequest const* request, const char* testName);
    static void FillLinkIOSDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementLinkIOSDeviceIDRequestWrapper<>& request);

    static void LogLinkKongregateAccountRequest(PFAccountManagementLinkKongregateAccountRequest const* request, const char* testName);
    static void FillLinkKongregateAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkKongregateAccountRequestWrapper<>& request);

    static void LogLinkNintendoServiceAccountRequest(PFAccountManagementLinkNintendoServiceAccountRequest const* request, const char* testName);
    static void FillLinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkNintendoServiceAccountRequestWrapper<>& request);

    static void LogLinkNintendoSwitchDeviceIdRequest(PFAccountManagementLinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void FillLinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    static void LogLinkOpenIdConnectRequest(PFAccountManagementLinkOpenIdConnectRequest const* request, const char* testName);
    static void FillLinkOpenIdConnectRequest(PlayFab::Wrappers::PFAccountManagementLinkOpenIdConnectRequestWrapper<>& request);

    static void LogClientLinkPSNAccountRequest(PFAccountManagementClientLinkPSNAccountRequest const* request, const char* testName);
    static void FillClientLinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkPSNAccountRequestWrapper<>& request);

    static void LogLinkSteamAccountRequest(PFAccountManagementLinkSteamAccountRequest const* request, const char* testName);
    static void FillLinkSteamAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkSteamAccountRequestWrapper<>& request);

    static void LogLinkTwitchAccountRequest(PFAccountManagementLinkTwitchAccountRequest const* request, const char* testName);
    static void FillLinkTwitchAccountRequest(PlayFab::Wrappers::PFAccountManagementLinkTwitchAccountRequestWrapper<>& request);

    static void LogClientLinkXboxAccountRequest(PFAccountManagementClientLinkXboxAccountRequest const* request, const char* testName);
    static void FillClientLinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementClientLinkXboxAccountRequestWrapper<>& request);

    static void LogRemoveContactEmailRequest(PFAccountManagementRemoveContactEmailRequest const* request, const char* testName);
    static void FillRemoveContactEmailRequest(PlayFab::Wrappers::PFAccountManagementRemoveContactEmailRequestWrapper<>& request);

    static void LogClientRemoveGenericIDRequest(PFAccountManagementClientRemoveGenericIDRequest const* request, const char* testName);
    static void FillClientRemoveGenericIDRequest(PlayFab::Wrappers::PFAccountManagementClientRemoveGenericIDRequestWrapper<>& request);

    static void LogReportPlayerClientRequest(PFAccountManagementReportPlayerClientRequest const* request, const char* testName);
    static void FillReportPlayerClientRequest(PlayFab::Wrappers::PFAccountManagementReportPlayerClientRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementReportPlayerClientResult(PFAccountManagementReportPlayerClientResult const* result);
    static HRESULT ValidatePFAccountManagementReportPlayerClientResult(PFAccountManagementReportPlayerClientResult* result);

    static void LogClientSendAccountRecoveryEmailRequest(PFAccountManagementClientSendAccountRecoveryEmailRequest const* request, const char* testName);
    static void FillClientSendAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper<>& request);

    static void LogUnlinkAndroidDeviceIDRequest(PFAccountManagementUnlinkAndroidDeviceIDRequest const* request, const char* testName);
    static void FillUnlinkAndroidDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper<>& request);

    static void LogUnlinkAppleRequest(PFAccountManagementUnlinkAppleRequest const* request, const char* testName);
    static void FillUnlinkAppleRequest(PlayFab::Wrappers::PFAccountManagementUnlinkAppleRequestWrapper<>& request);

    static void LogUnlinkCustomIDRequest(PFAccountManagementUnlinkCustomIDRequest const* request, const char* testName);
    static void FillUnlinkCustomIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkCustomIDRequestWrapper<>& request);

    static void LogUnlinkFacebookAccountRequest(PFAccountManagementUnlinkFacebookAccountRequest const* request, const char* testName);
    static void FillUnlinkFacebookAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkFacebookAccountRequestWrapper<>& request);

    static void LogUnlinkFacebookInstantGamesIdRequest(PFAccountManagementUnlinkFacebookInstantGamesIdRequest const* request, const char* testName);
    static void FillUnlinkFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper<>& request);

    static void LogUnlinkGameCenterAccountRequest(PFAccountManagementUnlinkGameCenterAccountRequest const* request, const char* testName);
    static void FillUnlinkGameCenterAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGameCenterAccountRequestWrapper<>& request);

    static void LogUnlinkGoogleAccountRequest(PFAccountManagementUnlinkGoogleAccountRequest const* request, const char* testName);
    static void FillUnlinkGoogleAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkGoogleAccountRequestWrapper<>& request);

    static void LogUnlinkIOSDeviceIDRequest(PFAccountManagementUnlinkIOSDeviceIDRequest const* request, const char* testName);
    static void FillUnlinkIOSDeviceIDRequest(PlayFab::Wrappers::PFAccountManagementUnlinkIOSDeviceIDRequestWrapper<>& request);

    static void LogUnlinkKongregateAccountRequest(PFAccountManagementUnlinkKongregateAccountRequest const* request, const char* testName);
    static void FillUnlinkKongregateAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkKongregateAccountRequestWrapper<>& request);

    static void LogUnlinkNintendoServiceAccountRequest(PFAccountManagementUnlinkNintendoServiceAccountRequest const* request, const char* testName);
    static void FillUnlinkNintendoServiceAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper<>& request);

    static void LogUnlinkNintendoSwitchDeviceIdRequest(PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void FillUnlinkNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper<>& request);

    static void LogUnlinkOpenIdConnectRequest(PFAccountManagementUnlinkOpenIdConnectRequest const* request, const char* testName);
    static void FillUnlinkOpenIdConnectRequest(PlayFab::Wrappers::PFAccountManagementUnlinkOpenIdConnectRequestWrapper<>& request);

    static void LogClientUnlinkPSNAccountRequest(PFAccountManagementClientUnlinkPSNAccountRequest const* request, const char* testName);
    static void FillClientUnlinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkPSNAccountRequestWrapper<>& request);

    static void LogUnlinkSteamAccountRequest(PFAccountManagementUnlinkSteamAccountRequest const* request, const char* testName);
    static void FillUnlinkSteamAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkSteamAccountRequestWrapper<>& request);

    static void LogUnlinkTwitchAccountRequest(PFAccountManagementUnlinkTwitchAccountRequest const* request, const char* testName);
    static void FillUnlinkTwitchAccountRequest(PlayFab::Wrappers::PFAccountManagementUnlinkTwitchAccountRequestWrapper<>& request);

    static void LogClientUnlinkXboxAccountRequest(PFAccountManagementClientUnlinkXboxAccountRequest const* request, const char* testName);
    static void FillClientUnlinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementClientUnlinkXboxAccountRequestWrapper<>& request);

    static void LogClientUpdateAvatarUrlRequest(PFAccountManagementClientUpdateAvatarUrlRequest const* request, const char* testName);
    static void FillClientUpdateAvatarUrlRequest(PlayFab::Wrappers::PFAccountManagementClientUpdateAvatarUrlRequestWrapper<>& request);

    static void LogClientUpdateUserTitleDisplayNameRequest(PFAccountManagementClientUpdateUserTitleDisplayNameRequest const* request, const char* testName);
    static void FillClientUpdateUserTitleDisplayNameRequest(PlayFab::Wrappers::PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper<>& request);

    static void LogServerAddGenericIDRequest(PFAccountManagementServerAddGenericIDRequest const* request, const char* testName);
    static void FillServerAddGenericIDRequest(PlayFab::Wrappers::PFAccountManagementServerAddGenericIDRequestWrapper<>& request);



    static void LogDeletePushNotificationTemplateRequest(PFAccountManagementDeletePushNotificationTemplateRequest const* request, const char* testName);
    static void FillDeletePushNotificationTemplateRequest(PlayFab::Wrappers::PFAccountManagementDeletePushNotificationTemplateRequestWrapper<>& request);









    static void LogGetServerCustomIDsFromPlayFabIDsRequest(PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest const* request, const char* testName);
    static void FillGetServerCustomIDsFromPlayFabIDsRequest(PlayFab::Wrappers::PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetServerCustomIDsFromPlayFabIDsResult(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult const* result);
    static HRESULT ValidatePFAccountManagementGetServerCustomIDsFromPlayFabIDsResult(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult* result);

    static void LogGetUserAccountInfoRequest(PFAccountManagementGetUserAccountInfoRequest const* request, const char* testName);
    static void FillGetUserAccountInfoRequest(PlayFab::Wrappers::PFAccountManagementGetUserAccountInfoRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementGetUserAccountInfoResult(PFAccountManagementGetUserAccountInfoResult const* result);
    static HRESULT ValidatePFAccountManagementGetUserAccountInfoResult(PFAccountManagementGetUserAccountInfoResult* result);


    static void LogServerLinkPSNAccountRequest(PFAccountManagementServerLinkPSNAccountRequest const* request, const char* testName);
    static void FillServerLinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkPSNAccountRequestWrapper<>& request);

    static void LogLinkServerCustomIdRequest(PFAccountManagementLinkServerCustomIdRequest const* request, const char* testName);
    static void FillLinkServerCustomIdRequest(PlayFab::Wrappers::PFAccountManagementLinkServerCustomIdRequestWrapper<>& request);

    static void LogServerLinkXboxAccountRequest(PFAccountManagementServerLinkXboxAccountRequest const* request, const char* testName);
    static void FillServerLinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementServerLinkXboxAccountRequestWrapper<>& request);

    static void LogServerRemoveGenericIDRequest(PFAccountManagementServerRemoveGenericIDRequest const* request, const char* testName);
    static void FillServerRemoveGenericIDRequest(PlayFab::Wrappers::PFAccountManagementServerRemoveGenericIDRequestWrapper<>& request);



    static void LogSavePushNotificationTemplateRequest(PFAccountManagementSavePushNotificationTemplateRequest const* request, const char* testName);
    static void FillSavePushNotificationTemplateRequest(PlayFab::Wrappers::PFAccountManagementSavePushNotificationTemplateRequestWrapper<>& request);
    static HRESULT LogPFAccountManagementSavePushNotificationTemplateResult(PFAccountManagementSavePushNotificationTemplateResult const* result);
    static HRESULT ValidatePFAccountManagementSavePushNotificationTemplateResult(PFAccountManagementSavePushNotificationTemplateResult* result);

    static void LogSendCustomAccountRecoveryEmailRequest(PFAccountManagementSendCustomAccountRecoveryEmailRequest const* request, const char* testName);
    static void FillSendCustomAccountRecoveryEmailRequest(PlayFab::Wrappers::PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper<>& request);

    static void LogSendEmailFromTemplateRequest(PFAccountManagementSendEmailFromTemplateRequest const* request, const char* testName);
    static void FillSendEmailFromTemplateRequest(PlayFab::Wrappers::PFAccountManagementSendEmailFromTemplateRequestWrapper<>& request);

    static void LogSendPushNotificationRequest(PFAccountManagementSendPushNotificationRequest const* request, const char* testName);
    static void FillSendPushNotificationRequest(PlayFab::Wrappers::PFAccountManagementSendPushNotificationRequestWrapper<>& request);

    static void LogSendPushNotificationFromTemplateRequest(PFAccountManagementSendPushNotificationFromTemplateRequest const* request, const char* testName);
    static void FillSendPushNotificationFromTemplateRequest(PlayFab::Wrappers::PFAccountManagementSendPushNotificationFromTemplateRequestWrapper<>& request);

    static void LogServerUnlinkPSNAccountRequest(PFAccountManagementServerUnlinkPSNAccountRequest const* request, const char* testName);
    static void FillServerUnlinkPSNAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkPSNAccountRequestWrapper<>& request);

    static void LogUnlinkServerCustomIdRequest(PFAccountManagementUnlinkServerCustomIdRequest const* request, const char* testName);
    static void FillUnlinkServerCustomIdRequest(PlayFab::Wrappers::PFAccountManagementUnlinkServerCustomIdRequestWrapper<>& request);

    static void LogServerUnlinkXboxAccountRequest(PFAccountManagementServerUnlinkXboxAccountRequest const* request, const char* testName);
    static void FillServerUnlinkXboxAccountRequest(PlayFab::Wrappers::PFAccountManagementServerUnlinkXboxAccountRequestWrapper<>& request);

    static void LogServerUpdateAvatarUrlRequest(PFAccountManagementServerUpdateAvatarUrlRequest const* request, const char* testName);
    static void FillServerUpdateAvatarUrlRequest(PlayFab::Wrappers::PFAccountManagementServerUpdateAvatarUrlRequestWrapper<>& request);


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
