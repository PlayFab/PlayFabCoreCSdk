#pragma once

#include "ContentDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Content
{

class ContentAPI
{
public:
    ContentAPI() = delete;
    ContentAPI(const ContentAPI& source) = delete;
    ContentAPI& operator=(const ContentAPI& source) = delete;
    ~ContentAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AdminDeleteContent(SharedPtr<GlobalState const> state, const DeleteContentRequest& request, const TaskQueue& queue);
    static AsyncOp<GetContentListResult> AdminGetContentList(SharedPtr<GlobalState const> state, const GetContentListRequest& request, const TaskQueue& queue);
    static AsyncOp<GetContentUploadUrlResult> AdminGetContentUploadUrl(SharedPtr<GlobalState const> state, const GetContentUploadUrlRequest& request, const TaskQueue& queue);
    static AsyncOp<GetContentDownloadUrlResult> ClientGetContentDownloadUrl(SharedPtr<TitlePlayer> entity, const GetContentDownloadUrlRequest& request, const TaskQueue& queue);
    static AsyncOp<GetContentDownloadUrlResult> ServerGetContentDownloadUrl(SharedPtr<GlobalState const> state, const GetContentDownloadUrlRequest& request, const TaskQueue& queue);
};

} // namespace Content
} // namespace PlayFab
