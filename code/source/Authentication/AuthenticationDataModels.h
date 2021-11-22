#pragma once

#include <playfab/cpp/PFAuthenticationDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Authentication
{

// Authentication Classes
class OpenIdIssuerInformation : public Wrappers::PFAuthenticationOpenIdIssuerInformationWrapper<Allocator>, public InputModel, public OutputModel<PFAuthenticationOpenIdIssuerInformation>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationOpenIdIssuerInformationWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationOpenIdIssuerInformation& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationOpenIdIssuerInformation const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationOpenIdIssuerInformation& model);
    static HRESULT Copy(const PFAuthenticationOpenIdIssuerInformation& input, PFAuthenticationOpenIdIssuerInformation& output, ModelBuffer& buffer);
};

class CreateOpenIdConnectionRequest : public Wrappers::PFAuthenticationCreateOpenIdConnectionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationCreateOpenIdConnectionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationCreateOpenIdConnectionRequest& input);

};

class CreatePlayerSharedSecretRequest : public Wrappers::PFAuthenticationCreatePlayerSharedSecretRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationCreatePlayerSharedSecretRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationCreatePlayerSharedSecretRequest& input);

};

class CreatePlayerSharedSecretResult : public Wrappers::PFAuthenticationCreatePlayerSharedSecretResultWrapper<Allocator>, public OutputModel<PFAuthenticationCreatePlayerSharedSecretResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationCreatePlayerSharedSecretResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationCreatePlayerSharedSecretResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationCreatePlayerSharedSecretResult& model);
    static HRESULT Copy(const PFAuthenticationCreatePlayerSharedSecretResult& input, PFAuthenticationCreatePlayerSharedSecretResult& output, ModelBuffer& buffer);
};

class DeleteOpenIdConnectionRequest : public Wrappers::PFAuthenticationDeleteOpenIdConnectionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationDeleteOpenIdConnectionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationDeleteOpenIdConnectionRequest& input);

};

class DeletePlayerSharedSecretRequest : public Wrappers::PFAuthenticationDeletePlayerSharedSecretRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationDeletePlayerSharedSecretRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationDeletePlayerSharedSecretRequest& input);

};

class SharedSecret : public Wrappers::PFAuthenticationSharedSecretWrapper<Allocator>, public OutputModel<PFAuthenticationSharedSecret>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationSharedSecretWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationSharedSecret const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationSharedSecret& model);
    static HRESULT Copy(const PFAuthenticationSharedSecret& input, PFAuthenticationSharedSecret& output, ModelBuffer& buffer);
};

class GetPlayerSharedSecretsResult : public Wrappers::PFAuthenticationGetPlayerSharedSecretsResultWrapper<Allocator>, public OutputModel<PFAuthenticationGetPlayerSharedSecretsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetPlayerSharedSecretsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationGetPlayerSharedSecretsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationGetPlayerSharedSecretsResult& model);
    static HRESULT Copy(const PFAuthenticationGetPlayerSharedSecretsResult& input, PFAuthenticationGetPlayerSharedSecretsResult& output, ModelBuffer& buffer);
};

class GetPolicyRequest : public Wrappers::PFAuthenticationGetPolicyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetPolicyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationGetPolicyRequest& input);

};

class ApiCondition : public Wrappers::PFAuthenticationApiConditionWrapper<Allocator>, public InputModel, public OutputModel<PFAuthenticationApiCondition>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationApiConditionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationApiCondition& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationApiCondition const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationApiCondition& model);
    static HRESULT Copy(const PFAuthenticationApiCondition& input, PFAuthenticationApiCondition& output, ModelBuffer& buffer);
};

class PermissionStatement : public Wrappers::PFAuthenticationPermissionStatementWrapper<Allocator>, public InputModel, public OutputModel<PFAuthenticationPermissionStatement>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationPermissionStatementWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationPermissionStatement& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationPermissionStatement const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationPermissionStatement& model);
    static HRESULT Copy(const PFAuthenticationPermissionStatement& input, PFAuthenticationPermissionStatement& output, ModelBuffer& buffer);
};

class GetPolicyResponse : public Wrappers::PFAuthenticationGetPolicyResponseWrapper<Allocator>, public OutputModel<PFAuthenticationGetPolicyResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetPolicyResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationGetPolicyResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationGetPolicyResponse& model);
    static HRESULT Copy(const PFAuthenticationGetPolicyResponse& input, PFAuthenticationGetPolicyResponse& output, ModelBuffer& buffer);
};

class OpenIdConnection : public Wrappers::PFAuthenticationOpenIdConnectionWrapper<Allocator>, public OutputModel<PFAuthenticationOpenIdConnection>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationOpenIdConnectionWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationOpenIdConnection const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationOpenIdConnection& model);
    static HRESULT Copy(const PFAuthenticationOpenIdConnection& input, PFAuthenticationOpenIdConnection& output, ModelBuffer& buffer);
};

class ListOpenIdConnectionResponse : public Wrappers::PFAuthenticationListOpenIdConnectionResponseWrapper<Allocator>, public OutputModel<PFAuthenticationListOpenIdConnectionResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationListOpenIdConnectionResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationListOpenIdConnectionResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationListOpenIdConnectionResponse& model);
    static HRESULT Copy(const PFAuthenticationListOpenIdConnectionResponse& input, PFAuthenticationListOpenIdConnectionResponse& output, ModelBuffer& buffer);
};

class AdminSetPlayerSecretRequest : public Wrappers::PFAuthenticationAdminSetPlayerSecretRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationAdminSetPlayerSecretRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationAdminSetPlayerSecretRequest& input);

};

class UpdateOpenIdConnectionRequest : public Wrappers::PFAuthenticationUpdateOpenIdConnectionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationUpdateOpenIdConnectionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationUpdateOpenIdConnectionRequest& input);

};

class UpdatePlayerSharedSecretRequest : public Wrappers::PFAuthenticationUpdatePlayerSharedSecretRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationUpdatePlayerSharedSecretRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationUpdatePlayerSharedSecretRequest& input);

};

class UpdatePolicyRequest : public Wrappers::PFAuthenticationUpdatePolicyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationUpdatePolicyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationUpdatePolicyRequest& input);

};

class UpdatePolicyResponse : public Wrappers::PFAuthenticationUpdatePolicyResponseWrapper<Allocator>, public OutputModel<PFAuthenticationUpdatePolicyResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationUpdatePolicyResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationUpdatePolicyResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationUpdatePolicyResponse& model);
    static HRESULT Copy(const PFAuthenticationUpdatePolicyResponse& input, PFAuthenticationUpdatePolicyResponse& output, ModelBuffer& buffer);
};

class GetPhotonAuthenticationTokenRequest : public Wrappers::PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationGetPhotonAuthenticationTokenRequest& input);

};

class GetPhotonAuthenticationTokenResult : public Wrappers::PFAuthenticationGetPhotonAuthenticationTokenResultWrapper<Allocator>, public OutputModel<PFAuthenticationGetPhotonAuthenticationTokenResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetPhotonAuthenticationTokenResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationGetPhotonAuthenticationTokenResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationGetPhotonAuthenticationTokenResult& model);
    static HRESULT Copy(const PFAuthenticationGetPhotonAuthenticationTokenResult& input, PFAuthenticationGetPhotonAuthenticationTokenResult& output, ModelBuffer& buffer);
};

class GetTitlePublicKeyRequest : public Wrappers::PFAuthenticationGetTitlePublicKeyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetTitlePublicKeyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationGetTitlePublicKeyRequest& input);

};

class GetTitlePublicKeyResult : public Wrappers::PFAuthenticationGetTitlePublicKeyResultWrapper<Allocator>, public OutputModel<PFAuthenticationGetTitlePublicKeyResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetTitlePublicKeyResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationGetTitlePublicKeyResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationGetTitlePublicKeyResult& model);
    static HRESULT Copy(const PFAuthenticationGetTitlePublicKeyResult& input, PFAuthenticationGetTitlePublicKeyResult& output, ModelBuffer& buffer);
};

class LoginWithAndroidDeviceIDRequest : public Wrappers::PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithAndroidDeviceIDRequest& input);

};

class EntityTokenResponse : public Wrappers::PFAuthenticationEntityTokenResponseWrapper<Allocator>, public OutputModel<PFAuthenticationEntityTokenResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationEntityTokenResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationEntityTokenResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationEntityTokenResponse& model);
    static HRESULT Copy(const PFAuthenticationEntityTokenResponse& input, PFAuthenticationEntityTokenResponse& output, ModelBuffer& buffer);
};

class UserSettings : public Wrappers::PFAuthenticationUserSettingsWrapper<Allocator>, public OutputModel<PFAuthenticationUserSettings>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationUserSettingsWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationUserSettings const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationUserSettings& model);
    static HRESULT Copy(const PFAuthenticationUserSettings& input, PFAuthenticationUserSettings& output, ModelBuffer& buffer);
};

class LoginResult
{
public:
    void FromJson(const JsonValue& input);

    _Maybenull_ StdExtra::optional<EntityTokenResponse> entityToken;
    _Maybenull_ StdExtra::optional<GetPlayerCombinedInfoResultPayload> infoResultPayload;
    _Maybenull_ StdExtra::optional<time_t> lastLoginTime;
    bool newlyCreated;
    _Maybenull_ _Null_terminated_ String playFabId;
    _Maybenull_ _Null_terminated_ String sessionTicket;
    _Maybenull_ StdExtra::optional<UserSettings> settingsForUser;
    _Maybenull_ StdExtra::optional<TreatmentAssignment> treatmentAssignment;
};

class LoginWithAppleRequest : public Wrappers::PFAuthenticationLoginWithAppleRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithAppleRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithAppleRequest& input);

};

class LoginWithCustomIDRequest : public Wrappers::PFAuthenticationLoginWithCustomIDRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithCustomIDRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithCustomIDRequest& input);

};

class LoginWithEmailAddressRequest : public Wrappers::PFAuthenticationLoginWithEmailAddressRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithEmailAddressRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithEmailAddressRequest& input);

};

class LoginWithFacebookRequest : public Wrappers::PFAuthenticationLoginWithFacebookRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithFacebookRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithFacebookRequest& input);

};

class LoginWithFacebookInstantGamesIdRequest : public Wrappers::PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithFacebookInstantGamesIdRequest& input);

};

class LoginWithGameCenterRequest : public Wrappers::PFAuthenticationLoginWithGameCenterRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithGameCenterRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithGameCenterRequest& input);

};

class LoginWithGoogleAccountRequest : public Wrappers::PFAuthenticationLoginWithGoogleAccountRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithGoogleAccountRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithGoogleAccountRequest& input);

};

class LoginWithIOSDeviceIDRequest : public Wrappers::PFAuthenticationLoginWithIOSDeviceIDRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithIOSDeviceIDRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithIOSDeviceIDRequest& input);

};

class LoginWithKongregateRequest : public Wrappers::PFAuthenticationLoginWithKongregateRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithKongregateRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithKongregateRequest& input);

};

class LoginWithNintendoServiceAccountRequest : public Wrappers::PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithNintendoServiceAccountRequest& input);

};

class LoginWithNintendoSwitchDeviceIdRequest : public Wrappers::PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest& input);

};

class LoginWithOpenIdConnectRequest : public Wrappers::PFAuthenticationLoginWithOpenIdConnectRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithOpenIdConnectRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithOpenIdConnectRequest& input);

};

class LoginWithPlayFabRequest : public Wrappers::PFAuthenticationLoginWithPlayFabRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithPlayFabRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithPlayFabRequest& input);

};

class LoginWithPSNRequest : public Wrappers::PFAuthenticationLoginWithPSNRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithPSNRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithPSNRequest& input);

};

class LoginWithSteamRequest : public Wrappers::PFAuthenticationLoginWithSteamRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithSteamRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithSteamRequest& input);

};

class LoginWithTwitchRequest : public Wrappers::PFAuthenticationLoginWithTwitchRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithTwitchRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithTwitchRequest& input);

};

class ClientLoginWithXboxRequest : public Wrappers::PFAuthenticationClientLoginWithXboxRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationClientLoginWithXboxRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationClientLoginWithXboxRequest& input);

};

class RegisterPlayFabUserRequest : public Wrappers::PFAuthenticationRegisterPlayFabUserRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationRegisterPlayFabUserRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationRegisterPlayFabUserRequest& input);

};

class RegisterPlayFabUserResult
{
public:
    void FromJson(const JsonValue& input);

    _Maybenull_ StdExtra::optional<EntityTokenResponse> entityToken;
    _Maybenull_ _Null_terminated_ String playFabId;
    _Maybenull_ _Null_terminated_ String sessionTicket;
    _Maybenull_ StdExtra::optional<UserSettings> settingsForUser;
    _Maybenull_ _Null_terminated_ String username;
};

class ClientSetPlayerSecretRequest : public Wrappers::PFAuthenticationClientSetPlayerSecretRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationClientSetPlayerSecretRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationClientSetPlayerSecretRequest& input);

};

class AuthenticateSessionTicketRequest : public Wrappers::PFAuthenticationAuthenticateSessionTicketRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationAuthenticateSessionTicketRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationAuthenticateSessionTicketRequest& input);

};

class AuthenticateSessionTicketResult : public Wrappers::PFAuthenticationAuthenticateSessionTicketResultWrapper<Allocator>, public OutputModel<PFAuthenticationAuthenticateSessionTicketResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationAuthenticateSessionTicketResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationAuthenticateSessionTicketResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationAuthenticateSessionTicketResult& model);
    static HRESULT Copy(const PFAuthenticationAuthenticateSessionTicketResult& input, PFAuthenticationAuthenticateSessionTicketResult& output, ModelBuffer& buffer);
};

class LoginWithServerCustomIdRequest : public Wrappers::PFAuthenticationLoginWithServerCustomIdRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithServerCustomIdRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithServerCustomIdRequest& input);

};

class ServerLoginResult
{
public:
    void FromJson(const JsonValue& input);

    _Maybenull_ StdExtra::optional<EntityTokenResponse> entityToken;
    _Maybenull_ StdExtra::optional<GetPlayerCombinedInfoResultPayload> infoResultPayload;
    _Maybenull_ StdExtra::optional<time_t> lastLoginTime;
    bool newlyCreated;
    _Maybenull_ _Null_terminated_ String playFabId;
    _Maybenull_ _Null_terminated_ String sessionTicket;
    _Maybenull_ StdExtra::optional<UserSettings> settingsForUser;
    _Maybenull_ StdExtra::optional<TreatmentAssignment> treatmentAssignment;
};

class LoginWithSteamIdRequest : public Wrappers::PFAuthenticationLoginWithSteamIdRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithSteamIdRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithSteamIdRequest& input);

};

class ServerLoginWithXboxRequest : public Wrappers::PFAuthenticationServerLoginWithXboxRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationServerLoginWithXboxRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationServerLoginWithXboxRequest& input);

};

class LoginWithXboxIdRequest : public Wrappers::PFAuthenticationLoginWithXboxIdRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLoginWithXboxIdRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationLoginWithXboxIdRequest& input);

};

class ServerSetPlayerSecretRequest : public Wrappers::PFAuthenticationServerSetPlayerSecretRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationServerSetPlayerSecretRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationServerSetPlayerSecretRequest& input);

};

class GetEntityTokenRequest : public Wrappers::PFAuthenticationGetEntityTokenRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetEntityTokenRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationGetEntityTokenRequest& input);

};

class GetEntityTokenResponse
{
public:
    void FromJson(const JsonValue& input);

    _Maybenull_ StdExtra::optional<EntityKey> entity;
    _Maybenull_ _Null_terminated_ String entityToken;
    _Maybenull_ StdExtra::optional<time_t> tokenExpiration;
};

class ValidateEntityTokenRequest : public Wrappers::PFAuthenticationValidateEntityTokenRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationValidateEntityTokenRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationValidateEntityTokenRequest& input);

};

class ValidateEntityTokenResponse : public Wrappers::PFAuthenticationValidateEntityTokenResponseWrapper<Allocator>, public OutputModel<PFAuthenticationValidateEntityTokenResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationValidateEntityTokenResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationValidateEntityTokenResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationValidateEntityTokenResponse& model);
    static HRESULT Copy(const PFAuthenticationValidateEntityTokenResponse& input, PFAuthenticationValidateEntityTokenResponse& output, ModelBuffer& buffer);
};

} // namespace Authentication
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
