#pragma once

#include <playfab/cpp/PFLeaderboardDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Leaderboard
{

// Leaderboard Classes
class CreatePlayerStatisticDefinitionRequest : public Wrappers::PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardCreatePlayerStatisticDefinitionRequest& input);

};

class PlayerStatisticDefinition : public Wrappers::PFLeaderboardPlayerStatisticDefinitionWrapper<Allocator>, public OutputModel<PFLeaderboardPlayerStatisticDefinition>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardPlayerStatisticDefinitionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardPlayerStatisticDefinition const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardPlayerStatisticDefinition& model);
    static HRESULT Copy(const PFLeaderboardPlayerStatisticDefinition& input, PFLeaderboardPlayerStatisticDefinition& output, ModelBuffer& buffer);
};

class CreatePlayerStatisticDefinitionResult : public Wrappers::PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper<Allocator>, public OutputModel<PFLeaderboardCreatePlayerStatisticDefinitionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardCreatePlayerStatisticDefinitionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardCreatePlayerStatisticDefinitionResult& model);
    static HRESULT Copy(const PFLeaderboardCreatePlayerStatisticDefinitionResult& input, PFLeaderboardCreatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer);
};

class GetPlayerStatisticDefinitionsResult : public Wrappers::PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper<Allocator>, public OutputModel<PFLeaderboardGetPlayerStatisticDefinitionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardGetPlayerStatisticDefinitionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardGetPlayerStatisticDefinitionsResult& model);
    static HRESULT Copy(const PFLeaderboardGetPlayerStatisticDefinitionsResult& input, PFLeaderboardGetPlayerStatisticDefinitionsResult& output, ModelBuffer& buffer);
};

class GetPlayerStatisticVersionsRequest : public Wrappers::PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardGetPlayerStatisticVersionsRequest& input);

};

class PlayerStatisticVersion : public Wrappers::PFLeaderboardPlayerStatisticVersionWrapper<Allocator>, public OutputModel<PFLeaderboardPlayerStatisticVersion>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardPlayerStatisticVersionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardPlayerStatisticVersion const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardPlayerStatisticVersion& model);
    static HRESULT Copy(const PFLeaderboardPlayerStatisticVersion& input, PFLeaderboardPlayerStatisticVersion& output, ModelBuffer& buffer);
};

class GetPlayerStatisticVersionsResult : public Wrappers::PFLeaderboardGetPlayerStatisticVersionsResultWrapper<Allocator>, public OutputModel<PFLeaderboardGetPlayerStatisticVersionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetPlayerStatisticVersionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardGetPlayerStatisticVersionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardGetPlayerStatisticVersionsResult& model);
    static HRESULT Copy(const PFLeaderboardGetPlayerStatisticVersionsResult& input, PFLeaderboardGetPlayerStatisticVersionsResult& output, ModelBuffer& buffer);
};

class IncrementPlayerStatisticVersionRequest : public Wrappers::PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardIncrementPlayerStatisticVersionRequest& input);

};

class IncrementPlayerStatisticVersionResult : public Wrappers::PFLeaderboardIncrementPlayerStatisticVersionResultWrapper<Allocator>, public OutputModel<PFLeaderboardIncrementPlayerStatisticVersionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardIncrementPlayerStatisticVersionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardIncrementPlayerStatisticVersionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardIncrementPlayerStatisticVersionResult& model);
    static HRESULT Copy(const PFLeaderboardIncrementPlayerStatisticVersionResult& input, PFLeaderboardIncrementPlayerStatisticVersionResult& output, ModelBuffer& buffer);
};

class ResetUserStatisticsRequest : public Wrappers::PFLeaderboardResetUserStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardResetUserStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardResetUserStatisticsRequest& input);

};

class UpdatePlayerStatisticDefinitionRequest : public Wrappers::PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardUpdatePlayerStatisticDefinitionRequest& input);

};

class UpdatePlayerStatisticDefinitionResult : public Wrappers::PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper<Allocator>, public OutputModel<PFLeaderboardUpdatePlayerStatisticDefinitionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardUpdatePlayerStatisticDefinitionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardUpdatePlayerStatisticDefinitionResult& model);
    static HRESULT Copy(const PFLeaderboardUpdatePlayerStatisticDefinitionResult& input, PFLeaderboardUpdatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer);
};

class ClientGetFriendLeaderboardRequest : public Wrappers::PFLeaderboardClientGetFriendLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardClientGetFriendLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardClientGetFriendLeaderboardRequest& input);

};

class PlayerLeaderboardEntry : public Wrappers::PFLeaderboardPlayerLeaderboardEntryWrapper<Allocator>, public OutputModel<PFLeaderboardPlayerLeaderboardEntry>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardPlayerLeaderboardEntryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardPlayerLeaderboardEntry const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardPlayerLeaderboardEntry& model);
    static HRESULT Copy(const PFLeaderboardPlayerLeaderboardEntry& input, PFLeaderboardPlayerLeaderboardEntry& output, ModelBuffer& buffer);
};

class GetLeaderboardResult : public Wrappers::PFLeaderboardGetLeaderboardResultWrapper<Allocator>, public OutputModel<PFLeaderboardGetLeaderboardResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetLeaderboardResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardGetLeaderboardResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardGetLeaderboardResult& model);
    static HRESULT Copy(const PFLeaderboardGetLeaderboardResult& input, PFLeaderboardGetLeaderboardResult& output, ModelBuffer& buffer);
};

class GetFriendLeaderboardAroundPlayerRequest : public Wrappers::PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardGetFriendLeaderboardAroundPlayerRequest& input);

};

class GetFriendLeaderboardAroundPlayerResult : public Wrappers::PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper<Allocator>, public OutputModel<PFLeaderboardGetFriendLeaderboardAroundPlayerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardGetFriendLeaderboardAroundPlayerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardGetFriendLeaderboardAroundPlayerResult& model);
    static HRESULT Copy(const PFLeaderboardGetFriendLeaderboardAroundPlayerResult& input, PFLeaderboardGetFriendLeaderboardAroundPlayerResult& output, ModelBuffer& buffer);
};

class GetLeaderboardRequest : public Wrappers::PFLeaderboardGetLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardGetLeaderboardRequest& input);

};

class GetLeaderboardAroundPlayerRequest : public Wrappers::PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardGetLeaderboardAroundPlayerRequest& input);

};

class GetLeaderboardAroundPlayerResult : public Wrappers::PFLeaderboardGetLeaderboardAroundPlayerResultWrapper<Allocator>, public OutputModel<PFLeaderboardGetLeaderboardAroundPlayerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetLeaderboardAroundPlayerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardGetLeaderboardAroundPlayerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardGetLeaderboardAroundPlayerResult& model);
    static HRESULT Copy(const PFLeaderboardGetLeaderboardAroundPlayerResult& input, PFLeaderboardGetLeaderboardAroundPlayerResult& output, ModelBuffer& buffer);
};

class StatisticNameVersion : public Wrappers::PFLeaderboardStatisticNameVersionWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardStatisticNameVersionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardStatisticNameVersion& input);

};

class ClientGetPlayerStatisticsRequest : public Wrappers::PFLeaderboardClientGetPlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardClientGetPlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardClientGetPlayerStatisticsRequest& input);

};

class ClientGetPlayerStatisticsResult : public Wrappers::PFLeaderboardClientGetPlayerStatisticsResultWrapper<Allocator>, public OutputModel<PFLeaderboardClientGetPlayerStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardClientGetPlayerStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardClientGetPlayerStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardClientGetPlayerStatisticsResult& model);
    static HRESULT Copy(const PFLeaderboardClientGetPlayerStatisticsResult& input, PFLeaderboardClientGetPlayerStatisticsResult& output, ModelBuffer& buffer);
};

class StatisticUpdate : public Wrappers::PFLeaderboardStatisticUpdateWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardStatisticUpdateWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardStatisticUpdate& input);

};

class ClientUpdatePlayerStatisticsRequest : public Wrappers::PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardClientUpdatePlayerStatisticsRequest& input);

};

class ServerGetFriendLeaderboardRequest : public Wrappers::PFLeaderboardServerGetFriendLeaderboardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardServerGetFriendLeaderboardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardServerGetFriendLeaderboardRequest& input);

};

class GetLeaderboardAroundUserRequest : public Wrappers::PFLeaderboardGetLeaderboardAroundUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetLeaderboardAroundUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardGetLeaderboardAroundUserRequest& input);

};

class GetLeaderboardAroundUserResult : public Wrappers::PFLeaderboardGetLeaderboardAroundUserResultWrapper<Allocator>, public OutputModel<PFLeaderboardGetLeaderboardAroundUserResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardGetLeaderboardAroundUserResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardGetLeaderboardAroundUserResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardGetLeaderboardAroundUserResult& model);
    static HRESULT Copy(const PFLeaderboardGetLeaderboardAroundUserResult& input, PFLeaderboardGetLeaderboardAroundUserResult& output, ModelBuffer& buffer);
};

class ServerGetPlayerStatisticsRequest : public Wrappers::PFLeaderboardServerGetPlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardServerGetPlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardServerGetPlayerStatisticsRequest& input);

};

class ServerGetPlayerStatisticsResult : public Wrappers::PFLeaderboardServerGetPlayerStatisticsResultWrapper<Allocator>, public OutputModel<PFLeaderboardServerGetPlayerStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardServerGetPlayerStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLeaderboardServerGetPlayerStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLeaderboardServerGetPlayerStatisticsResult& model);
    static HRESULT Copy(const PFLeaderboardServerGetPlayerStatisticsResult& input, PFLeaderboardServerGetPlayerStatisticsResult& output, ModelBuffer& buffer);
};

class ServerUpdatePlayerStatisticsRequest : public Wrappers::PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLeaderboardServerUpdatePlayerStatisticsRequest& input);

};

} // namespace Leaderboard
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
