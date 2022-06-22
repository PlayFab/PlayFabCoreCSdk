#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCloudScriptTests.h"
#include "XAsyncHelper.h"

uint32_t g_CloudScriptTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenCloudScriptTests::LogExecuteFunctionRequest(PFCloudScriptExecuteFunctionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptExecuteFunctionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    if (request->functionName) { ss << "  functionName " << request->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char* 
    if (request->functionParameter.stringValue) { ss << "  functionParameter " << request->functionParameter.stringValue; Log(ss); } else { ss << "  functionParameter = nullptr"; Log(ss); } // Class: PFJsonObject 
    ss << "  generatePlayStreamEvent " << request->generatePlayStreamEvent; Log(ss); // Class: bool 

}

HRESULT AutoGenCloudScriptTests::LogExecuteFunctionResult(PFCloudScriptExecuteFunctionResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabCloudScriptExecuteFunctionResult    
    ss << "  error " << result->error; Log(ss); // Class: PFCloudScriptFunctionExecutionError     
    ss << "  executionTimeMilliseconds " << result->executionTimeMilliseconds; Log(ss); // Class: int32_t     
    if (result->functionName) { ss << "  functionName " << result->functionName; Log(ss); } else { ss << "  functionName = nullptr"; Log(ss); } // Class: const char*     
    if (result->functionResult.stringValue) { ss << "  functionResult " << result->functionResult.stringValue; Log(ss); } else { ss << "  functionResult = nullptr"; Log(ss); } // Class: PFJsonObject     
    ss << "  functionResultTooLarge " << result->functionResultTooLarge; Log(ss); // Class: bool 
    return S_OK;
}

void AutoGenCloudScriptTests::LogPostFunctionResultForEntityTriggeredActionRequest(PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptPostFunctionResultForEntityTriggeredActionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  functionResult " << request->functionResult; Log(ss); // Class: PFCloudScriptExecuteFunctionResult 

}

void AutoGenCloudScriptTests::LogPostFunctionResultForFunctionExecutionRequest(PFCloudScriptPostFunctionResultForFunctionExecutionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_CloudScriptTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabCloudScriptPostFunctionResultForFunctionExecutionRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 
    ss << "  functionResult " << request->functionResult; Log(ss); // Class: PFCloudScriptExecuteFunctionResult 

}

 

}
