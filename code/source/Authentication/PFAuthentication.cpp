#include "stdafx.h"
#include <playfab/PFAuthentication.h>
#include "Authentication.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::Authentication;

PF_API PFAuthenticationAuthenticateWithCustomIdAsync(
    _In_ PFServiceConfigHandle contextHandle,
    _In_ const PFAuthenticationAuthenticateCustomIdIdentityRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    SharedPtr<GlobalState> state{ nullptr };
    RETURN_IF_FAILED(GlobalState::Get(state));

    SharedPtr<ServiceConfig> serviceConfig;
    RETURN_IF_FAILED(state->ServiceConfigs().FromHandle(contextHandle, serviceConfig));

    auto provider = MakeAuthProvider(std::move(state), async, __FUNCTION__, std::bind(&AuthenticationAPI::AuthenticateWithCustomId, std::placeholders::_1, std::move(serviceConfig), *request, std::placeholders::_2));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

PF_API PFAuthenticationAuthenticateWithCustomIdGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* entityHandle
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFTitlePlayerHandle), entityHandle, nullptr);
}

PF_API PFAuthenticationReAuthenticateWithCustomIdAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAuthenticationAuthenticateCustomIdIdentityRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(titlePlayerHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    SharedPtr<GlobalState> state{ nullptr };
    RETURN_IF_FAILED(GlobalState::Get(state));

    SharedPtr<TitlePlayer> titlePlayer;
    RETURN_IF_FAILED(state->TitlePlayers().FromHandle(titlePlayerHandle, titlePlayer));

    auto provider = MakeProvider(state->RunContext().DeriveOnQueue(async->queue), async, __FUNCTION__, std::bind(&AuthenticationAPI::ReAuthenticateWithCustomId, std::move(titlePlayer), *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

