#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAuthenticationTests.h"
#include "XAsyncHelper.h"

uint32_t g_AuthenticationTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenAuthenticationTests::LogAuthenticateCustomIdIdentityRequest(PFAuthenticationAuthenticateCustomIdIdentityRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationAuthenticateCustomIdIdentityRequest struct:
    // request->behaviorIfIdentityNotLinked: PFAuthenticationAccountLinkAction
    ss << "  behaviorIfIdentityNotLinked " << static_cast<uint32_t>(request->behaviorIfIdentityNotLinked); Log(ss); // Class: PFAuthenticationAccountLinkAction 
    if (request->customId) { ss << "  customId " << request->customId; Log(ss); } else { ss << "  customId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->existingMasterPlayerAccountId) { ss << "  existingMasterPlayerAccountId " << request->existingMasterPlayerAccountId; Log(ss); } else { ss << "  existingMasterPlayerAccountId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerAccountPoolId) { ss << "  playerAccountPoolId " << request->playerAccountPoolId; Log(ss); } else { ss << "  playerAccountPoolId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogAuthenticateIdentityResult(PFAuthenticationAuthenticateIdentityResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationAuthenticateIdentityResult    
    if (result->createdIdentityLinkId) { ss << "  createdIdentityLinkId " << result->createdIdentityLinkId; Log(ss); } else { ss << "  createdIdentityLinkId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  masterPlayerAccount " << result->masterPlayerAccount; Log(ss); // Class: PFAuthenticationEntityTokenResponse     
    ss << "  titlePlayerAccount " << result->titlePlayerAccount; Log(ss); // Class: PFAuthenticationEntityTokenResponse 
    return S_OK;
}

void AutoGenAuthenticationTests::LogGetLinkedPlayerIdentitiesRequest(PFAuthenticationGetLinkedPlayerIdentitiesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationGetLinkedPlayerIdentitiesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->masterPlayerAccountId) { ss << "  masterPlayerAccountId " << request->masterPlayerAccountId; Log(ss); } else { ss << "  masterPlayerAccountId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogGetLinkedPlayerIdentitiesResult(PFAuthenticationGetLinkedPlayerIdentitiesResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationGetLinkedPlayerIdentitiesResult        
    ss << "  linkedIdentitiesCount " << result->linkedIdentitiesCount; Log(ss);

    // PFAuthenticationLinkedPlayerIdentity
    for (uint32_t i=0; i<result->linkedIdentitiesCount; i++)
    {
            ss << "  result->linkedIdentities[" << i << "]:" << result->linkedIdentities[i]; Log(ss); // PFAuthenticationLinkedPlayerIdentity
    } 
    return S_OK;
}

void AutoGenAuthenticationTests::LogUnlinkPlayerIdentityRequest(PFAuthenticationUnlinkPlayerIdentityRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationUnlinkPlayerIdentityRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->identityLinkId) { ss << "  identityLinkId " << request->identityLinkId; Log(ss); } else { ss << "  identityLinkId = nullptr"; Log(ss); } // Class: const char* 
    if (request->masterPlayerAccountId) { ss << "  masterPlayerAccountId " << request->masterPlayerAccountId; Log(ss); } else { ss << "  masterPlayerAccountId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginPlayerRequest(PFAuthenticationLoginPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->titleId) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogLoginPlayerResult(PFAuthenticationLoginPlayerResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationLoginPlayerResult    
    ss << "  titlePlayerAccountEntityToken " << result->titlePlayerAccountEntityToken; Log(ss); // Class: PFAuthenticationEntityTokenResponse 
    return S_OK;
}

 

}
