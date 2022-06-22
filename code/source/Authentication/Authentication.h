#pragma once

#include "AuthenticationDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Authentication
{

class AuthenticationAPI
{
public:
    AuthenticationAPI() = delete;
    AuthenticationAPI(const AuthenticationAPI& source) = delete;
    AuthenticationAPI& operator=(const AuthenticationAPI& source) = delete;
    ~AuthenticationAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<SharedPtr<TitlePlayer>> AuthenticateWithCustomId(SharedPtr<GlobalState const> state, SharedPtr<ServiceConfig const> config, const AuthenticateCustomIdIdentityRequest& request, RunContext rc);
    static AsyncOp<void> ReAuthenticateWithCustomId(SharedPtr<TitlePlayer> player, const AuthenticateCustomIdIdentityRequest& request, RunContext rc);
    static AsyncOp<GetLinkedPlayerIdentitiesResult> GetLinkedPlayerIdentities(SharedPtr<TitlePlayer> entity, const GetLinkedPlayerIdentitiesRequest& request, RunContext rc);
    static AsyncOp<void> UnlinkPlayerIdentity(SharedPtr<TitlePlayer> entity, const UnlinkPlayerIdentityRequest& request, RunContext rc);
};

} // namespace Authentication
} // namespace PlayFab
