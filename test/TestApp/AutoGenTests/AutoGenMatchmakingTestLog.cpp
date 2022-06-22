#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenMatchmakingTests.h"
#include "XAsyncHelper.h"

uint32_t g_MatchmakingTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenMatchmakingTests::LogCancelAllMatchmakingTicketsForPlayerRequest(PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCancelAllServerBackfillTicketsForPlayerRequest(PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCancelMatchmakingTicketRequest(PFMatchmakingCancelMatchmakingTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if (request->ticketId) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCancelServerBackfillTicketRequest(PFMatchmakingCancelServerBackfillTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if (request->ticketId) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogCreateMatchmakingTicketRequest(PFMatchmakingCreateMatchmakingTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  giveUpAfterSeconds " << request->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    ss << "  membersToMatchWithCount " << request->membersToMatchWithCount; Log(ss);

    // PFEntityKey
    for (uint32_t i=0; i<request->membersToMatchWithCount; i++)
    {
            ss << "  request->membersToMatchWith[" << i << "]:" << request->membersToMatchWith[i]; Log(ss); // PFEntityKey
    } 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogCreateMatchmakingTicketResult(PFMatchmakingCreateMatchmakingTicketResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingCreateMatchmakingTicketResult    
    if (result->ticketId) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogCreateServerBackfillTicketRequest(PFMatchmakingCreateServerBackfillTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  giveUpAfterSeconds " << request->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    for (uint32_t i=0; i<request->membersCount; i++)
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    } 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  serverDetails " << request->serverDetails; Log(ss); // Class: PFMatchmakingServerDetails 

}

HRESULT AutoGenMatchmakingTests::LogCreateServerBackfillTicketResult(PFMatchmakingCreateServerBackfillTicketResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingCreateServerBackfillTicketResult    
    if (result->ticketId) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogCreateServerMatchmakingTicketRequest(PFMatchmakingCreateServerMatchmakingTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  giveUpAfterSeconds " << request->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    ss << "  membersCount " << request->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayer
    for (uint32_t i=0; i<request->membersCount; i++)
    {
            ss << "  request->members[" << i << "]:" << request->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayer
    } 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogGetMatchRequest(PFMatchmakingGetMatchRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  escapeObject " << request->escapeObject; Log(ss); // Class: bool 
    if (request->matchId) { ss << "  matchId " << request->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char* 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  returnMemberAttributes " << request->returnMemberAttributes; Log(ss); // Class: bool 

}

HRESULT AutoGenMatchmakingTests::LogGetMatchResult(PFMatchmakingGetMatchResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetMatchResult    
    if (result->matchId) { ss << "  matchId " << result->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    for (uint32_t i=0; i<result->membersCount; i++)
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    }         
    ss << "  regionPreferencesCount " << result->regionPreferencesCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->regionPreferencesCount; i++)
    {
            ss << "  result->regionPreferences[" << i << "]:" << result->regionPreferences[i]; Log(ss); // const char*
    }     
    ss << "  serverDetails " << result->serverDetails; Log(ss); // Class: PFMatchmakingServerDetails 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGetMatchmakingTicketRequest(PFMatchmakingGetMatchmakingTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  escapeObject " << request->escapeObject; Log(ss); // Class: bool 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if (request->ticketId) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogGetMatchmakingTicketResult(PFMatchmakingGetMatchmakingTicketResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetMatchmakingTicketResult    
    if (result->cancellationReasonString) { ss << "  cancellationReasonString " << result->cancellationReasonString; Log(ss); } else { ss << "  cancellationReasonString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  created " << result->created; Log(ss); // Class: time_t     
    ss << "  creator " << result->creator; Log(ss); // Class: PFEntityKey     
    ss << "  giveUpAfterSeconds " << result->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    if (result->matchId) { ss << "  matchId " << result->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayer
    for (uint32_t i=0; i<result->membersCount; i++)
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayer
    }         
    ss << "  membersToMatchWithCount " << result->membersToMatchWithCount; Log(ss);

    // PFEntityKey
    for (uint32_t i=0; i<result->membersToMatchWithCount; i++)
    {
            ss << "  result->membersToMatchWith[" << i << "]:" << result->membersToMatchWith[i]; Log(ss); // PFEntityKey
    }     
    if (result->queueName) { ss << "  queueName " << result->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char*     
    if (result->status) { ss << "  status " << result->status; Log(ss); } else { ss << "  status = nullptr"; Log(ss); } // Class: const char*     
    if (result->ticketId) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogGetQueueStatisticsRequest(PFMatchmakingGetQueueStatisticsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogGetQueueStatisticsResult(PFMatchmakingGetQueueStatisticsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  escapeObject " << request->escapeObject; Log(ss); // Class: bool 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if (request->ticketId) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogGetServerBackfillTicketResult(PFMatchmakingGetServerBackfillTicketResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingGetServerBackfillTicketResult    
    if (result->cancellationReasonString) { ss << "  cancellationReasonString " << result->cancellationReasonString; Log(ss); } else { ss << "  cancellationReasonString = nullptr"; Log(ss); } // Class: const char*     
    ss << "  created " << result->created; Log(ss); // Class: time_t     
    ss << "  giveUpAfterSeconds " << result->giveUpAfterSeconds; Log(ss); // Class: int32_t     
    if (result->matchId) { ss << "  matchId " << result->matchId; Log(ss); } else { ss << "  matchId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  membersCount " << result->membersCount; Log(ss);

    // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    for (uint32_t i=0; i<result->membersCount; i++)
    {
            ss << "  result->members[" << i << "]:" << result->members[i]; Log(ss); // PFMatchmakingMatchmakingPlayerWithTeamAssignment
    }     
    if (result->queueName) { ss << "  queueName " << result->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  serverDetails " << result->serverDetails; Log(ss); // Class: PFMatchmakingServerDetails     
    if (result->status) { ss << "  status " << result->status; Log(ss); } else { ss << "  status = nullptr"; Log(ss); } // Class: const char*     
    if (result->ticketId) { ss << "  ticketId " << result->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenMatchmakingTests::LogJoinMatchmakingTicketRequest(PFMatchmakingJoinMatchmakingTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  member " << request->member; Log(ss); // Class: PFMatchmakingMatchmakingPlayer 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 
    if (request->ticketId) { ss << "  ticketId " << request->ticketId; Log(ss); } else { ss << "  ticketId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenMatchmakingTests::LogListMatchmakingTicketsForPlayerRequest(PFMatchmakingListMatchmakingTicketsForPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogListMatchmakingTicketsForPlayerResult(PFMatchmakingListMatchmakingTicketsForPlayerResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingListMatchmakingTicketsForPlayerResult        
    ss << "  ticketIdsCount " << result->ticketIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->ticketIdsCount; i++)
    {
            ss << "  result->ticketIds[" << i << "]:" << result->ticketIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenMatchmakingTests::LogListServerBackfillTicketsForPlayerRequest(PFMatchmakingListServerBackfillTicketsForPlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
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
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->queueName) { ss << "  queueName " << request->queueName; Log(ss); } else { ss << "  queueName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenMatchmakingTests::LogListServerBackfillTicketsForPlayerResult(PFMatchmakingListServerBackfillTicketsForPlayerResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabMatchmakingListServerBackfillTicketsForPlayerResult        
    ss << "  ticketIdsCount " << result->ticketIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->ticketIdsCount; i++)
    {
            ss << "  result->ticketIds[" << i << "]:" << result->ticketIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

 

}
