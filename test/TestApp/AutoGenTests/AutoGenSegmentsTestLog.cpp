#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenSegmentsTests.h"
#include "XAsyncHelper.h"

uint32_t g_SegmentsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenSegmentsTests::LogCreateSegmentRequest(PFSegmentsCreateSegmentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SegmentsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSegmentsCreateSegmentRequest struct:
    // request->segmentModel: PFSegmentsSegmentModel const*
    ss << "  segmentModel " << request->segmentModel; Log(ss); // Class: PFSegmentsSegmentModel 

}

HRESULT AutoGenSegmentsTests::LogPFSegmentsCreateSegmentResponse(PFSegmentsCreateSegmentResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabSegmentsCreateSegmentResponse    
    if( result->errorMessage ) { ss << "  errorMessage " << result->errorMessage; Log(ss); } else { ss << "  errorMessage = nullptr"; Log(ss); } // Class: const char*     
    if( result->segmentId ) { ss << "  segmentId " << result->segmentId; Log(ss); } else { ss << "  segmentId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenSegmentsTests::LogDeleteSegmentRequest(PFSegmentsDeleteSegmentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SegmentsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSegmentsDeleteSegmentRequest struct:
    // request->segmentId: const char*
    if( request->segmentId ) { ss << "  segmentId " << request->segmentId; Log(ss); } else { ss << "  segmentId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenSegmentsTests::LogPFSegmentsDeleteSegmentsResponse(PFSegmentsDeleteSegmentsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabSegmentsDeleteSegmentsResponse    
    if( result->errorMessage ) { ss << "  errorMessage " << result->errorMessage; Log(ss); } else { ss << "  errorMessage = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenSegmentsTests::LogGetSegmentsRequest(PFSegmentsGetSegmentsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SegmentsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSegmentsGetSegmentsRequest struct:
    // request->segmentIds: const char* const*
    // request->segmentIdsCount: uint32_t    
    ss << "  segmentIdsCount " << request->segmentIdsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->segmentIdsCount; i++ )
    {
            ss << "  request->segmentIds[" << i << "]:" << request->segmentIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenSegmentsTests::LogPFSegmentsGetSegmentsResponse(PFSegmentsGetSegmentsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabSegmentsGetSegmentsResponse    
    if( result->errorMessage ) { ss << "  errorMessage " << result->errorMessage; Log(ss); } else { ss << "  errorMessage = nullptr"; Log(ss); } // Class: const char*         
    ss << "  segmentsCount " << result->segmentsCount; Log(ss);

    // PFSegmentsSegmentModel
    for( uint32_t i=0; i<result->segmentsCount; i++ )
    {
            ss << "  result->segments[" << i << "]:" << result->segments[i]; Log(ss); // PFSegmentsSegmentModel
    } 
    return S_OK;
}

void AutoGenSegmentsTests::LogUpdateSegmentRequest(PFSegmentsUpdateSegmentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SegmentsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSegmentsUpdateSegmentRequest struct:
    // request->segmentModel: PFSegmentsSegmentModel const*
    ss << "  segmentModel " << request->segmentModel; Log(ss); // Class: PFSegmentsSegmentModel 

}

HRESULT AutoGenSegmentsTests::LogPFSegmentsUpdateSegmentResponse(PFSegmentsUpdateSegmentResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabSegmentsUpdateSegmentResponse    
    if( result->errorMessage ) { ss << "  errorMessage " << result->errorMessage; Log(ss); } else { ss << "  errorMessage = nullptr"; Log(ss); } // Class: const char*     
    if( result->segmentId ) { ss << "  segmentId " << result->segmentId; Log(ss); } else { ss << "  segmentId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

 

}
