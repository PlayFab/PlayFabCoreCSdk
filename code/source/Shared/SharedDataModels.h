#pragma once

#include <playfab/cpp/PFSharedDataModelWrappers.h>
#include "BaseModel.h"

namespace PlayFab
{

// Shared Classes
class EntityKey : public Wrappers::PFEntityKeyWrapper<Allocator>, public InputModel, public ServiceOutputModel, public ClientOutputModel<PFEntityKey>
{
public:
    using ModelWrapperType = typename Wrappers::PFEntityKeyWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFEntityKey& input);
    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFEntityKey const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFEntityKey& model);
    static HRESULT Copy(const PFEntityKey& input, PFEntityKey& output, ModelBuffer& buffer);
};

class Port : public Wrappers::PFPortWrapper<Allocator>, public InputModel, public ServiceOutputModel, public ClientOutputModel<PFPort>
{
public:
    using ModelWrapperType = typename Wrappers::PFPortWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFPort& input);
    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFPort const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFPort& model);
    static HRESULT Copy(const PFPort& input, PFPort& output, ModelBuffer& buffer);
};

// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
