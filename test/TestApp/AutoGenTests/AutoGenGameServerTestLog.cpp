#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenGameServerTests.h"
#include "XAsyncHelper.h"

uint32_t g_GameServerTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenGameServerTests::LogAddServerBuildRequest(PFGameServerAddServerBuildRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GameServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGameServerAddServerBuildRequest struct:
    // request->activeRegions: PFRegion const*
    // request->activeRegionsCount: uint32_t    
    ss << "  activeRegionsCount " << request->activeRegionsCount; Log(ss);

    // PFRegion
    for( uint32_t i=0; i<request->activeRegionsCount; i++ )
    {
            ss << "  request->activeRegions[" << i << "]:" << request->activeRegions[i]; Log(ss); // PFRegion
    } 
    if( request->buildId ) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 
    if( request->commandLineTemplate ) { ss << "  commandLineTemplate " << request->commandLineTemplate; Log(ss); } else { ss << "  commandLineTemplate = nullptr"; Log(ss); } // Class: const char* 
    if( request->comment ) { ss << "  comment " << request->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->executablePath ) { ss << "  executablePath " << request->executablePath; Log(ss); } else { ss << "  executablePath = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxGamesPerHost " << request->maxGamesPerHost; Log(ss); // Class: int32_t 
    ss << "  minFreeGameSlots " << request->minFreeGameSlots; Log(ss); // Class: int32_t 

}

HRESULT AutoGenGameServerTests::LogPFGameServerAddServerBuildResult(PFGameServerAddServerBuildResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGameServerAddServerBuildResult    
    ss << "  activeRegionsCount " << result->activeRegionsCount; Log(ss);

    // PFRegion
    for( uint32_t i=0; i<result->activeRegionsCount; i++ )
    {
            ss << "  result->activeRegions[" << i << "]:" << result->activeRegions[i]; Log(ss); // PFRegion
    } 
    if( result->buildId ) { ss << "  buildId " << result->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 
    if( result->commandLineTemplate ) { ss << "  commandLineTemplate " << result->commandLineTemplate; Log(ss); } else { ss << "  commandLineTemplate = nullptr"; Log(ss); } // Class: const char* 
    if( result->comment ) { ss << "  comment " << result->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char* 
    if( result->executablePath ) { ss << "  executablePath " << result->executablePath; Log(ss); } else { ss << "  executablePath = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxGamesPerHost " << result->maxGamesPerHost; Log(ss); // Class: int32_t 
    ss << "  minFreeGameSlots " << result->minFreeGameSlots; Log(ss); // Class: int32_t 
    ss << "  status " << result->status; Log(ss); // Class: PFGameServerGameBuildStatus 
    ss << "  timestamp " << result->timestamp; Log(ss); // Class: time_t 
    if( result->titleId ) { ss << "  titleId " << result->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenGameServerTests::LogGetServerBuildInfoRequest(PFGameServerGetServerBuildInfoRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GameServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGameServerGetServerBuildInfoRequest struct:
    // request->buildId: const char*
    if( request->buildId ) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGameServerTests::LogPFGameServerGetServerBuildInfoResult(PFGameServerGetServerBuildInfoResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGameServerGetServerBuildInfoResult    
    ss << "  activeRegionsCount " << result->activeRegionsCount; Log(ss);

    // PFRegion
    for( uint32_t i=0; i<result->activeRegionsCount; i++ )
    {
            ss << "  result->activeRegions[" << i << "]:" << result->activeRegions[i]; Log(ss); // PFRegion
    } 
    if( result->buildId ) { ss << "  buildId " << result->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 
    if( result->comment ) { ss << "  comment " << result->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char* 
    if( result->errorMessage ) { ss << "  errorMessage " << result->errorMessage; Log(ss); } else { ss << "  errorMessage = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxGamesPerHost " << result->maxGamesPerHost; Log(ss); // Class: int32_t 
    ss << "  minFreeGameSlots " << result->minFreeGameSlots; Log(ss); // Class: int32_t 
    ss << "  status " << result->status; Log(ss); // Class: PFGameServerGameBuildStatus 
    ss << "  timestamp " << result->timestamp; Log(ss); // Class: time_t 
    if( result->titleId ) { ss << "  titleId " << result->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenGameServerTests::LogGetServerBuildUploadURLRequest(PFGameServerGetServerBuildUploadURLRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GameServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGameServerGetServerBuildUploadURLRequest struct:
    // request->buildId: const char*
    if( request->buildId ) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenGameServerTests::LogPFGameServerGetServerBuildUploadURLResult(PFGameServerGetServerBuildUploadURLResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGameServerGetServerBuildUploadURLResult
    if( result->URL ) { ss << "  URL " << result->URL; Log(ss); } else { ss << "  URL = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

HRESULT AutoGenGameServerTests::LogPFGameServerListBuildsResult(PFGameServerListBuildsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGameServerListBuildsResult    
    ss << "  buildsCount " << result->buildsCount; Log(ss);

    // PFGameServerGetServerBuildInfoResult
    for( uint32_t i=0; i<result->buildsCount; i++ )
    {
            ss << "  result->builds[" << i << "]:" << result->builds[i]; Log(ss); // PFGameServerGetServerBuildInfoResult
    } 
    return S_OK;
}

void AutoGenGameServerTests::LogModifyServerBuildRequest(PFGameServerModifyServerBuildRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GameServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGameServerModifyServerBuildRequest struct:
    // request->activeRegions: PFRegion const*
    // request->activeRegionsCount: uint32_t    
    ss << "  activeRegionsCount " << request->activeRegionsCount; Log(ss);

    // PFRegion
    for( uint32_t i=0; i<request->activeRegionsCount; i++ )
    {
            ss << "  request->activeRegions[" << i << "]:" << request->activeRegions[i]; Log(ss); // PFRegion
    } 
    if( request->buildId ) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 
    if( request->commandLineTemplate ) { ss << "  commandLineTemplate " << request->commandLineTemplate; Log(ss); } else { ss << "  commandLineTemplate = nullptr"; Log(ss); } // Class: const char* 
    if( request->comment ) { ss << "  comment " << request->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->executablePath ) { ss << "  executablePath " << request->executablePath; Log(ss); } else { ss << "  executablePath = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxGamesPerHost " << request->maxGamesPerHost; Log(ss); // Class: int32_t 
    ss << "  minFreeGameSlots " << request->minFreeGameSlots; Log(ss); // Class: int32_t 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

HRESULT AutoGenGameServerTests::LogPFGameServerModifyServerBuildResult(PFGameServerModifyServerBuildResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabGameServerModifyServerBuildResult    
    ss << "  activeRegionsCount " << result->activeRegionsCount; Log(ss);

    // PFRegion
    for( uint32_t i=0; i<result->activeRegionsCount; i++ )
    {
            ss << "  result->activeRegions[" << i << "]:" << result->activeRegions[i]; Log(ss); // PFRegion
    } 
    if( result->buildId ) { ss << "  buildId " << result->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 
    if( result->commandLineTemplate ) { ss << "  commandLineTemplate " << result->commandLineTemplate; Log(ss); } else { ss << "  commandLineTemplate = nullptr"; Log(ss); } // Class: const char* 
    if( result->comment ) { ss << "  comment " << result->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char* 
    if( result->executablePath ) { ss << "  executablePath " << result->executablePath; Log(ss); } else { ss << "  executablePath = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxGamesPerHost " << result->maxGamesPerHost; Log(ss); // Class: int32_t 
    ss << "  minFreeGameSlots " << result->minFreeGameSlots; Log(ss); // Class: int32_t 
    ss << "  status " << result->status; Log(ss); // Class: PFGameServerGameBuildStatus 
    ss << "  timestamp " << result->timestamp; Log(ss); // Class: time_t 
    if( result->titleId ) { ss << "  titleId " << result->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenGameServerTests::LogRemoveServerBuildRequest(PFGameServerRemoveServerBuildRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_GameServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabGameServerRemoveServerBuildRequest struct:
    // request->buildId: const char*
    if( request->buildId ) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
