#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenInventoryTests.h"
#include "XAsyncHelper.h"

uint32_t g_InventoryTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenInventoryTests::LogAddInventoryItemsRequest(PFInventoryAddInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryAddInventoryItemsRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t 
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  item " << request->item; Log(ss); // Class: PFInventoryInventoryItemReference 

}

HRESULT AutoGenInventoryTests::LogAddInventoryItemsResponse(PFInventoryAddInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryAddInventoryItemsResponse    
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogDeleteInventoryCollectionRequest(PFInventoryDeleteInventoryCollectionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryDeleteInventoryCollectionRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

void AutoGenInventoryTests::LogDeleteInventoryItemsRequest(PFInventoryDeleteInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryDeleteInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  item " << request->item; Log(ss); // Class: PFInventoryInventoryItemReference 

}

HRESULT AutoGenInventoryTests::LogDeleteInventoryItemsResponse(PFInventoryDeleteInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryDeleteInventoryItemsResponse    
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogExecuteInventoryOperationsRequest(PFInventoryExecuteInventoryOperationsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryExecuteInventoryOperationsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  operationsCount " << request->operationsCount; Log(ss);

    // PFInventoryInventoryOperation
    for (uint32_t i=0; i<request->operationsCount; i++)
    {
            ss << "  request->operations[" << i << "]:" << request->operations[i]; Log(ss); // PFInventoryInventoryOperation
    } 

}

HRESULT AutoGenInventoryTests::LogExecuteInventoryOperationsResponse(PFInventoryExecuteInventoryOperationsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryExecuteInventoryOperationsResponse    
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogGetInventoryCollectionIdsRequest(PFInventoryGetInventoryCollectionIdsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryGetInventoryCollectionIdsRequest struct:
    // request->continuationToken: const char*
    if (request->continuationToken) { ss << "  continuationToken " << request->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  count " << request->count; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenInventoryTests::LogGetInventoryCollectionIdsResponse(PFInventoryGetInventoryCollectionIdsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryGetInventoryCollectionIdsResponse        
    ss << "  collectionIdsCount " << result->collectionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->collectionIdsCount; i++)
    {
            ss << "  result->collectionIds[" << i << "]:" << result->collectionIds[i]; Log(ss); // const char*
    }     
    if (result->continuationToken) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenInventoryTests::LogGetInventoryItemsRequest(PFInventoryGetInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryGetInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char* 
    if (request->continuationToken) { ss << "  continuationToken " << request->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  count " << request->count; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->filter) { ss << "  filter " << request->filter; Log(ss); } else { ss << "  filter = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenInventoryTests::LogGetInventoryItemsResponse(PFInventoryGetInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryGetInventoryItemsResponse    
    if (result->continuationToken) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*         
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFInventoryInventoryItem
    for (uint32_t i=0; i<result->itemsCount; i++)
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFInventoryInventoryItem
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogGetMicrosoftStoreAccessTokensRequest(PFInventoryGetMicrosoftStoreAccessTokensRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryGetMicrosoftStoreAccessTokensRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenInventoryTests::LogGetMicrosoftStoreAccessTokensResponse(PFInventoryGetMicrosoftStoreAccessTokensResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryGetMicrosoftStoreAccessTokensResponse    
    if (result->collectionsAccessToken) { ss << "  collectionsAccessToken " << result->collectionsAccessToken; Log(ss); } else { ss << "  collectionsAccessToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  collectionsAccessTokenExpirationDate " << result->collectionsAccessTokenExpirationDate; Log(ss); // Class: time_t 
    return S_OK;
}

void AutoGenInventoryTests::LogPurchaseInventoryItemsRequest(PFInventoryPurchaseInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryPurchaseInventoryItemsRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t 
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  deleteEmptyStacks " << request->deleteEmptyStacks; Log(ss); // Class: bool 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  item " << request->item; Log(ss); // Class: PFInventoryInventoryItemReference     
    ss << "  priceAmountsCount " << request->priceAmountsCount; Log(ss);

    // PFInventoryPurchasePriceAmount
    for (uint32_t i=0; i<request->priceAmountsCount; i++)
    {
            ss << "  request->priceAmounts[" << i << "]:" << request->priceAmounts[i]; Log(ss); // PFInventoryPurchasePriceAmount
    } 
    if (request->storeId) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenInventoryTests::LogPurchaseInventoryItemsResponse(PFInventoryPurchaseInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryPurchaseInventoryItemsResponse    
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogRedeemAppleAppStoreInventoryItemsRequest(PFInventoryRedeemAppleAppStoreInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryRedeemAppleAppStoreInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->receipt) { ss << "  receipt " << request->receipt; Log(ss); } else { ss << "  receipt = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenInventoryTests::LogRedeemAppleAppStoreInventoryItemsResponse(PFInventoryRedeemAppleAppStoreInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryRedeemAppleAppStoreInventoryItemsResponse        
    ss << "  failedCount " << result->failedCount; Log(ss);

    // PFInventoryRedemptionFailure
    for (uint32_t i=0; i<result->failedCount; i++)
    {
            ss << "  result->failed[" << i << "]:" << result->failed[i]; Log(ss); // PFInventoryRedemptionFailure
    }         
    ss << "  succeededCount " << result->succeededCount; Log(ss);

    // PFInventoryRedemptionSuccess
    for (uint32_t i=0; i<result->succeededCount; i++)
    {
            ss << "  result->succeeded[" << i << "]:" << result->succeeded[i]; Log(ss); // PFInventoryRedemptionSuccess
    }         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogRedeemGooglePlayInventoryItemsRequest(PFInventoryRedeemGooglePlayInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryRedeemGooglePlayInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey     
    ss << "  purchasesCount " << request->purchasesCount; Log(ss);

    // PFInventoryGooglePlayProductPurchase
    for (uint32_t i=0; i<request->purchasesCount; i++)
    {
            ss << "  request->purchases[" << i << "]:" << request->purchases[i]; Log(ss); // PFInventoryGooglePlayProductPurchase
    } 

}

HRESULT AutoGenInventoryTests::LogRedeemGooglePlayInventoryItemsResponse(PFInventoryRedeemGooglePlayInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryRedeemGooglePlayInventoryItemsResponse        
    ss << "  failedCount " << result->failedCount; Log(ss);

    // PFInventoryRedemptionFailure
    for (uint32_t i=0; i<result->failedCount; i++)
    {
            ss << "  result->failed[" << i << "]:" << result->failed[i]; Log(ss); // PFInventoryRedemptionFailure
    }         
    ss << "  succeededCount " << result->succeededCount; Log(ss);

    // PFInventoryRedemptionSuccess
    for (uint32_t i=0; i<result->succeededCount; i++)
    {
            ss << "  result->succeeded[" << i << "]:" << result->succeeded[i]; Log(ss); // PFInventoryRedemptionSuccess
    }         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogRedeemMicrosoftStoreInventoryItemsRequest(PFInventoryRedeemMicrosoftStoreInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryRedeemMicrosoftStoreInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char* 
    if (request->collectionsIdKey) { ss << "  collectionsIdKey " << request->collectionsIdKey; Log(ss); } else { ss << "  collectionsIdKey = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenInventoryTests::LogRedeemMicrosoftStoreInventoryItemsResponse(PFInventoryRedeemMicrosoftStoreInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryRedeemMicrosoftStoreInventoryItemsResponse        
    ss << "  failedCount " << result->failedCount; Log(ss);

    // PFInventoryRedemptionFailure
    for (uint32_t i=0; i<result->failedCount; i++)
    {
            ss << "  result->failed[" << i << "]:" << result->failed[i]; Log(ss); // PFInventoryRedemptionFailure
    }         
    ss << "  succeededCount " << result->succeededCount; Log(ss);

    // PFInventoryRedemptionSuccess
    for (uint32_t i=0; i<result->succeededCount; i++)
    {
            ss << "  result->succeeded[" << i << "]:" << result->succeeded[i]; Log(ss); // PFInventoryRedemptionSuccess
    }         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogRedeemNintendoEShopInventoryItemsRequest(PFInventoryRedeemNintendoEShopInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryRedeemNintendoEShopInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->nintendoServiceAccountIdToken) { ss << "  nintendoServiceAccountIdToken " << request->nintendoServiceAccountIdToken; Log(ss); } else { ss << "  nintendoServiceAccountIdToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenInventoryTests::LogRedeemNintendoEShopInventoryItemsResponse(PFInventoryRedeemNintendoEShopInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryRedeemNintendoEShopInventoryItemsResponse        
    ss << "  failedCount " << result->failedCount; Log(ss);

    // PFInventoryRedemptionFailure
    for (uint32_t i=0; i<result->failedCount; i++)
    {
            ss << "  result->failed[" << i << "]:" << result->failed[i]; Log(ss); // PFInventoryRedemptionFailure
    }         
    ss << "  succeededCount " << result->succeededCount; Log(ss);

    // PFInventoryRedemptionSuccess
    for (uint32_t i=0; i<result->succeededCount; i++)
    {
            ss << "  result->succeeded[" << i << "]:" << result->succeeded[i]; Log(ss); // PFInventoryRedemptionSuccess
    }         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogRedeemPlayStationStoreInventoryItemsRequest(PFInventoryRedeemPlayStationStoreInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryRedeemPlayStationStoreInventoryItemsRequest struct:
    // request->authorizationCode: const char*
    if (request->authorizationCode) { ss << "  authorizationCode " << request->authorizationCode; Log(ss); } else { ss << "  authorizationCode = nullptr"; Log(ss); } // Class: const char* 
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->serviceLabel) { ss << "  serviceLabel " << request->serviceLabel; Log(ss); } else { ss << "  serviceLabel = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenInventoryTests::LogRedeemPlayStationStoreInventoryItemsResponse(PFInventoryRedeemPlayStationStoreInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryRedeemPlayStationStoreInventoryItemsResponse        
    ss << "  failedCount " << result->failedCount; Log(ss);

    // PFInventoryRedemptionFailure
    for (uint32_t i=0; i<result->failedCount; i++)
    {
            ss << "  result->failed[" << i << "]:" << result->failed[i]; Log(ss); // PFInventoryRedemptionFailure
    }         
    ss << "  succeededCount " << result->succeededCount; Log(ss);

    // PFInventoryRedemptionSuccess
    for (uint32_t i=0; i<result->succeededCount; i++)
    {
            ss << "  result->succeeded[" << i << "]:" << result->succeeded[i]; Log(ss); // PFInventoryRedemptionSuccess
    }         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogRedeemSteamInventoryItemsRequest(PFInventoryRedeemSteamInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryRedeemSteamInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenInventoryTests::LogRedeemSteamInventoryItemsResponse(PFInventoryRedeemSteamInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryRedeemSteamInventoryItemsResponse        
    ss << "  failedCount " << result->failedCount; Log(ss);

    // PFInventoryRedemptionFailure
    for (uint32_t i=0; i<result->failedCount; i++)
    {
            ss << "  result->failed[" << i << "]:" << result->failed[i]; Log(ss); // PFInventoryRedemptionFailure
    }         
    ss << "  succeededCount " << result->succeededCount; Log(ss);

    // PFInventoryRedemptionSuccess
    for (uint32_t i=0; i<result->succeededCount; i++)
    {
            ss << "  result->succeeded[" << i << "]:" << result->succeeded[i]; Log(ss); // PFInventoryRedemptionSuccess
    }         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogSubtractInventoryItemsRequest(PFInventorySubtractInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventorySubtractInventoryItemsRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t 
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  deleteEmptyStacks " << request->deleteEmptyStacks; Log(ss); // Class: bool 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  item " << request->item; Log(ss); // Class: PFInventoryInventoryItemReference 

}

HRESULT AutoGenInventoryTests::LogSubtractInventoryItemsResponse(PFInventorySubtractInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventorySubtractInventoryItemsResponse    
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogTransferInventoryItemsRequest(PFInventoryTransferInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryTransferInventoryItemsRequest struct:
    // request->amount: int32_t
    ss << "  amount " << request->amount; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  deleteEmptyStacks " << request->deleteEmptyStacks; Log(ss); // Class: bool 
    if (request->givingCollectionId) { ss << "  givingCollectionId " << request->givingCollectionId; Log(ss); } else { ss << "  givingCollectionId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  givingEntity " << request->givingEntity; Log(ss); // Class: PFEntityKey 
    ss << "  givingItem " << request->givingItem; Log(ss); // Class: PFInventoryInventoryItemReference 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char* 
    if (request->receivingCollectionId) { ss << "  receivingCollectionId " << request->receivingCollectionId; Log(ss); } else { ss << "  receivingCollectionId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  receivingEntity " << request->receivingEntity; Log(ss); // Class: PFEntityKey 
    ss << "  receivingItem " << request->receivingItem; Log(ss); // Class: PFInventoryInventoryItemReference 

}

HRESULT AutoGenInventoryTests::LogTransferInventoryItemsResponse(PFInventoryTransferInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryTransferInventoryItemsResponse        
    ss << "  givingTransactionIdsCount " << result->givingTransactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->givingTransactionIdsCount; i++)
    {
            ss << "  result->givingTransactionIds[" << i << "]:" << result->givingTransactionIds[i]; Log(ss); // const char*
    }     
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  receivingTransactionIdsCount " << result->receivingTransactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->receivingTransactionIdsCount; i++)
    {
            ss << "  result->receivingTransactionIds[" << i << "]:" << result->receivingTransactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

void AutoGenInventoryTests::LogUpdateInventoryItemsRequest(PFInventoryUpdateInventoryItemsRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_InventoryTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabInventoryUpdateInventoryItemsRequest struct:
    // request->collectionId: const char*
    if (request->collectionId) { ss << "  collectionId " << request->collectionId; Log(ss); } else { ss << "  collectionId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->idempotencyId) { ss << "  idempotencyId " << request->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  item " << request->item; Log(ss); // Class: PFInventoryInventoryItem 

}

HRESULT AutoGenInventoryTests::LogUpdateInventoryItemsResponse(PFInventoryUpdateInventoryItemsResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabInventoryUpdateInventoryItemsResponse    
    if (result->idempotencyId) { ss << "  idempotencyId " << result->idempotencyId; Log(ss); } else { ss << "  idempotencyId = nullptr"; Log(ss); } // Class: const char*         
    ss << "  transactionIdsCount " << result->transactionIdsCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<result->transactionIdsCount; i++)
    {
            ss << "  result->transactionIds[" << i << "]:" << result->transactionIds[i]; Log(ss); // const char*
    } 
    return S_OK;
}

 

}
