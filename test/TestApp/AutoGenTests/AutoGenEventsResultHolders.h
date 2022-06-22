#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


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
