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
    void TestPlayStreamAdminGetAllSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminGetPlayerSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayStreamAdminGetPlayersInSegment(TestContext& testContext);
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
