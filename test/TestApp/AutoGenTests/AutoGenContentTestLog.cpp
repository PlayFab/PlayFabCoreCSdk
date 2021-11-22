#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenContentTests.h"
#include "XAsyncHelper.h"

uint32_t g_ContentTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenContentTests::LogDeleteContentRequest(PFContentDeleteContentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ContentTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabContentDeleteContentRequest struct:
    // request->key: const char*
    if( request->key ) { ss << "  key " << request->key; Log(ss); } else { ss << "  key = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenContentTests::LogGetContentListRequest(PFContentGetContentListRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ContentTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabContentGetContentListRequest struct:
    // request->prefix: const char*
    if( request->prefix ) { ss << "  prefix " << request->prefix; Log(ss); } else { ss << "  prefix = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenContentTests::LogPFContentGetContentListResult(PFContentGetContentListResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabContentGetContentListResult    
    ss << "  contentsCount " << result->contentsCount; Log(ss);

    // PFContentContentInfo
    for( uint32_t i=0; i<result->contentsCount; i++ )
    {
            ss << "  result->contents[" << i << "]:" << result->contents[i]; Log(ss); // PFContentContentInfo
    } 
    ss << "  itemCount " << result->itemCount; Log(ss); // Class: int32_t 
    ss << "  totalSize " << result->totalSize; Log(ss); // Class: uint32_t 
    return S_OK;
}

void AutoGenContentTests::LogGetContentUploadUrlRequest(PFContentGetContentUploadUrlRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ContentTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabContentGetContentUploadUrlRequest struct:
    // request->contentType: const char*
    if( request->contentType ) { ss << "  contentType " << request->contentType; Log(ss); } else { ss << "  contentType = nullptr"; Log(ss); } // Class: const char* 
    if( request->key ) { ss << "  key " << request->key; Log(ss); } else { ss << "  key = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenContentTests::LogPFContentGetContentUploadUrlResult(PFContentGetContentUploadUrlResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabContentGetContentUploadUrlResult
    if( result->URL ) { ss << "  URL " << result->URL; Log(ss); } else { ss << "  URL = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenContentTests::LogGetContentDownloadUrlRequest(PFContentGetContentDownloadUrlRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ContentTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabContentGetContentDownloadUrlRequest struct:
    // request->httpMethod: const char*
    if( request->httpMethod ) { ss << "  httpMethod " << request->httpMethod; Log(ss); } else { ss << "  httpMethod = nullptr"; Log(ss); } // Class: const char* 
    if( request->key ) { ss << "  key " << request->key; Log(ss); } else { ss << "  key = nullptr"; Log(ss); } // Class: const char* 
    ss << "  thruCDN " << request->thruCDN; Log(ss); // Class: bool 

}

HRESULT AutoGenContentTests::LogPFContentGetContentDownloadUrlResult(PFContentGetContentDownloadUrlResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabContentGetContentDownloadUrlResult
    if( result->URL ) { ss << "  URL " << result->URL; Log(ss); } else { ss << "  URL = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

 

}
