#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFSegmentsDataModelWrappers.h>
#include "AutoGenSegmentsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenSegmentsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSegmentsAdminCreateSegment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSegmentsAdminDeleteSegment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSegmentsAdminGetSegments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestSegmentsAdminUpdateSegment(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogCreateSegmentRequest(PFSegmentsCreateSegmentRequest const* request, const char* testName);
    static void FillCreateSegmentRequest(PlayFab::Wrappers::PFSegmentsCreateSegmentRequestWrapper<>& request);
    static HRESULT LogPFSegmentsCreateSegmentResponse(PFSegmentsCreateSegmentResponse const* result);
    static HRESULT ValidatePFSegmentsCreateSegmentResponse(PFSegmentsCreateSegmentResponse* result);

    static void LogDeleteSegmentRequest(PFSegmentsDeleteSegmentRequest const* request, const char* testName);
    static void FillDeleteSegmentRequest(PlayFab::Wrappers::PFSegmentsDeleteSegmentRequestWrapper<>& request);
    static HRESULT LogPFSegmentsDeleteSegmentsResponse(PFSegmentsDeleteSegmentsResponse const* result);
    static HRESULT ValidatePFSegmentsDeleteSegmentsResponse(PFSegmentsDeleteSegmentsResponse* result);

    static void LogGetSegmentsRequest(PFSegmentsGetSegmentsRequest const* request, const char* testName);
    static void FillGetSegmentsRequest(PlayFab::Wrappers::PFSegmentsGetSegmentsRequestWrapper<>& request);
    static HRESULT LogPFSegmentsGetSegmentsResponse(PFSegmentsGetSegmentsResponse const* result);
    static HRESULT ValidatePFSegmentsGetSegmentsResponse(PFSegmentsGetSegmentsResponse* result);

    static void LogUpdateSegmentRequest(PFSegmentsUpdateSegmentRequest const* request, const char* testName);
    static void FillUpdateSegmentRequest(PlayFab::Wrappers::PFSegmentsUpdateSegmentRequestWrapper<>& request);
    static HRESULT LogPFSegmentsUpdateSegmentResponse(PFSegmentsUpdateSegmentResponse const* result);
    static HRESULT ValidatePFSegmentsUpdateSegmentResponse(PFSegmentsUpdateSegmentResponse* result);

    struct SegmentsTestData
    {
        ~SegmentsTestData() = default;

    };

    static SegmentsTestData testData;

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
