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
    static void FillAbortTaskInstanceRequest(PlayFab::Wrappers::PFScheduledTaskAbortTaskInstanceRequestWrapper<>& request);

    static void LogCreateActionsOnPlayerSegmentTaskRequest(PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest const* request, const char* testName);
    static void FillCreateActionsOnPlayerSegmentTaskRequest(PlayFab::Wrappers::PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper<>& request);
    static HRESULT LogPFScheduledTaskCreateTaskResult(PFScheduledTaskCreateTaskResult const* result);
    static HRESULT ValidatePFScheduledTaskCreateTaskResult(PFScheduledTaskCreateTaskResult* result);

    static void LogCreateCloudScriptTaskRequest(PFScheduledTaskCreateCloudScriptTaskRequest const* request, const char* testName);
    static void FillCreateCloudScriptTaskRequest(PlayFab::Wrappers::PFScheduledTaskCreateCloudScriptTaskRequestWrapper<>& request);

    static void LogCreateInsightsScheduledScalingTaskRequest(PFScheduledTaskCreateInsightsScheduledScalingTaskRequest const* request, const char* testName);
    static void FillCreateInsightsScheduledScalingTaskRequest(PlayFab::Wrappers::PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper<>& request);

    static void LogDeleteTaskRequest(PFScheduledTaskDeleteTaskRequest const* request, const char* testName);
    static void FillDeleteTaskRequest(PlayFab::Wrappers::PFScheduledTaskDeleteTaskRequestWrapper<>& request);

    static void LogGetTaskInstanceRequest(PFScheduledTaskGetTaskInstanceRequest const* request, const char* testName);
    static void FillGetTaskInstanceRequest(PlayFab::Wrappers::PFScheduledTaskGetTaskInstanceRequestWrapper<>& request);
    static HRESULT LogPFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult const* result);
    static HRESULT ValidatePFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult* result);

    static HRESULT LogPFScheduledTaskGetCloudScriptTaskInstanceResult(PFScheduledTaskGetCloudScriptTaskInstanceResult const* result);
    static HRESULT ValidatePFScheduledTaskGetCloudScriptTaskInstanceResult(PFScheduledTaskGetCloudScriptTaskInstanceResult* result);

    static void LogGetTaskInstancesRequest(PFScheduledTaskGetTaskInstancesRequest const* request, const char* testName);
    static void FillGetTaskInstancesRequest(PlayFab::Wrappers::PFScheduledTaskGetTaskInstancesRequestWrapper<>& request);
    static HRESULT LogPFScheduledTaskGetTaskInstancesResult(PFScheduledTaskGetTaskInstancesResult const* result);
    static HRESULT ValidatePFScheduledTaskGetTaskInstancesResult(PFScheduledTaskGetTaskInstancesResult* result);

    static void LogGetTasksRequest(PFScheduledTaskGetTasksRequest const* request, const char* testName);
    static void FillGetTasksRequest(PlayFab::Wrappers::PFScheduledTaskGetTasksRequestWrapper<>& request);
    static HRESULT LogPFScheduledTaskGetTasksResult(PFScheduledTaskGetTasksResult const* result);
    static HRESULT ValidatePFScheduledTaskGetTasksResult(PFScheduledTaskGetTasksResult* result);

    static void LogRunTaskRequest(PFScheduledTaskRunTaskRequest const* request, const char* testName);
    static void FillRunTaskRequest(PlayFab::Wrappers::PFScheduledTaskRunTaskRequestWrapper<>& request);
    static HRESULT LogPFScheduledTaskRunTaskResult(PFScheduledTaskRunTaskResult const* result);
    static HRESULT ValidatePFScheduledTaskRunTaskResult(PFScheduledTaskRunTaskResult* result);

    static void LogUpdateTaskRequest(PFScheduledTaskUpdateTaskRequest const* request, const char* testName);
    static void FillUpdateTaskRequest(PlayFab::Wrappers::PFScheduledTaskUpdateTaskRequestWrapper<>& request);

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
