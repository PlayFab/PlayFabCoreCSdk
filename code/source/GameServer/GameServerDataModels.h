#pragma once

#include <playfab/cpp/PFGameServerDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace GameServer
{

// GameServer Classes
class ModifyServerBuildRequest : public Wrappers::PFGameServerModifyServerBuildRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerModifyServerBuildRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGameServerModifyServerBuildRequest& input);

};

class ModifyServerBuildResult : public Wrappers::PFGameServerModifyServerBuildResultWrapper<Allocator>, public OutputModel<PFGameServerModifyServerBuildResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerModifyServerBuildResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGameServerModifyServerBuildResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGameServerModifyServerBuildResult& model);
    static HRESULT Copy(const PFGameServerModifyServerBuildResult& input, PFGameServerModifyServerBuildResult& output, ModelBuffer& buffer);
};

} // namespace GameServer
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
