#pragma once

#include <playfab/cpp/PFLobbyDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Lobby
{

// Lobby Classes
class Member : public Wrappers::PFLobbyMemberWrapper<Allocator>, public InputModel, public OutputModel<PFLobbyMember>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyMemberWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyMember& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyMember const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyMember& model);
    static HRESULT Copy(const PFLobbyMember& input, PFLobbyMember& output, ModelBuffer& buffer);
};

class CreateLobbyRequest : public Wrappers::PFLobbyCreateLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyCreateLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyCreateLobbyRequest& input);

};

class CreateLobbyResult : public Wrappers::PFLobbyCreateLobbyResultWrapper<Allocator>, public OutputModel<PFLobbyCreateLobbyResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyCreateLobbyResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyCreateLobbyResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyCreateLobbyResult& model);
    static HRESULT Copy(const PFLobbyCreateLobbyResult& input, PFLobbyCreateLobbyResult& output, ModelBuffer& buffer);
};

class DeleteLobbyRequest : public Wrappers::PFLobbyDeleteLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyDeleteLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyDeleteLobbyRequest& input);

};

class PaginationRequest : public Wrappers::PFLobbyPaginationRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyPaginationRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyPaginationRequest& input);

};

class FindFriendLobbiesRequest : public Wrappers::PFLobbyFindFriendLobbiesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyFindFriendLobbiesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyFindFriendLobbiesRequest& input);

};

class FriendLobbySummary : public Wrappers::PFLobbyFriendLobbySummaryWrapper<Allocator>, public OutputModel<PFLobbyFriendLobbySummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyFriendLobbySummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyFriendLobbySummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyFriendLobbySummary& model);
    static HRESULT Copy(const PFLobbyFriendLobbySummary& input, PFLobbyFriendLobbySummary& output, ModelBuffer& buffer);
};

class PaginationResponse : public Wrappers::PFLobbyPaginationResponseWrapper<Allocator>, public OutputModel<PFLobbyPaginationResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyPaginationResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyPaginationResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyPaginationResponse& model);
    static HRESULT Copy(const PFLobbyPaginationResponse& input, PFLobbyPaginationResponse& output, ModelBuffer& buffer);
};

class FindFriendLobbiesResult : public Wrappers::PFLobbyFindFriendLobbiesResultWrapper<Allocator>, public OutputModel<PFLobbyFindFriendLobbiesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyFindFriendLobbiesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyFindFriendLobbiesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyFindFriendLobbiesResult& model);
    static HRESULT Copy(const PFLobbyFindFriendLobbiesResult& input, PFLobbyFindFriendLobbiesResult& output, ModelBuffer& buffer);
};

class FindLobbiesRequest : public Wrappers::PFLobbyFindLobbiesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyFindLobbiesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyFindLobbiesRequest& input);

};

class LobbySummary : public Wrappers::PFLobbyLobbySummaryWrapper<Allocator>, public OutputModel<PFLobbyLobbySummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyLobbySummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyLobbySummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyLobbySummary& model);
    static HRESULT Copy(const PFLobbyLobbySummary& input, PFLobbyLobbySummary& output, ModelBuffer& buffer);
};

class FindLobbiesResult : public Wrappers::PFLobbyFindLobbiesResultWrapper<Allocator>, public OutputModel<PFLobbyFindLobbiesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyFindLobbiesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyFindLobbiesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyFindLobbiesResult& model);
    static HRESULT Copy(const PFLobbyFindLobbiesResult& input, PFLobbyFindLobbiesResult& output, ModelBuffer& buffer);
};

class GetLobbyRequest : public Wrappers::PFLobbyGetLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyGetLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyGetLobbyRequest& input);

};

class Lobby : public Wrappers::PFLobbyLobbyWrapper<Allocator>, public OutputModel<PFLobbyLobby>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyLobbyWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyLobby const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyLobby& model);
    static HRESULT Copy(const PFLobbyLobby& input, PFLobbyLobby& output, ModelBuffer& buffer);
};

class GetLobbyResult : public Wrappers::PFLobbyGetLobbyResultWrapper<Allocator>, public OutputModel<PFLobbyGetLobbyResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyGetLobbyResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyGetLobbyResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyGetLobbyResult& model);
    static HRESULT Copy(const PFLobbyGetLobbyResult& input, PFLobbyGetLobbyResult& output, ModelBuffer& buffer);
};

class InviteToLobbyRequest : public Wrappers::PFLobbyInviteToLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyInviteToLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyInviteToLobbyRequest& input);

};

class JoinArrangedLobbyRequest : public Wrappers::PFLobbyJoinArrangedLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyJoinArrangedLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyJoinArrangedLobbyRequest& input);

};

class JoinLobbyResult : public Wrappers::PFLobbyJoinLobbyResultWrapper<Allocator>, public OutputModel<PFLobbyJoinLobbyResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyJoinLobbyResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbyJoinLobbyResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbyJoinLobbyResult& model);
    static HRESULT Copy(const PFLobbyJoinLobbyResult& input, PFLobbyJoinLobbyResult& output, ModelBuffer& buffer);
};

class JoinLobbyRequest : public Wrappers::PFLobbyJoinLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyJoinLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyJoinLobbyRequest& input);

};

class LeaveLobbyRequest : public Wrappers::PFLobbyLeaveLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyLeaveLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyLeaveLobbyRequest& input);

};

class RemoveMemberFromLobbyRequest : public Wrappers::PFLobbyRemoveMemberFromLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyRemoveMemberFromLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyRemoveMemberFromLobbyRequest& input);

};

class SubscribeToLobbyResourceRequest : public Wrappers::PFLobbySubscribeToLobbyResourceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbySubscribeToLobbyResourceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbySubscribeToLobbyResourceRequest& input);

};

class SubscribeToLobbyResourceResult : public Wrappers::PFLobbySubscribeToLobbyResourceResultWrapper<Allocator>, public OutputModel<PFLobbySubscribeToLobbyResourceResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbySubscribeToLobbyResourceResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLobbySubscribeToLobbyResourceResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLobbySubscribeToLobbyResourceResult& model);
    static HRESULT Copy(const PFLobbySubscribeToLobbyResourceResult& input, PFLobbySubscribeToLobbyResourceResult& output, ModelBuffer& buffer);
};

class UnsubscribeFromLobbyResourceRequest : public Wrappers::PFLobbyUnsubscribeFromLobbyResourceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyUnsubscribeFromLobbyResourceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyUnsubscribeFromLobbyResourceRequest& input);

};

class UpdateLobbyRequest : public Wrappers::PFLobbyUpdateLobbyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLobbyUpdateLobbyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLobbyUpdateLobbyRequest& input);

};

} // namespace Lobby
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
