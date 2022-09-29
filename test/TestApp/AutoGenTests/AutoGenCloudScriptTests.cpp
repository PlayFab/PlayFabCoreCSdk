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
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptAdminGetCloudScriptRevision", &AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptRevision);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptAdminGetCloudScriptVersions", &AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptVersions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptAdminSetPublishedRevision", &AutoGenCloudScriptTests::TestCloudScriptAdminSetPublishedRevision);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptAdminUpdateCloudScript", &AutoGenCloudScriptTests::TestCloudScriptAdminUpdateCloudScript);
#endif

    AddTest("TestCloudScriptClientExecuteCloudScript", &AutoGenCloudScriptTests::TestCloudScriptClientExecuteCloudScript);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptServerExecuteCloudScript", &AutoGenCloudScriptTests::TestCloudScriptServerExecuteCloudScript);
#endif

    AddTest("TestCloudScriptExecuteEntityCloudScript", &AutoGenCloudScriptTests::TestCloudScriptExecuteEntityCloudScript);

    AddTest("TestCloudScriptExecuteFunction", &AutoGenCloudScriptTests::TestCloudScriptExecuteFunction);

    AddTest("TestCloudScriptGetFunction", &AutoGenCloudScriptTests::TestCloudScriptGetFunction);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptListFunctions", &AutoGenCloudScriptTests::TestCloudScriptListFunctions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptListHttpFunctions", &AutoGenCloudScriptTests::TestCloudScriptListHttpFunctions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptListQueuedFunctions", &AutoGenCloudScriptTests::TestCloudScriptListQueuedFunctions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptPostFunctionResultForEntityTriggeredAction", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForEntityTriggeredAction);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptPostFunctionResultForFunctionExecution", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForFunctionExecution);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptPostFunctionResultForPlayerTriggeredAction", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForPlayerTriggeredAction);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptPostFunctionResultForScheduledTask", &AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForScheduledTask);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptRegisterHttpFunction", &AutoGenCloudScriptTests::TestCloudScriptRegisterHttpFunction);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptRegisterQueuedFunction", &AutoGenCloudScriptTests::TestCloudScriptRegisterQueuedFunction);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCloudScriptUnregisterFunction", &AutoGenCloudScriptTests::TestCloudScriptUnregisterFunction);
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

#pragma region AdminGetCloudScriptRevision

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptRevision(TestContext& testContext)
{
    struct AdminGetCloudScriptRevisionResultHolderStruct : public GetCloudScriptRevisionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptRevisionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptRevisionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCloudScriptRevisionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetCloudScriptRevisionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCloudScriptRevisionResultHolderStruct>>(testContext);

    PFCloudScriptGetCloudScriptRevisionRequestWrapper<> request;
    FillAdminGetCloudScriptRevisionRequest(request);
    LogGetCloudScriptRevisionRequest(&request.Model(), "TestCloudScriptAdminGetCloudScriptRevision");
    HRESULT hr = PFCloudScriptAdminGetCloudScriptRevisionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminGetCloudScriptRevisionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetCloudScriptVersions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptAdminGetCloudScriptVersions(TestContext& testContext)
{
    struct AdminGetCloudScriptVersionsResultHolderStruct : public GetCloudScriptVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminGetCloudScriptVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCloudScriptVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetCloudScriptVersionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCloudScriptVersionsResultHolderStruct>>(testContext);

    HRESULT hr = PFCloudScriptAdminGetCloudScriptVersionsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminGetCloudScriptVersionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetPublishedRevision

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptAdminSetPublishedRevision(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptSetPublishedRevisionRequestWrapper<> request;
    FillAdminSetPublishedRevisionRequest(request);
    LogSetPublishedRevisionRequest(&request.Model(), "TestCloudScriptAdminSetPublishedRevision");
    HRESULT hr = PFCloudScriptAdminSetPublishedRevisionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminSetPublishedRevisionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateCloudScript

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptAdminUpdateCloudScript(TestContext& testContext)
{
    struct AdminUpdateCloudScriptResultHolderStruct : public UpdateCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCloudScriptAdminUpdateCloudScriptGetResult(async, &result)));
            LogUpdateCloudScriptResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateCloudScriptResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateCloudScriptResultHolderStruct>>(testContext);

    PFCloudScriptUpdateCloudScriptRequestWrapper<> request;
    FillAdminUpdateCloudScriptRequest(request);
    LogUpdateCloudScriptRequest(&request.Model(), "TestCloudScriptAdminUpdateCloudScript");
    HRESULT hr = PFCloudScriptAdminUpdateCloudScriptAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptAdminUpdateCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientExecuteCloudScript

void AutoGenCloudScriptTests::TestCloudScriptClientExecuteCloudScript(TestContext& testContext)
{
    struct ClientExecuteCloudScriptResultHolderStruct : public ExecuteCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptClientExecuteCloudScriptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptClientExecuteCloudScriptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogExecuteCloudScriptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientExecuteCloudScriptResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientExecuteCloudScriptResultHolderStruct>>(testContext);

    PFCloudScriptExecuteCloudScriptRequestWrapper<> request;
    FillClientExecuteCloudScriptRequest(request);
    LogExecuteCloudScriptRequest(&request.Model(), "TestCloudScriptClientExecuteCloudScript");
    HRESULT hr = PFCloudScriptClientExecuteCloudScriptAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptClientExecuteCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerExecuteCloudScript

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptServerExecuteCloudScript(TestContext& testContext)
{
    struct ServerExecuteCloudScriptResultHolderStruct : public ExecuteCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptServerExecuteCloudScriptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptServerExecuteCloudScriptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogExecuteCloudScriptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerExecuteCloudScriptResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerExecuteCloudScriptResultHolderStruct>>(testContext);

    PFCloudScriptExecuteCloudScriptServerRequestWrapper<> request;
    FillServerExecuteCloudScriptRequest(request);
    LogExecuteCloudScriptServerRequest(&request.Model(), "TestCloudScriptServerExecuteCloudScript");
    HRESULT hr = PFCloudScriptServerExecuteCloudScriptAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptServerExecuteCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ExecuteEntityCloudScript

void AutoGenCloudScriptTests::TestCloudScriptExecuteEntityCloudScript(TestContext& testContext)
{
    struct ExecuteEntityCloudScriptResultHolderStruct : public ExecuteCloudScriptResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteEntityCloudScriptGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptExecuteEntityCloudScriptGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogExecuteCloudScriptResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateExecuteEntityCloudScriptResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ExecuteEntityCloudScriptResultHolderStruct>>(testContext);

    PFCloudScriptExecuteEntityCloudScriptRequestWrapper<> request;
    FillExecuteEntityCloudScriptRequest(request);
    LogExecuteEntityCloudScriptRequest(&request.Model(), "TestCloudScriptExecuteEntityCloudScript");
    HRESULT hr = PFCloudScriptExecuteEntityCloudScriptAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptExecuteEntityCloudScriptAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

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

#pragma region GetFunction

void AutoGenCloudScriptTests::TestCloudScriptGetFunction(TestContext& testContext)
{
    struct GetFunctionResultHolderStruct : public GetFunctionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptGetFunctionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptGetFunctionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetFunctionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetFunctionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetFunctionResultHolderStruct>>(testContext);

    PFCloudScriptGetFunctionRequestWrapper<> request;
    FillGetFunctionRequest(request);
    LogGetFunctionRequest(&request.Model(), "TestCloudScriptGetFunction");
    HRESULT hr = PFCloudScriptGetFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptGetFunctionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListFunctions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptListFunctions(TestContext& testContext)
{
    struct ListFunctionsResultHolderStruct : public ListFunctionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptListFunctionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptListFunctionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListFunctionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListFunctionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListFunctionsResultHolderStruct>>(testContext);

    PFCloudScriptListFunctionsRequestWrapper<> request;
    FillListFunctionsRequest(request);
    LogListFunctionsRequest(&request.Model(), "TestCloudScriptListFunctions");
    HRESULT hr = PFCloudScriptListFunctionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptListFunctionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListHttpFunctions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptListHttpFunctions(TestContext& testContext)
{
    struct ListHttpFunctionsResultHolderStruct : public ListHttpFunctionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptListHttpFunctionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptListHttpFunctionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListHttpFunctionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListHttpFunctionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListHttpFunctionsResultHolderStruct>>(testContext);

    PFCloudScriptListFunctionsRequestWrapper<> request;
    FillListHttpFunctionsRequest(request);
    LogListFunctionsRequest(&request.Model(), "TestCloudScriptListHttpFunctions");
    HRESULT hr = PFCloudScriptListHttpFunctionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptListHttpFunctionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListQueuedFunctions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptListQueuedFunctions(TestContext& testContext)
{
    struct ListQueuedFunctionsResultHolderStruct : public ListQueuedFunctionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCloudScriptListQueuedFunctionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCloudScriptListQueuedFunctionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListQueuedFunctionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListQueuedFunctionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListQueuedFunctionsResultHolderStruct>>(testContext);

    PFCloudScriptListFunctionsRequestWrapper<> request;
    FillListQueuedFunctionsRequest(request);
    LogListFunctionsRequest(&request.Model(), "TestCloudScriptListQueuedFunctions");
    HRESULT hr = PFCloudScriptListQueuedFunctionsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptListQueuedFunctionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

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

#pragma region PostFunctionResultForPlayerTriggeredAction

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForPlayerTriggeredAction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper<> request;
    FillPostFunctionResultForPlayerTriggeredActionRequest(request);
    LogPostFunctionResultForPlayerTriggeredActionRequest(&request.Model(), "TestCloudScriptPostFunctionResultForPlayerTriggeredAction");
    HRESULT hr = PFCloudScriptPostFunctionResultForPlayerTriggeredActionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForPlayerTriggeredActionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region PostFunctionResultForScheduledTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptPostFunctionResultForScheduledTask(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper<> request;
    FillPostFunctionResultForScheduledTaskRequest(request);
    LogPostFunctionResultForScheduledTaskRequest(&request.Model(), "TestCloudScriptPostFunctionResultForScheduledTask");
    HRESULT hr = PFCloudScriptPostFunctionResultForScheduledTaskAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptPostFunctionResultForScheduledTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region RegisterHttpFunction

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptRegisterHttpFunction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptRegisterHttpFunctionRequestWrapper<> request;
    FillRegisterHttpFunctionRequest(request);
    LogRegisterHttpFunctionRequest(&request.Model(), "TestCloudScriptRegisterHttpFunction");
    HRESULT hr = PFCloudScriptRegisterHttpFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptRegisterHttpFunctionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region RegisterQueuedFunction

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptRegisterQueuedFunction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptRegisterQueuedFunctionRequestWrapper<> request;
    FillRegisterQueuedFunctionRequest(request);
    LogRegisterQueuedFunctionRequest(&request.Model(), "TestCloudScriptRegisterQueuedFunction");
    HRESULT hr = PFCloudScriptRegisterQueuedFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptRegisterQueuedFunctionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region UnregisterFunction

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCloudScriptTests::TestCloudScriptUnregisterFunction(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCloudScriptUnregisterFunctionRequestWrapper<> request;
    FillUnregisterFunctionRequest(request);
    LogUnregisterFunctionRequest(&request.Model(), "TestCloudScriptUnregisterFunction");
    HRESULT hr = PFCloudScriptUnregisterFunctionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCloudScriptCloudScriptUnregisterFunctionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
