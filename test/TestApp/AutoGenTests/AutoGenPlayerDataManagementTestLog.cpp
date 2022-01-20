#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayerDataManagementTests.h"
#include "XAsyncHelper.h"

uint32_t g_PlayerDataManagementTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenPlayerDataManagementTests::LogGetDataReportRequest(PFPlayerDataManagementGetDataReportRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetDataReportRequest struct:
    // request->day: int32_t
    ss << "  day " << request->day; Log(ss); // Class: int32_t 
    ss << "  month " << request->month; Log(ss); // Class: int32_t 
    if (request->reportName) { ss << "  reportName " << request->reportName; Log(ss); } else { ss << "  reportName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  year " << request->year; Log(ss); // Class: int32_t 

}

HRESULT AutoGenPlayerDataManagementTests::LogGetDataReportResult(PFPlayerDataManagementGetDataReportResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementGetDataReportResult    
    if (result->downloadUrl) { ss << "  downloadUrl " << result->downloadUrl; Log(ss); } else { ss << "  downloadUrl = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogGetUserDataRequest(PFPlayerDataManagementGetUserDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementGetUserDataRequest struct:
    // request->ifChangedFromDataVersion: uint32_t const*
    ss << "  ifChangedFromDataVersion " << request->ifChangedFromDataVersion; Log(ss); // Class: uint32_t     
    ss << "  keysCount " << request->keysCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysCount; i++)
    {
            ss << "  request->keys[" << i << "]:" << request->keys[i]; Log(ss); // const char*
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogAdminGetUserDataResult(PFPlayerDataManagementAdminGetUserDataResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementAdminGetUserDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFUserDataRecordDictionaryEntry
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }     
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogAdminUpdateUserDataRequest(PFPlayerDataManagementAdminUpdateUserDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysToRemoveCount; i++)
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    ss << "  permission " << request->permission; Log(ss); // Class: PFUserDataPermission 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogUpdateUserDataResult(PFPlayerDataManagementUpdateUserDataResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementUpdateUserDataResult    
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogUpdateUserInternalDataRequest(PFPlayerDataManagementUpdateUserInternalDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserInternalDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysToRemoveCount; i++)
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPlayerDataManagementTests::LogClientGetUserDataResult(PFPlayerDataManagementClientGetUserDataResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementClientGetUserDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFUserDataRecordDictionaryEntry
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }     
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogClientUpdateUserDataRequest(PFPlayerDataManagementClientUpdateUserDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: PassingWithData"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysToRemoveCount; i++)
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    ss << "  permission " << request->permission; Log(ss); // Class: PFUserDataPermission 

}

HRESULT AutoGenPlayerDataManagementTests::LogServerGetUserDataResult(PFPlayerDataManagementServerGetUserDataResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPlayerDataManagementServerGetUserDataResult        
    ss << "  dataCount " << result->dataCount; Log(ss);

    // PFUserDataRecordDictionaryEntry
    for (uint32_t i=0; i<result->dataCount; i++)
    {
            ss << "  result->data[" << i << "]:" << result->data[i].key << "=" << result->data[i].value; Log(ss);
            
    }     
    ss << "  dataVersion " << result->dataVersion; Log(ss); // Class: uint32_t     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPlayerDataManagementTests::LogServerUpdateUserDataRequest(PFPlayerDataManagementServerUpdateUserDataRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PlayerDataManagementTestIndex++ << ": " << testName << ".  Last Known Status: Failing"; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPlayerDataManagementUpdateUserDataRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
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
    ss << "  keysToRemoveCount " << request->keysToRemoveCount; Log(ss);

    // const char*
    for (uint32_t i=0; i<request->keysToRemoveCount; i++)
    {
            ss << "  request->keysToRemove[" << i << "]:" << request->keysToRemove[i]; Log(ss); // const char*
    } 
    ss << "  permission " << request->permission; Log(ss); // Class: PFUserDataPermission 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

 

}
