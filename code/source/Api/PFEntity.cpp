#include "stdafx.h"
#include <playfab/PFEntity.h>
#include "Entity.h"
#include "ApiAsyncProviders.h"

using namespace PlayFab;

HRESULT PFEntityDuplicateHandle(
    _In_ PFEntityHandle entityHandle,
    _Out_ PFEntityHandle* duplicatedEntityHandle
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);
    RETURN_HR_INVALIDARG_IF_NULL(duplicatedEntityHandle);

    *duplicatedEntityHandle = MakeUnique<PFEntity>(*entityHandle).release();
    return S_OK;
}

void PFEntityCloseHandle(
    _In_ PFEntityHandle entityHandle
) noexcept
{
    UniquePtr<PFEntity>{ entityHandle };
}

HRESULT PFEntityRegisterTokenRefreshedCallback(
    _In_ PFEntityHandle entityHandle,
    _In_ XTaskQueueHandle queue,
    _In_ PFEntityTokenRefreshedCallback* callback,
    _In_opt_ void* context,
    _Out_ PFRegistrationToken* token
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);
    RETURN_HR_INVALIDARG_IF_NULL(callback);
    RETURN_HR_INVALIDARG_IF_NULL(token);

    *token = entityHandle->entity->TokenRefreshedCallbacks.Register(queue, [callback, context](SharedPtr<EntityToken const> newToken)
        {
            callback(newToken.get(), context);
        });

    return S_OK;
}

HRESULT PFEntityUnregisterTokenRefreshedCallback(
    _In_ PFEntityHandle entityHandle,
    _In_ PFRegistrationToken token
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);

    entityHandle->entity->TokenRefreshedCallbacks.Unregister(token);
    return S_OK;
}

HRESULT PFEntityGetEntityTokenAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFAuthenticationGetEntityTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&Entity::GetEntityToken, entityHandle->entity.get(), *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFEntityGetEntityTokenGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFEntityHandle* entityHandle
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFEntityHandle), entityHandle, nullptr);
}

HRESULT PFEntityGetEntityKeySize(
    _In_ PFEntityHandle entityHandle,
    _Out_ size_t* bufferSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);
    RETURN_HR_INVALIDARG_IF_NULL(bufferSize);

    *bufferSize = entityHandle->entity->EntityKey().RequiredBufferSize();
    return S_OK;
}

HRESULT PFEntityGetEntityKey(
    _In_ PFEntityHandle entityHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityKey** entityKey,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);
    RETURN_HR_INVALIDARG_IF_NULL(buffer);
    RETURN_HR_INVALIDARG_IF_NULL(entityKey);

    ModelBuffer b{ buffer, bufferSize };
    auto copyResult = entityHandle->entity->EntityKey().Copy(b);
    RETURN_IF_FAILED(copyResult.hr);
    *entityKey = copyResult.ExtractPayload();
    if (bufferUsed)
    {
        *bufferUsed = bufferSize - b.RemainingSpace();
    }
    
    return S_OK;
}

HRESULT PFEntityGetCachedEntityTokenSize(
    _In_ PFEntityHandle entityHandle,
    _Out_ size_t* bufferSize
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);
    RETURN_HR_INVALIDARG_IF_NULL(bufferSize);

    *bufferSize = entityHandle->entity->EntityToken()->RequiredBufferSize();
    return S_OK;
}

HRESULT PFEntityGetCachedEntityToken(
    _In_ PFEntityHandle entityHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityToken** entityToken,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);
    RETURN_HR_INVALIDARG_IF_NULL(buffer);
    RETURN_HR_INVALIDARG_IF_NULL(entityToken);

    ModelBuffer b{ buffer, bufferSize };
    auto copyResult = entityHandle->entity->EntityToken()->Copy(b);
    RETURN_IF_FAILED(copyResult.hr);
    *entityToken = copyResult.ExtractPayload();
    if (bufferUsed)
    {
        *bufferUsed = bufferSize - b.RemainingSpace();
    }

    return S_OK;
}
