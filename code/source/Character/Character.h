#pragma once

#include "CharacterDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Character
{

class CharacterAPI
{
public:
    CharacterAPI() = delete;
    CharacterAPI(const CharacterAPI& source) = delete;
    CharacterAPI& operator=(const CharacterAPI& source) = delete;
    ~CharacterAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AdminResetCharacterStatistics(SharedPtr<GlobalState const> state, const ResetCharacterStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<ListUsersCharactersResult> ClientGetAllUsersCharacters(SharedPtr<TitlePlayer> entity, const ListUsersCharactersRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetCharacterDataResult> ClientGetCharacterData(SharedPtr<TitlePlayer> entity, const GetCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCharacterLeaderboardResult> ClientGetCharacterLeaderboard(SharedPtr<TitlePlayer> entity, const GetCharacterLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetCharacterDataResult> ClientGetCharacterReadOnlyData(SharedPtr<TitlePlayer> entity, const GetCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetCharacterStatisticsResult> ClientGetCharacterStatistics(SharedPtr<TitlePlayer> entity, const ClientGetCharacterStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardAroundCharacterResult> ClientGetLeaderboardAroundCharacter(SharedPtr<TitlePlayer> entity, const ClientGetLeaderboardAroundCharacterRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardForUsersCharactersResult> ClientGetLeaderboardForUserCharacters(SharedPtr<TitlePlayer> entity, const ClientGetLeaderboardForUsersCharactersRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGrantCharacterToUserResult> ClientGrantCharacterToUser(SharedPtr<TitlePlayer> entity, const ClientGrantCharacterToUserRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateCharacterDataResult> ClientUpdateCharacterData(SharedPtr<TitlePlayer> entity, const ClientUpdateCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUpdateCharacterStatistics(SharedPtr<TitlePlayer> entity, const ClientUpdateCharacterStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerDeleteCharacterFromUser(SharedPtr<GlobalState const> state, const DeleteCharacterFromUserRequest& request, const TaskQueue& queue);
    static AsyncOp<ListUsersCharactersResult> ServerGetAllUsersCharacters(SharedPtr<GlobalState const> state, const ListUsersCharactersRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetCharacterDataResult> ServerGetCharacterData(SharedPtr<GlobalState const> state, const GetCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetCharacterDataResult> ServerGetCharacterInternalData(SharedPtr<GlobalState const> state, const GetCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCharacterLeaderboardResult> ServerGetCharacterLeaderboard(SharedPtr<GlobalState const> state, const GetCharacterLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetCharacterDataResult> ServerGetCharacterReadOnlyData(SharedPtr<GlobalState const> state, const GetCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetCharacterStatisticsResult> ServerGetCharacterStatistics(SharedPtr<GlobalState const> state, const ServerGetCharacterStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardAroundCharacterResult> ServerGetLeaderboardAroundCharacter(SharedPtr<GlobalState const> state, const ServerGetLeaderboardAroundCharacterRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardForUsersCharactersResult> ServerGetLeaderboardForUserCharacters(SharedPtr<GlobalState const> state, const ServerGetLeaderboardForUsersCharactersRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGrantCharacterToUserResult> ServerGrantCharacterToUser(SharedPtr<GlobalState const> state, const ServerGrantCharacterToUserRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateCharacterDataResult> ServerUpdateCharacterData(SharedPtr<GlobalState const> state, const ServerUpdateCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateCharacterDataResult> ServerUpdateCharacterInternalData(SharedPtr<GlobalState const> state, const ServerUpdateCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateCharacterDataResult> ServerUpdateCharacterReadOnlyData(SharedPtr<GlobalState const> state, const ServerUpdateCharacterDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUpdateCharacterStatistics(SharedPtr<GlobalState const> state, const ServerUpdateCharacterStatisticsRequest& request, const TaskQueue& queue);
};

} // namespace Character
} // namespace PlayFab
