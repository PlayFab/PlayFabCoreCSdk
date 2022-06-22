#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenMultiplayerServerTests.h"
#include "XAsyncHelper.h"

uint32_t g_MultiplayerServerTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenMultiplayerServerTests::LogCreateRemoteUserRequest(PFMultiplayerServerCreateRemoteUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerCreateRemoteUserRequest struct:
    // request->buildId: const char*
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  expirationTime " << request->expirationTime; Log(ss); // Class: time_t 
    if (request->region) { ss << "  region " << request->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 
    if (request->vmId) { ss << "  vmId " << request->vmId; Log(ss); } else { ss << "  vmId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerCreateRemoteUserResponse    
    ss << "  expirationTime " << result->expirationTime; Log(ss); // Class: time_t     
    if (result->password) { ss << "  password " << result->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char*     
    if (result->username) { ss << "  username " << result->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogDeleteCertificateRequest(PFMultiplayerServerDeleteCertificateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerDeleteCertificateRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->name) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMultiplayerServerTests::LogDeleteRemoteUserRequest(PFMultiplayerServerDeleteRemoteUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerDeleteRemoteUserRequest struct:
    // request->buildId: const char*
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->region) { ss << "  region " << request->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 
    if (request->vmId) { ss << "  vmId " << request->vmId; Log(ss); } else { ss << "  vmId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMultiplayerServerTests::LogGetMultiplayerServerDetailsRequest(PFMultiplayerServerGetMultiplayerServerDetailsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerGetMultiplayerServerDetailsRequest struct:
    // request->buildId: const char*
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->region) { ss << "  region " << request->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char* 
    if (request->sessionId) { ss << "  sessionId " << request->sessionId; Log(ss); } else { ss << "  sessionId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerGetMultiplayerServerDetailsResponse    
    if (result->buildId) { ss << "  buildId " << result->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  connectedPlayersCount " << result->connectedPlayersCount; Log(ss);

    // PFMultiplayerServerConnectedPlayer
    for (uint32_t i=0; i<result->connectedPlayersCount; i++)
    {
            ss << "  result->connectedPlayers[" << i << "]:" << result->connectedPlayers[i]; Log(ss); // PFMultiplayerServerConnectedPlayer
    }     
    if (result->fQDN) { ss << "  fQDN " << result->fQDN; Log(ss); } else { ss << "  fQDN = nullptr"; Log(ss); } // Class: const char*     
    if (result->iPV4Address) { ss << "  iPV4Address " << result->iPV4Address; Log(ss); } else { ss << "  iPV4Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  lastStateTransitionTime " << result->lastStateTransitionTime; Log(ss); // Class: time_t         
    ss << "  portsCount " << result->portsCount; Log(ss);

    // PFPort
    for (uint32_t i=0; i<result->portsCount; i++)
    {
            ss << "  result->ports[" << i << "]:" << result->ports[i]; Log(ss); // PFPort
    }     
    if (result->region) { ss << "  region " << result->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char*     
    if (result->serverId) { ss << "  serverId " << result->serverId; Log(ss); } else { ss << "  serverId = nullptr"; Log(ss); } // Class: const char*     
    if (result->sessionId) { ss << "  sessionId " << result->sessionId; Log(ss); } else { ss << "  sessionId = nullptr"; Log(ss); } // Class: const char*     
    if (result->state) { ss << "  state " << result->state; Log(ss); } else { ss << "  state = nullptr"; Log(ss); } // Class: const char*     
    if (result->vmId) { ss << "  vmId " << result->vmId; Log(ss); } else { ss << "  vmId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogGetMultiplayerServerLogsRequest(PFMultiplayerServerGetMultiplayerServerLogsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerGetMultiplayerServerLogsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->serverId) { ss << "  serverId " << request->serverId; Log(ss); } else { ss << "  serverId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerGetMultiplayerServerLogsResponse    
    if (result->logDownloadUrl) { ss << "  logDownloadUrl " << result->logDownloadUrl; Log(ss); } else { ss << "  logDownloadUrl = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogGetMultiplayerSessionLogsBySessionIdRequest(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->sessionId) { ss << "  sessionId " << request->sessionId; Log(ss); } else { ss << "  sessionId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMultiplayerServerTests::LogGetRemoteLoginEndpointRequest(PFMultiplayerServerGetRemoteLoginEndpointRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerGetRemoteLoginEndpointRequest struct:
    // request->buildId: const char*
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->region) { ss << "  region " << request->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char* 
    if (request->vmId) { ss << "  vmId " << request->vmId; Log(ss); } else { ss << "  vmId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerGetRemoteLoginEndpointResponse    
    if (result->iPV4Address) { ss << "  iPV4Address " << result->iPV4Address; Log(ss); } else { ss << "  iPV4Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  port " << result->port; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListMultiplayerServersRequest(PFMultiplayerServerListMultiplayerServersRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListMultiplayerServersRequest struct:
    // request->buildId: const char*
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  pageSize " << request->pageSize; Log(ss); // Class: int32_t 
    if (request->region) { ss << "  region " << request->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char* 
    if (request->skipToken) { ss << "  skipToken " << request->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListMultiplayerServersResponse        
    ss << "  multiplayerServerSummariesCount " << result->multiplayerServerSummariesCount; Log(ss);

    // PFMultiplayerServerMultiplayerServerSummary
    for (uint32_t i=0; i<result->multiplayerServerSummariesCount; i++)
    {
            ss << "  result->multiplayerServerSummaries[" << i << "]:" << result->multiplayerServerSummaries[i]; Log(ss); // PFMultiplayerServerMultiplayerServerSummary
    }     
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListBuildAliasesRequest(PFMultiplayerServerListBuildAliasesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListBuildAliasesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  pageSize " << request->pageSize; Log(ss); // Class: int32_t 
    if (request->skipToken) { ss << "  skipToken " << request->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListBuildAliasesResponse        
    ss << "  buildAliasesCount " << result->buildAliasesCount; Log(ss);

    // PFMultiplayerServerBuildAliasDetailsResponse
    for (uint32_t i=0; i<result->buildAliasesCount; i++)
    {
            ss << "  result->buildAliases[" << i << "]:" << result->buildAliases[i]; Log(ss); // PFMultiplayerServerBuildAliasDetailsResponse
    }     
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListBuildSummariesRequest(PFMultiplayerServerListBuildSummariesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListBuildSummariesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  pageSize " << request->pageSize; Log(ss); // Class: int32_t 
    if (request->skipToken) { ss << "  skipToken " << request->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogListBuildSummariesResponse(PFMultiplayerServerListBuildSummariesResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListBuildSummariesResponse        
    ss << "  buildSummariesCount " << result->buildSummariesCount; Log(ss);

    // PFMultiplayerServerBuildSummary
    for (uint32_t i=0; i<result->buildSummariesCount; i++)
    {
            ss << "  result->buildSummaries[" << i << "]:" << result->buildSummaries[i]; Log(ss); // PFMultiplayerServerBuildSummary
    }     
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListCertificateSummariesRequest(PFMultiplayerServerListCertificateSummariesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListCertificateSummariesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  pageSize " << request->pageSize; Log(ss); // Class: int32_t 
    if (request->skipToken) { ss << "  skipToken " << request->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListCertificateSummariesResponse        
    ss << "  certificateSummariesCount " << result->certificateSummariesCount; Log(ss);

    // PFMultiplayerServerCertificateSummary
    for (uint32_t i=0; i<result->certificateSummariesCount; i++)
    {
            ss << "  result->certificateSummaries[" << i << "]:" << result->certificateSummaries[i]; Log(ss); // PFMultiplayerServerCertificateSummary
    }     
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListPartyQosServersRequest(PFMultiplayerServerListPartyQosServersRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListPartyQosServersRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenMultiplayerServerTests::LogListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListPartyQosServersResponse    
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t         
    ss << "  qosServersCount " << result->qosServersCount; Log(ss);

    // PFMultiplayerServerQosServer
    for (uint32_t i=0; i<result->qosServersCount; i++)
    {
            ss << "  result->qosServers[" << i << "]:" << result->qosServers[i]; Log(ss); // PFMultiplayerServerQosServer
    }     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListQosServersForTitleRequest(PFMultiplayerServerListQosServersForTitleRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListQosServersForTitleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeAllRegions " << request->includeAllRegions; Log(ss); // Class: bool 

}

HRESULT AutoGenMultiplayerServerTests::LogListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListQosServersForTitleResponse    
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t         
    ss << "  qosServersCount " << result->qosServersCount; Log(ss);

    // PFMultiplayerServerQosServer
    for (uint32_t i=0; i<result->qosServersCount; i++)
    {
            ss << "  result->qosServers[" << i << "]:" << result->qosServers[i]; Log(ss); // PFMultiplayerServerQosServer
    }     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogListVirtualMachineSummariesRequest(PFMultiplayerServerListVirtualMachineSummariesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerListVirtualMachineSummariesRequest struct:
    // request->buildId: const char*
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  pageSize " << request->pageSize; Log(ss); // Class: int32_t 
    if (request->region) { ss << "  region " << request->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char* 
    if (request->skipToken) { ss << "  skipToken " << request->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerListVirtualMachineSummariesResponse    
    ss << "  pageSize " << result->pageSize; Log(ss); // Class: int32_t     
    if (result->skipToken) { ss << "  skipToken " << result->skipToken; Log(ss); } else { ss << "  skipToken = nullptr"; Log(ss); } // Class: const char*         
    ss << "  virtualMachinesCount " << result->virtualMachinesCount; Log(ss);

    // PFMultiplayerServerVirtualMachineSummary
    for (uint32_t i=0; i<result->virtualMachinesCount; i++)
    {
            ss << "  result->virtualMachines[" << i << "]:" << result->virtualMachines[i]; Log(ss); // PFMultiplayerServerVirtualMachineSummary
    } 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogRequestMultiplayerServerRequest(PFMultiplayerServerRequestMultiplayerServerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerRequestMultiplayerServerRequest struct:
    // request->buildAliasParams: PFMultiplayerServerBuildAliasParams const*
    ss << "  buildAliasParams " << request->buildAliasParams; Log(ss); // Class: PFMultiplayerServerBuildAliasParams 
    if (request->buildId) { ss << "  buildId " << request->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  initialPlayersCount " << request->initialPlayersCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->initialPlayersCount; i++)
    {
            ss << "  request->initialPlayers[" << i << "]:" << request->initialPlayers[i]; Log(ss); // const char*
    }     
    ss << "  preferredRegionsCount " << request->preferredRegionsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->preferredRegionsCount; i++)
    {
            ss << "  request->preferredRegions[" << i << "]:" << request->preferredRegions[i]; Log(ss); // const char*
    } 
    if (request->sessionCookie) { ss << "  sessionCookie " << request->sessionCookie; Log(ss); } else { ss << "  sessionCookie = nullptr"; Log(ss); } // Class: const char* 
    if (request->sessionId) { ss << "  sessionId " << request->sessionId; Log(ss); } else { ss << "  sessionId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMultiplayerServerTests::LogRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMultiplayerServerRequestMultiplayerServerResponse    
    if (result->buildId) { ss << "  buildId " << result->buildId; Log(ss); } else { ss << "  buildId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  connectedPlayersCount " << result->connectedPlayersCount; Log(ss);

    // PFMultiplayerServerConnectedPlayer
    for (uint32_t i=0; i<result->connectedPlayersCount; i++)
    {
            ss << "  result->connectedPlayers[" << i << "]:" << result->connectedPlayers[i]; Log(ss); // PFMultiplayerServerConnectedPlayer
    }     
    if (result->fQDN) { ss << "  fQDN " << result->fQDN; Log(ss); } else { ss << "  fQDN = nullptr"; Log(ss); } // Class: const char*     
    if (result->iPV4Address) { ss << "  iPV4Address " << result->iPV4Address; Log(ss); } else { ss << "  iPV4Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  lastStateTransitionTime " << result->lastStateTransitionTime; Log(ss); // Class: time_t         
    ss << "  portsCount " << result->portsCount; Log(ss);

    // PFPort
    for (uint32_t i=0; i<result->portsCount; i++)
    {
            ss << "  result->ports[" << i << "]:" << result->ports[i]; Log(ss); // PFPort
    }     
    if (result->region) { ss << "  region " << result->region; Log(ss); } else { ss << "  region = nullptr"; Log(ss); } // Class: const char*     
    if (result->serverId) { ss << "  serverId " << result->serverId; Log(ss); } else { ss << "  serverId = nullptr"; Log(ss); } // Class: const char*     
    if (result->sessionId) { ss << "  sessionId " << result->sessionId; Log(ss); } else { ss << "  sessionId = nullptr"; Log(ss); } // Class: const char*     
    if (result->state) { ss << "  state " << result->state; Log(ss); } else { ss << "  state = nullptr"; Log(ss); } // Class: const char*     
    if (result->vmId) { ss << "  vmId " << result->vmId; Log(ss); } else { ss << "  vmId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMultiplayerServerTests::LogShutdownMultiplayerServerRequest(PFMultiplayerServerShutdownMultiplayerServerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerShutdownMultiplayerServerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->sessionId) { ss << "  sessionId " << request->sessionId; Log(ss); } else { ss << "  sessionId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMultiplayerServerTests::LogUploadCertificateRequest(PFMultiplayerServerUploadCertificateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MultiplayerServerTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMultiplayerServerUploadCertificateRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  gameCertificate " << request->gameCertificate; Log(ss); // Class: PFMultiplayerServerCertificate 

}

 

}
