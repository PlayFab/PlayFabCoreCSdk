#pragma once

#include <playfab/cpp/PFGameServerDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace GameServer
{

// GameServer Classes
class AddServerBuildRequest : public Wrappers::PFGameServerAddServerBuildRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerAddServerBuildRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGameServerAddServerBuildRequest& input);

};

class AddServerBuildResult : public Wrappers::PFGameServerAddServerBuildResultWrapper<Allocator>, public OutputModel<PFGameServerAddServerBuildResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerAddServerBuildResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGameServerAddServerBuildResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGameServerAddServerBuildResult& model);
    static HRESULT Copy(const PFGameServerAddServerBuildResult& input, PFGameServerAddServerBuildResult& output, ModelBuffer& buffer);
};

class GetServerBuildInfoRequest : public Wrappers::PFGameServerGetServerBuildInfoRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerGetServerBuildInfoRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGameServerGetServerBuildInfoRequest& input);

};

class GetServerBuildInfoResult : public Wrappers::PFGameServerGetServerBuildInfoResultWrapper<Allocator>, public OutputModel<PFGameServerGetServerBuildInfoResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerGetServerBuildInfoResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGameServerGetServerBuildInfoResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGameServerGetServerBuildInfoResult& model);
    static HRESULT Copy(const PFGameServerGetServerBuildInfoResult& input, PFGameServerGetServerBuildInfoResult& output, ModelBuffer& buffer);
};

class GetServerBuildUploadURLRequest : public Wrappers::PFGameServerGetServerBuildUploadURLRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerGetServerBuildUploadURLRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGameServerGetServerBuildUploadURLRequest& input);

};

class GetServerBuildUploadURLResult : public Wrappers::PFGameServerGetServerBuildUploadURLResultWrapper<Allocator>, public OutputModel<PFGameServerGetServerBuildUploadURLResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerGetServerBuildUploadURLResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGameServerGetServerBuildUploadURLResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGameServerGetServerBuildUploadURLResult& model);
    static HRESULT Copy(const PFGameServerGetServerBuildUploadURLResult& input, PFGameServerGetServerBuildUploadURLResult& output, ModelBuffer& buffer);
};

class ListBuildsResult : public Wrappers::PFGameServerListBuildsResultWrapper<Allocator>, public OutputModel<PFGameServerListBuildsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerListBuildsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFGameServerListBuildsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFGameServerListBuildsResult& model);
    static HRESULT Copy(const PFGameServerListBuildsResult& input, PFGameServerListBuildsResult& output, ModelBuffer& buffer);
};

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

class RemoveServerBuildRequest : public Wrappers::PFGameServerRemoveServerBuildRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFGameServerRemoveServerBuildRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFGameServerRemoveServerBuildRequest& input);

};

} // namespace GameServer
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
