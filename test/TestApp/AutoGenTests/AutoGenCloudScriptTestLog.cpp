#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCloudScriptTests.h"
#include "XAsyncHelper.h"

uint32_t g_CloudScriptTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenCloudScriptTests::LogGetCloudScriptRevisionRequest(PFCloudScriptGetCloudScriptRevisionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptGetCloudScriptRevisionRequest struct:
    // request->revision: int32_t const*
    ss << "  revision " << request->revision; Log(ss); // Class: int32_t 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptGetCloudScriptRevisionResult(PFCloudScriptGetCloudScriptRevisionResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptGetCloudScriptRevisionResult    
    ss << "  createdAt " << result->createdAt; Log(ss); // Class: time_t         
    ss << "  filesCount " << result->filesCount; Log(ss);

    // PFCloudScriptCloudScriptFile
    for( uint32_t i=0; i<result->filesCount; i++ )
    {
            ss << "  result->files[" << i << "]:" << result->files[i]; Log(ss); // PFCloudScriptCloudScriptFile
    }     
    ss << "  isPublished " << result->isPublished; Log(ss); // Class: bool     
    ss << "  revision " << result->revision; Log(ss); // Class: int32_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptGetCloudScriptVersionsResult(PFCloudScriptGetCloudScriptVersionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptGetCloudScriptVersionsResult        
    ss << "  versionsCount " << result->versionsCount; Log(ss);

    // PFCloudScriptCloudScriptVersionStatus
    for( uint32_t i=0; i<result->versionsCount; i++ )
    {
            ss << "  result->versions[" << i << "]:" << result->versions[i]; Log(ss); // PFCloudScriptCloudScriptVersionStatus
    } 
    return S_OK;
}

void AutoGenCloudScriptTests::LogSetPublishedRevisionRequest(PFCloudScriptSetPublishedRevisionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptSetPublishedRevisionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  revision " << request->revision; Log(ss); // Class: int32_t 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

void AutoGenCloudScriptTests::LogUpdateCloudScriptRequest(PFCloudScriptUpdateCloudScriptRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptUpdateCloudScriptRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->developerPlayFabId ) { ss << "  developerPlayFabId " << request->developerPlayFabId; Log(ss); } else { ss << "  developerPlayFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  filesCount " << request->filesCount; Log(ss);

    // PFCloudScriptCloudScriptFile
    for( uint32_t i=0; i<request->filesCount; i++ )
    {
            ss << "  request->files[" << i << "]:" << request->files[i]; Log(ss); // PFCloudScriptCloudScriptFile
    } 
    ss << "  publish " << request->publish; Log(ss); // Class: bool 

}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptUpdateCloudScriptResult(PFCloudScriptUpdateCloudScriptResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptUpdateCloudScriptResult    
    ss << "  revision " << result->revision; Log(ss); // Class: int32_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenCloudScriptTests::LogExecuteCloudScriptRequest(PFCloudScriptExecuteCloudScriptRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptExecuteCloudScriptRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->functionParameter.stringValue ) { ss << "  functionParameter " << request->functionParameter.stringValue; Log(ss); } else { ss << "  functionParameter = nullptr"; Log(ss); } // Class: PFJsonObject 
    ss << "  generatePlayStreamEvent " << request->generatePlayStreamEvent; Log(ss); // Class: bool 
    ss << "  revisionSelection " << request->revisionSelection; Log(ss); // Class: PFCloudScriptCloudScriptRevisionOption 
    ss << "  specificRevision " << request->specificRevision; Log(ss); // Class: int32_t 

}

HRESULT AutoGenCloudScriptTests::LogPFExecuteCloudScriptResult(PFExecuteCloudScriptResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptExecuteCloudScriptResult    
    ss << "  aPIRequestsIssued " << result->aPIRequestsIssued; Log(ss); // Class: int32_t     
    ss << "  error " << result->error; Log(ss); // Class: PFScriptExecutionError     
    ss << "  executionTimeSeconds " << result->executionTimeSeconds; Log(ss); // Class: double     
    if( result->functionName ) { ss << "  functionName " << result->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char*     
    if( result->functionResult.stringValue ) { ss << "  functionResult " << result->functionResult.stringValue; Log(ss); } else { ss << "  functionResult = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  functionResultTooLarge " << result->functionResultTooLarge; Log(ss); // Class: bool     
    ss << "  httpRequestsIssued " << result->httpRequestsIssued; Log(ss); // Class: int32_t         
    ss << "  logsCount " << result->logsCount; Log(ss);

    // PFLogStatement
    for( uint32_t i=0; i<result->logsCount; i++ )
    {
            ss << "  result->logs[" << i << "]:" << result->logs[i]; Log(ss); // PFLogStatement
    }     
    ss << "  logsTooLarge " << result->logsTooLarge; Log(ss); // Class: bool     
    ss << "  memoryConsumedBytes " << result->memoryConsumedBytes; Log(ss); // Class: uint32_t     
    ss << "  processorTimeSeconds " << result->processorTimeSeconds; Log(ss); // Class: double     
    ss << "  revision " << result->revision; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenCloudScriptTests::LogExecuteCloudScriptServerRequest(PFCloudScriptExecuteCloudScriptServerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptExecuteCloudScriptServerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->functionParameter.stringValue ) { ss << "  functionParameter " << request->functionParameter.stringValue; Log(ss); } else { ss << "  functionParameter = nullptr"; Log(ss); } // Class: PFJsonObject 
    ss << "  generatePlayStreamEvent " << request->generatePlayStreamEvent; Log(ss); // Class: bool 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  revisionSelection " << request->revisionSelection; Log(ss); // Class: PFCloudScriptCloudScriptRevisionOption 
    ss << "  specificRevision " << request->specificRevision; Log(ss); // Class: int32_t 

}

void AutoGenCloudScriptTests::LogExecuteEntityCloudScriptRequest(PFCloudScriptExecuteEntityCloudScriptRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptExecuteEntityCloudScriptRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->functionParameter.stringValue ) { ss << "  functionParameter " << request->functionParameter.stringValue; Log(ss); } else { ss << "  functionParameter = nullptr"; Log(ss); } // Class: PFJsonObject 
    ss << "  generatePlayStreamEvent " << request->generatePlayStreamEvent; Log(ss); // Class: bool 
    ss << "  revisionSelection " << request->revisionSelection; Log(ss); // Class: PFCloudScriptCloudScriptRevisionOption 
    ss << "  specificRevision " << request->specificRevision; Log(ss); // Class: int32_t 

}

void AutoGenCloudScriptTests::LogExecuteFunctionRequest(PFCloudScriptExecuteFunctionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptExecuteFunctionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->functionParameter.stringValue ) { ss << "  functionParameter " << request->functionParameter.stringValue; Log(ss); } else { ss << "  functionParameter = nullptr"; Log(ss); } // Class: PFJsonObject 
    ss << "  generatePlayStreamEvent " << request->generatePlayStreamEvent; Log(ss); // Class: bool 

}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptExecuteFunctionResult(PFCloudScriptExecuteFunctionResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptExecuteFunctionResult    
    ss << "  error " << result->error; Log(ss); // Class: PFCloudScriptFunctionExecutionError     
    ss << "  executionTimeMilliseconds " << result->executionTimeMilliseconds; Log(ss); // Class: int32_t     
    if( result->functionName ) { ss << "  functionName " << result->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char*     
    if( result->functionResult.stringValue ) { ss << "  functionResult " << result->functionResult.stringValue; Log(ss); } else { ss << "  functionResult = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  functionResultTooLarge " << result->functionResultTooLarge; Log(ss); // Class: bool 
    return S_OK;
}

void AutoGenCloudScriptTests::LogGetFunctionRequest(PFCloudScriptGetFunctionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptGetFunctionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptGetFunctionResult(PFCloudScriptGetFunctionResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptGetFunctionResult    
    if( result->connectionString ) { ss << "  connectionString " << result->connectionString; Log(ss); } else { ss << "  connectionString = nullptr"; Log(ss); } // Class: const char*     
    if( result->functionUrl ) { ss << "  functionUrl " << result->functionUrl; Log(ss); } else { ss << "  functionUrl = nullptr"; Log(ss); } // Class: const char*     
    if( result->queueName ) { ss << "  queueName " << result->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  systemData " << result->systemData; Log(ss); // Class: PFAzureResourceSystemData     
    if( result->triggerType ) { ss << "  triggerType " << result->triggerType; Log(ss); } else { ss << "  triggerType = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenCloudScriptTests::LogListFunctionsRequest(PFCloudScriptListFunctionsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptListFunctionsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptListFunctionsResult(PFCloudScriptListFunctionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptListFunctionsResult        
    ss << "  functionsCount " << result->functionsCount; Log(ss);

    // PFCloudScriptFunctionModel
    for( uint32_t i=0; i<result->functionsCount; i++ )
    {
            ss << "  result->functions[" << i << "]:" << result->functions[i]; Log(ss); // PFCloudScriptFunctionModel
    } 
    return S_OK;
}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptListHttpFunctionsResult(PFCloudScriptListHttpFunctionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptListHttpFunctionsResult        
    ss << "  functionsCount " << result->functionsCount; Log(ss);

    // PFCloudScriptHttpFunctionModel
    for( uint32_t i=0; i<result->functionsCount; i++ )
    {
            ss << "  result->functions[" << i << "]:" << result->functions[i]; Log(ss); // PFCloudScriptHttpFunctionModel
    } 
    return S_OK;
}

HRESULT AutoGenCloudScriptTests::LogPFCloudScriptListQueuedFunctionsResult(PFCloudScriptListQueuedFunctionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptListQueuedFunctionsResult        
    ss << "  functionsCount " << result->functionsCount; Log(ss);

    // PFCloudScriptQueuedFunctionModel
    for( uint32_t i=0; i<result->functionsCount; i++ )
    {
            ss << "  result->functions[" << i << "]:" << result->functions[i]; Log(ss); // PFCloudScriptQueuedFunctionModel
    } 
    return S_OK;
}

void AutoGenCloudScriptTests::LogPostFunctionResultForEntityTriggeredActionRequest(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptPostFunctionResultForEntityTriggeredActionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  functionResult " << request->functionResult; Log(ss); // Class: PFCloudScriptExecuteFunctionResult 

}

void AutoGenCloudScriptTests::LogPostFunctionResultForFunctionExecutionRequest(PFCloudScriptPostFunctionResultForFunctionExecutionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptPostFunctionResultForFunctionExecutionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  functionResult " << request->functionResult; Log(ss); // Class: PFCloudScriptExecuteFunctionResult 

}

void AutoGenCloudScriptTests::LogPostFunctionResultForPlayerTriggeredActionRequest(PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptPostFunctionResultForPlayerTriggeredActionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  functionResult " << request->functionResult; Log(ss); // Class: PFCloudScriptExecuteFunctionResult 
    ss << "  playerProfile " << request->playerProfile; Log(ss); // Class: PFPlayerProfileModel 
    ss << "  playStreamEventEnvelope " << request->playStreamEventEnvelope; Log(ss); // Class: PFCloudScriptPlayStreamEventEnvelopeModel 

}

void AutoGenCloudScriptTests::LogPostFunctionResultForScheduledTaskRequest(PFCloudScriptPostFunctionResultForScheduledTaskRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptPostFunctionResultForScheduledTaskRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  functionResult " << request->functionResult; Log(ss); // Class: PFCloudScriptExecuteFunctionResult 
    ss << "  scheduledTaskId " << request->scheduledTaskId; Log(ss); // Class: PFNameIdentifier 

}

void AutoGenCloudScriptTests::LogRegisterHttpFunctionRequest(PFCloudScriptRegisterHttpFunctionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptRegisterHttpFunctionRequest struct:
    // request->azureResourceId: const char*
    if( request->azureResourceId ) { ss << "  azureResourceId " << request->azureResourceId; Log(ss); } else { ss << "  azureResourceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->functionUrl ) { ss << "  functionUrl " << request->functionUrl; Log(ss); } else { ss << "  functionUrl = nullptr"; Log(ss); } // Class: const char* 
    ss << "  systemData " << request->systemData; Log(ss); // Class: PFAzureResourceSystemData 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCloudScriptTests::LogRegisterQueuedFunctionRequest(PFCloudScriptRegisterQueuedFunctionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptRegisterQueuedFunctionRequest struct:
    // request->azureResourceId: const char*
    if( request->azureResourceId ) { ss << "  azureResourceId " << request->azureResourceId; Log(ss); } else { ss << "  azureResourceId = nullptr"; Log(ss); } // Class: const char* 
    if( request->connectionString ) { ss << "  connectionString " << request->connectionString; Log(ss); } else { ss << "  connectionString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  systemData " << request->systemData; Log(ss); // Class: PFAzureResourceSystemData 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCloudScriptTests::LogUnregisterFunctionRequest(PFCloudScriptUnregisterFunctionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptUnregisterFunctionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->functionName ) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
