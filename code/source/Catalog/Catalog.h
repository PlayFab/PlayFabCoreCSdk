#pragma once

#include "CatalogDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Catalog
{

class CatalogAPI
{
public:
    CatalogAPI() = delete;
    CatalogAPI(const CatalogAPI& source) = delete;
    CatalogAPI& operator=(const CatalogAPI& source) = delete;
    ~CatalogAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<CreateDraftItemResponse> CreateDraftItem(SharedPtr<Entity> entity, const CreateDraftItemRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateUploadUrlsResponse> CreateUploadUrls(SharedPtr<Entity> entity, const CreateUploadUrlsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteEntityItemReviews(SharedPtr<Entity> entity, const DeleteEntityItemReviewsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteItem(SharedPtr<Entity> entity, const DeleteItemRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCatalogConfigResponse> GetCatalogConfig(SharedPtr<Entity> entity, const GetCatalogConfigRequest& request, const TaskQueue& queue);
    static AsyncOp<GetDraftItemResponse> GetDraftItem(SharedPtr<Entity> entity, const GetDraftItemRequest& request, const TaskQueue& queue);
    static AsyncOp<GetDraftItemsResponse> GetDraftItems(SharedPtr<Entity> entity, const GetDraftItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetEntityDraftItemsResponse> GetEntityDraftItems(SharedPtr<Entity> entity, const GetEntityDraftItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetEntityItemReviewResponse> GetEntityItemReview(SharedPtr<Entity> entity, const GetEntityItemReviewRequest& request, const TaskQueue& queue);
    static AsyncOp<GetItemResponse> GetItem(SharedPtr<Entity> entity, const GetItemRequest& request, const TaskQueue& queue);
    static AsyncOp<GetItemModerationStateResponse> GetItemModerationState(SharedPtr<Entity> entity, const GetItemModerationStateRequest& request, const TaskQueue& queue);
    static AsyncOp<GetItemPublishStatusResponse> GetItemPublishStatus(SharedPtr<Entity> entity, const GetItemPublishStatusRequest& request, const TaskQueue& queue);
    static AsyncOp<GetItemReviewsResponse> GetItemReviews(SharedPtr<Entity> entity, const GetItemReviewsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetItemReviewSummaryResponse> GetItemReviewSummary(SharedPtr<Entity> entity, const GetItemReviewSummaryRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PublishDraftItem(SharedPtr<Entity> entity, const PublishDraftItemRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ReportItem(SharedPtr<Entity> entity, const ReportItemRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ReportItemReview(SharedPtr<Entity> entity, const ReportItemReviewRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ReviewItem(SharedPtr<Entity> entity, const ReviewItemRequest& request, const TaskQueue& queue);
    static AsyncOp<SearchItemsResponse> SearchItems(SharedPtr<Entity> entity, const SearchItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> SetItemModerationState(SharedPtr<Entity> entity, const SetItemModerationStateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> SubmitItemReviewVote(SharedPtr<Entity> entity, const SubmitItemReviewVoteRequest& request, const TaskQueue& queue);
    static AsyncOp<void> TakedownItemReviews(SharedPtr<Entity> entity, const TakedownItemReviewsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateCatalogConfig(SharedPtr<Entity> entity, const UpdateCatalogConfigRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateDraftItemResponse> UpdateDraftItem(SharedPtr<Entity> entity, const UpdateDraftItemRequest& request, const TaskQueue& queue);
};

} // namespace Catalog
} // namespace PlayFab
