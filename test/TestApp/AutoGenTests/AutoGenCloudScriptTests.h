#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFCloudScriptDataModelWrappers.h>
#include "AutoGenCloudScriptResultHolders.h"

namespace PlayFabUnit
{

class AutoGenCloudScriptTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestCloudScriptAdminGetCloudScriptRevision(TestContext& testContext);

    void TestCloudScriptAdminGetCloudScriptVersions(TestContext& testContext);

    void TestCloudScriptAdminSetPublishedRevision(TestContext& testContext);

    void TestCloudScriptAdminUpdateCloudScript(TestContext& testContext);

    void TestCloudScriptClientExecuteCloudScript(TestContext& testContext);

    void TestCloudScriptServerExecuteCloudScript(TestContext& testContext);

    void TestCloudScriptExecuteEntityCloudScript(TestContext& testContext);

    void TestCloudScriptExecuteFunction(TestContext& testContext);

    void TestCloudScriptGetFunction(TestContext& testContext);

    void TestCloudScriptListFunctions(TestContext& testContext);

    void TestCloudScriptListHttpFunctions(TestContext& testContext);

    void TestCloudScriptListQueuedFunctions(TestContext& testContext);

    void TestCloudScriptPostFunctionResultForEntityTriggeredAction(TestContext& testContext);

    void TestCloudScriptPostFunctionResultForFunctionExecution(TestContext& testContext);

    void TestCloudScriptPostFunctionResultForPlayerTriggeredAction(TestContext& testContext);

    void TestCloudScriptPostFunctionResultForScheduledTask(TestContext& testContext);

    void TestCloudScriptRegisterHttpFunction(TestContext& testContext);

    void TestCloudScriptRegisterQueuedFunction(TestContext& testContext);

    void TestCloudScriptUnregisterFunction(TestContext& testContext);


protected:
    void AddTests();

    static void LogGetCloudScriptRevisionRequest(PFCloudScriptGetCloudScriptRevisionRequest const* request, const char* testName);
    static void FillGetCloudScriptRevisionRequest(PlayFab::Wrappers::PFCloudScriptGetCloudScriptRevisionRequestWrapper<>& request);
    static HRESULT LogPFCloudScriptGetCloudScriptRevisionResult(PFCloudScriptGetCloudScriptRevisionResult const* result);
    static HRESULT ValidatePFCloudScriptGetCloudScriptRevisionResult(PFCloudScriptGetCloudScriptRevisionResult* result);

    static HRESULT LogPFCloudScriptGetCloudScriptVersionsResult(PFCloudScriptGetCloudScriptVersionsResult const* result);
    static HRESULT ValidatePFCloudScriptGetCloudScriptVersionsResult(PFCloudScriptGetCloudScriptVersionsResult* result);

    static void LogSetPublishedRevisionRequest(PFCloudScriptSetPublishedRevisionRequest const* request, const char* testName);
    static void FillSetPublishedRevisionRequest(PlayFab::Wrappers::PFCloudScriptSetPublishedRevisionRequestWrapper<>& request);

    static void LogUpdateCloudScriptRequest(PFCloudScriptUpdateCloudScriptRequest const* request, const char* testName);
    static void FillUpdateCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptUpdateCloudScriptRequestWrapper<>& request);
    static HRESULT LogPFCloudScriptUpdateCloudScriptResult(PFCloudScriptUpdateCloudScriptResult const* result);
    static HRESULT ValidatePFCloudScriptUpdateCloudScriptResult(PFCloudScriptUpdateCloudScriptResult* result);

    static void LogExecuteCloudScriptRequest(PFCloudScriptExecuteCloudScriptRequest const* request, const char* testName);
    static void FillExecuteCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptExecuteCloudScriptRequestWrapper<>& request);
    static HRESULT LogPFExecuteCloudScriptResult(PFExecuteCloudScriptResult const* result);
    static HRESULT ValidatePFExecuteCloudScriptResult(PFExecuteCloudScriptResult* result);

    static void LogExecuteCloudScriptServerRequest(PFCloudScriptExecuteCloudScriptServerRequest const* request, const char* testName);
    static void FillExecuteCloudScriptServerRequest(PlayFab::Wrappers::PFCloudScriptExecuteCloudScriptServerRequestWrapper<>& request);

    static void LogExecuteEntityCloudScriptRequest(PFCloudScriptExecuteEntityCloudScriptRequest const* request, const char* testName);
    static void FillExecuteEntityCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptExecuteEntityCloudScriptRequestWrapper<>& request);

    static void LogExecuteFunctionRequest(PFCloudScriptExecuteFunctionRequest const* request, const char* testName);
    static void FillExecuteFunctionRequest(PlayFab::Wrappers::PFCloudScriptExecuteFunctionRequestWrapper<>& request);
    static HRESULT LogPFCloudScriptExecuteFunctionResult(PFCloudScriptExecuteFunctionResult const* result);
    static HRESULT ValidatePFCloudScriptExecuteFunctionResult(PFCloudScriptExecuteFunctionResult* result);

    static void LogGetFunctionRequest(PFCloudScriptGetFunctionRequest const* request, const char* testName);
    static void FillGetFunctionRequest(PlayFab::Wrappers::PFCloudScriptGetFunctionRequestWrapper<>& request);
    static HRESULT LogPFCloudScriptGetFunctionResult(PFCloudScriptGetFunctionResult const* result);
    static HRESULT ValidatePFCloudScriptGetFunctionResult(PFCloudScriptGetFunctionResult* result);

    static void LogListFunctionsRequest(PFCloudScriptListFunctionsRequest const* request, const char* testName);
    static void FillListFunctionsRequest(PlayFab::Wrappers::PFCloudScriptListFunctionsRequestWrapper<>& request);
    static HRESULT LogPFCloudScriptListFunctionsResult(PFCloudScriptListFunctionsResult const* result);
    static HRESULT ValidatePFCloudScriptListFunctionsResult(PFCloudScriptListFunctionsResult* result);

    static HRESULT LogPFCloudScriptListHttpFunctionsResult(PFCloudScriptListHttpFunctionsResult const* result);
    static HRESULT ValidatePFCloudScriptListHttpFunctionsResult(PFCloudScriptListHttpFunctionsResult* result);

    static HRESULT LogPFCloudScriptListQueuedFunctionsResult(PFCloudScriptListQueuedFunctionsResult const* result);
    static HRESULT ValidatePFCloudScriptListQueuedFunctionsResult(PFCloudScriptListQueuedFunctionsResult* result);

    static void LogPostFunctionResultForEntityTriggeredActionRequest(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest const* request, const char* testName);
    static void FillPostFunctionResultForEntityTriggeredActionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<>& request);

    static void LogPostFunctionResultForFunctionExecutionRequest(PFCloudScriptPostFunctionResultForFunctionExecutionRequest const* request, const char* testName);
    static void FillPostFunctionResultForFunctionExecutionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<>& request);

    static void LogPostFunctionResultForPlayerTriggeredActionRequest(PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest const* request, const char* testName);
    static void FillPostFunctionResultForPlayerTriggeredActionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper<>& request);

    static void LogPostFunctionResultForScheduledTaskRequest(PFCloudScriptPostFunctionResultForScheduledTaskRequest const* request, const char* testName);
    static void FillPostFunctionResultForScheduledTaskRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper<>& request);

    static void LogRegisterHttpFunctionRequest(PFCloudScriptRegisterHttpFunctionRequest const* request, const char* testName);
    static void FillRegisterHttpFunctionRequest(PlayFab::Wrappers::PFCloudScriptRegisterHttpFunctionRequestWrapper<>& request);

    static void LogRegisterQueuedFunctionRequest(PFCloudScriptRegisterQueuedFunctionRequest const* request, const char* testName);
    static void FillRegisterQueuedFunctionRequest(PlayFab::Wrappers::PFCloudScriptRegisterQueuedFunctionRequestWrapper<>& request);

    static void LogUnregisterFunctionRequest(PFCloudScriptUnregisterFunctionRequest const* request, const char* testName);
    static void FillUnregisterFunctionRequest(PlayFab::Wrappers::PFCloudScriptUnregisterFunctionRequestWrapper<>& request);

    struct CloudScriptTestData
    {
        ~CloudScriptTestData() = default;

    };

    static CloudScriptTestData testData;

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
