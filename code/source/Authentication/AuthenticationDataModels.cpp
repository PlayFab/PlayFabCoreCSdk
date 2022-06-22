#include "stdafx.h"
#include "AuthenticationDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Authentication
{

JsonValue AuthenticateCustomIdIdentityRequest::ToJson() const
{
    return AuthenticateCustomIdIdentityRequest::ToJson(this->Model());
}

JsonValue AuthenticateCustomIdIdentityRequest::ToJson(const PFAuthenticationAuthenticateCustomIdIdentityRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BehaviorIfIdentityNotLinked", input.behaviorIfIdentityNotLinked);
    JsonUtils::ObjectAddMember(output, "CustomId", input.customId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExistingMasterPlayerAccountId", input.existingMasterPlayerAccountId);
    return output;
}

void EntityTokenResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Entity", entity);
    JsonUtils::ObjectGetMember(input, "EntityToken", entityToken);
    JsonUtils::ObjectGetMemberTime(input, "TokenExpiration", tokenExpiration);}

void AuthenticateIdentityResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "CreatedIdentityLinkId", createdIdentityLinkId);
    JsonUtils::ObjectGetMember(input, "MasterPlayerAccount", masterPlayerAccount);
    JsonUtils::ObjectGetMember(input, "TitlePlayerAccount", titlePlayerAccount);}

JsonValue GetLinkedPlayerIdentitiesRequest::ToJson() const
{
    return GetLinkedPlayerIdentitiesRequest::ToJson(this->Model());
}

JsonValue GetLinkedPlayerIdentitiesRequest::ToJson(const PFAuthenticationGetLinkedPlayerIdentitiesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MasterPlayerAccountId", input.masterPlayerAccountId);
    return output;
}

void LinkedPlayerIdentity::FromJson(const JsonValue& input)
{
    String identityLinkId{};
    JsonUtils::ObjectGetMember(input, "IdentityLinkId", identityLinkId);
    this->SetIdentityLinkId(std::move(identityLinkId));

    JsonUtils::ObjectGetMember(input, "IdentityProvider", this->m_model.identityProvider);

    String identityProviderIssuedId{};
    JsonUtils::ObjectGetMember(input, "IdentityProviderIssuedId", identityProviderIssuedId);
    this->SetIdentityProviderIssuedId(std::move(identityProviderIssuedId));
}

size_t LinkedPlayerIdentity::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationLinkedPlayerIdentity const*> LinkedPlayerIdentity::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LinkedPlayerIdentity>(&this->Model());
}

size_t LinkedPlayerIdentity::RequiredBufferSize(const PFAuthenticationLinkedPlayerIdentity& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.identityLinkId)
    {
        requiredSize += (std::strlen(model.identityLinkId) + 1);
    }
    if (model.identityProviderIssuedId)
    {
        requiredSize += (std::strlen(model.identityProviderIssuedId) + 1);
    }
    return requiredSize;
}

HRESULT LinkedPlayerIdentity::Copy(const PFAuthenticationLinkedPlayerIdentity& input, PFAuthenticationLinkedPlayerIdentity& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.identityLinkId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.identityLinkId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.identityProviderIssuedId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.identityProviderIssuedId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetLinkedPlayerIdentitiesResult::FromJson(const JsonValue& input)
{
    ModelVector<LinkedPlayerIdentity> linkedIdentities{};
    JsonUtils::ObjectGetMember<LinkedPlayerIdentity>(input, "LinkedIdentities", linkedIdentities);
    this->SetLinkedIdentities(std::move(linkedIdentities));
}

size_t GetLinkedPlayerIdentitiesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAuthenticationGetLinkedPlayerIdentitiesResult const*> GetLinkedPlayerIdentitiesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLinkedPlayerIdentitiesResult>(&this->Model());
}

size_t GetLinkedPlayerIdentitiesResult::RequiredBufferSize(const PFAuthenticationGetLinkedPlayerIdentitiesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAuthenticationLinkedPlayerIdentity*) + sizeof(PFAuthenticationLinkedPlayerIdentity*) * model.linkedIdentitiesCount);
    for (size_t i = 0; i < model.linkedIdentitiesCount; ++i)
    {
        requiredSize += LinkedPlayerIdentity::RequiredBufferSize(*model.linkedIdentities[i]);
    }
    return requiredSize;
}

HRESULT GetLinkedPlayerIdentitiesResult::Copy(const PFAuthenticationGetLinkedPlayerIdentitiesResult& input, PFAuthenticationGetLinkedPlayerIdentitiesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<LinkedPlayerIdentity>(input.linkedIdentities, input.linkedIdentitiesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.linkedIdentities = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UnlinkPlayerIdentityRequest::ToJson() const
{
    return UnlinkPlayerIdentityRequest::ToJson(this->Model());
}

JsonValue UnlinkPlayerIdentityRequest::ToJson(const PFAuthenticationUnlinkPlayerIdentityRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IdentityLinkId", input.identityLinkId);
    JsonUtils::ObjectAddMember(output, "MasterPlayerAccountId", input.masterPlayerAccountId);
    return output;
}

} // namespace Authentication
} // namespace PlayFab
