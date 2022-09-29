#include "stdafx.h"
#include "AccountManagementDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace AccountManagement
{

JsonValue BanRequest::ToJson() const
{
    return BanRequest::ToJson(this->Model());
}

JsonValue BanRequest::ToJson(const PFAccountManagementBanRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "DurationInHours", input.durationInHours);
    JsonUtils::ObjectAddMember(output, "IPAddress", input.IPAddress);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

JsonValue BanUsersRequest::ToJson() const
{
    return BanUsersRequest::ToJson(this->Model());
}

JsonValue BanUsersRequest::ToJson(const PFAccountManagementBanUsersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<BanRequest>(output, "Bans", input.bans, input.bansCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void BanInfo::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Active", this->m_model.active);

    String banId{};
    JsonUtils::ObjectGetMember(input, "BanId", banId);
    this->SetBanId(std::move(banId));

    StdExtra::optional<time_t> created{};
    JsonUtils::ObjectGetMemberTime(input, "Created", created);
    this->SetCreated(std::move(created));

    StdExtra::optional<time_t> expires{};
    JsonUtils::ObjectGetMemberTime(input, "Expires", expires);
    this->SetExpires(std::move(expires));

    String IPAddress{};
    JsonUtils::ObjectGetMember(input, "IPAddress", IPAddress);
    this->SetIPAddress(std::move(IPAddress));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String reason{};
    JsonUtils::ObjectGetMember(input, "Reason", reason);
    this->SetReason(std::move(reason));
}

size_t BanInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementBanInfo const*> BanInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BanInfo>(&this->Model());
}

size_t BanInfo::RequiredBufferSize(const PFAccountManagementBanInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.banId)
    {
        requiredSize += (std::strlen(model.banId) + 1);
    }
    if (model.created)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.expires)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.IPAddress)
    {
        requiredSize += (std::strlen(model.IPAddress) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.reason)
    {
        requiredSize += (std::strlen(model.reason) + 1);
    }
    return requiredSize;
}

HRESULT BanInfo::Copy(const PFAccountManagementBanInfo& input, PFAccountManagementBanInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.banId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.created); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.created = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.expires); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.expires = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.IPAddress); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.IPAddress = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reason); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reason = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void BanUsersResult::FromJson(const JsonValue& input)
{
    ModelVector<BanInfo> banData{};
    JsonUtils::ObjectGetMember<BanInfo>(input, "BanData", banData);
    this->SetBanData(std::move(banData));
}

size_t BanUsersResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementBanUsersResult const*> BanUsersResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BanUsersResult>(&this->Model());
}

size_t BanUsersResult::RequiredBufferSize(const PFAccountManagementBanUsersResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementBanInfo*) + sizeof(PFAccountManagementBanInfo*) * model.banDataCount);
    for (size_t i = 0; i < model.banDataCount; ++i)
    {
        requiredSize += BanInfo::RequiredBufferSize(*model.banData[i]);
    }
    return requiredSize;
}

HRESULT BanUsersResult::Copy(const PFAccountManagementBanUsersResult& input, PFAccountManagementBanUsersResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BanInfo>(input.banData, input.banDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteMasterPlayerAccountRequest::ToJson() const
{
    return DeleteMasterPlayerAccountRequest::ToJson(this->Model());
}

JsonValue DeleteMasterPlayerAccountRequest::ToJson(const PFAccountManagementDeleteMasterPlayerAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "MetaData", input.metaData);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void DeleteMasterPlayerAccountResult::FromJson(const JsonValue& input)
{
    String jobReceiptId{};
    JsonUtils::ObjectGetMember(input, "JobReceiptId", jobReceiptId);
    this->SetJobReceiptId(std::move(jobReceiptId));

    CStringVector titleIds{};
    JsonUtils::ObjectGetMember(input, "TitleIds", titleIds);
    this->SetTitleIds(std::move(titleIds));
}

size_t DeleteMasterPlayerAccountResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementDeleteMasterPlayerAccountResult const*> DeleteMasterPlayerAccountResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DeleteMasterPlayerAccountResult>(&this->Model());
}

size_t DeleteMasterPlayerAccountResult::RequiredBufferSize(const PFAccountManagementDeleteMasterPlayerAccountResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.jobReceiptId)
    {
        requiredSize += (std::strlen(model.jobReceiptId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.titleIdsCount);
    for (size_t i = 0; i < model.titleIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.titleIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT DeleteMasterPlayerAccountResult::Copy(const PFAccountManagementDeleteMasterPlayerAccountResult& input, PFAccountManagementDeleteMasterPlayerAccountResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.jobReceiptId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.jobReceiptId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.titleIds, input.titleIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteMembershipSubscriptionRequest::ToJson() const
{
    return DeleteMembershipSubscriptionRequest::ToJson(this->Model());
}

JsonValue DeleteMembershipSubscriptionRequest::ToJson(const PFAccountManagementDeleteMembershipSubscriptionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MembershipId", input.membershipId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "SubscriptionId", input.subscriptionId);
    return output;
}

JsonValue DeletePlayerRequest::ToJson() const
{
    return DeletePlayerRequest::ToJson(this->Model());
}

JsonValue DeletePlayerRequest::ToJson(const PFAccountManagementDeletePlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ExportMasterPlayerDataRequest::ToJson() const
{
    return ExportMasterPlayerDataRequest::ToJson(this->Model());
}

JsonValue ExportMasterPlayerDataRequest::ToJson(const PFAccountManagementExportMasterPlayerDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ExportMasterPlayerDataResult::FromJson(const JsonValue& input)
{
    String jobReceiptId{};
    JsonUtils::ObjectGetMember(input, "JobReceiptId", jobReceiptId);
    this->SetJobReceiptId(std::move(jobReceiptId));
}

size_t ExportMasterPlayerDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementExportMasterPlayerDataResult const*> ExportMasterPlayerDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ExportMasterPlayerDataResult>(&this->Model());
}

size_t ExportMasterPlayerDataResult::RequiredBufferSize(const PFAccountManagementExportMasterPlayerDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.jobReceiptId)
    {
        requiredSize += (std::strlen(model.jobReceiptId) + 1);
    }
    return requiredSize;
}

HRESULT ExportMasterPlayerDataResult::Copy(const PFAccountManagementExportMasterPlayerDataResult& input, PFAccountManagementExportMasterPlayerDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.jobReceiptId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.jobReceiptId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayedTitleListRequest::ToJson() const
{
    return GetPlayedTitleListRequest::ToJson(this->Model());
}

JsonValue GetPlayedTitleListRequest::ToJson(const PFAccountManagementGetPlayedTitleListRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetPlayedTitleListResult::FromJson(const JsonValue& input)
{
    CStringVector titleIds{};
    JsonUtils::ObjectGetMember(input, "TitleIds", titleIds);
    this->SetTitleIds(std::move(titleIds));
}

size_t GetPlayedTitleListResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayedTitleListResult const*> GetPlayedTitleListResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayedTitleListResult>(&this->Model());
}

size_t GetPlayedTitleListResult::RequiredBufferSize(const PFAccountManagementGetPlayedTitleListResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.titleIdsCount);
    for (size_t i = 0; i < model.titleIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.titleIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT GetPlayedTitleListResult::Copy(const PFAccountManagementGetPlayedTitleListResult& input, PFAccountManagementGetPlayedTitleListResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.titleIds, input.titleIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayerIdFromAuthTokenRequest::ToJson() const
{
    return GetPlayerIdFromAuthTokenRequest::ToJson(this->Model());
}

JsonValue GetPlayerIdFromAuthTokenRequest::ToJson(const PFAccountManagementGetPlayerIdFromAuthTokenRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Token", input.token);
    JsonUtils::ObjectAddMember(output, "TokenType", input.tokenType);
    return output;
}

void GetPlayerIdFromAuthTokenResult::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t GetPlayerIdFromAuthTokenResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayerIdFromAuthTokenResult const*> GetPlayerIdFromAuthTokenResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerIdFromAuthTokenResult>(&this->Model());
}

size_t GetPlayerIdFromAuthTokenResult::RequiredBufferSize(const PFAccountManagementGetPlayerIdFromAuthTokenResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT GetPlayerIdFromAuthTokenResult::Copy(const PFAccountManagementGetPlayerIdFromAuthTokenResult& input, PFAccountManagementGetPlayerIdFromAuthTokenResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayerProfileRequest::ToJson() const
{
    return GetPlayerProfileRequest::ToJson(this->Model());
}

JsonValue GetPlayerProfileRequest::ToJson(const PFAccountManagementGetPlayerProfileRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    return output;
}

void GetPlayerProfileResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<PlayerProfileModel> playerProfile{};
    JsonUtils::ObjectGetMember(input, "PlayerProfile", playerProfile);
    if (playerProfile)
    {
        this->SetPlayerProfile(std::move(*playerProfile));
    }
}

size_t GetPlayerProfileResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayerProfileResult const*> GetPlayerProfileResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerProfileResult>(&this->Model());
}

size_t GetPlayerProfileResult::RequiredBufferSize(const PFAccountManagementGetPlayerProfileResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playerProfile)
    {
        requiredSize += PlayerProfileModel::RequiredBufferSize(*model.playerProfile);
    }
    return requiredSize;
}

HRESULT GetPlayerProfileResult::Copy(const PFAccountManagementGetPlayerProfileResult& input, PFAccountManagementGetPlayerProfileResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerProfileModel>(input.playerProfile); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerProfile = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LookupUserAccountInfoRequest::ToJson() const
{
    return LookupUserAccountInfoRequest::ToJson(this->Model());
}

JsonValue LookupUserAccountInfoRequest::ToJson(const PFAccountManagementLookupUserAccountInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "TitleDisplayName", input.titleDisplayName);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    return output;
}

void LookupUserAccountInfoResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<UserAccountInfo> userInfo{};
    JsonUtils::ObjectGetMember(input, "UserInfo", userInfo);
    if (userInfo)
    {
        this->SetUserInfo(std::move(*userInfo));
    }
}

size_t LookupUserAccountInfoResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementLookupUserAccountInfoResult const*> LookupUserAccountInfoResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LookupUserAccountInfoResult>(&this->Model());
}

size_t LookupUserAccountInfoResult::RequiredBufferSize(const PFAccountManagementLookupUserAccountInfoResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.userInfo)
    {
        requiredSize += UserAccountInfo::RequiredBufferSize(*model.userInfo);
    }
    return requiredSize;
}

HRESULT LookupUserAccountInfoResult::Copy(const PFAccountManagementLookupUserAccountInfoResult& input, PFAccountManagementLookupUserAccountInfoResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<UserAccountInfo>(input.userInfo); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userInfo = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetUserBansRequest::ToJson() const
{
    return GetUserBansRequest::ToJson(this->Model());
}

JsonValue GetUserBansRequest::ToJson(const PFAccountManagementGetUserBansRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetUserBansResult::FromJson(const JsonValue& input)
{
    ModelVector<BanInfo> banData{};
    JsonUtils::ObjectGetMember<BanInfo>(input, "BanData", banData);
    this->SetBanData(std::move(banData));
}

size_t GetUserBansResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetUserBansResult const*> GetUserBansResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetUserBansResult>(&this->Model());
}

size_t GetUserBansResult::RequiredBufferSize(const PFAccountManagementGetUserBansResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementBanInfo*) + sizeof(PFAccountManagementBanInfo*) * model.banDataCount);
    for (size_t i = 0; i < model.banDataCount; ++i)
    {
        requiredSize += BanInfo::RequiredBufferSize(*model.banData[i]);
    }
    return requiredSize;
}

HRESULT GetUserBansResult::Copy(const PFAccountManagementGetUserBansResult& input, PFAccountManagementGetUserBansResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BanInfo>(input.banData, input.banDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ResetPasswordRequest::ToJson() const
{
    return ResetPasswordRequest::ToJson(this->Model());
}

JsonValue ResetPasswordRequest::ToJson(const PFAccountManagementResetPasswordRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Password", input.password);
    JsonUtils::ObjectAddMember(output, "Token", input.token);
    return output;
}

JsonValue RevokeAllBansForUserRequest::ToJson() const
{
    return RevokeAllBansForUserRequest::ToJson(this->Model());
}

JsonValue RevokeAllBansForUserRequest::ToJson(const PFAccountManagementRevokeAllBansForUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void RevokeAllBansForUserResult::FromJson(const JsonValue& input)
{
    ModelVector<BanInfo> banData{};
    JsonUtils::ObjectGetMember<BanInfo>(input, "BanData", banData);
    this->SetBanData(std::move(banData));
}

size_t RevokeAllBansForUserResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementRevokeAllBansForUserResult const*> RevokeAllBansForUserResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RevokeAllBansForUserResult>(&this->Model());
}

size_t RevokeAllBansForUserResult::RequiredBufferSize(const PFAccountManagementRevokeAllBansForUserResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementBanInfo*) + sizeof(PFAccountManagementBanInfo*) * model.banDataCount);
    for (size_t i = 0; i < model.banDataCount; ++i)
    {
        requiredSize += BanInfo::RequiredBufferSize(*model.banData[i]);
    }
    return requiredSize;
}

HRESULT RevokeAllBansForUserResult::Copy(const PFAccountManagementRevokeAllBansForUserResult& input, PFAccountManagementRevokeAllBansForUserResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BanInfo>(input.banData, input.banDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RevokeBansRequest::ToJson() const
{
    return RevokeBansRequest::ToJson(this->Model());
}

JsonValue RevokeBansRequest::ToJson(const PFAccountManagementRevokeBansRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "BanIds", input.banIds, input.banIdsCount);
    return output;
}

void RevokeBansResult::FromJson(const JsonValue& input)
{
    ModelVector<BanInfo> banData{};
    JsonUtils::ObjectGetMember<BanInfo>(input, "BanData", banData);
    this->SetBanData(std::move(banData));
}

size_t RevokeBansResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementRevokeBansResult const*> RevokeBansResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RevokeBansResult>(&this->Model());
}

size_t RevokeBansResult::RequiredBufferSize(const PFAccountManagementRevokeBansResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementBanInfo*) + sizeof(PFAccountManagementBanInfo*) * model.banDataCount);
    for (size_t i = 0; i < model.banDataCount; ++i)
    {
        requiredSize += BanInfo::RequiredBufferSize(*model.banData[i]);
    }
    return requiredSize;
}

HRESULT RevokeBansResult::Copy(const PFAccountManagementRevokeBansResult& input, PFAccountManagementRevokeBansResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BanInfo>(input.banData, input.banDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdminSendAccountRecoveryEmailRequest::ToJson() const
{
    return AdminSendAccountRecoveryEmailRequest::ToJson(this->Model());
}

JsonValue AdminSendAccountRecoveryEmailRequest::ToJson(const PFAccountManagementAdminSendAccountRecoveryEmailRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember(output, "EmailTemplateId", input.emailTemplateId);
    return output;
}

JsonValue SetMembershipOverrideRequest::ToJson() const
{
    return SetMembershipOverrideRequest::ToJson(this->Model());
}

JsonValue SetMembershipOverrideRequest::ToJson(const PFAccountManagementSetMembershipOverrideRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberTime(output, "ExpirationTime", input.expirationTime);
    JsonUtils::ObjectAddMember(output, "MembershipId", input.membershipId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue UpdateBanRequest::ToJson() const
{
    return UpdateBanRequest::ToJson(this->Model());
}

JsonValue UpdateBanRequest::ToJson(const PFAccountManagementUpdateBanRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Active", input.active);
    JsonUtils::ObjectAddMember(output, "BanId", input.banId);
    JsonUtils::ObjectAddMemberTime(output, "Expires", input.expires);
    JsonUtils::ObjectAddMember(output, "IPAddress", input.IPAddress);
    JsonUtils::ObjectAddMember(output, "Permanent", input.permanent);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

JsonValue UpdateBansRequest::ToJson() const
{
    return UpdateBansRequest::ToJson(this->Model());
}

JsonValue UpdateBansRequest::ToJson(const PFAccountManagementUpdateBansRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<UpdateBanRequest>(output, "Bans", input.bans, input.bansCount);
    return output;
}

void UpdateBansResult::FromJson(const JsonValue& input)
{
    ModelVector<BanInfo> banData{};
    JsonUtils::ObjectGetMember<BanInfo>(input, "BanData", banData);
    this->SetBanData(std::move(banData));
}

size_t UpdateBansResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementUpdateBansResult const*> UpdateBansResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateBansResult>(&this->Model());
}

size_t UpdateBansResult::RequiredBufferSize(const PFAccountManagementUpdateBansResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementBanInfo*) + sizeof(PFAccountManagementBanInfo*) * model.banDataCount);
    for (size_t i = 0; i < model.banDataCount; ++i)
    {
        requiredSize += BanInfo::RequiredBufferSize(*model.banData[i]);
    }
    return requiredSize;
}

HRESULT UpdateBansResult::Copy(const PFAccountManagementUpdateBansResult& input, PFAccountManagementUpdateBansResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BanInfo>(input.banData, input.banDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.banData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdminUpdateUserTitleDisplayNameRequest::ToJson() const
{
    return AdminUpdateUserTitleDisplayNameRequest::ToJson(this->Model());
}

JsonValue AdminUpdateUserTitleDisplayNameRequest::ToJson(const PFAccountManagementAdminUpdateUserTitleDisplayNameRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DisplayName", input.displayName);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void UpdateUserTitleDisplayNameResult::FromJson(const JsonValue& input)
{
    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));
}

size_t UpdateUserTitleDisplayNameResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementUpdateUserTitleDisplayNameResult const*> UpdateUserTitleDisplayNameResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateUserTitleDisplayNameResult>(&this->Model());
}

size_t UpdateUserTitleDisplayNameResult::RequiredBufferSize(const PFAccountManagementUpdateUserTitleDisplayNameResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    return requiredSize;
}

HRESULT UpdateUserTitleDisplayNameResult::Copy(const PFAccountManagementUpdateUserTitleDisplayNameResult& input, PFAccountManagementUpdateUserTitleDisplayNameResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GenericServiceId::ToJson() const
{
    return GenericServiceId::ToJson(this->Model());
}

JsonValue GenericServiceId::ToJson(const PFAccountManagementGenericServiceId& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ServiceName", input.serviceName);
    JsonUtils::ObjectAddMember(output, "UserId", input.userId);
    return output;
}

void GenericServiceId::FromJson(const JsonValue& input)
{
    String serviceName{};
    JsonUtils::ObjectGetMember(input, "ServiceName", serviceName);
    this->SetServiceName(std::move(serviceName));

    String userId{};
    JsonUtils::ObjectGetMember(input, "UserId", userId);
    this->SetUserId(std::move(userId));
}

size_t GenericServiceId::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGenericServiceId const*> GenericServiceId::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GenericServiceId>(&this->Model());
}

size_t GenericServiceId::RequiredBufferSize(const PFAccountManagementGenericServiceId& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.serviceName)
    {
        requiredSize += (std::strlen(model.serviceName) + 1);
    }
    if (model.userId)
    {
        requiredSize += (std::strlen(model.userId) + 1);
    }
    return requiredSize;
}

HRESULT GenericServiceId::Copy(const PFAccountManagementGenericServiceId& input, PFAccountManagementGenericServiceId& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.serviceName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serviceName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.userId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientAddGenericIDRequest::ToJson() const
{
    return ClientAddGenericIDRequest::ToJson(this->Model());
}

JsonValue ClientAddGenericIDRequest::ToJson(const PFAccountManagementClientAddGenericIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<GenericServiceId>(output, "GenericId", input.genericId);
    return output;
}

JsonValue AddOrUpdateContactEmailRequest::ToJson() const
{
    return AddOrUpdateContactEmailRequest::ToJson(this->Model());
}

JsonValue AddOrUpdateContactEmailRequest::ToJson(const PFAccountManagementAddOrUpdateContactEmailRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EmailAddress", input.emailAddress);
    return output;
}

JsonValue AddUsernamePasswordRequest::ToJson() const
{
    return AddUsernamePasswordRequest::ToJson(this->Model());
}

JsonValue AddUsernamePasswordRequest::ToJson(const PFAccountManagementAddUsernamePasswordRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember(output, "Password", input.password);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    return output;
}

void AddUsernamePasswordResult::FromJson(const JsonValue& input)
{
    String username{};
    JsonUtils::ObjectGetMember(input, "Username", username);
    this->SetUsername(std::move(username));
}

size_t AddUsernamePasswordResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementAddUsernamePasswordResult const*> AddUsernamePasswordResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AddUsernamePasswordResult>(&this->Model());
}

size_t AddUsernamePasswordResult::RequiredBufferSize(const PFAccountManagementAddUsernamePasswordResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.username)
    {
        requiredSize += (std::strlen(model.username) + 1);
    }
    return requiredSize;
}

HRESULT AddUsernamePasswordResult::Copy(const PFAccountManagementAddUsernamePasswordResult& input, PFAccountManagementAddUsernamePasswordResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.username); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.username = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetAccountInfoRequest::ToJson() const
{
    return GetAccountInfoRequest::ToJson(this->Model());
}

JsonValue GetAccountInfoRequest::ToJson(const PFAccountManagementGetAccountInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "TitleDisplayName", input.titleDisplayName);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    return output;
}

void GetAccountInfoResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<UserAccountInfo> accountInfo{};
    JsonUtils::ObjectGetMember(input, "AccountInfo", accountInfo);
    if (accountInfo)
    {
        this->SetAccountInfo(std::move(*accountInfo));
    }
}

size_t GetAccountInfoResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetAccountInfoResult const*> GetAccountInfoResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetAccountInfoResult>(&this->Model());
}

size_t GetAccountInfoResult::RequiredBufferSize(const PFAccountManagementGetAccountInfoResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.accountInfo)
    {
        requiredSize += UserAccountInfo::RequiredBufferSize(*model.accountInfo);
    }
    return requiredSize;
}

HRESULT GetAccountInfoResult::Copy(const PFAccountManagementGetAccountInfoResult& input, PFAccountManagementGetAccountInfoResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<UserAccountInfo>(input.accountInfo); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.accountInfo = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayerCombinedInfoRequest::ToJson() const
{
    return GetPlayerCombinedInfoRequest::ToJson(this->Model());
}

JsonValue GetPlayerCombinedInfoRequest::ToJson(const PFAccountManagementGetPlayerCombinedInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetPlayerCombinedInfoResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<GetPlayerCombinedInfoResultPayload> infoResultPayload{};
    JsonUtils::ObjectGetMember(input, "InfoResultPayload", infoResultPayload);
    if (infoResultPayload)
    {
        this->SetInfoResultPayload(std::move(*infoResultPayload));
    }

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t GetPlayerCombinedInfoResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayerCombinedInfoResult const*> GetPlayerCombinedInfoResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerCombinedInfoResult>(&this->Model());
}

size_t GetPlayerCombinedInfoResult::RequiredBufferSize(const PFAccountManagementGetPlayerCombinedInfoResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.infoResultPayload)
    {
        requiredSize += GetPlayerCombinedInfoResultPayload::RequiredBufferSize(*model.infoResultPayload);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT GetPlayerCombinedInfoResult::Copy(const PFAccountManagementGetPlayerCombinedInfoResult& input, PFAccountManagementGetPlayerCombinedInfoResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<GetPlayerCombinedInfoResultPayload>(input.infoResultPayload); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.infoResultPayload = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromFacebookIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromFacebookIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromFacebookIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "FacebookIDs", input.facebookIDs, input.facebookIDsCount);
    return output;
}

void FacebookPlayFabIdPair::FromJson(const JsonValue& input)
{
    String facebookId{};
    JsonUtils::ObjectGetMember(input, "FacebookId", facebookId);
    this->SetFacebookId(std::move(facebookId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t FacebookPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementFacebookPlayFabIdPair const*> FacebookPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FacebookPlayFabIdPair>(&this->Model());
}

size_t FacebookPlayFabIdPair::RequiredBufferSize(const PFAccountManagementFacebookPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.facebookId)
    {
        requiredSize += (std::strlen(model.facebookId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT FacebookPlayFabIdPair::Copy(const PFAccountManagementFacebookPlayFabIdPair& input, PFAccountManagementFacebookPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.facebookId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.facebookId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromFacebookIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<FacebookPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<FacebookPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromFacebookIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromFacebookIDsResult const*> GetPlayFabIDsFromFacebookIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromFacebookIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromFacebookIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromFacebookIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementFacebookPlayFabIdPair*) + sizeof(PFAccountManagementFacebookPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += FacebookPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromFacebookIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromFacebookIDsResult& input, PFAccountManagementGetPlayFabIDsFromFacebookIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<FacebookPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromFacebookInstantGamesIdsRequest::ToJson() const
{
    return GetPlayFabIDsFromFacebookInstantGamesIdsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromFacebookInstantGamesIdsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "FacebookInstantGamesIds", input.facebookInstantGamesIds, input.facebookInstantGamesIdsCount);
    return output;
}

void FacebookInstantGamesPlayFabIdPair::FromJson(const JsonValue& input)
{
    String facebookInstantGamesId{};
    JsonUtils::ObjectGetMember(input, "FacebookInstantGamesId", facebookInstantGamesId);
    this->SetFacebookInstantGamesId(std::move(facebookInstantGamesId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t FacebookInstantGamesPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementFacebookInstantGamesPlayFabIdPair const*> FacebookInstantGamesPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FacebookInstantGamesPlayFabIdPair>(&this->Model());
}

size_t FacebookInstantGamesPlayFabIdPair::RequiredBufferSize(const PFAccountManagementFacebookInstantGamesPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.facebookInstantGamesId)
    {
        requiredSize += (std::strlen(model.facebookInstantGamesId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT FacebookInstantGamesPlayFabIdPair::Copy(const PFAccountManagementFacebookInstantGamesPlayFabIdPair& input, PFAccountManagementFacebookInstantGamesPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.facebookInstantGamesId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.facebookInstantGamesId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromFacebookInstantGamesIdsResult::FromJson(const JsonValue& input)
{
    ModelVector<FacebookInstantGamesPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<FacebookInstantGamesPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromFacebookInstantGamesIdsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult const*> GetPlayFabIDsFromFacebookInstantGamesIdsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(&this->Model());
}

size_t GetPlayFabIDsFromFacebookInstantGamesIdsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementFacebookInstantGamesPlayFabIdPair*) + sizeof(PFAccountManagementFacebookInstantGamesPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += FacebookInstantGamesPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromFacebookInstantGamesIdsResult::Copy(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult& input, PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<FacebookInstantGamesPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromGameCenterIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromGameCenterIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromGameCenterIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "GameCenterIDs", input.gameCenterIDs, input.gameCenterIDsCount);
    return output;
}

void GameCenterPlayFabIdPair::FromJson(const JsonValue& input)
{
    String gameCenterId{};
    JsonUtils::ObjectGetMember(input, "GameCenterId", gameCenterId);
    this->SetGameCenterId(std::move(gameCenterId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t GameCenterPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGameCenterPlayFabIdPair const*> GameCenterPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GameCenterPlayFabIdPair>(&this->Model());
}

size_t GameCenterPlayFabIdPair::RequiredBufferSize(const PFAccountManagementGameCenterPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.gameCenterId)
    {
        requiredSize += (std::strlen(model.gameCenterId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT GameCenterPlayFabIdPair::Copy(const PFAccountManagementGameCenterPlayFabIdPair& input, PFAccountManagementGameCenterPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.gameCenterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameCenterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromGameCenterIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<GameCenterPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<GameCenterPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromGameCenterIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult const*> GetPlayFabIDsFromGameCenterIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromGameCenterIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromGameCenterIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementGameCenterPlayFabIdPair*) + sizeof(PFAccountManagementGameCenterPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += GameCenterPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromGameCenterIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult& input, PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GameCenterPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromGenericIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromGenericIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromGenericIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromGenericIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<GenericServiceId>(output, "GenericIDs", input.genericIDs, input.genericIDsCount);
    return output;
}

void GenericPlayFabIdPair::FromJson(const JsonValue& input)
{
    StdExtra::optional<GenericServiceId> genericId{};
    JsonUtils::ObjectGetMember(input, "GenericId", genericId);
    if (genericId)
    {
        this->SetGenericId(std::move(*genericId));
    }

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t GenericPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGenericPlayFabIdPair const*> GenericPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GenericPlayFabIdPair>(&this->Model());
}

size_t GenericPlayFabIdPair::RequiredBufferSize(const PFAccountManagementGenericPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.genericId)
    {
        requiredSize += GenericServiceId::RequiredBufferSize(*model.genericId);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT GenericPlayFabIdPair::Copy(const PFAccountManagementGenericPlayFabIdPair& input, PFAccountManagementGenericPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<GenericServiceId>(input.genericId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.genericId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromGenericIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<GenericPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<GenericPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromGenericIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromGenericIDsResult const*> GetPlayFabIDsFromGenericIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromGenericIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromGenericIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromGenericIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementGenericPlayFabIdPair*) + sizeof(PFAccountManagementGenericPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += GenericPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromGenericIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromGenericIDsResult& input, PFAccountManagementGetPlayFabIDsFromGenericIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GenericPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromGoogleIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromGoogleIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromGoogleIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "GoogleIDs", input.googleIDs, input.googleIDsCount);
    return output;
}

void GooglePlayFabIdPair::FromJson(const JsonValue& input)
{
    String googleId{};
    JsonUtils::ObjectGetMember(input, "GoogleId", googleId);
    this->SetGoogleId(std::move(googleId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t GooglePlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGooglePlayFabIdPair const*> GooglePlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GooglePlayFabIdPair>(&this->Model());
}

size_t GooglePlayFabIdPair::RequiredBufferSize(const PFAccountManagementGooglePlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.googleId)
    {
        requiredSize += (std::strlen(model.googleId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT GooglePlayFabIdPair::Copy(const PFAccountManagementGooglePlayFabIdPair& input, PFAccountManagementGooglePlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.googleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.googleId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromGoogleIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<GooglePlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<GooglePlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromGoogleIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromGoogleIDsResult const*> GetPlayFabIDsFromGoogleIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromGoogleIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromGoogleIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromGoogleIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementGooglePlayFabIdPair*) + sizeof(PFAccountManagementGooglePlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += GooglePlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromGoogleIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromGoogleIDsResult& input, PFAccountManagementGetPlayFabIDsFromGoogleIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GooglePlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "GooglePlayGamesPlayerIDs", input.googlePlayGamesPlayerIDs, input.googlePlayGamesPlayerIDsCount);
    return output;
}

void GooglePlayGamesPlayFabIdPair::FromJson(const JsonValue& input)
{
    String googlePlayGamesPlayerId{};
    JsonUtils::ObjectGetMember(input, "GooglePlayGamesPlayerId", googlePlayGamesPlayerId);
    this->SetGooglePlayGamesPlayerId(std::move(googlePlayGamesPlayerId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t GooglePlayGamesPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGooglePlayGamesPlayFabIdPair const*> GooglePlayGamesPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GooglePlayGamesPlayFabIdPair>(&this->Model());
}

size_t GooglePlayGamesPlayFabIdPair::RequiredBufferSize(const PFAccountManagementGooglePlayGamesPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.googlePlayGamesPlayerId)
    {
        requiredSize += (std::strlen(model.googlePlayGamesPlayerId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT GooglePlayGamesPlayFabIdPair::Copy(const PFAccountManagementGooglePlayGamesPlayFabIdPair& input, PFAccountManagementGooglePlayGamesPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.googlePlayGamesPlayerId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.googlePlayGamesPlayerId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromGooglePlayGamesPlayerIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<GooglePlayGamesPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<GooglePlayGamesPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromGooglePlayGamesPlayerIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult const*> GetPlayFabIDsFromGooglePlayGamesPlayerIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromGooglePlayGamesPlayerIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromGooglePlayGamesPlayerIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementGooglePlayGamesPlayFabIdPair*) + sizeof(PFAccountManagementGooglePlayGamesPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += GooglePlayGamesPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromGooglePlayGamesPlayerIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult& input, PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GooglePlayGamesPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromKongregateIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromKongregateIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromKongregateIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "KongregateIDs", input.kongregateIDs, input.kongregateIDsCount);
    return output;
}

void KongregatePlayFabIdPair::FromJson(const JsonValue& input)
{
    String kongregateId{};
    JsonUtils::ObjectGetMember(input, "KongregateId", kongregateId);
    this->SetKongregateId(std::move(kongregateId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t KongregatePlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementKongregatePlayFabIdPair const*> KongregatePlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<KongregatePlayFabIdPair>(&this->Model());
}

size_t KongregatePlayFabIdPair::RequiredBufferSize(const PFAccountManagementKongregatePlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.kongregateId)
    {
        requiredSize += (std::strlen(model.kongregateId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT KongregatePlayFabIdPair::Copy(const PFAccountManagementKongregatePlayFabIdPair& input, PFAccountManagementKongregatePlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.kongregateId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.kongregateId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromKongregateIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<KongregatePlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<KongregatePlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromKongregateIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromKongregateIDsResult const*> GetPlayFabIDsFromKongregateIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromKongregateIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromKongregateIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromKongregateIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementKongregatePlayFabIdPair*) + sizeof(PFAccountManagementKongregatePlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += KongregatePlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromKongregateIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromKongregateIDsResult& input, PFAccountManagementGetPlayFabIDsFromKongregateIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<KongregatePlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromNintendoServiceAccountIdsRequest::ToJson() const
{
    return GetPlayFabIDsFromNintendoServiceAccountIdsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromNintendoServiceAccountIdsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "NintendoAccountIds", input.nintendoAccountIds, input.nintendoAccountIdsCount);
    return output;
}

void NintendoServiceAccountPlayFabIdPair::FromJson(const JsonValue& input)
{
    String nintendoServiceAccountId{};
    JsonUtils::ObjectGetMember(input, "NintendoServiceAccountId", nintendoServiceAccountId);
    this->SetNintendoServiceAccountId(std::move(nintendoServiceAccountId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t NintendoServiceAccountPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementNintendoServiceAccountPlayFabIdPair const*> NintendoServiceAccountPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<NintendoServiceAccountPlayFabIdPair>(&this->Model());
}

size_t NintendoServiceAccountPlayFabIdPair::RequiredBufferSize(const PFAccountManagementNintendoServiceAccountPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.nintendoServiceAccountId)
    {
        requiredSize += (std::strlen(model.nintendoServiceAccountId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT NintendoServiceAccountPlayFabIdPair::Copy(const PFAccountManagementNintendoServiceAccountPlayFabIdPair& input, PFAccountManagementNintendoServiceAccountPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.nintendoServiceAccountId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nintendoServiceAccountId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromNintendoServiceAccountIdsResult::FromJson(const JsonValue& input)
{
    ModelVector<NintendoServiceAccountPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<NintendoServiceAccountPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromNintendoServiceAccountIdsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult const*> GetPlayFabIDsFromNintendoServiceAccountIdsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromNintendoServiceAccountIdsResult>(&this->Model());
}

size_t GetPlayFabIDsFromNintendoServiceAccountIdsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementNintendoServiceAccountPlayFabIdPair*) + sizeof(PFAccountManagementNintendoServiceAccountPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += NintendoServiceAccountPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromNintendoServiceAccountIdsResult::Copy(const PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult& input, PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<NintendoServiceAccountPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest::ToJson() const
{
    return GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "NintendoSwitchDeviceIds", input.nintendoSwitchDeviceIds, input.nintendoSwitchDeviceIdsCount);
    return output;
}

void NintendoSwitchPlayFabIdPair::FromJson(const JsonValue& input)
{
    String nintendoSwitchDeviceId{};
    JsonUtils::ObjectGetMember(input, "NintendoSwitchDeviceId", nintendoSwitchDeviceId);
    this->SetNintendoSwitchDeviceId(std::move(nintendoSwitchDeviceId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t NintendoSwitchPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementNintendoSwitchPlayFabIdPair const*> NintendoSwitchPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<NintendoSwitchPlayFabIdPair>(&this->Model());
}

size_t NintendoSwitchPlayFabIdPair::RequiredBufferSize(const PFAccountManagementNintendoSwitchPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.nintendoSwitchDeviceId)
    {
        requiredSize += (std::strlen(model.nintendoSwitchDeviceId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT NintendoSwitchPlayFabIdPair::Copy(const PFAccountManagementNintendoSwitchPlayFabIdPair& input, PFAccountManagementNintendoSwitchPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.nintendoSwitchDeviceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nintendoSwitchDeviceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::FromJson(const JsonValue& input)
{
    ModelVector<NintendoSwitchPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<NintendoSwitchPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult const*> GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(&this->Model());
}

size_t GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementNintendoSwitchPlayFabIdPair*) + sizeof(PFAccountManagementNintendoSwitchPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += NintendoSwitchPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::Copy(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult& input, PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<NintendoSwitchPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromPSNAccountIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromPSNAccountIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromPSNAccountIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IssuerId", input.issuerId);
    JsonUtils::ObjectAddMemberArray(output, "PSNAccountIDs", input.PSNAccountIDs, input.PSNAccountIDsCount);
    return output;
}

void PSNAccountPlayFabIdPair::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String PSNAccountId{};
    JsonUtils::ObjectGetMember(input, "PSNAccountId", PSNAccountId);
    this->SetPSNAccountId(std::move(PSNAccountId));
}

size_t PSNAccountPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementPSNAccountPlayFabIdPair const*> PSNAccountPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PSNAccountPlayFabIdPair>(&this->Model());
}

size_t PSNAccountPlayFabIdPair::RequiredBufferSize(const PFAccountManagementPSNAccountPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.PSNAccountId)
    {
        requiredSize += (std::strlen(model.PSNAccountId) + 1);
    }
    return requiredSize;
}

HRESULT PSNAccountPlayFabIdPair::Copy(const PFAccountManagementPSNAccountPlayFabIdPair& input, PFAccountManagementPSNAccountPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.PSNAccountId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.PSNAccountId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromPSNAccountIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<PSNAccountPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<PSNAccountPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromPSNAccountIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult const*> GetPlayFabIDsFromPSNAccountIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromPSNAccountIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromPSNAccountIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementPSNAccountPlayFabIdPair*) + sizeof(PFAccountManagementPSNAccountPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += PSNAccountPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromPSNAccountIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult& input, PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PSNAccountPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromSteamIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromSteamIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromSteamIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromSteamIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "SteamStringIDs", input.steamStringIDs, input.steamStringIDsCount);
    return output;
}

void SteamPlayFabIdPair::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String steamStringId{};
    JsonUtils::ObjectGetMember(input, "SteamStringId", steamStringId);
    this->SetSteamStringId(std::move(steamStringId));
}

size_t SteamPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementSteamPlayFabIdPair const*> SteamPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SteamPlayFabIdPair>(&this->Model());
}

size_t SteamPlayFabIdPair::RequiredBufferSize(const PFAccountManagementSteamPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.steamStringId)
    {
        requiredSize += (std::strlen(model.steamStringId) + 1);
    }
    return requiredSize;
}

HRESULT SteamPlayFabIdPair::Copy(const PFAccountManagementSteamPlayFabIdPair& input, PFAccountManagementSteamPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.steamStringId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.steamStringId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromSteamIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<SteamPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<SteamPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromSteamIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromSteamIDsResult const*> GetPlayFabIDsFromSteamIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromSteamIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromSteamIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromSteamIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementSteamPlayFabIdPair*) + sizeof(PFAccountManagementSteamPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += SteamPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromSteamIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromSteamIDsResult& input, PFAccountManagementGetPlayFabIDsFromSteamIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<SteamPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromTwitchIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromTwitchIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromTwitchIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "TwitchIds", input.twitchIds, input.twitchIdsCount);
    return output;
}

void TwitchPlayFabIdPair::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String twitchId{};
    JsonUtils::ObjectGetMember(input, "TwitchId", twitchId);
    this->SetTwitchId(std::move(twitchId));
}

size_t TwitchPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementTwitchPlayFabIdPair const*> TwitchPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TwitchPlayFabIdPair>(&this->Model());
}

size_t TwitchPlayFabIdPair::RequiredBufferSize(const PFAccountManagementTwitchPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.twitchId)
    {
        requiredSize += (std::strlen(model.twitchId) + 1);
    }
    return requiredSize;
}

HRESULT TwitchPlayFabIdPair::Copy(const PFAccountManagementTwitchPlayFabIdPair& input, PFAccountManagementTwitchPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.twitchId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.twitchId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromTwitchIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<TwitchPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<TwitchPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromTwitchIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromTwitchIDsResult const*> GetPlayFabIDsFromTwitchIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromTwitchIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromTwitchIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromTwitchIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementTwitchPlayFabIdPair*) + sizeof(PFAccountManagementTwitchPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += TwitchPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromTwitchIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromTwitchIDsResult& input, PFAccountManagementGetPlayFabIDsFromTwitchIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<TwitchPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayFabIDsFromXboxLiveIDsRequest::ToJson() const
{
    return GetPlayFabIDsFromXboxLiveIDsRequest::ToJson(this->Model());
}

JsonValue GetPlayFabIDsFromXboxLiveIDsRequest::ToJson(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Sandbox", input.sandbox);
    JsonUtils::ObjectAddMemberArray(output, "XboxLiveAccountIDs", input.xboxLiveAccountIDs, input.xboxLiveAccountIDsCount);
    return output;
}

void XboxLiveAccountPlayFabIdPair::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String xboxLiveAccountId{};
    JsonUtils::ObjectGetMember(input, "XboxLiveAccountId", xboxLiveAccountId);
    this->SetXboxLiveAccountId(std::move(xboxLiveAccountId));
}

size_t XboxLiveAccountPlayFabIdPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementXboxLiveAccountPlayFabIdPair const*> XboxLiveAccountPlayFabIdPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<XboxLiveAccountPlayFabIdPair>(&this->Model());
}

size_t XboxLiveAccountPlayFabIdPair::RequiredBufferSize(const PFAccountManagementXboxLiveAccountPlayFabIdPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.xboxLiveAccountId)
    {
        requiredSize += (std::strlen(model.xboxLiveAccountId) + 1);
    }
    return requiredSize;
}

HRESULT XboxLiveAccountPlayFabIdPair::Copy(const PFAccountManagementXboxLiveAccountPlayFabIdPair& input, PFAccountManagementXboxLiveAccountPlayFabIdPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.xboxLiveAccountId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.xboxLiveAccountId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayFabIDsFromXboxLiveIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<XboxLiveAccountPlayFabIdPair> data{};
    JsonUtils::ObjectGetMember<XboxLiveAccountPlayFabIdPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPlayFabIDsFromXboxLiveIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult const*> GetPlayFabIDsFromXboxLiveIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayFabIDsFromXboxLiveIDsResult>(&this->Model());
}

size_t GetPlayFabIDsFromXboxLiveIDsResult::RequiredBufferSize(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementXboxLiveAccountPlayFabIdPair*) + sizeof(PFAccountManagementXboxLiveAccountPlayFabIdPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += XboxLiveAccountPlayFabIdPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetPlayFabIDsFromXboxLiveIDsResult::Copy(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult& input, PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<XboxLiveAccountPlayFabIdPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LinkAndroidDeviceIDRequest::ToJson() const
{
    return LinkAndroidDeviceIDRequest::ToJson(this->Model());
}

JsonValue LinkAndroidDeviceIDRequest::ToJson(const PFAccountManagementLinkAndroidDeviceIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AndroidDevice", input.androidDevice);
    JsonUtils::ObjectAddMember(output, "AndroidDeviceId", input.androidDeviceId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "OS", input.OS);
    return output;
}

JsonValue LinkAppleRequest::ToJson() const
{
    return LinkAppleRequest::ToJson(this->Model());
}

JsonValue LinkAppleRequest::ToJson(const PFAccountManagementLinkAppleRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "IdentityToken", input.identityToken);
    return output;
}

JsonValue LinkCustomIDRequest::ToJson() const
{
    return LinkCustomIDRequest::ToJson(this->Model());
}

JsonValue LinkCustomIDRequest::ToJson(const PFAccountManagementLinkCustomIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CustomId", input.customId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    return output;
}

JsonValue LinkFacebookAccountRequest::ToJson() const
{
    return LinkFacebookAccountRequest::ToJson(this->Model());
}

JsonValue LinkFacebookAccountRequest::ToJson(const PFAccountManagementLinkFacebookAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessToken", input.accessToken);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    return output;
}

JsonValue LinkFacebookInstantGamesIdRequest::ToJson() const
{
    return LinkFacebookInstantGamesIdRequest::ToJson(this->Model());
}

JsonValue LinkFacebookInstantGamesIdRequest::ToJson(const PFAccountManagementLinkFacebookInstantGamesIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "FacebookInstantGamesSignature", input.facebookInstantGamesSignature);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    return output;
}

JsonValue LinkGameCenterAccountRequest::ToJson() const
{
    return LinkGameCenterAccountRequest::ToJson(this->Model());
}

JsonValue LinkGameCenterAccountRequest::ToJson(const PFAccountManagementLinkGameCenterAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "GameCenterId", input.gameCenterId);
    JsonUtils::ObjectAddMember(output, "PublicKeyUrl", input.publicKeyUrl);
    JsonUtils::ObjectAddMember(output, "Salt", input.salt);
    JsonUtils::ObjectAddMember(output, "Signature", input.signature);
    JsonUtils::ObjectAddMember(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue LinkGoogleAccountRequest::ToJson() const
{
    return LinkGoogleAccountRequest::ToJson(this->Model());
}

JsonValue LinkGoogleAccountRequest::ToJson(const PFAccountManagementLinkGoogleAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "ServerAuthCode", input.serverAuthCode);
    return output;
}

JsonValue LinkGooglePlayGamesServicesAccountRequest::ToJson() const
{
    return LinkGooglePlayGamesServicesAccountRequest::ToJson(this->Model());
}

JsonValue LinkGooglePlayGamesServicesAccountRequest::ToJson(const PFAccountManagementLinkGooglePlayGamesServicesAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "ServerAuthCode", input.serverAuthCode);
    return output;
}

JsonValue LinkIOSDeviceIDRequest::ToJson() const
{
    return LinkIOSDeviceIDRequest::ToJson(this->Model());
}

JsonValue LinkIOSDeviceIDRequest::ToJson(const PFAccountManagementLinkIOSDeviceIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DeviceId", input.deviceId);
    JsonUtils::ObjectAddMember(output, "DeviceModel", input.deviceModel);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "OS", input.OS);
    return output;
}

JsonValue LinkKongregateAccountRequest::ToJson() const
{
    return LinkKongregateAccountRequest::ToJson(this->Model());
}

JsonValue LinkKongregateAccountRequest::ToJson(const PFAccountManagementLinkKongregateAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthTicket", input.authTicket);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "KongregateId", input.kongregateId);
    return output;
}

JsonValue ClientLinkNintendoServiceAccountRequest::ToJson() const
{
    return ClientLinkNintendoServiceAccountRequest::ToJson(this->Model());
}

JsonValue ClientLinkNintendoServiceAccountRequest::ToJson(const PFAccountManagementClientLinkNintendoServiceAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "IdentityToken", input.identityToken);
    return output;
}

JsonValue ClientLinkNintendoSwitchDeviceIdRequest::ToJson() const
{
    return ClientLinkNintendoSwitchDeviceIdRequest::ToJson(this->Model());
}

JsonValue ClientLinkNintendoSwitchDeviceIdRequest::ToJson(const PFAccountManagementClientLinkNintendoSwitchDeviceIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "NintendoSwitchDeviceId", input.nintendoSwitchDeviceId);
    return output;
}

JsonValue LinkOpenIdConnectRequest::ToJson() const
{
    return LinkOpenIdConnectRequest::ToJson(this->Model());
}

JsonValue LinkOpenIdConnectRequest::ToJson(const PFAccountManagementLinkOpenIdConnectRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConnectionId", input.connectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "IdToken", input.idToken);
    return output;
}

JsonValue ClientLinkPSNAccountRequest::ToJson() const
{
    return ClientLinkPSNAccountRequest::ToJson(this->Model());
}

JsonValue ClientLinkPSNAccountRequest::ToJson(const PFAccountManagementClientLinkPSNAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthCode", input.authCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "IssuerId", input.issuerId);
    JsonUtils::ObjectAddMember(output, "RedirectUri", input.redirectUri);
    return output;
}

JsonValue LinkSteamAccountRequest::ToJson() const
{
    return LinkSteamAccountRequest::ToJson(this->Model());
}

JsonValue LinkSteamAccountRequest::ToJson(const PFAccountManagementLinkSteamAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "SteamTicket", input.steamTicket);
    return output;
}

JsonValue LinkTwitchAccountRequest::ToJson() const
{
    return LinkTwitchAccountRequest::ToJson(this->Model());
}

JsonValue LinkTwitchAccountRequest::ToJson(const PFAccountManagementLinkTwitchAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessToken", input.accessToken);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    return output;
}

JsonValue ClientLinkXboxAccountRequest::ToJson() const
{
    return ClientLinkXboxAccountRequest::ToJson(this->Model());
}

JsonValue ClientLinkXboxAccountRequest::ToJson(const PFAccountManagementClientLinkXboxAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

JsonValue RemoveContactEmailRequest::ToJson() const
{
    return RemoveContactEmailRequest::ToJson(this->Model());
}

JsonValue RemoveContactEmailRequest::ToJson(const PFAccountManagementRemoveContactEmailRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue ClientRemoveGenericIDRequest::ToJson() const
{
    return ClientRemoveGenericIDRequest::ToJson(this->Model());
}

JsonValue ClientRemoveGenericIDRequest::ToJson(const PFAccountManagementClientRemoveGenericIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<GenericServiceId>(output, "GenericId", input.genericId);
    return output;
}

JsonValue ReportPlayerClientRequest::ToJson() const
{
    return ReportPlayerClientRequest::ToJson(this->Model());
}

JsonValue ReportPlayerClientRequest::ToJson(const PFAccountManagementReportPlayerClientRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comment", input.comment);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ReporteeId", input.reporteeId);
    return output;
}

void ReportPlayerClientResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "SubmissionsRemaining", this->m_model.submissionsRemaining);
}

size_t ReportPlayerClientResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementReportPlayerClientResult const*> ReportPlayerClientResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ReportPlayerClientResult>(&this->Model());
}

size_t ReportPlayerClientResult::RequiredBufferSize(const PFAccountManagementReportPlayerClientResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT ReportPlayerClientResult::Copy(const PFAccountManagementReportPlayerClientResult& input, PFAccountManagementReportPlayerClientResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue ClientSendAccountRecoveryEmailRequest::ToJson() const
{
    return ClientSendAccountRecoveryEmailRequest::ToJson(this->Model());
}

JsonValue ClientSendAccountRecoveryEmailRequest::ToJson(const PFAccountManagementClientSendAccountRecoveryEmailRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember(output, "EmailTemplateId", input.emailTemplateId);
    JsonUtils::ObjectAddMember(output, "TitleId", input.titleId);
    return output;
}

JsonValue UnlinkAndroidDeviceIDRequest::ToJson() const
{
    return UnlinkAndroidDeviceIDRequest::ToJson(this->Model());
}

JsonValue UnlinkAndroidDeviceIDRequest::ToJson(const PFAccountManagementUnlinkAndroidDeviceIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AndroidDeviceId", input.androidDeviceId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkAppleRequest::ToJson() const
{
    return UnlinkAppleRequest::ToJson(this->Model());
}

JsonValue UnlinkAppleRequest::ToJson(const PFAccountManagementUnlinkAppleRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkCustomIDRequest::ToJson() const
{
    return UnlinkCustomIDRequest::ToJson(this->Model());
}

JsonValue UnlinkCustomIDRequest::ToJson(const PFAccountManagementUnlinkCustomIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CustomId", input.customId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkFacebookAccountRequest::ToJson() const
{
    return UnlinkFacebookAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkFacebookAccountRequest::ToJson(const PFAccountManagementUnlinkFacebookAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkFacebookInstantGamesIdRequest::ToJson() const
{
    return UnlinkFacebookInstantGamesIdRequest::ToJson(this->Model());
}

JsonValue UnlinkFacebookInstantGamesIdRequest::ToJson(const PFAccountManagementUnlinkFacebookInstantGamesIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "FacebookInstantGamesId", input.facebookInstantGamesId);
    return output;
}

JsonValue UnlinkGameCenterAccountRequest::ToJson() const
{
    return UnlinkGameCenterAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkGameCenterAccountRequest::ToJson(const PFAccountManagementUnlinkGameCenterAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkGoogleAccountRequest::ToJson() const
{
    return UnlinkGoogleAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkGoogleAccountRequest::ToJson(const PFAccountManagementUnlinkGoogleAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkGooglePlayGamesServicesAccountRequest::ToJson() const
{
    return UnlinkGooglePlayGamesServicesAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkGooglePlayGamesServicesAccountRequest::ToJson(const PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkIOSDeviceIDRequest::ToJson() const
{
    return UnlinkIOSDeviceIDRequest::ToJson(this->Model());
}

JsonValue UnlinkIOSDeviceIDRequest::ToJson(const PFAccountManagementUnlinkIOSDeviceIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DeviceId", input.deviceId);
    return output;
}

JsonValue UnlinkKongregateAccountRequest::ToJson() const
{
    return UnlinkKongregateAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkKongregateAccountRequest::ToJson(const PFAccountManagementUnlinkKongregateAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue ClientUnlinkNintendoServiceAccountRequest::ToJson() const
{
    return ClientUnlinkNintendoServiceAccountRequest::ToJson(this->Model());
}

JsonValue ClientUnlinkNintendoServiceAccountRequest::ToJson(const PFAccountManagementClientUnlinkNintendoServiceAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue ClientUnlinkNintendoSwitchDeviceIdRequest::ToJson() const
{
    return ClientUnlinkNintendoSwitchDeviceIdRequest::ToJson(this->Model());
}

JsonValue ClientUnlinkNintendoSwitchDeviceIdRequest::ToJson(const PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "NintendoSwitchDeviceId", input.nintendoSwitchDeviceId);
    return output;
}

JsonValue UnlinkOpenIdConnectRequest::ToJson() const
{
    return UnlinkOpenIdConnectRequest::ToJson(this->Model());
}

JsonValue UnlinkOpenIdConnectRequest::ToJson(const PFAccountManagementUnlinkOpenIdConnectRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConnectionId", input.connectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue ClientUnlinkPSNAccountRequest::ToJson() const
{
    return ClientUnlinkPSNAccountRequest::ToJson(this->Model());
}

JsonValue ClientUnlinkPSNAccountRequest::ToJson(const PFAccountManagementClientUnlinkPSNAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkSteamAccountRequest::ToJson() const
{
    return UnlinkSteamAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkSteamAccountRequest::ToJson(const PFAccountManagementUnlinkSteamAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UnlinkTwitchAccountRequest::ToJson() const
{
    return UnlinkTwitchAccountRequest::ToJson(this->Model());
}

JsonValue UnlinkTwitchAccountRequest::ToJson(const PFAccountManagementUnlinkTwitchAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessToken", input.accessToken);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue ClientUnlinkXboxAccountRequest::ToJson() const
{
    return ClientUnlinkXboxAccountRequest::ToJson(this->Model());
}

JsonValue ClientUnlinkXboxAccountRequest::ToJson(const PFAccountManagementClientUnlinkXboxAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue ClientUpdateAvatarUrlRequest::ToJson() const
{
    return ClientUpdateAvatarUrlRequest::ToJson(this->Model());
}

JsonValue ClientUpdateAvatarUrlRequest::ToJson(const PFAccountManagementClientUpdateAvatarUrlRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ImageUrl", input.imageUrl);
    return output;
}

JsonValue ClientUpdateUserTitleDisplayNameRequest::ToJson() const
{
    return ClientUpdateUserTitleDisplayNameRequest::ToJson(this->Model());
}

JsonValue ClientUpdateUserTitleDisplayNameRequest::ToJson(const PFAccountManagementClientUpdateUserTitleDisplayNameRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DisplayName", input.displayName);
    return output;
}

JsonValue ServerAddGenericIDRequest::ToJson() const
{
    return ServerAddGenericIDRequest::ToJson(this->Model());
}

JsonValue ServerAddGenericIDRequest::ToJson(const PFAccountManagementServerAddGenericIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<GenericServiceId>(output, "GenericId", input.genericId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue GetServerCustomIDsFromPlayFabIDsRequest::ToJson() const
{
    return GetServerCustomIDsFromPlayFabIDsRequest::ToJson(this->Model());
}

JsonValue GetServerCustomIDsFromPlayFabIDsRequest::ToJson(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "PlayFabIDs", input.playFabIDs, input.playFabIDsCount);
    return output;
}

void ServerCustomIDPlayFabIDPair::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String serverCustomId{};
    JsonUtils::ObjectGetMember(input, "ServerCustomId", serverCustomId);
    this->SetServerCustomId(std::move(serverCustomId));
}

size_t ServerCustomIDPlayFabIDPair::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementServerCustomIDPlayFabIDPair const*> ServerCustomIDPlayFabIDPair::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerCustomIDPlayFabIDPair>(&this->Model());
}

size_t ServerCustomIDPlayFabIDPair::RequiredBufferSize(const PFAccountManagementServerCustomIDPlayFabIDPair& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.serverCustomId)
    {
        requiredSize += (std::strlen(model.serverCustomId) + 1);
    }
    return requiredSize;
}

HRESULT ServerCustomIDPlayFabIDPair::Copy(const PFAccountManagementServerCustomIDPlayFabIDPair& input, PFAccountManagementServerCustomIDPlayFabIDPair& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverCustomId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverCustomId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetServerCustomIDsFromPlayFabIDsResult::FromJson(const JsonValue& input)
{
    ModelVector<ServerCustomIDPlayFabIDPair> data{};
    JsonUtils::ObjectGetMember<ServerCustomIDPlayFabIDPair>(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetServerCustomIDsFromPlayFabIDsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult const*> GetServerCustomIDsFromPlayFabIDsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetServerCustomIDsFromPlayFabIDsResult>(&this->Model());
}

size_t GetServerCustomIDsFromPlayFabIDsResult::RequiredBufferSize(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAccountManagementServerCustomIDPlayFabIDPair*) + sizeof(PFAccountManagementServerCustomIDPlayFabIDPair*) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += ServerCustomIDPlayFabIDPair::RequiredBufferSize(*model.data[i]);
    }
    return requiredSize;
}

HRESULT GetServerCustomIDsFromPlayFabIDsResult::Copy(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult& input, PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ServerCustomIDPlayFabIDPair>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetUserAccountInfoRequest::ToJson() const
{
    return GetUserAccountInfoRequest::ToJson(this->Model());
}

JsonValue GetUserAccountInfoRequest::ToJson(const PFAccountManagementGetUserAccountInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetUserAccountInfoResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<UserAccountInfo> userInfo{};
    JsonUtils::ObjectGetMember(input, "UserInfo", userInfo);
    if (userInfo)
    {
        this->SetUserInfo(std::move(*userInfo));
    }
}

size_t GetUserAccountInfoResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAccountManagementGetUserAccountInfoResult const*> GetUserAccountInfoResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetUserAccountInfoResult>(&this->Model());
}

size_t GetUserAccountInfoResult::RequiredBufferSize(const PFAccountManagementGetUserAccountInfoResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.userInfo)
    {
        requiredSize += UserAccountInfo::RequiredBufferSize(*model.userInfo);
    }
    return requiredSize;
}

HRESULT GetUserAccountInfoResult::Copy(const PFAccountManagementGetUserAccountInfoResult& input, PFAccountManagementGetUserAccountInfoResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<UserAccountInfo>(input.userInfo); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userInfo = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerLinkNintendoServiceAccountRequest::ToJson() const
{
    return ServerLinkNintendoServiceAccountRequest::ToJson(this->Model());
}

JsonValue ServerLinkNintendoServiceAccountRequest::ToJson(const PFAccountManagementServerLinkNintendoServiceAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "IdentityToken", input.identityToken);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerLinkNintendoSwitchDeviceIdRequest::ToJson() const
{
    return ServerLinkNintendoSwitchDeviceIdRequest::ToJson(this->Model());
}

JsonValue ServerLinkNintendoSwitchDeviceIdRequest::ToJson(const PFAccountManagementServerLinkNintendoSwitchDeviceIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "NintendoSwitchDeviceId", input.nintendoSwitchDeviceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerLinkPSNAccountRequest::ToJson() const
{
    return ServerLinkPSNAccountRequest::ToJson(this->Model());
}

JsonValue ServerLinkPSNAccountRequest::ToJson(const PFAccountManagementServerLinkPSNAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthCode", input.authCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "IssuerId", input.issuerId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "RedirectUri", input.redirectUri);
    return output;
}

JsonValue LinkServerCustomIdRequest::ToJson() const
{
    return LinkServerCustomIdRequest::ToJson(this->Model());
}

JsonValue LinkServerCustomIdRequest::ToJson(const PFAccountManagementLinkServerCustomIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "ServerCustomId", input.serverCustomId);
    return output;
}

JsonValue ServerLinkXboxAccountRequest::ToJson() const
{
    return ServerLinkXboxAccountRequest::ToJson(this->Model());
}

JsonValue ServerLinkXboxAccountRequest::ToJson(const PFAccountManagementServerLinkXboxAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceLink", input.forceLink);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

JsonValue ServerRemoveGenericIDRequest::ToJson() const
{
    return ServerRemoveGenericIDRequest::ToJson(this->Model());
}

JsonValue ServerRemoveGenericIDRequest::ToJson(const PFAccountManagementServerRemoveGenericIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<GenericServiceId>(output, "GenericId", input.genericId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue SendCustomAccountRecoveryEmailRequest::ToJson() const
{
    return SendCustomAccountRecoveryEmailRequest::ToJson(this->Model());
}

JsonValue SendCustomAccountRecoveryEmailRequest::ToJson(const PFAccountManagementSendCustomAccountRecoveryEmailRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember(output, "EmailTemplateId", input.emailTemplateId);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    return output;
}

JsonValue SendEmailFromTemplateRequest::ToJson() const
{
    return SendEmailFromTemplateRequest::ToJson(this->Model());
}

JsonValue SendEmailFromTemplateRequest::ToJson(const PFAccountManagementSendEmailFromTemplateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EmailTemplateId", input.emailTemplateId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerUnlinkNintendoServiceAccountRequest::ToJson() const
{
    return ServerUnlinkNintendoServiceAccountRequest::ToJson(this->Model());
}

JsonValue ServerUnlinkNintendoServiceAccountRequest::ToJson(const PFAccountManagementServerUnlinkNintendoServiceAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerUnlinkNintendoSwitchDeviceIdRequest::ToJson() const
{
    return ServerUnlinkNintendoSwitchDeviceIdRequest::ToJson(this->Model());
}

JsonValue ServerUnlinkNintendoSwitchDeviceIdRequest::ToJson(const PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "NintendoSwitchDeviceId", input.nintendoSwitchDeviceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerUnlinkPSNAccountRequest::ToJson() const
{
    return ServerUnlinkPSNAccountRequest::ToJson(this->Model());
}

JsonValue ServerUnlinkPSNAccountRequest::ToJson(const PFAccountManagementServerUnlinkPSNAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue UnlinkServerCustomIdRequest::ToJson() const
{
    return UnlinkServerCustomIdRequest::ToJson(this->Model());
}

JsonValue UnlinkServerCustomIdRequest::ToJson(const PFAccountManagementUnlinkServerCustomIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "ServerCustomId", input.serverCustomId);
    return output;
}

JsonValue ServerUnlinkXboxAccountRequest::ToJson() const
{
    return ServerUnlinkXboxAccountRequest::ToJson(this->Model());
}

JsonValue ServerUnlinkXboxAccountRequest::ToJson(const PFAccountManagementServerUnlinkXboxAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerUpdateAvatarUrlRequest::ToJson() const
{
    return ServerUpdateAvatarUrlRequest::ToJson(this->Model());
}

JsonValue ServerUpdateAvatarUrlRequest::ToJson(const PFAccountManagementServerUpdateAvatarUrlRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ImageUrl", input.imageUrl);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

} // namespace AccountManagement
} // namespace PlayFab
