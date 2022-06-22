#pragma once

#include <playfab/cpp/PFAuthenticationDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Authentication
{

// Authentication Classes
class AuthenticateCustomIdIdentityRequest : public Wrappers::PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationAuthenticateCustomIdIdentityRequest& input);
};

class EntityTokenResponse : public ServiceOutputModel
{
public:
    void FromJson(const JsonValue& input);

    StdExtra::optional<EntityKey> entity;
    String entityToken;
    StdExtra::optional<time_t> tokenExpiration;
};

class AuthenticateIdentityResult : public ServiceOutputModel
{
public:
    void FromJson(const JsonValue& input);

    String createdIdentityLinkId;
    StdExtra::optional<EntityTokenResponse> masterPlayerAccount;
    StdExtra::optional<EntityTokenResponse> titlePlayerAccount;
};

class GetLinkedPlayerIdentitiesRequest : public Wrappers::PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationGetLinkedPlayerIdentitiesRequest& input);
};

class LinkedPlayerIdentity : public Wrappers::PFAuthenticationLinkedPlayerIdentityWrapper<Allocator>, public ServiceOutputModel, public ClientOutputModel<PFAuthenticationLinkedPlayerIdentity>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationLinkedPlayerIdentityWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationLinkedPlayerIdentity const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationLinkedPlayerIdentity& model);
    static HRESULT Copy(const PFAuthenticationLinkedPlayerIdentity& input, PFAuthenticationLinkedPlayerIdentity& output, ModelBuffer& buffer);
};

class GetLinkedPlayerIdentitiesResult : public Wrappers::PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper<Allocator>, public ServiceOutputModel, public ClientOutputModel<PFAuthenticationGetLinkedPlayerIdentitiesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationGetLinkedPlayerIdentitiesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAuthenticationGetLinkedPlayerIdentitiesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAuthenticationGetLinkedPlayerIdentitiesResult& model);
    static HRESULT Copy(const PFAuthenticationGetLinkedPlayerIdentitiesResult& input, PFAuthenticationGetLinkedPlayerIdentitiesResult& output, ModelBuffer& buffer);
};

class UnlinkPlayerIdentityRequest : public Wrappers::PFAuthenticationUnlinkPlayerIdentityRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAuthenticationUnlinkPlayerIdentityRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAuthenticationUnlinkPlayerIdentityRequest& input);
};

} // namespace Authentication
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
