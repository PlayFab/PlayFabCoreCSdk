#include "stdafx.h"
#include "AuthenticationDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Authentication
{

JsonValue OpenIdIssuerInformation::ToJson() const
{
    return OpenIdIssuerInformation::ToJson(this->Model());
}

JsonValue OpenIdIssuerInformation::ToJson(const PFAuthenticationOpenIdIssuerInformation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthorizationUrl", input.authorizationUrl);
    JsonUtils::ObjectAddMember(output, "Issuer", input.issuer);
    JsonUtils::ObjectAddMember(output, "JsonWebKeySet", input.jsonWebKeySet);
    JsonUtils::ObjectAddMember(output, "TokenUrl", input.tokenUrl);
    return output;
}

void OpenIdIssuerInformation::FromJson(const JsonValue& input)
{
    String authorizationUrl{};
    JsonUtils::ObjectGetMember(input, "AuthorizationUrl", authorizationUrl);
    this->SetAuthorizationUrl(std::move(authorizationUrl));

    String issuer{};
    JsonUtils::ObjectGetMember(input, "Issuer", issuer);
    this->SetIssuer(std::move(issuer));

    JsonObject jsonWebKeySet{};
    JsonUtils::ObjectGetMember(input, "JsonWebKeySet", jsonWebKeySet);
    this->SetJsonWebKeySet(std::move(jsonWebKeySet));

    String tokenUrl{};
    JsonUtils::ObjectGetMember(input, "TokenUrl", tokenUrl);
    this->SetTokenUrl(std::move(tokenUrl));
}

size_t OpenIdIssuerInformation::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationOpenIdIssuerInformation const*> OpenIdIssuerInformation::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<OpenIdIssuerInformation>(&this->Model());
}

size_t OpenIdIssuerInformation::RequiredBufferSize(const PFAuthenticationOpenIdIssuerInformation& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.authorizationUrl)
    {
        requiredSize += (std::strlen(model.authorizationUrl) + 1);
    }
    if (model.issuer)
    {
        requiredSize += (std::strlen(model.issuer) + 1);
    }
    if (model.jsonWebKeySet.stringValue)
    {
    requiredSize += (std::strlen(model.jsonWebKeySet.stringValue) + 1);
    }
    if (model.tokenUrl)
    {
        requiredSize += (std::strlen(model.tokenUrl) + 1);
    }
    return requiredSize;
}

HRESULT OpenIdIssuerInformation::Copy(const PFAuthenticationOpenIdIssuerInformation& input, PFAuthenticationOpenIdIssuerInformation& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.authorizationUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.authorizationUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.issuer); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.issuer = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.jsonWebKeySet.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.jsonWebKeySet.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.tokenUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tokenUrl = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateOpenIdConnectionRequest::ToJson() const
{
    return CreateOpenIdConnectionRequest::ToJson(this->Model());
}

JsonValue CreateOpenIdConnectionRequest::ToJson(const PFAuthenticationCreateOpenIdConnectionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ClientId", input.clientId);
    JsonUtils::ObjectAddMember(output, "ClientSecret", input.clientSecret);
    JsonUtils::ObjectAddMember(output, "ConnectionId", input.connectionId);
    JsonUtils::ObjectAddMember(output, "IgnoreNonce", input.ignoreNonce);
    JsonUtils::ObjectAddMember(output, "IssuerDiscoveryUrl", input.issuerDiscoveryUrl);
    JsonUtils::ObjectAddMember<OpenIdIssuerInformation>(output, "IssuerInformation", input.issuerInformation);
    return output;
}

JsonValue CreatePlayerSharedSecretRequest::ToJson() const
{
    return CreatePlayerSharedSecretRequest::ToJson(this->Model());
}

JsonValue CreatePlayerSharedSecretRequest::ToJson(const PFAuthenticationCreatePlayerSharedSecretRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "FriendlyName", input.friendlyName);
    return output;
}

void CreatePlayerSharedSecretResult::FromJson(const JsonValue& input)
{
    String secretKey{};
    JsonUtils::ObjectGetMember(input, "SecretKey", secretKey);
    this->SetSecretKey(std::move(secretKey));
}

size_t CreatePlayerSharedSecretResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationCreatePlayerSharedSecretResult const*> CreatePlayerSharedSecretResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreatePlayerSharedSecretResult>(&this->Model());
}

size_t CreatePlayerSharedSecretResult::RequiredBufferSize(const PFAuthenticationCreatePlayerSharedSecretResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.secretKey)
    {
        requiredSize += (std::strlen(model.secretKey) + 1);
    }
    return requiredSize;
}

HRESULT CreatePlayerSharedSecretResult::Copy(const PFAuthenticationCreatePlayerSharedSecretResult& input, PFAuthenticationCreatePlayerSharedSecretResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.secretKey); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.secretKey = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteOpenIdConnectionRequest::ToJson() const
{
    return DeleteOpenIdConnectionRequest::ToJson(this->Model());
}

JsonValue DeleteOpenIdConnectionRequest::ToJson(const PFAuthenticationDeleteOpenIdConnectionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConnectionId", input.connectionId);
    return output;
}

JsonValue DeletePlayerSharedSecretRequest::ToJson() const
{
    return DeletePlayerSharedSecretRequest::ToJson(this->Model());
}

JsonValue DeletePlayerSharedSecretRequest::ToJson(const PFAuthenticationDeletePlayerSharedSecretRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "SecretKey", input.secretKey);
    return output;
}

void SharedSecret::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Disabled", this->m_model.disabled);

    String friendlyName{};
    JsonUtils::ObjectGetMember(input, "FriendlyName", friendlyName);
    this->SetFriendlyName(std::move(friendlyName));

    String secretKey{};
    JsonUtils::ObjectGetMember(input, "SecretKey", secretKey);
    this->SetSecretKey(std::move(secretKey));
}

size_t SharedSecret::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationSharedSecret const*> SharedSecret::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SharedSecret>(&this->Model());
}

size_t SharedSecret::RequiredBufferSize(const PFAuthenticationSharedSecret& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.friendlyName)
    {
        requiredSize += (std::strlen(model.friendlyName) + 1);
    }
    if (model.secretKey)
    {
        requiredSize += (std::strlen(model.secretKey) + 1);
    }
    return requiredSize;
}

HRESULT SharedSecret::Copy(const PFAuthenticationSharedSecret& input, PFAuthenticationSharedSecret& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.friendlyName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.friendlyName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.secretKey); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.secretKey = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayerSharedSecretsResult::FromJson(const JsonValue& input)
{
    ModelVector<SharedSecret> sharedSecrets{};
    JsonUtils::ObjectGetMember<SharedSecret>(input, "SharedSecrets", sharedSecrets);
    this->SetSharedSecrets(std::move(sharedSecrets));
}

size_t GetPlayerSharedSecretsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationGetPlayerSharedSecretsResult const*> GetPlayerSharedSecretsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerSharedSecretsResult>(&this->Model());
}

size_t GetPlayerSharedSecretsResult::RequiredBufferSize(const PFAuthenticationGetPlayerSharedSecretsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAuthenticationSharedSecret*) + sizeof(PFAuthenticationSharedSecret*) * model.sharedSecretsCount);
    for (size_t i = 0; i < model.sharedSecretsCount; ++i)
    {
        requiredSize += SharedSecret::RequiredBufferSize(*model.sharedSecrets[i]);
    }
    return requiredSize;
}

HRESULT GetPlayerSharedSecretsResult::Copy(const PFAuthenticationGetPlayerSharedSecretsResult& input, PFAuthenticationGetPlayerSharedSecretsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<SharedSecret>(input.sharedSecrets, input.sharedSecretsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.sharedSecrets = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPolicyRequest::ToJson() const
{
    return GetPolicyRequest::ToJson(this->Model());
}

JsonValue GetPolicyRequest::ToJson(const PFAuthenticationGetPolicyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PolicyName", input.policyName);
    return output;
}

JsonValue ApiCondition::ToJson() const
{
    return ApiCondition::ToJson(this->Model());
}

JsonValue ApiCondition::ToJson(const PFAuthenticationApiCondition& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "HasSignatureOrEncryption", input.hasSignatureOrEncryption);
    return output;
}

void ApiCondition::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFAuthenticationConditionals> hasSignatureOrEncryption{};
    JsonUtils::ObjectGetMember(input, "HasSignatureOrEncryption", hasSignatureOrEncryption);
    this->SetHasSignatureOrEncryption(std::move(hasSignatureOrEncryption));
}

size_t ApiCondition::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationApiCondition const*> ApiCondition::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ApiCondition>(&this->Model());
}

size_t ApiCondition::RequiredBufferSize(const PFAuthenticationApiCondition& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.hasSignatureOrEncryption)
    {
        requiredSize += (alignof(PFAuthenticationConditionals) + sizeof(PFAuthenticationConditionals));
    }
    return requiredSize;
}

HRESULT ApiCondition::Copy(const PFAuthenticationApiCondition& input, PFAuthenticationApiCondition& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.hasSignatureOrEncryption); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.hasSignatureOrEncryption = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PermissionStatement::ToJson() const
{
    return PermissionStatement::ToJson(this->Model());
}

JsonValue PermissionStatement::ToJson(const PFAuthenticationPermissionStatement& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Action", input.action);
    JsonUtils::ObjectAddMember<ApiCondition>(output, "ApiConditions", input.apiConditions);
    JsonUtils::ObjectAddMember(output, "Comment", input.comment);
    JsonUtils::ObjectAddMember(output, "Effect", input.effect);
    JsonUtils::ObjectAddMember(output, "Principal", input.principal);
    JsonUtils::ObjectAddMember(output, "Resource", input.resource);
    return output;
}

void PermissionStatement::FromJson(const JsonValue& input)
{
    String action{};
    JsonUtils::ObjectGetMember(input, "Action", action);
    this->SetAction(std::move(action));

    StdExtra::optional<ApiCondition> apiConditions{};
    JsonUtils::ObjectGetMember(input, "ApiConditions", apiConditions);
    if (apiConditions)
    {
        this->SetApiConditions(std::move(*apiConditions));
    }

    String comment{};
    JsonUtils::ObjectGetMember(input, "Comment", comment);
    this->SetComment(std::move(comment));

    JsonUtils::ObjectGetMember(input, "Effect", this->m_model.effect);

    String principal{};
    JsonUtils::ObjectGetMember(input, "Principal", principal);
    this->SetPrincipal(std::move(principal));

    String resource{};
    JsonUtils::ObjectGetMember(input, "Resource", resource);
    this->SetResource(std::move(resource));
}

size_t PermissionStatement::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationPermissionStatement const*> PermissionStatement::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PermissionStatement>(&this->Model());
}

size_t PermissionStatement::RequiredBufferSize(const PFAuthenticationPermissionStatement& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.action)
    {
        requiredSize += (std::strlen(model.action) + 1);
    }
    if (model.apiConditions)
    {
        requiredSize += ApiCondition::RequiredBufferSize(*model.apiConditions);
    }
    if (model.comment)
    {
        requiredSize += (std::strlen(model.comment) + 1);
    }
    if (model.principal)
    {
        requiredSize += (std::strlen(model.principal) + 1);
    }
    if (model.resource)
    {
        requiredSize += (std::strlen(model.resource) + 1);
    }
    return requiredSize;
}

HRESULT PermissionStatement::Copy(const PFAuthenticationPermissionStatement& input, PFAuthenticationPermissionStatement& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.action); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.action = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ApiCondition>(input.apiConditions); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.apiConditions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.comment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.comment = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.principal); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.principal = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.resource); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.resource = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPolicyResponse::FromJson(const JsonValue& input)
{
    String policyName{};
    JsonUtils::ObjectGetMember(input, "PolicyName", policyName);
    this->SetPolicyName(std::move(policyName));

    JsonUtils::ObjectGetMember(input, "PolicyVersion", this->m_model.policyVersion);

    ModelVector<PermissionStatement> statements{};
    JsonUtils::ObjectGetMember<PermissionStatement>(input, "Statements", statements);
    this->SetStatements(std::move(statements));
}

size_t GetPolicyResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationGetPolicyResponse const*> GetPolicyResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPolicyResponse>(&this->Model());
}

size_t GetPolicyResponse::RequiredBufferSize(const PFAuthenticationGetPolicyResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.policyName)
    {
        requiredSize += (std::strlen(model.policyName) + 1);
    }
    requiredSize += (alignof(PFAuthenticationPermissionStatement*) + sizeof(PFAuthenticationPermissionStatement*) * model.statementsCount);
    for (size_t i = 0; i < model.statementsCount; ++i)
    {
        requiredSize += PermissionStatement::RequiredBufferSize(*model.statements[i]);
    }
    return requiredSize;
}

HRESULT GetPolicyResponse::Copy(const PFAuthenticationGetPolicyResponse& input, PFAuthenticationGetPolicyResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.policyName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.policyName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PermissionStatement>(input.statements, input.statementsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statements = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void OpenIdConnection::FromJson(const JsonValue& input)
{
    String clientId{};
    JsonUtils::ObjectGetMember(input, "ClientId", clientId);
    this->SetClientId(std::move(clientId));

    String clientSecret{};
    JsonUtils::ObjectGetMember(input, "ClientSecret", clientSecret);
    this->SetClientSecret(std::move(clientSecret));

    String connectionId{};
    JsonUtils::ObjectGetMember(input, "ConnectionId", connectionId);
    this->SetConnectionId(std::move(connectionId));

    JsonUtils::ObjectGetMember(input, "DiscoverConfiguration", this->m_model.discoverConfiguration);

    StdExtra::optional<OpenIdIssuerInformation> issuerInformation{};
    JsonUtils::ObjectGetMember(input, "IssuerInformation", issuerInformation);
    if (issuerInformation)
    {
        this->SetIssuerInformation(std::move(*issuerInformation));
    }
}

size_t OpenIdConnection::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationOpenIdConnection const*> OpenIdConnection::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<OpenIdConnection>(&this->Model());
}

size_t OpenIdConnection::RequiredBufferSize(const PFAuthenticationOpenIdConnection& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.clientId)
    {
        requiredSize += (std::strlen(model.clientId) + 1);
    }
    if (model.clientSecret)
    {
        requiredSize += (std::strlen(model.clientSecret) + 1);
    }
    if (model.connectionId)
    {
        requiredSize += (std::strlen(model.connectionId) + 1);
    }
    if (model.issuerInformation)
    {
        requiredSize += OpenIdIssuerInformation::RequiredBufferSize(*model.issuerInformation);
    }
    return requiredSize;
}

HRESULT OpenIdConnection::Copy(const PFAuthenticationOpenIdConnection& input, PFAuthenticationOpenIdConnection& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.clientId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.clientId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.clientSecret); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.clientSecret = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.connectionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<OpenIdIssuerInformation>(input.issuerInformation); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.issuerInformation = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListOpenIdConnectionResponse::FromJson(const JsonValue& input)
{
    ModelVector<OpenIdConnection> connections{};
    JsonUtils::ObjectGetMember<OpenIdConnection>(input, "Connections", connections);
    this->SetConnections(std::move(connections));
}

size_t ListOpenIdConnectionResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationListOpenIdConnectionResponse const*> ListOpenIdConnectionResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListOpenIdConnectionResponse>(&this->Model());
}

size_t ListOpenIdConnectionResponse::RequiredBufferSize(const PFAuthenticationListOpenIdConnectionResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAuthenticationOpenIdConnection*) + sizeof(PFAuthenticationOpenIdConnection*) * model.connectionsCount);
    for (size_t i = 0; i < model.connectionsCount; ++i)
    {
        requiredSize += OpenIdConnection::RequiredBufferSize(*model.connections[i]);
    }
    return requiredSize;
}

HRESULT ListOpenIdConnectionResponse::Copy(const PFAuthenticationListOpenIdConnectionResponse& input, PFAuthenticationListOpenIdConnectionResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<OpenIdConnection>(input.connections, input.connectionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connections = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdminSetPlayerSecretRequest::ToJson() const
{
    return AdminSetPlayerSecretRequest::ToJson(this->Model());
}

JsonValue AdminSetPlayerSecretRequest::ToJson(const PFAuthenticationAdminSetPlayerSecretRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue UpdateOpenIdConnectionRequest::ToJson() const
{
    return UpdateOpenIdConnectionRequest::ToJson(this->Model());
}

JsonValue UpdateOpenIdConnectionRequest::ToJson(const PFAuthenticationUpdateOpenIdConnectionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ClientId", input.clientId);
    JsonUtils::ObjectAddMember(output, "ClientSecret", input.clientSecret);
    JsonUtils::ObjectAddMember(output, "ConnectionId", input.connectionId);
    JsonUtils::ObjectAddMember(output, "IssuerDiscoveryUrl", input.issuerDiscoveryUrl);
    JsonUtils::ObjectAddMember<OpenIdIssuerInformation>(output, "IssuerInformation", input.issuerInformation);
    return output;
}

JsonValue UpdatePlayerSharedSecretRequest::ToJson() const
{
    return UpdatePlayerSharedSecretRequest::ToJson(this->Model());
}

JsonValue UpdatePlayerSharedSecretRequest::ToJson(const PFAuthenticationUpdatePlayerSharedSecretRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Disabled", input.disabled);
    JsonUtils::ObjectAddMember(output, "FriendlyName", input.friendlyName);
    JsonUtils::ObjectAddMember(output, "SecretKey", input.secretKey);
    return output;
}

JsonValue UpdatePolicyRequest::ToJson() const
{
    return UpdatePolicyRequest::ToJson(this->Model());
}

JsonValue UpdatePolicyRequest::ToJson(const PFAuthenticationUpdatePolicyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OverwritePolicy", input.overwritePolicy);
    JsonUtils::ObjectAddMember(output, "PolicyName", input.policyName);
    JsonUtils::ObjectAddMember(output, "PolicyVersion", input.policyVersion);
    JsonUtils::ObjectAddMemberArray<PermissionStatement>(output, "Statements", input.statements, input.statementsCount);
    return output;
}

void UpdatePolicyResponse::FromJson(const JsonValue& input)
{
    String policyName{};
    JsonUtils::ObjectGetMember(input, "PolicyName", policyName);
    this->SetPolicyName(std::move(policyName));

    ModelVector<PermissionStatement> statements{};
    JsonUtils::ObjectGetMember<PermissionStatement>(input, "Statements", statements);
    this->SetStatements(std::move(statements));
}

size_t UpdatePolicyResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationUpdatePolicyResponse const*> UpdatePolicyResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdatePolicyResponse>(&this->Model());
}

size_t UpdatePolicyResponse::RequiredBufferSize(const PFAuthenticationUpdatePolicyResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.policyName)
    {
        requiredSize += (std::strlen(model.policyName) + 1);
    }
    requiredSize += (alignof(PFAuthenticationPermissionStatement*) + sizeof(PFAuthenticationPermissionStatement*) * model.statementsCount);
    for (size_t i = 0; i < model.statementsCount; ++i)
    {
        requiredSize += PermissionStatement::RequiredBufferSize(*model.statements[i]);
    }
    return requiredSize;
}

HRESULT UpdatePolicyResponse::Copy(const PFAuthenticationUpdatePolicyResponse& input, PFAuthenticationUpdatePolicyResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.policyName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.policyName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PermissionStatement>(input.statements, input.statementsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statements = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPhotonAuthenticationTokenRequest::ToJson() const
{
    return GetPhotonAuthenticationTokenRequest::ToJson(this->Model());
}

JsonValue GetPhotonAuthenticationTokenRequest::ToJson(const PFAuthenticationGetPhotonAuthenticationTokenRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PhotonApplicationId", input.photonApplicationId);
    return output;
}

void GetPhotonAuthenticationTokenResult::FromJson(const JsonValue& input)
{
    String photonCustomAuthenticationToken{};
    JsonUtils::ObjectGetMember(input, "PhotonCustomAuthenticationToken", photonCustomAuthenticationToken);
    this->SetPhotonCustomAuthenticationToken(std::move(photonCustomAuthenticationToken));
}

size_t GetPhotonAuthenticationTokenResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationGetPhotonAuthenticationTokenResult const*> GetPhotonAuthenticationTokenResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPhotonAuthenticationTokenResult>(&this->Model());
}

size_t GetPhotonAuthenticationTokenResult::RequiredBufferSize(const PFAuthenticationGetPhotonAuthenticationTokenResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.photonCustomAuthenticationToken)
    {
        requiredSize += (std::strlen(model.photonCustomAuthenticationToken) + 1);
    }
    return requiredSize;
}

HRESULT GetPhotonAuthenticationTokenResult::Copy(const PFAuthenticationGetPhotonAuthenticationTokenResult& input, PFAuthenticationGetPhotonAuthenticationTokenResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.photonCustomAuthenticationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.photonCustomAuthenticationToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTitlePublicKeyRequest::ToJson() const
{
    return GetTitlePublicKeyRequest::ToJson(this->Model());
}

JsonValue GetTitlePublicKeyRequest::ToJson(const PFAuthenticationGetTitlePublicKeyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "TitleId", input.titleId);
    JsonUtils::ObjectAddMember(output, "TitleSharedSecret", input.titleSharedSecret);
    return output;
}

void GetTitlePublicKeyResult::FromJson(const JsonValue& input)
{
    String RSAPublicKey{};
    JsonUtils::ObjectGetMember(input, "RSAPublicKey", RSAPublicKey);
    this->SetRSAPublicKey(std::move(RSAPublicKey));
}

size_t GetTitlePublicKeyResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationGetTitlePublicKeyResult const*> GetTitlePublicKeyResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitlePublicKeyResult>(&this->Model());
}

size_t GetTitlePublicKeyResult::RequiredBufferSize(const PFAuthenticationGetTitlePublicKeyResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.RSAPublicKey)
    {
        requiredSize += (std::strlen(model.RSAPublicKey) + 1);
    }
    return requiredSize;
}

HRESULT GetTitlePublicKeyResult::Copy(const PFAuthenticationGetTitlePublicKeyResult& input, PFAuthenticationGetTitlePublicKeyResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.RSAPublicKey); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.RSAPublicKey = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LoginWithAndroidDeviceIDRequest::ToJson() const
{
    return LoginWithAndroidDeviceIDRequest::ToJson(this->Model());
}

JsonValue LoginWithAndroidDeviceIDRequest::ToJson(const PFAuthenticationLoginWithAndroidDeviceIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AndroidDevice", input.androidDevice);
    JsonUtils::ObjectAddMember(output, "AndroidDeviceId", input.androidDeviceId);
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "OS", input.OS);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

void EntityTokenResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<EntityKey> entity{};
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    if (entity)
    {
        this->SetEntity(std::move(*entity));
    }

    String entityToken{};
    JsonUtils::ObjectGetMember(input, "EntityToken", entityToken);
    this->SetEntityToken(std::move(entityToken));

    StdExtra::optional<time_t> tokenExpiration{};
    JsonUtils::ObjectGetMemberTime(input, "TokenExpiration", tokenExpiration);
    this->SetTokenExpiration(std::move(tokenExpiration));
}

size_t EntityTokenResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationEntityTokenResponse const*> EntityTokenResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityTokenResponse>(&this->Model());
}

size_t EntityTokenResponse::RequiredBufferSize(const PFAuthenticationEntityTokenResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.entity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.entity);
    }
    if (model.entityToken)
    {
        requiredSize += (std::strlen(model.entityToken) + 1);
    }
    if (model.tokenExpiration)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    return requiredSize;
}

HRESULT EntityTokenResponse::Copy(const PFAuthenticationEntityTokenResponse& input, PFAuthenticationEntityTokenResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.entity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entity = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.entityToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entityToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.tokenExpiration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tokenExpiration = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void UserSettings::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "GatherDeviceInfo", this->m_model.gatherDeviceInfo);

    JsonUtils::ObjectGetMember(input, "GatherFocusInfo", this->m_model.gatherFocusInfo);

    JsonUtils::ObjectGetMember(input, "NeedsAttribution", this->m_model.needsAttribution);
}

size_t UserSettings::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationUserSettings const*> UserSettings::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UserSettings>(&this->Model());
}

size_t UserSettings::RequiredBufferSize(const PFAuthenticationUserSettings& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT UserSettings::Copy(const PFAuthenticationUserSettings& input, PFAuthenticationUserSettings& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

void LoginResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "EntityToken", entityToken);
    JsonUtils::ObjectGetMember(input, "InfoResultPayload", infoResultPayload);
    JsonUtils::ObjectGetMemberTime(input, "LastLoginTime", lastLoginTime);
    JsonUtils::ObjectGetMember(input, "NewlyCreated", newlyCreated);
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    JsonUtils::ObjectGetMember(input, "SessionTicket", sessionTicket);
    JsonUtils::ObjectGetMember(input, "SettingsForUser", settingsForUser);
    JsonUtils::ObjectGetMember(input, "TreatmentAssignment", treatmentAssignment);}

JsonValue LoginWithAppleRequest::ToJson() const
{
    return LoginWithAppleRequest::ToJson(this->Model());
}

JsonValue LoginWithAppleRequest::ToJson(const PFAuthenticationLoginWithAppleRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IdentityToken", input.identityToken);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithCustomIDRequest::ToJson() const
{
    return LoginWithCustomIDRequest::ToJson(this->Model());
}

JsonValue LoginWithCustomIDRequest::ToJson(const PFAuthenticationLoginWithCustomIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMember(output, "CustomId", input.customId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithEmailAddressRequest::ToJson() const
{
    return LoginWithEmailAddressRequest::ToJson(this->Model());
}

JsonValue LoginWithEmailAddressRequest::ToJson(const PFAuthenticationLoginWithEmailAddressRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "Password", input.password);
    return output;
}

JsonValue LoginWithFacebookRequest::ToJson() const
{
    return LoginWithFacebookRequest::ToJson(this->Model());
}

JsonValue LoginWithFacebookRequest::ToJson(const PFAuthenticationLoginWithFacebookRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessToken", input.accessToken);
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithFacebookInstantGamesIdRequest::ToJson() const
{
    return LoginWithFacebookInstantGamesIdRequest::ToJson(this->Model());
}

JsonValue LoginWithFacebookInstantGamesIdRequest::ToJson(const PFAuthenticationLoginWithFacebookInstantGamesIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "FacebookInstantGamesSignature", input.facebookInstantGamesSignature);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithGameCenterRequest::ToJson() const
{
    return LoginWithGameCenterRequest::ToJson(this->Model());
}

JsonValue LoginWithGameCenterRequest::ToJson(const PFAuthenticationLoginWithGameCenterRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerId", input.playerId);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "PublicKeyUrl", input.publicKeyUrl);
    JsonUtils::ObjectAddMember(output, "Salt", input.salt);
    JsonUtils::ObjectAddMember(output, "Signature", input.signature);
    JsonUtils::ObjectAddMember(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue LoginWithGoogleAccountRequest::ToJson() const
{
    return LoginWithGoogleAccountRequest::ToJson(this->Model());
}

JsonValue LoginWithGoogleAccountRequest::ToJson(const PFAuthenticationLoginWithGoogleAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "ServerAuthCode", input.serverAuthCode);
    return output;
}

JsonValue LoginWithIOSDeviceIDRequest::ToJson() const
{
    return LoginWithIOSDeviceIDRequest::ToJson(this->Model());
}

JsonValue LoginWithIOSDeviceIDRequest::ToJson(const PFAuthenticationLoginWithIOSDeviceIDRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DeviceId", input.deviceId);
    JsonUtils::ObjectAddMember(output, "DeviceModel", input.deviceModel);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "OS", input.OS);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithKongregateRequest::ToJson() const
{
    return LoginWithKongregateRequest::ToJson(this->Model());
}

JsonValue LoginWithKongregateRequest::ToJson(const PFAuthenticationLoginWithKongregateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthTicket", input.authTicket);
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "KongregateId", input.kongregateId);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithNintendoServiceAccountRequest::ToJson() const
{
    return LoginWithNintendoServiceAccountRequest::ToJson(this->Model());
}

JsonValue LoginWithNintendoServiceAccountRequest::ToJson(const PFAuthenticationLoginWithNintendoServiceAccountRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IdentityToken", input.identityToken);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithNintendoSwitchDeviceIdRequest::ToJson() const
{
    return LoginWithNintendoSwitchDeviceIdRequest::ToJson(this->Model());
}

JsonValue LoginWithNintendoSwitchDeviceIdRequest::ToJson(const PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "NintendoSwitchDeviceId", input.nintendoSwitchDeviceId);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithOpenIdConnectRequest::ToJson() const
{
    return LoginWithOpenIdConnectRequest::ToJson(this->Model());
}

JsonValue LoginWithOpenIdConnectRequest::ToJson(const PFAuthenticationLoginWithOpenIdConnectRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConnectionId", input.connectionId);
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IdToken", input.idToken);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue LoginWithPlayFabRequest::ToJson() const
{
    return LoginWithPlayFabRequest::ToJson(this->Model());
}

JsonValue LoginWithPlayFabRequest::ToJson(const PFAuthenticationLoginWithPlayFabRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "Password", input.password);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    return output;
}

JsonValue LoginWithPSNRequest::ToJson() const
{
    return LoginWithPSNRequest::ToJson(this->Model());
}

JsonValue LoginWithPSNRequest::ToJson(const PFAuthenticationLoginWithPSNRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthCode", input.authCode);
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "IssuerId", input.issuerId);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "RedirectUri", input.redirectUri);
    return output;
}

JsonValue LoginWithSteamRequest::ToJson() const
{
    return LoginWithSteamRequest::ToJson(this->Model());
}

JsonValue LoginWithSteamRequest::ToJson(const PFAuthenticationLoginWithSteamRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "SteamTicket", input.steamTicket);
    return output;
}

JsonValue LoginWithTwitchRequest::ToJson() const
{
    return LoginWithTwitchRequest::ToJson(this->Model());
}

JsonValue LoginWithTwitchRequest::ToJson(const PFAuthenticationLoginWithTwitchRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AccessToken", input.accessToken);
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue ClientLoginWithXboxRequest::ToJson() const
{
    return ClientLoginWithXboxRequest::ToJson(this->Model());
}

JsonValue ClientLoginWithXboxRequest::ToJson(const PFAuthenticationClientLoginWithXboxRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

JsonValue RegisterPlayFabUserRequest::ToJson() const
{
    return RegisterPlayFabUserRequest::ToJson(this->Model());
}

JsonValue RegisterPlayFabUserRequest::ToJson(const PFAuthenticationRegisterPlayFabUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DisplayName", input.displayName);
    JsonUtils::ObjectAddMember(output, "Email", input.email);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "Password", input.password);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "RequireBothUsernameAndEmail", input.requireBothUsernameAndEmail);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    return output;
}

void RegisterPlayFabUserResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "EntityToken", entityToken);
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    JsonUtils::ObjectGetMember(input, "SessionTicket", sessionTicket);
    JsonUtils::ObjectGetMember(input, "SettingsForUser", settingsForUser);
    JsonUtils::ObjectGetMember(input, "Username", username);}

JsonValue ClientSetPlayerSecretRequest::ToJson() const
{
    return ClientSetPlayerSecretRequest::ToJson(this->Model());
}

JsonValue ClientSetPlayerSecretRequest::ToJson(const PFAuthenticationClientSetPlayerSecretRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "EncryptedRequest", input.encryptedRequest);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    return output;
}

JsonValue AuthenticateSessionTicketRequest::ToJson() const
{
    return AuthenticateSessionTicketRequest::ToJson(this->Model());
}

JsonValue AuthenticateSessionTicketRequest::ToJson(const PFAuthenticationAuthenticateSessionTicketRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "SessionTicket", input.sessionTicket);
    return output;
}

void AuthenticateSessionTicketResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<bool> isSessionTicketExpired{};
    JsonUtils::ObjectGetMember(input, "IsSessionTicketExpired", isSessionTicketExpired);
    this->SetIsSessionTicketExpired(std::move(isSessionTicketExpired));

    StdExtra::optional<UserAccountInfo> userInfo{};
    JsonUtils::ObjectGetMember(input, "UserInfo", userInfo);
    if (userInfo)
    {
        this->SetUserInfo(std::move(*userInfo));
    }
}

size_t AuthenticateSessionTicketResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationAuthenticateSessionTicketResult const*> AuthenticateSessionTicketResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AuthenticateSessionTicketResult>(&this->Model());
}

size_t AuthenticateSessionTicketResult::RequiredBufferSize(const PFAuthenticationAuthenticateSessionTicketResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.isSessionTicketExpired)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.userInfo)
    {
        requiredSize += UserAccountInfo::RequiredBufferSize(*model.userInfo);
    }
    return requiredSize;
}

HRESULT AuthenticateSessionTicketResult::Copy(const PFAuthenticationAuthenticateSessionTicketResult& input, PFAuthenticationAuthenticateSessionTicketResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.isSessionTicketExpired); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.isSessionTicketExpired = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<UserAccountInfo>(input.userInfo); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userInfo = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue LoginWithServerCustomIdRequest::ToJson() const
{
    return LoginWithServerCustomIdRequest::ToJson(this->Model());
}

JsonValue LoginWithServerCustomIdRequest::ToJson(const PFAuthenticationLoginWithServerCustomIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "ServerCustomId", input.serverCustomId);
    return output;
}

void ServerLoginResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "EntityToken", entityToken);
    JsonUtils::ObjectGetMember(input, "InfoResultPayload", infoResultPayload);
    JsonUtils::ObjectGetMemberTime(input, "LastLoginTime", lastLoginTime);
    JsonUtils::ObjectGetMember(input, "NewlyCreated", newlyCreated);
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    JsonUtils::ObjectGetMember(input, "SessionTicket", sessionTicket);
    JsonUtils::ObjectGetMember(input, "SettingsForUser", settingsForUser);
    JsonUtils::ObjectGetMember(input, "TreatmentAssignment", treatmentAssignment);}

JsonValue LoginWithSteamIdRequest::ToJson() const
{
    return LoginWithSteamIdRequest::ToJson(this->Model());
}

JsonValue LoginWithSteamIdRequest::ToJson(const PFAuthenticationLoginWithSteamIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "SteamId", input.steamId);
    return output;
}

JsonValue ServerLoginWithXboxRequest::ToJson() const
{
    return ServerLoginWithXboxRequest::ToJson(this->Model());
}

JsonValue ServerLoginWithXboxRequest::ToJson(const PFAuthenticationServerLoginWithXboxRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

JsonValue LoginWithXboxIdRequest::ToJson() const
{
    return LoginWithXboxIdRequest::ToJson(this->Model());
}

JsonValue LoginWithXboxIdRequest::ToJson(const PFAuthenticationLoginWithXboxIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CreateAccount", input.createAccount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<GetPlayerCombinedInfoRequestParams>(output, "InfoRequestParameters", input.infoRequestParameters);
    JsonUtils::ObjectAddMember(output, "Sandbox", input.sandbox);
    JsonUtils::ObjectAddMember(output, "XboxId", input.xboxId);
    return output;
}

JsonValue ServerSetPlayerSecretRequest::ToJson() const
{
    return ServerSetPlayerSecretRequest::ToJson(this->Model());
}

JsonValue ServerSetPlayerSecretRequest::ToJson(const PFAuthenticationServerSetPlayerSecretRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "PlayerSecret", input.playerSecret);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue GetEntityTokenRequest::ToJson() const
{
    return GetEntityTokenRequest::ToJson(this->Model());
}

JsonValue GetEntityTokenRequest::ToJson(const PFAuthenticationGetEntityTokenRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void GetEntityTokenResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    JsonUtils::ObjectGetMember(input, "EntityToken", entityToken);
    JsonUtils::ObjectGetMemberTime(input, "TokenExpiration", tokenExpiration);}

JsonValue ValidateEntityTokenRequest::ToJson() const
{
    return ValidateEntityTokenRequest::ToJson(this->Model());
}

JsonValue ValidateEntityTokenRequest::ToJson(const PFAuthenticationValidateEntityTokenRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EntityToken", input.entityToken);
    return output;
}

void ValidateEntityTokenResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<EntityKey> entity{};
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    if (entity)
    {
        this->SetEntity(std::move(*entity));
    }

    StdExtra::optional<PFAuthenticationIdentifiedDeviceType> identifiedDeviceType{};
    JsonUtils::ObjectGetMember(input, "IdentifiedDeviceType", identifiedDeviceType);
    this->SetIdentifiedDeviceType(std::move(identifiedDeviceType));

    StdExtra::optional<PFLoginIdentityProvider> identityProvider{};
    JsonUtils::ObjectGetMember(input, "IdentityProvider", identityProvider);
    this->SetIdentityProvider(std::move(identityProvider));

    String identityProviderIssuedId{};
    JsonUtils::ObjectGetMember(input, "IdentityProviderIssuedId", identityProviderIssuedId);
    this->SetIdentityProviderIssuedId(std::move(identityProviderIssuedId));

    StdExtra::optional<EntityLineage> lineage{};
    JsonUtils::ObjectGetMember(input, "Lineage", lineage);
    if (lineage)
    {
        this->SetLineage(std::move(*lineage));
    }
}

size_t ValidateEntityTokenResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationValidateEntityTokenResponse const*> ValidateEntityTokenResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ValidateEntityTokenResponse>(&this->Model());
}

size_t ValidateEntityTokenResponse::RequiredBufferSize(const PFAuthenticationValidateEntityTokenResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.entity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.entity);
    }
    if (model.identifiedDeviceType)
    {
        requiredSize += (alignof(PFAuthenticationIdentifiedDeviceType) + sizeof(PFAuthenticationIdentifiedDeviceType));
    }
    if (model.identityProvider)
    {
        requiredSize += (alignof(PFLoginIdentityProvider) + sizeof(PFLoginIdentityProvider));
    }
    if (model.identityProviderIssuedId)
    {
        requiredSize += (std::strlen(model.identityProviderIssuedId) + 1);
    }
    if (model.lineage)
    {
        requiredSize += EntityLineage::RequiredBufferSize(*model.lineage);
    }
    return requiredSize;
}

HRESULT ValidateEntityTokenResponse::Copy(const PFAuthenticationValidateEntityTokenResponse& input, PFAuthenticationValidateEntityTokenResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.entity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.entity = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.identifiedDeviceType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.identifiedDeviceType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.identityProvider); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.identityProvider = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.identityProviderIssuedId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.identityProviderIssuedId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityLineage>(input.lineage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lineage = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Authentication
} // namespace PlayFab
