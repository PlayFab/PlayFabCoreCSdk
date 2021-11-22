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

    void TestExperimentationCreateExclusionGroup(TestContext& testContext);

    void TestExperimentationCreateExperiment(TestContext& testContext);

    void TestExperimentationDeleteExclusionGroup(TestContext& testContext);

    void TestExperimentationDeleteExperiment(TestContext& testContext);

    void TestExperimentationGetExclusionGroups(TestContext& testContext);

    void TestExperimentationGetExclusionGroupTraffic(TestContext& testContext);

    void TestExperimentationGetExperiments(TestContext& testContext);

    void TestExperimentationGetLatestScorecard(TestContext& testContext);

    void TestExperimentationGetTreatmentAssignment(TestContext& testContext);

    void TestExperimentationStartExperiment(TestContext& testContext);

    void TestExperimentationStopExperiment(TestContext& testContext);

    void TestExperimentationUpdateExclusionGroup(TestContext& testContext);

    void TestExperimentationUpdateExperiment(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreateExclusionGroupRequest(PFExperimentationCreateExclusionGroupRequest const* request, const char* testName);
    static void FillCreateExclusionGroupRequest(PlayFab::Wrappers::PFExperimentationCreateExclusionGroupRequestWrapper<>& request);
    static HRESULT LogPFExperimentationCreateExclusionGroupResult(PFExperimentationCreateExclusionGroupResult const* result);
    static HRESULT ValidatePFExperimentationCreateExclusionGroupResult(PFExperimentationCreateExclusionGroupResult* result);

    static void LogCreateExperimentRequest(PFExperimentationCreateExperimentRequest const* request, const char* testName);
    static void FillCreateExperimentRequest(PlayFab::Wrappers::PFExperimentationCreateExperimentRequestWrapper<>& request);
    static HRESULT LogPFExperimentationCreateExperimentResult(PFExperimentationCreateExperimentResult const* result);
    static HRESULT ValidatePFExperimentationCreateExperimentResult(PFExperimentationCreateExperimentResult* result);

    static void LogDeleteExclusionGroupRequest(PFExperimentationDeleteExclusionGroupRequest const* request, const char* testName);
    static void FillDeleteExclusionGroupRequest(PlayFab::Wrappers::PFExperimentationDeleteExclusionGroupRequestWrapper<>& request);

    static void LogDeleteExperimentRequest(PFExperimentationDeleteExperimentRequest const* request, const char* testName);
    static void FillDeleteExperimentRequest(PlayFab::Wrappers::PFExperimentationDeleteExperimentRequestWrapper<>& request);

    static void LogGetExclusionGroupsRequest(PFExperimentationGetExclusionGroupsRequest const* request, const char* testName);
    static void FillGetExclusionGroupsRequest(PlayFab::Wrappers::PFExperimentationGetExclusionGroupsRequestWrapper<>& request);
    static HRESULT LogPFExperimentationGetExclusionGroupsResult(PFExperimentationGetExclusionGroupsResult const* result);
    static HRESULT ValidatePFExperimentationGetExclusionGroupsResult(PFExperimentationGetExclusionGroupsResult* result);

    static void LogGetExclusionGroupTrafficRequest(PFExperimentationGetExclusionGroupTrafficRequest const* request, const char* testName);
    static void FillGetExclusionGroupTrafficRequest(PlayFab::Wrappers::PFExperimentationGetExclusionGroupTrafficRequestWrapper<>& request);
    static HRESULT LogPFExperimentationGetExclusionGroupTrafficResult(PFExperimentationGetExclusionGroupTrafficResult const* result);
    static HRESULT ValidatePFExperimentationGetExclusionGroupTrafficResult(PFExperimentationGetExclusionGroupTrafficResult* result);

    static void LogGetExperimentsRequest(PFExperimentationGetExperimentsRequest const* request, const char* testName);
    static void FillGetExperimentsRequest(PlayFab::Wrappers::PFExperimentationGetExperimentsRequestWrapper<>& request);
    static HRESULT LogPFExperimentationGetExperimentsResult(PFExperimentationGetExperimentsResult const* result);
    static HRESULT ValidatePFExperimentationGetExperimentsResult(PFExperimentationGetExperimentsResult* result);

    static void LogGetLatestScorecardRequest(PFExperimentationGetLatestScorecardRequest const* request, const char* testName);
    static void FillGetLatestScorecardRequest(PlayFab::Wrappers::PFExperimentationGetLatestScorecardRequestWrapper<>& request);
    static HRESULT LogPFExperimentationGetLatestScorecardResult(PFExperimentationGetLatestScorecardResult const* result);
    static HRESULT ValidatePFExperimentationGetLatestScorecardResult(PFExperimentationGetLatestScorecardResult* result);

    static void LogGetTreatmentAssignmentRequest(PFExperimentationGetTreatmentAssignmentRequest const* request, const char* testName);
    static void FillGetTreatmentAssignmentRequest(PlayFab::Wrappers::PFExperimentationGetTreatmentAssignmentRequestWrapper<>& request);
    static HRESULT LogPFExperimentationGetTreatmentAssignmentResult(PFExperimentationGetTreatmentAssignmentResult const* result);
    static HRESULT ValidatePFExperimentationGetTreatmentAssignmentResult(PFExperimentationGetTreatmentAssignmentResult* result);

    static void LogStartExperimentRequest(PFExperimentationStartExperimentRequest const* request, const char* testName);
    static void FillStartExperimentRequest(PlayFab::Wrappers::PFExperimentationStartExperimentRequestWrapper<>& request);

    static void LogStopExperimentRequest(PFExperimentationStopExperimentRequest const* request, const char* testName);
    static void FillStopExperimentRequest(PlayFab::Wrappers::PFExperimentationStopExperimentRequestWrapper<>& request);

    static void LogUpdateExclusionGroupRequest(PFExperimentationUpdateExclusionGroupRequest const* request, const char* testName);
    static void FillUpdateExclusionGroupRequest(PlayFab::Wrappers::PFExperimentationUpdateExclusionGroupRequestWrapper<>& request);

    static void LogUpdateExperimentRequest(PFExperimentationUpdateExperimentRequest const* request, const char* testName);
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
