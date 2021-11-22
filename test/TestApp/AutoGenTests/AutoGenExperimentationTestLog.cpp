#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenExperimentationTests.h"
#include "XAsyncHelper.h"

uint32_t g_ExperimentationTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenExperimentationTests::LogCreateExclusionGroupRequest(PFExperimentationCreateExclusionGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationCreateExclusionGroupRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationCreateExclusionGroupResult(PFExperimentationCreateExclusionGroupResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationCreateExclusionGroupResult
    if( result->exclusionGroupId ) { ss << "  exclusionGroupId " << result->exclusionGroupId; Log(ss); } else { ss << "  exclusionGroupId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenExperimentationTests::LogCreateExperimentRequest(PFExperimentationCreateExperimentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationCreateExperimentRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    ss << "  endDate " << request->endDate; Log(ss); // Class: time_t 
    if( request->exclusionGroupId ) { ss << "  exclusionGroupId " << request->exclusionGroupId; Log(ss); } else { ss << "  exclusionGroupId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  exclusionGroupTrafficAllocation " << request->exclusionGroupTrafficAllocation; Log(ss); // Class: uint32_t 
    ss << "  experimentType " << request->experimentType; Log(ss); // Class: PFExperimentationExperimentType 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    if( request->segmentId ) { ss << "  segmentId " << request->segmentId; Log(ss); } else { ss << "  segmentId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  startDate " << request->startDate; Log(ss); // Class: time_t     
    ss << "  titlePlayerAccountTestIdsCount " << request->titlePlayerAccountTestIdsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->titlePlayerAccountTestIdsCount; i++ )
    {
            ss << "  request->titlePlayerAccountTestIds[" << i << "]:" << request->titlePlayerAccountTestIds[i]; Log(ss); // const char*
    }     
    ss << "  variantsCount " << request->variantsCount; Log(ss);

    // PFExperimentationVariant
    for( uint32_t i=0; i<request->variantsCount; i++ )
    {
            ss << "  request->variants[" << i << "]:" << request->variants[i]; Log(ss); // PFExperimentationVariant
    } 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationCreateExperimentResult(PFExperimentationCreateExperimentResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationCreateExperimentResult
    if( result->experimentId ) { ss << "  experimentId " << result->experimentId; Log(ss); } else { ss << "  experimentId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenExperimentationTests::LogDeleteExclusionGroupRequest(PFExperimentationDeleteExclusionGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationDeleteExclusionGroupRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->exclusionGroupId ) { ss << "  exclusionGroupId " << request->exclusionGroupId; Log(ss); } else { ss << "  exclusionGroupId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenExperimentationTests::LogDeleteExperimentRequest(PFExperimentationDeleteExperimentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationDeleteExperimentRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->experimentId ) { ss << "  experimentId " << request->experimentId; Log(ss); } else { ss << "  experimentId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenExperimentationTests::LogGetExclusionGroupsRequest(PFExperimentationGetExclusionGroupsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationGetExclusionGroupsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationGetExclusionGroupsResult(PFExperimentationGetExclusionGroupsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationGetExclusionGroupsResult    
    ss << "  exclusionGroupsCount " << result->exclusionGroupsCount; Log(ss);

    // PFExperimentationExperimentExclusionGroup
    for( uint32_t i=0; i<result->exclusionGroupsCount; i++ )
    {
            ss << "  result->exclusionGroups[" << i << "]:" << result->exclusionGroups[i]; Log(ss); // PFExperimentationExperimentExclusionGroup
    } 
    return S_OK;
}

void AutoGenExperimentationTests::LogGetExclusionGroupTrafficRequest(PFExperimentationGetExclusionGroupTrafficRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationGetExclusionGroupTrafficRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->exclusionGroupId ) { ss << "  exclusionGroupId " << request->exclusionGroupId; Log(ss); } else { ss << "  exclusionGroupId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationGetExclusionGroupTrafficResult(PFExperimentationGetExclusionGroupTrafficResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationGetExclusionGroupTrafficResult    
    ss << "  trafficAllocationsCount " << result->trafficAllocationsCount; Log(ss);

    // PFExperimentationExclusionGroupTrafficAllocation
    for( uint32_t i=0; i<result->trafficAllocationsCount; i++ )
    {
            ss << "  result->trafficAllocations[" << i << "]:" << result->trafficAllocations[i]; Log(ss); // PFExperimentationExclusionGroupTrafficAllocation
    } 
    return S_OK;
}

void AutoGenExperimentationTests::LogGetExperimentsRequest(PFExperimentationGetExperimentsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationGetExperimentsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationGetExperimentsResult(PFExperimentationGetExperimentsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationGetExperimentsResult    
    ss << "  experimentsCount " << result->experimentsCount; Log(ss);

    // PFExperimentationExperiment
    for( uint32_t i=0; i<result->experimentsCount; i++ )
    {
            ss << "  result->experiments[" << i << "]:" << result->experiments[i]; Log(ss); // PFExperimentationExperiment
    } 
    return S_OK;
}

void AutoGenExperimentationTests::LogGetLatestScorecardRequest(PFExperimentationGetLatestScorecardRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationGetLatestScorecardRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->experimentId ) { ss << "  experimentId " << request->experimentId; Log(ss); } else { ss << "  experimentId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationGetLatestScorecardResult(PFExperimentationGetLatestScorecardResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationGetLatestScorecardResult
    ss << "  scorecard " << result->scorecard; Log(ss); // Class: PFExperimentationScorecard 
    return S_OK;
}

void AutoGenExperimentationTests::LogGetTreatmentAssignmentRequest(PFExperimentationGetTreatmentAssignmentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationGetTreatmentAssignmentRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenExperimentationTests::LogPFExperimentationGetTreatmentAssignmentResult(PFExperimentationGetTreatmentAssignmentResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabExperimentationGetTreatmentAssignmentResult
    ss << "  treatmentAssignment " << result->treatmentAssignment; Log(ss); // Class: PFTreatmentAssignment 
    return S_OK;
}

void AutoGenExperimentationTests::LogStartExperimentRequest(PFExperimentationStartExperimentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationStartExperimentRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->experimentId ) { ss << "  experimentId " << request->experimentId; Log(ss); } else { ss << "  experimentId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenExperimentationTests::LogStopExperimentRequest(PFExperimentationStopExperimentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationStopExperimentRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->experimentId ) { ss << "  experimentId " << request->experimentId; Log(ss); } else { ss << "  experimentId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenExperimentationTests::LogUpdateExclusionGroupRequest(PFExperimentationUpdateExclusionGroupRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationUpdateExclusionGroupRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    if( request->exclusionGroupId ) { ss << "  exclusionGroupId " << request->exclusionGroupId; Log(ss); } else { ss << "  exclusionGroupId = nullptr"; Log(ss); } // Class: const char* 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenExperimentationTests::LogUpdateExperimentRequest(PFExperimentationUpdateExperimentRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_ExperimentationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabExperimentationUpdateExperimentRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->description ) { ss << "  description " << request->description; Log(ss); } else { ss << "  description = nullptr"; Log(ss); } // Class: const char* 
    ss << "  endDate " << request->endDate; Log(ss); // Class: time_t 
    if( request->exclusionGroupId ) { ss << "  exclusionGroupId " << request->exclusionGroupId; Log(ss); } else { ss << "  exclusionGroupId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  exclusionGroupTrafficAllocation " << request->exclusionGroupTrafficAllocation; Log(ss); // Class: uint32_t 
    ss << "  experimentType " << request->experimentType; Log(ss); // Class: PFExperimentationExperimentType 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    if( request->segmentId ) { ss << "  segmentId " << request->segmentId; Log(ss); } else { ss << "  segmentId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  startDate " << request->startDate; Log(ss); // Class: time_t     
    ss << "  titlePlayerAccountTestIdsCount " << request->titlePlayerAccountTestIdsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->titlePlayerAccountTestIdsCount; i++ )
    {
            ss << "  request->titlePlayerAccountTestIds[" << i << "]:" << request->titlePlayerAccountTestIds[i]; Log(ss); // const char*
    }     
    ss << "  variantsCount " << request->variantsCount; Log(ss);

    // PFExperimentationVariant
    for( uint32_t i=0; i<request->variantsCount; i++ )
    {
            ss << "  request->variants[" << i << "]:" << request->variants[i]; Log(ss); // PFExperimentationVariant
    } 

}

 

}
