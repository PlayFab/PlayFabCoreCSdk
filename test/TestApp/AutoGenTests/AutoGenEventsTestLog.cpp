#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenEventsTests.h"
#include "XAsyncHelper.h"

uint32_t g_EventsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenEventsTests::LogWriteEventsRequest(PFEventsWriteEventsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsWriteEventsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  eventsCount " << request->eventsCount; Log(ss);

    // PFEventsEventContents
    for (uint32_t i=0; i<request->eventsCount; i++)
    {
            ss << "  request->events[" << i << "]:" << request->events[i]; Log(ss); // PFEventsEventContents
    } 

}

HRESULT AutoGenEventsTests::LogWriteEventsResponse(PFEventsWriteEventsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabEventsWriteEventsResponse        
    ss << "  assignedEventIdsCount " << result->assignedEventIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->assignedEventIdsCount; i++)
    {
            ss << "  result->assignedEventIds[" << i << "]:" << result->assignedEventIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

 

}
