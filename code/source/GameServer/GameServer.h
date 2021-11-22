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
    static AsyncOp<AddServerBuildResult> AdminAddServerBuild(SharedPtr<GlobalState const> state, const AddServerBuildRequest& request, const TaskQueue& queue);
    static AsyncOp<GetServerBuildInfoResult> AdminGetServerBuildInfo(SharedPtr<GlobalState const> state, const GetServerBuildInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<GetServerBuildUploadURLResult> AdminGetServerBuildUploadUrl(SharedPtr<GlobalState const> state, const GetServerBuildUploadURLRequest& request, const TaskQueue& queue);
    static AsyncOp<ListBuildsResult> AdminListServerBuilds(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<ModifyServerBuildResult> AdminModifyServerBuild(SharedPtr<GlobalState const> state, const ModifyServerBuildRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminRemoveServerBuild(SharedPtr<GlobalState const> state, const RemoveServerBuildRequest& request, const TaskQueue& queue);
};

} // namespace GameServer
} // namespace PlayFab
