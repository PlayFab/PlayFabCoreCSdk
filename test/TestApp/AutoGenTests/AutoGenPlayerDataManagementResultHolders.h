#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetDataReportResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetDataReportResultHolder>
{
    GetDataReportResultHolder() = default;
    GetDataReportResultHolder(const GetDataReportResultHolder&) = delete;
    GetDataReportResultHolder(GetDataReportResultHolder&&) = default;
    GetDataReportResultHolder& operator=(const GetDataReportResultHolder&) = delete;
    GetDataReportResultHolder& operator=(GetDataReportResultHolder&&) = default;
    ~GetDataReportResultHolder() = default;

    PFPlayerDataManagementGetDataReportResult* result{ nullptr };
};

struct AdminGetUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<AdminGetUserDataResultHolder>
{
    AdminGetUserDataResultHolder() = default;
    AdminGetUserDataResultHolder(const AdminGetUserDataResultHolder&) = delete;
    AdminGetUserDataResultHolder(AdminGetUserDataResultHolder&&) = default;
    AdminGetUserDataResultHolder& operator=(const AdminGetUserDataResultHolder&) = delete;
    AdminGetUserDataResultHolder& operator=(AdminGetUserDataResultHolder&&) = default;
    ~AdminGetUserDataResultHolder() = default;

    PFPlayerDataManagementAdminGetUserDataResult* result{ nullptr };
};

struct UpdateUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateUserDataResultHolder>
{
    UpdateUserDataResultHolder() = default;
    UpdateUserDataResultHolder(const UpdateUserDataResultHolder&) = default;
    UpdateUserDataResultHolder(UpdateUserDataResultHolder&&) = default;
    UpdateUserDataResultHolder& operator=(const UpdateUserDataResultHolder&) = default;
    UpdateUserDataResultHolder& operator=(UpdateUserDataResultHolder&&) = default;
    ~UpdateUserDataResultHolder() = default;

    PFPlayerDataManagementUpdateUserDataResult result{};
};

struct ClientGetUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetUserDataResultHolder>
{
    ClientGetUserDataResultHolder() = default;
    ClientGetUserDataResultHolder(const ClientGetUserDataResultHolder&) = delete;
    ClientGetUserDataResultHolder(ClientGetUserDataResultHolder&&) = default;
    ClientGetUserDataResultHolder& operator=(const ClientGetUserDataResultHolder&) = delete;
    ClientGetUserDataResultHolder& operator=(ClientGetUserDataResultHolder&&) = default;
    ~ClientGetUserDataResultHolder() = default;

    PFPlayerDataManagementClientGetUserDataResult* result{ nullptr };
};

struct ServerGetUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetUserDataResultHolder>
{
    ServerGetUserDataResultHolder() = default;
    ServerGetUserDataResultHolder(const ServerGetUserDataResultHolder&) = delete;
    ServerGetUserDataResultHolder(ServerGetUserDataResultHolder&&) = default;
    ServerGetUserDataResultHolder& operator=(const ServerGetUserDataResultHolder&) = delete;
    ServerGetUserDataResultHolder& operator=(ServerGetUserDataResultHolder&&) = default;
    ~ServerGetUserDataResultHolder() = default;

    PFPlayerDataManagementServerGetUserDataResult* result{ nullptr };
};


}
