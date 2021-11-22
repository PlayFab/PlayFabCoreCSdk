#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCatalogTests.h"
#include "XAsyncHelper.h"

uint32_t g_CatalogTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenCatalogTests::LogCreateDraftItemRequest(PFCatalogCreateDraftItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogCreateDraftItemRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  item " << request->item; Log(ss); // Class: PFCatalogCatalogItem 
    ss << "  publish " << request->publish; Log(ss); // Class: bool 

}

HRESULT AutoGenCatalogTests::LogPFCatalogCreateDraftItemResponse(PFCatalogCreateDraftItemResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogCreateDraftItemResponse
    ss << "  item " << result->item; Log(ss); // Class: PFCatalogCatalogItem 
    return S_OK;
}

void AutoGenCatalogTests::LogCreateUploadUrlsRequest(PFCatalogCreateUploadUrlsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogCreateUploadUrlsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  filesCount " << request->filesCount; Log(ss);

    // PFCatalogUploadInfo
    for( uint32_t i=0; i<request->filesCount; i++ )
    {
            ss << "  request->files[" << i << "]:" << request->files[i]; Log(ss); // PFCatalogUploadInfo
    } 

}

HRESULT AutoGenCatalogTests::LogPFCatalogCreateUploadUrlsResponse(PFCatalogCreateUploadUrlsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogCreateUploadUrlsResponse    
    ss << "  uploadUrlsCount " << result->uploadUrlsCount; Log(ss);

    // PFCatalogUploadUrlMetadata
    for( uint32_t i=0; i<result->uploadUrlsCount; i++ )
    {
            ss << "  result->uploadUrls[" << i << "]:" << result->uploadUrls[i]; Log(ss); // PFCatalogUploadUrlMetadata
    } 
    return S_OK;
}

void AutoGenCatalogTests::LogDeleteEntityItemReviewsRequest(PFCatalogDeleteEntityItemReviewsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogDeleteEntityItemReviewsRequest struct:
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

void AutoGenCatalogTests::LogDeleteItemRequest(PFCatalogDeleteItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogDeleteItemRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCatalogTests::LogGetCatalogConfigRequest(PFCatalogGetCatalogConfigRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetCatalogConfigRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetCatalogConfigResponse(PFCatalogGetCatalogConfigResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetCatalogConfigResponse
    ss << "  config " << result->config; Log(ss); // Class: PFCatalogCatalogConfig 
    return S_OK;
}

void AutoGenCatalogTests::LogGetDraftItemRequest(PFCatalogGetDraftItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetDraftItemRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetDraftItemResponse(PFCatalogGetDraftItemResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetDraftItemResponse
    ss << "  item " << result->item; Log(ss); // Class: PFCatalogCatalogItem 
    return S_OK;
}

void AutoGenCatalogTests::LogGetDraftItemsRequest(PFCatalogGetDraftItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetDraftItemsRequest struct:
    // request->alternateIds: PFCatalogCatalogAlternateId const* const*
    // request->alternateIdsCount: uint32_t    
    ss << "  alternateIdsCount " << request->alternateIdsCount; Log(ss);

    // PFCatalogCatalogAlternateId
    for( uint32_t i=0; i<request->alternateIdsCount; i++ )
    {
            ss << "  request->alternateIds[" << i << "]:" << request->alternateIds[i]; Log(ss); // PFCatalogCatalogAlternateId
    }     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey     
    ss << "  idsCount " << request->idsCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->idsCount; i++ )
    {
            ss << "  request->ids[" << i << "]:" << request->ids[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetDraftItemsResponse(PFCatalogGetDraftItemsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetDraftItemsResponse
    if( result->continuationToken ) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFCatalogCatalogItem
    for( uint32_t i=0; i<result->itemsCount; i++ )
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFCatalogCatalogItem
    } 
    return S_OK;
}

void AutoGenCatalogTests::LogGetEntityDraftItemsRequest(PFCatalogGetEntityDraftItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetEntityDraftItemsRequest struct:
    // request->continuationToken: const char*
    if( request->continuationToken ) { ss << "  continuationToken " << request->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  count " << request->count; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetEntityDraftItemsResponse(PFCatalogGetEntityDraftItemsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetEntityDraftItemsResponse
    if( result->continuationToken ) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFCatalogCatalogItem
    for( uint32_t i=0; i<result->itemsCount; i++ )
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFCatalogCatalogItem
    } 
    return S_OK;
}

void AutoGenCatalogTests::LogGetEntityItemReviewRequest(PFCatalogGetEntityItemReviewRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetEntityItemReviewRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetEntityItemReviewResponse(PFCatalogGetEntityItemReviewResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetEntityItemReviewResponse
    ss << "  review " << result->review; Log(ss); // Class: PFCatalogReview 
    return S_OK;
}

void AutoGenCatalogTests::LogGetItemRequest(PFCatalogGetItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetItemRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetItemResponse(PFCatalogGetItemResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetItemResponse
    ss << "  item " << result->item; Log(ss); // Class: PFCatalogCatalogItem 
    return S_OK;
}

void AutoGenCatalogTests::LogGetItemModerationStateRequest(PFCatalogGetItemModerationStateRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetItemModerationStateRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetItemModerationStateResponse(PFCatalogGetItemModerationStateResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetItemModerationStateResponse
    ss << "  state " << result->state; Log(ss); // Class: PFCatalogModerationState 
    return S_OK;
}

void AutoGenCatalogTests::LogGetItemPublishStatusRequest(PFCatalogGetItemPublishStatusRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetItemPublishStatusRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetItemPublishStatusResponse(PFCatalogGetItemPublishStatusResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetItemPublishStatusResponse    
    ss << "  failedScanResultsCount " << result->failedScanResultsCount; Log(ss);

    // PFCatalogScanResult
    for( uint32_t i=0; i<result->failedScanResultsCount; i++ )
    {
            ss << "  result->failedScanResults[" << i << "]:" << result->failedScanResults[i]; Log(ss); // PFCatalogScanResult
    } 
    ss << "  result " << result->result; Log(ss); // Class: PFCatalogPublishResult 
    if( result->statusMessage ) { ss << "  statusMessage " << result->statusMessage; Log(ss); } else { ss << "  statusMessage = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenCatalogTests::LogGetItemReviewsRequest(PFCatalogGetItemReviewsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetItemReviewsRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId 
    if( request->continuationToken ) { ss << "  continuationToken " << request->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  count " << request->count; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 
    if( request->orderBy ) { ss << "  orderBy " << request->orderBy; Log(ss); } else { ss << "  orderBy = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetItemReviewsResponse(PFCatalogGetItemReviewsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetItemReviewsResponse
    if( result->continuationToken ) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  reviewsCount " << result->reviewsCount; Log(ss);

    // PFCatalogReview
    for( uint32_t i=0; i<result->reviewsCount; i++ )
    {
            ss << "  result->reviews[" << i << "]:" << result->reviews[i]; Log(ss); // PFCatalogReview
    } 
    return S_OK;
}

void AutoGenCatalogTests::LogGetItemReviewSummaryRequest(PFCatalogGetItemReviewSummaryRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogGetItemReviewSummaryRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogGetItemReviewSummaryResponse(PFCatalogGetItemReviewSummaryResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogGetItemReviewSummaryResponse
    ss << "  leastFavorableReview " << result->leastFavorableReview; Log(ss); // Class: PFCatalogReview 
    ss << "  mostFavorableReview " << result->mostFavorableReview; Log(ss); // Class: PFCatalogReview 
    ss << "  rating " << result->rating; Log(ss); // Class: PFCatalogRating 
    ss << "  reviewsCount " << result->reviewsCount; Log(ss); // Class: int32_t 
    return S_OK;
}

void AutoGenCatalogTests::LogPublishDraftItemRequest(PFCatalogPublishDraftItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogPublishDraftItemRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->eTag ) { ss << "  eTag " << request->eTag; Log(ss); } else { ss << "  eTag = nullptr"; Log(ss); } // Class: const char* 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCatalogTests::LogReportItemRequest(PFCatalogReportItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogReportItemRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId 
    ss << "  concernCategory " << request->concernCategory; Log(ss); // Class: PFCatalogConcernCategory     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 
    if( request->reason ) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCatalogTests::LogReportItemReviewRequest(PFCatalogReportItemReviewRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogReportItemReviewRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId 
    ss << "  concernCategory " << request->concernCategory; Log(ss); // Class: PFCatalogConcernCategory     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->itemId ) { ss << "  itemId " << request->itemId; Log(ss); } else { ss << "  itemId = nullptr"; Log(ss); } // Class: const char* 
    if( request->reason ) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 
    if( request->reviewId ) { ss << "  reviewId " << request->reviewId; Log(ss); } else { ss << "  reviewId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenCatalogTests::LogReviewItemRequest(PFCatalogReviewItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogReviewItemRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 
    ss << "  review " << request->review; Log(ss); // Class: PFCatalogReview 

}

void AutoGenCatalogTests::LogSearchItemsRequest(PFCatalogSearchItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogSearchItemsRequest struct:
    // request->continuationToken: const char*
    if( request->continuationToken ) { ss << "  continuationToken " << request->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  count " << request->count; Log(ss); // Class: int32_t     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->filter ) { ss << "  filter " << request->filter; Log(ss); } else { ss << "  filter = nullptr"; Log(ss); } // Class: const char* 
    if( request->orderBy ) { ss << "  orderBy " << request->orderBy; Log(ss); } else { ss << "  orderBy = nullptr"; Log(ss); } // Class: const char* 
    if( request->search ) { ss << "  search " << request->search; Log(ss); } else { ss << "  search = nullptr"; Log(ss); } // Class: const char* 
    if( request->select ) { ss << "  select " << request->select; Log(ss); } else { ss << "  select = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenCatalogTests::LogPFCatalogSearchItemsResponse(PFCatalogSearchItemsResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogSearchItemsResponse
    if( result->continuationToken ) { ss << "  continuationToken " << result->continuationToken; Log(ss); } else { ss << "  continuationToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  itemsCount " << result->itemsCount; Log(ss);

    // PFCatalogCatalogItem
    for( uint32_t i=0; i<result->itemsCount; i++ )
    {
            ss << "  result->items[" << i << "]:" << result->items[i]; Log(ss); // PFCatalogCatalogItem
    } 
    return S_OK;
}

void AutoGenCatalogTests::LogSetItemModerationStateRequest(PFCatalogSetItemModerationStateRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogSetItemModerationStateRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->id ) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 
    if( request->reason ) { ss << "  reason " << request->reason; Log(ss); } else { ss << "  reason = nullptr"; Log(ss); } // Class: const char* 
    ss << "  status " << request->status; Log(ss); // Class: PFCatalogModerationStatus 

}

void AutoGenCatalogTests::LogSubmitItemReviewVoteRequest(PFCatalogSubmitItemReviewVoteRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogSubmitItemReviewVoteRequest struct:
    // request->alternateId: PFCatalogCatalogAlternateId const*
    ss << "  alternateId " << request->alternateId; Log(ss); // Class: PFCatalogCatalogAlternateId     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if( request->itemId ) { ss << "  itemId " << request->itemId; Log(ss); } else { ss << "  itemId = nullptr"; Log(ss); } // Class: const char* 
    if( request->reviewId ) { ss << "  reviewId " << request->reviewId; Log(ss); } else { ss << "  reviewId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  vote " << request->vote; Log(ss); // Class: PFCatalogHelpfulnessVote 

}

void AutoGenCatalogTests::LogTakedownItemReviewsRequest(PFCatalogTakedownItemReviewsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogTakedownItemReviewsRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  reviewsCount " << request->reviewsCount; Log(ss);

    // PFCatalogReviewTakedown
    for( uint32_t i=0; i<request->reviewsCount; i++ )
    {
            ss << "  request->reviews[" << i << "]:" << request->reviews[i]; Log(ss); // PFCatalogReviewTakedown
    } 

}

void AutoGenCatalogTests::LogUpdateCatalogConfigRequest(PFCatalogUpdateCatalogConfigRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogUpdateCatalogConfigRequest struct:
    // request->config: PFCatalogCatalogConfig const*
    ss << "  config " << request->config; Log(ss); // Class: PFCatalogCatalogConfig     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

void AutoGenCatalogTests::LogUpdateDraftItemRequest(PFCatalogUpdateDraftItemRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CatalogTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCatalogUpdateDraftItemRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  item " << request->item; Log(ss); // Class: PFCatalogCatalogItem 
    ss << "  publish " << request->publish; Log(ss); // Class: bool 

}

HRESULT AutoGenCatalogTests::LogPFCatalogUpdateDraftItemResponse(PFCatalogUpdateDraftItemResponse const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCatalogUpdateDraftItemResponse
    ss << "  item " << result->item; Log(ss); // Class: PFCatalogCatalogItem 
    return S_OK;
}

 

}
