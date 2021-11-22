#pragma once

#include "CloudScriptDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace CloudScript
{

class CloudScriptAPI
{
public:
    CloudScriptAPI() = delete;
    CloudScriptAPI(const CloudScriptAPI& source) = delete;
    CloudScriptAPI& operator=(const CloudScriptAPI& source) = delete;
    ~CloudScriptAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<GetCloudScriptRevisionResult> AdminGetCloudScriptRevision(SharedPtr<GlobalState const> state, const GetCloudScriptRevisionRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCloudScriptVersionsResult> AdminGetCloudScriptVersions(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<void> AdminSetPublishedRevision(SharedPtr<GlobalState const> state, const SetPublishedRevisionRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateCloudScriptResult> AdminUpdateCloudScript(SharedPtr<GlobalState const> state, const UpdateCloudScriptRequest& request, const TaskQueue& queue);
    static AsyncOp<ExecuteCloudScriptResult> ClientExecuteCloudScript(SharedPtr<TitlePlayer> entity, const ExecuteCloudScriptRequest& request, const TaskQueue& queue);
    static AsyncOp<ExecuteCloudScriptResult> ServerExecuteCloudScript(SharedPtr<GlobalState const> state, const ExecuteCloudScriptServerRequest& request, const TaskQueue& queue);
    static AsyncOp<ExecuteCloudScriptResult> ExecuteEntityCloudScript(SharedPtr<Entity> entity, const ExecuteEntityCloudScriptRequest& request, const TaskQueue& queue);
    static AsyncOp<ExecuteFunctionResult> ExecuteFunction(SharedPtr<Entity> entity, const ExecuteFunctionRequest& request, const TaskQueue& queue);
    static AsyncOp<GetFunctionResult> GetFunction(SharedPtr<Entity> entity, const GetFunctionRequest& request, const TaskQueue& queue);
    static AsyncOp<ListFunctionsResult> ListFunctions(SharedPtr<Entity> entity, const ListFunctionsRequest& request, const TaskQueue& queue);
    static AsyncOp<ListHttpFunctionsResult> ListHttpFunctions(SharedPtr<Entity> entity, const ListFunctionsRequest& request, const TaskQueue& queue);
    static AsyncOp<ListQueuedFunctionsResult> ListQueuedFunctions(SharedPtr<Entity> entity, const ListFunctionsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PostFunctionResultForEntityTriggeredAction(SharedPtr<Entity> entity, const PostFunctionResultForEntityTriggeredActionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PostFunctionResultForFunctionExecution(SharedPtr<Entity> entity, const PostFunctionResultForFunctionExecutionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PostFunctionResultForPlayerTriggeredAction(SharedPtr<Entity> entity, const PostFunctionResultForPlayerTriggeredActionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PostFunctionResultForScheduledTask(SharedPtr<Entity> entity, const PostFunctionResultForScheduledTaskRequest& request, const TaskQueue& queue);
    static AsyncOp<void> RegisterHttpFunction(SharedPtr<Entity> entity, const RegisterHttpFunctionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> RegisterQueuedFunction(SharedPtr<Entity> entity, const RegisterQueuedFunctionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UnregisterFunction(SharedPtr<Entity> entity, const UnregisterFunctionRequest& request, const TaskQueue& queue);
};

} // namespace CloudScript
} // namespace PlayFab
