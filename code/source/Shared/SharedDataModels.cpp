#include "stdafx.h"
#include "SharedDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{

JsonValue EntityKey::ToJson() const
{
    return EntityKey::ToJson(this->Model());
}

JsonValue EntityKey::ToJson(const PFEntityKey& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

void EntityKey::FromJson(const JsonValue& input)
{
    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));
}

size_t EntityKey::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFEntityKey const*> EntityKey::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EntityKey>(&this->Model());
}

size_t EntityKey::RequiredBufferSize(const PFEntityKey& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.type)
    {
        requiredSize += (std::strlen(model.type) + 1);
    }
    return requiredSize;
}

HRESULT EntityKey::Copy(const PFEntityKey& input, PFEntityKey& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Port::ToJson() const
{
    return Port::ToJson(this->Model());
}

JsonValue Port::ToJson(const PFPort& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "Num", input.num);
    JsonUtils::ObjectAddMember(output, "Protocol", input.protocol);
    return output;
}

void Port::FromJson(const JsonValue& input)
{
    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    JsonUtils::ObjectGetMember(input, "Num", this->m_model.num);

    JsonUtils::ObjectGetMember(input, "Protocol", this->m_model.protocol);
}

size_t Port::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPort const*> Port::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Port>(&this->Model());
}

size_t Port::RequiredBufferSize(const PFPort& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    return requiredSize;
}

HRESULT Port::Copy(const PFPort& input, PFPort& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace PlayFab
