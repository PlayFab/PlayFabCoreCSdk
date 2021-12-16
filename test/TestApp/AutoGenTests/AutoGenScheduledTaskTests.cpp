#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenScheduledTaskTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenScheduledTaskTests::ScheduledTaskTestData AutoGenScheduledTaskTests::testData;

void AutoGenScheduledTaskTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenScheduledTaskTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenScheduledTaskTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminAbortTaskInstance", &AutoGenScheduledTaskTests::TestScheduledTaskAdminAbortTaskInstance);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminCreateActionsOnPlayersInSegmentTask", &AutoGenScheduledTaskTests::TestScheduledTaskAdminCreateActionsOnPlayersInSegmentTask);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminCreateCloudScriptTask", &AutoGenScheduledTaskTests::TestScheduledTaskAdminCreateCloudScriptTask);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminCreateInsightsScheduledScalingTask", &AutoGenScheduledTaskTests::TestScheduledTaskAdminCreateInsightsScheduledScalingTask);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminDeleteTask", &AutoGenScheduledTaskTests::TestScheduledTaskAdminDeleteTask);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstance", &AutoGenScheduledTaskTests::TestScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstance);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminGetCloudScriptTaskInstance", &AutoGenScheduledTaskTests::TestScheduledTaskAdminGetCloudScriptTaskInstance);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminGetTaskInstances", &AutoGenScheduledTaskTests::TestScheduledTaskAdminGetTaskInstances);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminGetTasks", &AutoGenScheduledTaskTests::TestScheduledTaskAdminGetTasks);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminRunTask", &AutoGenScheduledTaskTests::TestScheduledTaskAdminRunTask);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestScheduledTaskAdminUpdateTask", &AutoGenScheduledTaskTests::TestScheduledTaskAdminUpdateTask);
#endif
}

void AutoGenScheduledTaskTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), nullptr, &stateHandle);
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

void AutoGenScheduledTaskTests::ClassTearDown()
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

void AutoGenScheduledTaskTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminAbortTaskInstance

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminAbortTaskInstance(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFScheduledTaskAbortTaskInstanceRequestWrapper<> request;
    FillAbortTaskInstanceRequest(request);
    LogAbortTaskInstanceRequest(&request.Model(), "TestScheduledTaskAdminAbortTaskInstance");
    HRESULT hr = PFScheduledTaskAdminAbortTaskInstanceAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminAbortTaskInstanceAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminCreateActionsOnPlayersInSegmentTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminCreateActionsOnPlayersInSegmentTask(TestContext& testContext)
{
    struct AdminCreateActionsOnPlayersInSegmentTaskResultHolderStruct : public CreateTaskResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskCreateTaskResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskCreateTaskResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreateActionsOnPlayersInSegmentTaskResultHolderStruct>>(testContext);

    PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper<> request;
    FillCreateActionsOnPlayerSegmentTaskRequest(request);
    LogCreateActionsOnPlayerSegmentTaskRequest(&request.Model(), "TestScheduledTaskAdminCreateActionsOnPlayersInSegmentTask");
    HRESULT hr = PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminCreateCloudScriptTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminCreateCloudScriptTask(TestContext& testContext)
{
    struct AdminCreateCloudScriptTaskResultHolderStruct : public CreateTaskResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminCreateCloudScriptTaskGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminCreateCloudScriptTaskGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskCreateTaskResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskCreateTaskResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreateCloudScriptTaskResultHolderStruct>>(testContext);

    PFScheduledTaskCreateCloudScriptTaskRequestWrapper<> request;
    FillCreateCloudScriptTaskRequest(request);
    LogCreateCloudScriptTaskRequest(&request.Model(), "TestScheduledTaskAdminCreateCloudScriptTask");
    HRESULT hr = PFScheduledTaskAdminCreateCloudScriptTaskAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminCreateCloudScriptTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminCreateInsightsScheduledScalingTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminCreateInsightsScheduledScalingTask(TestContext& testContext)
{
    struct AdminCreateInsightsScheduledScalingTaskResultHolderStruct : public CreateTaskResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskCreateTaskResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskCreateTaskResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreateInsightsScheduledScalingTaskResultHolderStruct>>(testContext);

    PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper<> request;
    FillCreateInsightsScheduledScalingTaskRequest(request);
    LogCreateInsightsScheduledScalingTaskRequest(&request.Model(), "TestScheduledTaskAdminCreateInsightsScheduledScalingTask");
    HRESULT hr = PFScheduledTaskAdminCreateInsightsScheduledScalingTaskAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminCreateInsightsScheduledScalingTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminDeleteTask(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFScheduledTaskDeleteTaskRequestWrapper<> request;
    FillDeleteTaskRequest(request);
    LogDeleteTaskRequest(&request.Model(), "TestScheduledTaskAdminDeleteTask");
    HRESULT hr = PFScheduledTaskAdminDeleteTaskAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminDeleteTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetActionsOnPlayersInSegmentTaskInstance

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstance(TestContext& testContext)
{
    struct AdminGetActionsOnPlayersInSegmentTaskInstanceResultHolderStruct : public GetActionsOnPlayersInSegmentTaskInstanceResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetActionsOnPlayersInSegmentTaskInstanceResultHolderStruct>>(testContext);

    PFScheduledTaskGetTaskInstanceRequestWrapper<> request;
    FillGetTaskInstanceRequest(request);
    LogGetTaskInstanceRequest(&request.Model(), "TestScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstance");
    HRESULT hr = PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetCloudScriptTaskInstance

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminGetCloudScriptTaskInstance(TestContext& testContext)
{
    struct AdminGetCloudScriptTaskInstanceResultHolderStruct : public GetCloudScriptTaskInstanceResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskGetCloudScriptTaskInstanceResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskGetCloudScriptTaskInstanceResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCloudScriptTaskInstanceResultHolderStruct>>(testContext);

    PFScheduledTaskGetTaskInstanceRequestWrapper<> request;
    FillGetTaskInstanceRequest(request);
    LogGetTaskInstanceRequest(&request.Model(), "TestScheduledTaskAdminGetCloudScriptTaskInstance");
    HRESULT hr = PFScheduledTaskAdminGetCloudScriptTaskInstanceAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminGetCloudScriptTaskInstanceAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetTaskInstances

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminGetTaskInstances(TestContext& testContext)
{
    struct AdminGetTaskInstancesResultHolderStruct : public GetTaskInstancesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetTaskInstancesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetTaskInstancesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskGetTaskInstancesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskGetTaskInstancesResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetTaskInstancesResultHolderStruct>>(testContext);

    PFScheduledTaskGetTaskInstancesRequestWrapper<> request;
    FillGetTaskInstancesRequest(request);
    LogGetTaskInstancesRequest(&request.Model(), "TestScheduledTaskAdminGetTaskInstances");
    HRESULT hr = PFScheduledTaskAdminGetTaskInstancesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminGetTaskInstancesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetTasks

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminGetTasks(TestContext& testContext)
{
    struct AdminGetTasksResultHolderStruct : public GetTasksResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetTasksGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminGetTasksGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskGetTasksResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskGetTasksResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetTasksResultHolderStruct>>(testContext);

    PFScheduledTaskGetTasksRequestWrapper<> request;
    FillGetTasksRequest(request);
    LogGetTasksRequest(&request.Model(), "TestScheduledTaskAdminGetTasks");
    HRESULT hr = PFScheduledTaskAdminGetTasksAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminGetTasksAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRunTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminRunTask(TestContext& testContext)
{
    struct AdminRunTaskResultHolderStruct : public RunTaskResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminRunTaskGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFScheduledTaskAdminRunTaskGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFScheduledTaskRunTaskResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFScheduledTaskRunTaskResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRunTaskResultHolderStruct>>(testContext);

    PFScheduledTaskRunTaskRequestWrapper<> request;
    FillRunTaskRequest(request);
    LogRunTaskRequest(&request.Model(), "TestScheduledTaskAdminRunTask");
    HRESULT hr = PFScheduledTaskAdminRunTaskAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminRunTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateTask

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenScheduledTaskTests::TestScheduledTaskAdminUpdateTask(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFScheduledTaskUpdateTaskRequestWrapper<> request;
    FillUpdateTaskRequest(request);
    LogUpdateTaskRequest(&request.Model(), "TestScheduledTaskAdminUpdateTask");
    HRESULT hr = PFScheduledTaskAdminUpdateTaskAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFScheduledTaskScheduledTaskAdminUpdateTaskAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
