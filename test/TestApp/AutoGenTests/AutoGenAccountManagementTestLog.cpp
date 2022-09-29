#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAccountManagementTests.h"
#include "XAsyncHelper.h"

uint32_t g_AccountManagementTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenAccountManagementTests::LogBanUsersRequest(PFAccountManagementBanUsersRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementBanUsersRequest struct:
    // request->bans: PFAccountManagementBanRequest const* const*
    // request->bansCount: uint32_t    
    ss << "  bansCount " << request->bansCount; Log(ss);

    // PFAccountManagementBanRequest
    for (uint32_t i=0; i<request->bansCount; i++)
    {
            ss << "  request->bans[" << i << "]:" << request->bans[i]; Log(ss); // PFAccountManagementBanRequest
    }     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenAccountManagementTests::LogBanUsersResult(PFAccountManagementBanUsersResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementBanUsersResult        
    ss << "  banDataCount " << result->banDataCount; Log(ss);

    // PFAccountManagementBanInfo
    for (uint32_t i=0; i<result->banDataCount; i++)
    {
            ss << "  result->banData[" << i << "]:" << result->banData[i]; Log(ss); // PFAccountManagementBanInfo
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogDeleteMasterPlayerAccountRequest(PFAccountManagementDeleteMasterPlayerAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementDeleteMasterPlayerAccountRequest struct:
    // request->metaData: const char*
    if (request->metaData) { ss << "  metaData " << request->metaData; Log(ss); } else { ss << "  metaData = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogDeleteMasterPlayerAccountResult(PFAccountManagementDeleteMasterPlayerAccountResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementDeleteMasterPlayerAccountResult    
    if (result->jobReceiptId) { ss << "  jobReceiptId " << result->jobReceiptId; Log(ss); } else { ss << "  jobReceiptId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  titleIdsCount " << result->titleIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->titleIdsCount; i++)
    {
            ss << "  result->titleIds[" << i << "]:" << result->titleIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogDeleteMembershipSubscriptionRequest(PFAccountManagementDeleteMembershipSubscriptionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementDeleteMembershipSubscriptionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->membershipId) { ss << "  membershipId " << request->membershipId; Log(ss); } else { ss << "  membershipId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->subscriptionId) { ss << "  subscriptionId " << request->subscriptionId; Log(ss); } else { ss << "  subscriptionId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogDeletePlayerRequest(PFAccountManagementDeletePlayerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementDeletePlayerRequest struct:
    // request->playFabId: const char*
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogExportMasterPlayerDataRequest(PFAccountManagementExportMasterPlayerDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementExportMasterPlayerDataRequest struct:
    // request->playFabId: const char*
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogExportMasterPlayerDataResult(PFAccountManagementExportMasterPlayerDataResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementExportMasterPlayerDataResult    
    if (result->jobReceiptId) { ss << "  jobReceiptId " << result->jobReceiptId; Log(ss); } else { ss << "  jobReceiptId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayedTitleListRequest(PFAccountManagementGetPlayedTitleListRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayedTitleListRequest struct:
    // request->playFabId: const char*
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayedTitleListResult(PFAccountManagementGetPlayedTitleListResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayedTitleListResult        
    ss << "  titleIdsCount " << result->titleIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->titleIdsCount; i++)
    {
            ss << "  result->titleIds[" << i << "]:" << result->titleIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayerIdFromAuthTokenRequest(PFAccountManagementGetPlayerIdFromAuthTokenRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayerIdFromAuthTokenRequest struct:
    // request->token: const char*
    if (request->token) { ss << "  token " << request->token; Log(ss); } else { ss << "  token = nullptr"; Log(ss); } // Class: const char* 
    ss << "  tokenType " << static_cast<uint32_t>(request->tokenType); Log(ss); // Class: PFAccountManagementAuthTokenType 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayerIdFromAuthTokenResult(PFAccountManagementGetPlayerIdFromAuthTokenResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayerIdFromAuthTokenResult    
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayerProfileRequest(PFAccountManagementGetPlayerProfileRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayerProfileRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  profileConstraints " << request->profileConstraints; Log(ss); // Class: PFPlayerProfileViewConstraints 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayerProfileResult(PFAccountManagementGetPlayerProfileResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayerProfileResult    
    ss << "  playerProfile " << result->playerProfile; Log(ss); // Class: PFPlayerProfileModel 
    return S_OK;
}

void AutoGenAccountManagementTests::LogLookupUserAccountInfoRequest(PFAccountManagementLookupUserAccountInfoRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLookupUserAccountInfoRequest struct:
    // request->email: const char*
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->titleDisplayName) { ss << "  titleDisplayName " << request->titleDisplayName; Log(ss); } else { ss << "  titleDisplayName = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogLookupUserAccountInfoResult(PFAccountManagementLookupUserAccountInfoResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementLookupUserAccountInfoResult    
    ss << "  userInfo " << result->userInfo; Log(ss); // Class: PFUserAccountInfo 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetUserBansRequest(PFAccountManagementGetUserBansRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetUserBansRequest struct:
    // request->playFabId: const char*
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogGetUserBansResult(PFAccountManagementGetUserBansResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetUserBansResult        
    ss << "  banDataCount " << result->banDataCount; Log(ss);

    // PFAccountManagementBanInfo
    for (uint32_t i=0; i<result->banDataCount; i++)
    {
            ss << "  result->banData[" << i << "]:" << result->banData[i]; Log(ss); // PFAccountManagementBanInfo
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogResetPasswordRequest(PFAccountManagementResetPasswordRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementResetPasswordRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->password) { ss << "  password " << request->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char* 
    if (request->token) { ss << "  token " << request->token; Log(ss); } else { ss << "  token = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogRevokeAllBansForUserRequest(PFAccountManagementRevokeAllBansForUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementRevokeAllBansForUserRequest struct:
    // request->playFabId: const char*
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogRevokeAllBansForUserResult(PFAccountManagementRevokeAllBansForUserResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementRevokeAllBansForUserResult        
    ss << "  banDataCount " << result->banDataCount; Log(ss);

    // PFAccountManagementBanInfo
    for (uint32_t i=0; i<result->banDataCount; i++)
    {
            ss << "  result->banData[" << i << "]:" << result->banData[i]; Log(ss); // PFAccountManagementBanInfo
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogRevokeBansRequest(PFAccountManagementRevokeBansRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementRevokeBansRequest struct:
    // request->banIds: const char* const*
    // request->banIdsCount: uint32_t    
    ss << "  banIdsCount " << request->banIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->banIdsCount; i++)
    {
            ss << "  request->banIds[" << i << "]:" << request->banIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogRevokeBansResult(PFAccountManagementRevokeBansResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementRevokeBansResult        
    ss << "  banDataCount " << result->banDataCount; Log(ss);

    // PFAccountManagementBanInfo
    for (uint32_t i=0; i<result->banDataCount; i++)
    {
            ss << "  result->banData[" << i << "]:" << result->banData[i]; Log(ss); // PFAccountManagementBanInfo
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogAdminSendAccountRecoveryEmailRequest(PFAccountManagementAdminSendAccountRecoveryEmailRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementSendAccountRecoveryEmailRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    if (request->emailTemplateId) { ss << "  emailTemplateId " << request->emailTemplateId; Log(ss); } else { ss << "  emailTemplateId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogSetMembershipOverrideRequest(PFAccountManagementSetMembershipOverrideRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementSetMembershipOverrideRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  expirationTime " << request->expirationTime; Log(ss); // Class: time_t 
    if (request->membershipId) { ss << "  membershipId " << request->membershipId; Log(ss); } else { ss << "  membershipId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogUpdateBansRequest(PFAccountManagementUpdateBansRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUpdateBansRequest struct:
    // request->bans: PFAccountManagementUpdateBanRequest const* const*
    // request->bansCount: uint32_t    
    ss << "  bansCount " << request->bansCount; Log(ss);

    // PFAccountManagementUpdateBanRequest
    for (uint32_t i=0; i<request->bansCount; i++)
    {
            ss << "  request->bans[" << i << "]:" << request->bans[i]; Log(ss); // PFAccountManagementUpdateBanRequest
    } 

}

HRESULT AutoGenAccountManagementTests::LogUpdateBansResult(PFAccountManagementUpdateBansResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementUpdateBansResult        
    ss << "  banDataCount " << result->banDataCount; Log(ss);

    // PFAccountManagementBanInfo
    for (uint32_t i=0; i<result->banDataCount; i++)
    {
            ss << "  result->banData[" << i << "]:" << result->banData[i]; Log(ss); // PFAccountManagementBanInfo
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogAdminUpdateUserTitleDisplayNameRequest(PFAccountManagementAdminUpdateUserTitleDisplayNameRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUpdateUserTitleDisplayNameRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->displayName) { ss << "  displayName " << request->displayName; Log(ss); } else { ss << "  displayName = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogUpdateUserTitleDisplayNameResult(PFAccountManagementUpdateUserTitleDisplayNameResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementUpdateUserTitleDisplayNameResult    
    if (result->displayName) { ss << "  displayName " << result->displayName; Log(ss); } else { ss << "  displayName = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAccountManagementTests::LogClientAddGenericIDRequest(PFAccountManagementClientAddGenericIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementAddGenericIDRequest struct:
    // request->genericId: PFAccountManagementGenericServiceId const*
    ss << "  genericId " << request->genericId; Log(ss); // Class: PFAccountManagementGenericServiceId 

}

void AutoGenAccountManagementTests::LogAddOrUpdateContactEmailRequest(PFAccountManagementAddOrUpdateContactEmailRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementAddOrUpdateContactEmailRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->emailAddress) { ss << "  emailAddress " << request->emailAddress; Log(ss); } else { ss << "  emailAddress = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogAddUsernamePasswordRequest(PFAccountManagementAddUsernamePasswordRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithManualData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementAddUsernamePasswordRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    if (request->password) { ss << "  password " << request->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogAddUsernamePasswordResult(PFAccountManagementAddUsernamePasswordResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementAddUsernamePasswordResult    
    if (result->username) { ss << "  username " << result->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetAccountInfoRequest(PFAccountManagementGetAccountInfoRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetAccountInfoRequest struct:
    // request->email: const char*
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->titleDisplayName) { ss << "  titleDisplayName " << request->titleDisplayName; Log(ss); } else { ss << "  titleDisplayName = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogGetAccountInfoResult(PFAccountManagementGetAccountInfoResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetAccountInfoResult    
    ss << "  accountInfo " << result->accountInfo; Log(ss); // Class: PFUserAccountInfo 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayerCombinedInfoRequest(PFAccountManagementGetPlayerCombinedInfoRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayerCombinedInfoRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayerCombinedInfoResult(PFAccountManagementGetPlayerCombinedInfoResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayerCombinedInfoResult    
    ss << "  infoResultPayload " << result->infoResultPayload; Log(ss); // Class: PFGetPlayerCombinedInfoResultPayload     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromFacebookIDsRequest(PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromFacebookIDsRequest struct:
    // request->facebookIDs: const char* const*
    // request->facebookIDsCount: uint32_t    
    ss << "  facebookIDsCount " << request->facebookIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->facebookIDsCount; i++)
    {
            ss << "  request->facebookIDs[" << i << "]:" << request->facebookIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromFacebookIDsResult(PFAccountManagementGetPlayFabIDsFromFacebookIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromFacebookIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementFacebookPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementFacebookPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromFacebookInstantGamesIdsRequest(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest struct:
    // request->facebookInstantGamesIds: const char* const*
    // request->facebookInstantGamesIdsCount: uint32_t    
    ss << "  facebookInstantGamesIdsCount " << request->facebookInstantGamesIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->facebookInstantGamesIdsCount; i++)
    {
            ss << "  request->facebookInstantGamesIds[" << i << "]:" << request->facebookInstantGamesIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromFacebookInstantGamesIdsResult(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementFacebookInstantGamesPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementFacebookInstantGamesPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromGameCenterIDsRequest(PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromGameCenterIDsRequest struct:
    // request->gameCenterIDs: const char* const*
    // request->gameCenterIDsCount: uint32_t    
    ss << "  gameCenterIDsCount " << request->gameCenterIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->gameCenterIDsCount; i++)
    {
            ss << "  request->gameCenterIDs[" << i << "]:" << request->gameCenterIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromGameCenterIDsResult(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromGameCenterIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementGameCenterPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementGameCenterPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromGenericIDsRequest(PFAccountManagementGetPlayFabIDsFromGenericIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromGenericIDsRequest struct:
    // request->genericIDs: PFAccountManagementGenericServiceId const* const*
    // request->genericIDsCount: uint32_t    
    ss << "  genericIDsCount " << request->genericIDsCount; Log(ss);

    // PFAccountManagementGenericServiceId
    for (uint32_t i=0; i<request->genericIDsCount; i++)
    {
            ss << "  request->genericIDs[" << i << "]:" << request->genericIDs[i]; Log(ss); // PFAccountManagementGenericServiceId
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromGenericIDsResult(PFAccountManagementGetPlayFabIDsFromGenericIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromGenericIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementGenericPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementGenericPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromGoogleIDsRequest(PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromGoogleIDsRequest struct:
    // request->googleIDs: const char* const*
    // request->googleIDsCount: uint32_t    
    ss << "  googleIDsCount " << request->googleIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->googleIDsCount; i++)
    {
            ss << "  request->googleIDs[" << i << "]:" << request->googleIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromGoogleIDsResult(PFAccountManagementGetPlayFabIDsFromGoogleIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromGoogleIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementGooglePlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementGooglePlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest(PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest struct:
    // request->googlePlayGamesPlayerIDs: const char* const*
    // request->googlePlayGamesPlayerIDsCount: uint32_t    
    ss << "  googlePlayGamesPlayerIDsCount " << request->googlePlayGamesPlayerIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->googlePlayGamesPlayerIDsCount; i++)
    {
            ss << "  request->googlePlayGamesPlayerIDs[" << i << "]:" << request->googlePlayGamesPlayerIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult(PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementGooglePlayGamesPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementGooglePlayGamesPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromKongregateIDsRequest(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromKongregateIDsRequest struct:
    // request->kongregateIDs: const char* const*
    // request->kongregateIDsCount: uint32_t    
    ss << "  kongregateIDsCount " << request->kongregateIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->kongregateIDsCount; i++)
    {
            ss << "  request->kongregateIDs[" << i << "]:" << request->kongregateIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromKongregateIDsResult(PFAccountManagementGetPlayFabIDsFromKongregateIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromKongregateIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementKongregatePlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementKongregatePlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromNintendoServiceAccountIdsRequest(PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest struct:
    // request->nintendoAccountIds: const char* const*
    // request->nintendoAccountIdsCount: uint32_t    
    ss << "  nintendoAccountIdsCount " << request->nintendoAccountIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->nintendoAccountIdsCount; i++)
    {
            ss << "  request->nintendoAccountIds[" << i << "]:" << request->nintendoAccountIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromNintendoServiceAccountIdsResult(PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementNintendoServiceAccountPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementNintendoServiceAccountPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest struct:
    // request->nintendoSwitchDeviceIds: const char* const*
    // request->nintendoSwitchDeviceIdsCount: uint32_t    
    ss << "  nintendoSwitchDeviceIdsCount " << request->nintendoSwitchDeviceIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->nintendoSwitchDeviceIdsCount; i++)
    {
            ss << "  request->nintendoSwitchDeviceIds[" << i << "]:" << request->nintendoSwitchDeviceIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementNintendoSwitchPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementNintendoSwitchPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromPSNAccountIDsRequest(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest struct:
    // request->issuerId: int32_t const*
    ss << "  issuerId " << request->issuerId; Log(ss); // Class: int32_t     
    ss << "  PSNAccountIDsCount " << request->PSNAccountIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->PSNAccountIDsCount; i++)
    {
            ss << "  request->PSNAccountIDs[" << i << "]:" << request->PSNAccountIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromPSNAccountIDsResult(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromPSNAccountIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementPSNAccountPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementPSNAccountPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromSteamIDsRequest(PFAccountManagementGetPlayFabIDsFromSteamIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromSteamIDsRequest struct:
    // request->steamStringIDs: const char* const*
    // request->steamStringIDsCount: uint32_t    
    ss << "  steamStringIDsCount " << request->steamStringIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->steamStringIDsCount; i++)
    {
            ss << "  request->steamStringIDs[" << i << "]:" << request->steamStringIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromSteamIDsResult(PFAccountManagementGetPlayFabIDsFromSteamIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromSteamIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementSteamPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementSteamPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromTwitchIDsRequest(PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromTwitchIDsRequest struct:
    // request->twitchIds: const char* const*
    // request->twitchIdsCount: uint32_t    
    ss << "  twitchIdsCount " << request->twitchIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->twitchIdsCount; i++)
    {
            ss << "  request->twitchIds[" << i << "]:" << request->twitchIds[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromTwitchIDsResult(PFAccountManagementGetPlayFabIDsFromTwitchIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromTwitchIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementTwitchPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementTwitchPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetPlayFabIDsFromXboxLiveIDsRequest(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest struct:
    // request->sandbox: const char*
    if (request->sandbox) { ss << "  sandbox " << request->sandbox; Log(ss); } else { ss << "  sandbox = nullptr"; Log(ss); } // Class: const char*     
    ss << "  xboxLiveAccountIDsCount " << request->xboxLiveAccountIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->xboxLiveAccountIDsCount; i++)
    {
            ss << "  request->xboxLiveAccountIDs[" << i << "]:" << request->xboxLiveAccountIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetPlayFabIDsFromXboxLiveIDsResult(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetPlayFabIDsFromXboxLiveIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementXboxLiveAccountPlayFabIdPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementXboxLiveAccountPlayFabIdPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogLinkAndroidDeviceIDRequest(PFAccountManagementLinkAndroidDeviceIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkAndroidDeviceIDRequest struct:
    // request->androidDevice: const char*
    if (request->androidDevice) { ss << "  androidDevice " << request->androidDevice; Log(ss); } else { ss << "  androidDevice = nullptr"; Log(ss); } // Class: const char* 
    if (request->androidDeviceId) { ss << "  androidDeviceId " << request->androidDeviceId; Log(ss); } else { ss << "  androidDeviceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->OS) { ss << "  OS " << request->OS; Log(ss); } else { ss << "  OS = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkAppleRequest(PFAccountManagementLinkAppleRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkAppleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->identityToken) { ss << "  identityToken " << request->identityToken; Log(ss); } else { ss << "  identityToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkCustomIDRequest(PFAccountManagementLinkCustomIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkCustomIDRequest struct:
    // request->customId: const char*
    if (request->customId) { ss << "  customId " << request->customId; Log(ss); } else { ss << "  customId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 

}

void AutoGenAccountManagementTests::LogLinkFacebookAccountRequest(PFAccountManagementLinkFacebookAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkFacebookAccountRequest struct:
    // request->accessToken: const char*
    if (request->accessToken) { ss << "  accessToken " << request->accessToken; Log(ss); } else { ss << "  accessToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 

}

void AutoGenAccountManagementTests::LogLinkFacebookInstantGamesIdRequest(PFAccountManagementLinkFacebookInstantGamesIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkFacebookInstantGamesIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->facebookInstantGamesSignature) { ss << "  facebookInstantGamesSignature " << request->facebookInstantGamesSignature; Log(ss); } else { ss << "  facebookInstantGamesSignature = nullptr"; Log(ss); } // Class: const char* 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 

}

void AutoGenAccountManagementTests::LogLinkGameCenterAccountRequest(PFAccountManagementLinkGameCenterAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkGameCenterAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->gameCenterId) { ss << "  gameCenterId " << request->gameCenterId; Log(ss); } else { ss << "  gameCenterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->publicKeyUrl) { ss << "  publicKeyUrl " << request->publicKeyUrl; Log(ss); } else { ss << "  publicKeyUrl = nullptr"; Log(ss); } // Class: const char* 
    if (request->salt) { ss << "  salt " << request->salt; Log(ss); } else { ss << "  salt = nullptr"; Log(ss); } // Class: const char* 
    if (request->signature) { ss << "  signature " << request->signature; Log(ss); } else { ss << "  signature = nullptr"; Log(ss); } // Class: const char* 
    if (request->timestamp) { ss << "  timestamp " << request->timestamp; Log(ss); } else { ss << "  timestamp = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkGoogleAccountRequest(PFAccountManagementLinkGoogleAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkGoogleAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->serverAuthCode) { ss << "  serverAuthCode " << request->serverAuthCode; Log(ss); } else { ss << "  serverAuthCode = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkGooglePlayGamesServicesAccountRequest(PFAccountManagementLinkGooglePlayGamesServicesAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkGooglePlayGamesServicesAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->serverAuthCode) { ss << "  serverAuthCode " << request->serverAuthCode; Log(ss); } else { ss << "  serverAuthCode = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkIOSDeviceIDRequest(PFAccountManagementLinkIOSDeviceIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkIOSDeviceIDRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->deviceId) { ss << "  deviceId " << request->deviceId; Log(ss); } else { ss << "  deviceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->deviceModel) { ss << "  deviceModel " << request->deviceModel; Log(ss); } else { ss << "  deviceModel = nullptr"; Log(ss); } // Class: const char* 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->OS) { ss << "  OS " << request->OS; Log(ss); } else { ss << "  OS = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkKongregateAccountRequest(PFAccountManagementLinkKongregateAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkKongregateAccountRequest struct:
    // request->authTicket: const char*
    if (request->authTicket) { ss << "  authTicket " << request->authTicket; Log(ss); } else { ss << "  authTicket = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->kongregateId) { ss << "  kongregateId " << request->kongregateId; Log(ss); } else { ss << "  kongregateId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogClientLinkNintendoServiceAccountRequest(PFAccountManagementClientLinkNintendoServiceAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkNintendoServiceAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->identityToken) { ss << "  identityToken " << request->identityToken; Log(ss); } else { ss << "  identityToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogClientLinkNintendoSwitchDeviceIdRequest(PFAccountManagementClientLinkNintendoSwitchDeviceIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkNintendoSwitchDeviceIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->nintendoSwitchDeviceId) { ss << "  nintendoSwitchDeviceId " << request->nintendoSwitchDeviceId; Log(ss); } else { ss << "  nintendoSwitchDeviceId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkOpenIdConnectRequest(PFAccountManagementLinkOpenIdConnectRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkOpenIdConnectRequest struct:
    // request->connectionId: const char*
    if (request->connectionId) { ss << "  connectionId " << request->connectionId; Log(ss); } else { ss << "  connectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->idToken) { ss << "  idToken " << request->idToken; Log(ss); } else { ss << "  idToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogClientLinkPSNAccountRequest(PFAccountManagementClientLinkPSNAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkPSNAccountRequest struct:
    // request->authCode: const char*
    if (request->authCode) { ss << "  authCode " << request->authCode; Log(ss); } else { ss << "  authCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    ss << "  issuerId " << request->issuerId; Log(ss); // Class: int32_t 
    if (request->redirectUri) { ss << "  redirectUri " << request->redirectUri; Log(ss); } else { ss << "  redirectUri = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkSteamAccountRequest(PFAccountManagementLinkSteamAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkSteamAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->steamTicket) { ss << "  steamTicket " << request->steamTicket; Log(ss); } else { ss << "  steamTicket = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkTwitchAccountRequest(PFAccountManagementLinkTwitchAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkTwitchAccountRequest struct:
    // request->accessToken: const char*
    if (request->accessToken) { ss << "  accessToken " << request->accessToken; Log(ss); } else { ss << "  accessToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 

}

void AutoGenAccountManagementTests::LogClientLinkXboxAccountRequest(PFAccountManagementClientLinkXboxAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkXboxAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogRemoveContactEmailRequest(PFAccountManagementRemoveContactEmailRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementRemoveContactEmailRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogClientRemoveGenericIDRequest(PFAccountManagementClientRemoveGenericIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementRemoveGenericIDRequest struct:
    // request->genericId: PFAccountManagementGenericServiceId const*
    ss << "  genericId " << request->genericId; Log(ss); // Class: PFAccountManagementGenericServiceId 

}

void AutoGenAccountManagementTests::LogReportPlayerClientRequest(PFAccountManagementReportPlayerClientRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithManualData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementReportPlayerClientRequest struct:
    // request->comment: const char*
    if (request->comment) { ss << "  comment " << request->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->reporteeId) { ss << "  reporteeId " << request->reporteeId; Log(ss); } else { ss << "  reporteeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogReportPlayerClientResult(PFAccountManagementReportPlayerClientResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementReportPlayerClientResult    
    ss << "  submissionsRemaining " << result->submissionsRemaining; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenAccountManagementTests::LogClientSendAccountRecoveryEmailRequest(PFAccountManagementClientSendAccountRecoveryEmailRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithManualData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementSendAccountRecoveryEmailRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    if (request->emailTemplateId) { ss << "  emailTemplateId " << request->emailTemplateId; Log(ss); } else { ss << "  emailTemplateId = nullptr"; Log(ss); } // Class: const char* 
    if (request->titleId) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogUnlinkAndroidDeviceIDRequest(PFAccountManagementUnlinkAndroidDeviceIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkAndroidDeviceIDRequest struct:
    // request->androidDeviceId: const char*
    if (request->androidDeviceId) { ss << "  androidDeviceId " << request->androidDeviceId; Log(ss); } else { ss << "  androidDeviceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkAppleRequest(PFAccountManagementUnlinkAppleRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkAppleRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkCustomIDRequest(PFAccountManagementUnlinkCustomIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkCustomIDRequest struct:
    // request->customId: const char*
    if (request->customId) { ss << "  customId " << request->customId; Log(ss); } else { ss << "  customId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkFacebookAccountRequest(PFAccountManagementUnlinkFacebookAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkFacebookAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkFacebookInstantGamesIdRequest(PFAccountManagementUnlinkFacebookInstantGamesIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkFacebookInstantGamesIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->facebookInstantGamesId) { ss << "  facebookInstantGamesId " << request->facebookInstantGamesId; Log(ss); } else { ss << "  facebookInstantGamesId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogUnlinkGameCenterAccountRequest(PFAccountManagementUnlinkGameCenterAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkGameCenterAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkGoogleAccountRequest(PFAccountManagementUnlinkGoogleAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkGoogleAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkGooglePlayGamesServicesAccountRequest(PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkGooglePlayGamesServicesAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkIOSDeviceIDRequest(PFAccountManagementUnlinkIOSDeviceIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkIOSDeviceIDRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->deviceId) { ss << "  deviceId " << request->deviceId; Log(ss); } else { ss << "  deviceId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogUnlinkKongregateAccountRequest(PFAccountManagementUnlinkKongregateAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkKongregateAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogClientUnlinkNintendoServiceAccountRequest(PFAccountManagementClientUnlinkNintendoServiceAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkNintendoServiceAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogClientUnlinkNintendoSwitchDeviceIdRequest(PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkNintendoSwitchDeviceIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->nintendoSwitchDeviceId) { ss << "  nintendoSwitchDeviceId " << request->nintendoSwitchDeviceId; Log(ss); } else { ss << "  nintendoSwitchDeviceId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogUnlinkOpenIdConnectRequest(PFAccountManagementUnlinkOpenIdConnectRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkOpenIdConnectRequest struct:
    // request->connectionId: const char*
    if (request->connectionId) { ss << "  connectionId " << request->connectionId; Log(ss); } else { ss << "  connectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogClientUnlinkPSNAccountRequest(PFAccountManagementClientUnlinkPSNAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkPSNAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkSteamAccountRequest(PFAccountManagementUnlinkSteamAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkSteamAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogUnlinkTwitchAccountRequest(PFAccountManagementUnlinkTwitchAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkTwitchAccountRequest struct:
    // request->accessToken: const char*
    if (request->accessToken) { ss << "  accessToken " << request->accessToken; Log(ss); } else { ss << "  accessToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogClientUnlinkXboxAccountRequest(PFAccountManagementClientUnlinkXboxAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkXboxAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenAccountManagementTests::LogClientUpdateAvatarUrlRequest(PFAccountManagementClientUpdateAvatarUrlRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUpdateAvatarUrlRequest struct:
    // request->imageUrl: const char*
    if (request->imageUrl) { ss << "  imageUrl " << request->imageUrl; Log(ss); } else { ss << "  imageUrl = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogClientUpdateUserTitleDisplayNameRequest(PFAccountManagementClientUpdateUserTitleDisplayNameRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUpdateUserTitleDisplayNameRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->displayName) { ss << "  displayName " << request->displayName; Log(ss); } else { ss << "  displayName = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerAddGenericIDRequest(PFAccountManagementServerAddGenericIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementAddGenericIDRequest struct:
    // request->genericId: PFAccountManagementGenericServiceId const*
    ss << "  genericId " << request->genericId; Log(ss); // Class: PFAccountManagementGenericServiceId 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogGetServerCustomIDsFromPlayFabIDsRequest(PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetServerCustomIDsFromPlayFabIDsRequest struct:
    // request->playFabIDs: const char* const*
    // request->playFabIDsCount: uint32_t    
    ss << "  playFabIDsCount " << request->playFabIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->playFabIDsCount; i++)
    {
            ss << "  request->playFabIDs[" << i << "]:" << request->playFabIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenAccountManagementTests::LogGetServerCustomIDsFromPlayFabIDsResult(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetServerCustomIDsFromPlayFabIDsResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFAccountManagementServerCustomIDPlayFabIDPair
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i]; Log(ss); // PFAccountManagementServerCustomIDPlayFabIDPair
    } 
    return S_OK;
}

void AutoGenAccountManagementTests::LogGetUserAccountInfoRequest(PFAccountManagementGetUserAccountInfoRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementGetUserAccountInfoRequest struct:
    // request->playFabId: const char*
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAccountManagementTests::LogGetUserAccountInfoResult(PFAccountManagementGetUserAccountInfoResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAccountManagementGetUserAccountInfoResult    
    ss << "  userInfo " << result->userInfo; Log(ss); // Class: PFUserAccountInfo 
    return S_OK;
}

void AutoGenAccountManagementTests::LogServerLinkNintendoServiceAccountRequest(PFAccountManagementServerLinkNintendoServiceAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkNintendoServiceAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->identityToken) { ss << "  identityToken " << request->identityToken; Log(ss); } else { ss << "  identityToken = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerLinkNintendoSwitchDeviceIdRequest(PFAccountManagementServerLinkNintendoSwitchDeviceIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkNintendoSwitchDeviceIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->nintendoSwitchDeviceId) { ss << "  nintendoSwitchDeviceId " << request->nintendoSwitchDeviceId; Log(ss); } else { ss << "  nintendoSwitchDeviceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerLinkPSNAccountRequest(PFAccountManagementServerLinkPSNAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkPSNAccountRequest struct:
    // request->authCode: const char*
    if (request->authCode) { ss << "  authCode " << request->authCode; Log(ss); } else { ss << "  authCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    ss << "  issuerId " << request->issuerId; Log(ss); // Class: int32_t 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->redirectUri) { ss << "  redirectUri " << request->redirectUri; Log(ss); } else { ss << "  redirectUri = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogLinkServerCustomIdRequest(PFAccountManagementLinkServerCustomIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkServerCustomIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->serverCustomId) { ss << "  serverCustomId " << request->serverCustomId; Log(ss); } else { ss << "  serverCustomId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerLinkXboxAccountRequest(PFAccountManagementServerLinkXboxAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementLinkXboxAccountRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  forceLink " << request->forceLink; Log(ss); // Class: bool 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerRemoveGenericIDRequest(PFAccountManagementServerRemoveGenericIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementRemoveGenericIDRequest struct:
    // request->genericId: PFAccountManagementGenericServiceId const*
    ss << "  genericId " << request->genericId; Log(ss); // Class: PFAccountManagementGenericServiceId 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogSendCustomAccountRecoveryEmailRequest(PFAccountManagementSendCustomAccountRecoveryEmailRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementSendCustomAccountRecoveryEmailRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    if (request->emailTemplateId) { ss << "  emailTemplateId " << request->emailTemplateId; Log(ss); } else { ss << "  emailTemplateId = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogSendEmailFromTemplateRequest(PFAccountManagementSendEmailFromTemplateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementSendEmailFromTemplateRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->emailTemplateId) { ss << "  emailTemplateId " << request->emailTemplateId; Log(ss); } else { ss << "  emailTemplateId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerUnlinkNintendoServiceAccountRequest(PFAccountManagementServerUnlinkNintendoServiceAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkNintendoServiceAccountRequest struct:
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

void AutoGenAccountManagementTests::LogServerUnlinkNintendoSwitchDeviceIdRequest(PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkNintendoSwitchDeviceIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->nintendoSwitchDeviceId) { ss << "  nintendoSwitchDeviceId " << request->nintendoSwitchDeviceId; Log(ss); } else { ss << "  nintendoSwitchDeviceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerUnlinkPSNAccountRequest(PFAccountManagementServerUnlinkPSNAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkPSNAccountRequest struct:
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

void AutoGenAccountManagementTests::LogUnlinkServerCustomIdRequest(PFAccountManagementUnlinkServerCustomIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkServerCustomIdRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->serverCustomId) { ss << "  serverCustomId " << request->serverCustomId; Log(ss); } else { ss << "  serverCustomId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAccountManagementTests::LogServerUnlinkXboxAccountRequest(PFAccountManagementServerUnlinkXboxAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUnlinkXboxAccountRequest struct:
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

void AutoGenAccountManagementTests::LogServerUpdateAvatarUrlRequest(PFAccountManagementServerUpdateAvatarUrlRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AccountManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAccountManagementUpdateAvatarUrlRequest struct:
    // request->imageUrl: const char*
    if (request->imageUrl) { ss << "  imageUrl " << request->imageUrl; Log(ss); } else { ss << "  imageUrl = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
