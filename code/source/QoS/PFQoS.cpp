#include "stdafx.h"
#include <playfab/PFQoS.h>
#include "QoS.h"
#include "ApiAsyncProviders.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::QoS;

HRESULT PFQoSGetMeasurementsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ uint32_t pingIterations,
    _In_ uint32_t timeoutMs,
    _Inout_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(entityHandle);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&QoSAPI::GetMeasurements, entityHandle->entity->QoSAPI().get(), entityHandle->entity, pingIterations, timeoutMs, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFQoSGetMeasurementsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFQoSGetMeasurementsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFQoSMeasurements** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFQoSMeasurements*>(buffer);

    return S_OK;
}