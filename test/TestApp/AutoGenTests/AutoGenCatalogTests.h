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
    static void FillCreateDraftItemRequest(PlayFab::Wrappers::PFCatalogCreateDraftItemRequestWrapper<>& request);
    static HRESULT LogPFCatalogCreateDraftItemResponse(PFCatalogCreateDraftItemResponse const* result);
    static HRESULT ValidatePFCatalogCreateDraftItemResponse(PFCatalogCreateDraftItemResponse* result);

    static void LogCreateUploadUrlsRequest(PFCatalogCreateUploadUrlsRequest const* request, const char* testName);
    static void FillCreateUploadUrlsRequest(PlayFab::Wrappers::PFCatalogCreateUploadUrlsRequestWrapper<>& request);
    static HRESULT LogPFCatalogCreateUploadUrlsResponse(PFCatalogCreateUploadUrlsResponse const* result);
    static HRESULT ValidatePFCatalogCreateUploadUrlsResponse(PFCatalogCreateUploadUrlsResponse* result);

    static void LogDeleteEntityItemReviewsRequest(PFCatalogDeleteEntityItemReviewsRequest const* request, const char* testName);
    static void FillDeleteEntityItemReviewsRequest(PlayFab::Wrappers::PFCatalogDeleteEntityItemReviewsRequestWrapper<>& request);

    static void LogDeleteItemRequest(PFCatalogDeleteItemRequest const* request, const char* testName);
    static void FillDeleteItemRequest(PlayFab::Wrappers::PFCatalogDeleteItemRequestWrapper<>& request);

    static void LogGetCatalogConfigRequest(PFCatalogGetCatalogConfigRequest const* request, const char* testName);
    static void FillGetCatalogConfigRequest(PlayFab::Wrappers::PFCatalogGetCatalogConfigRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetCatalogConfigResponse(PFCatalogGetCatalogConfigResponse const* result);
    static HRESULT ValidatePFCatalogGetCatalogConfigResponse(PFCatalogGetCatalogConfigResponse* result);

    static void LogGetDraftItemRequest(PFCatalogGetDraftItemRequest const* request, const char* testName);
    static void FillGetDraftItemRequest(PlayFab::Wrappers::PFCatalogGetDraftItemRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetDraftItemResponse(PFCatalogGetDraftItemResponse const* result);
    static HRESULT ValidatePFCatalogGetDraftItemResponse(PFCatalogGetDraftItemResponse* result);

    static void LogGetDraftItemsRequest(PFCatalogGetDraftItemsRequest const* request, const char* testName);
    static void FillGetDraftItemsRequest(PlayFab::Wrappers::PFCatalogGetDraftItemsRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetDraftItemsResponse(PFCatalogGetDraftItemsResponse const* result);
    static HRESULT ValidatePFCatalogGetDraftItemsResponse(PFCatalogGetDraftItemsResponse* result);

    static void LogGetEntityDraftItemsRequest(PFCatalogGetEntityDraftItemsRequest const* request, const char* testName);
    static void FillGetEntityDraftItemsRequest(PlayFab::Wrappers::PFCatalogGetEntityDraftItemsRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetEntityDraftItemsResponse(PFCatalogGetEntityDraftItemsResponse const* result);
    static HRESULT ValidatePFCatalogGetEntityDraftItemsResponse(PFCatalogGetEntityDraftItemsResponse* result);

    static void LogGetEntityItemReviewRequest(PFCatalogGetEntityItemReviewRequest const* request, const char* testName);
    static void FillGetEntityItemReviewRequest(PlayFab::Wrappers::PFCatalogGetEntityItemReviewRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetEntityItemReviewResponse(PFCatalogGetEntityItemReviewResponse const* result);
    static HRESULT ValidatePFCatalogGetEntityItemReviewResponse(PFCatalogGetEntityItemReviewResponse* result);

    static void LogGetItemRequest(PFCatalogGetItemRequest const* request, const char* testName);
    static void FillGetItemRequest(PlayFab::Wrappers::PFCatalogGetItemRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetItemResponse(PFCatalogGetItemResponse const* result);
    static HRESULT ValidatePFCatalogGetItemResponse(PFCatalogGetItemResponse* result);

    static void LogGetItemModerationStateRequest(PFCatalogGetItemModerationStateRequest const* request, const char* testName);
    static void FillGetItemModerationStateRequest(PlayFab::Wrappers::PFCatalogGetItemModerationStateRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetItemModerationStateResponse(PFCatalogGetItemModerationStateResponse const* result);
    static HRESULT ValidatePFCatalogGetItemModerationStateResponse(PFCatalogGetItemModerationStateResponse* result);

    static void LogGetItemPublishStatusRequest(PFCatalogGetItemPublishStatusRequest const* request, const char* testName);
    static void FillGetItemPublishStatusRequest(PlayFab::Wrappers::PFCatalogGetItemPublishStatusRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetItemPublishStatusResponse(PFCatalogGetItemPublishStatusResponse const* result);
    static HRESULT ValidatePFCatalogGetItemPublishStatusResponse(PFCatalogGetItemPublishStatusResponse* result);

    static void LogGetItemReviewsRequest(PFCatalogGetItemReviewsRequest const* request, const char* testName);
    static void FillGetItemReviewsRequest(PlayFab::Wrappers::PFCatalogGetItemReviewsRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetItemReviewsResponse(PFCatalogGetItemReviewsResponse const* result);
    static HRESULT ValidatePFCatalogGetItemReviewsResponse(PFCatalogGetItemReviewsResponse* result);

    static void LogGetItemReviewSummaryRequest(PFCatalogGetItemReviewSummaryRequest const* request, const char* testName);
    static void FillGetItemReviewSummaryRequest(PlayFab::Wrappers::PFCatalogGetItemReviewSummaryRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetItemReviewSummaryResponse(PFCatalogGetItemReviewSummaryResponse const* result);
    static HRESULT ValidatePFCatalogGetItemReviewSummaryResponse(PFCatalogGetItemReviewSummaryResponse* result);

    static void LogGetItemsRequest(PFCatalogGetItemsRequest const* request, const char* testName);
    static void FillGetItemsRequest(PlayFab::Wrappers::PFCatalogGetItemsRequestWrapper<>& request);
    static HRESULT LogPFCatalogGetItemsResponse(PFCatalogGetItemsResponse const* result);
    static HRESULT ValidatePFCatalogGetItemsResponse(PFCatalogGetItemsResponse* result);

    static void LogPublishDraftItemRequest(PFCatalogPublishDraftItemRequest const* request, const char* testName);
    static void FillPublishDraftItemRequest(PlayFab::Wrappers::PFCatalogPublishDraftItemRequestWrapper<>& request);

    static void LogReportItemRequest(PFCatalogReportItemRequest const* request, const char* testName);
    static void FillReportItemRequest(PlayFab::Wrappers::PFCatalogReportItemRequestWrapper<>& request);

    static void LogReportItemReviewRequest(PFCatalogReportItemReviewRequest const* request, const char* testName);
    static void FillReportItemReviewRequest(PlayFab::Wrappers::PFCatalogReportItemReviewRequestWrapper<>& request);

    static void LogReviewItemRequest(PFCatalogReviewItemRequest const* request, const char* testName);
    static void FillReviewItemRequest(PlayFab::Wrappers::PFCatalogReviewItemRequestWrapper<>& request);

    static void LogSearchItemsRequest(PFCatalogSearchItemsRequest const* request, const char* testName);
    static void FillSearchItemsRequest(PlayFab::Wrappers::PFCatalogSearchItemsRequestWrapper<>& request);
    static HRESULT LogPFCatalogSearchItemsResponse(PFCatalogSearchItemsResponse const* result);
    static HRESULT ValidatePFCatalogSearchItemsResponse(PFCatalogSearchItemsResponse* result);

    static void LogSetItemModerationStateRequest(PFCatalogSetItemModerationStateRequest const* request, const char* testName);
    static void FillSetItemModerationStateRequest(PlayFab::Wrappers::PFCatalogSetItemModerationStateRequestWrapper<>& request);

    static void LogSubmitItemReviewVoteRequest(PFCatalogSubmitItemReviewVoteRequest const* request, const char* testName);
    static void FillSubmitItemReviewVoteRequest(PlayFab::Wrappers::PFCatalogSubmitItemReviewVoteRequestWrapper<>& request);

    static void LogTakedownItemReviewsRequest(PFCatalogTakedownItemReviewsRequest const* request, const char* testName);
    static void FillTakedownItemReviewsRequest(PlayFab::Wrappers::PFCatalogTakedownItemReviewsRequestWrapper<>& request);

    static void LogUpdateCatalogConfigRequest(PFCatalogUpdateCatalogConfigRequest const* request, const char* testName);
    static void FillUpdateCatalogConfigRequest(PlayFab::Wrappers::PFCatalogUpdateCatalogConfigRequestWrapper<>& request);

    static void LogUpdateDraftItemRequest(PFCatalogUpdateDraftItemRequest const* request, const char* testName);
    static void FillUpdateDraftItemRequest(PlayFab::Wrappers::PFCatalogUpdateDraftItemRequestWrapper<>& request);
    static HRESULT LogPFCatalogUpdateDraftItemResponse(PFCatalogUpdateDraftItemResponse const* result);
    static HRESULT ValidatePFCatalogUpdateDraftItemResponse(PFCatalogUpdateDraftItemResponse* result);

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
