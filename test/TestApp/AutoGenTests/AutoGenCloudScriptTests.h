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

    void TestCloudScriptExecuteFunction(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptPostFunctionResultForEntityTriggeredAction(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestCloudScriptPostFunctionResultForFunctionExecution(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogExecuteFunctionRequest(PFCloudScriptExecuteFunctionRequest const* request, const char* testName);
    static HRESULT LogExecuteFunctionResult(PFCloudScriptExecuteFunctionResult const* result);
    static void LogPostFunctionResultForEntityTriggeredActionRequest(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest const* request, const char* testName);
    static void LogPostFunctionResultForFunctionExecutionRequest(PFCloudScriptPostFunctionResultForFunctionExecutionRequest const* request, const char* testName);

    static void FillExecuteFunctionRequest(PlayFab::Wrappers::PFCloudScriptExecuteFunctionRequestWrapper<>& request);
    static HRESULT ValidateExecuteFunctionResponse(PFCloudScriptExecuteFunctionResult* result);

    static void FillPostFunctionResultForEntityTriggeredActionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<>& request);

    static void FillPostFunctionResultForFunctionExecutionRequest(PlayFab::Wrappers::PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<>& request);

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
