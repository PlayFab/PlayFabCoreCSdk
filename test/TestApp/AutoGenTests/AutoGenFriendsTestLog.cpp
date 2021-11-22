#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenFriendsTests.h"
#include "XAsyncHelper.h"

uint32_t g_FriendsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenFriendsTests::LogClientAddFriendRequest(PFFriendsClientAddFriendRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsAddFriendRequest struct:
    // request->friendEmail: const char*
    if( request->friendEmail ) { ss << "  friendEmail " << request->friendEmail; Log(ss); } else { ss << "  friendEmail = nullptr"; Log(ss); } // Class: const char* 
    if( request->friendPlayFabId ) { ss << "  friendPlayFabId " << request->friendPlayFabId; Log(ss); } else { ss << "  friendPlayFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->friendTitleDisplayName ) { ss << "  friendTitleDisplayName " << request->friendTitleDisplayName; Log(ss); } else { ss << "  friendTitleDisplayName = nullptr"; Log(ss); } // Class: const char* 
    if( request->friendUsername ) { ss << "  friendUsername " << request->friendUsername; Log(ss); } else { ss << "  friendUsername = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenFriendsTests::LogPFFriendsAddFriendResult(PFFriendsAddFriendResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabFriendsAddFriendResult
    ss << "  created " << result->created; Log(ss); // Class: bool 
    return S_OK;
}

void AutoGenFriendsTests::LogClientGetFriendsListRequest(PFFriendsClientGetFriendsListRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsGetFriendsListRequest struct:
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
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if( request->xboxToken ) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenFriendsTests::LogPFFriendsGetFriendsListResult(PFFriendsGetFriendsListResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabFriendsGetFriendsListResult    
    ss << "  friendsCount " << result->friendsCount; Log(ss);

    // PFFriendsFriendInfo
    for( uint32_t i=0; i<result->friendsCount; i++ )
    {
            ss << "  result->friends[" << i << "]:" << result->friends[i]; Log(ss); // PFFriendsFriendInfo
    } 
    return S_OK;
}

void AutoGenFriendsTests::LogClientRemoveFriendRequest(PFFriendsClientRemoveFriendRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsRemoveFriendRequest struct:
    // request->friendPlayFabId: const char*
    if( request->friendPlayFabId ) { ss << "  friendPlayFabId " << request->friendPlayFabId; Log(ss); } else { ss << "  friendPlayFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenFriendsTests::LogClientSetFriendTagsRequest(PFFriendsClientSetFriendTagsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsSetFriendTagsRequest struct:
    // request->friendPlayFabId: const char*
    if( request->friendPlayFabId ) { ss << "  friendPlayFabId " << request->friendPlayFabId; Log(ss); } else { ss << "  friendPlayFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  tagsCount " << request->tagsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->tagsCount; i++ )
    {
            ss << "  request->tags[" << i << "]:" << request->tags[i]; Log(ss); // const char*
    } 

}

void AutoGenFriendsTests::LogServerAddFriendRequest(PFFriendsServerAddFriendRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsAddFriendRequest struct:
    // request->friendEmail: const char*
    if( request->friendEmail ) { ss << "  friendEmail " << request->friendEmail; Log(ss); } else { ss << "  friendEmail = nullptr"; Log(ss); } // Class: const char* 
    if( request->friendPlayFabId ) { ss << "  friendPlayFabId " << request->friendPlayFabId; Log(ss); } else { ss << "  friendPlayFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->friendTitleDisplayName ) { ss << "  friendTitleDisplayName " << request->friendTitleDisplayName; Log(ss); } else { ss << "  friendTitleDisplayName = nullptr"; Log(ss); } // Class: const char* 
    if( request->friendUsername ) { ss << "  friendUsername " << request->friendUsername; Log(ss); } else { ss << "  friendUsername = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenFriendsTests::LogServerGetFriendsListRequest(PFFriendsServerGetFriendsListRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsGetFriendsListRequest struct:
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
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 
    if( request->xboxToken ) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenFriendsTests::LogServerRemoveFriendRequest(PFFriendsServerRemoveFriendRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsRemoveFriendRequest struct:
    // request->friendPlayFabId: const char*
    if( request->friendPlayFabId ) { ss << "  friendPlayFabId " << request->friendPlayFabId; Log(ss); } else { ss << "  friendPlayFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenFriendsTests::LogServerSetFriendTagsRequest(PFFriendsServerSetFriendTagsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_FriendsTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabFriendsSetFriendTagsRequest struct:
    // request->friendPlayFabId: const char*
    if( request->friendPlayFabId ) { ss << "  friendPlayFabId " << request->friendPlayFabId; Log(ss); } else { ss << "  friendPlayFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  tagsCount " << request->tagsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->tagsCount; i++ )
    {
            ss << "  request->tags[" << i << "]:" << request->tags[i]; Log(ss); // const char*
    } 

}

 

}
