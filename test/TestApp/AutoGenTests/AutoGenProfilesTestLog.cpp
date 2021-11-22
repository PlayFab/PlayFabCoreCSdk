#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenProfilesTests.h"
#include "XAsyncHelper.h"

uint32_t g_ProfilesTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenProfilesTests::LogGetGlobalPolicyRequest(PFProfilesGetGlobalPolicyRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesGetGlobalPolicyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenProfilesTests::LogPFProfilesGetGlobalPolicyResponse(PFProfilesGetGlobalPolicyResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabProfilesGetGlobalPolicyResponse    
    ss << "  permissionsCount " << result->permissionsCount; Log(ss);

    // PFProfilesEntityPermissionStatement
    for( uint32_t i=0; i<result->permissionsCount; i++ )
    {
            ss << "  result->permissions[" << i << "]:" << result->permissions[i]; Log(ss); // PFProfilesEntityPermissionStatement
    } 
    return S_OK;
}

void AutoGenProfilesTests::LogGetEntityProfileRequest(PFProfilesGetEntityProfileRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesGetEntityProfileRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  dataAsObject " << request->dataAsObject; Log(ss); // Class: bool 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenProfilesTests::LogPFProfilesGetEntityProfileResponse(PFProfilesGetEntityProfileResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabProfilesGetEntityProfileResponse
    ss << "  profile " << result->profile; Log(ss); // Class: PFProfilesEntityProfileBody 
    return S_OK;
}

void AutoGenProfilesTests::LogGetEntityProfilesRequest(PFProfilesGetEntityProfilesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesGetEntityProfilesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  dataAsObject " << request->dataAsObject; Log(ss); // Class: bool     
    ss << "  entitiesCount " << request->entitiesCount; Log(ss);

    // PFEntityKey
    for( uint32_t i=0; i<request->entitiesCount; i++ )
    {
            ss << "  request->entities[" << i << "]:" << request->entities[i]; Log(ss); // PFEntityKey
    } 

}

HRESULT AutoGenProfilesTests::LogPFProfilesGetEntityProfilesResponse(PFProfilesGetEntityProfilesResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabProfilesGetEntityProfilesResponse    
    ss << "  profilesCount " << result->profilesCount; Log(ss);

    // PFProfilesEntityProfileBody
    for( uint32_t i=0; i<result->profilesCount; i++ )
    {
            ss << "  result->profiles[" << i << "]:" << result->profiles[i]; Log(ss); // PFProfilesEntityProfileBody
    } 
    return S_OK;
}

void AutoGenProfilesTests::LogGetTitlePlayersFromMasterPlayerAccountIdsRequest(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  masterPlayerAccountIdsCount " << request->masterPlayerAccountIdsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->masterPlayerAccountIdsCount; i++ )
    {
            ss << "  request->masterPlayerAccountIds[" << i << "]:" << request->masterPlayerAccountIds[i]; Log(ss); // const char*
    } 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenProfilesTests::LogPFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse
    if( result->titleId ) { ss << "  titleId " << result->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  titlePlayerAccountsCount " << result->titlePlayerAccountsCount; Log(ss);

    // PFEntityKeyDictionaryEntry
    for( uint32_t i=0; i<result->titlePlayerAccountsCount; i++ )
    {
            ss << "  result->titlePlayerAccounts[" << i << "]:" << result->titlePlayerAccounts[i].key << "=" << result->titlePlayerAccounts[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenProfilesTests::LogSetGlobalPolicyRequest(PFProfilesSetGlobalPolicyRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesSetGlobalPolicyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  permissionsCount " << request->permissionsCount; Log(ss);

    // PFProfilesEntityPermissionStatement
    for( uint32_t i=0; i<request->permissionsCount; i++ )
    {
            ss << "  request->permissions[" << i << "]:" << request->permissions[i]; Log(ss); // PFProfilesEntityPermissionStatement
    } 

}

void AutoGenProfilesTests::LogSetProfileLanguageRequest(PFProfilesSetProfileLanguageRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesSetProfileLanguageRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  expectedVersion " << request->expectedVersion; Log(ss); // Class: int32_t 
    if( request->language ) { ss << "  language " << request->language; Log(ss); } else { ss << "  language = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenProfilesTests::LogPFProfilesSetProfileLanguageResponse(PFProfilesSetProfileLanguageResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabProfilesSetProfileLanguageResponse
    ss << "  operationResult " << result->operationResult; Log(ss); // Class: PFOperationTypes 
    ss << "  versionNumber " << result->versionNumber; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenProfilesTests::LogSetEntityProfilePolicyRequest(PFProfilesSetEntityProfilePolicyRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ProfilesTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabProfilesSetEntityProfilePolicyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey     
    ss << "  statementsCount " << request->statementsCount; Log(ss);

    // PFProfilesEntityPermissionStatement
    for( uint32_t i=0; i<request->statementsCount; i++ )
    {
            ss << "  request->statements[" << i << "]:" << request->statements[i]; Log(ss); // PFProfilesEntityPermissionStatement
    } 

}

HRESULT AutoGenProfilesTests::LogPFProfilesSetEntityProfilePolicyResponse(PFProfilesSetEntityProfilePolicyResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabProfilesSetEntityProfilePolicyResponse    
    ss << "  permissionsCount " << result->permissionsCount; Log(ss);

    // PFProfilesEntityPermissionStatement
    for( uint32_t i=0; i<result->permissionsCount; i++ )
    {
            ss << "  result->permissions[" << i << "]:" << result->permissions[i]; Log(ss); // PFProfilesEntityPermissionStatement
    } 
    return S_OK;
}

 

}
