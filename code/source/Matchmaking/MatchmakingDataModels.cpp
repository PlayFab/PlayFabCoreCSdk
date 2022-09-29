#include "stdafx.h"
#include "MatchmakingDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Matchmaking
{

JsonValue GetMatchmakerGameInfoRequest::ToJson() const
{
    return GetMatchmakerGameInfoRequest::ToJson(this->Model());
}

JsonValue GetMatchmakerGameInfoRequest::ToJson(const PFMatchmakingGetMatchmakerGameInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    return output;
}

void GetMatchmakerGameInfoResult::FromJson(const JsonValue& input)
{
    String buildVersion{};
    JsonUtils::ObjectGetMember(input, "BuildVersion", buildVersion);
    this->SetBuildVersion(std::move(buildVersion));

    StdExtra::optional<time_t> endTime{};
    JsonUtils::ObjectGetMemberTime(input, "EndTime", endTime);
    this->SetEndTime(std::move(endTime));

    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));

    String mode{};
    JsonUtils::ObjectGetMember(input, "Mode", mode);
    this->SetMode(std::move(mode));

    CStringVector players{};
    JsonUtils::ObjectGetMember(input, "Players", players);
    this->SetPlayers(std::move(players));

    StdExtra::optional<PFRegion> region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    String serverIPV4Address{};
    JsonUtils::ObjectGetMember(input, "ServerIPV4Address", serverIPV4Address);
    this->SetServerIPV4Address(std::move(serverIPV4Address));

    String serverIPV6Address{};
    JsonUtils::ObjectGetMember(input, "ServerIPV6Address", serverIPV6Address);
    this->SetServerIPV6Address(std::move(serverIPV6Address));

    JsonUtils::ObjectGetMember(input, "ServerPort", this->m_model.serverPort);

    String serverPublicDNSName{};
    JsonUtils::ObjectGetMember(input, "ServerPublicDNSName", serverPublicDNSName);
    this->SetServerPublicDNSName(std::move(serverPublicDNSName));

    JsonUtils::ObjectGetMemberTime(input, "StartTime", this->m_model.startTime);

    String titleId{};
    JsonUtils::ObjectGetMember(input, "TitleId", titleId);
    this->SetTitleId(std::move(titleId));
}

size_t GetMatchmakerGameInfoResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGetMatchmakerGameInfoResult const*> GetMatchmakerGameInfoResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMatchmakerGameInfoResult>(&this->Model());
}

size_t GetMatchmakerGameInfoResult::RequiredBufferSize(const PFMatchmakingGetMatchmakerGameInfoResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.buildVersion)
    {
        requiredSize += (std::strlen(model.buildVersion) + 1);
    }
    if (model.endTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    if (model.mode)
    {
        requiredSize += (std::strlen(model.mode) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.playersCount);
    for (size_t i = 0; i < model.playersCount; ++i)
    {
        requiredSize += (std::strlen(model.players[i]) + 1);
    }
    if (model.region)
    {
        requiredSize += (alignof(PFRegion) + sizeof(PFRegion));
    }
    if (model.serverIPV4Address)
    {
        requiredSize += (std::strlen(model.serverIPV4Address) + 1);
    }
    if (model.serverIPV6Address)
    {
        requiredSize += (std::strlen(model.serverIPV6Address) + 1);
    }
    if (model.serverPublicDNSName)
    {
        requiredSize += (std::strlen(model.serverPublicDNSName) + 1);
    }
    if (model.titleId)
    {
        requiredSize += (std::strlen(model.titleId) + 1);
    }
    return requiredSize;
}

HRESULT GetMatchmakerGameInfoResult::Copy(const PFMatchmakingGetMatchmakerGameInfoResult& input, PFMatchmakingGetMatchmakerGameInfoResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.buildVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.endTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.endTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.mode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.mode = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.players, input.playersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.players = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverIPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverIPV4Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverIPV6Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverIPV6Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverPublicDNSName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverPublicDNSName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetMatchmakerGameModesRequest::ToJson() const
{
    return GetMatchmakerGameModesRequest::ToJson(this->Model());
}

JsonValue GetMatchmakerGameModesRequest::ToJson(const PFMatchmakingGetMatchmakerGameModesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildVersion", input.buildVersion);
    return output;
}

void GameModeInfo::FromJson(const JsonValue& input)
{
    String gamemode{};
    JsonUtils::ObjectGetMember(input, "Gamemode", gamemode);
    this->SetGamemode(std::move(gamemode));

    JsonUtils::ObjectGetMember(input, "MaxPlayerCount", this->m_model.maxPlayerCount);

    JsonUtils::ObjectGetMember(input, "MinPlayerCount", this->m_model.minPlayerCount);

    StdExtra::optional<bool> startOpen{};
    JsonUtils::ObjectGetMember(input, "StartOpen", startOpen);
    this->SetStartOpen(std::move(startOpen));
}

size_t GameModeInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGameModeInfo const*> GameModeInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GameModeInfo>(&this->Model());
}

size_t GameModeInfo::RequiredBufferSize(const PFMatchmakingGameModeInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.gamemode)
    {
        requiredSize += (std::strlen(model.gamemode) + 1);
    }
    if (model.startOpen)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    return requiredSize;
}

HRESULT GameModeInfo::Copy(const PFMatchmakingGameModeInfo& input, PFMatchmakingGameModeInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.gamemode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gamemode = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.startOpen); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.startOpen = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetMatchmakerGameModesResult::FromJson(const JsonValue& input)
{
    ModelVector<GameModeInfo> gameModes{};
    JsonUtils::ObjectGetMember<GameModeInfo>(input, "GameModes", gameModes);
    this->SetGameModes(std::move(gameModes));
}

size_t GetMatchmakerGameModesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGetMatchmakerGameModesResult const*> GetMatchmakerGameModesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMatchmakerGameModesResult>(&this->Model());
}

size_t GetMatchmakerGameModesResult::RequiredBufferSize(const PFMatchmakingGetMatchmakerGameModesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMatchmakingGameModeInfo*) + sizeof(PFMatchmakingGameModeInfo*) * model.gameModesCount);
    for (size_t i = 0; i < model.gameModesCount; ++i)
    {
        requiredSize += GameModeInfo::RequiredBufferSize(*model.gameModes[i]);
    }
    return requiredSize;
}

HRESULT GetMatchmakerGameModesResult::Copy(const PFMatchmakingGetMatchmakerGameModesResult& input, PFMatchmakingGetMatchmakerGameModesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GameModeInfo>(input.gameModes, input.gameModesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameModes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Container_Dictionary_String_String::ToJson() const
{
    return Container_Dictionary_String_String::ToJson(this->Model());
}

JsonValue Container_Dictionary_String_String::ToJson(const PFMatchmakingContainer_Dictionary_String_String& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    return output;
}

JsonValue CollectionFilter::ToJson() const
{
    return CollectionFilter::ToJson(this->Model());
}

JsonValue CollectionFilter::ToJson(const PFMatchmakingCollectionFilter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<Container_Dictionary_String_String>(output, "Excludes", input.excludes, input.excludesCount);
    JsonUtils::ObjectAddMemberArray<Container_Dictionary_String_String>(output, "Includes", input.includes, input.includesCount);
    return output;
}

JsonValue CurrentGamesRequest::ToJson() const
{
    return CurrentGamesRequest::ToJson(this->Model());
}

JsonValue CurrentGamesRequest::ToJson(const PFMatchmakingCurrentGamesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildVersion", input.buildVersion);
    JsonUtils::ObjectAddMember(output, "GameMode", input.gameMode);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember<CollectionFilter>(output, "TagFilter", input.tagFilter);
    return output;
}

void GameInfo::FromJson(const JsonValue& input)
{
    String buildVersion{};
    JsonUtils::ObjectGetMember(input, "BuildVersion", buildVersion);
    this->SetBuildVersion(std::move(buildVersion));

    String gameMode{};
    JsonUtils::ObjectGetMember(input, "GameMode", gameMode);
    this->SetGameMode(std::move(gameMode));

    String gameServerData{};
    JsonUtils::ObjectGetMember(input, "GameServerData", gameServerData);
    this->SetGameServerData(std::move(gameServerData));

    StdExtra::optional<PFMatchmakingGameInstanceState> gameServerStateEnum{};
    JsonUtils::ObjectGetMember(input, "GameServerStateEnum", gameServerStateEnum);
    this->SetGameServerStateEnum(std::move(gameServerStateEnum));

    StdExtra::optional<time_t> lastHeartbeat{};
    JsonUtils::ObjectGetMemberTime(input, "LastHeartbeat", lastHeartbeat);
    this->SetLastHeartbeat(std::move(lastHeartbeat));

    String lobbyID{};
    JsonUtils::ObjectGetMember(input, "LobbyID", lobbyID);
    this->SetLobbyID(std::move(lobbyID));

    StdExtra::optional<int32_t> maxPlayers{};
    JsonUtils::ObjectGetMember(input, "MaxPlayers", maxPlayers);
    this->SetMaxPlayers(std::move(maxPlayers));

    CStringVector playerUserIds{};
    JsonUtils::ObjectGetMember(input, "PlayerUserIds", playerUserIds);
    this->SetPlayerUserIds(std::move(playerUserIds));

    StdExtra::optional<PFRegion> region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    JsonUtils::ObjectGetMember(input, "RunTime", this->m_model.runTime);

    String serverIPV4Address{};
    JsonUtils::ObjectGetMember(input, "ServerIPV4Address", serverIPV4Address);
    this->SetServerIPV4Address(std::move(serverIPV4Address));

    String serverIPV6Address{};
    JsonUtils::ObjectGetMember(input, "ServerIPV6Address", serverIPV6Address);
    this->SetServerIPV6Address(std::move(serverIPV6Address));

    StdExtra::optional<int32_t> serverPort{};
    JsonUtils::ObjectGetMember(input, "ServerPort", serverPort);
    this->SetServerPort(std::move(serverPort));

    String serverPublicDNSName{};
    JsonUtils::ObjectGetMember(input, "ServerPublicDNSName", serverPublicDNSName);
    this->SetServerPublicDNSName(std::move(serverPublicDNSName));

    String statisticName{};
    JsonUtils::ObjectGetMember(input, "StatisticName", statisticName);
    this->SetStatisticName(std::move(statisticName));

    StringDictionaryEntryVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));
}

size_t GameInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGameInfo const*> GameInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GameInfo>(&this->Model());
}

size_t GameInfo::RequiredBufferSize(const PFMatchmakingGameInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.buildVersion)
    {
        requiredSize += (std::strlen(model.buildVersion) + 1);
    }
    if (model.gameMode)
    {
        requiredSize += (std::strlen(model.gameMode) + 1);
    }
    if (model.gameServerData)
    {
        requiredSize += (std::strlen(model.gameServerData) + 1);
    }
    if (model.gameServerStateEnum)
    {
        requiredSize += (alignof(PFMatchmakingGameInstanceState) + sizeof(PFMatchmakingGameInstanceState));
    }
    if (model.lastHeartbeat)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.lobbyID)
    {
        requiredSize += (std::strlen(model.lobbyID) + 1);
    }
    if (model.maxPlayers)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.playerUserIdsCount);
    for (size_t i = 0; i < model.playerUserIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.playerUserIds[i]) + 1);
    }
    if (model.region)
    {
        requiredSize += (alignof(PFRegion) + sizeof(PFRegion));
    }
    if (model.serverIPV4Address)
    {
        requiredSize += (std::strlen(model.serverIPV4Address) + 1);
    }
    if (model.serverIPV6Address)
    {
        requiredSize += (std::strlen(model.serverIPV6Address) + 1);
    }
    if (model.serverPort)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.serverPublicDNSName)
    {
        requiredSize += (std::strlen(model.serverPublicDNSName) + 1);
    }
    if (model.statisticName)
    {
        requiredSize += (std::strlen(model.statisticName) + 1);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i].key) + 1);
        requiredSize += (std::strlen(model.tags[i].value) + 1);
    }
    return requiredSize;
}

HRESULT GameInfo::Copy(const PFMatchmakingGameInfo& input, PFMatchmakingGameInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.buildVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.gameMode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameMode = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.gameServerData); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameServerData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.gameServerStateEnum); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameServerStateEnum = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastHeartbeat); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastHeartbeat = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyID); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyID = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.maxPlayers); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.maxPlayers = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.playerUserIds, input.playerUserIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerUserIds = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverIPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverIPV4Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverIPV6Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverIPV6Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverPort); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverPort = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverPublicDNSName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverPublicDNSName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.statisticName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void CurrentGamesResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "GameCount", this->m_model.gameCount);

    ModelVector<GameInfo> games{};
    JsonUtils::ObjectGetMember<GameInfo>(input, "Games", games);
    this->SetGames(std::move(games));

    JsonUtils::ObjectGetMember(input, "PlayerCount", this->m_model.playerCount);
}

size_t CurrentGamesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingCurrentGamesResult const*> CurrentGamesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CurrentGamesResult>(&this->Model());
}

size_t CurrentGamesResult::RequiredBufferSize(const PFMatchmakingCurrentGamesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMatchmakingGameInfo*) + sizeof(PFMatchmakingGameInfo*) * model.gamesCount);
    for (size_t i = 0; i < model.gamesCount; ++i)
    {
        requiredSize += GameInfo::RequiredBufferSize(*model.games[i]);
    }
    return requiredSize;
}

HRESULT CurrentGamesResult::Copy(const PFMatchmakingCurrentGamesResult& input, PFMatchmakingCurrentGamesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GameInfo>(input.games, input.gamesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.games = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GameServerRegionsRequest::ToJson() const
{
    return GameServerRegionsRequest::ToJson(this->Model());
}

JsonValue GameServerRegionsRequest::ToJson(const PFMatchmakingGameServerRegionsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildVersion", input.buildVersion);
    JsonUtils::ObjectAddMember(output, "TitleId", input.titleId);
    return output;
}

void RegionInfo::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Available", this->m_model.available);

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    String pingUrl{};
    JsonUtils::ObjectGetMember(input, "PingUrl", pingUrl);
    this->SetPingUrl(std::move(pingUrl));

    StdExtra::optional<PFRegion> region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));
}

size_t RegionInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingRegionInfo const*> RegionInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RegionInfo>(&this->Model());
}

size_t RegionInfo::RequiredBufferSize(const PFMatchmakingRegionInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.pingUrl)
    {
        requiredSize += (std::strlen(model.pingUrl) + 1);
    }
    if (model.region)
    {
        requiredSize += (alignof(PFRegion) + sizeof(PFRegion));
    }
    return requiredSize;
}

HRESULT RegionInfo::Copy(const PFMatchmakingRegionInfo& input, PFMatchmakingRegionInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.pingUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pingUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GameServerRegionsResult::FromJson(const JsonValue& input)
{
    ModelVector<RegionInfo> regions{};
    JsonUtils::ObjectGetMember<RegionInfo>(input, "Regions", regions);
    this->SetRegions(std::move(regions));
}

size_t GameServerRegionsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGameServerRegionsResult const*> GameServerRegionsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GameServerRegionsResult>(&this->Model());
}

size_t GameServerRegionsResult::RequiredBufferSize(const PFMatchmakingGameServerRegionsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMatchmakingRegionInfo*) + sizeof(PFMatchmakingRegionInfo*) * model.regionsCount);
    for (size_t i = 0; i < model.regionsCount; ++i)
    {
        requiredSize += RegionInfo::RequiredBufferSize(*model.regions[i]);
    }
    return requiredSize;
}

HRESULT GameServerRegionsResult::Copy(const PFMatchmakingGameServerRegionsResult& input, PFMatchmakingGameServerRegionsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RegionInfo>(input.regions, input.regionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue MatchmakeRequest::ToJson() const
{
    return MatchmakeRequest::ToJson(this->Model());
}

JsonValue MatchmakeRequest::ToJson(const PFMatchmakingMatchmakeRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildVersion", input.buildVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "GameMode", input.gameMode);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "StartNewIfNoneFound", input.startNewIfNoneFound);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember<CollectionFilter>(output, "TagFilter", input.tagFilter);
    return output;
}

void MatchmakeResult::FromJson(const JsonValue& input)
{
    String expires{};
    JsonUtils::ObjectGetMember(input, "Expires", expires);
    this->SetExpires(std::move(expires));

    String lobbyID{};
    JsonUtils::ObjectGetMember(input, "LobbyID", lobbyID);
    this->SetLobbyID(std::move(lobbyID));

    StdExtra::optional<int32_t> pollWaitTimeMS{};
    JsonUtils::ObjectGetMember(input, "PollWaitTimeMS", pollWaitTimeMS);
    this->SetPollWaitTimeMS(std::move(pollWaitTimeMS));

    String serverIPV4Address{};
    JsonUtils::ObjectGetMember(input, "ServerIPV4Address", serverIPV4Address);
    this->SetServerIPV4Address(std::move(serverIPV4Address));

    String serverIPV6Address{};
    JsonUtils::ObjectGetMember(input, "ServerIPV6Address", serverIPV6Address);
    this->SetServerIPV6Address(std::move(serverIPV6Address));

    StdExtra::optional<int32_t> serverPort{};
    JsonUtils::ObjectGetMember(input, "ServerPort", serverPort);
    this->SetServerPort(std::move(serverPort));

    String serverPublicDNSName{};
    JsonUtils::ObjectGetMember(input, "ServerPublicDNSName", serverPublicDNSName);
    this->SetServerPublicDNSName(std::move(serverPublicDNSName));

    StdExtra::optional<PFMatchmakingMatchmakeStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    String ticket{};
    JsonUtils::ObjectGetMember(input, "Ticket", ticket);
    this->SetTicket(std::move(ticket));
}

size_t MatchmakeResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingMatchmakeResult const*> MatchmakeResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<MatchmakeResult>(&this->Model());
}

size_t MatchmakeResult::RequiredBufferSize(const PFMatchmakingMatchmakeResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.expires)
    {
        requiredSize += (std::strlen(model.expires) + 1);
    }
    if (model.lobbyID)
    {
        requiredSize += (std::strlen(model.lobbyID) + 1);
    }
    if (model.pollWaitTimeMS)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.serverIPV4Address)
    {
        requiredSize += (std::strlen(model.serverIPV4Address) + 1);
    }
    if (model.serverIPV6Address)
    {
        requiredSize += (std::strlen(model.serverIPV6Address) + 1);
    }
    if (model.serverPort)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.serverPublicDNSName)
    {
        requiredSize += (std::strlen(model.serverPublicDNSName) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFMatchmakingMatchmakeStatus) + sizeof(PFMatchmakingMatchmakeStatus));
    }
    if (model.ticket)
    {
        requiredSize += (std::strlen(model.ticket) + 1);
    }
    return requiredSize;
}

HRESULT MatchmakeResult::Copy(const PFMatchmakingMatchmakeResult& input, PFMatchmakingMatchmakeResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.expires); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.expires = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyID); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyID = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.pollWaitTimeMS); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pollWaitTimeMS = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverIPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverIPV4Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverIPV6Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverIPV6Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverPort); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverPort = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverPublicDNSName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverPublicDNSName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.ticket); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticket = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AuthUserRequest::ToJson() const
{
    return AuthUserRequest::ToJson(this->Model());
}

JsonValue AuthUserRequest::ToJson(const PFMatchmakingAuthUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthorizationTicket", input.authorizationTicket);
    return output;
}

void AuthUserResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Authorized", this->m_model.authorized);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t AuthUserResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingAuthUserResponse const*> AuthUserResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AuthUserResponse>(&this->Model());
}

size_t AuthUserResponse::RequiredBufferSize(const PFMatchmakingAuthUserResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT AuthUserResponse::Copy(const PFMatchmakingAuthUserResponse& input, PFMatchmakingAuthUserResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PlayerJoinedRequest::ToJson() const
{
    return PlayerJoinedRequest::ToJson(this->Model());
}

JsonValue PlayerJoinedRequest::ToJson(const PFMatchmakingPlayerJoinedRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue PlayerLeftRequest::ToJson() const
{
    return PlayerLeftRequest::ToJson(this->Model());
}

JsonValue PlayerLeftRequest::ToJson(const PFMatchmakingPlayerLeftRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue UserInfoRequest::ToJson() const
{
    return UserInfoRequest::ToJson(this->Model());
}

JsonValue UserInfoRequest::ToJson(const PFMatchmakingUserInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MinCatalogVersion", input.minCatalogVersion);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void UserInfoResponse::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> inventory{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Inventory", inventory);
    this->SetInventory(std::move(inventory));

    JsonUtils::ObjectGetMember(input, "IsDeveloper", this->m_model.isDeveloper);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String steamId{};
    JsonUtils::ObjectGetMember(input, "SteamId", steamId);
    this->SetSteamId(std::move(steamId));

    String titleDisplayName{};
    JsonUtils::ObjectGetMember(input, "TitleDisplayName", titleDisplayName);
    this->SetTitleDisplayName(std::move(titleDisplayName));

    String username{};
    JsonUtils::ObjectGetMember(input, "Username", username);
    this->SetUsername(std::move(username));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));

    ModelDictionaryEntryVector<VirtualCurrencyRechargeTime> virtualCurrencyRechargeTimes{};
    JsonUtils::ObjectGetMember<VirtualCurrencyRechargeTime>(input, "VirtualCurrencyRechargeTimes", virtualCurrencyRechargeTimes);
    this->SetVirtualCurrencyRechargeTimes(std::move(virtualCurrencyRechargeTimes));
}

size_t UserInfoResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingUserInfoResponse const*> UserInfoResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UserInfoResponse>(&this->Model());
}

size_t UserInfoResponse::RequiredBufferSize(const PFMatchmakingUserInfoResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.inventoryCount);
    for (size_t i = 0; i < model.inventoryCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.inventory[i]);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.steamId)
    {
        requiredSize += (std::strlen(model.steamId) + 1);
    }
    if (model.titleDisplayName)
    {
        requiredSize += (std::strlen(model.titleDisplayName) + 1);
    }
    if (model.username)
    {
        requiredSize += (std::strlen(model.username) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    requiredSize += (alignof(PFVirtualCurrencyRechargeTimeDictionaryEntry) + sizeof(PFVirtualCurrencyRechargeTimeDictionaryEntry) * model.virtualCurrencyRechargeTimesCount);
    for (size_t i = 0; i < model.virtualCurrencyRechargeTimesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyRechargeTimes[i].key) + 1);
        requiredSize += VirtualCurrencyRechargeTime::RequiredBufferSize(*model.virtualCurrencyRechargeTimes[i].value);
    }
    return requiredSize;
}

HRESULT UserInfoResponse::Copy(const PFMatchmakingUserInfoResponse& input, PFMatchmakingUserInfoResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.inventory, input.inventoryCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.inventory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.steamId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.steamId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleDisplayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleDisplayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.username); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.username = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<VirtualCurrencyRechargeTime>(input.virtualCurrencyRechargeTimes, input.virtualCurrencyRechargeTimesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyRechargeTimes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeregisterGameRequest::ToJson() const
{
    return DeregisterGameRequest::ToJson(this->Model());
}

JsonValue DeregisterGameRequest::ToJson(const PFMatchmakingDeregisterGameRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    return output;
}

JsonValue NotifyMatchmakerPlayerLeftRequest::ToJson() const
{
    return NotifyMatchmakerPlayerLeftRequest::ToJson(this->Model());
}

JsonValue NotifyMatchmakerPlayerLeftRequest::ToJson(const PFMatchmakingNotifyMatchmakerPlayerLeftRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void NotifyMatchmakerPlayerLeftResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFMatchmakingPlayerConnectionState> playerState{};
    JsonUtils::ObjectGetMember(input, "PlayerState", playerState);
    this->SetPlayerState(std::move(playerState));
}

size_t NotifyMatchmakerPlayerLeftResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingNotifyMatchmakerPlayerLeftResult const*> NotifyMatchmakerPlayerLeftResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<NotifyMatchmakerPlayerLeftResult>(&this->Model());
}

size_t NotifyMatchmakerPlayerLeftResult::RequiredBufferSize(const PFMatchmakingNotifyMatchmakerPlayerLeftResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playerState)
    {
        requiredSize += (alignof(PFMatchmakingPlayerConnectionState) + sizeof(PFMatchmakingPlayerConnectionState));
    }
    return requiredSize;
}

HRESULT NotifyMatchmakerPlayerLeftResult::Copy(const PFMatchmakingNotifyMatchmakerPlayerLeftResult& input, PFMatchmakingNotifyMatchmakerPlayerLeftResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playerState); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerState = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RedeemMatchmakerTicketRequest::ToJson() const
{
    return RedeemMatchmakerTicketRequest::ToJson(this->Model());
}

JsonValue RedeemMatchmakerTicketRequest::ToJson(const PFMatchmakingRedeemMatchmakerTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "Ticket", input.ticket);
    return output;
}

void RedeemMatchmakerTicketResult::FromJson(const JsonValue& input)
{
    String error{};
    JsonUtils::ObjectGetMember(input, "Error", error);
    this->SetError(std::move(error));

    JsonUtils::ObjectGetMember(input, "TicketIsValid", this->m_model.ticketIsValid);

    StdExtra::optional<UserAccountInfo> userInfo{};
    JsonUtils::ObjectGetMember(input, "UserInfo", userInfo);
    if (userInfo)
    {
        this->SetUserInfo(std::move(*userInfo));
    }
}

size_t RedeemMatchmakerTicketResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingRedeemMatchmakerTicketResult const*> RedeemMatchmakerTicketResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemMatchmakerTicketResult>(&this->Model());
}

size_t RedeemMatchmakerTicketResult::RequiredBufferSize(const PFMatchmakingRedeemMatchmakerTicketResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.error)
    {
        requiredSize += (std::strlen(model.error) + 1);
    }
    if (model.userInfo)
    {
        requiredSize += UserAccountInfo::RequiredBufferSize(*model.userInfo);
    }
    return requiredSize;
}

HRESULT RedeemMatchmakerTicketResult::Copy(const PFMatchmakingRedeemMatchmakerTicketResult& input, PFMatchmakingRedeemMatchmakerTicketResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.error); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.error = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<UserAccountInfo>(input.userInfo); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userInfo = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RefreshGameServerInstanceHeartbeatRequest::ToJson() const
{
    return RefreshGameServerInstanceHeartbeatRequest::ToJson(this->Model());
}

JsonValue RefreshGameServerInstanceHeartbeatRequest::ToJson(const PFMatchmakingRefreshGameServerInstanceHeartbeatRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    return output;
}

JsonValue RegisterGameRequest::ToJson() const
{
    return RegisterGameRequest::ToJson(this->Model());
}

JsonValue RegisterGameRequest::ToJson(const PFMatchmakingRegisterGameRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Build", input.build);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "GameMode", input.gameMode);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "ServerIPV4Address", input.serverIPV4Address);
    JsonUtils::ObjectAddMember(output, "ServerIPV6Address", input.serverIPV6Address);
    JsonUtils::ObjectAddMember(output, "ServerPort", input.serverPort);
    JsonUtils::ObjectAddMember(output, "ServerPublicDNSName", input.serverPublicDNSName);
    JsonUtils::ObjectAddMemberDictionary(output, "Tags", input.tags, input.tagsCount);
    return output;
}

void RegisterGameResponse::FromJson(const JsonValue& input)
{
    String lobbyId{};
    JsonUtils::ObjectGetMember(input, "LobbyId", lobbyId);
    this->SetLobbyId(std::move(lobbyId));
}

size_t RegisterGameResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingRegisterGameResponse const*> RegisterGameResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RegisterGameResponse>(&this->Model());
}

size_t RegisterGameResponse::RequiredBufferSize(const PFMatchmakingRegisterGameResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.lobbyId)
    {
        requiredSize += (std::strlen(model.lobbyId) + 1);
    }
    return requiredSize;
}

HRESULT RegisterGameResponse::Copy(const PFMatchmakingRegisterGameResponse& input, PFMatchmakingRegisterGameResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.lobbyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lobbyId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SetGameServerInstanceDataRequest::ToJson() const
{
    return SetGameServerInstanceDataRequest::ToJson(this->Model());
}

JsonValue SetGameServerInstanceDataRequest::ToJson(const PFMatchmakingSetGameServerInstanceDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "GameServerData", input.gameServerData);
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    return output;
}

JsonValue SetGameServerInstanceStateRequest::ToJson() const
{
    return SetGameServerInstanceStateRequest::ToJson(this->Model());
}

JsonValue SetGameServerInstanceStateRequest::ToJson(const PFMatchmakingSetGameServerInstanceStateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMember(output, "State", input.state);
    return output;
}

JsonValue SetGameServerInstanceTagsRequest::ToJson() const
{
    return SetGameServerInstanceTagsRequest::ToJson(this->Model());
}

JsonValue SetGameServerInstanceTagsRequest::ToJson(const PFMatchmakingSetGameServerInstanceTagsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "LobbyId", input.lobbyId);
    JsonUtils::ObjectAddMemberDictionary(output, "Tags", input.tags, input.tagsCount);
    return output;
}

JsonValue CancelAllMatchmakingTicketsForPlayerRequest::ToJson() const
{
    return CancelAllMatchmakingTicketsForPlayerRequest::ToJson(this->Model());
}

JsonValue CancelAllMatchmakingTicketsForPlayerRequest::ToJson(const PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

JsonValue CancelAllServerBackfillTicketsForPlayerRequest::ToJson() const
{
    return CancelAllServerBackfillTicketsForPlayerRequest::ToJson(this->Model());
}

JsonValue CancelAllServerBackfillTicketsForPlayerRequest::ToJson(const PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

JsonValue CancelMatchmakingTicketRequest::ToJson() const
{
    return CancelMatchmakingTicketRequest::ToJson(this->Model());
}

JsonValue CancelMatchmakingTicketRequest::ToJson(const PFMatchmakingCancelMatchmakingTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember(output, "TicketId", input.ticketId);
    return output;
}

JsonValue CancelServerBackfillTicketRequest::ToJson() const
{
    return CancelServerBackfillTicketRequest::ToJson(this->Model());
}

JsonValue CancelServerBackfillTicketRequest::ToJson(const PFMatchmakingCancelServerBackfillTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember(output, "TicketId", input.ticketId);
    return output;
}

JsonValue MatchmakingPlayerAttributes::ToJson() const
{
    return MatchmakingPlayerAttributes::ToJson(this->Model());
}

JsonValue MatchmakingPlayerAttributes::ToJson(const PFMatchmakingMatchmakingPlayerAttributes& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "DataObject", input.dataObject);
    JsonUtils::ObjectAddMember(output, "EscapedDataObject", input.escapedDataObject);
    return output;
}

void MatchmakingPlayerAttributes::FromJson(const JsonValue& input)
{
    JsonObject dataObject{};
    JsonUtils::ObjectGetMember(input, "DataObject", dataObject);
    this->SetDataObject(std::move(dataObject));

    String escapedDataObject{};
    JsonUtils::ObjectGetMember(input, "EscapedDataObject", escapedDataObject);
    this->SetEscapedDataObject(std::move(escapedDataObject));
}

size_t MatchmakingPlayerAttributes::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingMatchmakingPlayerAttributes const*> MatchmakingPlayerAttributes::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<MatchmakingPlayerAttributes>(&this->Model());
}

size_t MatchmakingPlayerAttributes::RequiredBufferSize(const PFMatchmakingMatchmakingPlayerAttributes& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.dataObject.stringValue)
    {
    requiredSize += (std::strlen(model.dataObject.stringValue) + 1);
    }
    if (model.escapedDataObject)
    {
        requiredSize += (std::strlen(model.escapedDataObject) + 1);
    }
    return requiredSize;
}

HRESULT MatchmakingPlayerAttributes::Copy(const PFMatchmakingMatchmakingPlayerAttributes& input, PFMatchmakingMatchmakingPlayerAttributes& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.dataObject.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dataObject.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.escapedDataObject); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.escapedDataObject = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue MatchmakingPlayer::ToJson() const
{
    return MatchmakingPlayer::ToJson(this->Model());
}

JsonValue MatchmakingPlayer::ToJson(const PFMatchmakingMatchmakingPlayer& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<MatchmakingPlayerAttributes>(output, "Attributes", input.attributes);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void MatchmakingPlayer::FromJson(const JsonValue& input)
{
    StdExtra::optional<MatchmakingPlayerAttributes> attributes{};
    JsonUtils::ObjectGetMember(input, "Attributes", attributes);
    if (attributes)
    {
        this->SetAttributes(std::move(*attributes));
    }

    EntityKey entity{};
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    this->SetEntity(std::move(entity));
}

size_t MatchmakingPlayer::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingMatchmakingPlayer const*> MatchmakingPlayer::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<MatchmakingPlayer>(&this->Model());
}

size_t MatchmakingPlayer::RequiredBufferSize(const PFMatchmakingMatchmakingPlayer& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.attributes)
    {
        requiredSize += MatchmakingPlayerAttributes::RequiredBufferSize(*model.attributes);
    }
    if (model.entity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.entity);
    }
    return requiredSize;
}

HRESULT MatchmakingPlayer::Copy(const PFMatchmakingMatchmakingPlayer& input, PFMatchmakingMatchmakingPlayer& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<MatchmakingPlayerAttributes>(input.attributes); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.attributes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.entity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entity = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateMatchmakingTicketRequest::ToJson() const
{
    return CreateMatchmakingTicketRequest::ToJson(this->Model());
}

JsonValue CreateMatchmakingTicketRequest::ToJson(const PFMatchmakingCreateMatchmakingTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<MatchmakingPlayer>(output, "Creator", input.creator);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "GiveUpAfterSeconds", input.giveUpAfterSeconds);
    JsonUtils::ObjectAddMemberArray<EntityKey>(output, "MembersToMatchWith", input.membersToMatchWith, input.membersToMatchWithCount);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

void CreateMatchmakingTicketResult::FromJson(const JsonValue& input)
{
    String ticketId{};
    JsonUtils::ObjectGetMember(input, "TicketId", ticketId);
    this->SetTicketId(std::move(ticketId));
}

size_t CreateMatchmakingTicketResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingCreateMatchmakingTicketResult const*> CreateMatchmakingTicketResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateMatchmakingTicketResult>(&this->Model());
}

size_t CreateMatchmakingTicketResult::RequiredBufferSize(const PFMatchmakingCreateMatchmakingTicketResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.ticketId)
    {
        requiredSize += (std::strlen(model.ticketId) + 1);
    }
    return requiredSize;
}

HRESULT CreateMatchmakingTicketResult::Copy(const PFMatchmakingCreateMatchmakingTicketResult& input, PFMatchmakingCreateMatchmakingTicketResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.ticketId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticketId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue MatchmakingPlayerWithTeamAssignment::ToJson() const
{
    return MatchmakingPlayerWithTeamAssignment::ToJson(this->Model());
}

JsonValue MatchmakingPlayerWithTeamAssignment::ToJson(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<MatchmakingPlayerAttributes>(output, "Attributes", input.attributes);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "TeamId", input.teamId);
    return output;
}

void MatchmakingPlayerWithTeamAssignment::FromJson(const JsonValue& input)
{
    StdExtra::optional<MatchmakingPlayerAttributes> attributes{};
    JsonUtils::ObjectGetMember(input, "Attributes", attributes);
    if (attributes)
    {
        this->SetAttributes(std::move(*attributes));
    }

    EntityKey entity{};
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    this->SetEntity(std::move(entity));

    String teamId{};
    JsonUtils::ObjectGetMember(input, "TeamId", teamId);
    this->SetTeamId(std::move(teamId));
}

size_t MatchmakingPlayerWithTeamAssignment::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingMatchmakingPlayerWithTeamAssignment const*> MatchmakingPlayerWithTeamAssignment::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<MatchmakingPlayerWithTeamAssignment>(&this->Model());
}

size_t MatchmakingPlayerWithTeamAssignment::RequiredBufferSize(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.attributes)
    {
        requiredSize += MatchmakingPlayerAttributes::RequiredBufferSize(*model.attributes);
    }
    if (model.entity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.entity);
    }
    if (model.teamId)
    {
        requiredSize += (std::strlen(model.teamId) + 1);
    }
    return requiredSize;
}

HRESULT MatchmakingPlayerWithTeamAssignment::Copy(const PFMatchmakingMatchmakingPlayerWithTeamAssignment& input, PFMatchmakingMatchmakingPlayerWithTeamAssignment& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<MatchmakingPlayerAttributes>(input.attributes); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.attributes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.entity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entity = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.teamId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.teamId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerDetails::ToJson() const
{
    return ServerDetails::ToJson(this->Model());
}

JsonValue ServerDetails::ToJson(const PFMatchmakingServerDetails& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Fqdn", input.fqdn);
    JsonUtils::ObjectAddMember(output, "IPV4Address", input.iPV4Address);
    JsonUtils::ObjectAddMemberArray<Port>(output, "Ports", input.ports, input.portsCount);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    return output;
}

void ServerDetails::FromJson(const JsonValue& input)
{
    String fqdn{};
    JsonUtils::ObjectGetMember(input, "Fqdn", fqdn);
    this->SetFqdn(std::move(fqdn));

    String iPV4Address{};
    JsonUtils::ObjectGetMember(input, "IPV4Address", iPV4Address);
    this->SetIPV4Address(std::move(iPV4Address));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));
}

size_t ServerDetails::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingServerDetails const*> ServerDetails::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerDetails>(&this->Model());
}

size_t ServerDetails::RequiredBufferSize(const PFMatchmakingServerDetails& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.fqdn)
    {
        requiredSize += (std::strlen(model.fqdn) + 1);
    }
    if (model.iPV4Address)
    {
        requiredSize += (std::strlen(model.iPV4Address) + 1);
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    return requiredSize;
}

HRESULT ServerDetails::Copy(const PFMatchmakingServerDetails& input, PFMatchmakingServerDetails& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.fqdn); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fqdn = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.iPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.iPV4Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateServerBackfillTicketRequest::ToJson() const
{
    return CreateServerBackfillTicketRequest::ToJson(this->Model());
}

JsonValue CreateServerBackfillTicketRequest::ToJson(const PFMatchmakingCreateServerBackfillTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "GiveUpAfterSeconds", input.giveUpAfterSeconds);
    JsonUtils::ObjectAddMemberArray<MatchmakingPlayerWithTeamAssignment>(output, "Members", input.members, input.membersCount);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember<ServerDetails>(output, "ServerDetails", input.serverDetails);
    return output;
}

void CreateServerBackfillTicketResult::FromJson(const JsonValue& input)
{
    String ticketId{};
    JsonUtils::ObjectGetMember(input, "TicketId", ticketId);
    this->SetTicketId(std::move(ticketId));
}

size_t CreateServerBackfillTicketResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingCreateServerBackfillTicketResult const*> CreateServerBackfillTicketResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateServerBackfillTicketResult>(&this->Model());
}

size_t CreateServerBackfillTicketResult::RequiredBufferSize(const PFMatchmakingCreateServerBackfillTicketResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.ticketId)
    {
        requiredSize += (std::strlen(model.ticketId) + 1);
    }
    return requiredSize;
}

HRESULT CreateServerBackfillTicketResult::Copy(const PFMatchmakingCreateServerBackfillTicketResult& input, PFMatchmakingCreateServerBackfillTicketResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.ticketId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticketId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateServerMatchmakingTicketRequest::ToJson() const
{
    return CreateServerMatchmakingTicketRequest::ToJson(this->Model());
}

JsonValue CreateServerMatchmakingTicketRequest::ToJson(const PFMatchmakingCreateServerMatchmakingTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "GiveUpAfterSeconds", input.giveUpAfterSeconds);
    JsonUtils::ObjectAddMemberArray<MatchmakingPlayer>(output, "Members", input.members, input.membersCount);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

JsonValue GetMatchRequest::ToJson() const
{
    return GetMatchRequest::ToJson(this->Model());
}

JsonValue GetMatchRequest::ToJson(const PFMatchmakingGetMatchRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EscapeObject", input.escapeObject);
    JsonUtils::ObjectAddMember(output, "MatchId", input.matchId);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember(output, "ReturnMemberAttributes", input.returnMemberAttributes);
    return output;
}

void GetMatchResult::FromJson(const JsonValue& input)
{
    String arrangementString{};
    JsonUtils::ObjectGetMember(input, "ArrangementString", arrangementString);
    this->SetArrangementString(std::move(arrangementString));

    String matchId{};
    JsonUtils::ObjectGetMember(input, "MatchId", matchId);
    this->SetMatchId(std::move(matchId));

    ModelVector<MatchmakingPlayerWithTeamAssignment> members{};
    JsonUtils::ObjectGetMember<MatchmakingPlayerWithTeamAssignment>(input, "Members", members);
    this->SetMembers(std::move(members));

    CStringVector regionPreferences{};
    JsonUtils::ObjectGetMember(input, "RegionPreferences", regionPreferences);
    this->SetRegionPreferences(std::move(regionPreferences));

    StdExtra::optional<ServerDetails> serverDetails{};
    JsonUtils::ObjectGetMember(input, "ServerDetails", serverDetails);
    if (serverDetails)
    {
        this->SetServerDetails(std::move(*serverDetails));
    }
}

size_t GetMatchResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGetMatchResult const*> GetMatchResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMatchResult>(&this->Model());
}

size_t GetMatchResult::RequiredBufferSize(const PFMatchmakingGetMatchResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.arrangementString)
    {
        requiredSize += (std::strlen(model.arrangementString) + 1);
    }
    if (model.matchId)
    {
        requiredSize += (std::strlen(model.matchId) + 1);
    }
    requiredSize += (alignof(PFMatchmakingMatchmakingPlayerWithTeamAssignment*) + sizeof(PFMatchmakingMatchmakingPlayerWithTeamAssignment*) * model.membersCount);
    for (size_t i = 0; i < model.membersCount; ++i)
    {
        requiredSize += MatchmakingPlayerWithTeamAssignment::RequiredBufferSize(*model.members[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.regionPreferencesCount);
    for (size_t i = 0; i < model.regionPreferencesCount; ++i)
    {
        requiredSize += (std::strlen(model.regionPreferences[i]) + 1);
    }
    if (model.serverDetails)
    {
        requiredSize += ServerDetails::RequiredBufferSize(*model.serverDetails);
    }
    return requiredSize;
}

HRESULT GetMatchResult::Copy(const PFMatchmakingGetMatchResult& input, PFMatchmakingGetMatchResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.arrangementString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.arrangementString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.matchId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.matchId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<MatchmakingPlayerWithTeamAssignment>(input.members, input.membersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.members = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.regionPreferences, input.regionPreferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regionPreferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ServerDetails>(input.serverDetails); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverDetails = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetMatchmakingTicketRequest::ToJson() const
{
    return GetMatchmakingTicketRequest::ToJson(this->Model());
}

JsonValue GetMatchmakingTicketRequest::ToJson(const PFMatchmakingGetMatchmakingTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EscapeObject", input.escapeObject);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember(output, "TicketId", input.ticketId);
    return output;
}

void GetMatchmakingTicketResult::FromJson(const JsonValue& input)
{
    String cancellationReasonString{};
    JsonUtils::ObjectGetMember(input, "CancellationReasonString", cancellationReasonString);
    this->SetCancellationReasonString(std::move(cancellationReasonString));

    StdExtra::optional<uint32_t> changeNumber{};
    JsonUtils::ObjectGetMember(input, "ChangeNumber", changeNumber);
    this->SetChangeNumber(std::move(changeNumber));

    JsonUtils::ObjectGetMemberTime(input, "Created", this->m_model.created);

    EntityKey creator{};
    JsonUtils::ObjectGetMember(input, "Creator", creator);
    this->SetCreator(std::move(creator));

    JsonUtils::ObjectGetMember(input, "GiveUpAfterSeconds", this->m_model.giveUpAfterSeconds);

    String matchId{};
    JsonUtils::ObjectGetMember(input, "MatchId", matchId);
    this->SetMatchId(std::move(matchId));

    ModelVector<MatchmakingPlayer> members{};
    JsonUtils::ObjectGetMember<MatchmakingPlayer>(input, "Members", members);
    this->SetMembers(std::move(members));

    ModelVector<EntityKey> membersToMatchWith{};
    JsonUtils::ObjectGetMember<EntityKey>(input, "MembersToMatchWith", membersToMatchWith);
    this->SetMembersToMatchWith(std::move(membersToMatchWith));

    String queueName{};
    JsonUtils::ObjectGetMember(input, "QueueName", queueName);
    this->SetQueueName(std::move(queueName));

    String status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    String ticketId{};
    JsonUtils::ObjectGetMember(input, "TicketId", ticketId);
    this->SetTicketId(std::move(ticketId));
}

size_t GetMatchmakingTicketResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGetMatchmakingTicketResult const*> GetMatchmakingTicketResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMatchmakingTicketResult>(&this->Model());
}

size_t GetMatchmakingTicketResult::RequiredBufferSize(const PFMatchmakingGetMatchmakingTicketResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.cancellationReasonString)
    {
        requiredSize += (std::strlen(model.cancellationReasonString) + 1);
    }
    if (model.changeNumber)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.creator)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.creator);
    }
    if (model.matchId)
    {
        requiredSize += (std::strlen(model.matchId) + 1);
    }
    requiredSize += (alignof(PFMatchmakingMatchmakingPlayer*) + sizeof(PFMatchmakingMatchmakingPlayer*) * model.membersCount);
    for (size_t i = 0; i < model.membersCount; ++i)
    {
        requiredSize += MatchmakingPlayer::RequiredBufferSize(*model.members[i]);
    }
    requiredSize += (alignof(PFEntityKey*) + sizeof(PFEntityKey*) * model.membersToMatchWithCount);
    for (size_t i = 0; i < model.membersToMatchWithCount; ++i)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.membersToMatchWith[i]);
    }
    if (model.queueName)
    {
        requiredSize += (std::strlen(model.queueName) + 1);
    }
    if (model.status)
    {
        requiredSize += (std::strlen(model.status) + 1);
    }
    if (model.ticketId)
    {
        requiredSize += (std::strlen(model.ticketId) + 1);
    }
    return requiredSize;
}

HRESULT GetMatchmakingTicketResult::Copy(const PFMatchmakingGetMatchmakingTicketResult& input, PFMatchmakingGetMatchmakingTicketResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.cancellationReasonString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.cancellationReasonString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.changeNumber); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.changeNumber = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.creator); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creator = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.matchId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.matchId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<MatchmakingPlayer>(input.members, input.membersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.members = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<EntityKey>(input.membersToMatchWith, input.membersToMatchWithCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.membersToMatchWith = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.queueName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.queueName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.ticketId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticketId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetQueueStatisticsRequest::ToJson() const
{
    return GetQueueStatisticsRequest::ToJson(this->Model());
}

JsonValue GetQueueStatisticsRequest::ToJson(const PFMatchmakingGetQueueStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

void Statistics::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Average", this->m_model.average);

    JsonUtils::ObjectGetMember(input, "Percentile50", this->m_model.percentile50);

    JsonUtils::ObjectGetMember(input, "Percentile90", this->m_model.percentile90);

    JsonUtils::ObjectGetMember(input, "Percentile99", this->m_model.percentile99);
}

size_t Statistics::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingStatistics const*> Statistics::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Statistics>(&this->Model());
}

size_t Statistics::RequiredBufferSize(const PFMatchmakingStatistics& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT Statistics::Copy(const PFMatchmakingStatistics& input, PFMatchmakingStatistics& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

void GetQueueStatisticsResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<uint32_t> numberOfPlayersMatching{};
    JsonUtils::ObjectGetMember(input, "NumberOfPlayersMatching", numberOfPlayersMatching);
    this->SetNumberOfPlayersMatching(std::move(numberOfPlayersMatching));

    StdExtra::optional<Statistics> timeToMatchStatisticsInSeconds{};
    JsonUtils::ObjectGetMember(input, "TimeToMatchStatisticsInSeconds", timeToMatchStatisticsInSeconds);
    if (timeToMatchStatisticsInSeconds)
    {
        this->SetTimeToMatchStatisticsInSeconds(std::move(*timeToMatchStatisticsInSeconds));
    }
}

size_t GetQueueStatisticsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGetQueueStatisticsResult const*> GetQueueStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetQueueStatisticsResult>(&this->Model());
}

size_t GetQueueStatisticsResult::RequiredBufferSize(const PFMatchmakingGetQueueStatisticsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.numberOfPlayersMatching)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.timeToMatchStatisticsInSeconds)
    {
        requiredSize += Statistics::RequiredBufferSize(*model.timeToMatchStatisticsInSeconds);
    }
    return requiredSize;
}

HRESULT GetQueueStatisticsResult::Copy(const PFMatchmakingGetQueueStatisticsResult& input, PFMatchmakingGetQueueStatisticsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.numberOfPlayersMatching); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.numberOfPlayersMatching = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<Statistics>(input.timeToMatchStatisticsInSeconds); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.timeToMatchStatisticsInSeconds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetServerBackfillTicketRequest::ToJson() const
{
    return GetServerBackfillTicketRequest::ToJson(this->Model());
}

JsonValue GetServerBackfillTicketRequest::ToJson(const PFMatchmakingGetServerBackfillTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EscapeObject", input.escapeObject);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember(output, "TicketId", input.ticketId);
    return output;
}

void GetServerBackfillTicketResult::FromJson(const JsonValue& input)
{
    String cancellationReasonString{};
    JsonUtils::ObjectGetMember(input, "CancellationReasonString", cancellationReasonString);
    this->SetCancellationReasonString(std::move(cancellationReasonString));

    JsonUtils::ObjectGetMemberTime(input, "Created", this->m_model.created);

    JsonUtils::ObjectGetMember(input, "GiveUpAfterSeconds", this->m_model.giveUpAfterSeconds);

    String matchId{};
    JsonUtils::ObjectGetMember(input, "MatchId", matchId);
    this->SetMatchId(std::move(matchId));

    ModelVector<MatchmakingPlayerWithTeamAssignment> members{};
    JsonUtils::ObjectGetMember<MatchmakingPlayerWithTeamAssignment>(input, "Members", members);
    this->SetMembers(std::move(members));

    String queueName{};
    JsonUtils::ObjectGetMember(input, "QueueName", queueName);
    this->SetQueueName(std::move(queueName));

    ServerDetails serverDetails{};
    JsonUtils::ObjectGetMember(input, "ServerDetails", serverDetails);
    this->SetServerDetails(std::move(serverDetails));

    String status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    String ticketId{};
    JsonUtils::ObjectGetMember(input, "TicketId", ticketId);
    this->SetTicketId(std::move(ticketId));
}

size_t GetServerBackfillTicketResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingGetServerBackfillTicketResult const*> GetServerBackfillTicketResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetServerBackfillTicketResult>(&this->Model());
}

size_t GetServerBackfillTicketResult::RequiredBufferSize(const PFMatchmakingGetServerBackfillTicketResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.cancellationReasonString)
    {
        requiredSize += (std::strlen(model.cancellationReasonString) + 1);
    }
    if (model.matchId)
    {
        requiredSize += (std::strlen(model.matchId) + 1);
    }
    requiredSize += (alignof(PFMatchmakingMatchmakingPlayerWithTeamAssignment*) + sizeof(PFMatchmakingMatchmakingPlayerWithTeamAssignment*) * model.membersCount);
    for (size_t i = 0; i < model.membersCount; ++i)
    {
        requiredSize += MatchmakingPlayerWithTeamAssignment::RequiredBufferSize(*model.members[i]);
    }
    if (model.queueName)
    {
        requiredSize += (std::strlen(model.queueName) + 1);
    }
    if (model.serverDetails)
    {
        requiredSize += ServerDetails::RequiredBufferSize(*model.serverDetails);
    }
    if (model.status)
    {
        requiredSize += (std::strlen(model.status) + 1);
    }
    if (model.ticketId)
    {
        requiredSize += (std::strlen(model.ticketId) + 1);
    }
    return requiredSize;
}

HRESULT GetServerBackfillTicketResult::Copy(const PFMatchmakingGetServerBackfillTicketResult& input, PFMatchmakingGetServerBackfillTicketResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.cancellationReasonString); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.cancellationReasonString = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.matchId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.matchId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<MatchmakingPlayerWithTeamAssignment>(input.members, input.membersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.members = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.queueName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.queueName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ServerDetails>(input.serverDetails); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverDetails = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.ticketId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticketId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue JoinMatchmakingTicketRequest::ToJson() const
{
    return JoinMatchmakingTicketRequest::ToJson(this->Model());
}

JsonValue JoinMatchmakingTicketRequest::ToJson(const PFMatchmakingJoinMatchmakingTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<MatchmakingPlayer>(output, "Member", input.member);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    JsonUtils::ObjectAddMember(output, "TicketId", input.ticketId);
    return output;
}

JsonValue ListMatchmakingTicketsForPlayerRequest::ToJson() const
{
    return ListMatchmakingTicketsForPlayerRequest::ToJson(this->Model());
}

JsonValue ListMatchmakingTicketsForPlayerRequest::ToJson(const PFMatchmakingListMatchmakingTicketsForPlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

void ListMatchmakingTicketsForPlayerResult::FromJson(const JsonValue& input)
{
    CStringVector ticketIds{};
    JsonUtils::ObjectGetMember(input, "TicketIds", ticketIds);
    this->SetTicketIds(std::move(ticketIds));
}

size_t ListMatchmakingTicketsForPlayerResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingListMatchmakingTicketsForPlayerResult const*> ListMatchmakingTicketsForPlayerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListMatchmakingTicketsForPlayerResult>(&this->Model());
}

size_t ListMatchmakingTicketsForPlayerResult::RequiredBufferSize(const PFMatchmakingListMatchmakingTicketsForPlayerResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.ticketIdsCount);
    for (size_t i = 0; i < model.ticketIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.ticketIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT ListMatchmakingTicketsForPlayerResult::Copy(const PFMatchmakingListMatchmakingTicketsForPlayerResult& input, PFMatchmakingListMatchmakingTicketsForPlayerResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.ticketIds, input.ticketIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticketIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListServerBackfillTicketsForPlayerRequest::ToJson() const
{
    return ListServerBackfillTicketsForPlayerRequest::ToJson(this->Model());
}

JsonValue ListServerBackfillTicketsForPlayerRequest::ToJson(const PFMatchmakingListServerBackfillTicketsForPlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "QueueName", input.queueName);
    return output;
}

void ListServerBackfillTicketsForPlayerResult::FromJson(const JsonValue& input)
{
    CStringVector ticketIds{};
    JsonUtils::ObjectGetMember(input, "TicketIds", ticketIds);
    this->SetTicketIds(std::move(ticketIds));
}

size_t ListServerBackfillTicketsForPlayerResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMatchmakingListServerBackfillTicketsForPlayerResult const*> ListServerBackfillTicketsForPlayerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListServerBackfillTicketsForPlayerResult>(&this->Model());
}

size_t ListServerBackfillTicketsForPlayerResult::RequiredBufferSize(const PFMatchmakingListServerBackfillTicketsForPlayerResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.ticketIdsCount);
    for (size_t i = 0; i < model.ticketIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.ticketIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT ListServerBackfillTicketsForPlayerResult::Copy(const PFMatchmakingListServerBackfillTicketsForPlayerResult& input, PFMatchmakingListServerBackfillTicketsForPlayerResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.ticketIds, input.ticketIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ticketIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Matchmaking
} // namespace PlayFab
