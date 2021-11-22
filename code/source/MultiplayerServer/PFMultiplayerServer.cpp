#include "stdafx.h"
#include <playfab/PFMultiplayerServer.h>
#include "MultiplayerServer.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::MultiplayerServer;

HRESULT PFMultiplayerServerCreateBuildAliasAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerCreateBuildAliasRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::CreateBuildAlias, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerCreateBuildAliasGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerCreateBuildAliasGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerBuildAliasDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerBuildAliasDetailsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerCreateBuildWithCustomContainerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerCreateBuildWithCustomContainerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::CreateBuildWithCustomContainer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerCreateBuildWithCustomContainerGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerCreateBuildWithCustomContainerGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateBuildWithCustomContainerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerCreateBuildWithCustomContainerResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerCreateBuildWithManagedContainerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerCreateBuildWithManagedContainerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::CreateBuildWithManagedContainer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerCreateBuildWithManagedContainerGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerCreateBuildWithManagedContainerGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateBuildWithManagedContainerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerCreateBuildWithManagedContainerResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerCreateBuildWithProcessBasedServerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerCreateBuildWithProcessBasedServerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::CreateBuildWithProcessBasedServer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerCreateBuildWithProcessBasedServerGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerCreateBuildWithProcessBasedServerGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateBuildWithProcessBasedServerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerCreateBuildWithProcessBasedServerResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerCreateRemoteUserAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerCreateRemoteUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::CreateRemoteUser, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerCreateRemoteUserGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerCreateRemoteUserGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateRemoteUserResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerCreateRemoteUserResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::CreateTitleMultiplayerServersQuotaChange, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerDeleteAssetAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteAssetRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteAsset, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerDeleteBuildAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteBuildRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteBuild, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerDeleteBuildAliasAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteBuildAliasRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteBuildAlias, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerDeleteBuildRegionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteBuildRegionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteBuildRegion, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerDeleteCertificateAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteCertificateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteCertificate, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerDeleteContainerImageRepositoryAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteContainerImageRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteContainerImageRepository, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerDeleteRemoteUserAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerDeleteRemoteUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::DeleteRemoteUser, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerEnableMultiplayerServersForTitleAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerEnableMultiplayerServersForTitleRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::EnableMultiplayerServersForTitle, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerEnableMultiplayerServersForTitleGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerEnableMultiplayerServersForTitleGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerEnableMultiplayerServersForTitleResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerEnableMultiplayerServersForTitleResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetAssetDownloadUrlAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetAssetDownloadUrlRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetAssetDownloadUrl, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetAssetDownloadUrlGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetAssetDownloadUrlGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetAssetDownloadUrlResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetAssetDownloadUrlResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetAssetUploadUrlAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetAssetUploadUrlRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetAssetUploadUrl, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetAssetUploadUrlGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetAssetUploadUrlGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetAssetUploadUrlResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetAssetUploadUrlResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetBuildAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetBuildRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetBuild, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetBuildGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetBuildGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetBuildResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetBuildResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetBuildAliasAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetBuildAliasRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetBuildAlias, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetBuildAliasGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetBuildAliasGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerBuildAliasDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerBuildAliasDetailsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetContainerRegistryCredentialsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetContainerRegistryCredentialsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetContainerRegistryCredentials, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetContainerRegistryCredentialsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetContainerRegistryCredentialsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetContainerRegistryCredentialsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetContainerRegistryCredentialsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetMultiplayerServerDetailsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetMultiplayerServerDetailsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetMultiplayerServerDetails, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetMultiplayerServerDetailsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetMultiplayerServerDetailsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetMultiplayerServerDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetMultiplayerServerDetailsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetMultiplayerServerLogsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetMultiplayerServerLogsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetMultiplayerServerLogs, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetMultiplayerServerLogsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetMultiplayerServerLogsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetMultiplayerServerLogsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetMultiplayerServerLogsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetMultiplayerSessionLogsBySessionId, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetMultiplayerServerLogsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetMultiplayerServerLogsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetRemoteLoginEndpointAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetRemoteLoginEndpointRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetRemoteLoginEndpoint, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetRemoteLoginEndpointGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetRemoteLoginEndpointGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetRemoteLoginEndpointResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetRemoteLoginEndpointResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetTitleEnabledForMultiplayerServersStatus, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetTitleMultiplayerServersQuotaChange, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotasAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::GetTitleMultiplayerServersQuotas, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListArchivedMultiplayerServersAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListMultiplayerServersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListArchivedMultiplayerServers, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListArchivedMultiplayerServersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListArchivedMultiplayerServersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListMultiplayerServersResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListMultiplayerServersResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListAssetSummariesAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListAssetSummariesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListAssetSummaries, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListAssetSummariesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListAssetSummariesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListAssetSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListAssetSummariesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListBuildAliasesAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListBuildAliasesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListBuildAliases, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListBuildAliasesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListBuildAliasesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListBuildAliasesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListBuildAliasesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListBuildSummariesV2Async(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListBuildSummariesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListBuildSummariesV2, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListBuildSummariesV2GetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListBuildSummariesV2GetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListBuildSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListBuildSummariesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListCertificateSummariesAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListCertificateSummariesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListCertificateSummaries, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListCertificateSummariesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListCertificateSummariesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListCertificateSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListCertificateSummariesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListContainerImagesAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListContainerImagesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListContainerImages, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListContainerImagesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListContainerImagesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListContainerImagesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListContainerImagesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListContainerImageTagsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListContainerImageTagsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListContainerImageTags, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListContainerImageTagsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListContainerImageTagsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListContainerImageTagsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListContainerImageTagsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListMultiplayerServersAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListMultiplayerServersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListMultiplayerServers, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListMultiplayerServersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListMultiplayerServersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListMultiplayerServersResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListMultiplayerServersResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListPartyQosServersAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFMultiplayerServerListPartyQosServersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListPartyQosServers, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListPartyQosServersGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListPartyQosServersGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListPartyQosServersResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListPartyQosServersResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListQosServersForTitleAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListQosServersForTitleRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListQosServersForTitle, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListQosServersForTitleGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListQosServersForTitleGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListQosServersForTitleResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListQosServersForTitleResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListTitleMultiplayerServersQuotaChangesAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListTitleMultiplayerServersQuotaChanges, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerListVirtualMachineSummariesAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerListVirtualMachineSummariesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ListVirtualMachineSummaries, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerListVirtualMachineSummariesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerListVirtualMachineSummariesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListVirtualMachineSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerListVirtualMachineSummariesResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerRequestMultiplayerServerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerRequestMultiplayerServerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::RequestMultiplayerServer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerRequestMultiplayerServerGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerRequestMultiplayerServerGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerRequestMultiplayerServerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerRequestMultiplayerServerResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerRolloverContainerRegistryCredentialsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerRolloverContainerRegistryCredentialsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::RolloverContainerRegistryCredentials, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerRolloverContainerRegistryCredentialsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerRolloverContainerRegistryCredentialsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerRolloverContainerRegistryCredentialsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerRolloverContainerRegistryCredentialsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerShutdownMultiplayerServerAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerShutdownMultiplayerServerRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::ShutdownMultiplayerServer, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerUntagContainerImageAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerUntagContainerImageRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::UntagContainerImage, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerUpdateBuildAliasAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerUpdateBuildAliasRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::UpdateBuildAlias, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerUpdateBuildAliasGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFMultiplayerServerUpdateBuildAliasGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerBuildAliasDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFMultiplayerServerBuildAliasDetailsResponse*>(buffer);

    return S_OK;
}

HRESULT PFMultiplayerServerUpdateBuildNameAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerUpdateBuildNameRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::UpdateBuildName, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerUpdateBuildRegionAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerUpdateBuildRegionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::UpdateBuildRegion, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerUpdateBuildRegionsAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerUpdateBuildRegionsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::UpdateBuildRegions, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFMultiplayerServerUploadCertificateAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFMultiplayerServerUploadCertificateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&MultiplayerServerAPI::UploadCertificate, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

