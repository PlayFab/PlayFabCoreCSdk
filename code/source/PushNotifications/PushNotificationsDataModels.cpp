#include "stdafx.h"
#include "PushNotificationsDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace PushNotifications
{

JsonValue DeletePushNotificationTemplateRequest::ToJson() const
{
    return DeletePushNotificationTemplateRequest::ToJson(this->Model());
}

JsonValue DeletePushNotificationTemplateRequest::ToJson(const PFPushNotificationsDeletePushNotificationTemplateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PushNotificationTemplateId", input.pushNotificationTemplateId);
    return output;
}

JsonValue LocalizedPushNotificationProperties::ToJson() const
{
    return LocalizedPushNotificationProperties::ToJson(this->Model());
}

JsonValue LocalizedPushNotificationProperties::ToJson(const PFPushNotificationsLocalizedPushNotificationProperties& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Message", input.message);
    JsonUtils::ObjectAddMember(output, "Subject", input.subject);
    return output;
}

JsonValue SavePushNotificationTemplateRequest::ToJson() const
{
    return SavePushNotificationTemplateRequest::ToJson(this->Model());
}

JsonValue SavePushNotificationTemplateRequest::ToJson(const PFPushNotificationsSavePushNotificationTemplateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AndroidPayload", input.androidPayload);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "IOSPayload", input.iOSPayload);
    JsonUtils::ObjectAddMemberDictionary<LocalizedPushNotificationProperties>(output, "LocalizedPushNotificationTemplates", input.localizedPushNotificationTemplates, input.localizedPushNotificationTemplatesCount);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    return output;
}

void SavePushNotificationTemplateResult::FromJson(const JsonValue& input)
{
    String pushNotificationTemplateId{};
    JsonUtils::ObjectGetMember(input, "PushNotificationTemplateId", pushNotificationTemplateId);
    this->SetPushNotificationTemplateId(std::move(pushNotificationTemplateId));
}

size_t SavePushNotificationTemplateResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPushNotificationsSavePushNotificationTemplateResult const*> SavePushNotificationTemplateResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SavePushNotificationTemplateResult>(&this->Model());
}

size_t SavePushNotificationTemplateResult::RequiredBufferSize(const PFPushNotificationsSavePushNotificationTemplateResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.pushNotificationTemplateId)
    {
        requiredSize += (std::strlen(model.pushNotificationTemplateId) + 1);
    }
    return requiredSize;
}

HRESULT SavePushNotificationTemplateResult::Copy(const PFPushNotificationsSavePushNotificationTemplateResult& input, PFPushNotificationsSavePushNotificationTemplateResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.pushNotificationTemplateId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pushNotificationTemplateId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdvancedPushPlatformMsg::ToJson() const
{
    return AdvancedPushPlatformMsg::ToJson(this->Model());
}

JsonValue AdvancedPushPlatformMsg::ToJson(const PFPushNotificationsAdvancedPushPlatformMsg& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "GCMDataOnly", input.gCMDataOnly);
    JsonUtils::ObjectAddMember(output, "Json", input.json);
    JsonUtils::ObjectAddMember(output, "Platform", input.platform);
    return output;
}

JsonValue PushNotificationPackage::ToJson() const
{
    return PushNotificationPackage::ToJson(this->Model());
}

JsonValue PushNotificationPackage::ToJson(const PFPushNotificationsPushNotificationPackage& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Badge", input.badge);
    JsonUtils::ObjectAddMember(output, "CustomData", input.customData);
    JsonUtils::ObjectAddMember(output, "Icon", input.icon);
    JsonUtils::ObjectAddMember(output, "Message", input.message);
    JsonUtils::ObjectAddMember(output, "Sound", input.sound);
    JsonUtils::ObjectAddMember(output, "Title", input.title);
    return output;
}

JsonValue SendPushNotificationRequest::ToJson() const
{
    return SendPushNotificationRequest::ToJson(this->Model());
}

JsonValue SendPushNotificationRequest::ToJson(const PFPushNotificationsSendPushNotificationRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<AdvancedPushPlatformMsg>(output, "AdvancedPlatformDelivery", input.advancedPlatformDelivery, input.advancedPlatformDeliveryCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Message", input.message);
    JsonUtils::ObjectAddMember<PushNotificationPackage>(output, "Package", input.package);
    JsonUtils::ObjectAddMember(output, "Recipient", input.recipient);
    JsonUtils::ObjectAddMember(output, "Subject", input.subject);
    JsonUtils::ObjectAddMemberArray(output, "TargetPlatforms", input.targetPlatforms, input.targetPlatformsCount);
    return output;
}

JsonValue SendPushNotificationFromTemplateRequest::ToJson() const
{
    return SendPushNotificationFromTemplateRequest::ToJson(this->Model());
}

JsonValue SendPushNotificationFromTemplateRequest::ToJson(const PFPushNotificationsSendPushNotificationFromTemplateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PushNotificationTemplateId", input.pushNotificationTemplateId);
    JsonUtils::ObjectAddMember(output, "Recipient", input.recipient);
    return output;
}

} // namespace PushNotifications
} // namespace PlayFab
