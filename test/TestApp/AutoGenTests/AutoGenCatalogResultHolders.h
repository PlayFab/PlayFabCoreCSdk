#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreateDraftItemResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateDraftItemResponseHolder>
{
    CreateDraftItemResponseHolder() = default;
    CreateDraftItemResponseHolder(const CreateDraftItemResponseHolder&) = delete;
    CreateDraftItemResponseHolder(CreateDraftItemResponseHolder&&) = default;
    CreateDraftItemResponseHolder& operator=(const CreateDraftItemResponseHolder&) = delete;
    CreateDraftItemResponseHolder& operator=(CreateDraftItemResponseHolder&&) = default;
    ~CreateDraftItemResponseHolder() = default;

    PFCatalogCreateDraftItemResponse* result{ nullptr };
};

struct CreateUploadUrlsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateUploadUrlsResponseHolder>
{
    CreateUploadUrlsResponseHolder() = default;
    CreateUploadUrlsResponseHolder(const CreateUploadUrlsResponseHolder&) = delete;
    CreateUploadUrlsResponseHolder(CreateUploadUrlsResponseHolder&&) = default;
    CreateUploadUrlsResponseHolder& operator=(const CreateUploadUrlsResponseHolder&) = delete;
    CreateUploadUrlsResponseHolder& operator=(CreateUploadUrlsResponseHolder&&) = default;
    ~CreateUploadUrlsResponseHolder() = default;

    PFCatalogCreateUploadUrlsResponse* result{ nullptr };
};

struct GetCatalogConfigResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetCatalogConfigResponseHolder>
{
    GetCatalogConfigResponseHolder() = default;
    GetCatalogConfigResponseHolder(const GetCatalogConfigResponseHolder&) = delete;
    GetCatalogConfigResponseHolder(GetCatalogConfigResponseHolder&&) = default;
    GetCatalogConfigResponseHolder& operator=(const GetCatalogConfigResponseHolder&) = delete;
    GetCatalogConfigResponseHolder& operator=(GetCatalogConfigResponseHolder&&) = default;
    ~GetCatalogConfigResponseHolder() = default;

    PFCatalogGetCatalogConfigResponse* result{ nullptr };
};

struct GetDraftItemResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetDraftItemResponseHolder>
{
    GetDraftItemResponseHolder() = default;
    GetDraftItemResponseHolder(const GetDraftItemResponseHolder&) = delete;
    GetDraftItemResponseHolder(GetDraftItemResponseHolder&&) = default;
    GetDraftItemResponseHolder& operator=(const GetDraftItemResponseHolder&) = delete;
    GetDraftItemResponseHolder& operator=(GetDraftItemResponseHolder&&) = default;
    ~GetDraftItemResponseHolder() = default;

    PFCatalogGetDraftItemResponse* result{ nullptr };
};

struct GetDraftItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetDraftItemsResponseHolder>
{
    GetDraftItemsResponseHolder() = default;
    GetDraftItemsResponseHolder(const GetDraftItemsResponseHolder&) = delete;
    GetDraftItemsResponseHolder(GetDraftItemsResponseHolder&&) = default;
    GetDraftItemsResponseHolder& operator=(const GetDraftItemsResponseHolder&) = delete;
    GetDraftItemsResponseHolder& operator=(GetDraftItemsResponseHolder&&) = default;
    ~GetDraftItemsResponseHolder() = default;

    PFCatalogGetDraftItemsResponse* result{ nullptr };
};

struct GetEntityDraftItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetEntityDraftItemsResponseHolder>
{
    GetEntityDraftItemsResponseHolder() = default;
    GetEntityDraftItemsResponseHolder(const GetEntityDraftItemsResponseHolder&) = delete;
    GetEntityDraftItemsResponseHolder(GetEntityDraftItemsResponseHolder&&) = default;
    GetEntityDraftItemsResponseHolder& operator=(const GetEntityDraftItemsResponseHolder&) = delete;
    GetEntityDraftItemsResponseHolder& operator=(GetEntityDraftItemsResponseHolder&&) = default;
    ~GetEntityDraftItemsResponseHolder() = default;

    PFCatalogGetEntityDraftItemsResponse* result{ nullptr };
};

struct GetEntityItemReviewResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetEntityItemReviewResponseHolder>
{
    GetEntityItemReviewResponseHolder() = default;
    GetEntityItemReviewResponseHolder(const GetEntityItemReviewResponseHolder&) = delete;
    GetEntityItemReviewResponseHolder(GetEntityItemReviewResponseHolder&&) = default;
    GetEntityItemReviewResponseHolder& operator=(const GetEntityItemReviewResponseHolder&) = delete;
    GetEntityItemReviewResponseHolder& operator=(GetEntityItemReviewResponseHolder&&) = default;
    ~GetEntityItemReviewResponseHolder() = default;

    PFCatalogGetEntityItemReviewResponse* result{ nullptr };
};

struct GetItemResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetItemResponseHolder>
{
    GetItemResponseHolder() = default;
    GetItemResponseHolder(const GetItemResponseHolder&) = delete;
    GetItemResponseHolder(GetItemResponseHolder&&) = default;
    GetItemResponseHolder& operator=(const GetItemResponseHolder&) = delete;
    GetItemResponseHolder& operator=(GetItemResponseHolder&&) = default;
    ~GetItemResponseHolder() = default;

    PFCatalogGetItemResponse* result{ nullptr };
};

struct GetItemModerationStateResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetItemModerationStateResponseHolder>
{
    GetItemModerationStateResponseHolder() = default;
    GetItemModerationStateResponseHolder(const GetItemModerationStateResponseHolder&) = delete;
    GetItemModerationStateResponseHolder(GetItemModerationStateResponseHolder&&) = default;
    GetItemModerationStateResponseHolder& operator=(const GetItemModerationStateResponseHolder&) = delete;
    GetItemModerationStateResponseHolder& operator=(GetItemModerationStateResponseHolder&&) = default;
    ~GetItemModerationStateResponseHolder() = default;

    PFCatalogGetItemModerationStateResponse* result{ nullptr };
};

struct GetItemPublishStatusResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetItemPublishStatusResponseHolder>
{
    GetItemPublishStatusResponseHolder() = default;
    GetItemPublishStatusResponseHolder(const GetItemPublishStatusResponseHolder&) = delete;
    GetItemPublishStatusResponseHolder(GetItemPublishStatusResponseHolder&&) = default;
    GetItemPublishStatusResponseHolder& operator=(const GetItemPublishStatusResponseHolder&) = delete;
    GetItemPublishStatusResponseHolder& operator=(GetItemPublishStatusResponseHolder&&) = default;
    ~GetItemPublishStatusResponseHolder() = default;

    PFCatalogGetItemPublishStatusResponse* result{ nullptr };
};

struct GetItemReviewsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetItemReviewsResponseHolder>
{
    GetItemReviewsResponseHolder() = default;
    GetItemReviewsResponseHolder(const GetItemReviewsResponseHolder&) = delete;
    GetItemReviewsResponseHolder(GetItemReviewsResponseHolder&&) = default;
    GetItemReviewsResponseHolder& operator=(const GetItemReviewsResponseHolder&) = delete;
    GetItemReviewsResponseHolder& operator=(GetItemReviewsResponseHolder&&) = default;
    ~GetItemReviewsResponseHolder() = default;

    PFCatalogGetItemReviewsResponse* result{ nullptr };
};

struct GetItemReviewSummaryResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetItemReviewSummaryResponseHolder>
{
    GetItemReviewSummaryResponseHolder() = default;
    GetItemReviewSummaryResponseHolder(const GetItemReviewSummaryResponseHolder&) = delete;
    GetItemReviewSummaryResponseHolder(GetItemReviewSummaryResponseHolder&&) = default;
    GetItemReviewSummaryResponseHolder& operator=(const GetItemReviewSummaryResponseHolder&) = delete;
    GetItemReviewSummaryResponseHolder& operator=(GetItemReviewSummaryResponseHolder&&) = default;
    ~GetItemReviewSummaryResponseHolder() = default;

    PFCatalogGetItemReviewSummaryResponse* result{ nullptr };
};

struct GetItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetItemsResponseHolder>
{
    GetItemsResponseHolder() = default;
    GetItemsResponseHolder(const GetItemsResponseHolder&) = delete;
    GetItemsResponseHolder(GetItemsResponseHolder&&) = default;
    GetItemsResponseHolder& operator=(const GetItemsResponseHolder&) = delete;
    GetItemsResponseHolder& operator=(GetItemsResponseHolder&&) = default;
    ~GetItemsResponseHolder() = default;

    PFCatalogGetItemsResponse* result{ nullptr };
};

struct SearchItemsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<SearchItemsResponseHolder>
{
    SearchItemsResponseHolder() = default;
    SearchItemsResponseHolder(const SearchItemsResponseHolder&) = delete;
    SearchItemsResponseHolder(SearchItemsResponseHolder&&) = default;
    SearchItemsResponseHolder& operator=(const SearchItemsResponseHolder&) = delete;
    SearchItemsResponseHolder& operator=(SearchItemsResponseHolder&&) = default;
    ~SearchItemsResponseHolder() = default;

    PFCatalogSearchItemsResponse* result{ nullptr };
};

struct UpdateDraftItemResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateDraftItemResponseHolder>
{
    UpdateDraftItemResponseHolder() = default;
    UpdateDraftItemResponseHolder(const UpdateDraftItemResponseHolder&) = delete;
    UpdateDraftItemResponseHolder(UpdateDraftItemResponseHolder&&) = default;
    UpdateDraftItemResponseHolder& operator=(const UpdateDraftItemResponseHolder&) = delete;
    UpdateDraftItemResponseHolder& operator=(UpdateDraftItemResponseHolder&&) = default;
    ~UpdateDraftItemResponseHolder() = default;

    PFCatalogUpdateDraftItemResponse* result{ nullptr };
};


}
