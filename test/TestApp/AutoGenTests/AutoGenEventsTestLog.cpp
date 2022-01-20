#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenEventsTests.h"
#include "XAsyncHelper.h"

uint32_t g_EventsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenEventsTests::LogAddPlayerTagRequest(PFEventsAddPlayerTagRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsAddPlayerTagRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->tagName) { ss << "  tagName " << request->tagName; Log(ss); } else { ss << "  tagName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenEventsTests::LogGetPlayerTagsRequest(PFEventsGetPlayerTagsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsGetPlayerTagsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playfabNamespace) { ss << "  playfabNamespace " << request->playfabNamespace; Log(ss); } else { ss << "  playfabNamespace = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenEventsTests::LogGetPlayerTagsResult(PFEventsGetPlayerTagsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabEventsGetPlayerTagsResult    
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  tagsCount " << result->tagsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->tagsCount; i++)
    {
            ss << "  result->tags[" << i << "]:" << result->tags[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenEventsTests::LogRemovePlayerTagRequest(PFEventsRemovePlayerTagRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsRemovePlayerTagRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->tagName) { ss << "  tagName " << request->tagName; Log(ss); } else { ss << "  tagName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenEventsTests::LogWriteClientCharacterEventRequest(PFEventsWriteClientCharacterEventRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsWriteClientCharacterEventRequest struct:
    // request->body: PFJsonObject
    if (request->body.stringValue) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->eventName) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

HRESULT AutoGenEventsTests::LogWriteEventResponse(PFEventsWriteEventResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabEventsWriteEventResponse    
    if (result->eventId) { ss << "  eventId " << result->eventId; Log(ss); } else { ss << "  eventId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenEventsTests::LogWriteClientPlayerEventRequest(PFEventsWriteClientPlayerEventRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsWriteClientPlayerEventRequest struct:
    // request->body: PFJsonObject
    if (request->body.stringValue) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->eventName) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenEventsTests::LogWriteTitleEventRequest(PFEventsWriteTitleEventRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsWriteTitleEventRequest struct:
    // request->body: PFJsonObject
    if (request->body.stringValue) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->eventName) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenEventsTests::LogWriteServerCharacterEventRequest(PFEventsWriteServerCharacterEventRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsWriteServerCharacterEventRequest struct:
    // request->body: PFJsonObject
    if (request->body.stringValue) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->eventName) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

void AutoGenEventsTests::LogWriteServerPlayerEventRequest(PFEventsWriteServerPlayerEventRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_EventsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabEventsWriteServerPlayerEventRequest struct:
    // request->body: PFJsonObject
    if (request->body.stringValue) { ss << "  body " << request->body.stringValue; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->eventName) { ss << "  eventName " << request->eventName; Log(ss); } else { ss << "  eventName = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 

}

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
