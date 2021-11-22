#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCharacterTests.h"
#include "XAsyncHelper.h"

uint32_t g_CharacterTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenCharacterTests::LogResetCharacterStatisticsRequest(PFCharacterResetCharacterStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterResetCharacterStatisticsRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCharacterTests::LogListUsersCharactersRequest(PFCharacterListUsersCharactersRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterListUsersCharactersRequest struct:
    // request->playFabId: const char*
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterListUsersCharactersResult(PFCharacterListUsersCharactersResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCharacterListUsersCharactersResult    
    ss << "  charactersCount " << result->charactersCount; Log(ss);

    // PFCharacterResult
    for( uint32_t i=0; i<result->charactersCount; i++ )
    {
            ss << "  result->characters[" << i << "]:" << result->characters[i]; Log(ss); // PFCharacterResult
    } 
    return S_OK;
}

void AutoGenCharacterTests::LogGetCharacterDataRequest(PFCharacterGetCharacterDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetCharacterDataRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  ifChangedFromDataVersion " << request->ifChangedFromDataVersion; Log(ss); // Class: uint32_t     
    ss << "  keysCount " << request->keysCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->keysCount; i++ )
    {
            ss << "  request->keys[" << i << "]:" << request->keys[i]; Log(ss); // const char*
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterClientGetCharacterDataResult(PFCharacterClientGetCharacterDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    return S_OK;
}

void AutoGenCharacterTests::LogGetCharacterLeaderboardRequest(PFCharacterGetCharacterLeaderboardRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetCharacterLeaderboardRequest struct:
    // request->characterType: const char*
    if( request->characterType ) { ss << "  characterType " << request->characterType; Log(ss); } else { ss << "  characterType = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterGetCharacterLeaderboardResult(PFCharacterGetCharacterLeaderboardResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCharacterGetCharacterLeaderboardResult    
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFCharacterCharacterLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFCharacterCharacterLeaderboardEntry
    } 
    return S_OK;
}

void AutoGenCharacterTests::LogClientGetCharacterStatisticsRequest(PFCharacterClientGetCharacterStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetCharacterStatisticsRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterClientGetCharacterStatisticsResult(PFCharacterClientGetCharacterStatisticsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    return S_OK;
}

void AutoGenCharacterTests::LogClientGetLeaderboardAroundCharacterRequest(PFCharacterClientGetLeaderboardAroundCharacterRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetLeaderboardAroundCharacterRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if( request->characterType ) { ss << "  characterType " << request->characterType; Log(ss); } else { ss << "  characterType = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterGetLeaderboardAroundCharacterResult(PFCharacterGetLeaderboardAroundCharacterResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCharacterGetLeaderboardAroundCharacterResult    
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFCharacterCharacterLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFCharacterCharacterLeaderboardEntry
    } 
    return S_OK;
}

void AutoGenCharacterTests::LogClientGetLeaderboardForUsersCharactersRequest(PFCharacterClientGetLeaderboardForUsersCharactersRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetLeaderboardForUsersCharactersRequest struct:
    // request->statisticName: const char*
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterGetLeaderboardForUsersCharactersResult(PFCharacterGetLeaderboardForUsersCharactersResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCharacterGetLeaderboardForUsersCharactersResult    
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFCharacterCharacterLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFCharacterCharacterLeaderboardEntry
    } 
    return S_OK;
}

void AutoGenCharacterTests::LogClientGrantCharacterToUserRequest(PFCharacterClientGrantCharacterToUserRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGrantCharacterToUserRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if( request->characterName ) { ss << "  characterName " << request->characterName; Log(ss); } else { ss << "  characterName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->itemId ) { ss << "  itemId " << request->itemId; Log(ss); } else { ss << "  itemId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterClientGrantCharacterToUserResult(PFCharacterClientGrantCharacterToUserResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    return S_OK;
}

void AutoGenCharacterTests::LogClientUpdateCharacterDataRequest(PFCharacterClientUpdateCharacterDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterUpdateCharacterDataRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  dataCount " << request->dataCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->dataCount; i++ )
    {
            ss << "  request->data[" << i << "]:" << request->data[i].key << "=" << request->data[i].value; Log(ss);
            
    }     
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->keysToRemoveCount; i++ )
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    ss << "  permission " << request->permission; Log(ss); // Class: PFUserDataPermission 

}

HRESULT AutoGenCharacterTests::LogPFCharacterUpdateCharacterDataResult(PFCharacterUpdateCharacterDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCharacterUpdateCharacterDataResult
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t 
    return S_OK;
}

void AutoGenCharacterTests::LogClientUpdateCharacterStatisticsRequest(PFCharacterClientUpdateCharacterStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterUpdateCharacterStatisticsRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  characterStatisticsCount " << request->characterStatisticsCount; Log(ss);

    // PFInt32DictionaryEntry
    for( uint32_t i=0; i<request->characterStatisticsCount; i++ )
    {
            ss << "  request->characterStatistics[" << i << "]:" << request->characterStatistics[i].key << "=" << request->characterStatistics[i].value; Log(ss);
            
    }     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenCharacterTests::LogDeleteCharacterFromUserRequest(PFCharacterDeleteCharacterFromUserRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterDeleteCharacterFromUserRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  saveCharacterInventory " << request->saveCharacterInventory; Log(ss); // Class: bool 

}

HRESULT AutoGenCharacterTests::LogPFCharacterServerGetCharacterDataResult(PFCharacterServerGetCharacterDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    return S_OK;
}

void AutoGenCharacterTests::LogServerGetCharacterStatisticsRequest(PFCharacterServerGetCharacterStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetCharacterStatisticsRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterServerGetCharacterStatisticsResult(PFCharacterServerGetCharacterStatisticsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    return S_OK;
}

void AutoGenCharacterTests::LogServerGetLeaderboardAroundCharacterRequest(PFCharacterServerGetLeaderboardAroundCharacterRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetLeaderboardAroundCharacterRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if( request->characterType ) { ss << "  characterType " << request->characterType; Log(ss); } else { ss << "  characterType = nullptr"; Log(ss); } // Class: const char* 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCharacterTests::LogServerGetLeaderboardForUsersCharactersRequest(PFCharacterServerGetLeaderboardForUsersCharactersRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGetLeaderboardForUsersCharactersRequest struct:
    // request->playFabId: const char*
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCharacterTests::LogServerGrantCharacterToUserRequest(PFCharacterServerGrantCharacterToUserRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterGrantCharacterToUserRequest struct:
    // request->characterName: const char*
    if( request->characterName ) { ss << "  characterName " << request->characterName; Log(ss); } else { ss << "  characterName = nullptr"; Log(ss); } // Class: const char* 
    if( request->characterType ) { ss << "  characterType " << request->characterType; Log(ss); } else { ss << "  characterType = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCharacterTests::LogPFCharacterServerGrantCharacterToUserResult(PFCharacterServerGrantCharacterToUserResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    return S_OK;
}

void AutoGenCharacterTests::LogServerUpdateCharacterDataRequest(PFCharacterServerUpdateCharacterDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterUpdateCharacterDataRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  dataCount " << request->dataCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->dataCount; i++ )
    {
            ss << "  request->data[" << i << "]:" << request->data[i].key << "=" << request->data[i].value; Log(ss);
            
    }     
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->keysToRemoveCount; i++ )
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    ss << "  permission " << request->permission; Log(ss); // Class: PFUserDataPermission 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCharacterTests::LogServerUpdateCharacterStatisticsRequest(PFCharacterServerUpdateCharacterStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CharacterTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCharacterUpdateCharacterStatisticsRequest struct:
    // request->characterId: const char*
    if( request->characterId ) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  characterStatisticsCount " << request->characterStatisticsCount; Log(ss);

    // PFInt32DictionaryEntry
    for( uint32_t i=0; i<request->characterStatisticsCount; i++ )
    {
            ss << "  request->characterStatistics[" << i << "]:" << request->characterStatistics[i].key << "=" << request->characterStatistics[i].value; Log(ss);
            
    }     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
