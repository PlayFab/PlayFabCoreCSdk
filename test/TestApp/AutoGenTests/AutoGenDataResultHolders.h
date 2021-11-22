#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AbortFileUploadsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<AbortFileUploadsResponseHolder>
{
    AbortFileUploadsResponseHolder() = default;
    AbortFileUploadsResponseHolder(const AbortFileUploadsResponseHolder&) = delete;
    AbortFileUploadsResponseHolder(AbortFileUploadsResponseHolder&&) = default;
    AbortFileUploadsResponseHolder& operator=(const AbortFileUploadsResponseHolder&) = delete;
    AbortFileUploadsResponseHolder& operator=(AbortFileUploadsResponseHolder&&) = default;
    ~AbortFileUploadsResponseHolder() = default;

    PFDataAbortFileUploadsResponse* result{ nullptr };
};

struct DeleteFilesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<DeleteFilesResponseHolder>
{
    DeleteFilesResponseHolder() = default;
    DeleteFilesResponseHolder(const DeleteFilesResponseHolder&) = delete;
    DeleteFilesResponseHolder(DeleteFilesResponseHolder&&) = default;
    DeleteFilesResponseHolder& operator=(const DeleteFilesResponseHolder&) = delete;
    DeleteFilesResponseHolder& operator=(DeleteFilesResponseHolder&&) = default;
    ~DeleteFilesResponseHolder() = default;

    PFDataDeleteFilesResponse* result{ nullptr };
};

struct FinalizeFileUploadsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<FinalizeFileUploadsResponseHolder>
{
    FinalizeFileUploadsResponseHolder() = default;
    FinalizeFileUploadsResponseHolder(const FinalizeFileUploadsResponseHolder&) = delete;
    FinalizeFileUploadsResponseHolder(FinalizeFileUploadsResponseHolder&&) = default;
    FinalizeFileUploadsResponseHolder& operator=(const FinalizeFileUploadsResponseHolder&) = delete;
    FinalizeFileUploadsResponseHolder& operator=(FinalizeFileUploadsResponseHolder&&) = default;
    ~FinalizeFileUploadsResponseHolder() = default;

    PFDataFinalizeFileUploadsResponse* result{ nullptr };
};

struct GetFilesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetFilesResponseHolder>
{
    GetFilesResponseHolder() = default;
    GetFilesResponseHolder(const GetFilesResponseHolder&) = delete;
    GetFilesResponseHolder(GetFilesResponseHolder&&) = default;
    GetFilesResponseHolder& operator=(const GetFilesResponseHolder&) = delete;
    GetFilesResponseHolder& operator=(GetFilesResponseHolder&&) = default;
    ~GetFilesResponseHolder() = default;

    PFDataGetFilesResponse* result{ nullptr };
};

struct GetObjectsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetObjectsResponseHolder>
{
    GetObjectsResponseHolder() = default;
    GetObjectsResponseHolder(const GetObjectsResponseHolder&) = delete;
    GetObjectsResponseHolder(GetObjectsResponseHolder&&) = default;
    GetObjectsResponseHolder& operator=(const GetObjectsResponseHolder&) = delete;
    GetObjectsResponseHolder& operator=(GetObjectsResponseHolder&&) = default;
    ~GetObjectsResponseHolder() = default;

    PFDataGetObjectsResponse* result{ nullptr };
};

struct InitiateFileUploadsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InitiateFileUploadsResponseHolder>
{
    InitiateFileUploadsResponseHolder() = default;
    InitiateFileUploadsResponseHolder(const InitiateFileUploadsResponseHolder&) = delete;
    InitiateFileUploadsResponseHolder(InitiateFileUploadsResponseHolder&&) = default;
    InitiateFileUploadsResponseHolder& operator=(const InitiateFileUploadsResponseHolder&) = delete;
    InitiateFileUploadsResponseHolder& operator=(InitiateFileUploadsResponseHolder&&) = default;
    ~InitiateFileUploadsResponseHolder() = default;

    PFDataInitiateFileUploadsResponse* result{ nullptr };
};

struct SetObjectsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<SetObjectsResponseHolder>
{
    SetObjectsResponseHolder() = default;
    SetObjectsResponseHolder(const SetObjectsResponseHolder&) = delete;
    SetObjectsResponseHolder(SetObjectsResponseHolder&&) = default;
    SetObjectsResponseHolder& operator=(const SetObjectsResponseHolder&) = delete;
    SetObjectsResponseHolder& operator=(SetObjectsResponseHolder&&) = default;
    ~SetObjectsResponseHolder() = default;

    PFDataSetObjectsResponse* result{ nullptr };
};


}
