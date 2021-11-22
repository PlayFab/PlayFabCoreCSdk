#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetContentListResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetContentListResultHolder>
{
    GetContentListResultHolder() = default;
    GetContentListResultHolder(const GetContentListResultHolder&) = delete;
    GetContentListResultHolder(GetContentListResultHolder&&) = default;
    GetContentListResultHolder& operator=(const GetContentListResultHolder&) = delete;
    GetContentListResultHolder& operator=(GetContentListResultHolder&&) = default;
    ~GetContentListResultHolder() = default;

    PFContentGetContentListResult* result{ nullptr };
};

struct GetContentUploadUrlResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetContentUploadUrlResultHolder>
{
    GetContentUploadUrlResultHolder() = default;
    GetContentUploadUrlResultHolder(const GetContentUploadUrlResultHolder&) = delete;
    GetContentUploadUrlResultHolder(GetContentUploadUrlResultHolder&&) = default;
    GetContentUploadUrlResultHolder& operator=(const GetContentUploadUrlResultHolder&) = delete;
    GetContentUploadUrlResultHolder& operator=(GetContentUploadUrlResultHolder&&) = default;
    ~GetContentUploadUrlResultHolder() = default;

    PFContentGetContentUploadUrlResult* result{ nullptr };
};

struct GetContentDownloadUrlResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetContentDownloadUrlResultHolder>
{
    GetContentDownloadUrlResultHolder() = default;
    GetContentDownloadUrlResultHolder(const GetContentDownloadUrlResultHolder&) = delete;
    GetContentDownloadUrlResultHolder(GetContentDownloadUrlResultHolder&&) = default;
    GetContentDownloadUrlResultHolder& operator=(const GetContentDownloadUrlResultHolder&) = delete;
    GetContentDownloadUrlResultHolder& operator=(GetContentDownloadUrlResultHolder&&) = default;
    ~GetContentDownloadUrlResultHolder() = default;

    PFContentGetContentDownloadUrlResult* result{ nullptr };
};


}
