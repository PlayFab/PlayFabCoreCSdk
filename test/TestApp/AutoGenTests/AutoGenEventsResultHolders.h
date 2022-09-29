#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetPlayerTagsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerTagsResultHolder>
{
    GetPlayerTagsResultHolder() = default;
    GetPlayerTagsResultHolder(const GetPlayerTagsResultHolder&) = delete;
    GetPlayerTagsResultHolder(GetPlayerTagsResultHolder&&) = default;
    GetPlayerTagsResultHolder& operator=(const GetPlayerTagsResultHolder&) = delete;
    GetPlayerTagsResultHolder& operator=(GetPlayerTagsResultHolder&&) = default;
    ~GetPlayerTagsResultHolder() = default;

    PFEventsGetPlayerTagsResult* result{ nullptr };
};

struct WriteEventResponseHolder : public XAsyncResult, public std::enable_shared_from_this<WriteEventResponseHolder>
{
    WriteEventResponseHolder() = default;
    WriteEventResponseHolder(const WriteEventResponseHolder&) = delete;
    WriteEventResponseHolder(WriteEventResponseHolder&&) = default;
    WriteEventResponseHolder& operator=(const WriteEventResponseHolder&) = delete;
    WriteEventResponseHolder& operator=(WriteEventResponseHolder&&) = default;
    ~WriteEventResponseHolder() = default;

    PFEventsWriteEventResponse* result{ nullptr };
};

struct WriteEventsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<WriteEventsResponseHolder>
{
    WriteEventsResponseHolder() = default;
    WriteEventsResponseHolder(const WriteEventsResponseHolder&) = delete;
    WriteEventsResponseHolder(WriteEventsResponseHolder&&) = default;
    WriteEventsResponseHolder& operator=(const WriteEventsResponseHolder&) = delete;
    WriteEventsResponseHolder& operator=(WriteEventsResponseHolder&&) = default;
    ~WriteEventsResponseHolder() = default;

    PFEventsWriteEventsResponse* result{ nullptr };
};


}
