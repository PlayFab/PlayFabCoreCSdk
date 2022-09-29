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

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptAdminGetCloudScriptRevision(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptAdminGetCloudScriptVersions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptAdminSetPublishedRevision(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptAdminUpdateCloudScript(TestContext& testContext);
#endif

    void TestCloudScriptClientExecuteCloudScript(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptServerExecuteCloudScript(TestContext& testContext);
#endif

    void TestCloudScriptExecuteEntityCloudScript(TestContext& testContext);

    void TestCloudScriptExecuteFunction(TestContext& testContext);

    void TestCloudScriptGetFunction(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptListFunctions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptListHttpFunctions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptListQueuedFunctions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptPostFunctionResultForEntityTriggeredAction(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptPostFunctionResultForFunctionExecution(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptPostFunctionResultForPlayerTriggeredAction(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptPostFunctionResultForScheduledTask(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptRegisterHttpFunction(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptRegisterQueuedFunction(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptUnregisterFunction(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogGetCloudScriptRevisionRequest(PFCloudScriptGetCloudScriptRevisionRequest const* request, const char* testName);
    static HRESULT LogGetCloudScriptRevisionResult(PFCloudScriptGetCloudScriptRevisionResult const* result);
    static HRESULT LogGetCloudScriptVersionsResult(PFCloudScriptGetCloudScriptVersionsResult const* result);
    static void LogSetPublishedRevisionRequest(PFCloudScriptSetPublishedRevisionRequest const* request, const char* testName);
    static void LogUpdateCloudScriptRequest(PFCloudScriptUpdateCloudScriptRequest const* request, const char* testName);
    static HRESULT LogUpdateCloudScriptResult(PFCloudScriptUpdateCloudScriptResult const* result);
    static void LogExecuteCloudScriptRequest(PFCloudScriptExecuteCloudScriptRequest const* request, const char* testName);
    static HRESULT LogExecuteCloudScriptResult(PFExecuteCloudScriptResult const* result);
    static void LogExecuteCloudScriptServerRequest(PFCloudScriptExecuteCloudScriptServerRequest const* request, const char* testName);
    static void LogExecuteEntityCloudScriptRequest(PFCloudScriptExecuteEntityCloudScriptRequest const* request, const char* testName);
    static void LogExecuteFunctionRequest(PFCloudScriptExecuteFunctionRequest const* request, const char* testName);
    static HRESULT LogExecuteFunctionResult(PFCloudScriptExecuteFunctionResult const* result);
    static void LogGetFunctionRequest(PFCloudScriptGetFunctionRequest const* request, const char* testName);
    static HRESULT LogGetFunctionResult(PFCloudScriptGetFunctionResult const* result);
    static void LogListFunctionsRequest(PFCloudScriptListFunctionsRequest const* request, const char* testName);
    static HRESULT LogListFunctionsResult(PFCloudScriptListFunctionsResult const* result);
    static HRESULT LogListHttpFunctionsResult(PFCloudScriptListHttpFunctionsResult const* result);
    static HRESULT LogListQueuedFunctionsResult(PFCloudScriptListQueuedFunctionsResult const* result);
    static void LogPostFunctionResultForEntityTriggeredActionRequest(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest const* request, const char* testName);
    static void LogPostFunctionResultForFunctionExecutionRequest(PFCloudScriptPostFunctionResultForFunctionExecutionRequest const* request, const char* testName);
    static void LogPostFunctionResultForPlayerTriggeredActionRequest(PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest const* request, const char* testName);
    static void LogPostFunctionResultForScheduledTaskRequest(PFCloudScriptPostFunctionResultForScheduledTaskRequest const* request, const char* testName);
    static void LogRegisterHttpFunctionRequest(PFCloudScriptRegisterHttpFunctionRequest const* request, const char* testName);
    static void LogRegisterQueuedFunctionRequest(PFCloudScriptRegisterQueuedFunctionRequest const* request, const char* testName);
    static void LogUnregisterFunctionRequest(PFCloudScriptUnregisterFunctionRequest const* request, const char* testName);

    void FillAdminGetCloudScriptRevisionRequest(PlayFab::Wrappers::PFCloudScriptGetCloudScriptRevisionRequestWrapper<>& request);
    static HRESULT ValidateAdminGetCloudScriptRevisionResponse(PFCloudScriptGetCloudScriptRevisionResult* result);

    static HRESULT ValidateAdminGetCloudScriptVersionsResponse(PFCloudScriptGetCloudScriptVersionsResult* result);

    void FillAdminSetPublishedRevisionRequest(PlayFab::Wrappers::PFCloudScriptSetPublishedRevisionRequestWrapper<>& request);

    void FillAdminUpdateCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptUpdateCloudScriptRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateCloudScriptResponse(PFCloudScriptUpdateCloudScriptResult* result);

    void FillClientExecuteCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptExecuteCloudScriptRequestWrapper<>& request);
    static HRESULT ValidateClientExecuteCloudScriptResponse(PFExecuteCloudScriptResult* result);

    void FillServerExecuteCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptExecuteCloudScriptServerRequestWrapper<>& request);
    static HRESULT ValidateServerExecuteCloudScriptResponse(PFExecuteCloudScriptResult* result);

    void FillExecuteEntityCloudScriptRequest(PlayFab::Wrappers::PFCloudScriptExecuteEntityCloudScriptRequestWrapper<>& request);
    static HRESULT ValidateExecuteEntityCloudScriptResponse(PFExecuteCloudScriptResult* result);

    void FillExecuteFunctionRequest(PlayFab::Wrappers::PFCloudScriptExecuteFunctionRequestWrapper<>& request);
    static HRESULT ValidateExecuteFunctionResponse(PFCloudScriptExecuteFunctionResult* result);

    void FillGetFunctionRequest(PlayFab::Wrappers::PFCloudScriptGetFunctionRequestWrapper<>& request);
    static HRESULT ValidateGetFunctionResponse(PFCloudScriptGetFunctionResult* result);

    void FillListFunctionsRequest(PlayFab::Wrappers::PFCloudScriptListFunctionsRequestWrapper<>& request);
    static HRESULT ValidateListFunctionsResponse(PFCloudScriptListFunctionsResult* result);

    void FillListHttpFunctionsRequest(PlayFab::Wrappers::PFCloudScriptListFunctionsRequestWrapper<>& request);
    static HRESULT ValidateListHttpFunctionsResponse(PFCloudScriptListHttpFunctionsResult* result);

    void FillListQueuedFunctionsRequest(PlayFab::Wrappers::PFCloudScriptListFunctionsRequestWrapper<>& request);
    static HRESULT ValidateListQueuedFunctionsResponse(PFCloudScriptListQueuedFunctionsResult* result);

    void FillPostFunctionResultForEntityTriggeredActionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<>& request);

    void FillPostFunctionResultForFunctionExecutionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<>& request);

    void FillPostFunctionResultForPlayerTriggeredActionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper<>& request);

    void FillPostFunctionResultForScheduledTaskRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper<>& request);

    void FillRegisterHttpFunctionRequest(PlayFab::Wrappers::PFCloudScriptRegisterHttpFunctionRequestWrapper<>& request);

    void FillRegisterQueuedFunctionRequest(PlayFab::Wrappers::PFCloudScriptRegisterQueuedFunctionRequestWrapper<>& request);

    void FillUnregisterFunctionRequest(PlayFab::Wrappers::PFCloudScriptUnregisterFunctionRequestWrapper<>& request);

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
