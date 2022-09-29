#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenLobbyTests.h"
#include "XAsyncHelper.h"

uint32_t g_LobbyTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenLobbyTests::LogCreateLobbyRequest(PFLobbyCreateLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyCreateLobbyRequest struct:
    // request->accessPolicy: PFLobbyAccessPolicy const*
    ss << "  accessPolicy " << request->accessPolicy; Log(ss); // Class: PFLobbyAccessPolicy     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  lobbyDataCount " << request->lobbyDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->lobbyDataCount; i++)
    {
            ss << "  request->lobbyData[" << i << "]:" << request->lobbyData[i].key << "=" << request->lobbyData[i].value; Log(ss);
            
    } 
    ss << "  maxPlayers " << request->maxPlayers; Log(ss); // Class: uint32_t     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFLobbyMember
    for (uint32_t i=0; i<request->membersCount; i++)
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFLobbyMember
    } 
    ss << "  owner " << request->owner; Log(ss); // Class: PFEntityKey 
    ss << "  ownerMigrationPolicy " << request->ownerMigrationPolicy; Log(ss); // Class: PFLobbyOwnerMigrationPolicy     
    ss << "  searchDataCount " << request->searchDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->searchDataCount; i++)
    {
            ss << "  request->searchData[" << i << "]:" << request->searchData[i].key << "=" << request->searchData[i].value; Log(ss);
            
    } 
    ss << "  useConnections " << request->useConnections; Log(ss); // Class: bool 

}

HRESULT AutoGenLobbyTests::LogCreateLobbyResult(PFLobbyCreateLobbyResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLobbyCreateLobbyResult    
    if (result->connectionString) { ss << "  connectionString " << result->connectionString; Log(ss); } else { ss << "  connectionString = nullptr"; Log(ss); } // Class: const char*     
    if (result->lobbyId) { ss << "  lobbyId " << result->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenLobbyTests::LogDeleteLobbyRequest(PFLobbyDeleteLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyDeleteLobbyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->lobbyId) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenLobbyTests::LogFindFriendLobbiesRequest(PFLobbyFindFriendLobbiesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyFindFriendLobbiesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  excludeFacebookFriends " << request->excludeFacebookFriends; Log(ss); // Class: bool 
    ss << "  excludeSteamFriends " << request->excludeSteamFriends; Log(ss); // Class: bool 
    if (request->filter) { ss << "  filter " << request->filter; Log(ss); } else { ss << "  filter = nullptr"; Log(ss); } // Class: const char* 
    if (request->orderBy) { ss << "  orderBy " << request->orderBy; Log(ss); } else { ss << "  orderBy = nullptr"; Log(ss); } // Class: const char* 
    ss << "  pagination " << request->pagination; Log(ss); // Class: PFLobbyPaginationRequest 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenLobbyTests::LogFindFriendLobbiesResult(PFLobbyFindFriendLobbiesResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLobbyFindFriendLobbiesResult        
    ss << "  lobbiesCount " << result->lobbiesCount; Log(ss);

    // PFLobbyFriendLobbySummary
    for (uint32_t i=0; i<result->lobbiesCount; i++)
    {
            ss << "  result->lobbies[" << i << "]:" << result->lobbies[i]; Log(ss); // PFLobbyFriendLobbySummary
    }     
    ss << "  pagination " << result->pagination; Log(ss); // Class: PFLobbyPaginationResponse 
    return S_OK;
}

void AutoGenLobbyTests::LogFindLobbiesRequest(PFLobbyFindLobbiesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyFindLobbiesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->filter) { ss << "  filter " << request->filter; Log(ss); } else { ss << "  filter = nullptr"; Log(ss); } // Class: const char* 
    if (request->orderBy) { ss << "  orderBy " << request->orderBy; Log(ss); } else { ss << "  orderBy = nullptr"; Log(ss); } // Class: const char* 
    ss << "  pagination " << request->pagination; Log(ss); // Class: PFLobbyPaginationRequest 

}

HRESULT AutoGenLobbyTests::LogFindLobbiesResult(PFLobbyFindLobbiesResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLobbyFindLobbiesResult        
    ss << "  lobbiesCount " << result->lobbiesCount; Log(ss);

    // PFLobbyLobbySummary
    for (uint32_t i=0; i<result->lobbiesCount; i++)
    {
            ss << "  result->lobbies[" << i << "]:" << result->lobbies[i]; Log(ss); // PFLobbyLobbySummary
    }     
    ss << "  pagination " << result->pagination; Log(ss); // Class: PFLobbyPaginationResponse 
    return S_OK;
}

void AutoGenLobbyTests::LogGetLobbyRequest(PFLobbyGetLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyGetLobbyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->lobbyId) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenLobbyTests::LogGetLobbyResult(PFLobbyGetLobbyResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLobbyGetLobbyResult    
    ss << "  lobby " << result->lobby; Log(ss); // Class: PFLobbyLobby 
    return S_OK;
}

void AutoGenLobbyTests::LogInviteToLobbyRequest(PFLobbyInviteToLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyInviteToLobbyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  inviteeEntity " << request->inviteeEntity; Log(ss); // Class: PFEntityKey 
    if (request->lobbyId) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  memberEntity " << request->memberEntity; Log(ss); // Class: PFEntityKey 

}

void AutoGenLobbyTests::LogJoinArrangedLobbyRequest(PFLobbyJoinArrangedLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyJoinArrangedLobbyRequest struct:
    // request->accessPolicy: PFLobbyAccessPolicy const*
    ss << "  accessPolicy " << request->accessPolicy; Log(ss); // Class: PFLobbyAccessPolicy 
    if (request->arrangementString) { ss << "  arrangementString " << request->arrangementString; Log(ss); } else { ss << "  arrangementString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxPlayers " << request->maxPlayers; Log(ss); // Class: uint32_t     
    ss << "  memberDataCount " << request->memberDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->memberDataCount; i++)
    {
            ss << "  request->memberData[" << i << "]:" << request->memberData[i].key << "=" << request->memberData[i].value; Log(ss);
            
    } 
    ss << "  memberEntity " << request->memberEntity; Log(ss); // Class: PFEntityKey 
    ss << "  ownerMigrationPolicy " << request->ownerMigrationPolicy; Log(ss); // Class: PFLobbyOwnerMigrationPolicy 
    ss << "  useConnections " << request->useConnections; Log(ss); // Class: bool 

}

HRESULT AutoGenLobbyTests::LogJoinLobbyResult(PFLobbyJoinLobbyResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLobbyJoinLobbyResult    
    if (result->lobbyId) { ss << "  lobbyId " << result->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenLobbyTests::LogJoinLobbyRequest(PFLobbyJoinLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyJoinLobbyRequest struct:
    // request->connectionString: const char*
    if (request->connectionString) { ss << "  connectionString " << request->connectionString; Log(ss); } else { ss << "  connectionString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  memberDataCount " << request->memberDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->memberDataCount; i++)
    {
            ss << "  request->memberData[" << i << "]:" << request->memberData[i].key << "=" << request->memberData[i].value; Log(ss);
            
    } 
    ss << "  memberEntity " << request->memberEntity; Log(ss); // Class: PFEntityKey 

}

void AutoGenLobbyTests::LogLeaveLobbyRequest(PFLobbyLeaveLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyLeaveLobbyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->lobbyId) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  memberEntity " << request->memberEntity; Log(ss); // Class: PFEntityKey 

}

void AutoGenLobbyTests::LogRemoveMemberFromLobbyRequest(PFLobbyRemoveMemberFromLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyRemoveMemberFromLobbyRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->lobbyId) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  memberEntity " << request->memberEntity; Log(ss); // Class: PFEntityKey 
    ss << "  preventRejoin " << request->preventRejoin; Log(ss); // Class: bool 

}

void AutoGenLobbyTests::LogSubscribeToLobbyResourceRequest(PFLobbySubscribeToLobbyResourceRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbySubscribeToLobbyResourceRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entityKey " << request->entityKey; Log(ss); // Class: PFEntityKey 
    if (request->pubSubConnectionHandle) { ss << "  pubSubConnectionHandle " << request->pubSubConnectionHandle; Log(ss); } else { ss << "  pubSubConnectionHandle = nullptr"; Log(ss); } // Class: const char* 
    if (request->resourceId) { ss << "  resourceId " << request->resourceId; Log(ss); } else { ss << "  resourceId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  subscriptionVersion " << request->subscriptionVersion; Log(ss); // Class: uint32_t 
    ss << "  type " << static_cast<uint32_t>(request->type); Log(ss); // Class: PFLobbySubscriptionType 

}

HRESULT AutoGenLobbyTests::LogSubscribeToLobbyResourceResult(PFLobbySubscribeToLobbyResourceResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLobbySubscribeToLobbyResourceResult    
    if (result->topic) { ss << "  topic " << result->topic; Log(ss); } else { ss << "  topic = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenLobbyTests::LogUnsubscribeFromLobbyResourceRequest(PFLobbyUnsubscribeFromLobbyResourceRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyUnsubscribeFromLobbyResourceRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entityKey " << request->entityKey; Log(ss); // Class: PFEntityKey 
    if (request->pubSubConnectionHandle) { ss << "  pubSubConnectionHandle " << request->pubSubConnectionHandle; Log(ss); } else { ss << "  pubSubConnectionHandle = nullptr"; Log(ss); } // Class: const char* 
    if (request->resourceId) { ss << "  resourceId " << request->resourceId; Log(ss); } else { ss << "  resourceId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  subscriptionVersion " << request->subscriptionVersion; Log(ss); // Class: uint32_t 
    ss << "  type " << static_cast<uint32_t>(request->type); Log(ss); // Class: PFLobbySubscriptionType 

}

void AutoGenLobbyTests::LogUpdateLobbyRequest(PFLobbyUpdateLobbyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LobbyTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLobbyUpdateLobbyRequest struct:
    // request->accessPolicy: PFLobbyAccessPolicy const*
    ss << "  accessPolicy " << request->accessPolicy; Log(ss); // Class: PFLobbyAccessPolicy     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  lobbyDataCount " << request->lobbyDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->lobbyDataCount; i++)
    {
            ss << "  request->lobbyData[" << i << "]:" << request->lobbyData[i].key << "=" << request->lobbyData[i].value; Log(ss);
            
    }     
    ss << "  lobbyDataToDeleteCount " << request->lobbyDataToDeleteCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->lobbyDataToDeleteCount; i++)
    {
            ss << "  request->lobbyDataToDelete[" << i << "]:" << request->lobbyDataToDelete[i]; Log(ss); // const char*
    } 
    if (request->lobbyId) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxPlayers " << request->maxPlayers; Log(ss); // Class: uint32_t     
    ss << "  memberDataCount " << request->memberDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->memberDataCount; i++)
    {
            ss << "  request->memberData[" << i << "]:" << request->memberData[i].key << "=" << request->memberData[i].value; Log(ss);
            
    }     
    ss << "  memberDataToDeleteCount " << request->memberDataToDeleteCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->memberDataToDeleteCount; i++)
    {
            ss << "  request->memberDataToDelete[" << i << "]:" << request->memberDataToDelete[i]; Log(ss); // const char*
    } 
    ss << "  memberEntity " << request->memberEntity; Log(ss); // Class: PFEntityKey 
    ss << "  membershipLock " << request->membershipLock; Log(ss); // Class: PFLobbyMembershipLock 
    ss << "  owner " << request->owner; Log(ss); // Class: PFEntityKey     
    ss << "  searchDataCount " << request->searchDataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->searchDataCount; i++)
    {
            ss << "  request->searchData[" << i << "]:" << request->searchData[i].key << "=" << request->searchData[i].value; Log(ss);
            
    }     
    ss << "  searchDataToDeleteCount " << request->searchDataToDeleteCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->searchDataToDeleteCount; i++)
    {
            ss << "  request->searchDataToDelete[" << i << "]:" << request->searchDataToDelete[i]; Log(ss); // const char*
    } 

}

 

}
