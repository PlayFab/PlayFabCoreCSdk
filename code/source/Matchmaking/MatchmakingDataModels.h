#pragma once

#include <playfab/cpp/PFMatchmakingDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Matchmaking
{

// Matchmaking Classes
class GetMatchmakerGameInfoRequest : public Wrappers::PFMatchmakingGetMatchmakerGameInfoRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchmakerGameInfoRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGetMatchmakerGameInfoRequest& input);

};

class GetMatchmakerGameInfoResult : public Wrappers::PFMatchmakingGetMatchmakerGameInfoResultWrapper<Allocator>, public OutputModel<PFMatchmakingGetMatchmakerGameInfoResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchmakerGameInfoResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGetMatchmakerGameInfoResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGetMatchmakerGameInfoResult& model);
    static HRESULT Copy(const PFMatchmakingGetMatchmakerGameInfoResult& input, PFMatchmakingGetMatchmakerGameInfoResult& output, ModelBuffer& buffer);
};

class GetMatchmakerGameModesRequest : public Wrappers::PFMatchmakingGetMatchmakerGameModesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchmakerGameModesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGetMatchmakerGameModesRequest& input);

};

class GameModeInfo : public Wrappers::PFMatchmakingGameModeInfoWrapper<Allocator>, public InputModel, public OutputModel<PFMatchmakingGameModeInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGameModeInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGameModeInfo& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGameModeInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGameModeInfo& model);
    static HRESULT Copy(const PFMatchmakingGameModeInfo& input, PFMatchmakingGameModeInfo& output, ModelBuffer& buffer);
};

class GetMatchmakerGameModesResult : public Wrappers::PFMatchmakingGetMatchmakerGameModesResultWrapper<Allocator>, public OutputModel<PFMatchmakingGetMatchmakerGameModesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchmakerGameModesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGetMatchmakerGameModesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGetMatchmakerGameModesResult& model);
    static HRESULT Copy(const PFMatchmakingGetMatchmakerGameModesResult& input, PFMatchmakingGetMatchmakerGameModesResult& output, ModelBuffer& buffer);
};

class ModifyMatchmakerGameModesRequest : public Wrappers::PFMatchmakingModifyMatchmakerGameModesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingModifyMatchmakerGameModesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingModifyMatchmakerGameModesRequest& input);

};

class Container_Dictionary_String_String : public Wrappers::PFMatchmakingContainer_Dictionary_String_StringWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingContainer_Dictionary_String_StringWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingContainer_Dictionary_String_String& input);

};

class CollectionFilter : public Wrappers::PFMatchmakingCollectionFilterWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCollectionFilterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCollectionFilter& input);

};

class CurrentGamesRequest : public Wrappers::PFMatchmakingCurrentGamesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCurrentGamesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCurrentGamesRequest& input);

};

class GameInfo : public Wrappers::PFMatchmakingGameInfoWrapper<Allocator>, public OutputModel<PFMatchmakingGameInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGameInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGameInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGameInfo& model);
    static HRESULT Copy(const PFMatchmakingGameInfo& input, PFMatchmakingGameInfo& output, ModelBuffer& buffer);
};

class CurrentGamesResult : public Wrappers::PFMatchmakingCurrentGamesResultWrapper<Allocator>, public OutputModel<PFMatchmakingCurrentGamesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCurrentGamesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingCurrentGamesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingCurrentGamesResult& model);
    static HRESULT Copy(const PFMatchmakingCurrentGamesResult& input, PFMatchmakingCurrentGamesResult& output, ModelBuffer& buffer);
};

class GameServerRegionsRequest : public Wrappers::PFMatchmakingGameServerRegionsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGameServerRegionsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGameServerRegionsRequest& input);

};

class RegionInfo : public Wrappers::PFMatchmakingRegionInfoWrapper<Allocator>, public OutputModel<PFMatchmakingRegionInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingRegionInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingRegionInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingRegionInfo& model);
    static HRESULT Copy(const PFMatchmakingRegionInfo& input, PFMatchmakingRegionInfo& output, ModelBuffer& buffer);
};

class GameServerRegionsResult : public Wrappers::PFMatchmakingGameServerRegionsResultWrapper<Allocator>, public OutputModel<PFMatchmakingGameServerRegionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGameServerRegionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGameServerRegionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGameServerRegionsResult& model);
    static HRESULT Copy(const PFMatchmakingGameServerRegionsResult& input, PFMatchmakingGameServerRegionsResult& output, ModelBuffer& buffer);
};

class MatchmakeRequest : public Wrappers::PFMatchmakingMatchmakeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingMatchmakeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingMatchmakeRequest& input);

};

class MatchmakeResult : public Wrappers::PFMatchmakingMatchmakeResultWrapper<Allocator>, public OutputModel<PFMatchmakingMatchmakeResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingMatchmakeResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingMatchmakeResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingMatchmakeResult& model);
    static HRESULT Copy(const PFMatchmakingMatchmakeResult& input, PFMatchmakingMatchmakeResult& output, ModelBuffer& buffer);
};

class ClientStartGameRequest : public Wrappers::PFMatchmakingClientStartGameRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingClientStartGameRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingClientStartGameRequest& input);

};

class StartGameResult : public Wrappers::PFMatchmakingStartGameResultWrapper<Allocator>, public OutputModel<PFMatchmakingStartGameResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingStartGameResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingStartGameResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingStartGameResult& model);
    static HRESULT Copy(const PFMatchmakingStartGameResult& input, PFMatchmakingStartGameResult& output, ModelBuffer& buffer);
};

class AuthUserRequest : public Wrappers::PFMatchmakingAuthUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingAuthUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingAuthUserRequest& input);

};

class AuthUserResponse : public Wrappers::PFMatchmakingAuthUserResponseWrapper<Allocator>, public OutputModel<PFMatchmakingAuthUserResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingAuthUserResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingAuthUserResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingAuthUserResponse& model);
    static HRESULT Copy(const PFMatchmakingAuthUserResponse& input, PFMatchmakingAuthUserResponse& output, ModelBuffer& buffer);
};

class PlayerJoinedRequest : public Wrappers::PFMatchmakingPlayerJoinedRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingPlayerJoinedRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingPlayerJoinedRequest& input);

};

class PlayerLeftRequest : public Wrappers::PFMatchmakingPlayerLeftRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingPlayerLeftRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingPlayerLeftRequest& input);

};

class MatchmakerStartGameRequest : public Wrappers::PFMatchmakingMatchmakerStartGameRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingMatchmakerStartGameRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingMatchmakerStartGameRequest& input);

};

class StartGameResponse : public Wrappers::PFMatchmakingStartGameResponseWrapper<Allocator>, public OutputModel<PFMatchmakingStartGameResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingStartGameResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingStartGameResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingStartGameResponse& model);
    static HRESULT Copy(const PFMatchmakingStartGameResponse& input, PFMatchmakingStartGameResponse& output, ModelBuffer& buffer);
};

class UserInfoRequest : public Wrappers::PFMatchmakingUserInfoRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingUserInfoRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingUserInfoRequest& input);

};

class UserInfoResponse : public Wrappers::PFMatchmakingUserInfoResponseWrapper<Allocator>, public OutputModel<PFMatchmakingUserInfoResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingUserInfoResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingUserInfoResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingUserInfoResponse& model);
    static HRESULT Copy(const PFMatchmakingUserInfoResponse& input, PFMatchmakingUserInfoResponse& output, ModelBuffer& buffer);
};

class DeregisterGameRequest : public Wrappers::PFMatchmakingDeregisterGameRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingDeregisterGameRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingDeregisterGameRequest& input);

};

class NotifyMatchmakerPlayerLeftRequest : public Wrappers::PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingNotifyMatchmakerPlayerLeftRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingNotifyMatchmakerPlayerLeftRequest& input);

};

class NotifyMatchmakerPlayerLeftResult : public Wrappers::PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper<Allocator>, public OutputModel<PFMatchmakingNotifyMatchmakerPlayerLeftResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingNotifyMatchmakerPlayerLeftResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingNotifyMatchmakerPlayerLeftResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingNotifyMatchmakerPlayerLeftResult& model);
    static HRESULT Copy(const PFMatchmakingNotifyMatchmakerPlayerLeftResult& input, PFMatchmakingNotifyMatchmakerPlayerLeftResult& output, ModelBuffer& buffer);
};

class RedeemMatchmakerTicketRequest : public Wrappers::PFMatchmakingRedeemMatchmakerTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingRedeemMatchmakerTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingRedeemMatchmakerTicketRequest& input);

};

class RedeemMatchmakerTicketResult : public Wrappers::PFMatchmakingRedeemMatchmakerTicketResultWrapper<Allocator>, public OutputModel<PFMatchmakingRedeemMatchmakerTicketResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingRedeemMatchmakerTicketResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingRedeemMatchmakerTicketResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingRedeemMatchmakerTicketResult& model);
    static HRESULT Copy(const PFMatchmakingRedeemMatchmakerTicketResult& input, PFMatchmakingRedeemMatchmakerTicketResult& output, ModelBuffer& buffer);
};

class RefreshGameServerInstanceHeartbeatRequest : public Wrappers::PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingRefreshGameServerInstanceHeartbeatRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingRefreshGameServerInstanceHeartbeatRequest& input);

};

class RegisterGameRequest : public Wrappers::PFMatchmakingRegisterGameRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingRegisterGameRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingRegisterGameRequest& input);

};

class RegisterGameResponse : public Wrappers::PFMatchmakingRegisterGameResponseWrapper<Allocator>, public OutputModel<PFMatchmakingRegisterGameResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingRegisterGameResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingRegisterGameResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingRegisterGameResponse& model);
    static HRESULT Copy(const PFMatchmakingRegisterGameResponse& input, PFMatchmakingRegisterGameResponse& output, ModelBuffer& buffer);
};

class SetGameServerInstanceDataRequest : public Wrappers::PFMatchmakingSetGameServerInstanceDataRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingSetGameServerInstanceDataRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingSetGameServerInstanceDataRequest& input);

};

class SetGameServerInstanceStateRequest : public Wrappers::PFMatchmakingSetGameServerInstanceStateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingSetGameServerInstanceStateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingSetGameServerInstanceStateRequest& input);

};

class SetGameServerInstanceTagsRequest : public Wrappers::PFMatchmakingSetGameServerInstanceTagsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingSetGameServerInstanceTagsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingSetGameServerInstanceTagsRequest& input);

};

class CancelAllMatchmakingTicketsForPlayerRequest : public Wrappers::PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest& input);

};

class CancelAllServerBackfillTicketsForPlayerRequest : public Wrappers::PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest& input);

};

class CancelMatchmakingTicketRequest : public Wrappers::PFMatchmakingCancelMatchmakingTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCancelMatchmakingTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCancelMatchmakingTicketRequest& input);

};

class CancelServerBackfillTicketRequest : public Wrappers::PFMatchmakingCancelServerBackfillTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCancelServerBackfillTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCancelServerBackfillTicketRequest& input);

};

class MatchmakingPlayerAttributes : public Wrappers::PFMatchmakingMatchmakingPlayerAttributesWrapper<Allocator>, public InputModel, public OutputModel<PFMatchmakingMatchmakingPlayerAttributes>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingMatchmakingPlayerAttributesWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingMatchmakingPlayerAttributes& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingMatchmakingPlayerAttributes const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingMatchmakingPlayerAttributes& model);
    static HRESULT Copy(const PFMatchmakingMatchmakingPlayerAttributes& input, PFMatchmakingMatchmakingPlayerAttributes& output, ModelBuffer& buffer);
};

class MatchmakingPlayer : public Wrappers::PFMatchmakingMatchmakingPlayerWrapper<Allocator>, public InputModel, public OutputModel<PFMatchmakingMatchmakingPlayer>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingMatchmakingPlayerWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingMatchmakingPlayer& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingMatchmakingPlayer const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingMatchmakingPlayer& model);
    static HRESULT Copy(const PFMatchmakingMatchmakingPlayer& input, PFMatchmakingMatchmakingPlayer& output, ModelBuffer& buffer);
};

class CreateMatchmakingTicketRequest : public Wrappers::PFMatchmakingCreateMatchmakingTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCreateMatchmakingTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCreateMatchmakingTicketRequest& input);

};

class CreateMatchmakingTicketResult : public Wrappers::PFMatchmakingCreateMatchmakingTicketResultWrapper<Allocator>, public OutputModel<PFMatchmakingCreateMatchmakingTicketResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCreateMatchmakingTicketResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingCreateMatchmakingTicketResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingCreateMatchmakingTicketResult& model);
    static HRESULT Copy(const PFMatchmakingCreateMatchmakingTicketResult& input, PFMatchmakingCreateMatchmakingTicketResult& output, ModelBuffer& buffer);
};

class MatchmakingPlayerWithTeamAssignment : public Wrappers::PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Allocator>, public InputModel, public OutputModel<PFMatchmakingMatchmakingPlayerWithTeamAssignment>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingMatchmakingPlayerWithTeamAssignmentWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingMatchmakingPlayerWithTeamAssignment const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& model);
    static HRESULT Copy(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& input, PFMatchmakingMatchmakingPlayerWithTeamAssignment& output, ModelBuffer& buffer);
};

class ServerDetails : public Wrappers::PFMatchmakingServerDetailsWrapper<Allocator>, public InputModel, public OutputModel<PFMatchmakingServerDetails>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingServerDetailsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingServerDetails& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingServerDetails const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingServerDetails& model);
    static HRESULT Copy(const PFMatchmakingServerDetails& input, PFMatchmakingServerDetails& output, ModelBuffer& buffer);
};

class CreateServerBackfillTicketRequest : public Wrappers::PFMatchmakingCreateServerBackfillTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCreateServerBackfillTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCreateServerBackfillTicketRequest& input);

};

class CreateServerBackfillTicketResult : public Wrappers::PFMatchmakingCreateServerBackfillTicketResultWrapper<Allocator>, public OutputModel<PFMatchmakingCreateServerBackfillTicketResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCreateServerBackfillTicketResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingCreateServerBackfillTicketResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingCreateServerBackfillTicketResult& model);
    static HRESULT Copy(const PFMatchmakingCreateServerBackfillTicketResult& input, PFMatchmakingCreateServerBackfillTicketResult& output, ModelBuffer& buffer);
};

class CreateServerMatchmakingTicketRequest : public Wrappers::PFMatchmakingCreateServerMatchmakingTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingCreateServerMatchmakingTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingCreateServerMatchmakingTicketRequest& input);

};

class GetMatchRequest : public Wrappers::PFMatchmakingGetMatchRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGetMatchRequest& input);

};

class GetMatchResult : public Wrappers::PFMatchmakingGetMatchResultWrapper<Allocator>, public OutputModel<PFMatchmakingGetMatchResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGetMatchResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGetMatchResult& model);
    static HRESULT Copy(const PFMatchmakingGetMatchResult& input, PFMatchmakingGetMatchResult& output, ModelBuffer& buffer);
};

class GetMatchmakingTicketRequest : public Wrappers::PFMatchmakingGetMatchmakingTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchmakingTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGetMatchmakingTicketRequest& input);

};

class GetMatchmakingTicketResult : public Wrappers::PFMatchmakingGetMatchmakingTicketResultWrapper<Allocator>, public OutputModel<PFMatchmakingGetMatchmakingTicketResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetMatchmakingTicketResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGetMatchmakingTicketResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGetMatchmakingTicketResult& model);
    static HRESULT Copy(const PFMatchmakingGetMatchmakingTicketResult& input, PFMatchmakingGetMatchmakingTicketResult& output, ModelBuffer& buffer);
};

class GetQueueStatisticsRequest : public Wrappers::PFMatchmakingGetQueueStatisticsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetQueueStatisticsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGetQueueStatisticsRequest& input);

};

class Statistics : public Wrappers::PFMatchmakingStatisticsWrapper<Allocator>, public OutputModel<PFMatchmakingStatistics>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingStatisticsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingStatistics const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingStatistics& model);
    static HRESULT Copy(const PFMatchmakingStatistics& input, PFMatchmakingStatistics& output, ModelBuffer& buffer);
};

class GetQueueStatisticsResult : public Wrappers::PFMatchmakingGetQueueStatisticsResultWrapper<Allocator>, public OutputModel<PFMatchmakingGetQueueStatisticsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetQueueStatisticsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGetQueueStatisticsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGetQueueStatisticsResult& model);
    static HRESULT Copy(const PFMatchmakingGetQueueStatisticsResult& input, PFMatchmakingGetQueueStatisticsResult& output, ModelBuffer& buffer);
};

class GetServerBackfillTicketRequest : public Wrappers::PFMatchmakingGetServerBackfillTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetServerBackfillTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingGetServerBackfillTicketRequest& input);

};

class GetServerBackfillTicketResult : public Wrappers::PFMatchmakingGetServerBackfillTicketResultWrapper<Allocator>, public OutputModel<PFMatchmakingGetServerBackfillTicketResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingGetServerBackfillTicketResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingGetServerBackfillTicketResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingGetServerBackfillTicketResult& model);
    static HRESULT Copy(const PFMatchmakingGetServerBackfillTicketResult& input, PFMatchmakingGetServerBackfillTicketResult& output, ModelBuffer& buffer);
};

class JoinMatchmakingTicketRequest : public Wrappers::PFMatchmakingJoinMatchmakingTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingJoinMatchmakingTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingJoinMatchmakingTicketRequest& input);

};

class ListMatchmakingTicketsForPlayerRequest : public Wrappers::PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingListMatchmakingTicketsForPlayerRequest& input);

};

class ListMatchmakingTicketsForPlayerResult : public Wrappers::PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper<Allocator>, public OutputModel<PFMatchmakingListMatchmakingTicketsForPlayerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingListMatchmakingTicketsForPlayerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingListMatchmakingTicketsForPlayerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingListMatchmakingTicketsForPlayerResult& model);
    static HRESULT Copy(const PFMatchmakingListMatchmakingTicketsForPlayerResult& input, PFMatchmakingListMatchmakingTicketsForPlayerResult& output, ModelBuffer& buffer);
};

class ListServerBackfillTicketsForPlayerRequest : public Wrappers::PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFMatchmakingListServerBackfillTicketsForPlayerRequest& input);

};

class ListServerBackfillTicketsForPlayerResult : public Wrappers::PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper<Allocator>, public OutputModel<PFMatchmakingListServerBackfillTicketsForPlayerResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFMatchmakingListServerBackfillTicketsForPlayerResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFMatchmakingListServerBackfillTicketsForPlayerResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFMatchmakingListServerBackfillTicketsForPlayerResult& model);
    static HRESULT Copy(const PFMatchmakingListServerBackfillTicketsForPlayerResult& input, PFMatchmakingListServerBackfillTicketsForPlayerResult& output, ModelBuffer& buffer);
};

} // namespace Matchmaking
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
