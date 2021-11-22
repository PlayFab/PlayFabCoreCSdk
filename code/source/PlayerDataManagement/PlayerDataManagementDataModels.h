#pragma once

#include <playfab/cpp/PFPlayerDataManagementDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace PlayerDataManagement
{

// PlayerDataManagement Classes
class CreatePlayerStatisticDefinitionRequest : public Wrappers::PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest& input);

};

class PlayerStatisticDefinition : public Wrappers::PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Allocator>, public OutputModel<PFPlayerDataManagementPlayerStatisticDefinition>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementPlayerStatisticDefinition const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementPlayerStatisticDefinition& model);
    static HRESULT Copy(const PFPlayerDataManagementPlayerStatisticDefinition& input, PFPlayerDataManagementPlayerStatisticDefinition& output, ModelBuffer& buffer);
};

class CreatePlayerStatisticDefinitionResult : public Wrappers::PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementCreatePlayerStatisticDefinitionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementCreatePlayerStatisticDefinitionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& model);
    static HRESULT Copy(const PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& input, PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer);
};

class GetDataReportRequest : public Wrappers::PFPlayerDataManagementGetDataReportRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetDataReportRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetDataReportRequest& input);

};

class GetDataReportResult : public Wrappers::PFPlayerDataManagementGetDataReportResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetDataReportResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetDataReportResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetDataReportResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetDataReportResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetDataReportResult& input, PFPlayerDataManagementGetDataReportResult& output, ModelBuffer& buffer);
};

class GetPlayerStatisticDefinitionsResult : public Wrappers::PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetPlayerStatisticDefinitionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetPlayerStatisticDefinitionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& input, PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& output, ModelBuffer& buffer);
};

class GetPlayerStatisticVersionsRequest : public Wrappers::PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetPlayerStatisticVersionsRequest& input);

};

class PlayerStatisticVersion : public Wrappers::PFPlayerDataManagementPlayerStatisticVersionWrapper<Allocator>, public OutputModel<PFPlayerDataManagementPlayerStatisticVersion>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementPlayerStatisticVersionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementPlayerStatisticVersion const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementPlayerStatisticVersion& model);
    static HRESULT Copy(const PFPlayerDataManagementPlayerStatisticVersion& input, PFPlayerDataManagementPlayerStatisticVersion& output, ModelBuffer& buffer);
};

class GetPlayerStatisticVersionsResult : public Wrappers::PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetPlayerStatisticVersionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetPlayerStatisticVersionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetPlayerStatisticVersionsResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetPlayerStatisticVersionsResult& input, PFPlayerDataManagementGetPlayerStatisticVersionsResult& output, ModelBuffer& buffer);
};

class GetUserDataRequest : public Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetUserDataRequest& input);

};

class AdminGetUserDataResult : public Wrappers::PFPlayerDataManagementAdminGetUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementAdminGetUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementAdminGetUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementAdminGetUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementAdminGetUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementAdminGetUserDataResult& input, PFPlayerDataManagementAdminGetUserDataResult& output, ModelBuffer& buffer);
};

class IncrementPlayerStatisticVersionRequest : public Wrappers::PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementIncrementPlayerStatisticVersionRequest& input);

};

class IncrementPlayerStatisticVersionResult : public Wrappers::PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementIncrementPlayerStatisticVersionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementIncrementPlayerStatisticVersionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementIncrementPlayerStatisticVersionResult& model);
    static HRESULT Copy(const PFPlayerDataManagementIncrementPlayerStatisticVersionResult& input, PFPlayerDataManagementIncrementPlayerStatisticVersionResult& output, ModelBuffer& buffer);
};

class RefundPurchaseRequest : public Wrappers::PFPlayerDataManagementRefundPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementRefundPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementRefundPurchaseRequest& input);

};

class RefundPurchaseResponse : public Wrappers::PFPlayerDataManagementRefundPurchaseResponseWrapper<Allocator>, public OutputModel<PFPlayerDataManagementRefundPurchaseResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementRefundPurchaseResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementRefundPurchaseResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementRefundPurchaseResponse& model);
    static HRESULT Copy(const PFPlayerDataManagementRefundPurchaseResponse& input, PFPlayerDataManagementRefundPurchaseResponse& output, ModelBuffer& buffer);
};

class ResetUserStatisticsRequest : public Wrappers::PFPlayerDataManagementResetUserStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementResetUserStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementResetUserStatisticsRequest& input);

};

class ResolvePurchaseDisputeRequest : public Wrappers::PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementResolvePurchaseDisputeRequest& input);

};

class ResolvePurchaseDisputeResponse : public Wrappers::PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper<Allocator>, public OutputModel<PFPlayerDataManagementResolvePurchaseDisputeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementResolvePurchaseDisputeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementResolvePurchaseDisputeResponse& model);
    static HRESULT Copy(const PFPlayerDataManagementResolvePurchaseDisputeResponse& input, PFPlayerDataManagementResolvePurchaseDisputeResponse& output, ModelBuffer& buffer);
};

class UpdatePlayerStatisticDefinitionRequest : public Wrappers::PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest& input);

};

class UpdatePlayerStatisticDefinitionResult : public Wrappers::PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& model);
    static HRESULT Copy(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& input, PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer);
};

class AdminUpdateUserDataRequest : public Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementAdminUpdateUserDataRequest& input);

};

class UpdateUserDataResult : public Wrappers::PFPlayerDataManagementUpdateUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementUpdateUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementUpdateUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementUpdateUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementUpdateUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementUpdateUserDataResult& input, PFPlayerDataManagementUpdateUserDataResult& output, ModelBuffer& buffer);
};

class UpdateUserInternalDataRequest : public Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementUpdateUserInternalDataRequest& input);

};

class ClientGetFriendLeaderboardRequest : public Wrappers::PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementClientGetFriendLeaderboardRequest& input);

};

class PlayerLeaderboardEntry : public Wrappers::PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Allocator>, public OutputModel<PFPlayerDataManagementPlayerLeaderboardEntry>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementPlayerLeaderboardEntry const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementPlayerLeaderboardEntry& model);
    static HRESULT Copy(const PFPlayerDataManagementPlayerLeaderboardEntry& input, PFPlayerDataManagementPlayerLeaderboardEntry& output, ModelBuffer& buffer);
};

class GetLeaderboardResult : public Wrappers::PFPlayerDataManagementGetLeaderboardResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetLeaderboardResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetLeaderboardResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetLeaderboardResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetLeaderboardResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetLeaderboardResult& input, PFPlayerDataManagementGetLeaderboardResult& output, ModelBuffer& buffer);
};

class GetFriendLeaderboardAroundPlayerRequest : public Wrappers::PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest& input);

};

class GetFriendLeaderboardAroundPlayerResult : public Wrappers::PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& input, PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& output, ModelBuffer& buffer);
};

class GetLeaderboardRequest : public Wrappers::PFPlayerDataManagementGetLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetLeaderboardRequest& input);

};

class GetLeaderboardAroundPlayerRequest : public Wrappers::PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetLeaderboardAroundPlayerRequest& input);

};

class GetLeaderboardAroundPlayerResult : public Wrappers::PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetLeaderboardAroundPlayerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetLeaderboardAroundPlayerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetLeaderboardAroundPlayerResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetLeaderboardAroundPlayerResult& input, PFPlayerDataManagementGetLeaderboardAroundPlayerResult& output, ModelBuffer& buffer);
};

class StatisticNameVersion : public Wrappers::PFPlayerDataManagementStatisticNameVersionWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementStatisticNameVersionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementStatisticNameVersion& input);

};

class ClientGetPlayerStatisticsRequest : public Wrappers::PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementClientGetPlayerStatisticsRequest& input);

};

class ClientGetPlayerStatisticsResult : public Wrappers::PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementClientGetPlayerStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementClientGetPlayerStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementClientGetPlayerStatisticsResult& model);
    static HRESULT Copy(const PFPlayerDataManagementClientGetPlayerStatisticsResult& input, PFPlayerDataManagementClientGetPlayerStatisticsResult& output, ModelBuffer& buffer);
};

class ClientGetUserDataResult : public Wrappers::PFPlayerDataManagementClientGetUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementClientGetUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientGetUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementClientGetUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementClientGetUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementClientGetUserDataResult& input, PFPlayerDataManagementClientGetUserDataResult& output, ModelBuffer& buffer);
};

class StatisticUpdate : public Wrappers::PFPlayerDataManagementStatisticUpdateWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementStatisticUpdateWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementStatisticUpdate& input);

};

class ClientUpdatePlayerStatisticsRequest : public Wrappers::PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementClientUpdatePlayerStatisticsRequest& input);

};

class ClientUpdateUserDataRequest : public Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementClientUpdateUserDataRequest& input);

};

class ServerGetFriendLeaderboardRequest : public Wrappers::PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementServerGetFriendLeaderboardRequest& input);

};

class GetLeaderboardAroundUserRequest : public Wrappers::PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementGetLeaderboardAroundUserRequest& input);

};

class GetLeaderboardAroundUserResult : public Wrappers::PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementGetLeaderboardAroundUserResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementGetLeaderboardAroundUserResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementGetLeaderboardAroundUserResult& model);
    static HRESULT Copy(const PFPlayerDataManagementGetLeaderboardAroundUserResult& input, PFPlayerDataManagementGetLeaderboardAroundUserResult& output, ModelBuffer& buffer);
};

class ServerGetPlayerStatisticsRequest : public Wrappers::PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementServerGetPlayerStatisticsRequest& input);

};

class ServerGetPlayerStatisticsResult : public Wrappers::PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementServerGetPlayerStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementServerGetPlayerStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementServerGetPlayerStatisticsResult& model);
    static HRESULT Copy(const PFPlayerDataManagementServerGetPlayerStatisticsResult& input, PFPlayerDataManagementServerGetPlayerStatisticsResult& output, ModelBuffer& buffer);
};

class ServerGetUserDataResult : public Wrappers::PFPlayerDataManagementServerGetUserDataResultWrapper<Allocator>, public OutputModel<PFPlayerDataManagementServerGetUserDataResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerGetUserDataResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlayerDataManagementServerGetUserDataResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlayerDataManagementServerGetUserDataResult& model);
    static HRESULT Copy(const PFPlayerDataManagementServerGetUserDataResult& input, PFPlayerDataManagementServerGetUserDataResult& output, ModelBuffer& buffer);
};

class ServerUpdatePlayerStatisticsRequest : public Wrappers::PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementServerUpdatePlayerStatisticsRequest& input);

};

class ServerUpdateUserDataRequest : public Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlayerDataManagementServerUpdateUserDataRequest& input);

};

} // namespace PlayerDataManagement
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
