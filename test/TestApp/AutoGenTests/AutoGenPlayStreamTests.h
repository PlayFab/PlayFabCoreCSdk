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

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminExportPlayersInSegment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminGetAllSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminGetPlayerSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminGetPlayersInSegment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminGetSegmentExport(TestContext& testContext);
#endif

    void TestPlayStreamClientGetPlayerSegments(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamServerGetAllSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamServerGetPlayerSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamServerGetPlayersInSegment(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogExportPlayersInSegmentRequest(PFPlayStreamExportPlayersInSegmentRequest const* request, const char* testName);
    static HRESULT LogExportPlayersInSegmentResult(PFPlayStreamExportPlayersInSegmentResult const* result);
    static HRESULT LogGetAllSegmentsResult(PFPlayStreamGetAllSegmentsResult const* result);
    static void LogGetPlayersSegmentsRequest(PFPlayStreamGetPlayersSegmentsRequest const* request, const char* testName);
    static HRESULT LogGetPlayerSegmentsResult(PFPlayStreamGetPlayerSegmentsResult const* result);
    static void LogGetPlayersInSegmentRequest(PFPlayStreamGetPlayersInSegmentRequest const* request, const char* testName);
    static HRESULT LogGetPlayersInSegmentResult(PFPlayStreamGetPlayersInSegmentResult const* result);
    static void LogGetPlayersInSegmentExportRequest(PFPlayStreamGetPlayersInSegmentExportRequest const* request, const char* testName);
    static HRESULT LogGetPlayersInSegmentExportResponse(PFPlayStreamGetPlayersInSegmentExportResponse const* result);

    void FillAdminExportPlayersInSegmentRequest(PlayFab::Wrappers::PFPlayStreamExportPlayersInSegmentRequestWrapper<>& request);
    static HRESULT ValidateAdminExportPlayersInSegmentResponse(PFPlayStreamExportPlayersInSegmentResult* result);

    static HRESULT ValidateAdminGetAllSegmentsResponse(PFPlayStreamGetAllSegmentsResult* result);

    void FillAdminGetPlayerSegmentsRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersSegmentsRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayerSegmentsResponse(PFPlayStreamGetPlayerSegmentsResult* result);

    void FillAdminGetPlayersInSegmentRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersInSegmentRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPlayersInSegmentResponse(PFPlayStreamGetPlayersInSegmentResult* result);

    void FillAdminGetSegmentExportRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersInSegmentExportRequestWrapper<>& request);
    static HRESULT ValidateAdminGetSegmentExportResponse(PFPlayStreamGetPlayersInSegmentExportResponse* result);

    static HRESULT ValidateClientGetPlayerSegmentsResponse(PFPlayStreamGetPlayerSegmentsResult* result);

    static HRESULT ValidateServerGetAllSegmentsResponse(PFPlayStreamGetAllSegmentsResult* result);

    void FillServerGetPlayerSegmentsRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersSegmentsRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayerSegmentsResponse(PFPlayStreamGetPlayerSegmentsResult* result);

    void FillServerGetPlayersInSegmentRequest(PlayFab::Wrappers::PFPlayStreamGetPlayersInSegmentRequestWrapper<>& request);
    static HRESULT ValidateServerGetPlayersInSegmentResponse(PFPlayStreamGetPlayersInSegmentResult* result);

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
