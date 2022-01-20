#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFCatalogDataModelWrappers.h>
#include "AutoGenCatalogResultHolders.h"

namespace PlayFabUnit
{

class AutoGenCatalogTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestCatalogCreateDraftItem(TestContext& testContext);

    void TestCatalogCreateUploadUrls(TestContext& testContext);

    void TestCatalogDeleteEntityItemReviews(TestContext& testContext);

    void TestCatalogDeleteItem(TestContext& testContext);

    void TestCatalogGetCatalogConfig(TestContext& testContext);

    void TestCatalogGetDraftItem(TestContext& testContext);

    void TestCatalogGetDraftItems(TestContext& testContext);

    void TestCatalogGetEntityDraftItems(TestContext& testContext);

    void TestCatalogGetEntityItemReview(TestContext& testContext);

    void TestCatalogGetItem(TestContext& testContext);

    void TestCatalogGetItemModerationState(TestContext& testContext);

    void TestCatalogGetItemPublishStatus(TestContext& testContext);

    void TestCatalogGetItemReviews(TestContext& testContext);

    void TestCatalogGetItemReviewSummary(TestContext& testContext);

    void TestCatalogGetItems(TestContext& testContext);

    void TestCatalogPublishDraftItem(TestContext& testContext);

    void TestCatalogReportItem(TestContext& testContext);

    void TestCatalogReportItemReview(TestContext& testContext);

    void TestCatalogReviewItem(TestContext& testContext);

    void TestCatalogSearchItems(TestContext& testContext);

    void TestCatalogSetItemModerationState(TestContext& testContext);

    void TestCatalogSubmitItemReviewVote(TestContext& testContext);

    void TestCatalogTakedownItemReviews(TestContext& testContext);

    void TestCatalogUpdateCatalogConfig(TestContext& testContext);

    void TestCatalogUpdateDraftItem(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreateDraftItemRequest(PFCatalogCreateDraftItemRequest const* request, const char* testName);
    static HRESULT LogCreateDraftItemResponse(PFCatalogCreateDraftItemResponse const* result);
    static void LogCreateUploadUrlsRequest(PFCatalogCreateUploadUrlsRequest const* request, const char* testName);
    static HRESULT LogCreateUploadUrlsResponse(PFCatalogCreateUploadUrlsResponse const* result);
    static void LogDeleteEntityItemReviewsRequest(PFCatalogDeleteEntityItemReviewsRequest const* request, const char* testName);
    static void LogDeleteItemRequest(PFCatalogDeleteItemRequest const* request, const char* testName);
    static void LogGetCatalogConfigRequest(PFCatalogGetCatalogConfigRequest const* request, const char* testName);
    static HRESULT LogGetCatalogConfigResponse(PFCatalogGetCatalogConfigResponse const* result);
    static void LogGetDraftItemRequest(PFCatalogGetDraftItemRequest const* request, const char* testName);
    static HRESULT LogGetDraftItemResponse(PFCatalogGetDraftItemResponse const* result);
    static void LogGetDraftItemsRequest(PFCatalogGetDraftItemsRequest const* request, const char* testName);
    static HRESULT LogGetDraftItemsResponse(PFCatalogGetDraftItemsResponse const* result);
    static void LogGetEntityDraftItemsRequest(PFCatalogGetEntityDraftItemsRequest const* request, const char* testName);
    static HRESULT LogGetEntityDraftItemsResponse(PFCatalogGetEntityDraftItemsResponse const* result);
    static void LogGetEntityItemReviewRequest(PFCatalogGetEntityItemReviewRequest const* request, const char* testName);
    static HRESULT LogGetEntityItemReviewResponse(PFCatalogGetEntityItemReviewResponse const* result);
    static void LogGetItemRequest(PFCatalogGetItemRequest const* request, const char* testName);
    static HRESULT LogGetItemResponse(PFCatalogGetItemResponse const* result);
    static void LogGetItemModerationStateRequest(PFCatalogGetItemModerationStateRequest const* request, const char* testName);
    static HRESULT LogGetItemModerationStateResponse(PFCatalogGetItemModerationStateResponse const* result);
    static void LogGetItemPublishStatusRequest(PFCatalogGetItemPublishStatusRequest const* request, const char* testName);
    static HRESULT LogGetItemPublishStatusResponse(PFCatalogGetItemPublishStatusResponse const* result);
    static void LogGetItemReviewsRequest(PFCatalogGetItemReviewsRequest const* request, const char* testName);
    static HRESULT LogGetItemReviewsResponse(PFCatalogGetItemReviewsResponse const* result);
    static void LogGetItemReviewSummaryRequest(PFCatalogGetItemReviewSummaryRequest const* request, const char* testName);
    static HRESULT LogGetItemReviewSummaryResponse(PFCatalogGetItemReviewSummaryResponse const* result);
    static void LogGetItemsRequest(PFCatalogGetItemsRequest const* request, const char* testName);
    static HRESULT LogGetItemsResponse(PFCatalogGetItemsResponse const* result);
    static void LogPublishDraftItemRequest(PFCatalogPublishDraftItemRequest const* request, const char* testName);
    static void LogReportItemRequest(PFCatalogReportItemRequest const* request, const char* testName);
    static void LogReportItemReviewRequest(PFCatalogReportItemReviewRequest const* request, const char* testName);
    static void LogReviewItemRequest(PFCatalogReviewItemRequest const* request, const char* testName);
    static void LogSearchItemsRequest(PFCatalogSearchItemsRequest const* request, const char* testName);
    static HRESULT LogSearchItemsResponse(PFCatalogSearchItemsResponse const* result);
    static void LogSetItemModerationStateRequest(PFCatalogSetItemModerationStateRequest const* request, const char* testName);
    static void LogSubmitItemReviewVoteRequest(PFCatalogSubmitItemReviewVoteRequest const* request, const char* testName);
    static void LogTakedownItemReviewsRequest(PFCatalogTakedownItemReviewsRequest const* request, const char* testName);
    static void LogUpdateCatalogConfigRequest(PFCatalogUpdateCatalogConfigRequest const* request, const char* testName);
    static void LogUpdateDraftItemRequest(PFCatalogUpdateDraftItemRequest const* request, const char* testName);
    static HRESULT LogUpdateDraftItemResponse(PFCatalogUpdateDraftItemResponse const* result);

    static void FillCreateDraftItemRequest(PlayFab::Wrappers::PFCatalogCreateDraftItemRequestWrapper<>& request);
    static HRESULT ValidateCreateDraftItemResponse(PFCatalogCreateDraftItemResponse* result);

    static void FillCreateUploadUrlsRequest(PlayFab::Wrappers::PFCatalogCreateUploadUrlsRequestWrapper<>& request);
    static HRESULT ValidateCreateUploadUrlsResponse(PFCatalogCreateUploadUrlsResponse* result);

    static void FillDeleteEntityItemReviewsRequest(PlayFab::Wrappers::PFCatalogDeleteEntityItemReviewsRequestWrapper<>& request);

    static void FillDeleteItemRequest(PlayFab::Wrappers::PFCatalogDeleteItemRequestWrapper<>& request);

    static void FillGetCatalogConfigRequest(PlayFab::Wrappers::PFCatalogGetCatalogConfigRequestWrapper<>& request);
    static HRESULT ValidateGetCatalogConfigResponse(PFCatalogGetCatalogConfigResponse* result);

    static void FillGetDraftItemRequest(PlayFab::Wrappers::PFCatalogGetDraftItemRequestWrapper<>& request);
    static HRESULT ValidateGetDraftItemResponse(PFCatalogGetDraftItemResponse* result);

    static void FillGetDraftItemsRequest(PlayFab::Wrappers::PFCatalogGetDraftItemsRequestWrapper<>& request);
    static HRESULT ValidateGetDraftItemsResponse(PFCatalogGetDraftItemsResponse* result);

    static void FillGetEntityDraftItemsRequest(PlayFab::Wrappers::PFCatalogGetEntityDraftItemsRequestWrapper<>& request);
    static HRESULT ValidateGetEntityDraftItemsResponse(PFCatalogGetEntityDraftItemsResponse* result);

    static void FillGetEntityItemReviewRequest(PlayFab::Wrappers::PFCatalogGetEntityItemReviewRequestWrapper<>& request);
    static HRESULT ValidateGetEntityItemReviewResponse(PFCatalogGetEntityItemReviewResponse* result);

    static void FillGetItemRequest(PlayFab::Wrappers::PFCatalogGetItemRequestWrapper<>& request);
    static HRESULT ValidateGetItemResponse(PFCatalogGetItemResponse* result);

    static void FillGetItemModerationStateRequest(PlayFab::Wrappers::PFCatalogGetItemModerationStateRequestWrapper<>& request);
    static HRESULT ValidateGetItemModerationStateResponse(PFCatalogGetItemModerationStateResponse* result);

    static void FillGetItemPublishStatusRequest(PlayFab::Wrappers::PFCatalogGetItemPublishStatusRequestWrapper<>& request);
    static HRESULT ValidateGetItemPublishStatusResponse(PFCatalogGetItemPublishStatusResponse* result);

    static void FillGetItemReviewsRequest(PlayFab::Wrappers::PFCatalogGetItemReviewsRequestWrapper<>& request);
    static HRESULT ValidateGetItemReviewsResponse(PFCatalogGetItemReviewsResponse* result);

    static void FillGetItemReviewSummaryRequest(PlayFab::Wrappers::PFCatalogGetItemReviewSummaryRequestWrapper<>& request);
    static HRESULT ValidateGetItemReviewSummaryResponse(PFCatalogGetItemReviewSummaryResponse* result);

    static void FillGetItemsRequest(PlayFab::Wrappers::PFCatalogGetItemsRequestWrapper<>& request);
    static HRESULT ValidateGetItemsResponse(PFCatalogGetItemsResponse* result);

    static void FillPublishDraftItemRequest(PlayFab::Wrappers::PFCatalogPublishDraftItemRequestWrapper<>& request);

    static void FillReportItemRequest(PlayFab::Wrappers::PFCatalogReportItemRequestWrapper<>& request);

    static void FillReportItemReviewRequest(PlayFab::Wrappers::PFCatalogReportItemReviewRequestWrapper<>& request);

    static void FillReviewItemRequest(PlayFab::Wrappers::PFCatalogReviewItemRequestWrapper<>& request);

    static void FillSearchItemsRequest(PlayFab::Wrappers::PFCatalogSearchItemsRequestWrapper<>& request);
    static HRESULT ValidateSearchItemsResponse(PFCatalogSearchItemsResponse* result);

    static void FillSetItemModerationStateRequest(PlayFab::Wrappers::PFCatalogSetItemModerationStateRequestWrapper<>& request);

    static void FillSubmitItemReviewVoteRequest(PlayFab::Wrappers::PFCatalogSubmitItemReviewVoteRequestWrapper<>& request);

    static void FillTakedownItemReviewsRequest(PlayFab::Wrappers::PFCatalogTakedownItemReviewsRequestWrapper<>& request);

    static void FillUpdateCatalogConfigRequest(PlayFab::Wrappers::PFCatalogUpdateCatalogConfigRequestWrapper<>& request);

    static void FillUpdateDraftItemRequest(PlayFab::Wrappers::PFCatalogUpdateDraftItemRequestWrapper<>& request);
    static HRESULT ValidateUpdateDraftItemResponse(PFCatalogUpdateDraftItemResponse* result);

    struct CatalogTestData
    {
        ~CatalogTestData() = default;

    };

    static CatalogTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
