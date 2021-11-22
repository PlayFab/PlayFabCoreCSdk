#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFPlayStreamDataModelWrappers.h>
#include "AutoGenPlayStreamResultHolders.h"

namespace PlayFabUnit
{

class AutoGenPlayStreamTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestPlayStreamAdminAddPlayerTag(TestContext& testContext);

    void TestPlayStreamAdminGetAllSegments(TestContext& testContext);

    void TestPlayStreamAdminGetPlayerSegments(TestContext& testContext);

    void TestPlayStreamAdminGetPlayersInSegment(TestContext& testContext);

    void TestPlayStreamAdminGetPlayerTags(TestContext& testContext);

    void TestPlayStreamAdminRemovePlayerTag(TestContext& testContext);

    void TestPlayStreamClientGetPlayerSegments(TestContext& testContext);

    void TestPlayStreamClientGetPlayerTags(TestContext& testContext);

    void TestPlayStreamServerAddPlayerTag(TestContext& testContext);

    void TestPlayStreamServerGetAllSegments(TestContext& testContext);

    void TestPlayStreamServerGetPlayerSegments(TestContext& testContext);

    void TestPlayStreamServerGetPlayersInSegment(TestContext& testContext);

    void TestPlayStreamServerGetPlayerTags(TestContext& testContext);

    void TestPlayStreamServerRemovePlayerTag(TestContext& testContext);

    void TestPlayStreamWriteEvents(TestContext& testContext);

    void TestPlayStreamWriteTelemetryEvents(TestContext& testContext);


protected:
    void AddTests();

    static void LogAddPlayerTagRequest(PFPlayStreamAddPlayerTagRequest const* request, const char* testName);
    static void FillAddPlayerTagRequest(PlayFab::Wrappers::PFPlayStreamAddPlayerTagRequestWrapper<>& request);

    static HRESULT LogPFPlayStreamGetAllSegmentsResult(PFPlayStreamGetAllSegmentsResult const* result);
    static HRESULT ValidatePFPlayStreamGetAllSegmentsResult(PFPlayStreamGetAllSegmentsResult* result);

    static void LogGetPlayersSegmentsRequest(PFPlayStreamGetPlayersSegmentsRequest const* request, const char* testName);
    static void FillGetPlayersSegmentsRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersSegmentsRequestWrapper<>& request);
    static HRESULT LogPFPlayStreamGetPlayerSegmentsResult(PFPlayStreamGetPlayerSegmentsResult const* result);
    static HRESULT ValidatePFPlayStreamGetPlayerSegmentsResult(PFPlayStreamGetPlayerSegmentsResult* result);

    static void LogGetPlayersInSegmentRequest(PFPlayStreamGetPlayersInSegmentRequest const* request, const char* testName);
    static void FillGetPlayersInSegmentRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersInSegmentRequestWrapper<>& request);
    static HRESULT LogPFPlayStreamGetPlayersInSegmentResult(PFPlayStreamGetPlayersInSegmentResult const* result);
    static HRESULT ValidatePFPlayStreamGetPlayersInSegmentResult(PFPlayStreamGetPlayersInSegmentResult* result);

    static void LogGetPlayerTagsRequest(PFPlayStreamGetPlayerTagsRequest const* request, const char* testName);
    static void FillGetPlayerTagsRequest(PlayFab::Wrappers::PFPlayStreamGetPlayerTagsRequestWrapper<>& request);
    static HRESULT LogPFPlayStreamGetPlayerTagsResult(PFPlayStreamGetPlayerTagsResult const* result);
    static HRESULT ValidatePFPlayStreamGetPlayerTagsResult(PFPlayStreamGetPlayerTagsResult* result);

    static void LogRemovePlayerTagRequest(PFPlayStreamRemovePlayerTagRequest const* request, const char* testName);
    static void FillRemovePlayerTagRequest(PlayFab::Wrappers::PFPlayStreamRemovePlayerTagRequestWrapper<>& request);









    static void LogWriteEventsRequest(PFPlayStreamWriteEventsRequest const* request, const char* testName);
    static void FillWriteEventsRequest(PlayFab::Wrappers::PFPlayStreamWriteEventsRequestWrapper<>& request);
    static HRESULT LogPFPlayStreamWriteEventsResponse(PFPlayStreamWriteEventsResponse const* result);
    static HRESULT ValidatePFPlayStreamWriteEventsResponse(PFPlayStreamWriteEventsResponse* result);


    struct PlayStreamTestData
    {
        ~PlayStreamTestData() = default;

    };

    static PlayStreamTestData testData;

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
