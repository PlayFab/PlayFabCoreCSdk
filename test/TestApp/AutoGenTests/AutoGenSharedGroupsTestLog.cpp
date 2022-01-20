#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenSharedGroupsTests.h"
#include "XAsyncHelper.h"

uint32_t g_SharedGroupsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenSharedGroupsTests::LogAddSharedGroupMembersRequest(PFSharedGroupsAddSharedGroupMembersRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SharedGroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSharedGroupsAddSharedGroupMembersRequest struct:
    // request->playFabIds: const char* const*
    // request->playFabIdsCount: uint32_t    
    ss << "  playFabIdsCount " << request->playFabIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->playFabIdsCount; i++)
    {
            ss << "  request->playFabIds[" << i << "]:" << request->playFabIds[i]; Log(ss); // const char*
    } 
    if (request->sharedGroupId) { ss << "  sharedGroupId " << request->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenSharedGroupsTests::LogCreateSharedGroupRequest(PFSharedGroupsCreateSharedGroupRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SharedGroupsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSharedGroupsCreateSharedGroupRequest struct:
    // request->sharedGroupId: const char*
    if (request->sharedGroupId) { ss << "  sharedGroupId " << request->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenSharedGroupsTests::LogCreateSharedGroupResult(PFSharedGroupsCreateSharedGroupResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabSharedGroupsCreateSharedGroupResult    
    if (result->sharedGroupId) { ss << "  sharedGroupId " << result->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenSharedGroupsTests::LogGetSharedGroupDataRequest(PFSharedGroupsGetSharedGroupDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SharedGroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSharedGroupsGetSharedGroupDataRequest struct:
    // request->getMembers: bool const*
    ss << "  getMembers " << request->getMembers; Log(ss); // Class: bool     
    ss << "  keysCount " << request->keysCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysCount; i++)
    {
            ss << "  request->keys[" << i << "]:" << request->keys[i]; Log(ss); // const char*
    } 
    if (request->sharedGroupId) { ss << "  sharedGroupId " << request->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenSharedGroupsTests::LogGetSharedGroupDataResult(PFSharedGroupsGetSharedGroupDataResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabSharedGroupsGetSharedGroupDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFSharedGroupsSharedGroupDataRecordDictionaryEntry
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->membersCount; i++)
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenSharedGroupsTests::LogRemoveSharedGroupMembersRequest(PFSharedGroupsRemoveSharedGroupMembersRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SharedGroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSharedGroupsRemoveSharedGroupMembersRequest struct:
    // request->playFabIds: const char* const*
    // request->playFabIdsCount: uint32_t    
    ss << "  playFabIdsCount " << request->playFabIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->playFabIdsCount; i++)
    {
            ss << "  request->playFabIds[" << i << "]:" << request->playFabIds[i]; Log(ss); // const char*
    } 
    if (request->sharedGroupId) { ss << "  sharedGroupId " << request->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenSharedGroupsTests::LogUpdateSharedGroupDataRequest(PFSharedGroupsUpdateSharedGroupDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SharedGroupsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSharedGroupsUpdateSharedGroupDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  dataCount " << request->dataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->dataCount; i++)
    {
            ss << "  request->data[" << i << "]:" << request->data[i].key << "=" << request->data[i].value; Log(ss);
            
    }     
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysToRemoveCount; i++)
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    ss << "  permission " << request->permission; Log(ss); // Class: PFUserDataPermission 
    if (request->sharedGroupId) { ss << "  sharedGroupId " << request->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenSharedGroupsTests::LogDeleteSharedGroupRequest(PFSharedGroupsDeleteSharedGroupRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_SharedGroupsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabSharedGroupsDeleteSharedGroupRequest struct:
    // request->sharedGroupId: const char*
    if (request->sharedGroupId) { ss << "  sharedGroupId " << request->sharedGroupId; Log(ss); } else { ss << "  sharedGroupId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
