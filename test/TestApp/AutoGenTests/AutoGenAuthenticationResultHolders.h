#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AuthenticateIdentityResultHolder : public XAsyncResult, public std::enable_shared_from_this<AuthenticateIdentityResultHolder>
{
    AuthenticateIdentityResultHolder() = default;
    AuthenticateIdentityResultHolder(const AuthenticateIdentityResultHolder&) = delete;
    AuthenticateIdentityResultHolder(AuthenticateIdentityResultHolder&&) = default;
    AuthenticateIdentityResultHolder& operator=(const AuthenticateIdentityResultHolder&) = delete;
    AuthenticateIdentityResultHolder& operator=(AuthenticateIdentityResultHolder&&) = default;
    ~AuthenticateIdentityResultHolder() = default;

    PFAuthenticationAuthenticateIdentityResult* result{ nullptr };
};

struct GetLinkedPlayerIdentitiesResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLinkedPlayerIdentitiesResultHolder>
{
    GetLinkedPlayerIdentitiesResultHolder() = default;
    GetLinkedPlayerIdentitiesResultHolder(const GetLinkedPlayerIdentitiesResultHolder&) = delete;
    GetLinkedPlayerIdentitiesResultHolder(GetLinkedPlayerIdentitiesResultHolder&&) = default;
    GetLinkedPlayerIdentitiesResultHolder& operator=(const GetLinkedPlayerIdentitiesResultHolder&) = delete;
    GetLinkedPlayerIdentitiesResultHolder& operator=(GetLinkedPlayerIdentitiesResultHolder&&) = default;
    ~GetLinkedPlayerIdentitiesResultHolder() = default;

    PFAuthenticationGetLinkedPlayerIdentitiesResult* result{ nullptr };
};

struct LoginPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<LoginPlayerResultHolder>
{
    LoginPlayerResultHolder() = default;
    LoginPlayerResultHolder(const LoginPlayerResultHolder&) = delete;
    LoginPlayerResultHolder(LoginPlayerResultHolder&&) = default;
    LoginPlayerResultHolder& operator=(const LoginPlayerResultHolder&) = delete;
    LoginPlayerResultHolder& operator=(LoginPlayerResultHolder&&) = default;
    ~LoginPlayerResultHolder() = default;

    PFAuthenticationLoginPlayerResult* result{ nullptr };
};


}
