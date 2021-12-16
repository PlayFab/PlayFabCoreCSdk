#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayStreamTests.h"
#include "XAsyncHelper.h"

uint32_t g_PlayStreamTestIndex = 1;

namespace PlayFabUnit
{

HRESULT AutoGenPlayStreamTests::LogPFPlayStreamGetAllSegmentsResult(PFPlayStreamGetAllSegmentsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayStreamGetAllSegmentsResult        
    ss << "  segmentsCount " << result->segmentsCount; Log(ss);

    // PFPlayStreamGetSegmentResult
    for( uint32_t i=0; i<result->segmentsCount; i++ )
    {
            ss << "  result->segments[" << i << "]:" << result->segments[i]; Log(ss); // PFPlayStreamGetSegmentResult
    } 
    return S_OK;
}

void AutoGenPlayStreamTests::LogGetPlayersSegmentsRequest(PFPlayStreamGetPlayersSegmentsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayStreamTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayStreamGetPlayersSegmentsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayStreamTests::LogPFPlayStreamGetPlayerSegmentsResult(PFPlayStreamGetPlayerSegmentsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayStreamGetPlayerSegmentsResult        
    ss << "  segmentsCount " << result->segmentsCount; Log(ss);

    // PFPlayStreamGetSegmentResult
    for( uint32_t i=0; i<result->segmentsCount; i++ )
    {
            ss << "  result->segments[" << i << "]:" << result->segments[i]; Log(ss); // PFPlayStreamGetSegmentResult
    } 
    return S_OK;
}

void AutoGenPlayStreamTests::LogGetPlayersInSegmentRequest(PFPlayStreamGetPlayersInSegmentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayStreamTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayStreamGetPlayersInSegmentRequest struct:
    // request->continuationToken: const char*
    if( request->continuationToken ) { ss << "  continuationToken " << request->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxBatchSize " << request->maxBatchSize; Log(ss); // Class: uint32_t 
    ss << "  secondsToLive " << request->secondsToLive; Log(ss); // Class: uint32_t 
    if( request->segmentId ) { ss << "  segmentId " << request->segmentId; Log(ss); } else { ss << "  segmentId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayStreamTests::LogPFPlayStreamGetPlayersInSegmentResult(PFPlayStreamGetPlayersInSegmentResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayStreamGetPlayersInSegmentResult    
    if( result->continuationToken ) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*         
    ss << "  playerProfilesCount " << result->playerProfilesCount; Log(ss);

    // PFPlayStreamPlayerProfile
    for( uint32_t i=0; i<result->playerProfilesCount; i++ )
    {
            ss << "  result->playerProfiles[" << i << "]:" << result->playerProfiles[i]; Log(ss); // PFPlayStreamPlayerProfile
    }     
    ss << "  profilesInSegment " << result->profilesInSegment; Log(ss); // Class: int32_t 
    return S_OK;
}

 

}
