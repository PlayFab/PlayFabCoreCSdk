#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayerDataManagementTests.h"
#include "XAsyncHelper.h"

uint32_t g_PlayerDataManagementTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenPlayerDataManagementTests::LogCreatePlayerStatisticDefinitionRequest(PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementCreatePlayerStatisticDefinitionRequest struct:
    // request->aggregationMethod: PFPlayerDataManagementStatisticAggregationMethod const*
    ss << "  aggregationMethod " << request->aggregationMethod; Log(ss); // Class: PFPlayerDataManagementStatisticAggregationMethod     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  versionChangeInterval " << request->versionChangeInterval; Log(ss); // Class: PFPlayerDataManagementStatisticResetIntervalOption 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementCreatePlayerStatisticDefinitionResult(PFPlayerDataManagementCreatePlayerStatisticDefinitionResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementCreatePlayerStatisticDefinitionResult    
    ss << "  statistic " << result->statistic; Log(ss); // Class: PFPlayerDataManagementPlayerStatisticDefinition 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetDataReportRequest(PFPlayerDataManagementGetDataReportRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetDataReportRequest struct:
    // request->day: int32_t
    ss << "  day " << request->day; Log(ss); // Class: int32_t 
    ss << "  month " << request->month; Log(ss); // Class: int32_t 
    if( request->reportName ) { ss << "  reportName " << request->reportName; Log(ss); } else { ss << "  reportName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  year " << request->year; Log(ss); // Class: int32_t 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetDataReportResult(PFPlayerDataManagementGetDataReportResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetDataReportResult    
    if( result->downloadUrl ) { ss << "  downloadUrl " << result->downloadUrl; Log(ss); } else { ss << "  downloadUrl = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetPlayerStatisticDefinitionsResult(PFPlayerDataManagementGetPlayerStatisticDefinitionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetPlayerStatisticDefinitionsResult        
    ss << "  statisticsCount " << result->statisticsCount; Log(ss);

    // PFPlayerDataManagementPlayerStatisticDefinition
    for( uint32_t i=0; i<result->statisticsCount; i++ )
    {
            ss << "  result->statistics[" << i << "]:" << result->statistics[i]; Log(ss); // PFPlayerDataManagementPlayerStatisticDefinition
    } 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetPlayerStatisticVersionsRequest(PFPlayerDataManagementGetPlayerStatisticVersionsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetPlayerStatisticVersionsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetPlayerStatisticVersionsResult(PFPlayerDataManagementGetPlayerStatisticVersionsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetPlayerStatisticVersionsResult        
    ss << "  statisticVersionsCount " << result->statisticVersionsCount; Log(ss);

    // PFPlayerDataManagementPlayerStatisticVersion
    for( uint32_t i=0; i<result->statisticVersionsCount; i++ )
    {
            ss << "  result->statisticVersions[" << i << "]:" << result->statisticVersions[i]; Log(ss); // PFPlayerDataManagementPlayerStatisticVersion
    } 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetUserDataRequest(PFPlayerDataManagementGetUserDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetUserDataRequest struct:
    // request->ifChangedFromDataVersion: uint32_t const*
    ss << "  ifChangedFromDataVersion " << request->ifChangedFromDataVersion; Log(ss); // Class: uint32_t     
    ss << "  keysCount " << request->keysCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->keysCount; i++ )
    {
            ss << "  request->keys[" << i << "]:" << request->keys[i]; Log(ss); // const char*
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementAdminGetUserDataResult(PFPlayerDataManagementAdminGetUserDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementAdminGetUserDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFUserDataRecordDictionaryEntry
    for( uint32_t i=0; i<result->dataCount; i++ )
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }     
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t     
    if( result->playFabId ) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogIncrementPlayerStatisticVersionRequest(PFPlayerDataManagementIncrementPlayerStatisticVersionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementIncrementPlayerStatisticVersionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementIncrementPlayerStatisticVersionResult(PFPlayerDataManagementIncrementPlayerStatisticVersionResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementIncrementPlayerStatisticVersionResult    
    ss << "  statisticVersion " << result->statisticVersion; Log(ss); // Class: PFPlayerDataManagementPlayerStatisticVersion 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogRefundPurchaseRequest(PFPlayerDataManagementRefundPurchaseRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementRefundPurchaseRequest struct:
    // request->orderId: const char*
    if( request->orderId ) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->reason ) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementRefundPurchaseResponse(PFPlayerDataManagementRefundPurchaseResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementRefundPurchaseResponse    
    if( result->purchaseStatus ) { ss << "  purchaseStatus " << result->purchaseStatus; Log(ss); } else { ss << "  purchaseStatus = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogResetUserStatisticsRequest(PFPlayerDataManagementResetUserStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementResetUserStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerDataManagementTests::LogResolvePurchaseDisputeRequest(PFPlayerDataManagementResolvePurchaseDisputeRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementResolvePurchaseDisputeRequest struct:
    // request->orderId: const char*
    if( request->orderId ) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  outcome " << request->outcome; Log(ss); // Class: PFPlayerDataManagementResolutionOutcome 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->reason ) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementResolvePurchaseDisputeResponse(PFPlayerDataManagementResolvePurchaseDisputeResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementResolvePurchaseDisputeResponse    
    if( result->purchaseStatus ) { ss << "  purchaseStatus " << result->purchaseStatus; Log(ss); } else { ss << "  purchaseStatus = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogUpdatePlayerStatisticDefinitionRequest(PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdatePlayerStatisticDefinitionRequest struct:
    // request->aggregationMethod: PFPlayerDataManagementStatisticAggregationMethod const*
    ss << "  aggregationMethod " << request->aggregationMethod; Log(ss); // Class: PFPlayerDataManagementStatisticAggregationMethod 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  versionChangeInterval " << request->versionChangeInterval; Log(ss); // Class: PFPlayerDataManagementStatisticResetIntervalOption 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementUpdatePlayerStatisticDefinitionResult(PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementUpdatePlayerStatisticDefinitionResult    
    ss << "  statistic " << result->statistic; Log(ss); // Class: PFPlayerDataManagementPlayerStatisticDefinition 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogAdminUpdateUserDataRequest(PFPlayerDataManagementAdminUpdateUserDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementUpdateUserDataResult(PFPlayerDataManagementUpdateUserDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementUpdateUserDataResult    
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogUpdateUserInternalDataRequest(PFPlayerDataManagementUpdateUserInternalDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserInternalDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerDataManagementTests::LogClientGetFriendLeaderboardRequest(PFPlayerDataManagementClientGetFriendLeaderboardRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetFriendLeaderboardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeFacebookFriends " << request->includeFacebookFriends; Log(ss); // Class: bool 
    ss << "  includeSteamFriends " << request->includeSteamFriends; Log(ss); // Class: bool 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 
    if( request->xboxToken ) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetLeaderboardResult(PFPlayerDataManagementGetLeaderboardResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetLeaderboardResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFPlayerDataManagementPlayerLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFPlayerDataManagementPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetFriendLeaderboardAroundPlayerRequest(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeFacebookFriends " << request->includeFacebookFriends; Log(ss); // Class: bool 
    ss << "  includeSteamFriends " << request->includeSteamFriends; Log(ss); // Class: bool 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 
    if( request->xboxToken ) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetFriendLeaderboardAroundPlayerResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFPlayerDataManagementPlayerLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFPlayerDataManagementPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetLeaderboardRequest(PFPlayerDataManagementGetLeaderboardRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetLeaderboardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

void AutoGenPlayerDataManagementTests::LogGetLeaderboardAroundPlayerRequest(PFPlayerDataManagementGetLeaderboardAroundPlayerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetLeaderboardAroundPlayerRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetLeaderboardAroundPlayerResult(PFPlayerDataManagementGetLeaderboardAroundPlayerResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetLeaderboardAroundPlayerResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFPlayerDataManagementPlayerLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFPlayerDataManagementPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogClientGetPlayerStatisticsRequest(PFPlayerDataManagementClientGetPlayerStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetPlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  statisticNamesCount " << request->statisticNamesCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->statisticNamesCount; i++ )
    {
            ss << "  request->statisticNames[" << i << "]:" << request->statisticNames[i]; Log(ss); // const char*
    }     
    ss << "  statisticNameVersionsCount " << request->statisticNameVersionsCount; Log(ss);

    // PFPlayerDataManagementStatisticNameVersion
    for( uint32_t i=0; i<request->statisticNameVersionsCount; i++ )
    {
            ss << "  request->statisticNameVersions[" << i << "]:" << request->statisticNameVersions[i]; Log(ss); // PFPlayerDataManagementStatisticNameVersion
    } 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementClientGetPlayerStatisticsResult(PFPlayerDataManagementClientGetPlayerStatisticsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementClientGetPlayerStatisticsResult        
    ss << "  statisticsCount " << result->statisticsCount; Log(ss);

    // PFStatisticValue
    for( uint32_t i=0; i<result->statisticsCount; i++ )
    {
            ss << "  result->statistics[" << i << "]:" << result->statistics[i]; Log(ss); // PFStatisticValue
    } 
    return S_OK;
}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementClientGetUserDataResult(PFPlayerDataManagementClientGetUserDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementClientGetUserDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFUserDataRecordDictionaryEntry
    for( uint32_t i=0; i<result->dataCount; i++ )
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }     
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogClientUpdatePlayerStatisticsRequest(PFPlayerDataManagementClientUpdatePlayerStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdatePlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  statisticsCount " << request->statisticsCount; Log(ss);

    // PFPlayerDataManagementStatisticUpdate
    for( uint32_t i=0; i<request->statisticsCount; i++ )
    {
            ss << "  request->statistics[" << i << "]:" << request->statistics[i]; Log(ss); // PFPlayerDataManagementStatisticUpdate
    } 

}

void AutoGenPlayerDataManagementTests::LogClientUpdateUserDataRequest(PFPlayerDataManagementClientUpdateUserDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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

void AutoGenPlayerDataManagementTests::LogServerGetFriendLeaderboardRequest(PFPlayerDataManagementServerGetFriendLeaderboardRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetFriendLeaderboardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  includeFacebookFriends " << request->includeFacebookFriends; Log(ss); // Class: bool 
    ss << "  includeSteamFriends " << request->includeSteamFriends; Log(ss); // Class: bool 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    ss << "  startPosition " << request->startPosition; Log(ss); // Class: int32_t 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 
    if( request->xboxToken ) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerDataManagementTests::LogGetLeaderboardAroundUserRequest(PFPlayerDataManagementGetLeaderboardAroundUserRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetLeaderboardAroundUserRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  maxResultsCount " << request->maxResultsCount; Log(ss); // Class: int32_t 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if( request->statisticName ) { ss << "  statisticName " << request->statisticName; Log(ss); } else { ss << "  statisticName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  version " << request->version; Log(ss); // Class: int32_t 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementGetLeaderboardAroundUserResult(PFPlayerDataManagementGetLeaderboardAroundUserResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetLeaderboardAroundUserResult        
    ss << "  leaderboardCount " << result->leaderboardCount; Log(ss);

    // PFPlayerDataManagementPlayerLeaderboardEntry
    for( uint32_t i=0; i<result->leaderboardCount; i++ )
    {
            ss << "  result->leaderboard[" << i << "]:" << result->leaderboard[i]; Log(ss); // PFPlayerDataManagementPlayerLeaderboardEntry
    }     
    ss << "  nextReset " << result->nextReset; Log(ss); // Class: time_t     
    ss << "  version " << result->version; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetPlayerCombinedInfoRequest(PFGetPlayerCombinedInfoRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetPlayerCombinedInfoRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFGetPlayerCombinedInfoResult(PFGetPlayerCombinedInfoResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetPlayerCombinedInfoResult    
    ss << "  infoResultPayload " << result->infoResultPayload; Log(ss); // Class: PFGetPlayerCombinedInfoResultPayload     
    if( result->playFabId ) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogServerGetPlayerStatisticsRequest(PFPlayerDataManagementServerGetPlayerStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetPlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  statisticNamesCount " << request->statisticNamesCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->statisticNamesCount; i++ )
    {
            ss << "  request->statisticNames[" << i << "]:" << request->statisticNames[i]; Log(ss); // const char*
    }     
    ss << "  statisticNameVersionsCount " << request->statisticNameVersionsCount; Log(ss);

    // PFPlayerDataManagementStatisticNameVersion
    for( uint32_t i=0; i<request->statisticNameVersionsCount; i++ )
    {
            ss << "  request->statisticNameVersions[" << i << "]:" << request->statisticNameVersions[i]; Log(ss); // PFPlayerDataManagementStatisticNameVersion
    } 

}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementServerGetPlayerStatisticsResult(PFPlayerDataManagementServerGetPlayerStatisticsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementServerGetPlayerStatisticsResult    
    if( result->playFabId ) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  statisticsCount " << result->statisticsCount; Log(ss);

    // PFStatisticValue
    for( uint32_t i=0; i<result->statisticsCount; i++ )
    {
            ss << "  result->statistics[" << i << "]:" << result->statistics[i]; Log(ss); // PFStatisticValue
    } 
    return S_OK;
}

HRESULT AutoGenPlayerDataManagementTests::LogPFPlayerDataManagementServerGetUserDataResult(PFPlayerDataManagementServerGetUserDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementServerGetUserDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFUserDataRecordDictionaryEntry
    for( uint32_t i=0; i<result->dataCount; i++ )
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }     
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t     
    if( result->playFabId ) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogServerUpdatePlayerStatisticsRequest(PFPlayerDataManagementServerUpdatePlayerStatisticsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdatePlayerStatisticsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceUpdate " << request->forceUpdate; Log(ss); // Class: bool 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  statisticsCount " << request->statisticsCount; Log(ss);

    // PFPlayerDataManagementStatisticUpdate
    for( uint32_t i=0; i<request->statisticsCount; i++ )
    {
            ss << "  request->statistics[" << i << "]:" << request->statistics[i]; Log(ss); // PFPlayerDataManagementStatisticUpdate
    } 

}

void AutoGenPlayerDataManagementTests::LogServerUpdateUserDataRequest(PFPlayerDataManagementServerUpdateUserDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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

 

}
