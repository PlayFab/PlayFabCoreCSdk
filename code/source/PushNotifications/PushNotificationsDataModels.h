#pragma once

#include <playfab/cpp/PFPushNotificationsDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace PushNotifications
{

// PushNotifications Classes
class DeletePushNotificationTemplateRequest : public Wrappers::PFPushNotificationsDeletePushNotificationTemplateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsDeletePushNotificationTemplateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsDeletePushNotificationTemplateRequest& input);

};

class LocalizedPushNotificationProperties : public Wrappers::PFPushNotificationsLocalizedPushNotificationPropertiesWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsLocalizedPushNotificationPropertiesWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsLocalizedPushNotificationProperties& input);

};

class SavePushNotificationTemplateRequest : public Wrappers::PFPushNotificationsSavePushNotificationTemplateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsSavePushNotificationTemplateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsSavePushNotificationTemplateRequest& input);

};

class SavePushNotificationTemplateResult : public Wrappers::PFPushNotificationsSavePushNotificationTemplateResultWrapper<Allocator>, public OutputModel<PFPushNotificationsSavePushNotificationTemplateResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsSavePushNotificationTemplateResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPushNotificationsSavePushNotificationTemplateResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPushNotificationsSavePushNotificationTemplateResult& model);
    static HRESULT Copy(const PFPushNotificationsSavePushNotificationTemplateResult& input, PFPushNotificationsSavePushNotificationTemplateResult& output, ModelBuffer& buffer);
};

class AdvancedPushPlatformMsg : public Wrappers::PFPushNotificationsAdvancedPushPlatformMsgWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsAdvancedPushPlatformMsgWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsAdvancedPushPlatformMsg& input);

};

class PushNotificationPackage : public Wrappers::PFPushNotificationsPushNotificationPackageWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsPushNotificationPackageWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsPushNotificationPackage& input);

};

class SendPushNotificationRequest : public Wrappers::PFPushNotificationsSendPushNotificationRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsSendPushNotificationRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsSendPushNotificationRequest& input);

};

class SendPushNotificationFromTemplateRequest : public Wrappers::PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPushNotificationsSendPushNotificationFromTemplateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPushNotificationsSendPushNotificationFromTemplateRequest& input);

};

} // namespace PushNotifications
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
