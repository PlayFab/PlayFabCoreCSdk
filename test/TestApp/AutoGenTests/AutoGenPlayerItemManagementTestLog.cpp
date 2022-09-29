#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayerItemManagementTests.h"
#include "XAsyncHelper.h"

uint32_t g_PlayerItemManagementTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenPlayerItemManagementTests::LogAdminAddUserVirtualCurrencyRequest(PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementAddUserVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogModifyUserVirtualCurrencyResult(PFPlayerItemManagementModifyUserVirtualCurrencyResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementModifyUserVirtualCurrencyResult    
    ss << "  balance " << result->balance; Log(ss); // Class: int32_t     
    ss << "  balanceChange " << result->balanceChange; Log(ss); // Class: int32_t     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    if (result->virtualCurrency) { ss << "  virtualCurrency " << result->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogCheckLimitedEditionItemAvailabilityRequest(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->itemId) { ss << "  itemId " << request->itemId; Log(ss); } else { ss << "  itemId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogCheckLimitedEditionItemAvailabilityResult(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementCheckLimitedEditionItemAvailabilityResult    
    ss << "  amount " << result->amount; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogAdminGetUserInventoryRequest(PFPlayerItemManagementAdminGetUserInventoryRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetUserInventoryRequest struct:
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

HRESULT AutoGenPlayerItemManagementTests::LogAdminGetUserInventoryResult(PFPlayerItemManagementAdminGetUserInventoryResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementAdminGetUserInventoryResult        
    ss << "  inventoryCount " << result->inventoryCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->inventoryCount; i++)
    {
            ss << "  result->inventory[" << i << "]:" << result->inventory[i]; Log(ss); // PFItemInstance
    }     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyRechargeTimesCount " << result->virtualCurrencyRechargeTimesCount; Log(ss);

    // PFVirtualCurrencyRechargeTimeDictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyRechargeTimesCount; i++)
    {
            ss << "  result->virtualCurrencyRechargeTimes[" << i << "]:" << result->virtualCurrencyRechargeTimes[i].key << "=" << result->virtualCurrencyRechargeTimes[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogGrantItemsToUsersRequest(PFPlayerItemManagementGrantItemsToUsersRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGrantItemsToUsersRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  itemGrantsCount " << request->itemGrantsCount; Log(ss);

    // PFPlayerItemManagementItemGrant
    for (uint32_t i=0; i<request->itemGrantsCount; i++)
    {
            ss << "  request->itemGrants[" << i << "]:" << request->itemGrants[i]; Log(ss); // PFPlayerItemManagementItemGrant
    } 

}

HRESULT AutoGenPlayerItemManagementTests::LogGrantItemsToUsersResult(PFPlayerItemManagementGrantItemsToUsersResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementGrantItemsToUsersResult        
    ss << "  itemGrantResultsCount " << result->itemGrantResultsCount; Log(ss);

    // PFPlayerItemManagementGrantedItemInstance
    for (uint32_t i=0; i<result->itemGrantResultsCount; i++)
    {
            ss << "  result->itemGrantResults[" << i << "]:" << result->itemGrantResults[i]; Log(ss); // PFPlayerItemManagementGrantedItemInstance
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogIncrementLimitedEditionItemAvailabilityRequest(PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t 
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->itemId) { ss << "  itemId " << request->itemId; Log(ss); } else { ss << "  itemId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogRevokeInventoryItemRequest(PFPlayerItemManagementRevokeInventoryItemRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementRevokeInventoryItemRequest struct:
    // request->characterId: const char*
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogRevokeInventoryItemsRequest(PFPlayerItemManagementRevokeInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementRevokeInventoryItemsRequest struct:
    // request->items: PFPlayerItemManagementRevokeInventoryItem const* const*
    // request->itemsCount: uint32_t    
    ss << "  itemsCount " << request->itemsCount; Log(ss);

    // PFPlayerItemManagementRevokeInventoryItem
    for (uint32_t i=0; i<request->itemsCount; i++)
    {
            ss << "  request->items[" << i << "]:" << request->items[i]; Log(ss); // PFPlayerItemManagementRevokeInventoryItem
    } 

}

HRESULT AutoGenPlayerItemManagementTests::LogRevokeInventoryItemsResult(PFPlayerItemManagementRevokeInventoryItemsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementRevokeInventoryItemsResult        
    ss << "  errorsCount " << result->errorsCount; Log(ss);

    // PFPlayerItemManagementRevokeItemError
    for (uint32_t i=0; i<result->errorsCount; i++)
    {
            ss << "  result->errors[" << i << "]:" << result->errors[i]; Log(ss); // PFPlayerItemManagementRevokeItemError
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogAdminSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementSubtractUserVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogClientAddUserVirtualCurrencyRequest(PFPlayerItemManagementClientAddUserVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementAddUserVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogConfirmPurchaseRequest(PFPlayerItemManagementConfirmPurchaseRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementConfirmPurchaseRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->orderId) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogConfirmPurchaseResult(PFPlayerItemManagementConfirmPurchaseResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementConfirmPurchaseResult        
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->itemsCount; i++)
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFItemInstance
    }     
    if (result->orderId) { ss << "  orderId " << result->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  purchaseDate " << result->purchaseDate; Log(ss); // Class: time_t 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogClientConsumeItemRequest(PFPlayerItemManagementClientConsumeItemRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementConsumeItemRequest struct:
    // request->characterId: const char*
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  consumeCount " << request->consumeCount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogConsumeItemResult(PFPlayerItemManagementConsumeItemResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementConsumeItemResult    
    if (result->itemInstanceId) { ss << "  itemInstanceId " << result->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  remainingUses " << result->remainingUses; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogClientGetCharacterInventoryRequest(PFPlayerItemManagementClientGetCharacterInventoryRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetCharacterInventoryRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenPlayerItemManagementTests::LogClientGetCharacterInventoryResult(PFPlayerItemManagementClientGetCharacterInventoryResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementClientGetCharacterInventoryResult    
    if (result->characterId) { ss << "  characterId " << result->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  inventoryCount " << result->inventoryCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->inventoryCount; i++)
    {
            ss << "  result->inventory[" << i << "]:" << result->inventory[i]; Log(ss); // PFItemInstance
    }         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyRechargeTimesCount " << result->virtualCurrencyRechargeTimesCount; Log(ss);

    // PFVirtualCurrencyRechargeTimeDictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyRechargeTimesCount; i++)
    {
            ss << "  result->virtualCurrencyRechargeTimes[" << i << "]:" << result->virtualCurrencyRechargeTimes[i].key << "=" << result->virtualCurrencyRechargeTimes[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogGetPaymentTokenRequest(PFPlayerItemManagementGetPaymentTokenRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetPaymentTokenRequest struct:
    // request->tokenProvider: const char*
    if (request->tokenProvider) { ss << "  tokenProvider " << request->tokenProvider; Log(ss); } else { ss << "  tokenProvider = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogGetPaymentTokenResult(PFPlayerItemManagementGetPaymentTokenResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementGetPaymentTokenResult    
    if (result->orderId) { ss << "  orderId " << result->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char*     
    if (result->providerToken) { ss << "  providerToken " << result->providerToken; Log(ss); } else { ss << "  providerToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogGetPurchaseRequest(PFPlayerItemManagementGetPurchaseRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetPurchaseRequest struct:
    // request->orderId: const char*
    if (request->orderId) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogGetPurchaseResult(PFPlayerItemManagementGetPurchaseResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementGetPurchaseResult    
    if (result->orderId) { ss << "  orderId " << result->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char*     
    if (result->paymentProvider) { ss << "  paymentProvider " << result->paymentProvider; Log(ss); } else { ss << "  paymentProvider = nullptr"; Log(ss); } // Class: const char*     
    ss << "  purchaseDate " << result->purchaseDate; Log(ss); // Class: time_t     
    if (result->transactionId) { ss << "  transactionId " << result->transactionId; Log(ss); } else { ss << "  transactionId = nullptr"; Log(ss); } // Class: const char*     
    if (result->transactionStatus) { ss << "  transactionStatus " << result->transactionStatus; Log(ss); } else { ss << "  transactionStatus = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogClientGetUserInventoryRequest(PFPlayerItemManagementClientGetUserInventoryRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetUserInventoryRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenPlayerItemManagementTests::LogClientGetUserInventoryResult(PFPlayerItemManagementClientGetUserInventoryResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementClientGetUserInventoryResult        
    ss << "  inventoryCount " << result->inventoryCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->inventoryCount; i++)
    {
            ss << "  result->inventory[" << i << "]:" << result->inventory[i]; Log(ss); // PFItemInstance
    }         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyRechargeTimesCount " << result->virtualCurrencyRechargeTimesCount; Log(ss);

    // PFVirtualCurrencyRechargeTimeDictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyRechargeTimesCount; i++)
    {
            ss << "  result->virtualCurrencyRechargeTimes[" << i << "]:" << result->virtualCurrencyRechargeTimes[i].key << "=" << result->virtualCurrencyRechargeTimes[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogPayForPurchaseRequest(PFPlayerItemManagementPayForPurchaseRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementPayForPurchaseRequest struct:
    // request->currency: const char*
    if (request->currency) { ss << "  currency " << request->currency; Log(ss); } else { ss << "  currency = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->orderId) { ss << "  orderId " << request->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char* 
    if (request->providerName) { ss << "  providerName " << request->providerName; Log(ss); } else { ss << "  providerName = nullptr"; Log(ss); } // Class: const char* 
    if (request->providerTransactionId) { ss << "  providerTransactionId " << request->providerTransactionId; Log(ss); } else { ss << "  providerTransactionId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogPayForPurchaseResult(PFPlayerItemManagementPayForPurchaseResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementPayForPurchaseResult    
    ss << "  creditApplied " << result->creditApplied; Log(ss); // Class: uint32_t     
    if (result->orderId) { ss << "  orderId " << result->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char*     
    if (result->providerData) { ss << "  providerData " << result->providerData; Log(ss); } else { ss << "  providerData = nullptr"; Log(ss); } // Class: const char*     
    if (result->providerToken) { ss << "  providerToken " << result->providerToken; Log(ss); } else { ss << "  providerToken = nullptr"; Log(ss); } // Class: const char*     
    if (result->purchaseConfirmationPageURL) { ss << "  purchaseConfirmationPageURL " << result->purchaseConfirmationPageURL; Log(ss); } else { ss << "  purchaseConfirmationPageURL = nullptr"; Log(ss); } // Class: const char*     
    if (result->purchaseCurrency) { ss << "  purchaseCurrency " << result->purchaseCurrency; Log(ss); } else { ss << "  purchaseCurrency = nullptr"; Log(ss); } // Class: const char*     
    ss << "  purchasePrice " << result->purchasePrice; Log(ss); // Class: uint32_t     
    ss << "  status " << result->status; Log(ss); // Class: PFPlayerItemManagementTransactionStatus         
    ss << "  vCAmountCount " << result->vCAmountCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->vCAmountCount; i++)
    {
            ss << "  result->vCAmount[" << i << "]:" << result->vCAmount[i].key << "=" << result->vCAmount[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogPurchaseItemRequest(PFPlayerItemManagementPurchaseItemRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementPurchaseItemRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->itemId) { ss << "  itemId " << request->itemId; Log(ss); } else { ss << "  itemId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  price " << request->price; Log(ss); // Class: int32_t 
    if (request->storeId) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogPurchaseItemResult(PFPlayerItemManagementPurchaseItemResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementPurchaseItemResult        
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->itemsCount; i++)
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFItemInstance
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogClientRedeemCouponRequest(PFPlayerItemManagementClientRedeemCouponRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementRedeemCouponRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->couponCode) { ss << "  couponCode " << request->couponCode; Log(ss); } else { ss << "  couponCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenPlayerItemManagementTests::LogRedeemCouponResult(PFPlayerItemManagementRedeemCouponResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementRedeemCouponResult        
    ss << "  grantedItemsCount " << result->grantedItemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->grantedItemsCount; i++)
    {
            ss << "  result->grantedItems[" << i << "]:" << result->grantedItems[i]; Log(ss); // PFItemInstance
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogStartPurchaseRequest(PFPlayerItemManagementStartPurchaseRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementStartPurchaseRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  itemsCount " << request->itemsCount; Log(ss);

    // PFPlayerItemManagementItemPurchaseRequest
    for (uint32_t i=0; i<request->itemsCount; i++)
    {
            ss << "  request->items[" << i << "]:" << request->items[i]; Log(ss); // PFPlayerItemManagementItemPurchaseRequest
    } 
    if (request->storeId) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogStartPurchaseResult(PFPlayerItemManagementStartPurchaseResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementStartPurchaseResult        
    ss << "  contentsCount " << result->contentsCount; Log(ss);

    // PFPlayerItemManagementCartItem
    for (uint32_t i=0; i<result->contentsCount; i++)
    {
            ss << "  result->contents[" << i << "]:" << result->contents[i]; Log(ss); // PFPlayerItemManagementCartItem
    }     
    if (result->orderId) { ss << "  orderId " << result->orderId; Log(ss); } else { ss << "  orderId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  paymentOptionsCount " << result->paymentOptionsCount; Log(ss);

    // PFPlayerItemManagementPaymentOption
    for (uint32_t i=0; i<result->paymentOptionsCount; i++)
    {
            ss << "  result->paymentOptions[" << i << "]:" << result->paymentOptions[i]; Log(ss); // PFPlayerItemManagementPaymentOption
    }         
    ss << "  virtualCurrencyBalancesCount " << result->virtualCurrencyBalancesCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyBalancesCount; i++)
    {
            ss << "  result->virtualCurrencyBalances[" << i << "]:" << result->virtualCurrencyBalances[i].key << "=" << result->virtualCurrencyBalances[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogClientSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementSubtractUserVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogClientUnlockContainerInstanceRequest(PFPlayerItemManagementClientUnlockContainerInstanceRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementUnlockContainerInstanceRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->containerItemInstanceId) { ss << "  containerItemInstanceId " << request->containerItemInstanceId; Log(ss); } else { ss << "  containerItemInstanceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->keyItemInstanceId) { ss << "  keyItemInstanceId " << request->keyItemInstanceId; Log(ss); } else { ss << "  keyItemInstanceId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogUnlockContainerItemResult(PFPlayerItemManagementUnlockContainerItemResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementUnlockContainerItemResult        
    ss << "  grantedItemsCount " << result->grantedItemsCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->grantedItemsCount; i++)
    {
            ss << "  result->grantedItems[" << i << "]:" << result->grantedItems[i]; Log(ss); // PFItemInstance
    }     
    if (result->unlockedItemInstanceId) { ss << "  unlockedItemInstanceId " << result->unlockedItemInstanceId; Log(ss); } else { ss << "  unlockedItemInstanceId = nullptr"; Log(ss); } // Class: const char*     
    if (result->unlockedWithItemInstanceId) { ss << "  unlockedWithItemInstanceId " << result->unlockedWithItemInstanceId; Log(ss); } else { ss << "  unlockedWithItemInstanceId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFUint32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogClientUnlockContainerItemRequest(PFPlayerItemManagementClientUnlockContainerItemRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementUnlockContainerItemRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->containerItemId) { ss << "  containerItemId " << request->containerItemId; Log(ss); } else { ss << "  containerItemId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenPlayerItemManagementTests::LogAddCharacterVirtualCurrencyRequest(PFPlayerItemManagementAddCharacterVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementAddCharacterVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogModifyCharacterVirtualCurrencyResult(PFPlayerItemManagementModifyCharacterVirtualCurrencyResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementModifyCharacterVirtualCurrencyResult    
    ss << "  balance " << result->balance; Log(ss); // Class: int32_t     
    if (result->virtualCurrency) { ss << "  virtualCurrency " << result->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogServerAddUserVirtualCurrencyRequest(PFPlayerItemManagementServerAddUserVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementAddUserVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogServerConsumeItemRequest(PFPlayerItemManagementServerConsumeItemRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementConsumeItemRequest struct:
    // request->characterId: const char*
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  consumeCount " << request->consumeCount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogEvaluateRandomResultTableRequest(PFPlayerItemManagementEvaluateRandomResultTableRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementEvaluateRandomResultTableRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->tableId) { ss << "  tableId " << request->tableId; Log(ss); } else { ss << "  tableId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogEvaluateRandomResultTableResult(PFPlayerItemManagementEvaluateRandomResultTableResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementEvaluateRandomResultTableResult    
    if (result->resultItemId) { ss << "  resultItemId " << result->resultItemId; Log(ss); } else { ss << "  resultItemId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogServerGetCharacterInventoryRequest(PFPlayerItemManagementServerGetCharacterInventoryRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetCharacterInventoryRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogServerGetCharacterInventoryResult(PFPlayerItemManagementServerGetCharacterInventoryResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementServerGetCharacterInventoryResult    
    if (result->characterId) { ss << "  characterId " << result->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  inventoryCount " << result->inventoryCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->inventoryCount; i++)
    {
            ss << "  result->inventory[" << i << "]:" << result->inventory[i]; Log(ss); // PFItemInstance
    }     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyRechargeTimesCount " << result->virtualCurrencyRechargeTimesCount; Log(ss);

    // PFVirtualCurrencyRechargeTimeDictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyRechargeTimesCount; i++)
    {
            ss << "  result->virtualCurrencyRechargeTimes[" << i << "]:" << result->virtualCurrencyRechargeTimes[i].key << "=" << result->virtualCurrencyRechargeTimes[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogGetRandomResultTablesRequest(PFPlayerItemManagementGetRandomResultTablesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetRandomResultTablesRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  tableIDsCount " << request->tableIDsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->tableIDsCount; i++)
    {
            ss << "  request->tableIDs[" << i << "]:" << request->tableIDs[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenPlayerItemManagementTests::LogGetRandomResultTablesResult(PFGetRandomResultTablesResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementGetRandomResultTablesResult        
    ss << "  tablesCount " << result->tablesCount; Log(ss);

    // PFRandomResultTableListingDictionaryEntry
    for (uint32_t i=0; i<result->tablesCount; i++)
    {
            ss << "  result->tables[" << i << "]:" << result->tables[i].key << "=" << result->tables[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogServerGetUserInventoryRequest(PFPlayerItemManagementServerGetUserInventoryRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGetUserInventoryRequest struct:
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

HRESULT AutoGenPlayerItemManagementTests::LogServerGetUserInventoryResult(PFPlayerItemManagementServerGetUserInventoryResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementServerGetUserInventoryResult        
    ss << "  inventoryCount " << result->inventoryCount; Log(ss);

    // PFItemInstance
    for (uint32_t i=0; i<result->inventoryCount; i++)
    {
            ss << "  result->inventory[" << i << "]:" << result->inventory[i]; Log(ss); // PFItemInstance
    }     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  virtualCurrencyCount " << result->virtualCurrencyCount; Log(ss);

    // PFInt32DictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyCount; i++)
    {
            ss << "  result->virtualCurrency[" << i << "]:" << result->virtualCurrency[i].key << "=" << result->virtualCurrency[i].value; Log(ss);
            
    }         
    ss << "  virtualCurrencyRechargeTimesCount " << result->virtualCurrencyRechargeTimesCount; Log(ss);

    // PFVirtualCurrencyRechargeTimeDictionaryEntry
    for (uint32_t i=0; i<result->virtualCurrencyRechargeTimesCount; i++)
    {
            ss << "  result->virtualCurrencyRechargeTimes[" << i << "]:" << result->virtualCurrencyRechargeTimes[i].key << "=" << result->virtualCurrencyRechargeTimes[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogGrantItemsToCharacterRequest(PFPlayerItemManagementGrantItemsToCharacterRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGrantItemsToCharacterRequest struct:
    // request->annotation: const char*
    if (request->annotation) { ss << "  annotation " << request->annotation; Log(ss); } else { ss << "  annotation = nullptr"; Log(ss); } // Class: const char* 
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  itemIdsCount " << request->itemIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->itemIdsCount; i++)
    {
            ss << "  request->itemIds[" << i << "]:" << request->itemIds[i]; Log(ss); // const char*
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogGrantItemsToCharacterResult(PFPlayerItemManagementGrantItemsToCharacterResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementGrantItemsToCharacterResult        
    ss << "  itemGrantResultsCount " << result->itemGrantResultsCount; Log(ss);

    // PFPlayerItemManagementGrantedItemInstance
    for (uint32_t i=0; i<result->itemGrantResultsCount; i++)
    {
            ss << "  result->itemGrantResults[" << i << "]:" << result->itemGrantResults[i]; Log(ss); // PFPlayerItemManagementGrantedItemInstance
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogGrantItemsToUserRequest(PFPlayerItemManagementGrantItemsToUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementGrantItemsToUserRequest struct:
    // request->annotation: const char*
    if (request->annotation) { ss << "  annotation " << request->annotation; Log(ss); } else { ss << "  annotation = nullptr"; Log(ss); } // Class: const char* 
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  itemIdsCount " << request->itemIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->itemIdsCount; i++)
    {
            ss << "  request->itemIds[" << i << "]:" << request->itemIds[i]; Log(ss); // const char*
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogGrantItemsToUserResult(PFPlayerItemManagementGrantItemsToUserResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementGrantItemsToUserResult        
    ss << "  itemGrantResultsCount " << result->itemGrantResultsCount; Log(ss);

    // PFPlayerItemManagementGrantedItemInstance
    for (uint32_t i=0; i<result->itemGrantResultsCount; i++)
    {
            ss << "  result->itemGrantResults[" << i << "]:" << result->itemGrantResults[i]; Log(ss); // PFPlayerItemManagementGrantedItemInstance
    } 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogModifyItemUsesRequest(PFPlayerItemManagementModifyItemUsesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementModifyItemUsesRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  usesToAdd " << request->usesToAdd; Log(ss); // Class: int32_t 

}

HRESULT AutoGenPlayerItemManagementTests::LogModifyItemUsesResult(PFPlayerItemManagementModifyItemUsesResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementModifyItemUsesResult    
    if (result->itemInstanceId) { ss << "  itemInstanceId " << result->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  remainingUses " << result->remainingUses; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogMoveItemToCharacterFromCharacterRequest(PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementMoveItemToCharacterFromCharacterRequest struct:
    // request->givingCharacterId: const char*
    if (request->givingCharacterId) { ss << "  givingCharacterId " << request->givingCharacterId; Log(ss); } else { ss << "  givingCharacterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->receivingCharacterId) { ss << "  receivingCharacterId " << request->receivingCharacterId; Log(ss); } else { ss << "  receivingCharacterId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogMoveItemToCharacterFromUserRequest(PFPlayerItemManagementMoveItemToCharacterFromUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementMoveItemToCharacterFromUserRequest struct:
    // request->characterId: const char*
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogMoveItemToUserFromCharacterRequest(PFPlayerItemManagementMoveItemToUserFromCharacterRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementMoveItemToUserFromCharacterRequest struct:
    // request->characterId: const char*
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogServerRedeemCouponRequest(PFPlayerItemManagementServerRedeemCouponRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementRedeemCouponRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->couponCode) { ss << "  couponCode " << request->couponCode; Log(ss); } else { ss << "  couponCode = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogReportPlayerServerRequest(PFPlayerItemManagementReportPlayerServerRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementReportPlayerServerRequest struct:
    // request->comment: const char*
    if (request->comment) { ss << "  comment " << request->comment; Log(ss); } else { ss << "  comment = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->reporteeId) { ss << "  reporteeId " << request->reporteeId; Log(ss); } else { ss << "  reporteeId = nullptr"; Log(ss); } // Class: const char* 
    if (request->reporterId) { ss << "  reporterId " << request->reporterId; Log(ss); } else { ss << "  reporterId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerItemManagementTests::LogReportPlayerServerResult(PFPlayerItemManagementReportPlayerServerResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerItemManagementReportPlayerServerResult    
    ss << "  submissionsRemaining " << result->submissionsRemaining; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenPlayerItemManagementTests::LogSubtractCharacterVirtualCurrencyRequest(PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementSubtractCharacterVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogServerSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementSubtractUserVirtualCurrencyRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if (request->virtualCurrency) { ss << "  virtualCurrency " << request->virtualCurrency; Log(ss); } else { ss << "  virtualCurrency = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogServerUnlockContainerInstanceRequest(PFPlayerItemManagementServerUnlockContainerInstanceRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementUnlockContainerInstanceRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->containerItemInstanceId) { ss << "  containerItemInstanceId " << request->containerItemInstanceId; Log(ss); } else { ss << "  containerItemInstanceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->keyItemInstanceId) { ss << "  keyItemInstanceId " << request->keyItemInstanceId; Log(ss); } else { ss << "  keyItemInstanceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogServerUnlockContainerItemRequest(PFPlayerItemManagementServerUnlockContainerItemRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementUnlockContainerItemRequest struct:
    // request->catalogVersion: const char*
    if (request->catalogVersion) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char* 
    if (request->containerItemId) { ss << "  containerItemId " << request->containerItemId; Log(ss); } else { ss << "  containerItemId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPlayerItemManagementTests::LogUpdateUserInventoryItemDataRequest(PFPlayerItemManagementUpdateUserInventoryItemDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerItemManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerItemManagementUpdateUserInventoryItemDataRequest struct:
    // request->characterId: const char*
    if (request->characterId) { ss << "  characterId " << request->characterId; Log(ss); } else { ss << "  characterId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  dataCount " << request->dataCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->dataCount; i++)
    {
            ss << "  request->data[" << i << "]:" << request->data[i].key << "=" << request->data[i].value; Log(ss);
            
    } 
    if (request->itemInstanceId) { ss << "  itemInstanceId " << request->itemInstanceId; Log(ss); } else { ss << "  itemInstanceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysToRemoveCount; i++)
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
