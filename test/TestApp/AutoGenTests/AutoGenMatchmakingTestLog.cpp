#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenMatchmakingTests.h"
#include "XAsyncHelper.h"

uint32_t g_MatchmakingTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenMatchmakingTests::LogGetMatchmakerGameInfoRequest(PFMatchmakingGetMatchmakerGameInfoRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGetMatchmakerGameInfoRequest struct:
    // request->lobbyId: const char*
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGetMatchmakerGameInfoResult(PFMatchmakingGetMatchmakerGameInfoResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetMatchmakerGameInfoResult    
    if( result->buildVersion ) { ss << "  buildVersion " << result->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  endTime " << result->endTime; Log(ss); // Class: time_t     
    if( result->lobbyId ) { ss << "  lobbyId " << result->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char*     
    if( result->mode ) { ss << "  mode " << result->mode; Log(ss); } else { ss << "  mode = nullptr"; Log(ss); } // Class: const char*         
    ss << "  playersCount " << result->playersCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<result->playersCount; i++ )
    {
            ss << "  result->players[" << i << "]:" << result->players[i]; Log(ss); // const char*
    }     
    ss << "  region " << result->region; Log(ss); // Class: PFRegion     
    if( result->serverIPV4Address ) { ss << "  serverIPV4Address " << result->serverIPV4Address; Log(ss); } else { ss << "  serverIPV4Address = nullptr"; Log(ss); } // Class: const char*     
    if( result->serverIPV6Address ) { ss << "  serverIPV6Address " << result->serverIPV6Address; Log(ss); } else { ss << "  serverIPV6Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  serverPort " << result->serverPort; Log(ss); // Class: uint32_t     
    if( result->serverPublicDNSName ) { ss << "  serverPublicDNSName " << result->serverPublicDNSName; Log(ss); } else { ss << "  serverPublicDNSName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  startTime " << result->startTime; Log(ss); // Class: time_t     
    if( result->titleId ) { ss << "  titleId " << result->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGetMatchmakerGameModesRequest(PFMatchmakingGetMatchmakerGameModesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGetMatchmakerGameModesRequest struct:
    // request->buildVersion: const char*
    if( request->buildVersion ) { ss << "  buildVersion " << request->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGetMatchmakerGameModesResult(PFMatchmakingGetMatchmakerGameModesResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetMatchmakerGameModesResult        
    ss << "  gameModesCount " << result->gameModesCount; Log(ss);

    // PFMatchmakingGameModeInfo
    for( uint32_t i=0; i<result->gameModesCount; i++ )
    {
            ss << "  result->gameModes[" << i << "]:" << result->gameModes[i]; Log(ss); // PFMatchmakingGameModeInfo
    } 
    return S_OK;
}

void AutoGenMatchmakingTests::LogModifyMatchmakerGameModesRequest(PFMatchmakingModifyMatchmakerGameModesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingModifyMatchmakerGameModesRequest struct:
    // request->buildVersion: const char*
    if( request->buildVersion ) { ss << "  buildVersion " << request->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  gameModesCount " << request->gameModesCount; Log(ss);

    // PFMatchmakingGameModeInfo
    for( uint32_t i=0; i<request->gameModesCount; i++ )
    {
            ss << "  request->gameModes[" << i << "]:" << request->gameModes[i]; Log(ss); // PFMatchmakingGameModeInfo
    } 

}

void AutoGenMatchmakingTests::LogCurrentGamesRequest(PFMatchmakingCurrentGamesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCurrentGamesRequest struct:
    // request->buildVersion: const char*
    if( request->buildVersion ) { ss << "  buildVersion " << request->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char* 
    if( request->gameMode ) { ss << "  gameMode " << request->gameMode; Log(ss); } else { ss << "  gameMode = nullptr"; Log(ss); } // Class: const char* 
    ss << "  region " << request->region; Log(ss); // Class: PFRegion 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  tagFilter " << request->tagFilter; Log(ss); // Class: PFMatchmakingCollectionFilter 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingCurrentGamesResult(PFMatchmakingCurrentGamesResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingCurrentGamesResult    
    ss << "  gameCount " << result->gameCount; Log(ss); // Class: int32_t         
    ss << "  gamesCount " << result->gamesCount; Log(ss);

    // PFMatchmakingGameInfo
    for( uint32_t i=0; i<result->gamesCount; i++ )
    {
            ss << "  result->games[" << i << "]:" << result->games[i]; Log(ss); // PFMatchmakingGameInfo
    }     
    ss << "  playerCount " << result->playerCount; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGameServerRegionsRequest(PFMatchmakingGameServerRegionsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGameServerRegionsRequest struct:
    // request->buildVersion: const char*
    if( request->buildVersion ) { ss << "  buildVersion " << request->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char* 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGameServerRegionsResult(PFMatchmakingGameServerRegionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGameServerRegionsResult        
    ss << "  regionsCount " << result->regionsCount; Log(ss);

    // PFMatchmakingRegionInfo
    for( uint32_t i=0; i<result->regionsCount; i++ )
    {
            ss << "  result->regions[" << i << "]:" << result->regions[i]; Log(ss); // PFMatchmakingRegionInfo
    } 
    return S_OK;
}

void AutoGenMatchmakingTests::LogMatchmakeRequest(PFMatchmakingMatchmakeRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingMatchmakeRequest struct:
    // request->buildVersion: const char*
    if( request->buildVersion ) { ss << "  buildVersion " << request->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char* 
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->gameMode ) { ss << "  gameMode " << request->gameMode; Log(ss); } else { ss << "  gameMode = nullptr"; Log(ss); } // Class: const char* 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  region " << request->region; Log(ss); // Class: PFRegion 
    ss << "  startNewIfNoneFound " << request->startNewIfNoneFound; Log(ss); // Class: bool 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  tagFilter " << request->tagFilter; Log(ss); // Class: PFMatchmakingCollectionFilter 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingMatchmakeResult(PFMatchmakingMatchmakeResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingMatchmakeResult    
    if( result->expires ) { ss << "  expires " << result->expires; Log(ss); } else { ss << "  expires = nullptr"; Log(ss); } // Class: const char*     
    if( result->lobbyID ) { ss << "  lobbyID " << result->lobbyID; Log(ss); } else { ss << "  lobbyID = nullptr"; Log(ss); } // Class: const char*     
    ss << "  pollWaitTimeMS " << result->pollWaitTimeMS; Log(ss); // Class: int32_t     
    if( result->serverIPV4Address ) { ss << "  serverIPV4Address " << result->serverIPV4Address; Log(ss); } else { ss << "  serverIPV4Address = nullptr"; Log(ss); } // Class: const char*     
    if( result->serverIPV6Address ) { ss << "  serverIPV6Address " << result->serverIPV6Address; Log(ss); } else { ss << "  serverIPV6Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  serverPort " << result->serverPort; Log(ss); // Class: int32_t     
    if( result->serverPublicDNSName ) { ss << "  serverPublicDNSName " << result->serverPublicDNSName; Log(ss); } else { ss << "  serverPublicDNSName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  status " << result->status; Log(ss); // Class: PFMatchmakingMatchmakeStatus     
    if( result->ticket ) { ss << "  ticket " << result->ticket; Log(ss); } else { ss << "  ticket = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogClientStartGameRequest(PFMatchmakingClientStartGameRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingStartGameRequest struct:
    // request->buildVersion: const char*
    if( request->buildVersion ) { ss << "  buildVersion " << request->buildVersion; Log(ss); } else { ss << "  buildVersion = nullptr"; Log(ss); } // Class: const char* 
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if( request->customCommandLineData ) { ss << "  customCommandLineData " << request->customCommandLineData; Log(ss); } else { ss << "  customCommandLineData = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->gameMode ) { ss << "  gameMode " << request->gameMode; Log(ss); } else { ss << "  gameMode = nullptr"; Log(ss); } // Class: const char* 
    ss << "  region " << request->region; Log(ss); // Class: PFRegion 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingStartGameResult(PFMatchmakingStartGameResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingStartGameResult    
    if( result->expires ) { ss << "  expires " << result->expires; Log(ss); } else { ss << "  expires = nullptr"; Log(ss); } // Class: const char*     
    if( result->lobbyID ) { ss << "  lobbyID " << result->lobbyID; Log(ss); } else { ss << "  lobbyID = nullptr"; Log(ss); } // Class: const char*     
    if( result->password ) { ss << "  password " << result->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char*     
    if( result->serverIPV4Address ) { ss << "  serverIPV4Address " << result->serverIPV4Address; Log(ss); } else { ss << "  serverIPV4Address = nullptr"; Log(ss); } // Class: const char*     
    if( result->serverIPV6Address ) { ss << "  serverIPV6Address " << result->serverIPV6Address; Log(ss); } else { ss << "  serverIPV6Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  serverPort " << result->serverPort; Log(ss); // Class: int32_t     
    if( result->serverPublicDNSName ) { ss << "  serverPublicDNSName " << result->serverPublicDNSName; Log(ss); } else { ss << "  serverPublicDNSName = nullptr"; Log(ss); } // Class: const char*     
    if( result->ticket ) { ss << "  ticket " << result->ticket; Log(ss); } else { ss << "  ticket = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogAuthUserRequest(PFMatchmakingAuthUserRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingAuthUserRequest struct:
    // request->authorizationTicket: const char*
    if( request->authorizationTicket ) { ss << "  authorizationTicket " << request->authorizationTicket; Log(ss); } else { ss << "  authorizationTicket = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingAuthUserResponse(PFMatchmakingAuthUserResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingAuthUserResponse    
    ss << "  authorized " << result->authorized; Log(ss); // Class: bool     
    if( result->playFabId ) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogPlayerJoinedRequest(PFMatchmakingPlayerJoinedRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingPlayerJoinedRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogPlayerLeftRequest(PFMatchmakingPlayerLeftRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingPlayerLeftRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogMatchmakerStartGameRequest(PFMatchmakingMatchmakerStartGameRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingStartGameRequest struct:
    // request->build: const char*
    if( request->build ) { ss << "  build " << request->build; Log(ss); } else { ss << "  build = nullptr"; Log(ss); } // Class: const char* 
    if( request->customCommandLineData ) { ss << "  customCommandLineData " << request->customCommandLineData; Log(ss); } else { ss << "  customCommandLineData = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->externalMatchmakerEventEndpoint ) { ss << "  externalMatchmakerEventEndpoint " << request->externalMatchmakerEventEndpoint; Log(ss); } else { ss << "  externalMatchmakerEventEndpoint = nullptr"; Log(ss); } // Class: const char* 
    if( request->gameMode ) { ss << "  gameMode " << request->gameMode; Log(ss); } else { ss << "  gameMode = nullptr"; Log(ss); } // Class: const char* 
    ss << "  region " << request->region; Log(ss); // Class: PFRegion 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingStartGameResponse(PFMatchmakingStartGameResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingStartGameResponse    
    if( result->gameID ) { ss << "  gameID " << result->gameID; Log(ss); } else { ss << "  gameID = nullptr"; Log(ss); } // Class: const char*     
    if( result->serverIPV4Address ) { ss << "  serverIPV4Address " << result->serverIPV4Address; Log(ss); } else { ss << "  serverIPV4Address = nullptr"; Log(ss); } // Class: const char*     
    if( result->serverIPV6Address ) { ss << "  serverIPV6Address " << result->serverIPV6Address; Log(ss); } else { ss << "  serverIPV6Address = nullptr"; Log(ss); } // Class: const char*     
    ss << "  serverPort " << result->serverPort; Log(ss); // Class: uint32_t     
    if( result->serverPublicDNSName ) { ss << "  serverPublicDNSName " << result->serverPublicDNSName; Log(ss); } else { ss << "  serverPublicDNSName = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogUserInfoRequest(PFMatchmakingUserInfoRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingUserInfoRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  minCatalogVersion " << request->minCatalogVersion; Log(ss); // Class: int32_t 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingUserInfoResponse(PFMatchmakingUserInfoResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingUserInfoResponse        
    ss << "  inventoryCount " << result->inventoryCount; Log(ss);

    // PFItemInstance
    for( uint32_t i=0; i<result->inventoryCount; i++ )
    {
            ss << "  result->inventory[" << i << "]:" << result->inventory[i]; Log(ss); // PFItemInstance
    }     
    ss << "  isDeveloper " << result->isDeveloper; Log(ss); // Class: bool     
    if( result->playFabId ) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    if( result->steamId ) { ss << "  steamId " << result->steamId; Log(ss); } else { ss << "  steamId = nullptr"; Log(ss); } // Class: const char*     
    if( result->titleDisplayName ) { ss << "  titleDisplayName " << result->titleDisplayName; Log(ss); } else { ss << "  titleDisplayName = nullptr"; Log(ss); } // Class: const char*     
    if( result->username ) { ss << "  username " << result->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char*         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for( uint32_t i=0; i<result->virtualCurrencyCount; i++ )
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyRechargeTimesCount " << result->virtualCurrencyRechargeTimesCount; Log(ss);

    // PFVirtualCurrencyRechargeTimeDictionaryEntry
    for( uint32_t i=0; i<result->virtualCurrencyRechargeTimesCount; i++ )
    {
            ss << "  result->virtualCurrencyRechargeTimes[" << i << "]:" << result->virtualCurrencyRechargeTimes[i].key << "=" << result->virtualCurrencyRechargeTimes[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenMatchmakingTests::LogDeregisterGameRequest(PFMatchmakingDeregisterGameRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingDeregisterGameRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogNotifyMatchmakerPlayerLeftRequest(PFMatchmakingNotifyMatchmakerPlayerLeftRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingNotifyMatchmakerPlayerLeftRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingNotifyMatchmakerPlayerLeftResult(PFMatchmakingNotifyMatchmakerPlayerLeftResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingNotifyMatchmakerPlayerLeftResult    
    ss << "  playerState " << result->playerState; Log(ss); // Class: PFMatchmakingPlayerConnectionState 
    return S_OK;
}

void AutoGenMatchmakingTests::LogRedeemMatchmakerTicketRequest(PFMatchmakingRedeemMatchmakerTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingRedeemMatchmakerTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    if( request->ticket ) { ss << "  ticket " << request->ticket; Log(ss); } else { ss << "  ticket = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingRedeemMatchmakerTicketResult(PFMatchmakingRedeemMatchmakerTicketResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingRedeemMatchmakerTicketResult    
    if( result->error ) { ss << "  error " << result->error; Log(ss); } else { ss << "  error = nullptr"; Log(ss); } // Class: const char*     
    ss << "  ticketIsValid " << result->ticketIsValid; Log(ss); // Class: bool     
    ss << "  userInfo " << result->userInfo; Log(ss); // Class: PFUserAccountInfo 
    return S_OK;
}

void AutoGenMatchmakingTests::LogRefreshGameServerInstanceHeartbeatRequest(PFMatchmakingRefreshGameServerInstanceHeartbeatRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingRefreshGameServerInstanceHeartbeatRequest struct:
    // request->lobbyId: const char*
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogRegisterGameRequest(PFMatchmakingRegisterGameRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingRegisterGameRequest struct:
    // request->build: const char*
    if( request->build ) { ss << "  build " << request->build; Log(ss); } else { ss << "  build = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->gameMode ) { ss << "  gameMode " << request->gameMode; Log(ss); } else { ss << "  gameMode = nullptr"; Log(ss); } // Class: const char* 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  region " << request->region; Log(ss); // Class: PFRegion 
    if( request->serverIPV4Address ) { ss << "  serverIPV4Address " << request->serverIPV4Address; Log(ss); } else { ss << "  serverIPV4Address = nullptr"; Log(ss); } // Class: const char* 
    if( request->serverIPV6Address ) { ss << "  serverIPV6Address " << request->serverIPV6Address; Log(ss); } else { ss << "  serverIPV6Address = nullptr"; Log(ss); } // Class: const char* 
    if( request->serverPort ) { ss << "  serverPort " << request->serverPort; Log(ss); } else { ss << "  serverPort = nullptr"; Log(ss); } // Class: const char* 
    if( request->serverPublicDNSName ) { ss << "  serverPublicDNSName " << request->serverPublicDNSName; Log(ss); } else { ss << "  serverPublicDNSName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  tagsCount " << request->tagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->tagsCount; i++ )
    {
            ss << "  request->tags[" << i << "]:" << request->tags[i].key << "=" << request->tags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingRegisterGameResponse(PFMatchmakingRegisterGameResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingRegisterGameResponse    
    if( result->lobbyId ) { ss << "  lobbyId " << result->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogSetGameServerInstanceDataRequest(PFMatchmakingSetGameServerInstanceDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingSetGameServerInstanceDataRequest struct:
    // request->gameServerData: const char*
    if( request->gameServerData ) { ss << "  gameServerData " << request->gameServerData; Log(ss); } else { ss << "  gameServerData = nullptr"; Log(ss); } // Class: const char* 
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogSetGameServerInstanceStateRequest(PFMatchmakingSetGameServerInstanceStateRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingSetGameServerInstanceStateRequest struct:
    // request->lobbyId: const char*
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  state " << request->state; Log(ss); // Class: PFMatchmakingGameInstanceState 

}

void AutoGenMatchmakingTests::LogSetGameServerInstanceTagsRequest(PFMatchmakingSetGameServerInstanceTagsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingSetGameServerInstanceTagsRequest struct:
    // request->lobbyId: const char*
    if( request->lobbyId ) { ss << "  lobbyId " << request->lobbyId; Log(ss); } else { ss << "  lobbyId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  tagsCount " << request->tagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->tagsCount; i++ )
    {
            ss << "  request->tags[" << i << "]:" << request->tags[i].key << "=" << request->tags[i].value; Log(ss);
            
    } 

}

void AutoGenMatchmakingTests::LogCancelAllMatchmakingTicketsForPlayerRequest(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCancelAllMatchmakingTicketsForPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCancelAllServerBackfillTicketsForPlayerRequest(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCancelAllServerBackfillTicketsForPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCancelMatchmakingTicketRequest(PFMatchmakingCancelMatchmakingTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCancelMatchmakingTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if( request->ticketId ) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCancelServerBackfillTicketRequest(PFMatchmakingCancelServerBackfillTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCancelServerBackfillTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if( request->ticketId ) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCreateMatchmakingTicketRequest(PFMatchmakingCreateMatchmakingTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCreateMatchmakingTicketRequest struct:
    // request->creator: PFMatchmakingMatchmakingPlayer const*
    ss << "  creator " << request->creator; Log(ss); // Class: PFMatchmakingMatchmakingPlayer     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  giveUpAfterSeconds " << request->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    ss << "  membersToMatchWithCount " << request->membersToMatchWithCount; Log(ss);

    // PFEntityKey
    for( uint32_t i=0; i<request->membersToMatchWithCount; i++ )
    {
            ss << "  request->membersToMatchWith[" << i << "]:" << request->membersToMatchWith[i]; Log(ss); // PFEntityKey
    } 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingCreateMatchmakingTicketResult(PFMatchmakingCreateMatchmakingTicketResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingCreateMatchmakingTicketResult    
    if( result->ticketId ) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogCreateServerBackfillTicketRequest(PFMatchmakingCreateServerBackfillTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCreateServerBackfillTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  giveUpAfterSeconds " << request->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    for( uint32_t i=0; i<request->membersCount; i++ )
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    } 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  serverDetails " << request->serverDetails; Log(ss); // Class: PFMatchmakingServerDetails 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingCreateServerBackfillTicketResult(PFMatchmakingCreateServerBackfillTicketResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingCreateServerBackfillTicketResult    
    if( result->ticketId ) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogCreateServerMatchmakingTicketRequest(PFMatchmakingCreateServerMatchmakingTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingCreateServerMatchmakingTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  giveUpAfterSeconds " << request->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayer
    for( uint32_t i=0; i<request->membersCount; i++ )
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayer
    } 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogGetMatchRequest(PFMatchmakingGetMatchRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGetMatchRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  escapeObject " << request->escapeObject; Log(ss); // Class: bool 
    if( request->matchId ) { ss << "  matchId " << request->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char* 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  returnMemberAttributes " << request->returnMemberAttributes; Log(ss); // Class: bool 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGetMatchResult(PFMatchmakingGetMatchResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetMatchResult    
    if( result->matchId ) { ss << "  matchId " << result->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    for( uint32_t i=0; i<result->membersCount; i++ )
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    }         
    ss << "  regionPreferencesCount " << result->regionPreferencesCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<result->regionPreferencesCount; i++ )
    {
            ss << "  result->regionPreferences[" << i << "]:" << result->regionPreferences[i]; Log(ss); // const char*
    }     
    ss << "  serverDetails " << result->serverDetails; Log(ss); // Class: PFMatchmakingServerDetails 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGetMatchmakingTicketRequest(PFMatchmakingGetMatchmakingTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGetMatchmakingTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  escapeObject " << request->escapeObject; Log(ss); // Class: bool 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if( request->ticketId ) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGetMatchmakingTicketResult(PFMatchmakingGetMatchmakingTicketResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetMatchmakingTicketResult    
    if( result->cancellationReasonString ) { ss << "  cancellationReasonString " << result->cancellationReasonString; Log(ss); } else { ss << "  cancellationReasonString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  created " << result->created; Log(ss); // Class: time_t     
    ss << "  creator " << result->creator; Log(ss); // Class: PFEntityKey     
    ss << "  giveUpAfterSeconds " << result->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    if( result->matchId ) { ss << "  matchId " << result->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayer
    for( uint32_t i=0; i<result->membersCount; i++ )
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayer
    }         
    ss << "  membersToMatchWithCount " << result->membersToMatchWithCount; Log(ss);

    // PFEntityKey
    for( uint32_t i=0; i<result->membersToMatchWithCount; i++ )
    {
            ss << "  result->membersToMatchWith[" << i << "]:" << result->membersToMatchWith[i]; Log(ss); // PFEntityKey
    }     
    if( result->queueName ) { ss << "  queueName " << result->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char*     
    if( result->status ) { ss << "  status " << result->status; Log(ss); } else { ss << "  status = nullptr"; Log(ss); } // Class: const char*     
    if( result->ticketId ) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGetQueueStatisticsRequest(PFMatchmakingGetQueueStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGetQueueStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGetQueueStatisticsResult(PFMatchmakingGetQueueStatisticsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetQueueStatisticsResult    
    ss << "  numberOfPlayersMatching " << result->numberOfPlayersMatching; Log(ss); // Class: uint32_t     
    ss << "  timeToMatchStatisticsInSeconds " << result->timeToMatchStatisticsInSeconds; Log(ss); // Class: PFMatchmakingStatistics 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGetServerBackfillTicketRequest(PFMatchmakingGetServerBackfillTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingGetServerBackfillTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  escapeObject " << request->escapeObject; Log(ss); // Class: bool 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if( request->ticketId ) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingGetServerBackfillTicketResult(PFMatchmakingGetServerBackfillTicketResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetServerBackfillTicketResult    
    if( result->cancellationReasonString ) { ss << "  cancellationReasonString " << result->cancellationReasonString; Log(ss); } else { ss << "  cancellationReasonString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  created " << result->created; Log(ss); // Class: time_t     
    ss << "  giveUpAfterSeconds " << result->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    if( result->matchId ) { ss << "  matchId " << result->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    for( uint32_t i=0; i<result->membersCount; i++ )
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    }     
    if( result->queueName ) { ss << "  queueName " << result->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  serverDetails " << result->serverDetails; Log(ss); // Class: PFMatchmakingServerDetails     
    if( result->status ) { ss << "  status " << result->status; Log(ss); } else { ss << "  status = nullptr"; Log(ss); } // Class: const char*     
    if( result->ticketId ) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogJoinMatchmakingTicketRequest(PFMatchmakingJoinMatchmakingTicketRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingJoinMatchmakingTicketRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  member " << request->member; Log(ss); // Class: PFMatchmakingMatchmakingPlayer 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if( request->ticketId ) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogListMatchmakingTicketsForPlayerRequest(PFMatchmakingListMatchmakingTicketsForPlayerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingListMatchmakingTicketsForPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingListMatchmakingTicketsForPlayerResult(PFMatchmakingListMatchmakingTicketsForPlayerResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingListMatchmakingTicketsForPlayerResult        
    ss << "  ticketIdsCount " << result->ticketIdsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<result->ticketIdsCount; i++ )
    {
            ss << "  result->ticketIds[" << i << "]:" << result->ticketIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenMatchmakingTests::LogListServerBackfillTicketsForPlayerRequest(PFMatchmakingListServerBackfillTicketsForPlayerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_MatchmakingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabMatchmakingListServerBackfillTicketsForPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->queueName ) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogPFMatchmakingListServerBackfillTicketsForPlayerResult(PFMatchmakingListServerBackfillTicketsForPlayerResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingListServerBackfillTicketsForPlayerResult        
    ss << "  ticketIdsCount " << result->ticketIdsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<result->ticketIdsCount; i++ )
    {
            ss << "  result->ticketIds[" << i << "]:" << result->ticketIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

 

}
