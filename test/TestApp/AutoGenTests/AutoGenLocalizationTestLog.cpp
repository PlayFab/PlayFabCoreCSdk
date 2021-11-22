#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenLocalizationTests.h"
#include "XAsyncHelper.h"

uint32_t g_LocalizationTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenLocalizationTests::LogGetLanguageListRequest(PFLocalizationGetLanguageListRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LocalizationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLocalizationGetLanguageListRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenLocalizationTests::LogPFLocalizationGetLanguageListResponse(PFLocalizationGetLanguageListResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLocalizationGetLanguageListResponse    
    ss << "  languageListCount " << result->languageListCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<result->languageListCount; i++ )
    {
            ss << "  result->languageList[" << i << "]:" << result->languageList[i]; Log(ss); // const char*
    } 
    return S_OK;
}

 

}
