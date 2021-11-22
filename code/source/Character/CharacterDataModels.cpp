#include "stdafx.h"
#include "CharacterDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Character
{

JsonValue ResetCharacterStatisticsRequest::ToJson() const
{
    return ResetCharacterStatisticsRequest::ToJson(this->Model());
}

JsonValue ResetCharacterStatisticsRequest::ToJson(const PFCharacterResetCharacterStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ListUsersCharactersRequest::ToJson() const
{
    return ListUsersCharactersRequest::ToJson(this->Model());
}

JsonValue ListUsersCharactersRequest::ToJson(const PFCharacterListUsersCharactersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ListUsersCharactersResult::FromJson(const JsonValue& input)
{
    ModelVector<CharacterResult> characters{};
    JsonUtils::ObjectGetMember<CharacterResult>(input, "Characters", characters);
    this->SetCharacters(std::move(characters));
}

size_t ListUsersCharactersResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterListUsersCharactersResult const*> ListUsersCharactersResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListUsersCharactersResult>(&this->Model());
}

size_t ListUsersCharactersResult::RequiredBufferSize(const PFCharacterListUsersCharactersResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCharacterResult*) + sizeof(PFCharacterResult*) * model.charactersCount);
    for (size_t i = 0; i < model.charactersCount; ++i)
    {
        requiredSize += CharacterResult::RequiredBufferSize(*model.characters[i]);
    }
    return requiredSize;
}

HRESULT ListUsersCharactersResult::Copy(const PFCharacterListUsersCharactersResult& input, PFCharacterListUsersCharactersResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CharacterResult>(input.characters, input.charactersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characters = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetCharacterDataRequest::ToJson() const
{
    return GetCharacterDataRequest::ToJson(this->Model());
}

JsonValue GetCharacterDataRequest::ToJson(const PFCharacterGetCharacterDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "IfChangedFromDataVersion", input.ifChangedFromDataVersion);
    JsonUtils::ObjectAddMemberArray(output, "Keys", input.keys, input.keysCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ClientGetCharacterDataResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);
}

size_t ClientGetCharacterDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterClientGetCharacterDataResult const*> ClientGetCharacterDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetCharacterDataResult>(&this->Model());
}

size_t ClientGetCharacterDataResult::RequiredBufferSize(const PFCharacterClientGetCharacterDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    return requiredSize;
}

HRESULT ClientGetCharacterDataResult::Copy(const PFCharacterClientGetCharacterDataResult& input, PFCharacterClientGetCharacterDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetCharacterLeaderboardRequest::ToJson() const
{
    return GetCharacterLeaderboardRequest::ToJson(this->Model());
}

JsonValue GetCharacterLeaderboardRequest::ToJson(const PFCharacterGetCharacterLeaderboardRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterType", input.characterType);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "StartPosition", input.startPosition);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void CharacterLeaderboardEntry::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    String characterName{};
    JsonUtils::ObjectGetMember(input, "CharacterName", characterName);
    this->SetCharacterName(std::move(characterName));

    String characterType{};
    JsonUtils::ObjectGetMember(input, "CharacterType", characterType);
    this->SetCharacterType(std::move(characterType));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    JsonUtils::ObjectGetMember(input, "Position", this->m_model.position);

    JsonUtils::ObjectGetMember(input, "StatValue", this->m_model.statValue);
}

size_t CharacterLeaderboardEntry::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterCharacterLeaderboardEntry const*> CharacterLeaderboardEntry::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CharacterLeaderboardEntry>(&this->Model());
}

size_t CharacterLeaderboardEntry::RequiredBufferSize(const PFCharacterCharacterLeaderboardEntry& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    if (model.characterName)
    {
        requiredSize += (std::strlen(model.characterName) + 1);
    }
    if (model.characterType)
    {
        requiredSize += (std::strlen(model.characterType) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT CharacterLeaderboardEntry::Copy(const PFCharacterCharacterLeaderboardEntry& input, PFCharacterCharacterLeaderboardEntry& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.characterName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.characterType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetCharacterLeaderboardResult::FromJson(const JsonValue& input)
{
    ModelVector<CharacterLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<CharacterLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));
}

size_t GetCharacterLeaderboardResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterGetCharacterLeaderboardResult const*> GetCharacterLeaderboardResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetCharacterLeaderboardResult>(&this->Model());
}

size_t GetCharacterLeaderboardResult::RequiredBufferSize(const PFCharacterGetCharacterLeaderboardResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCharacterCharacterLeaderboardEntry*) + sizeof(PFCharacterCharacterLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += CharacterLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    return requiredSize;
}

HRESULT GetCharacterLeaderboardResult::Copy(const PFCharacterGetCharacterLeaderboardResult& input, PFCharacterGetCharacterLeaderboardResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CharacterLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGetCharacterStatisticsRequest::ToJson() const
{
    return ClientGetCharacterStatisticsRequest::ToJson(this->Model());
}

JsonValue ClientGetCharacterStatisticsRequest::ToJson(const PFCharacterClientGetCharacterStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    return output;
}

void ClientGetCharacterStatisticsResult::FromJson(const JsonValue& input)
{
    DictionaryEntryVector<PFInt32DictionaryEntry> characterStatistics{};
    JsonUtils::ObjectGetMember(input, "CharacterStatistics", characterStatistics);
    this->SetCharacterStatistics(std::move(characterStatistics));
}

size_t ClientGetCharacterStatisticsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterClientGetCharacterStatisticsResult const*> ClientGetCharacterStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetCharacterStatisticsResult>(&this->Model());
}

size_t ClientGetCharacterStatisticsResult::RequiredBufferSize(const PFCharacterClientGetCharacterStatisticsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.characterStatisticsCount);
    for (size_t i = 0; i < model.characterStatisticsCount; ++i)
    {
        requiredSize += (std::strlen(model.characterStatistics[i].key) + 1);
    }
    return requiredSize;
}

HRESULT ClientGetCharacterStatisticsResult::Copy(const PFCharacterClientGetCharacterStatisticsResult& input, PFCharacterClientGetCharacterStatisticsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary(input.characterStatistics, input.characterStatisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterStatistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGetLeaderboardAroundCharacterRequest::ToJson() const
{
    return ClientGetLeaderboardAroundCharacterRequest::ToJson(this->Model());
}

JsonValue ClientGetLeaderboardAroundCharacterRequest::ToJson(const PFCharacterClientGetLeaderboardAroundCharacterRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "CharacterType", input.characterType);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void GetLeaderboardAroundCharacterResult::FromJson(const JsonValue& input)
{
    ModelVector<CharacterLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<CharacterLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));
}

size_t GetLeaderboardAroundCharacterResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterGetLeaderboardAroundCharacterResult const*> GetLeaderboardAroundCharacterResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardAroundCharacterResult>(&this->Model());
}

size_t GetLeaderboardAroundCharacterResult::RequiredBufferSize(const PFCharacterGetLeaderboardAroundCharacterResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCharacterCharacterLeaderboardEntry*) + sizeof(PFCharacterCharacterLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += CharacterLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    return requiredSize;
}

HRESULT GetLeaderboardAroundCharacterResult::Copy(const PFCharacterGetLeaderboardAroundCharacterResult& input, PFCharacterGetLeaderboardAroundCharacterResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CharacterLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGetLeaderboardForUsersCharactersRequest::ToJson() const
{
    return ClientGetLeaderboardForUsersCharactersRequest::ToJson(this->Model());
}

JsonValue ClientGetLeaderboardForUsersCharactersRequest::ToJson(const PFCharacterClientGetLeaderboardForUsersCharactersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void GetLeaderboardForUsersCharactersResult::FromJson(const JsonValue& input)
{
    ModelVector<CharacterLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<CharacterLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));
}

size_t GetLeaderboardForUsersCharactersResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterGetLeaderboardForUsersCharactersResult const*> GetLeaderboardForUsersCharactersResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardForUsersCharactersResult>(&this->Model());
}

size_t GetLeaderboardForUsersCharactersResult::RequiredBufferSize(const PFCharacterGetLeaderboardForUsersCharactersResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCharacterCharacterLeaderboardEntry*) + sizeof(PFCharacterCharacterLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += CharacterLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    return requiredSize;
}

HRESULT GetLeaderboardForUsersCharactersResult::Copy(const PFCharacterGetLeaderboardForUsersCharactersResult& input, PFCharacterGetLeaderboardForUsersCharactersResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CharacterLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGrantCharacterToUserRequest::ToJson() const
{
    return ClientGrantCharacterToUserRequest::ToJson(this->Model());
}

JsonValue ClientGrantCharacterToUserRequest::ToJson(const PFCharacterClientGrantCharacterToUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterName", input.characterName);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    return output;
}

void ClientGrantCharacterToUserResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    String characterType{};
    JsonUtils::ObjectGetMember(input, "CharacterType", characterType);
    this->SetCharacterType(std::move(characterType));

    JsonUtils::ObjectGetMember(input, "Result", this->m_model.result);
}

size_t ClientGrantCharacterToUserResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterClientGrantCharacterToUserResult const*> ClientGrantCharacterToUserResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGrantCharacterToUserResult>(&this->Model());
}

size_t ClientGrantCharacterToUserResult::RequiredBufferSize(const PFCharacterClientGrantCharacterToUserResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    if (model.characterType)
    {
        requiredSize += (std::strlen(model.characterType) + 1);
    }
    return requiredSize;
}

HRESULT ClientGrantCharacterToUserResult::Copy(const PFCharacterClientGrantCharacterToUserResult& input, PFCharacterClientGrantCharacterToUserResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.characterType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterType = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientUpdateCharacterDataRequest::ToJson() const
{
    return ClientUpdateCharacterDataRequest::ToJson(this->Model());
}

JsonValue ClientUpdateCharacterDataRequest::ToJson(const PFCharacterClientUpdateCharacterDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    return output;
}

void UpdateCharacterDataResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);
}

size_t UpdateCharacterDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterUpdateCharacterDataResult const*> UpdateCharacterDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateCharacterDataResult>(&this->Model());
}

size_t UpdateCharacterDataResult::RequiredBufferSize(const PFCharacterUpdateCharacterDataResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT UpdateCharacterDataResult::Copy(const PFCharacterUpdateCharacterDataResult& input, PFCharacterUpdateCharacterDataResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue ClientUpdateCharacterStatisticsRequest::ToJson() const
{
    return ClientUpdateCharacterStatisticsRequest::ToJson(this->Model());
}

JsonValue ClientUpdateCharacterStatisticsRequest::ToJson(const PFCharacterClientUpdateCharacterStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CharacterStatistics", input.characterStatistics, input.characterStatisticsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue DeleteCharacterFromUserRequest::ToJson() const
{
    return DeleteCharacterFromUserRequest::ToJson(this->Model());
}

JsonValue DeleteCharacterFromUserRequest::ToJson(const PFCharacterDeleteCharacterFromUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "SaveCharacterInventory", input.saveCharacterInventory);
    return output;
}

void ServerGetCharacterDataResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t ServerGetCharacterDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterServerGetCharacterDataResult const*> ServerGetCharacterDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetCharacterDataResult>(&this->Model());
}

size_t ServerGetCharacterDataResult::RequiredBufferSize(const PFCharacterServerGetCharacterDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT ServerGetCharacterDataResult::Copy(const PFCharacterServerGetCharacterDataResult& input, PFCharacterServerGetCharacterDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerGetCharacterStatisticsRequest::ToJson() const
{
    return ServerGetCharacterStatisticsRequest::ToJson(this->Model());
}

JsonValue ServerGetCharacterStatisticsRequest::ToJson(const PFCharacterServerGetCharacterStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ServerGetCharacterStatisticsResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    DictionaryEntryVector<PFInt32DictionaryEntry> characterStatistics{};
    JsonUtils::ObjectGetMember(input, "CharacterStatistics", characterStatistics);
    this->SetCharacterStatistics(std::move(characterStatistics));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t ServerGetCharacterStatisticsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterServerGetCharacterStatisticsResult const*> ServerGetCharacterStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetCharacterStatisticsResult>(&this->Model());
}

size_t ServerGetCharacterStatisticsResult::RequiredBufferSize(const PFCharacterServerGetCharacterStatisticsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.characterStatisticsCount);
    for (size_t i = 0; i < model.characterStatisticsCount; ++i)
    {
        requiredSize += (std::strlen(model.characterStatistics[i].key) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT ServerGetCharacterStatisticsResult::Copy(const PFCharacterServerGetCharacterStatisticsResult& input, PFCharacterServerGetCharacterStatisticsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.characterStatistics, input.characterStatisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterStatistics = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerGetLeaderboardAroundCharacterRequest::ToJson() const
{
    return ServerGetLeaderboardAroundCharacterRequest::ToJson(this->Model());
}

JsonValue ServerGetLeaderboardAroundCharacterRequest::ToJson(const PFCharacterServerGetLeaderboardAroundCharacterRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "CharacterType", input.characterType);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

JsonValue ServerGetLeaderboardForUsersCharactersRequest::ToJson() const
{
    return ServerGetLeaderboardForUsersCharactersRequest::ToJson(this->Model());
}

JsonValue ServerGetLeaderboardForUsersCharactersRequest::ToJson(const PFCharacterServerGetLeaderboardForUsersCharactersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

JsonValue ServerGrantCharacterToUserRequest::ToJson() const
{
    return ServerGrantCharacterToUserRequest::ToJson(this->Model());
}

JsonValue ServerGrantCharacterToUserRequest::ToJson(const PFCharacterServerGrantCharacterToUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterName", input.characterName);
    JsonUtils::ObjectAddMember(output, "CharacterType", input.characterType);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ServerGrantCharacterToUserResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));
}

size_t ServerGrantCharacterToUserResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCharacterServerGrantCharacterToUserResult const*> ServerGrantCharacterToUserResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGrantCharacterToUserResult>(&this->Model());
}

size_t ServerGrantCharacterToUserResult::RequiredBufferSize(const PFCharacterServerGrantCharacterToUserResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    return requiredSize;
}

HRESULT ServerGrantCharacterToUserResult::Copy(const PFCharacterServerGrantCharacterToUserResult& input, PFCharacterServerGrantCharacterToUserResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerUpdateCharacterDataRequest::ToJson() const
{
    return ServerUpdateCharacterDataRequest::ToJson(this->Model());
}

JsonValue ServerUpdateCharacterDataRequest::ToJson(const PFCharacterServerUpdateCharacterDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerUpdateCharacterStatisticsRequest::ToJson() const
{
    return ServerUpdateCharacterStatisticsRequest::ToJson(this->Model());
}

JsonValue ServerUpdateCharacterStatisticsRequest::ToJson(const PFCharacterServerUpdateCharacterStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CharacterStatistics", input.characterStatistics, input.characterStatisticsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

} // namespace Character
} // namespace PlayFab
