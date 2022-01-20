#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenLeaderboardTests.h"
#include "XAsyncHelper.h"

uint32_t g_LeaderboardTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenLeaderboardTests::LogCreatePlayerStatisticDefinitionRequest(PFLeaderboardCreatePlayerStatisticDefinitionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardCreatePlayerStatisticDefinitionRequest struct:
    // request->aggregationMethod: PFLeaderboardStatisticAggregationMethod const*
    ss << "  aggregationMethod " << request->aggregationMethod; Log(ss); // Class: PFLeaderboardStatisticAggregationMethod     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  versionChangeInterval " << request->versionChangeInterval; Log(ss); // Class: PFLeaderboardStatisticResetIntervalOption 

}

HRESULT AutoGenLeaderboardTests::LogCreatePlayerStatisticDefinitionResult(PFLeaderboardCreatePlayerStatisticDefinitionResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardCreatePlayerStatisticDefinitionResult    
    ss << "  statistic " << result->statistic; Log(ss); // Class: PFLeaderboardPlayerStatisticDefinition 
    return S_OK;
}

HRESULT AutoGenLeaderboardTests::LogGetPlayerStatisticDefinitionsResult(PFLeaderboardGetPlayerStatisticDefinitionsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardGetPlayerStatisticDefinitionsResult        
    ss << "  statisticsCount " << result->statisticsCount; Log(ss);

    // PFLeaderboardPlayerStatisticDefinition
    for (uint32_t i=0; i<result->statisticsCount; i++)
    {
            ss << "  result->statistics[" << i << "]:" << result->statistics[i]; Log(ss); // PFLeaderboardPlayerStatisticDefinition
    } 
    return S_OK;
}

void AutoGenLeaderboardTests::LogGetPlayerStatisticVersionsRequest(PFLeaderboardGetPlayerStatisticVersionsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetPlayerStatisticVersionsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenLeaderboardTests::LogGetPlayerStatisticVersionsResult(PFLeaderboardGetPlayerStatisticVersionsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardGetPlayerStatisticVersionsResult        
    ss << "  statisticVersionsCount " << result->statisticVersionsCount; Log(ss);

    // PFLeaderboardPlayerStatisticVersion
    for (uint32_t i=0; i<result->statisticVersionsCount; i++)
    {
            ss << "  result->statisticVersions[" << i << "]:" << result->statisticVersions[i]; Log(ss); // PFLeaderboardPlayerStatisticVersion
    } 
    return S_OK;
}

void AutoGenLeaderboardTests::LogIncrementPlayerStatisticVersionRequest(PFLeaderboardIncrementPlayerStatisticVersionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardIncrementPlayerStatisticVersionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenLeaderboardTests::LogIncrementPlayerStatisticVersionResult(PFLeaderboardIncrementPlayerStatisticVersionResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardIncrementPlayerStatisticVersionResult    
    ss << "  statisticVersion " << result->statisticVersion; Log(ss); // Class: PFLeaderboardPlayerStatisticVersion 
    return S_OK;
}

void AutoGenLeaderboardTests::LogResetUserStatisticsRequest(PFLeaderboardResetUserStatisticsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardResetUserStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenLeaderboardTests::LogUpdatePlayerStatisticDefinitionRequest(PFLeaderboardUpdatePlayerStatisticDefinitionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardUpdatePlayerStatisticDefinitionRequest struct:
    // request->aggregationMethod: PFLeaderboardStatisticAggregationMethod const*
    ss << "  aggregationMethod " << request->aggregationMethod; Log(ss); // Class: PFLeaderboardStatisticAggregationMethod 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  versionChangeInterval " << request->versionChangeInterval; Log(ss); // Class: PFLeaderboardStatisticResetIntervalOption 

}

HRESULT AutoGenLeaderboardTests::LogUpdatePlayerStatisticDefinitionResult(PFLeaderboardUpdatePlayerStatisticDefinitionResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardUpdatePlayerStatisticDefinitionResult    
    ss << "  statistic " << result->statistic; Log(ss); // Class: PFLeaderboardPlayerStatisticDefinition 
    return S_OK;
}

void AutoGenLeaderboardTests::LogClientGetFriendLeaderboardRequest(PFLeaderboardClientGetFriendLeaderboardRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetFriendLeaderboardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeFacebookFriends " << request->includeFacebookFriends; Log(ss); // Class: bool 
    ss << "  includeSteamFriends " << request->includeSteamFriends; Log(ss); // Class: bool 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenLeaderboardTests::LogGetLeaderboardResult(PFLeaderboardGetLeaderboardResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardGetLeaderboardResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFLeaderboardPlayerLeaderboardEntry
    for (uint32_t i=0; i<result->leaderboardCount; i++)
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFLeaderboardPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenLeaderboardTests::LogGetFriendLeaderboardAroundPlayerRequest(PFLeaderboardGetFriendLeaderboardAroundPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetFriendLeaderboardAroundPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeFacebookFriends " << request->includeFacebookFriends; Log(ss); // Class: bool 
    ss << "  includeSteamFriends " << request->includeSteamFriends; Log(ss); // Class: bool 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenLeaderboardTests::LogGetFriendLeaderboardAroundPlayerResult(PFLeaderboardGetFriendLeaderboardAroundPlayerResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardGetFriendLeaderboardAroundPlayerResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFLeaderboardPlayerLeaderboardEntry
    for (uint32_t i=0; i<result->leaderboardCount; i++)
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFLeaderboardPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenLeaderboardTests::LogGetLeaderboardRequest(PFLeaderboardGetLeaderboardRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetLeaderboardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

void AutoGenLeaderboardTests::LogGetLeaderboardAroundPlayerRequest(PFLeaderboardGetLeaderboardAroundPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetLeaderboardAroundPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

HRESULT AutoGenLeaderboardTests::LogGetLeaderboardAroundPlayerResult(PFLeaderboardGetLeaderboardAroundPlayerResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardGetLeaderboardAroundPlayerResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFLeaderboardPlayerLeaderboardEntry
    for (uint32_t i=0; i<result->leaderboardCount; i++)
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFLeaderboardPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenLeaderboardTests::LogClientGetPlayerStatisticsRequest(PFLeaderboardClientGetPlayerStatisticsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetPlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  statisticNamesCount " << request->statisticNamesCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->statisticNamesCount; i++)
    {
            ss << "  request->statisticNames[" << i << "]:" << request->statisticNames[i]; Log(ss); // const char*
    }     
    ss << "  statisticNameVersionsCount " << request->statisticNameVersionsCount; Log(ss);

    // PFLeaderboardStatisticNameVersion
    for (uint32_t i=0; i<request->statisticNameVersionsCount; i++)
    {
            ss << "  request->statisticNameVersions[" << i << "]:" << request->statisticNameVersions[i]; Log(ss); // PFLeaderboardStatisticNameVersion
    } 

}

HRESULT AutoGenLeaderboardTests::LogClientGetPlayerStatisticsResult(PFLeaderboardClientGetPlayerStatisticsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardClientGetPlayerStatisticsResult        
    ss << "  statisticsCount " << result->statisticsCount; Log(ss);

    // PFStatisticValue
    for (uint32_t i=0; i<result->statisticsCount; i++)
    {
            ss << "  result->statistics[" << i << "]:" << result->statistics[i]; Log(ss); // PFStatisticValue
    } 
    return S_OK;
}

void AutoGenLeaderboardTests::LogClientUpdatePlayerStatisticsRequest(PFLeaderboardClientUpdatePlayerStatisticsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardUpdatePlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  statisticsCount " << request->statisticsCount; Log(ss);

    // PFLeaderboardStatisticUpdate
    for (uint32_t i=0; i<request->statisticsCount; i++)
    {
            ss << "  request->statistics[" << i << "]:" << request->statistics[i]; Log(ss); // PFLeaderboardStatisticUpdate
    } 

}

void AutoGenLeaderboardTests::LogServerGetFriendLeaderboardRequest(PFLeaderboardServerGetFriendLeaderboardRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetFriendLeaderboardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeFacebookFriends " << request->includeFacebookFriends; Log(ss); // Class: bool 
    ss << "  includeSteamFriends " << request->includeSteamFriends; Log(ss); // Class: bool 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenLeaderboardTests::LogGetLeaderboardAroundUserRequest(PFLeaderboardGetLeaderboardAroundUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetLeaderboardAroundUserRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if (request->statisticName) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

HRESULT AutoGenLeaderboardTests::LogGetLeaderboardAroundUserResult(PFLeaderboardGetLeaderboardAroundUserResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardGetLeaderboardAroundUserResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFLeaderboardPlayerLeaderboardEntry
    for (uint32_t i=0; i<result->leaderboardCount; i++)
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFLeaderboardPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenLeaderboardTests::LogServerGetPlayerStatisticsRequest(PFLeaderboardServerGetPlayerStatisticsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardGetPlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  statisticNamesCount " << request->statisticNamesCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->statisticNamesCount; i++)
    {
            ss << "  request->statisticNames[" << i << "]:" << request->statisticNames[i]; Log(ss); // const char*
    }     
    ss << "  statisticNameVersionsCount " << request->statisticNameVersionsCount; Log(ss);

    // PFLeaderboardStatisticNameVersion
    for (uint32_t i=0; i<request->statisticNameVersionsCount; i++)
    {
            ss << "  request->statisticNameVersions[" << i << "]:" << request->statisticNameVersions[i]; Log(ss); // PFLeaderboardStatisticNameVersion
    } 

}

HRESULT AutoGenLeaderboardTests::LogServerGetPlayerStatisticsResult(PFLeaderboardServerGetPlayerStatisticsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabLeaderboardServerGetPlayerStatisticsResult    
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  statisticsCount " << result->statisticsCount; Log(ss);

    // PFStatisticValue
    for (uint32_t i=0; i<result->statisticsCount; i++)
    {
            ss << "  result->statistics[" << i << "]:" << result->statistics[i]; Log(ss); // PFStatisticValue
    } 
    return S_OK;
}

void AutoGenLeaderboardTests::LogServerUpdatePlayerStatisticsRequest(PFLeaderboardServerUpdatePlayerStatisticsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_LeaderboardTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabLeaderboardUpdatePlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceUpdate " << request->forceUpdate; Log(ss); // Class: bool 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  statisticsCount " << request->statisticsCount; Log(ss);

    // PFLeaderboardStatisticUpdate
    for (uint32_t i=0; i<request->statisticsCount; i++)
    {
            ss << "  request->statistics[" << i << "]:" << request->statistics[i]; Log(ss); // PFLeaderboardStatisticUpdate
    } 

}

 

}
