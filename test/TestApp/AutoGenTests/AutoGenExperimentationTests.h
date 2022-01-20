#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFExperimentationDataModelWrappers.h>
#include "AutoGenExperimentationResultHolders.h"

namespace PlayFabUnit
{

class AutoGenExperimentationTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationCreateExclusionGroup(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationCreateExperiment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationDeleteExclusionGroup(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationDeleteExperiment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationGetExclusionGroups(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationGetExclusionGroupTraffic(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationGetExperiments(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationGetLatestScorecard(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationGetTreatmentAssignment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationStartExperiment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationStopExperiment(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationUpdateExclusionGroup(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestExperimentationUpdateExperiment(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogCreateExclusionGroupRequest(PFExperimentationCreateExclusionGroupRequest const* request, const char* testName);
    static HRESULT LogCreateExclusionGroupResult(PFExperimentationCreateExclusionGroupResult const* result);
    static void LogCreateExperimentRequest(PFExperimentationCreateExperimentRequest const* request, const char* testName);
    static HRESULT LogCreateExperimentResult(PFExperimentationCreateExperimentResult const* result);
    static void LogDeleteExclusionGroupRequest(PFExperimentationDeleteExclusionGroupRequest const* request, const char* testName);
    static void LogDeleteExperimentRequest(PFExperimentationDeleteExperimentRequest const* request, const char* testName);
    static void LogGetExclusionGroupsRequest(PFExperimentationGetExclusionGroupsRequest const* request, const char* testName);
    static HRESULT LogGetExclusionGroupsResult(PFExperimentationGetExclusionGroupsResult const* result);
    static void LogGetExclusionGroupTrafficRequest(PFExperimentationGetExclusionGroupTrafficRequest const* request, const char* testName);
    static HRESULT LogGetExclusionGroupTrafficResult(PFExperimentationGetExclusionGroupTrafficResult const* result);
    static void LogGetExperimentsRequest(PFExperimentationGetExperimentsRequest const* request, const char* testName);
    static HRESULT LogGetExperimentsResult(PFExperimentationGetExperimentsResult const* result);
    static void LogGetLatestScorecardRequest(PFExperimentationGetLatestScorecardRequest const* request, const char* testName);
    static HRESULT LogGetLatestScorecardResult(PFExperimentationGetLatestScorecardResult const* result);
    static void LogGetTreatmentAssignmentRequest(PFExperimentationGetTreatmentAssignmentRequest const* request, const char* testName);
    static HRESULT LogGetTreatmentAssignmentResult(PFExperimentationGetTreatmentAssignmentResult const* result);
    static void LogStartExperimentRequest(PFExperimentationStartExperimentRequest const* request, const char* testName);
    static void LogStopExperimentRequest(PFExperimentationStopExperimentRequest const* request, const char* testName);
    static void LogUpdateExclusionGroupRequest(PFExperimentationUpdateExclusionGroupRequest const* request, const char* testName);
    static void LogUpdateExperimentRequest(PFExperimentationUpdateExperimentRequest const* request, const char* testName);

    static void FillCreateExclusionGroupRequest(PlayFab::Wrappers::PFExperimentationCreateExclusionGroupRequestWrapper<>& request);
    static HRESULT ValidateCreateExclusionGroupResponse(PFExperimentationCreateExclusionGroupResult* result);

    static void FillCreateExperimentRequest(PlayFab::Wrappers::PFExperimentationCreateExperimentRequestWrapper<>& request);
    static HRESULT ValidateCreateExperimentResponse(PFExperimentationCreateExperimentResult* result);

    static void FillDeleteExclusionGroupRequest(PlayFab::Wrappers::PFExperimentationDeleteExclusionGroupRequestWrapper<>& request);

    static void FillDeleteExperimentRequest(PlayFab::Wrappers::PFExperimentationDeleteExperimentRequestWrapper<>& request);

    static void FillGetExclusionGroupsRequest(PlayFab::Wrappers::PFExperimentationGetExclusionGroupsRequestWrapper<>& request);
    static HRESULT ValidateGetExclusionGroupsResponse(PFExperimentationGetExclusionGroupsResult* result);

    static void FillGetExclusionGroupTrafficRequest(PlayFab::Wrappers::PFExperimentationGetExclusionGroupTrafficRequestWrapper<>& request);
    static HRESULT ValidateGetExclusionGroupTrafficResponse(PFExperimentationGetExclusionGroupTrafficResult* result);

    static void FillGetExperimentsRequest(PlayFab::Wrappers::PFExperimentationGetExperimentsRequestWrapper<>& request);
    static HRESULT ValidateGetExperimentsResponse(PFExperimentationGetExperimentsResult* result);

    static void FillGetLatestScorecardRequest(PlayFab::Wrappers::PFExperimentationGetLatestScorecardRequestWrapper<>& request);
    static HRESULT ValidateGetLatestScorecardResponse(PFExperimentationGetLatestScorecardResult* result);

    static void FillGetTreatmentAssignmentRequest(PlayFab::Wrappers::PFExperimentationGetTreatmentAssignmentRequestWrapper<>& request);
    static HRESULT ValidateGetTreatmentAssignmentResponse(PFExperimentationGetTreatmentAssignmentResult* result);

    static void FillStartExperimentRequest(PlayFab::Wrappers::PFExperimentationStartExperimentRequestWrapper<>& request);

    static void FillStopExperimentRequest(PlayFab::Wrappers::PFExperimentationStopExperimentRequestWrapper<>& request);

    static void FillUpdateExclusionGroupRequest(PlayFab::Wrappers::PFExperimentationUpdateExclusionGroupRequestWrapper<>& request);

    static void FillUpdateExperimentRequest(PlayFab::Wrappers::PFExperimentationUpdateExperimentRequestWrapper<>& request);

    struct ExperimentationTestData
    {
        ~ExperimentationTestData() = default;

    };

    static ExperimentationTestData testData;

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
