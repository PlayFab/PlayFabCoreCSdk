#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreatePlayerSharedSecretResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreatePlayerSharedSecretResultHolder>
{
    CreatePlayerSharedSecretResultHolder() = default;
    CreatePlayerSharedSecretResultHolder(const CreatePlayerSharedSecretResultHolder&) = delete;
    CreatePlayerSharedSecretResultHolder(CreatePlayerSharedSecretResultHolder&&) = default;
    CreatePlayerSharedSecretResultHolder& operator=(const CreatePlayerSharedSecretResultHolder&) = delete;
    CreatePlayerSharedSecretResultHolder& operator=(CreatePlayerSharedSecretResultHolder&&) = default;
    ~CreatePlayerSharedSecretResultHolder() = default;

    PFAuthenticationCreatePlayerSharedSecretResult* result{ nullptr };
};

struct GetPlayerSharedSecretsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerSharedSecretsResultHolder>
{
    GetPlayerSharedSecretsResultHolder() = default;
    GetPlayerSharedSecretsResultHolder(const GetPlayerSharedSecretsResultHolder&) = delete;
    GetPlayerSharedSecretsResultHolder(GetPlayerSharedSecretsResultHolder&&) = default;
    GetPlayerSharedSecretsResultHolder& operator=(const GetPlayerSharedSecretsResultHolder&) = delete;
    GetPlayerSharedSecretsResultHolder& operator=(GetPlayerSharedSecretsResultHolder&&) = default;
    ~GetPlayerSharedSecretsResultHolder() = default;

    PFAuthenticationGetPlayerSharedSecretsResult* result{ nullptr };
};

struct GetPolicyResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetPolicyResponseHolder>
{
    GetPolicyResponseHolder() = default;
    GetPolicyResponseHolder(const GetPolicyResponseHolder&) = delete;
    GetPolicyResponseHolder(GetPolicyResponseHolder&&) = default;
    GetPolicyResponseHolder& operator=(const GetPolicyResponseHolder&) = delete;
    GetPolicyResponseHolder& operator=(GetPolicyResponseHolder&&) = default;
    ~GetPolicyResponseHolder() = default;

    PFAuthenticationGetPolicyResponse* result{ nullptr };
};

struct ListOpenIdConnectionResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListOpenIdConnectionResponseHolder>
{
    ListOpenIdConnectionResponseHolder() = default;
    ListOpenIdConnectionResponseHolder(const ListOpenIdConnectionResponseHolder&) = delete;
    ListOpenIdConnectionResponseHolder(ListOpenIdConnectionResponseHolder&&) = default;
    ListOpenIdConnectionResponseHolder& operator=(const ListOpenIdConnectionResponseHolder&) = delete;
    ListOpenIdConnectionResponseHolder& operator=(ListOpenIdConnectionResponseHolder&&) = default;
    ~ListOpenIdConnectionResponseHolder() = default;

    PFAuthenticationListOpenIdConnectionResponse* result{ nullptr };
};

struct UpdatePolicyResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UpdatePolicyResponseHolder>
{
    UpdatePolicyResponseHolder() = default;
    UpdatePolicyResponseHolder(const UpdatePolicyResponseHolder&) = delete;
    UpdatePolicyResponseHolder(UpdatePolicyResponseHolder&&) = default;
    UpdatePolicyResponseHolder& operator=(const UpdatePolicyResponseHolder&) = delete;
    UpdatePolicyResponseHolder& operator=(UpdatePolicyResponseHolder&&) = default;
    ~UpdatePolicyResponseHolder() = default;

    PFAuthenticationUpdatePolicyResponse* result{ nullptr };
};

struct GetPhotonAuthenticationTokenResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPhotonAuthenticationTokenResultHolder>
{
    GetPhotonAuthenticationTokenResultHolder() = default;
    GetPhotonAuthenticationTokenResultHolder(const GetPhotonAuthenticationTokenResultHolder&) = delete;
    GetPhotonAuthenticationTokenResultHolder(GetPhotonAuthenticationTokenResultHolder&&) = default;
    GetPhotonAuthenticationTokenResultHolder& operator=(const GetPhotonAuthenticationTokenResultHolder&) = delete;
    GetPhotonAuthenticationTokenResultHolder& operator=(GetPhotonAuthenticationTokenResultHolder&&) = default;
    ~GetPhotonAuthenticationTokenResultHolder() = default;

    PFAuthenticationGetPhotonAuthenticationTokenResult* result{ nullptr };
};

struct GetTitlePublicKeyResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitlePublicKeyResultHolder>
{
    GetTitlePublicKeyResultHolder() = default;
    GetTitlePublicKeyResultHolder(const GetTitlePublicKeyResultHolder&) = delete;
    GetTitlePublicKeyResultHolder(GetTitlePublicKeyResultHolder&&) = default;
    GetTitlePublicKeyResultHolder& operator=(const GetTitlePublicKeyResultHolder&) = delete;
    GetTitlePublicKeyResultHolder& operator=(GetTitlePublicKeyResultHolder&&) = default;
    ~GetTitlePublicKeyResultHolder() = default;

    PFAuthenticationGetTitlePublicKeyResult* result{ nullptr };
};

struct LoginResultHolder : public XAsyncResult, public std::enable_shared_from_this<LoginResultHolder>
{
    LoginResultHolder() = default;
    LoginResultHolder(const LoginResultHolder&) = delete;
    LoginResultHolder(LoginResultHolder&&) = default;
    LoginResultHolder& operator=(const LoginResultHolder&) = delete;
    LoginResultHolder& operator=(LoginResultHolder&&) = default;
    ~LoginResultHolder() = default;

    PFAuthenticationLoginResult* result{ nullptr };
};

struct RegisterPlayFabUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<RegisterPlayFabUserResultHolder>
{
    RegisterPlayFabUserResultHolder() = default;
    RegisterPlayFabUserResultHolder(const RegisterPlayFabUserResultHolder&) = delete;
    RegisterPlayFabUserResultHolder(RegisterPlayFabUserResultHolder&&) = default;
    RegisterPlayFabUserResultHolder& operator=(const RegisterPlayFabUserResultHolder&) = delete;
    RegisterPlayFabUserResultHolder& operator=(RegisterPlayFabUserResultHolder&&) = default;
    ~RegisterPlayFabUserResultHolder() = default;

    PFAuthenticationRegisterPlayFabUserResult* result{ nullptr };
};

struct AuthenticateSessionTicketResultHolder : public XAsyncResult, public std::enable_shared_from_this<AuthenticateSessionTicketResultHolder>
{
    AuthenticateSessionTicketResultHolder() = default;
    AuthenticateSessionTicketResultHolder(const AuthenticateSessionTicketResultHolder&) = delete;
    AuthenticateSessionTicketResultHolder(AuthenticateSessionTicketResultHolder&&) = default;
    AuthenticateSessionTicketResultHolder& operator=(const AuthenticateSessionTicketResultHolder&) = delete;
    AuthenticateSessionTicketResultHolder& operator=(AuthenticateSessionTicketResultHolder&&) = default;
    ~AuthenticateSessionTicketResultHolder() = default;

    PFAuthenticationAuthenticateSessionTicketResult* result{ nullptr };
};

struct ServerLoginResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerLoginResultHolder>
{
    ServerLoginResultHolder() = default;
    ServerLoginResultHolder(const ServerLoginResultHolder&) = delete;
    ServerLoginResultHolder(ServerLoginResultHolder&&) = default;
    ServerLoginResultHolder& operator=(const ServerLoginResultHolder&) = delete;
    ServerLoginResultHolder& operator=(ServerLoginResultHolder&&) = default;
    ~ServerLoginResultHolder() = default;

    PFAuthenticationServerLoginResult* result{ nullptr };
};

struct AuthenticateCustomIdResultHolder : public XAsyncResult, public std::enable_shared_from_this<AuthenticateCustomIdResultHolder>
{
    AuthenticateCustomIdResultHolder() = default;
    AuthenticateCustomIdResultHolder(const AuthenticateCustomIdResultHolder&) = delete;
    AuthenticateCustomIdResultHolder(AuthenticateCustomIdResultHolder&&) = default;
    AuthenticateCustomIdResultHolder& operator=(const AuthenticateCustomIdResultHolder&) = delete;
    AuthenticateCustomIdResultHolder& operator=(AuthenticateCustomIdResultHolder&&) = default;
    ~AuthenticateCustomIdResultHolder() = default;

    PFAuthenticationAuthenticateCustomIdResult* result{ nullptr };
};

struct GetEntityTokenResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetEntityTokenResponseHolder>
{
    GetEntityTokenResponseHolder() = default;
    GetEntityTokenResponseHolder(const GetEntityTokenResponseHolder&) = delete;
    GetEntityTokenResponseHolder(GetEntityTokenResponseHolder&&) = default;
    GetEntityTokenResponseHolder& operator=(const GetEntityTokenResponseHolder&) = delete;
    GetEntityTokenResponseHolder& operator=(GetEntityTokenResponseHolder&&) = default;
    ~GetEntityTokenResponseHolder() = default;

    PFAuthenticationGetEntityTokenResponse* result{ nullptr };
};

struct ValidateEntityTokenResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ValidateEntityTokenResponseHolder>
{
    ValidateEntityTokenResponseHolder() = default;
    ValidateEntityTokenResponseHolder(const ValidateEntityTokenResponseHolder&) = delete;
    ValidateEntityTokenResponseHolder(ValidateEntityTokenResponseHolder&&) = default;
    ValidateEntityTokenResponseHolder& operator=(const ValidateEntityTokenResponseHolder&) = delete;
    ValidateEntityTokenResponseHolder& operator=(ValidateEntityTokenResponseHolder&&) = default;
    ~ValidateEntityTokenResponseHolder() = default;

    PFAuthenticationValidateEntityTokenResponse* result{ nullptr };
};


}
