#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlatformSpecificTests.h"
#include "XAsyncHelper.h"

uint32_t g_PlatformSpecificTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenPlatformSpecificTests::LogAndroidDevicePushNotificationRegistrationRequest(PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificAndroidDevicePushNotificationRegistrationRequest struct:
    // request->confirmationMessage: const char*
    if (request->confirmationMessage) { ss << "  confirmationMessage " << request->confirmationMessage; Log(ss); } else { ss << "  confirmationMessage = nullptr"; Log(ss); } // Class: const char* 
    if (request->deviceToken) { ss << "  deviceToken " << request->deviceToken; Log(ss); } else { ss << "  deviceToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  sendPushNotificationConfirmation " << request->sendPushNotificationConfirmation; Log(ss); // Class: bool 

}

void AutoGenPlatformSpecificTests::LogConsumeMicrosoftStoreEntitlementsRequest(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  marketplaceSpecificData " << request->marketplaceSpecificData; Log(ss); // Class: PFPlatformSpecificMicrosoftStorePayload 

}

HRESULT AutoGenPlatformSpecificTests::LogConsumeMicrosoftStoreEntitlementsResponse(PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse        
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->itemsCount; i++)
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFItemInstance
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogConsumePS5EntitlementsRequest(PFPlatformSpecificConsumePS5EntitlementsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificConsumePS5EntitlementsRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  marketplaceSpecificData " << request->marketplaceSpecificData; Log(ss); // Class: PFPlatformSpecificPlayStation5Payload 

}

HRESULT AutoGenPlatformSpecificTests::LogConsumePS5EntitlementsResult(PFPlatformSpecificConsumePS5EntitlementsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificConsumePS5EntitlementsResult        
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->itemsCount; i++)
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFItemInstance
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogConsumePSNEntitlementsRequest(PFPlatformSpecificConsumePSNEntitlementsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificConsumePSNEntitlementsRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  serviceLabel " << request->serviceLabel; Log(ss); // Class: int32_t 

}

HRESULT AutoGenPlatformSpecificTests::LogConsumePSNEntitlementsResult(PFPlatformSpecificConsumePSNEntitlementsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificConsumePSNEntitlementsResult        
    ss << "  itemsGrantedCount " << result->itemsGrantedCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->itemsGrantedCount; i++)
    {
            ss << "  result->itemsGranted[" << i << "]:" << result->itemsGranted[i]; Log(ss); // PFItemInstance
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogConsumeXboxEntitlementsRequest(PFPlatformSpecificConsumeXboxEntitlementsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificConsumeXboxEntitlementsRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlatformSpecificTests::LogConsumeXboxEntitlementsResult(PFPlatformSpecificConsumeXboxEntitlementsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificConsumeXboxEntitlementsResult        
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->itemsCount; i++)
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFItemInstance
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogRefreshPSNAuthTokenRequest(PFPlatformSpecificRefreshPSNAuthTokenRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificRefreshPSNAuthTokenRequest struct:
    // request->authCode: const char*
    if (request->authCode) { ss << "  authCode " << request->authCode; Log(ss); } else { ss << "  authCode = nullptr"; Log(ss); } // Class: const char* 
    ss << "  issuerId " << request->issuerId; Log(ss); // Class: int32_t 
    if (request->redirectUri) { ss << "  redirectUri " << request->redirectUri; Log(ss); } else { ss << "  redirectUri = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlatformSpecificTests::LogRegisterForIOSPushNotificationRequest(PFPlatformSpecificRegisterForIOSPushNotificationRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificRegisterForIOSPushNotificationRequest struct:
    // request->confirmationMessage: const char*
    if (request->confirmationMessage) { ss << "  confirmationMessage " << request->confirmationMessage; Log(ss); } else { ss << "  confirmationMessage = nullptr"; Log(ss); } // Class: const char* 
    if (request->deviceToken) { ss << "  deviceToken " << request->deviceToken; Log(ss); } else { ss << "  deviceToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  sendPushNotificationConfirmation " << request->sendPushNotificationConfirmation; Log(ss); // Class: bool 

}

void AutoGenPlatformSpecificTests::LogRestoreIOSPurchasesRequest(PFPlatformSpecificRestoreIOSPurchasesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificRestoreIOSPurchasesRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->receiptData) { ss << "  receiptData " << request->receiptData; Log(ss); } else { ss << "  receiptData = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlatformSpecificTests::LogRestoreIOSPurchasesResult(PFPlatformSpecificRestoreIOSPurchasesResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificRestoreIOSPurchasesResult        
    ss << "  fulfillmentsCount " << result->fulfillmentsCount; Log(ss);

    // PFPlatformSpecificPurchaseReceiptFulfillment
    for (uint32_t i=0; i<result->fulfillmentsCount; i++)
    {
            ss << "  result->fulfillments[" << i << "]:" << result->fulfillments[i]; Log(ss); // PFPlatformSpecificPurchaseReceiptFulfillment
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogValidateAmazonReceiptRequest(PFPlatformSpecificValidateAmazonReceiptRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificValidateAmazonReceiptRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->currencyCode) { ss << "  currencyCode " << request->currencyCode; Log(ss); } else { ss << "  currencyCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  purchasePrice " << request->purchasePrice; Log(ss); // Class: int32_t 
    if (request->receiptId) { ss << "  receiptId " << request->receiptId; Log(ss); } else { ss << "  receiptId = nullptr"; Log(ss); } // Class: const char* 
    if (request->userId) { ss << "  userId " << request->userId; Log(ss); } else { ss << "  userId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlatformSpecificTests::LogValidateAmazonReceiptResult(PFPlatformSpecificValidateAmazonReceiptResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificValidateAmazonReceiptResult        
    ss << "  fulfillmentsCount " << result->fulfillmentsCount; Log(ss);

    // PFPlatformSpecificPurchaseReceiptFulfillment
    for (uint32_t i=0; i<result->fulfillmentsCount; i++)
    {
            ss << "  result->fulfillments[" << i << "]:" << result->fulfillments[i]; Log(ss); // PFPlatformSpecificPurchaseReceiptFulfillment
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogValidateGooglePlayPurchaseRequest(PFPlatformSpecificValidateGooglePlayPurchaseRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificValidateGooglePlayPurchaseRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->currencyCode) { ss << "  currencyCode " << request->currencyCode; Log(ss); } else { ss << "  currencyCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  purchasePrice " << request->purchasePrice; Log(ss); // Class: uint32_t 
    if (request->receiptJson) { ss << "  receiptJson " << request->receiptJson; Log(ss); } else { ss << "  receiptJson = nullptr"; Log(ss); } // Class: const char* 
    if (request->signature) { ss << "  signature " << request->signature; Log(ss); } else { ss << "  signature = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlatformSpecificTests::LogValidateGooglePlayPurchaseResult(PFPlatformSpecificValidateGooglePlayPurchaseResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificValidateGooglePlayPurchaseResult        
    ss << "  fulfillmentsCount " << result->fulfillmentsCount; Log(ss);

    // PFPlatformSpecificPurchaseReceiptFulfillment
    for (uint32_t i=0; i<result->fulfillmentsCount; i++)
    {
            ss << "  result->fulfillments[" << i << "]:" << result->fulfillments[i]; Log(ss); // PFPlatformSpecificPurchaseReceiptFulfillment
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogValidateIOSReceiptRequest(PFPlatformSpecificValidateIOSReceiptRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificValidateIOSReceiptRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->currencyCode) { ss << "  currencyCode " << request->currencyCode; Log(ss); } else { ss << "  currencyCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  purchasePrice " << request->purchasePrice; Log(ss); // Class: int32_t 
    if (request->receiptData) { ss << "  receiptData " << request->receiptData; Log(ss); } else { ss << "  receiptData = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlatformSpecificTests::LogValidateIOSReceiptResult(PFPlatformSpecificValidateIOSReceiptResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificValidateIOSReceiptResult        
    ss << "  fulfillmentsCount " << result->fulfillmentsCount; Log(ss);

    // PFPlatformSpecificPurchaseReceiptFulfillment
    for (uint32_t i=0; i<result->fulfillmentsCount; i++)
    {
            ss << "  result->fulfillments[" << i << "]:" << result->fulfillments[i]; Log(ss); // PFPlatformSpecificPurchaseReceiptFulfillment
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogValidateWindowsReceiptRequest(PFPlatformSpecificValidateWindowsReceiptRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificValidateWindowsReceiptRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->currencyCode) { ss << "  currencyCode " << request->currencyCode; Log(ss); } else { ss << "  currencyCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  purchasePrice " << request->purchasePrice; Log(ss); // Class: uint32_t 
    if (request->receipt) { ss << "  receipt " << request->receipt; Log(ss); } else { ss << "  receipt = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlatformSpecificTests::LogValidateWindowsReceiptResult(PFPlatformSpecificValidateWindowsReceiptResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificValidateWindowsReceiptResult        
    ss << "  fulfillmentsCount " << result->fulfillmentsCount; Log(ss);

    // PFPlatformSpecificPurchaseReceiptFulfillment
    for (uint32_t i=0; i<result->fulfillmentsCount; i++)
    {
            ss << "  result->fulfillments[" << i << "]:" << result->fulfillments[i]; Log(ss); // PFPlatformSpecificPurchaseReceiptFulfillment
    } 
    return S_OK;
}

void AutoGenPlatformSpecificTests::LogAwardSteamAchievementRequest(PFPlatformSpecificAwardSteamAchievementRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlatformSpecificTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlatformSpecificAwardSteamAchievementRequest struct:
    // request->achievements: PFPlatformSpecificAwardSteamAchievementItem const* const*
    // request->achievementsCount: uint32_t    
    ss << "  achievementsCount " << request->achievementsCount; Log(ss);

    // PFPlatformSpecificAwardSteamAchievementItem
    for (uint32_t i=0; i<request->achievementsCount; i++)
    {
            ss << "  request->achievements[" << i << "]:" << request->achievements[i]; Log(ss); // PFPlatformSpecificAwardSteamAchievementItem
    } 

}

HRESULT AutoGenPlatformSpecificTests::LogAwardSteamAchievementResult(PFPlatformSpecificAwardSteamAchievementResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlatformSpecificAwardSteamAchievementResult        
    ss << "  achievementResultsCount " << result->achievementResultsCount; Log(ss);

    // PFPlatformSpecificAwardSteamAchievementItem
    for (uint32_t i=0; i<result->achievementResultsCount; i++)
    {
            ss << "  result->achievementResults[" << i << "]:" << result->achievementResults[i]; Log(ss); // PFPlatformSpecificAwardSteamAchievementItem
    } 
    return S_OK;
}

 

}
