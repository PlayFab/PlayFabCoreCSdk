#include "stdafx.h"
#include "LobbyDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Lobby
{

JsonValue Member::ToJson() const
{
    return Member::ToJson(this->Model());
}

JsonValue Member::ToJson(const PFLobbyMember& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "MemberData", input.memberData, input.memberDataCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    JsonUtils::ObjectAddMember(output, "PubSubConnectionHandle", input.pubSubConnectionHandle);
    return output;
}

void Member::FromJson(const JsonValue& input)
{
    StringDictionaryEntryVector memberData{};
    JsonUtils::ObjectGetMember(input, "MemberData", memberData);
    this->SetMemberData(std::move(memberData));

    StdExtra::optional<EntityKey> memberEntity{};
    JsonUtils::ObjectGetMember(input, "MemberEntity", memberEntity);
    if (memberEntity)
    {
        this->SetMemberEntity(std::move(*memberEntity));
    }

    String pubSubConnectionHandle{};
    JsonUtils::ObjectGetMember(input, "PubSubConnectionHandle", pubSubConnectionHandle);
    this->SetPubSubConnectionHandle(std::move(pubSubConnectionHandle));
}

size_t Member::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyMember const*> Member::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Member>(&this->Model());
}

size_t Member::RequiredBufferSize(const PFLobbyMember& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.memberDataCount);
    for (size_t i = 0; i < model.memberDataCount; ++i)
    {
        requiredSize += (std::strlen(model.memberData[i].key) + 1);
        requiredSize += (std::strlen(model.memberData[i].value) + 1);
    }
    if (model.memberEntity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.memberEntity);
    }
    if (model.pubSubConnectionHandle)
    {
        requiredSize += (std::strlen(model.pubSubConnectionHandle) + 1);
    }
    return requiredSize;
}

HRESULT Member::Copy(const PFLobbyMember& input, PFLobbyMember& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary(input.memberData, input.memberDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.memberData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.memberEntity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.memberEntity = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.pubSubConnectionHandle); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pubSubConnectionHandle = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateLobbyRequest::ToJson() const
{
    return CreateLobbyRequest::ToJson(this->Model());
}

JsonValue CreateLobbyRequest::ToJson(const PFLobbyCreateLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessPolicy", input.accessPolicy);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "LobbyData", input.lobbyData, input.lobbyDataCount);
    JsonUtils::ObjectAddMember(output, "MaxPlayers", input.maxPlayers);
    JsonUtils::ObjectAddMemberArray<Member>(output, "Members", input.members, input.membersCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Owner", input.owner);
    JsonUtils::ObjectAddMember(output, "OwnerMigrationPolicy", input.ownerMigrationPolicy);
    JsonUtils::ObjectAddMemberDictionary(output, "SearchData", input.searchData, input.searchDataCount);
    JsonUtils::ObjectAddMember(output, "UseConnections", input.useConnections);
    return output;
}

void CreateLobbyResult::FromJson(const JsonValue& input)
{
    String connectionString{};
    JsonUtils::ObjectGetMember(input, "ConnectionString", connectionString);
    this->SetConnectionString(std::move(connectionString));

    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));
}

size_t CreateLobbyResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyCreateLobbyResult const*> CreateLobbyResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateLobbyResult>(&this->Model());
}

size_t CreateLobbyResult::RequiredBufferSize(const PFLobbyCreateLobbyResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.connectionString)
    {
        requiredSize += (std::strlen(model.connectionString) + 1);
    }
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    return requiredSize;
}

HRESULT CreateLobbyResult::Copy(const PFLobbyCreateLobbyResult& input, PFLobbyCreateLobbyResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.connectionString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectionString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteLobbyRequest::ToJson() const
{
    return DeleteLobbyRequest::ToJson(this->Model());
}

JsonValue DeleteLobbyRequest::ToJson(const PFLobbyDeleteLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    return output;
}

JsonValue PaginationRequest::ToJson() const
{
    return PaginationRequest::ToJson(this->Model());
}

JsonValue PaginationRequest::ToJson(const PFLobbyPaginationRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMember(output, "PageSizeRequested", input.pageSizeRequested);
    return output;
}

JsonValue FindFriendLobbiesRequest::ToJson() const
{
    return FindFriendLobbiesRequest::ToJson(this->Model());
}

JsonValue FindFriendLobbiesRequest::ToJson(const PFLobbyFindFriendLobbiesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExcludeFacebookFriends", input.excludeFacebookFriends);
    JsonUtils::ObjectAddMember(output, "ExcludeSteamFriends", input.excludeSteamFriends);
    JsonUtils::ObjectAddMember(output, "Filter", input.filter);
    JsonUtils::ObjectAddMember(output, "OrderBy", input.orderBy);
    JsonUtils::ObjectAddMember<PaginationRequest>(output, "Pagination", input.pagination);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

void FriendLobbySummary::FromJson(const JsonValue& input)
{
    String connectionString{};
    JsonUtils::ObjectGetMember(input, "ConnectionString", connectionString);
    this->SetConnectionString(std::move(connectionString));

    JsonUtils::ObjectGetMember(input, "CurrentPlayers", this->m_model.currentPlayers);

    ModelVector<EntityKey> friends{};
    JsonUtils::ObjectGetMember<EntityKey>(input, "Friends", friends);
    this->SetFriends(std::move(friends));

    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));

    JsonUtils::ObjectGetMember(input, "MaxPlayers", this->m_model.maxPlayers);

    StdExtra::optional<PFLobbyMembershipLock> membershipLock{};
    JsonUtils::ObjectGetMember(input, "MembershipLock", membershipLock);
    this->SetMembershipLock(std::move(membershipLock));

    EntityKey owner{};
    JsonUtils::ObjectGetMember(input, "Owner", owner);
    this->SetOwner(std::move(owner));

    StringDictionaryEntryVector searchData{};
    JsonUtils::ObjectGetMember(input, "SearchData", searchData);
    this->SetSearchData(std::move(searchData));
}

size_t FriendLobbySummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyFriendLobbySummary const*> FriendLobbySummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FriendLobbySummary>(&this->Model());
}

size_t FriendLobbySummary::RequiredBufferSize(const PFLobbyFriendLobbySummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.connectionString)
    {
        requiredSize += (std::strlen(model.connectionString) + 1);
    }
    requiredSize += (alignof(PFEntityKey*) + sizeof(PFEntityKey*) * model.friendsCount);
    for (size_t i = 0; i < model.friendsCount; ++i)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.friends[i]);
    }
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    if (model.membershipLock)
    {
        requiredSize += (alignof(PFLobbyMembershipLock) + sizeof(PFLobbyMembershipLock));
    }
    if (model.owner)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.owner);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.searchDataCount);
    for (size_t i = 0; i < model.searchDataCount; ++i)
    {
        requiredSize += (std::strlen(model.searchData[i].key) + 1);
        requiredSize += (std::strlen(model.searchData[i].value) + 1);
    }
    return requiredSize;
}

HRESULT FriendLobbySummary::Copy(const PFLobbyFriendLobbySummary& input, PFLobbyFriendLobbySummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.connectionString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectionString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<EntityKey>(input.friends, input.friendsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.friends = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.membershipLock); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.membershipLock = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.owner); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.owner = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.searchData, input.searchDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.searchData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void PaginationResponse::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    StdExtra::optional<uint32_t> totalMatchedLobbyCount{};
    JsonUtils::ObjectGetMember(input, "TotalMatchedLobbyCount", totalMatchedLobbyCount);
    this->SetTotalMatchedLobbyCount(std::move(totalMatchedLobbyCount));
}

size_t PaginationResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyPaginationResponse const*> PaginationResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PaginationResponse>(&this->Model());
}

size_t PaginationResponse::RequiredBufferSize(const PFLobbyPaginationResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    if (model.totalMatchedLobbyCount)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    return requiredSize;
}

HRESULT PaginationResponse::Copy(const PFLobbyPaginationResponse& input, PFLobbyPaginationResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.totalMatchedLobbyCount); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.totalMatchedLobbyCount = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void FindFriendLobbiesResult::FromJson(const JsonValue& input)
{
    ModelVector<FriendLobbySummary> lobbies{};
    JsonUtils::ObjectGetMember<FriendLobbySummary>(input, "Lobbies", lobbies);
    this->SetLobbies(std::move(lobbies));

    PaginationResponse pagination{};
    JsonUtils::ObjectGetMember(input, "Pagination", pagination);
    this->SetPagination(std::move(pagination));
}

size_t FindFriendLobbiesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyFindFriendLobbiesResult const*> FindFriendLobbiesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FindFriendLobbiesResult>(&this->Model());
}

size_t FindFriendLobbiesResult::RequiredBufferSize(const PFLobbyFindFriendLobbiesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLobbyFriendLobbySummary*) + sizeof(PFLobbyFriendLobbySummary*) * model.lobbiesCount);
    for (size_t i = 0; i < model.lobbiesCount; ++i)
    {
        requiredSize += FriendLobbySummary::RequiredBufferSize(*model.lobbies[i]);
    }
    if (model.pagination)
    {
        requiredSize += PaginationResponse::RequiredBufferSize(*model.pagination);
    }
    return requiredSize;
}

HRESULT FindFriendLobbiesResult::Copy(const PFLobbyFindFriendLobbiesResult& input, PFLobbyFindFriendLobbiesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<FriendLobbySummary>(input.lobbies, input.lobbiesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbies = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PaginationResponse>(input.pagination); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pagination = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue FindLobbiesRequest::ToJson() const
{
    return FindLobbiesRequest::ToJson(this->Model());
}

JsonValue FindLobbiesRequest::ToJson(const PFLobbyFindLobbiesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Filter", input.filter);
    JsonUtils::ObjectAddMember(output, "OrderBy", input.orderBy);
    JsonUtils::ObjectAddMember<PaginationRequest>(output, "Pagination", input.pagination);
    return output;
}

void LobbySummary::FromJson(const JsonValue& input)
{
    String connectionString{};
    JsonUtils::ObjectGetMember(input, "ConnectionString", connectionString);
    this->SetConnectionString(std::move(connectionString));

    JsonUtils::ObjectGetMember(input, "CurrentPlayers", this->m_model.currentPlayers);

    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));

    JsonUtils::ObjectGetMember(input, "MaxPlayers", this->m_model.maxPlayers);

    StdExtra::optional<PFLobbyMembershipLock> membershipLock{};
    JsonUtils::ObjectGetMember(input, "MembershipLock", membershipLock);
    this->SetMembershipLock(std::move(membershipLock));

    EntityKey owner{};
    JsonUtils::ObjectGetMember(input, "Owner", owner);
    this->SetOwner(std::move(owner));

    StringDictionaryEntryVector searchData{};
    JsonUtils::ObjectGetMember(input, "SearchData", searchData);
    this->SetSearchData(std::move(searchData));
}

size_t LobbySummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyLobbySummary const*> LobbySummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LobbySummary>(&this->Model());
}

size_t LobbySummary::RequiredBufferSize(const PFLobbyLobbySummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.connectionString)
    {
        requiredSize += (std::strlen(model.connectionString) + 1);
    }
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    if (model.membershipLock)
    {
        requiredSize += (alignof(PFLobbyMembershipLock) + sizeof(PFLobbyMembershipLock));
    }
    if (model.owner)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.owner);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.searchDataCount);
    for (size_t i = 0; i < model.searchDataCount; ++i)
    {
        requiredSize += (std::strlen(model.searchData[i].key) + 1);
        requiredSize += (std::strlen(model.searchData[i].value) + 1);
    }
    return requiredSize;
}

HRESULT LobbySummary::Copy(const PFLobbyLobbySummary& input, PFLobbyLobbySummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.connectionString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectionString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.membershipLock); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.membershipLock = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.owner); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.owner = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.searchData, input.searchDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.searchData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void FindLobbiesResult::FromJson(const JsonValue& input)
{
    ModelVector<LobbySummary> lobbies{};
    JsonUtils::ObjectGetMember<LobbySummary>(input, "Lobbies", lobbies);
    this->SetLobbies(std::move(lobbies));

    PaginationResponse pagination{};
    JsonUtils::ObjectGetMember(input, "Pagination", pagination);
    this->SetPagination(std::move(pagination));
}

size_t FindLobbiesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyFindLobbiesResult const*> FindLobbiesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<FindLobbiesResult>(&this->Model());
}

size_t FindLobbiesResult::RequiredBufferSize(const PFLobbyFindLobbiesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLobbyLobbySummary*) + sizeof(PFLobbyLobbySummary*) * model.lobbiesCount);
    for (size_t i = 0; i < model.lobbiesCount; ++i)
    {
        requiredSize += LobbySummary::RequiredBufferSize(*model.lobbies[i]);
    }
    if (model.pagination)
    {
        requiredSize += PaginationResponse::RequiredBufferSize(*model.pagination);
    }
    return requiredSize;
}

HRESULT FindLobbiesResult::Copy(const PFLobbyFindLobbiesResult& input, PFLobbyFindLobbiesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<LobbySummary>(input.lobbies, input.lobbiesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbies = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PaginationResponse>(input.pagination); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pagination = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetLobbyRequest::ToJson() const
{
    return GetLobbyRequest::ToJson(this->Model());
}

JsonValue GetLobbyRequest::ToJson(const PFLobbyGetLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    return output;
}

void Lobby::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "AccessPolicy", this->m_model.accessPolicy);

    JsonUtils::ObjectGetMember(input, "ChangeNumber", this->m_model.changeNumber);

    String connectionString{};
    JsonUtils::ObjectGetMember(input, "ConnectionString", connectionString);
    this->SetConnectionString(std::move(connectionString));

    StringDictionaryEntryVector lobbyData{};
    JsonUtils::ObjectGetMember(input, "LobbyData", lobbyData);
    this->SetLobbyData(std::move(lobbyData));

    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));

    JsonUtils::ObjectGetMember(input, "MaxPlayers", this->m_model.maxPlayers);

    ModelVector<Member> members{};
    JsonUtils::ObjectGetMember<Member>(input, "Members", members);
    this->SetMembers(std::move(members));

    JsonUtils::ObjectGetMember(input, "MembershipLock", this->m_model.membershipLock);

    StdExtra::optional<EntityKey> owner{};
    JsonUtils::ObjectGetMember(input, "Owner", owner);
    if (owner)
    {
        this->SetOwner(std::move(*owner));
    }

    StdExtra::optional<PFLobbyOwnerMigrationPolicy> ownerMigrationPolicy{};
    JsonUtils::ObjectGetMember(input, "OwnerMigrationPolicy", ownerMigrationPolicy);
    this->SetOwnerMigrationPolicy(std::move(ownerMigrationPolicy));

    String pubSubConnectionHandle{};
    JsonUtils::ObjectGetMember(input, "PubSubConnectionHandle", pubSubConnectionHandle);
    this->SetPubSubConnectionHandle(std::move(pubSubConnectionHandle));

    StringDictionaryEntryVector searchData{};
    JsonUtils::ObjectGetMember(input, "SearchData", searchData);
    this->SetSearchData(std::move(searchData));

    JsonUtils::ObjectGetMember(input, "UseConnections", this->m_model.useConnections);
}

size_t Lobby::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyLobby const*> Lobby::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Lobby>(&this->Model());
}

size_t Lobby::RequiredBufferSize(const PFLobbyLobby& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.connectionString)
    {
        requiredSize += (std::strlen(model.connectionString) + 1);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.lobbyDataCount);
    for (size_t i = 0; i < model.lobbyDataCount; ++i)
    {
        requiredSize += (std::strlen(model.lobbyData[i].key) + 1);
        requiredSize += (std::strlen(model.lobbyData[i].value) + 1);
    }
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    requiredSize += (alignof(PFLobbyMember*) + sizeof(PFLobbyMember*) * model.membersCount);
    for (size_t i = 0; i < model.membersCount; ++i)
    {
        requiredSize += Member::RequiredBufferSize(*model.members[i]);
    }
    if (model.owner)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.owner);
    }
    if (model.ownerMigrationPolicy)
    {
        requiredSize += (alignof(PFLobbyOwnerMigrationPolicy) + sizeof(PFLobbyOwnerMigrationPolicy));
    }
    if (model.pubSubConnectionHandle)
    {
        requiredSize += (std::strlen(model.pubSubConnectionHandle) + 1);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.searchDataCount);
    for (size_t i = 0; i < model.searchDataCount; ++i)
    {
        requiredSize += (std::strlen(model.searchData[i].key) + 1);
        requiredSize += (std::strlen(model.searchData[i].value) + 1);
    }
    return requiredSize;
}

HRESULT Lobby::Copy(const PFLobbyLobby& input, PFLobbyLobby& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.connectionString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectionString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.lobbyData, input.lobbyDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Member>(input.members, input.membersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.members = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.owner); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.owner = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.ownerMigrationPolicy); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ownerMigrationPolicy = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.pubSubConnectionHandle); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pubSubConnectionHandle = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.searchData, input.searchDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.searchData = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetLobbyResult::FromJson(const JsonValue& input)
{
    Lobby lobby{};
    JsonUtils::ObjectGetMember(input, "Lobby", lobby);
    this->SetLobby(std::move(lobby));
}

size_t GetLobbyResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyGetLobbyResult const*> GetLobbyResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLobbyResult>(&this->Model());
}

size_t GetLobbyResult::RequiredBufferSize(const PFLobbyGetLobbyResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.lobby)
    {
        requiredSize += Lobby::RequiredBufferSize(*model.lobby);
    }
    return requiredSize;
}

HRESULT GetLobbyResult::Copy(const PFLobbyGetLobbyResult& input, PFLobbyGetLobbyResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<Lobby>(input.lobby); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobby = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue InviteToLobbyRequest::ToJson() const
{
    return InviteToLobbyRequest::ToJson(this->Model());
}

JsonValue InviteToLobbyRequest::ToJson(const PFLobbyInviteToLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "InviteeEntity", input.inviteeEntity);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    return output;
}

JsonValue JoinArrangedLobbyRequest::ToJson() const
{
    return JoinArrangedLobbyRequest::ToJson(this->Model());
}

JsonValue JoinArrangedLobbyRequest::ToJson(const PFLobbyJoinArrangedLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessPolicy", input.accessPolicy);
    JsonUtils::ObjectAddMember(output, "ArrangementString", input.arrangementString);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MaxPlayers", input.maxPlayers);
    JsonUtils::ObjectAddMemberDictionary(output, "MemberData", input.memberData, input.memberDataCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    JsonUtils::ObjectAddMember(output, "OwnerMigrationPolicy", input.ownerMigrationPolicy);
    JsonUtils::ObjectAddMember(output, "UseConnections", input.useConnections);
    return output;
}

void JoinLobbyResult::FromJson(const JsonValue& input)
{
    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));
}

size_t JoinLobbyResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbyJoinLobbyResult const*> JoinLobbyResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<JoinLobbyResult>(&this->Model());
}

size_t JoinLobbyResult::RequiredBufferSize(const PFLobbyJoinLobbyResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    return requiredSize;
}

HRESULT JoinLobbyResult::Copy(const PFLobbyJoinLobbyResult& input, PFLobbyJoinLobbyResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue JoinLobbyRequest::ToJson() const
{
    return JoinLobbyRequest::ToJson(this->Model());
}

JsonValue JoinLobbyRequest::ToJson(const PFLobbyJoinLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConnectionString", input.connectionString);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "MemberData", input.memberData, input.memberDataCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    return output;
}

JsonValue LeaveLobbyRequest::ToJson() const
{
    return LeaveLobbyRequest::ToJson(this->Model());
}

JsonValue LeaveLobbyRequest::ToJson(const PFLobbyLeaveLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    return output;
}

JsonValue RemoveMemberFromLobbyRequest::ToJson() const
{
    return RemoveMemberFromLobbyRequest::ToJson(this->Model());
}

JsonValue RemoveMemberFromLobbyRequest::ToJson(const PFLobbyRemoveMemberFromLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    JsonUtils::ObjectAddMember(output, "PreventRejoin", input.preventRejoin);
    return output;
}

JsonValue SubscribeToLobbyResourceRequest::ToJson() const
{
    return SubscribeToLobbyResourceRequest::ToJson(this->Model());
}

JsonValue SubscribeToLobbyResourceRequest::ToJson(const PFLobbySubscribeToLobbyResourceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "EntityKey", input.entityKey);
    JsonUtils::ObjectAddMember(output, "PubSubConnectionHandle", input.pubSubConnectionHandle);
    JsonUtils::ObjectAddMember(output, "ResourceId", input.resourceId);
    JsonUtils::ObjectAddMember(output, "SubscriptionVersion", input.subscriptionVersion);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

void SubscribeToLobbyResourceResult::FromJson(const JsonValue& input)
{
    String topic{};
    JsonUtils::ObjectGetMember(input, "Topic", topic);
    this->SetTopic(std::move(topic));
}

size_t SubscribeToLobbyResourceResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLobbySubscribeToLobbyResourceResult const*> SubscribeToLobbyResourceResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SubscribeToLobbyResourceResult>(&this->Model());
}

size_t SubscribeToLobbyResourceResult::RequiredBufferSize(const PFLobbySubscribeToLobbyResourceResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.topic)
    {
        requiredSize += (std::strlen(model.topic) + 1);
    }
    return requiredSize;
}

HRESULT SubscribeToLobbyResourceResult::Copy(const PFLobbySubscribeToLobbyResourceResult& input, PFLobbySubscribeToLobbyResourceResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.topic); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.topic = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UnsubscribeFromLobbyResourceRequest::ToJson() const
{
    return UnsubscribeFromLobbyResourceRequest::ToJson(this->Model());
}

JsonValue UnsubscribeFromLobbyResourceRequest::ToJson(const PFLobbyUnsubscribeFromLobbyResourceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "EntityKey", input.entityKey);
    JsonUtils::ObjectAddMember(output, "PubSubConnectionHandle", input.pubSubConnectionHandle);
    JsonUtils::ObjectAddMember(output, "ResourceId", input.resourceId);
    JsonUtils::ObjectAddMember(output, "SubscriptionVersion", input.subscriptionVersion);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

JsonValue UpdateLobbyRequest::ToJson() const
{
    return UpdateLobbyRequest::ToJson(this->Model());
}

JsonValue UpdateLobbyRequest::ToJson(const PFLobbyUpdateLobbyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessPolicy", input.accessPolicy);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "LobbyData", input.lobbyData, input.lobbyDataCount);
    JsonUtils::ObjectAddMemberArray(output, "LobbyDataToDelete", input.lobbyDataToDelete, input.lobbyDataToDeleteCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "MaxPlayers", input.maxPlayers);
    JsonUtils::ObjectAddMemberDictionary(output, "MemberData", input.memberData, input.memberDataCount);
    JsonUtils::ObjectAddMemberArray(output, "MemberDataToDelete", input.memberDataToDelete, input.memberDataToDeleteCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "MemberEntity", input.memberEntity);
    JsonUtils::ObjectAddMember(output, "MembershipLock", input.membershipLock);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Owner", input.owner);
    JsonUtils::ObjectAddMemberDictionary(output, "SearchData", input.searchData, input.searchDataCount);
    JsonUtils::ObjectAddMemberArray(output, "SearchDataToDelete", input.searchDataToDelete, input.searchDataToDeleteCount);
    return output;
}

} // namespace Lobby
} // namespace PlayFab
