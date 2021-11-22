#pragma once

#include <playfab/cpp/PFPlatformSpecificDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace PlatformSpecific
{

// PlatformSpecific Classes
class AndroidDevicePushNotificationRegistrationRequest : public Wrappers::PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest& input);

};

class MicrosoftStorePayload : public Wrappers::PFPlatformSpecificMicrosoftStorePayloadWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificMicrosoftStorePayloadWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificMicrosoftStorePayload& input);

};

class ConsumeMicrosoftStoreEntitlementsRequest : public Wrappers::PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest& input);

};

class ConsumeMicrosoftStoreEntitlementsResponse : public Wrappers::PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper<Allocator>, public OutputModel<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& model);
    static HRESULT Copy(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& input, PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& output, ModelBuffer& buffer);
};

class PlayStation5Payload : public Wrappers::PFPlatformSpecificPlayStation5PayloadWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificPlayStation5PayloadWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificPlayStation5Payload& input);

};

class ConsumePS5EntitlementsRequest : public Wrappers::PFPlatformSpecificConsumePS5EntitlementsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumePS5EntitlementsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificConsumePS5EntitlementsRequest& input);

};

class ConsumePS5EntitlementsResult : public Wrappers::PFPlatformSpecificConsumePS5EntitlementsResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificConsumePS5EntitlementsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumePS5EntitlementsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificConsumePS5EntitlementsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificConsumePS5EntitlementsResult& model);
    static HRESULT Copy(const PFPlatformSpecificConsumePS5EntitlementsResult& input, PFPlatformSpecificConsumePS5EntitlementsResult& output, ModelBuffer& buffer);
};

class ConsumePSNEntitlementsRequest : public Wrappers::PFPlatformSpecificConsumePSNEntitlementsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumePSNEntitlementsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificConsumePSNEntitlementsRequest& input);

};

class ConsumePSNEntitlementsResult : public Wrappers::PFPlatformSpecificConsumePSNEntitlementsResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificConsumePSNEntitlementsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumePSNEntitlementsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificConsumePSNEntitlementsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificConsumePSNEntitlementsResult& model);
    static HRESULT Copy(const PFPlatformSpecificConsumePSNEntitlementsResult& input, PFPlatformSpecificConsumePSNEntitlementsResult& output, ModelBuffer& buffer);
};

class ConsumeXboxEntitlementsRequest : public Wrappers::PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumeXboxEntitlementsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificConsumeXboxEntitlementsRequest& input);

};

class ConsumeXboxEntitlementsResult : public Wrappers::PFPlatformSpecificConsumeXboxEntitlementsResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificConsumeXboxEntitlementsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificConsumeXboxEntitlementsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificConsumeXboxEntitlementsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificConsumeXboxEntitlementsResult& model);
    static HRESULT Copy(const PFPlatformSpecificConsumeXboxEntitlementsResult& input, PFPlatformSpecificConsumeXboxEntitlementsResult& output, ModelBuffer& buffer);
};

class RefreshPSNAuthTokenRequest : public Wrappers::PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificRefreshPSNAuthTokenRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificRefreshPSNAuthTokenRequest& input);

};

class RegisterForIOSPushNotificationRequest : public Wrappers::PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificRegisterForIOSPushNotificationRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificRegisterForIOSPushNotificationRequest& input);

};

class RestoreIOSPurchasesRequest : public Wrappers::PFPlatformSpecificRestoreIOSPurchasesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificRestoreIOSPurchasesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificRestoreIOSPurchasesRequest& input);

};

class PurchaseReceiptFulfillment : public Wrappers::PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Allocator>, public OutputModel<PFPlatformSpecificPurchaseReceiptFulfillment>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificPurchaseReceiptFulfillmentWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificPurchaseReceiptFulfillment const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificPurchaseReceiptFulfillment& model);
    static HRESULT Copy(const PFPlatformSpecificPurchaseReceiptFulfillment& input, PFPlatformSpecificPurchaseReceiptFulfillment& output, ModelBuffer& buffer);
};

class RestoreIOSPurchasesResult : public Wrappers::PFPlatformSpecificRestoreIOSPurchasesResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificRestoreIOSPurchasesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificRestoreIOSPurchasesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificRestoreIOSPurchasesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificRestoreIOSPurchasesResult& model);
    static HRESULT Copy(const PFPlatformSpecificRestoreIOSPurchasesResult& input, PFPlatformSpecificRestoreIOSPurchasesResult& output, ModelBuffer& buffer);
};

class ValidateAmazonReceiptRequest : public Wrappers::PFPlatformSpecificValidateAmazonReceiptRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateAmazonReceiptRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificValidateAmazonReceiptRequest& input);

};

class ValidateAmazonReceiptResult : public Wrappers::PFPlatformSpecificValidateAmazonReceiptResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificValidateAmazonReceiptResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateAmazonReceiptResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificValidateAmazonReceiptResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificValidateAmazonReceiptResult& model);
    static HRESULT Copy(const PFPlatformSpecificValidateAmazonReceiptResult& input, PFPlatformSpecificValidateAmazonReceiptResult& output, ModelBuffer& buffer);
};

class ValidateGooglePlayPurchaseRequest : public Wrappers::PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateGooglePlayPurchaseRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificValidateGooglePlayPurchaseRequest& input);

};

class ValidateGooglePlayPurchaseResult : public Wrappers::PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificValidateGooglePlayPurchaseResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateGooglePlayPurchaseResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificValidateGooglePlayPurchaseResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificValidateGooglePlayPurchaseResult& model);
    static HRESULT Copy(const PFPlatformSpecificValidateGooglePlayPurchaseResult& input, PFPlatformSpecificValidateGooglePlayPurchaseResult& output, ModelBuffer& buffer);
};

class ValidateIOSReceiptRequest : public Wrappers::PFPlatformSpecificValidateIOSReceiptRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateIOSReceiptRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificValidateIOSReceiptRequest& input);

};

class ValidateIOSReceiptResult : public Wrappers::PFPlatformSpecificValidateIOSReceiptResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificValidateIOSReceiptResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateIOSReceiptResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificValidateIOSReceiptResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificValidateIOSReceiptResult& model);
    static HRESULT Copy(const PFPlatformSpecificValidateIOSReceiptResult& input, PFPlatformSpecificValidateIOSReceiptResult& output, ModelBuffer& buffer);
};

class ValidateWindowsReceiptRequest : public Wrappers::PFPlatformSpecificValidateWindowsReceiptRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateWindowsReceiptRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificValidateWindowsReceiptRequest& input);

};

class ValidateWindowsReceiptResult : public Wrappers::PFPlatformSpecificValidateWindowsReceiptResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificValidateWindowsReceiptResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificValidateWindowsReceiptResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificValidateWindowsReceiptResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificValidateWindowsReceiptResult& model);
    static HRESULT Copy(const PFPlatformSpecificValidateWindowsReceiptResult& input, PFPlatformSpecificValidateWindowsReceiptResult& output, ModelBuffer& buffer);
};

class AwardSteamAchievementItem : public Wrappers::PFPlatformSpecificAwardSteamAchievementItemWrapper<Allocator>, public InputModel, public OutputModel<PFPlatformSpecificAwardSteamAchievementItem>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificAwardSteamAchievementItemWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificAwardSteamAchievementItem& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificAwardSteamAchievementItem const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificAwardSteamAchievementItem& model);
    static HRESULT Copy(const PFPlatformSpecificAwardSteamAchievementItem& input, PFPlatformSpecificAwardSteamAchievementItem& output, ModelBuffer& buffer);
};

class AwardSteamAchievementRequest : public Wrappers::PFPlatformSpecificAwardSteamAchievementRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificAwardSteamAchievementRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPlatformSpecificAwardSteamAchievementRequest& input);

};

class AwardSteamAchievementResult : public Wrappers::PFPlatformSpecificAwardSteamAchievementResultWrapper<Allocator>, public OutputModel<PFPlatformSpecificAwardSteamAchievementResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFPlatformSpecificAwardSteamAchievementResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPlatformSpecificAwardSteamAchievementResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPlatformSpecificAwardSteamAchievementResult& model);
    static HRESULT Copy(const PFPlatformSpecificAwardSteamAchievementResult& input, PFPlatformSpecificAwardSteamAchievementResult& output, ModelBuffer& buffer);
};

} // namespace PlatformSpecific
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
