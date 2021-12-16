#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenTitleDataManagementTests.h"
#include "XAsyncHelper.h"

uint32_t g_TitleDataManagementTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenTitleDataManagementTests::LogAddLocalizedNewsRequest(PFTitleDataManagementAddLocalizedNewsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementAddLocalizedNewsRequest struct:
    // request->body: const char*
    if( request->body ) { ss << "  body " << request->body; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->language ) { ss << "  language " << request->language; Log(ss); } else { ss << "  language = nullptr"; Log(ss); } // Class: const char* 
    if( request->newsId ) { ss << "  newsId " << request->newsId; Log(ss); } else { ss << "  newsId = nullptr"; Log(ss); } // Class: const char* 
    if( request->title ) { ss << "  title " << request->title; Log(ss); } else { ss << "  title = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenTitleDataManagementTests::LogAddNewsRequest(PFTitleDataManagementAddNewsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementAddNewsRequest struct:
    // request->body: const char*
    if( request->body ) { ss << "  body " << request->body; Log(ss); } else { ss << "  body = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  timestamp " << request->timestamp; Log(ss); // Class: time_t 
    if( request->title ) { ss << "  title " << request->title; Log(ss); } else { ss << "  title = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementAddNewsResult(PFTitleDataManagementAddNewsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementAddNewsResult    
    if( result->newsId ) { ss << "  newsId " << result->newsId; Log(ss); } else { ss << "  newsId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogAddVirtualCurrencyTypesRequest(PFTitleDataManagementAddVirtualCurrencyTypesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementAddVirtualCurrencyTypesRequest struct:
    // request->virtualCurrencies: PFTitleDataManagementVirtualCurrencyData const* const*
    // request->virtualCurrenciesCount: uint32_t    
    ss << "  virtualCurrenciesCount " << request->virtualCurrenciesCount; Log(ss);

    // PFTitleDataManagementVirtualCurrencyData
    for( uint32_t i=0; i<request->virtualCurrenciesCount; i++ )
    {
            ss << "  request->virtualCurrencies[" << i << "]:" << request->virtualCurrencies[i]; Log(ss); // PFTitleDataManagementVirtualCurrencyData
    } 

}

void AutoGenTitleDataManagementTests::LogDeleteStoreRequest(PFTitleDataManagementDeleteStoreRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementDeleteStoreRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->storeId ) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenTitleDataManagementTests::LogDeleteTitleDataOverrideRequest(PFTitleDataManagementDeleteTitleDataOverrideRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementDeleteTitleDataOverrideRequest struct:
    // request->overrideLabel: const char*
    if( request->overrideLabel ) { ss << "  overrideLabel " << request->overrideLabel; Log(ss); } else { ss << "  overrideLabel = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenTitleDataManagementTests::LogGetCatalogItemsRequest(PFTitleDataManagementGetCatalogItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetCatalogItemsRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementGetCatalogItemsResult(PFTitleDataManagementGetCatalogItemsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetCatalogItemsResult        
    ss << "  catalogCount " << result->catalogCount; Log(ss);

    // PFTitleDataManagementCatalogItem
    for( uint32_t i=0; i<result->catalogCount; i++ )
    {
            ss << "  result->catalog[" << i << "]:" << result->catalog[i]; Log(ss); // PFTitleDataManagementCatalogItem
    } 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogGetPublisherDataRequest(PFTitleDataManagementGetPublisherDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetPublisherDataRequest struct:
    // request->keys: const char* const*
    // request->keysCount: uint32_t    
    ss << "  keysCount " << request->keysCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->keysCount; i++ )
    {
            ss << "  request->keys[" << i << "]:" << request->keys[i]; Log(ss); // const char*
    } 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementGetPublisherDataResult(PFTitleDataManagementGetPublisherDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetPublisherDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<result->dataCount; i++ )
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogGetRandomResultTablesRequest(PFTitleDataManagementGetRandomResultTablesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetRandomResultTablesRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTitleDataManagementTests::LogPFGetRandomResultTablesResult(PFGetRandomResultTablesResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetRandomResultTablesResult        
    ss << "  tablesCount " << result->tablesCount; Log(ss);

    // PFRandomResultTableListingDictionaryEntry
    for( uint32_t i=0; i<result->tablesCount; i++ )
    {
            ss << "  result->tables[" << i << "]:" << result->tables[i].key << "=" << result->tables[i].value; Log(ss);
            
    } 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogGetStoreItemsRequest(PFTitleDataManagementGetStoreItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetStoreItemsRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char* 
    if( request->storeId ) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementGetStoreItemsResult(PFTitleDataManagementGetStoreItemsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetStoreItemsResult    
    if( result->catalogVersion ) { ss << "  catalogVersion " << result->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  marketingData " << result->marketingData; Log(ss); // Class: PFTitleDataManagementStoreMarketingModel     
    ss << "  source " << result->source; Log(ss); // Class: PFTitleDataManagementSourceType         
    ss << "  storeCount " << result->storeCount; Log(ss);

    // PFTitleDataManagementStoreItem
    for( uint32_t i=0; i<result->storeCount; i++ )
    {
            ss << "  result->store[" << i << "]:" << result->store[i]; Log(ss); // PFTitleDataManagementStoreItem
    }     
    if( result->storeId ) { ss << "  storeId " << result->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogGetTitleDataRequest(PFTitleDataManagementGetTitleDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetTitleDataRequest struct:
    // request->keys: const char* const*
    // request->keysCount: uint32_t    
    ss << "  keysCount " << request->keysCount; Log(ss);

    // const char*
    for( uint32_t i=0; i<request->keysCount; i++ )
    {
            ss << "  request->keys[" << i << "]:" << request->keys[i]; Log(ss); // const char*
    } 
    if( request->overrideLabel ) { ss << "  overrideLabel " << request->overrideLabel; Log(ss); } else { ss << "  overrideLabel = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementGetTitleDataResult(PFTitleDataManagementGetTitleDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetTitleDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<result->dataCount; i++ )
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    } 
    return S_OK;
}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementListVirtualCurrencyTypesResult(PFTitleDataManagementListVirtualCurrencyTypesResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementListVirtualCurrencyTypesResult        
    ss << "  virtualCurrenciesCount " << result->virtualCurrenciesCount; Log(ss);

    // PFTitleDataManagementVirtualCurrencyData
    for( uint32_t i=0; i<result->virtualCurrenciesCount; i++ )
    {
            ss << "  result->virtualCurrencies[" << i << "]:" << result->virtualCurrencies[i]; Log(ss); // PFTitleDataManagementVirtualCurrencyData
    } 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogRemoveVirtualCurrencyTypesRequest(PFTitleDataManagementRemoveVirtualCurrencyTypesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementRemoveVirtualCurrencyTypesRequest struct:
    // request->virtualCurrencies: PFTitleDataManagementVirtualCurrencyData const* const*
    // request->virtualCurrenciesCount: uint32_t    
    ss << "  virtualCurrenciesCount " << request->virtualCurrenciesCount; Log(ss);

    // PFTitleDataManagementVirtualCurrencyData
    for( uint32_t i=0; i<request->virtualCurrenciesCount; i++ )
    {
            ss << "  request->virtualCurrencies[" << i << "]:" << request->virtualCurrencies[i]; Log(ss); // PFTitleDataManagementVirtualCurrencyData
    } 

}

void AutoGenTitleDataManagementTests::LogUpdateCatalogItemsRequest(PFTitleDataManagementUpdateCatalogItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementUpdateCatalogItemsRequest struct:
    // request->catalog: PFTitleDataManagementCatalogItem const* const*
    // request->catalogCount: uint32_t    
    ss << "  catalogCount " << request->catalogCount; Log(ss);

    // PFTitleDataManagementCatalogItem
    for( uint32_t i=0; i<request->catalogCount; i++ )
    {
            ss << "  request->catalog[" << i << "]:" << request->catalog[i]; Log(ss); // PFTitleDataManagementCatalogItem
    } 
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  setAsDefaultCatalog " << request->setAsDefaultCatalog; Log(ss); // Class: bool 

}

void AutoGenTitleDataManagementTests::LogSetPublisherDataRequest(PFTitleDataManagementSetPublisherDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementSetPublisherDataRequest struct:
    // request->key: const char*
    if( request->key ) { ss << "  key " << request->key; Log(ss); } else { ss << "  key = nullptr"; Log(ss); } // Class: const char* 
    if( request->value ) { ss << "  value " << request->value; Log(ss); } else { ss << "  value = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenTitleDataManagementTests::LogUpdateStoreItemsRequest(PFTitleDataManagementUpdateStoreItemsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementUpdateStoreItemsRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  marketingData " << request->marketingData; Log(ss); // Class: PFTitleDataManagementStoreMarketingModel     
    ss << "  storeCount " << request->storeCount; Log(ss);

    // PFTitleDataManagementStoreItem
    for( uint32_t i=0; i<request->storeCount; i++ )
    {
            ss << "  request->store[" << i << "]:" << request->store[i]; Log(ss); // PFTitleDataManagementStoreItem
    } 
    if( request->storeId ) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenTitleDataManagementTests::LogSetTitleDataRequest(PFTitleDataManagementSetTitleDataRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementSetTitleDataRequest struct:
    // request->azureResourceId: const char*
    if( request->azureResourceId ) { ss << "  azureResourceId " << request->azureResourceId; Log(ss); } else { ss << "  azureResourceId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->key ) { ss << "  key " << request->key; Log(ss); } else { ss << "  key = nullptr"; Log(ss); } // Class: const char* 
    ss << "  systemData " << request->systemData; Log(ss); // Class: PFAzureResourceSystemData 
    if( request->titleId ) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 
    if( request->value ) { ss << "  value " << request->value; Log(ss); } else { ss << "  value = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementSetTitleDataResult(PFTitleDataManagementSetTitleDataResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementSetTitleDataResult    
    if( result->azureResourceId ) { ss << "  azureResourceId " << result->azureResourceId; Log(ss); } else { ss << "  azureResourceId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogSetTitleDataAndOverridesRequest(PFTitleDataManagementSetTitleDataAndOverridesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementSetTitleDataAndOverridesRequest struct:
    // request->keyValues: PFTitleDataManagementTitleDataKeyValue const* const*
    // request->keyValuesCount: uint32_t    
    ss << "  keyValuesCount " << request->keyValuesCount; Log(ss);

    // PFTitleDataManagementTitleDataKeyValue
    for( uint32_t i=0; i<request->keyValuesCount; i++ )
    {
            ss << "  request->keyValues[" << i << "]:" << request->keyValues[i]; Log(ss); // PFTitleDataManagementTitleDataKeyValue
    } 
    if( request->overrideLabel ) { ss << "  overrideLabel " << request->overrideLabel; Log(ss); } else { ss << "  overrideLabel = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenTitleDataManagementTests::LogSetupPushNotificationRequest(PFTitleDataManagementSetupPushNotificationRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementSetupPushNotificationRequest struct:
    // request->credential: const char*
    if( request->credential ) { ss << "  credential " << request->credential; Log(ss); } else { ss << "  credential = nullptr"; Log(ss); } // Class: const char* 
    if( request->key ) { ss << "  key " << request->key; Log(ss); } else { ss << "  key = nullptr"; Log(ss); } // Class: const char* 
    if( request->name ) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 
    ss << "  overwriteOldARN " << request->overwriteOldARN; Log(ss); // Class: bool 
    ss << "  platform " << request->platform; Log(ss); // Class: PFTitleDataManagementPushSetupPlatform 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementSetupPushNotificationResult(PFTitleDataManagementSetupPushNotificationResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementSetupPushNotificationResult    
    if( result->aRN ) { ss << "  aRN " << result->aRN; Log(ss); } else { ss << "  aRN = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogUpdateRandomResultTablesRequest(PFTitleDataManagementUpdateRandomResultTablesRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementUpdateRandomResultTablesRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    }     
    ss << "  tablesCount " << request->tablesCount; Log(ss);

    // PFTitleDataManagementRandomResultTable
    for( uint32_t i=0; i<request->tablesCount; i++ )
    {
            ss << "  request->tables[" << i << "]:" << request->tables[i]; Log(ss); // PFTitleDataManagementRandomResultTable
    } 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementGetTimeResult(PFTitleDataManagementGetTimeResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetTimeResult    
    ss << "  time " << result->time; Log(ss); // Class: time_t 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogGetTitleNewsRequest(PFTitleDataManagementGetTitleNewsRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetTitleNewsRequest struct:
    // request->count: int32_t const*
    ss << "  count " << request->count; Log(ss); // Class: int32_t 

}

HRESULT AutoGenTitleDataManagementTests::LogPFTitleDataManagementGetTitleNewsResult(PFTitleDataManagementGetTitleNewsResult const* result)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabTitleDataManagementGetTitleNewsResult        
    ss << "  newsCount " << result->newsCount; Log(ss);

    // PFTitleDataManagementTitleNewsItem
    for( uint32_t i=0; i<result->newsCount; i++ )
    {
            ss << "  result->news[" << i << "]:" << result->news[i]; Log(ss); // PFTitleDataManagementTitleNewsItem
    } 
    return S_OK;
}

void AutoGenTitleDataManagementTests::LogGetStoreItemsServerRequest(PFTitleDataManagementGetStoreItemsServerRequest const* request, const char* testName)
{
    if( !TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_TitleDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabTitleDataManagementGetStoreItemsServerRequest struct:
    // request->catalogVersion: const char*
    if( request->catalogVersion ) { ss << "  catalogVersion " << request->catalogVersion; Log(ss); } else { ss << "  catalogVersion = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for( uint32_t i=0; i<request->customTagsCount; i++ )
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if( request->playFabId ) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    if( request->storeId ) { ss << "  storeId " << request->storeId; Log(ss); } else { ss << "  storeId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
