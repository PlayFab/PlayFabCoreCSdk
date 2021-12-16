#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAdvertisingTests.h"
#include "XAsyncHelper.h"

uint32_t g_AdvertisingTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenAdvertisingTests::LogAttributeInstallRequest(PFAdvertisingAttributeInstallRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AdvertisingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAdvertisingAttributeInstallRequest struct:
    // request->adid: const char*
    if( request->adid ) { ss << "  adid " << request->adid; Log(ss); } else { ss << "  adid = nullptr"; Log(ss); } // Class: const char* 
    if( request->idfa ) { ss << "  idfa " << request->idfa; Log(ss); } else { ss << "  idfa = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAdvertisingTests::LogGetAdPlacementsRequest(PFAdvertisingGetAdPlacementsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AdvertisingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAdvertisingGetAdPlacementsRequest struct:
    // request->appId: const char*
    if( request->appId ) { ss << "  appId " << request->appId; Log(ss); } else { ss << "  appId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  identifier " << request->identifier; Log(ss); // Class: PFNameIdentifier 

}

HRESULT AutoGenAdvertisingTests::LogPFAdvertisingGetAdPlacementsResult(PFAdvertisingGetAdPlacementsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAdvertisingGetAdPlacementsResult        
    ss << "  adPlacementsCount " << result->adPlacementsCount; Log(ss);

    // PFAdvertisingAdPlacementDetails
    for( uint32_t i=0; i<result->adPlacementsCount; i++ )
    {
            ss << "  result->adPlacements[" << i << "]:" << result->adPlacements[i]; Log(ss); // PFAdvertisingAdPlacementDetails
    } 
    return S_OK;
}

void AutoGenAdvertisingTests::LogReportAdActivityRequest(PFAdvertisingReportAdActivityRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AdvertisingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAdvertisingReportAdActivityRequest struct:
    // request->activity: PFAdvertisingAdActivity
    ss << "  activity " << request->activity; Log(ss); // Class: PFAdvertisingAdActivity     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->placementId ) { ss << "  placementId " << request->placementId; Log(ss); } else { ss << "  placementId = nullptr"; Log(ss); } // Class: const char* 
    if( request->rewardId ) { ss << "  rewardId " << request->rewardId; Log(ss); } else { ss << "  rewardId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAdvertisingTests::LogRewardAdActivityRequest(PFAdvertisingRewardAdActivityRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AdvertisingTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAdvertisingRewardAdActivityRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->placementId ) { ss << "  placementId " << request->placementId; Log(ss); } else { ss << "  placementId = nullptr"; Log(ss); } // Class: const char* 
    if( request->rewardId ) { ss << "  rewardId " << request->rewardId; Log(ss); } else { ss << "  rewardId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAdvertisingTests::LogPFAdvertisingRewardAdActivityResult(PFAdvertisingRewardAdActivityResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAdvertisingRewardAdActivityResult    
    if( result->adActivityEventId ) { ss << "  adActivityEventId " << result->adActivityEventId; Log(ss); } else { ss << "  adActivityEventId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  debugResultsCount " << result->debugResultsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<result->debugResultsCount; i++ )
    {
            ss << "  result->debugResults[" << i << "]:" << result->debugResults[i]; Log(ss); // const char*
    }     
    if( result->placementId ) { ss << "  placementId " << result->placementId; Log(ss); } else { ss << "  placementId = nullptr"; Log(ss); } // Class: const char*     
    if( result->placementName ) { ss << "  placementName " << result->placementName; Log(ss); } else { ss << "  placementName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  placementViewsRemaining " << result->placementViewsRemaining; Log(ss); // Class: int32_t     
    ss << "  placementViewsResetMinutes " << result->placementViewsResetMinutes; Log(ss); // Class: double     
    ss << "  rewardResults " << result->rewardResults; Log(ss); // Class: PFAdvertisingAdRewardResults 
    return S_OK;
}

 

}
