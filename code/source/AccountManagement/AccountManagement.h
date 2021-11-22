#pragma once

#include "AccountManagementDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace AccountManagement
{

class AccountManagementAPI
{
public:
    AccountManagementAPI() = delete;
    AccountManagementAPI(const AccountManagementAPI& source) = delete;
    AccountManagementAPI& operator=(const AccountManagementAPI& source) = delete;
    ~AccountManagementAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<BanUsersResult> AdminBanUsers(SharedPtr<GlobalState const> state, const BanUsersRequest& request, const TaskQueue& queue);
    static AsyncOp<DeleteMasterPlayerAccountResult> AdminDeleteMasterPlayerAccount(SharedPtr<GlobalState const> state, const DeleteMasterPlayerAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeleteMembershipSubscription(SharedPtr<GlobalState const> state, const DeleteMembershipSubscriptionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeletePlayer(SharedPtr<GlobalState const> state, const DeletePlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeleteTitle(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<ExportMasterPlayerDataResult> AdminExportMasterPlayerData(SharedPtr<GlobalState const> state, const ExportMasterPlayerDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayedTitleListResult> AdminGetPlayedTitleList(SharedPtr<GlobalState const> state, const GetPlayedTitleListRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerIdFromAuthTokenResult> AdminGetPlayerIdFromAuthToken(SharedPtr<GlobalState const> state, const GetPlayerIdFromAuthTokenRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerProfileResult> AdminGetPlayerProfile(SharedPtr<GlobalState const> state, const GetPlayerProfileRequest& request, const TaskQueue& queue);
    static AsyncOp<LookupUserAccountInfoResult> AdminGetUserAccountInfo(SharedPtr<GlobalState const> state, const LookupUserAccountInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<GetUserBansResult> AdminGetUserBans(SharedPtr<GlobalState const> state, const GetUserBansRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminResetPassword(SharedPtr<GlobalState const> state, const ResetPasswordRequest& request, const TaskQueue& queue);
    static AsyncOp<RevokeAllBansForUserResult> AdminRevokeAllBansForUser(SharedPtr<GlobalState const> state, const RevokeAllBansForUserRequest& request, const TaskQueue& queue);
    static AsyncOp<RevokeBansResult> AdminRevokeBans(SharedPtr<GlobalState const> state, const RevokeBansRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminSendAccountRecoveryEmail(SharedPtr<GlobalState const> state, const AdminSendAccountRecoveryEmailRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminSetMembershipOverride(SharedPtr<GlobalState const> state, const SetMembershipOverrideRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateBansResult> AdminUpdateBans(SharedPtr<GlobalState const> state, const UpdateBansRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserTitleDisplayNameResult> AdminUpdateUserTitleDisplayName(SharedPtr<GlobalState const> state, const AdminUpdateUserTitleDisplayNameRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientAddGenericID(SharedPtr<TitlePlayer> entity, const ClientAddGenericIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientAddOrUpdateContactEmail(SharedPtr<TitlePlayer> entity, const AddOrUpdateContactEmailRequest& request, const TaskQueue& queue);
    static AsyncOp<AddUsernamePasswordResult> ClientAddUsernamePassword(SharedPtr<TitlePlayer> entity, const AddUsernamePasswordRequest& request, const TaskQueue& queue);
    static AsyncOp<GetAccountInfoResult> ClientGetAccountInfo(SharedPtr<TitlePlayer> entity, const GetAccountInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerCombinedInfoResult> ClientGetPlayerCombinedInfo(SharedPtr<TitlePlayer> entity, const GetPlayerCombinedInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerProfileResult> ClientGetPlayerProfile(SharedPtr<TitlePlayer> entity, const GetPlayerProfileRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromFacebookIDsResult> ClientGetPlayFabIDsFromFacebookIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromFacebookIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromFacebookInstantGamesIdsResult> ClientGetPlayFabIDsFromFacebookInstantGamesIds(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromGameCenterIDsResult> ClientGetPlayFabIDsFromGameCenterIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromGameCenterIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromGenericIDsResult> ClientGetPlayFabIDsFromGenericIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromGenericIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromGoogleIDsResult> ClientGetPlayFabIDsFromGoogleIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromGoogleIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromKongregateIDsResult> ClientGetPlayFabIDsFromKongregateIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromKongregateIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> ClientGetPlayFabIDsFromNintendoSwitchDeviceIds(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromPSNAccountIDsResult> ClientGetPlayFabIDsFromPSNAccountIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromPSNAccountIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromSteamIDsResult> ClientGetPlayFabIDsFromSteamIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromSteamIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromTwitchIDsResult> ClientGetPlayFabIDsFromTwitchIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromTwitchIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromXboxLiveIDsResult> ClientGetPlayFabIDsFromXboxLiveIDs(SharedPtr<TitlePlayer> entity, const GetPlayFabIDsFromXboxLiveIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkAndroidDeviceID(SharedPtr<TitlePlayer> entity, const LinkAndroidDeviceIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkApple(SharedPtr<TitlePlayer> entity, const LinkAppleRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkCustomID(SharedPtr<TitlePlayer> entity, const LinkCustomIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkFacebookAccount(SharedPtr<TitlePlayer> entity, const LinkFacebookAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkFacebookInstantGamesId(SharedPtr<TitlePlayer> entity, const LinkFacebookInstantGamesIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkGameCenterAccount(SharedPtr<TitlePlayer> entity, const LinkGameCenterAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkGoogleAccount(SharedPtr<TitlePlayer> entity, const LinkGoogleAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkIOSDeviceID(SharedPtr<TitlePlayer> entity, const LinkIOSDeviceIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkKongregate(SharedPtr<TitlePlayer> entity, const LinkKongregateAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkNintendoServiceAccount(SharedPtr<TitlePlayer> entity, const LinkNintendoServiceAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkNintendoSwitchDeviceId(SharedPtr<TitlePlayer> entity, const LinkNintendoSwitchDeviceIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkOpenIdConnect(SharedPtr<TitlePlayer> entity, const LinkOpenIdConnectRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkPSNAccount(SharedPtr<TitlePlayer> entity, const ClientLinkPSNAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkSteamAccount(SharedPtr<TitlePlayer> entity, const LinkSteamAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkTwitch(SharedPtr<TitlePlayer> entity, const LinkTwitchAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientLinkXboxAccount(SharedPtr<TitlePlayer> entity, const ClientLinkXboxAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientRemoveContactEmail(SharedPtr<TitlePlayer> entity, const RemoveContactEmailRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientRemoveGenericID(SharedPtr<TitlePlayer> entity, const ClientRemoveGenericIDRequest& request, const TaskQueue& queue);
    static AsyncOp<ReportPlayerClientResult> ClientReportPlayer(SharedPtr<TitlePlayer> entity, const ReportPlayerClientRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientSendAccountRecoveryEmail(SharedPtr<GlobalState const> state, const ClientSendAccountRecoveryEmailRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkAndroidDeviceID(SharedPtr<TitlePlayer> entity, const UnlinkAndroidDeviceIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkApple(SharedPtr<TitlePlayer> entity, const UnlinkAppleRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkCustomID(SharedPtr<TitlePlayer> entity, const UnlinkCustomIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkFacebookAccount(SharedPtr<TitlePlayer> entity, const UnlinkFacebookAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkFacebookInstantGamesId(SharedPtr<TitlePlayer> entity, const UnlinkFacebookInstantGamesIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkGameCenterAccount(SharedPtr<TitlePlayer> entity, const UnlinkGameCenterAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkGoogleAccount(SharedPtr<TitlePlayer> entity, const UnlinkGoogleAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkIOSDeviceID(SharedPtr<TitlePlayer> entity, const UnlinkIOSDeviceIDRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkKongregate(SharedPtr<TitlePlayer> entity, const UnlinkKongregateAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkNintendoServiceAccount(SharedPtr<TitlePlayer> entity, const UnlinkNintendoServiceAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkNintendoSwitchDeviceId(SharedPtr<TitlePlayer> entity, const UnlinkNintendoSwitchDeviceIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkOpenIdConnect(SharedPtr<TitlePlayer> entity, const UnlinkOpenIdConnectRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkPSNAccount(SharedPtr<TitlePlayer> entity, const ClientUnlinkPSNAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkSteamAccount(SharedPtr<TitlePlayer> entity, const UnlinkSteamAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkTwitch(SharedPtr<TitlePlayer> entity, const UnlinkTwitchAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUnlinkXboxAccount(SharedPtr<TitlePlayer> entity, const ClientUnlinkXboxAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUpdateAvatarUrl(SharedPtr<TitlePlayer> entity, const ClientUpdateAvatarUrlRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserTitleDisplayNameResult> ClientUpdateUserTitleDisplayName(SharedPtr<TitlePlayer> entity, const ClientUpdateUserTitleDisplayNameRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerAddGenericID(SharedPtr<GlobalState const> state, const ServerAddGenericIDRequest& request, const TaskQueue& queue);
    static AsyncOp<BanUsersResult> ServerBanUsers(SharedPtr<GlobalState const> state, const BanUsersRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerDeletePlayer(SharedPtr<GlobalState const> state, const DeletePlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerDeletePushNotificationTemplate(SharedPtr<GlobalState const> state, const DeletePushNotificationTemplateRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerProfileResult> ServerGetPlayerProfile(SharedPtr<GlobalState const> state, const GetPlayerProfileRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromFacebookIDsResult> ServerGetPlayFabIDsFromFacebookIDs(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromFacebookIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromFacebookInstantGamesIdsResult> ServerGetPlayFabIDsFromFacebookInstantGamesIds(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromGenericIDsResult> ServerGetPlayFabIDsFromGenericIDs(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromGenericIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> ServerGetPlayFabIDsFromNintendoSwitchDeviceIds(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromPSNAccountIDsResult> ServerGetPlayFabIDsFromPSNAccountIDs(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromPSNAccountIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromSteamIDsResult> ServerGetPlayFabIDsFromSteamIDs(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromSteamIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayFabIDsFromXboxLiveIDsResult> ServerGetPlayFabIDsFromXboxLiveIDs(SharedPtr<GlobalState const> state, const GetPlayFabIDsFromXboxLiveIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetServerCustomIDsFromPlayFabIDsResult> ServerGetServerCustomIDsFromPlayFabIDs(SharedPtr<GlobalState const> state, const GetServerCustomIDsFromPlayFabIDsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetUserAccountInfoResult> ServerGetUserAccountInfo(SharedPtr<GlobalState const> state, const GetUserAccountInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<GetUserBansResult> ServerGetUserBans(SharedPtr<GlobalState const> state, const GetUserBansRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerLinkPSNAccount(SharedPtr<GlobalState const> state, const ServerLinkPSNAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerLinkServerCustomId(SharedPtr<GlobalState const> state, const LinkServerCustomIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerLinkXboxAccount(SharedPtr<GlobalState const> state, const ServerLinkXboxAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRemoveGenericID(SharedPtr<GlobalState const> state, const ServerRemoveGenericIDRequest& request, const TaskQueue& queue);
    static AsyncOp<RevokeAllBansForUserResult> ServerRevokeAllBansForUser(SharedPtr<GlobalState const> state, const RevokeAllBansForUserRequest& request, const TaskQueue& queue);
    static AsyncOp<RevokeBansResult> ServerRevokeBans(SharedPtr<GlobalState const> state, const RevokeBansRequest& request, const TaskQueue& queue);
    static AsyncOp<SavePushNotificationTemplateResult> ServerSavePushNotificationTemplate(SharedPtr<GlobalState const> state, const SavePushNotificationTemplateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSendCustomAccountRecoveryEmail(SharedPtr<GlobalState const> state, const SendCustomAccountRecoveryEmailRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSendEmailFromTemplate(SharedPtr<GlobalState const> state, const SendEmailFromTemplateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSendPushNotification(SharedPtr<GlobalState const> state, const SendPushNotificationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSendPushNotificationFromTemplate(SharedPtr<GlobalState const> state, const SendPushNotificationFromTemplateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUnlinkPSNAccount(SharedPtr<GlobalState const> state, const ServerUnlinkPSNAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUnlinkServerCustomId(SharedPtr<GlobalState const> state, const UnlinkServerCustomIdRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUnlinkXboxAccount(SharedPtr<GlobalState const> state, const ServerUnlinkXboxAccountRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUpdateAvatarUrl(SharedPtr<GlobalState const> state, const ServerUpdateAvatarUrlRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateBansResult> ServerUpdateBans(SharedPtr<GlobalState const> state, const UpdateBansRequest& request, const TaskQueue& queue);
};

} // namespace AccountManagement
} // namespace PlayFab
