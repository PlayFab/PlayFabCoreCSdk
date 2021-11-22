#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetLanguageListResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetLanguageListResponseHolder>
{
    GetLanguageListResponseHolder() = default;
    GetLanguageListResponseHolder(const GetLanguageListResponseHolder&) = delete;
    GetLanguageListResponseHolder(GetLanguageListResponseHolder&&) = default;
    GetLanguageListResponseHolder& operator=(const GetLanguageListResponseHolder&) = delete;
    GetLanguageListResponseHolder& operator=(GetLanguageListResponseHolder&&) = default;
    ~GetLanguageListResponseHolder() = default;

    PFLocalizationGetLanguageListResponse* result{ nullptr };
};


}
