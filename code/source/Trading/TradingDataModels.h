#pragma once

#include <playfab/cpp/PFTradingDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Trading
{

// Trading Classes
class AcceptTradeRequest : public Wrappers::PFTradingAcceptTradeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingAcceptTradeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTradingAcceptTradeRequest& input);

};

class TradeInfo : public Wrappers::PFTradingTradeInfoWrapper<Allocator>, public OutputModel<PFTradingTradeInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingTradeInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTradingTradeInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTradingTradeInfo& model);
    static HRESULT Copy(const PFTradingTradeInfo& input, PFTradingTradeInfo& output, ModelBuffer& buffer);
};

class AcceptTradeResponse : public Wrappers::PFTradingAcceptTradeResponseWrapper<Allocator>, public OutputModel<PFTradingAcceptTradeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingAcceptTradeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTradingAcceptTradeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTradingAcceptTradeResponse& model);
    static HRESULT Copy(const PFTradingAcceptTradeResponse& input, PFTradingAcceptTradeResponse& output, ModelBuffer& buffer);
};

class CancelTradeRequest : public Wrappers::PFTradingCancelTradeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingCancelTradeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTradingCancelTradeRequest& input);

};

class CancelTradeResponse : public Wrappers::PFTradingCancelTradeResponseWrapper<Allocator>, public OutputModel<PFTradingCancelTradeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingCancelTradeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTradingCancelTradeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTradingCancelTradeResponse& model);
    static HRESULT Copy(const PFTradingCancelTradeResponse& input, PFTradingCancelTradeResponse& output, ModelBuffer& buffer);
};

class GetPlayerTradesRequest : public Wrappers::PFTradingGetPlayerTradesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingGetPlayerTradesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTradingGetPlayerTradesRequest& input);

};

class GetPlayerTradesResponse : public Wrappers::PFTradingGetPlayerTradesResponseWrapper<Allocator>, public OutputModel<PFTradingGetPlayerTradesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingGetPlayerTradesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTradingGetPlayerTradesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTradingGetPlayerTradesResponse& model);
    static HRESULT Copy(const PFTradingGetPlayerTradesResponse& input, PFTradingGetPlayerTradesResponse& output, ModelBuffer& buffer);
};

class GetTradeStatusRequest : public Wrappers::PFTradingGetTradeStatusRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingGetTradeStatusRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTradingGetTradeStatusRequest& input);

};

class GetTradeStatusResponse : public Wrappers::PFTradingGetTradeStatusResponseWrapper<Allocator>, public OutputModel<PFTradingGetTradeStatusResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingGetTradeStatusResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTradingGetTradeStatusResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTradingGetTradeStatusResponse& model);
    static HRESULT Copy(const PFTradingGetTradeStatusResponse& input, PFTradingGetTradeStatusResponse& output, ModelBuffer& buffer);
};

class OpenTradeRequest : public Wrappers::PFTradingOpenTradeRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingOpenTradeRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFTradingOpenTradeRequest& input);

};

class OpenTradeResponse : public Wrappers::PFTradingOpenTradeResponseWrapper<Allocator>, public OutputModel<PFTradingOpenTradeResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFTradingOpenTradeResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFTradingOpenTradeResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFTradingOpenTradeResponse& model);
    static HRESULT Copy(const PFTradingOpenTradeResponse& input, PFTradingOpenTradeResponse& output, ModelBuffer& buffer);
};

} // namespace Trading
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
