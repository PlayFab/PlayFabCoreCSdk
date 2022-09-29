#pragma once

#include "GameServerDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace GameServer
{

class GameServerAPI
{
public:
    GameServerAPI() = delete;
    GameServerAPI(const GameServerAPI& source) = delete;
    GameServerAPI& operator=(const GameServerAPI& source) = delete;
    ~GameServerAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<ModifyServerBuildResult> AdminModifyServerBuild(SharedPtr<GlobalState const> state, const ModifyServerBuildRequest& request, const TaskQueue& queue);
};

} // namespace GameServer
} // namespace PlayFab
