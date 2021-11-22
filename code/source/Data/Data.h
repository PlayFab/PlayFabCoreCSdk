#pragma once

#include "DataDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Data
{

class DataAPI
{
public:
    DataAPI() = delete;
    DataAPI(const DataAPI& source) = delete;
    DataAPI& operator=(const DataAPI& source) = delete;
    ~DataAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<AbortFileUploadsResponse> AbortFileUploads(SharedPtr<Entity> entity, const AbortFileUploadsRequest& request, const TaskQueue& queue);
    static AsyncOp<DeleteFilesResponse> DeleteFiles(SharedPtr<Entity> entity, const DeleteFilesRequest& request, const TaskQueue& queue);
    static AsyncOp<FinalizeFileUploadsResponse> FinalizeFileUploads(SharedPtr<Entity> entity, const FinalizeFileUploadsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetFilesResponse> GetFiles(SharedPtr<Entity> entity, const GetFilesRequest& request, const TaskQueue& queue);
    static AsyncOp<GetObjectsResponse> GetObjects(SharedPtr<Entity> entity, const GetObjectsRequest& request, const TaskQueue& queue);
    static AsyncOp<InitiateFileUploadsResponse> InitiateFileUploads(SharedPtr<Entity> entity, const InitiateFileUploadsRequest& request, const TaskQueue& queue);
    static AsyncOp<SetObjectsResponse> SetObjects(SharedPtr<Entity> entity, const SetObjectsRequest& request, const TaskQueue& queue);
};

} // namespace Data
} // namespace PlayFab
