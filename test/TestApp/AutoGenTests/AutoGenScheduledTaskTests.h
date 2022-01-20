#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFScheduledTaskDataModelWrappers.h>
#include "AutoGenScheduledTaskResultHolders.h"

namespace PlayFabUnit
{

class AutoGenScheduledTaskTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminAbortTaskInstance(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminCreateActionsOnPlayersInSegmentTask(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminCreateCloudScriptTask(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminCreateInsightsScheduledScalingTask(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminDeleteTask(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstance(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminGetCloudScriptTaskInstance(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminGetTaskInstances(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminGetTasks(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminRunTask(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestScheduledTaskAdminUpdateTask(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogAbortTaskInstanceRequest(PFScheduledTaskAbortTaskInstanceRequest const* request, const char* testName);
    static void LogCreateActionsOnPlayerSegmentTaskRequest(PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest const* request, const char* testName);
    static HRESULT LogCreateTaskResult(PFScheduledTaskCreateTaskResult const* result);
    static void LogCreateCloudScriptTaskRequest(PFScheduledTaskCreateCloudScriptTaskRequest const* request, const char* testName);
    static void LogCreateInsightsScheduledScalingTaskRequest(PFScheduledTaskCreateInsightsScheduledScalingTaskRequest const* request, const char* testName);
    static void LogDeleteTaskRequest(PFScheduledTaskDeleteTaskRequest const* request, const char* testName);
    static void LogGetTaskInstanceRequest(PFScheduledTaskGetTaskInstanceRequest const* request, const char* testName);
    static HRESULT LogGetActionsOnPlayersInSegmentTaskInstanceResult(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult const* result);
    static HRESULT LogGetCloudScriptTaskInstanceResult(PFScheduledTaskGetCloudScriptTaskInstanceResult const* result);
    static void LogGetTaskInstancesRequest(PFScheduledTaskGetTaskInstancesRequest const* request, const char* testName);
    static HRESULT LogGetTaskInstancesResult(PFScheduledTaskGetTaskInstancesResult const* result);
    static void LogGetTasksRequest(PFScheduledTaskGetTasksRequest const* request, const char* testName);
    static HRESULT LogGetTasksResult(PFScheduledTaskGetTasksResult const* result);
    static void LogRunTaskRequest(PFScheduledTaskRunTaskRequest const* request, const char* testName);
    static HRESULT LogRunTaskResult(PFScheduledTaskRunTaskResult const* result);
    static void LogUpdateTaskRequest(PFScheduledTaskUpdateTaskRequest const* request, const char* testName);

    static void FillAdminAbortTaskInstanceRequest(PlayFab::Wrappers::PFScheduledTaskAbortTaskInstanceRequestWrapper<>& request);

    static void FillAdminCreateActionsOnPlayersInSegmentTaskRequest(PlayFab::Wrappers::PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper<>& request);
    static HRESULT ValidateAdminCreateActionsOnPlayersInSegmentTaskResponse(PFScheduledTaskCreateTaskResult* result);

    static void FillAdminCreateCloudScriptTaskRequest(PlayFab::Wrappers::PFScheduledTaskCreateCloudScriptTaskRequestWrapper<>& request);
    static HRESULT ValidateAdminCreateCloudScriptTaskResponse(PFScheduledTaskCreateTaskResult* result);

    static void FillAdminCreateInsightsScheduledScalingTaskRequest(PlayFab::Wrappers::PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper<>& request);
    static HRESULT ValidateAdminCreateInsightsScheduledScalingTaskResponse(PFScheduledTaskCreateTaskResult* result);

    static void FillAdminDeleteTaskRequest(PlayFab::Wrappers::PFScheduledTaskDeleteTaskRequestWrapper<>& request);

    static void FillAdminGetActionsOnPlayersInSegmentTaskInstanceRequest(PlayFab::Wrappers::PFScheduledTaskGetTaskInstanceRequestWrapper<>& request);
    static HRESULT ValidateAdminGetActionsOnPlayersInSegmentTaskInstanceResponse(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult* result);

    static void FillAdminGetCloudScriptTaskInstanceRequest(PlayFab::Wrappers::PFScheduledTaskGetTaskInstanceRequestWrapper<>& request);
    static HRESULT ValidateAdminGetCloudScriptTaskInstanceResponse(PFScheduledTaskGetCloudScriptTaskInstanceResult* result);

    static void FillAdminGetTaskInstancesRequest(PlayFab::Wrappers::PFScheduledTaskGetTaskInstancesRequestWrapper<>& request);
    static HRESULT ValidateAdminGetTaskInstancesResponse(PFScheduledTaskGetTaskInstancesResult* result);

    static void FillAdminGetTasksRequest(PlayFab::Wrappers::PFScheduledTaskGetTasksRequestWrapper<>& request);
    static HRESULT ValidateAdminGetTasksResponse(PFScheduledTaskGetTasksResult* result);

    static void FillAdminRunTaskRequest(PlayFab::Wrappers::PFScheduledTaskRunTaskRequestWrapper<>& request);
    static HRESULT ValidateAdminRunTaskResponse(PFScheduledTaskRunTaskResult* result);

    static void FillAdminUpdateTaskRequest(PlayFab::Wrappers::PFScheduledTaskUpdateTaskRequestWrapper<>& request);

    struct ScheduledTaskTestData
    {
        ~ScheduledTaskTestData() = default;

    };

    static ScheduledTaskTestData testData;

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
