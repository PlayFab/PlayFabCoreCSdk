#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCloudScriptTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenCloudScriptTests::CloudScriptTestData AutoGenCloudScriptTests::testData;

void AutoGenCloudScriptTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenCloudScriptTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenCloudScriptTests::AddTests()
{
    // Generated tests 
    AddTest("TestCloudScriptExecuteFunction", &AutoGenCloudScriptTests::TestCloudScriptExecuteFunction);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptPostFunctionResultForEntityTriggeredAction", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForEntityTriggeredAction);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptPostFunctionResultForFunctionExecution", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForFunctionExecution);
#endif
}

void AutoGenCloudScriptTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), testTitleData.connectionString.data(), nullptr, &stateHandle);
    assert(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        PFAuthenticationLoginWithCustomIDRequest request{};
        request.customId = "CustomId";
        request.createAccount = true;

        PFGetPlayerCombinedInfoRequestParams combinedInfoRequestParams{};
        combinedInfoRequestParams.getCharacterInventories = true;
        combinedInfoRequestParams.getCharacterList = true;
        combinedInfoRequestParams.getPlayerProfile = true;
        combinedInfoRequestParams.getPlayerStatistics = true;
        combinedInfoRequestParams.getTitleData = true;
        combinedInfoRequestParams.getUserAccountInfo = true;
        combinedInfoRequestParams.getUserData = true;
        combinedInfoRequestParams.getUserInventory = true;
        combinedInfoRequestParams.getUserReadOnlyData = true;
        combinedInfoRequestParams.getUserVirtualCurrency = true;
        request.infoRequestParameters = &combinedInfoRequestParams;

        XAsyncBlock async{};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle);
                assert(SUCCEEDED(hr) && titlePlayerHandle);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle, &entityHandle);
                assert(SUCCEEDED(hr) && entityHandle);
            }
        }

        request.customId = "CustomId2";
        async = {};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously what for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle2);
                assert(SUCCEEDED(hr) && titlePlayerHandle2);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle2, &entityHandle2);
                assert(SUCCEEDED(hr) && entityHandle2);
            }
        }

        PFAuthenticationGetEntityTokenRequest titleTokenRequest{};
        async = {};
        hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &titleTokenRequest, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationGetEntityTokenGetResult(&async, &titleEntityHandle);
                assert(SUCCEEDED(hr));
            }
        }
    }
}

void AutoGenCloudScriptTests::ClassTearDown()
{
    PFTitlePlayerCloseHandle(titlePlayerHandle);
    PFEntityCloseHandle(entityHandle);
    PFEntityCloseHandle(titleEntityHandle);

    XAsyncBlock async{};
    HRESULT hr = PFUninitializeAsync(stateHandle, &async);
    assert(SUCCEEDED(hr));

    hr = XAsyncGetStatus(&async, true);
    assert(SUCCEEDED(hr));

    UNREFERENCED_PARAMETER(hr);
}

void AutoGenCloudScriptTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ExecuteFunction

void AutoGenCloudScriptTests::TestCloudScriptExecuteFunction(TestContext& testContext)
{
    struct ExecuteFunctionResultHolderStruct : public ExecuteFunctionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteFunctionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteFunctionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogExecuteFunctionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateExecuteFunctionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ExecuteFunctionResultHolderStruct>>(testContext);

    PFCloudScriptExecuteFunctionRequestWrapper<> request;
    FillExecuteFunctionRequest(request);
    LogExecuteFunctionRequest(&request.Model(), "TestCloudScriptExecuteFunction");
    HRESULT hr = PFCloudScriptExecuteFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptExecuteFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PostFunctionResultForEntityTriggeredAction

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForEntityTriggeredAction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<> request;
    FillPostFunctionResultForEntityTriggeredActionRequest(request);
    LogPostFunctionResultForEntityTriggeredActionRequest(&request.Model(), "TestCloudScriptPostFunctionResultForEntityTriggeredAction");
    HRESULT hr = PFCloudScriptPostFunctionResultForEntityTriggeredActionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForEntityTriggeredActionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region PostFunctionResultForFunctionExecution

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForFunctionExecution(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<> request;
    FillPostFunctionResultForFunctionExecutionRequest(request);
    LogPostFunctionResultForFunctionExecutionRequest(&request.Model(), "TestCloudScriptPostFunctionResultForFunctionExecution");
    HRESULT hr = PFCloudScriptPostFunctionResultForFunctionExecutionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForFunctionExecutionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
