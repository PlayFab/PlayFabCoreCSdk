#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAnalyticsTests.h"
#include "XAsyncHelper.h"

uint32_t g_AnalyticsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenAnalyticsTests::LogDeviceInfoRequest(PFAnalyticsDeviceInfoRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsDeviceInfoRequest struct:
    // request->info: PFJsonObject
    if( request->info.stringValue ) { ss << "  info " << request->info.stringValue; Log(ss); } else { ss << "  info = nullptr"; Log(ss); } // Class: PFJsonObject 

}

void AutoGenAnalyticsTests::LogWriteClientCharacterEventRequest(PFAnalyticsWriteClientCharacterEventRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsWriteClientCharacterEventRequest struct:
    // request->body: PFJsonObject
    if( request->body.stringValue ) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject 
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->eventName ) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

HRESULT AutoGenAnalyticsTests::LogPFAnalyticsWriteEventResponse(PFAnalyticsWriteEventResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAnalyticsWriteEventResponse
    if( result->eventId ) { ss << "  eventId " << result->eventId; Log(ss); } else { ss << "  eventId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAnalyticsTests::LogWriteClientPlayerEventRequest(PFAnalyticsWriteClientPlayerEventRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsWriteClientPlayerEventRequest struct:
    // request->body: PFJsonObject
    if( request->body.stringValue ) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->eventName ) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenAnalyticsTests::LogWriteTitleEventRequest(PFAnalyticsWriteTitleEventRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsWriteTitleEventRequest struct:
    // request->body: PFJsonObject
    if( request->body.stringValue ) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->eventName ) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenAnalyticsTests::LogWriteServerCharacterEventRequest(PFAnalyticsWriteServerCharacterEventRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsWriteServerCharacterEventRequest struct:
    // request->body: PFJsonObject
    if( request->body.stringValue ) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject 
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->eventName ) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenAnalyticsTests::LogWriteServerPlayerEventRequest(PFAnalyticsWriteServerPlayerEventRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsWriteServerPlayerEventRequest struct:
    // request->body: PFJsonObject
    if( request->body.stringValue ) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->eventName ) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenAnalyticsTests::LogInsightsEmptyRequest(PFAnalyticsInsightsEmptyRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsInsightsEmptyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenAnalyticsTests::LogPFAnalyticsInsightsGetDetailsResponse(PFAnalyticsInsightsGetDetailsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAnalyticsInsightsGetDetailsResponse
    ss << "  dataUsageMb " << result->dataUsageMb; Log(ss); // Class: uint32_t 
    if( result->errorMessage ) { ss << "  errorMessage " << result->errorMessage; Log(ss); } else { ss << "  errorMessage = nullptr"; Log(ss); } // Class: const char* 
    ss << "  limits " << result->limits; Log(ss); // Class: PFAnalyticsInsightsGetLimitsResponse     
    ss << "  pendingOperationsCount " << result->pendingOperationsCount; Log(ss);

    // PFAnalyticsInsightsGetOperationStatusResponse
    for( uint32_t i=0; i<result->pendingOperationsCount; i++ )
    {
            ss << "  result->pendingOperations[" << i << "]:" << result->pendingOperations[i]; Log(ss); // PFAnalyticsInsightsGetOperationStatusResponse
    } 
    ss << "  performanceLevel " << result->performanceLevel; Log(ss); // Class: int32_t 
    ss << "  retentionDays " << result->retentionDays; Log(ss); // Class: int32_t 
    return S_OK;
}

HRESULT AutoGenAnalyticsTests::LogPFAnalyticsInsightsGetLimitsResponse(PFAnalyticsInsightsGetLimitsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAnalyticsInsightsGetLimitsResponse
    ss << "  defaultPerformanceLevel " << result->defaultPerformanceLevel; Log(ss); // Class: int32_t 
    ss << "  defaultStorageRetentionDays " << result->defaultStorageRetentionDays; Log(ss); // Class: int32_t 
    ss << "  storageMaxRetentionDays " << result->storageMaxRetentionDays; Log(ss); // Class: int32_t 
    ss << "  storageMinRetentionDays " << result->storageMinRetentionDays; Log(ss); // Class: int32_t     
    ss << "  subMetersCount " << result->subMetersCount; Log(ss);

    // PFAnalyticsInsightsPerformanceLevel
    for( uint32_t i=0; i<result->subMetersCount; i++ )
    {
            ss << "  result->subMeters[" << i << "]:" << result->subMeters[i]; Log(ss); // PFAnalyticsInsightsPerformanceLevel
    } 
    return S_OK;
}

void AutoGenAnalyticsTests::LogInsightsGetOperationStatusRequest(PFAnalyticsInsightsGetOperationStatusRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsInsightsGetOperationStatusRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->operationId ) { ss << "  operationId " << request->operationId; Log(ss); } else { ss << "  operationId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAnalyticsTests::LogPFAnalyticsInsightsGetOperationStatusResponse(PFAnalyticsInsightsGetOperationStatusResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAnalyticsInsightsGetOperationStatusResponse
    if( result->message ) { ss << "  message " << result->message; Log(ss); } else { ss << "  message = nullptr"; Log(ss); } // Class: const char* 
    ss << "  operationCompletedTime " << result->operationCompletedTime; Log(ss); // Class: time_t 
    if( result->operationId ) { ss << "  operationId " << result->operationId; Log(ss); } else { ss << "  operationId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  operationLastUpdated " << result->operationLastUpdated; Log(ss); // Class: time_t 
    ss << "  operationStartedTime " << result->operationStartedTime; Log(ss); // Class: time_t 
    if( result->operationType ) { ss << "  operationType " << result->operationType; Log(ss); } else { ss << "  operationType = nullptr"; Log(ss); } // Class: const char* 
    ss << "  operationValue " << result->operationValue; Log(ss); // Class: int32_t 
    if( result->status ) { ss << "  status " << result->status; Log(ss); } else { ss << "  status = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAnalyticsTests::LogInsightsGetPendingOperationsRequest(PFAnalyticsInsightsGetPendingOperationsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsInsightsGetPendingOperationsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->operationType ) { ss << "  operationType " << request->operationType; Log(ss); } else { ss << "  operationType = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAnalyticsTests::LogPFAnalyticsInsightsGetPendingOperationsResponse(PFAnalyticsInsightsGetPendingOperationsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAnalyticsInsightsGetPendingOperationsResponse    
    ss << "  pendingOperationsCount " << result->pendingOperationsCount; Log(ss);

    // PFAnalyticsInsightsGetOperationStatusResponse
    for( uint32_t i=0; i<result->pendingOperationsCount; i++ )
    {
            ss << "  result->pendingOperations[" << i << "]:" << result->pendingOperations[i]; Log(ss); // PFAnalyticsInsightsGetOperationStatusResponse
    } 
    return S_OK;
}

void AutoGenAnalyticsTests::LogInsightsSetPerformanceRequest(PFAnalyticsInsightsSetPerformanceRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsInsightsSetPerformanceRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  performanceLevel " << request->performanceLevel; Log(ss); // Class: int32_t 

}

HRESULT AutoGenAnalyticsTests::LogPFAnalyticsInsightsOperationResponse(PFAnalyticsInsightsOperationResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAnalyticsInsightsOperationResponse
    if( result->message ) { ss << "  message " << result->message; Log(ss); } else { ss << "  message = nullptr"; Log(ss); } // Class: const char* 
    if( result->operationId ) { ss << "  operationId " << result->operationId; Log(ss); } else { ss << "  operationId = nullptr"; Log(ss); } // Class: const char* 
    if( result->operationType ) { ss << "  operationType " << result->operationType; Log(ss); } else { ss << "  operationType = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAnalyticsTests::LogInsightsSetStorageRetentionRequest(PFAnalyticsInsightsSetStorageRetentionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AnalyticsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAnalyticsInsightsSetStorageRetentionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  retentionDays " << request->retentionDays; Log(ss); // Class: int32_t 

}

 

}
