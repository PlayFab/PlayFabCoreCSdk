#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPushNotificationsTests.h"
#include "XAsyncHelper.h"

uint32_t g_PushNotificationsTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenPushNotificationsTests::LogDeletePushNotificationTemplateRequest(PFPushNotificationsDeletePushNotificationTemplateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PushNotificationsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPushNotificationsDeletePushNotificationTemplateRequest struct:
    // request->pushNotificationTemplateId: const char*
    if (request->pushNotificationTemplateId) { ss << "  pushNotificationTemplateId " << request->pushNotificationTemplateId; Log(ss); } else { ss << "  pushNotificationTemplateId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenPushNotificationsTests::LogSavePushNotificationTemplateRequest(PFPushNotificationsSavePushNotificationTemplateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PushNotificationsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPushNotificationsSavePushNotificationTemplateRequest struct:
    // request->androidPayload: const char*
    if (request->androidPayload) { ss << "  androidPayload " << request->androidPayload; Log(ss); } else { ss << "  androidPayload = nullptr"; Log(ss); } // Class: const char* 
    if (request->id) { ss << "  id " << request->id; Log(ss); } else { ss << "  id = nullptr"; Log(ss); } // Class: const char* 
    if (request->iOSPayload) { ss << "  iOSPayload " << request->iOSPayload; Log(ss); } else { ss << "  iOSPayload = nullptr"; Log(ss); } // Class: const char*     
    ss << "  localizedPushNotificationTemplatesCount " << request->localizedPushNotificationTemplatesCount; Log(ss);

    // PFPushNotificationsLocalizedPushNotificationPropertiesDictionaryEntry
    for (uint32_t i=0; i<request->localizedPushNotificationTemplatesCount; i++)
    {
            ss << "  request->localizedPushNotificationTemplates[" << i << "]:" << request->localizedPushNotificationTemplates[i].key << "=" << request->localizedPushNotificationTemplates[i].value; Log(ss);
            
    } 
    if (request->name) { ss << "  name " << request->name; Log(ss); } else { ss << "  name = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenPushNotificationsTests::LogSavePushNotificationTemplateResult(PFPushNotificationsSavePushNotificationTemplateResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabPushNotificationsSavePushNotificationTemplateResult    
    if (result->pushNotificationTemplateId) { ss << "  pushNotificationTemplateId " << result->pushNotificationTemplateId; Log(ss); } else { ss << "  pushNotificationTemplateId = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenPushNotificationsTests::LogSendPushNotificationRequest(PFPushNotificationsSendPushNotificationRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PushNotificationsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPushNotificationsSendPushNotificationRequest struct:
    // request->advancedPlatformDelivery: PFPushNotificationsAdvancedPushPlatformMsg const* const*
    // request->advancedPlatformDeliveryCount: uint32_t    
    ss << "  advancedPlatformDeliveryCount " << request->advancedPlatformDeliveryCount; Log(ss);

    // PFPushNotificationsAdvancedPushPlatformMsg
    for (uint32_t i=0; i<request->advancedPlatformDeliveryCount; i++)
    {
            ss << "  request->advancedPlatformDelivery[" << i << "]:" << request->advancedPlatformDelivery[i]; Log(ss); // PFPushNotificationsAdvancedPushPlatformMsg
    }     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->message) { ss << "  message " << request->message; Log(ss); } else { ss << "  message = nullptr"; Log(ss); } // Class: const char* 
    ss << "  package " << request->package; Log(ss); // Class: PFPushNotificationsPushNotificationPackage 
    if (request->recipient) { ss << "  recipient " << request->recipient; Log(ss); } else { ss << "  recipient = nullptr"; Log(ss); } // Class: const char* 
    if (request->subject) { ss << "  subject " << request->subject; Log(ss); } else { ss << "  subject = nullptr"; Log(ss); } // Class: const char*     
    ss << "  targetPlatformsCount " << request->targetPlatformsCount; Log(ss);

    // PFPushNotificationPlatform
    for (uint32_t i=0; i<request->targetPlatformsCount; i++)
    {
            ss << "  request->targetPlatforms[" << i << "]:" << request->targetPlatforms[i]; Log(ss); // PFPushNotificationPlatform
    } 

}

void AutoGenPushNotificationsTests::LogSendPushNotificationFromTemplateRequest(PFPushNotificationsSendPushNotificationFromTemplateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_PushNotificationsTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabPushNotificationsSendPushNotificationFromTemplateRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->pushNotificationTemplateId) { ss << "  pushNotificationTemplateId " << request->pushNotificationTemplateId; Log(ss); } else { ss << "  pushNotificationTemplateId = nullptr"; Log(ss); } // Class: const char* 
    if (request->recipient) { ss << "  recipient " << request->recipient; Log(ss); } else { ss << "  recipient = nullptr"; Log(ss); } // Class: const char* 

}

 

}
