#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenScheduledTaskTests.h"
#include "XAsyncHelper.h"

uint32_t g_ScheduledTaskTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenScheduledTaskTests::LogAbortTaskInstanceRequest(PFScheduledTaskAbortTaskInstanceRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskAbortTaskInstanceRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->taskInstanceId ) { ss << "  taskInstanceId " << request->taskInstanceId; Log(ss); } else { ss << "  taskInstanceId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenScheduledTaskTests::LogCreateActionsOnPlayerSegmentTaskRequest(PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskCreateActionsOnPlayerSegmentTaskRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    ss << "  isActive " << request->isActive; Log(ss); // Class: bool 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    ss << "  parameter " << request->parameter; Log(ss); // Class: PFScheduledTaskActionsOnPlayersInSegmentTaskParameter 
    if( request->schedule ) { ss << "  schedule " << request->schedule; Log(ss); } else { ss << "  schedule = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenScheduledTaskTests::LogPFScheduledTaskCreateTaskResult(PFScheduledTaskCreateTaskResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabScheduledTaskCreateTaskResult
    if( result->taskId ) { ss << "  taskId " << result->taskId; Log(ss); } else { ss << "  taskId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenScheduledTaskTests::LogCreateCloudScriptTaskRequest(PFScheduledTaskCreateCloudScriptTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskCreateCloudScriptTaskRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    ss << "  isActive " << request->isActive; Log(ss); // Class: bool 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    ss << "  parameter " << request->parameter; Log(ss); // Class: PFScheduledTaskCloudScriptTaskParameter 
    if( request->schedule ) { ss << "  schedule " << request->schedule; Log(ss); } else { ss << "  schedule = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenScheduledTaskTests::LogCreateInsightsScheduledScalingTaskRequest(PFScheduledTaskCreateInsightsScheduledScalingTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskCreateInsightsScheduledScalingTaskRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    ss << "  isActive " << request->isActive; Log(ss); // Class: bool 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    ss << "  parameter " << request->parameter; Log(ss); // Class: PFScheduledTaskInsightsScalingTaskParameter 
    if( request->schedule ) { ss << "  schedule " << request->schedule; Log(ss); } else { ss << "  schedule = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenScheduledTaskTests::LogDeleteTaskRequest(PFScheduledTaskDeleteTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskDeleteTaskRequest struct:
    // request->identifier: PFNameIdentifier const*
    ss << "  identifier " << request->identifier; Log(ss); // Class: PFNameIdentifier 

}

void AutoGenScheduledTaskTests::LogGetTaskInstanceRequest(PFScheduledTaskGetTaskInstanceRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskGetTaskInstanceRequest struct:
    // request->taskInstanceId: const char*
    if( request->taskInstanceId ) { ss << "  taskInstanceId " << request->taskInstanceId; Log(ss); } else { ss << "  taskInstanceId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenScheduledTaskTests::LogPFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult(PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult
    ss << "  parameter " << result->parameter; Log(ss); // Class: PFScheduledTaskActionsOnPlayersInSegmentTaskParameter 
    ss << "  summary " << result->summary; Log(ss); // Class: PFScheduledTaskActionsOnPlayersInSegmentTaskSummary 
    return S_OK;
}

HRESULT AutoGenScheduledTaskTests::LogPFScheduledTaskGetCloudScriptTaskInstanceResult(PFScheduledTaskGetCloudScriptTaskInstanceResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabScheduledTaskGetCloudScriptTaskInstanceResult
    ss << "  parameter " << result->parameter; Log(ss); // Class: PFScheduledTaskCloudScriptTaskParameter 
    ss << "  summary " << result->summary; Log(ss); // Class: PFScheduledTaskCloudScriptTaskSummary 
    return S_OK;
}

void AutoGenScheduledTaskTests::LogGetTaskInstancesRequest(PFScheduledTaskGetTaskInstancesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskGetTaskInstancesRequest struct:
    // request->startedAtRangeFrom: time_t const*
    ss << "  startedAtRangeFrom " << request->startedAtRangeFrom; Log(ss); // Class: time_t 
    ss << "  startedAtRangeTo " << request->startedAtRangeTo; Log(ss); // Class: time_t 
    ss << "  statusFilter " << request->statusFilter; Log(ss); // Class: PFScheduledTaskTaskInstanceStatus 
    ss << "  taskIdentifier " << request->taskIdentifier; Log(ss); // Class: PFNameIdentifier 

}

HRESULT AutoGenScheduledTaskTests::LogPFScheduledTaskGetTaskInstancesResult(PFScheduledTaskGetTaskInstancesResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabScheduledTaskGetTaskInstancesResult    
    ss << "  summariesCount " << result->summariesCount; Log(ss);

    // PFScheduledTaskTaskInstanceBasicSummary
    for( uint32_t i=0; i<result->summariesCount; i++ )
    {
            ss << "  result->summaries[" << i << "]:" << result->summaries[i]; Log(ss); // PFScheduledTaskTaskInstanceBasicSummary
    } 
    return S_OK;
}

void AutoGenScheduledTaskTests::LogGetTasksRequest(PFScheduledTaskGetTasksRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskGetTasksRequest struct:
    // request->identifier: PFNameIdentifier const*
    ss << "  identifier " << request->identifier; Log(ss); // Class: PFNameIdentifier 

}

HRESULT AutoGenScheduledTaskTests::LogPFScheduledTaskGetTasksResult(PFScheduledTaskGetTasksResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabScheduledTaskGetTasksResult    
    ss << "  tasksCount " << result->tasksCount; Log(ss);

    // PFScheduledTaskScheduledTask
    for( uint32_t i=0; i<result->tasksCount; i++ )
    {
            ss << "  result->tasks[" << i << "]:" << result->tasks[i]; Log(ss); // PFScheduledTaskScheduledTask
    } 
    return S_OK;
}

void AutoGenScheduledTaskTests::LogRunTaskRequest(PFScheduledTaskRunTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskRunTaskRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  identifier " << request->identifier; Log(ss); // Class: PFNameIdentifier 

}

HRESULT AutoGenScheduledTaskTests::LogPFScheduledTaskRunTaskResult(PFScheduledTaskRunTaskResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabScheduledTaskRunTaskResult
    if( result->taskInstanceId ) { ss << "  taskInstanceId " << result->taskInstanceId; Log(ss); } else { ss << "  taskInstanceId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenScheduledTaskTests::LogUpdateTaskRequest(PFScheduledTaskUpdateTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ScheduledTaskTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabScheduledTaskUpdateTaskRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    ss << "  identifier " << request->identifier; Log(ss); // Class: PFNameIdentifier 
    ss << "  isActive " << request->isActive; Log(ss); // Class: bool 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    if( request->parameter.stringValue ) { ss << "  parameter " << request->parameter.stringValue; Log(ss); } else { ss << "  parameter = nullptr"; Log(ss); } // Class: PFJsonObject 
    if( request->schedule ) { ss << "  schedule " << request->schedule; Log(ss); } else { ss << "  schedule = nullptr"; Log(ss); } // Class: const char* 
    ss << "  type " << request->type; Log(ss); // Class: PFScheduledTaskScheduledTaskType 

}

 

}
