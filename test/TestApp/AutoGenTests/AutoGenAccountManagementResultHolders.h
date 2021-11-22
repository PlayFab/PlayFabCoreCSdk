#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct BanUsersResultHolder : public XAsyncResult, public std::enable_shared_from_this<BanUsersResultHolder>
{
    BanUsersResultHolder() = default;
    BanUsersResultHolder(const BanUsersResultHolder&) = delete;
    BanUsersResultHolder(BanUsersResultHolder&&) = default;
    BanUsersResultHolder& operator=(const BanUsersResultHolder&) = delete;
    BanUsersResultHolder& operator=(BanUsersResultHolder&&) = default;
    ~BanUsersResultHolder() = default;

    PFAccountManagementBanUsersResult* result{ nullptr };
};

struct DeleteMasterPlayerAccountResultHolder : public XAsyncResult, public std::enable_shared_from_this<DeleteMasterPlayerAccountResultHolder>
{
    DeleteMasterPlayerAccountResultHolder() = default;
    DeleteMasterPlayerAccountResultHolder(const DeleteMasterPlayerAccountResultHolder&) = delete;
    DeleteMasterPlayerAccountResultHolder(DeleteMasterPlayerAccountResultHolder&&) = default;
    DeleteMasterPlayerAccountResultHolder& operator=(const DeleteMasterPlayerAccountResultHolder&) = delete;
    DeleteMasterPlayerAccountResultHolder& operator=(DeleteMasterPlayerAccountResultHolder&&) = default;
    ~DeleteMasterPlayerAccountResultHolder() = default;

    PFAccountManagementDeleteMasterPlayerAccountResult* result{ nullptr };
};

struct ExportMasterPlayerDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ExportMasterPlayerDataResultHolder>
{
    ExportMasterPlayerDataResultHolder() = default;
    ExportMasterPlayerDataResultHolder(const ExportMasterPlayerDataResultHolder&) = delete;
    ExportMasterPlayerDataResultHolder(ExportMasterPlayerDataResultHolder&&) = default;
    ExportMasterPlayerDataResultHolder& operator=(const ExportMasterPlayerDataResultHolder&) = delete;
    ExportMasterPlayerDataResultHolder& operator=(ExportMasterPlayerDataResultHolder&&) = default;
    ~ExportMasterPlayerDataResultHolder() = default;

    PFAccountManagementExportMasterPlayerDataResult* result{ nullptr };
};

struct GetPlayedTitleListResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayedTitleListResultHolder>
{
    GetPlayedTitleListResultHolder() = default;
    GetPlayedTitleListResultHolder(const GetPlayedTitleListResultHolder&) = delete;
    GetPlayedTitleListResultHolder(GetPlayedTitleListResultHolder&&) = default;
    GetPlayedTitleListResultHolder& operator=(const GetPlayedTitleListResultHolder&) = delete;
    GetPlayedTitleListResultHolder& operator=(GetPlayedTitleListResultHolder&&) = default;
    ~GetPlayedTitleListResultHolder() = default;

    PFAccountManagementGetPlayedTitleListResult* result{ nullptr };
};

struct GetPlayerIdFromAuthTokenResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerIdFromAuthTokenResultHolder>
{
    GetPlayerIdFromAuthTokenResultHolder() = default;
    GetPlayerIdFromAuthTokenResultHolder(const GetPlayerIdFromAuthTokenResultHolder&) = delete;
    GetPlayerIdFromAuthTokenResultHolder(GetPlayerIdFromAuthTokenResultHolder&&) = default;
    GetPlayerIdFromAuthTokenResultHolder& operator=(const GetPlayerIdFromAuthTokenResultHolder&) = delete;
    GetPlayerIdFromAuthTokenResultHolder& operator=(GetPlayerIdFromAuthTokenResultHolder&&) = default;
    ~GetPlayerIdFromAuthTokenResultHolder() = default;

    PFAccountManagementGetPlayerIdFromAuthTokenResult* result{ nullptr };
};

struct GetPlayerProfileResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerProfileResultHolder>
{
    GetPlayerProfileResultHolder() = default;
    GetPlayerProfileResultHolder(const GetPlayerProfileResultHolder&) = delete;
    GetPlayerProfileResultHolder(GetPlayerProfileResultHolder&&) = default;
    GetPlayerProfileResultHolder& operator=(const GetPlayerProfileResultHolder&) = delete;
    GetPlayerProfileResultHolder& operator=(GetPlayerProfileResultHolder&&) = default;
    ~GetPlayerProfileResultHolder() = default;

    PFAccountManagementGetPlayerProfileResult* result{ nullptr };
};

struct LookupUserAccountInfoResultHolder : public XAsyncResult, public std::enable_shared_from_this<LookupUserAccountInfoResultHolder>
{
    LookupUserAccountInfoResultHolder() = default;
    LookupUserAccountInfoResultHolder(const LookupUserAccountInfoResultHolder&) = delete;
    LookupUserAccountInfoResultHolder(LookupUserAccountInfoResultHolder&&) = default;
    LookupUserAccountInfoResultHolder& operator=(const LookupUserAccountInfoResultHolder&) = delete;
    LookupUserAccountInfoResultHolder& operator=(LookupUserAccountInfoResultHolder&&) = default;
    ~LookupUserAccountInfoResultHolder() = default;

    PFAccountManagementLookupUserAccountInfoResult* result{ nullptr };
};

struct GetUserBansResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetUserBansResultHolder>
{
    GetUserBansResultHolder() = default;
    GetUserBansResultHolder(const GetUserBansResultHolder&) = delete;
    GetUserBansResultHolder(GetUserBansResultHolder&&) = default;
    GetUserBansResultHolder& operator=(const GetUserBansResultHolder&) = delete;
    GetUserBansResultHolder& operator=(GetUserBansResultHolder&&) = default;
    ~GetUserBansResultHolder() = default;

    PFAccountManagementGetUserBansResult* result{ nullptr };
};

struct RevokeAllBansForUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<RevokeAllBansForUserResultHolder>
{
    RevokeAllBansForUserResultHolder() = default;
    RevokeAllBansForUserResultHolder(const RevokeAllBansForUserResultHolder&) = delete;
    RevokeAllBansForUserResultHolder(RevokeAllBansForUserResultHolder&&) = default;
    RevokeAllBansForUserResultHolder& operator=(const RevokeAllBansForUserResultHolder&) = delete;
    RevokeAllBansForUserResultHolder& operator=(RevokeAllBansForUserResultHolder&&) = default;
    ~RevokeAllBansForUserResultHolder() = default;

    PFAccountManagementRevokeAllBansForUserResult* result{ nullptr };
};

struct RevokeBansResultHolder : public XAsyncResult, public std::enable_shared_from_this<RevokeBansResultHolder>
{
    RevokeBansResultHolder() = default;
    RevokeBansResultHolder(const RevokeBansResultHolder&) = delete;
    RevokeBansResultHolder(RevokeBansResultHolder&&) = default;
    RevokeBansResultHolder& operator=(const RevokeBansResultHolder&) = delete;
    RevokeBansResultHolder& operator=(RevokeBansResultHolder&&) = default;
    ~RevokeBansResultHolder() = default;

    PFAccountManagementRevokeBansResult* result{ nullptr };
};

struct UpdateBansResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateBansResultHolder>
{
    UpdateBansResultHolder() = default;
    UpdateBansResultHolder(const UpdateBansResultHolder&) = delete;
    UpdateBansResultHolder(UpdateBansResultHolder&&) = default;
    UpdateBansResultHolder& operator=(const UpdateBansResultHolder&) = delete;
    UpdateBansResultHolder& operator=(UpdateBansResultHolder&&) = default;
    ~UpdateBansResultHolder() = default;

    PFAccountManagementUpdateBansResult* result{ nullptr };
};

struct UpdateUserTitleDisplayNameResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateUserTitleDisplayNameResultHolder>
{
    UpdateUserTitleDisplayNameResultHolder() = default;
    UpdateUserTitleDisplayNameResultHolder(const UpdateUserTitleDisplayNameResultHolder&) = delete;
    UpdateUserTitleDisplayNameResultHolder(UpdateUserTitleDisplayNameResultHolder&&) = default;
    UpdateUserTitleDisplayNameResultHolder& operator=(const UpdateUserTitleDisplayNameResultHolder&) = delete;
    UpdateUserTitleDisplayNameResultHolder& operator=(UpdateUserTitleDisplayNameResultHolder&&) = default;
    ~UpdateUserTitleDisplayNameResultHolder() = default;

    PFAccountManagementUpdateUserTitleDisplayNameResult* result{ nullptr };
};

struct AddUsernamePasswordResultHolder : public XAsyncResult, public std::enable_shared_from_this<AddUsernamePasswordResultHolder>
{
    AddUsernamePasswordResultHolder() = default;
    AddUsernamePasswordResultHolder(const AddUsernamePasswordResultHolder&) = delete;
    AddUsernamePasswordResultHolder(AddUsernamePasswordResultHolder&&) = default;
    AddUsernamePasswordResultHolder& operator=(const AddUsernamePasswordResultHolder&) = delete;
    AddUsernamePasswordResultHolder& operator=(AddUsernamePasswordResultHolder&&) = default;
    ~AddUsernamePasswordResultHolder() = default;

    PFAccountManagementAddUsernamePasswordResult* result{ nullptr };
};

struct GetAccountInfoResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetAccountInfoResultHolder>
{
    GetAccountInfoResultHolder() = default;
    GetAccountInfoResultHolder(const GetAccountInfoResultHolder&) = delete;
    GetAccountInfoResultHolder(GetAccountInfoResultHolder&&) = default;
    GetAccountInfoResultHolder& operator=(const GetAccountInfoResultHolder&) = delete;
    GetAccountInfoResultHolder& operator=(GetAccountInfoResultHolder&&) = default;
    ~GetAccountInfoResultHolder() = default;

    PFAccountManagementGetAccountInfoResult* result{ nullptr };
};

struct GetPlayFabIDsFromFacebookIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromFacebookIDsResultHolder>
{
    GetPlayFabIDsFromFacebookIDsResultHolder() = default;
    GetPlayFabIDsFromFacebookIDsResultHolder(const GetPlayFabIDsFromFacebookIDsResultHolder&) = delete;
    GetPlayFabIDsFromFacebookIDsResultHolder(GetPlayFabIDsFromFacebookIDsResultHolder&&) = default;
    GetPlayFabIDsFromFacebookIDsResultHolder& operator=(const GetPlayFabIDsFromFacebookIDsResultHolder&) = delete;
    GetPlayFabIDsFromFacebookIDsResultHolder& operator=(GetPlayFabIDsFromFacebookIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromFacebookIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromFacebookIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder>
{
    GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder() = default;
    GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder(const GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder&) = delete;
    GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder(GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder&&) = default;
    GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder& operator=(const GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder&) = delete;
    GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder& operator=(GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder&&) = default;
    ~GetPlayFabIDsFromFacebookInstantGamesIdsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult* result{ nullptr };
};

struct GetPlayFabIDsFromGameCenterIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromGameCenterIDsResultHolder>
{
    GetPlayFabIDsFromGameCenterIDsResultHolder() = default;
    GetPlayFabIDsFromGameCenterIDsResultHolder(const GetPlayFabIDsFromGameCenterIDsResultHolder&) = delete;
    GetPlayFabIDsFromGameCenterIDsResultHolder(GetPlayFabIDsFromGameCenterIDsResultHolder&&) = default;
    GetPlayFabIDsFromGameCenterIDsResultHolder& operator=(const GetPlayFabIDsFromGameCenterIDsResultHolder&) = delete;
    GetPlayFabIDsFromGameCenterIDsResultHolder& operator=(GetPlayFabIDsFromGameCenterIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromGameCenterIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromGenericIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromGenericIDsResultHolder>
{
    GetPlayFabIDsFromGenericIDsResultHolder() = default;
    GetPlayFabIDsFromGenericIDsResultHolder(const GetPlayFabIDsFromGenericIDsResultHolder&) = delete;
    GetPlayFabIDsFromGenericIDsResultHolder(GetPlayFabIDsFromGenericIDsResultHolder&&) = default;
    GetPlayFabIDsFromGenericIDsResultHolder& operator=(const GetPlayFabIDsFromGenericIDsResultHolder&) = delete;
    GetPlayFabIDsFromGenericIDsResultHolder& operator=(GetPlayFabIDsFromGenericIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromGenericIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromGenericIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromGoogleIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromGoogleIDsResultHolder>
{
    GetPlayFabIDsFromGoogleIDsResultHolder() = default;
    GetPlayFabIDsFromGoogleIDsResultHolder(const GetPlayFabIDsFromGoogleIDsResultHolder&) = delete;
    GetPlayFabIDsFromGoogleIDsResultHolder(GetPlayFabIDsFromGoogleIDsResultHolder&&) = default;
    GetPlayFabIDsFromGoogleIDsResultHolder& operator=(const GetPlayFabIDsFromGoogleIDsResultHolder&) = delete;
    GetPlayFabIDsFromGoogleIDsResultHolder& operator=(GetPlayFabIDsFromGoogleIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromGoogleIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromGoogleIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromKongregateIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromKongregateIDsResultHolder>
{
    GetPlayFabIDsFromKongregateIDsResultHolder() = default;
    GetPlayFabIDsFromKongregateIDsResultHolder(const GetPlayFabIDsFromKongregateIDsResultHolder&) = delete;
    GetPlayFabIDsFromKongregateIDsResultHolder(GetPlayFabIDsFromKongregateIDsResultHolder&&) = default;
    GetPlayFabIDsFromKongregateIDsResultHolder& operator=(const GetPlayFabIDsFromKongregateIDsResultHolder&) = delete;
    GetPlayFabIDsFromKongregateIDsResultHolder& operator=(GetPlayFabIDsFromKongregateIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromKongregateIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromKongregateIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder>
{
    GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder() = default;
    GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder(const GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder&) = delete;
    GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder(GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder&&) = default;
    GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder& operator=(const GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder&) = delete;
    GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder& operator=(GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder&&) = default;
    ~GetPlayFabIDsFromNintendoSwitchDeviceIdsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult* result{ nullptr };
};

struct GetPlayFabIDsFromPSNAccountIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromPSNAccountIDsResultHolder>
{
    GetPlayFabIDsFromPSNAccountIDsResultHolder() = default;
    GetPlayFabIDsFromPSNAccountIDsResultHolder(const GetPlayFabIDsFromPSNAccountIDsResultHolder&) = delete;
    GetPlayFabIDsFromPSNAccountIDsResultHolder(GetPlayFabIDsFromPSNAccountIDsResultHolder&&) = default;
    GetPlayFabIDsFromPSNAccountIDsResultHolder& operator=(const GetPlayFabIDsFromPSNAccountIDsResultHolder&) = delete;
    GetPlayFabIDsFromPSNAccountIDsResultHolder& operator=(GetPlayFabIDsFromPSNAccountIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromPSNAccountIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromSteamIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromSteamIDsResultHolder>
{
    GetPlayFabIDsFromSteamIDsResultHolder() = default;
    GetPlayFabIDsFromSteamIDsResultHolder(const GetPlayFabIDsFromSteamIDsResultHolder&) = delete;
    GetPlayFabIDsFromSteamIDsResultHolder(GetPlayFabIDsFromSteamIDsResultHolder&&) = default;
    GetPlayFabIDsFromSteamIDsResultHolder& operator=(const GetPlayFabIDsFromSteamIDsResultHolder&) = delete;
    GetPlayFabIDsFromSteamIDsResultHolder& operator=(GetPlayFabIDsFromSteamIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromSteamIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromSteamIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromTwitchIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromTwitchIDsResultHolder>
{
    GetPlayFabIDsFromTwitchIDsResultHolder() = default;
    GetPlayFabIDsFromTwitchIDsResultHolder(const GetPlayFabIDsFromTwitchIDsResultHolder&) = delete;
    GetPlayFabIDsFromTwitchIDsResultHolder(GetPlayFabIDsFromTwitchIDsResultHolder&&) = default;
    GetPlayFabIDsFromTwitchIDsResultHolder& operator=(const GetPlayFabIDsFromTwitchIDsResultHolder&) = delete;
    GetPlayFabIDsFromTwitchIDsResultHolder& operator=(GetPlayFabIDsFromTwitchIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromTwitchIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromTwitchIDsResult* result{ nullptr };
};

struct GetPlayFabIDsFromXboxLiveIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayFabIDsFromXboxLiveIDsResultHolder>
{
    GetPlayFabIDsFromXboxLiveIDsResultHolder() = default;
    GetPlayFabIDsFromXboxLiveIDsResultHolder(const GetPlayFabIDsFromXboxLiveIDsResultHolder&) = delete;
    GetPlayFabIDsFromXboxLiveIDsResultHolder(GetPlayFabIDsFromXboxLiveIDsResultHolder&&) = default;
    GetPlayFabIDsFromXboxLiveIDsResultHolder& operator=(const GetPlayFabIDsFromXboxLiveIDsResultHolder&) = delete;
    GetPlayFabIDsFromXboxLiveIDsResultHolder& operator=(GetPlayFabIDsFromXboxLiveIDsResultHolder&&) = default;
    ~GetPlayFabIDsFromXboxLiveIDsResultHolder() = default;

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult* result{ nullptr };
};

struct ReportPlayerClientResultHolder : public XAsyncResult, public std::enable_shared_from_this<ReportPlayerClientResultHolder>
{
    ReportPlayerClientResultHolder() = default;
    ReportPlayerClientResultHolder(const ReportPlayerClientResultHolder&) = default;
    ReportPlayerClientResultHolder(ReportPlayerClientResultHolder&&) = default;
    ReportPlayerClientResultHolder& operator=(const ReportPlayerClientResultHolder&) = default;
    ReportPlayerClientResultHolder& operator=(ReportPlayerClientResultHolder&&) = default;
    ~ReportPlayerClientResultHolder() = default;

    PFAccountManagementReportPlayerClientResult result{};
};

struct GetServerCustomIDsFromPlayFabIDsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetServerCustomIDsFromPlayFabIDsResultHolder>
{
    GetServerCustomIDsFromPlayFabIDsResultHolder() = default;
    GetServerCustomIDsFromPlayFabIDsResultHolder(const GetServerCustomIDsFromPlayFabIDsResultHolder&) = delete;
    GetServerCustomIDsFromPlayFabIDsResultHolder(GetServerCustomIDsFromPlayFabIDsResultHolder&&) = default;
    GetServerCustomIDsFromPlayFabIDsResultHolder& operator=(const GetServerCustomIDsFromPlayFabIDsResultHolder&) = delete;
    GetServerCustomIDsFromPlayFabIDsResultHolder& operator=(GetServerCustomIDsFromPlayFabIDsResultHolder&&) = default;
    ~GetServerCustomIDsFromPlayFabIDsResultHolder() = default;

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult* result{ nullptr };
};

struct GetUserAccountInfoResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetUserAccountInfoResultHolder>
{
    GetUserAccountInfoResultHolder() = default;
    GetUserAccountInfoResultHolder(const GetUserAccountInfoResultHolder&) = delete;
    GetUserAccountInfoResultHolder(GetUserAccountInfoResultHolder&&) = default;
    GetUserAccountInfoResultHolder& operator=(const GetUserAccountInfoResultHolder&) = delete;
    GetUserAccountInfoResultHolder& operator=(GetUserAccountInfoResultHolder&&) = default;
    ~GetUserAccountInfoResultHolder() = default;

    PFAccountManagementGetUserAccountInfoResult* result{ nullptr };
};

struct SavePushNotificationTemplateResultHolder : public XAsyncResult, public std::enable_shared_from_this<SavePushNotificationTemplateResultHolder>
{
    SavePushNotificationTemplateResultHolder() = default;
    SavePushNotificationTemplateResultHolder(const SavePushNotificationTemplateResultHolder&) = delete;
    SavePushNotificationTemplateResultHolder(SavePushNotificationTemplateResultHolder&&) = default;
    SavePushNotificationTemplateResultHolder& operator=(const SavePushNotificationTemplateResultHolder&) = delete;
    SavePushNotificationTemplateResultHolder& operator=(SavePushNotificationTemplateResultHolder&&) = default;
    ~SavePushNotificationTemplateResultHolder() = default;

    PFAccountManagementSavePushNotificationTemplateResult* result{ nullptr };
};


}
