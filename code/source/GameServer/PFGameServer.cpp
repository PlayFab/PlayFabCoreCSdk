#include "stdafx.h"
#include <playfab/PFGameServer.h>
#include "GameServer.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::GameServer;

HRESULT PFGameServerAdminAddServerBuildAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFGameServerAddServerBuildRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&GameServerAPI::AdminAddServerBuild, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFGameServerAdminAddServerBuildGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFGameServerAdminAddServerBuildGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGameServerAddServerBuildResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFGameServerAddServerBuildResult*>(buffer);

    return S_OK;
}

HRESULT PFGameServerAdminGetServerBuildInfoAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFGameServerGetServerBuildInfoRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&GameServerAPI::AdminGetServerBuildInfo, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFGameServerAdminGetServerBuildInfoGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFGameServerAdminGetServerBuildInfoGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGameServerGetServerBuildInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFGameServerGetServerBuildInfoResult*>(buffer);

    return S_OK;
}

HRESULT PFGameServerAdminGetServerBuildUploadUrlAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFGameServerGetServerBuildUploadURLRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&GameServerAPI::AdminGetServerBuildUploadUrl, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFGameServerAdminGetServerBuildUploadUrlGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFGameServerAdminGetServerBuildUploadUrlGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGameServerGetServerBuildUploadURLResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFGameServerGetServerBuildUploadURLResult*>(buffer);

    return S_OK;
}

HRESULT PFGameServerAdminListServerBuildsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&GameServerAPI::AdminListServerBuilds, contextHandle->state, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFGameServerAdminListServerBuildsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFGameServerAdminListServerBuildsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGameServerListBuildsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFGameServerListBuildsResult*>(buffer);

    return S_OK;
}

HRESULT PFGameServerAdminModifyServerBuildAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFGameServerModifyServerBuildRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&GameServerAPI::AdminModifyServerBuild, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFGameServerAdminModifyServerBuildGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFGameServerAdminModifyServerBuildGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGameServerModifyServerBuildResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFGameServerModifyServerBuildResult*>(buffer);

    return S_OK;
}

HRESULT PFGameServerAdminRemoveServerBuildAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFGameServerRemoveServerBuildRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&GameServerAPI::AdminRemoveServerBuild, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

