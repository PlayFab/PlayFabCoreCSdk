#pragma once

#include <playfab/cpp/PFProfilesDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Profiles
{

// Profiles Classes
class GetGlobalPolicyRequest : public Wrappers::PFProfilesGetGlobalPolicyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetGlobalPolicyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesGetGlobalPolicyRequest& input);

};

class EntityPermissionStatement : public Wrappers::PFProfilesEntityPermissionStatementWrapper<Allocator>, public InputModel, public OutputModel<PFProfilesEntityPermissionStatement>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesEntityPermissionStatementWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesEntityPermissionStatement& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesEntityPermissionStatement const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesEntityPermissionStatement& model);
    static HRESULT Copy(const PFProfilesEntityPermissionStatement& input, PFProfilesEntityPermissionStatement& output, ModelBuffer& buffer);
};

class GetGlobalPolicyResponse : public Wrappers::PFProfilesGetGlobalPolicyResponseWrapper<Allocator>, public OutputModel<PFProfilesGetGlobalPolicyResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetGlobalPolicyResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesGetGlobalPolicyResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesGetGlobalPolicyResponse& model);
    static HRESULT Copy(const PFProfilesGetGlobalPolicyResponse& input, PFProfilesGetGlobalPolicyResponse& output, ModelBuffer& buffer);
};

class GetEntityProfileRequest : public Wrappers::PFProfilesGetEntityProfileRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetEntityProfileRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesGetEntityProfileRequest& input);

};

class EntityProfileFileMetadata : public Wrappers::PFProfilesEntityProfileFileMetadataWrapper<Allocator>, public OutputModel<PFProfilesEntityProfileFileMetadata>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesEntityProfileFileMetadataWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesEntityProfileFileMetadata const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesEntityProfileFileMetadata& model);
    static HRESULT Copy(const PFProfilesEntityProfileFileMetadata& input, PFProfilesEntityProfileFileMetadata& output, ModelBuffer& buffer);
};

class EntityDataObject : public Wrappers::PFProfilesEntityDataObjectWrapper<Allocator>, public OutputModel<PFProfilesEntityDataObject>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesEntityDataObjectWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesEntityDataObject const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesEntityDataObject& model);
    static HRESULT Copy(const PFProfilesEntityDataObject& input, PFProfilesEntityDataObject& output, ModelBuffer& buffer);
};

class EntityStatisticChildValue : public Wrappers::PFProfilesEntityStatisticChildValueWrapper<Allocator>, public OutputModel<PFProfilesEntityStatisticChildValue>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesEntityStatisticChildValueWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesEntityStatisticChildValue const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesEntityStatisticChildValue& model);
    static HRESULT Copy(const PFProfilesEntityStatisticChildValue& input, PFProfilesEntityStatisticChildValue& output, ModelBuffer& buffer);
};

class EntityStatisticValue : public Wrappers::PFProfilesEntityStatisticValueWrapper<Allocator>, public OutputModel<PFProfilesEntityStatisticValue>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesEntityStatisticValueWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesEntityStatisticValue const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesEntityStatisticValue& model);
    static HRESULT Copy(const PFProfilesEntityStatisticValue& input, PFProfilesEntityStatisticValue& output, ModelBuffer& buffer);
};

class EntityProfileBody : public Wrappers::PFProfilesEntityProfileBodyWrapper<Allocator>, public OutputModel<PFProfilesEntityProfileBody>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesEntityProfileBodyWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesEntityProfileBody const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesEntityProfileBody& model);
    static HRESULT Copy(const PFProfilesEntityProfileBody& input, PFProfilesEntityProfileBody& output, ModelBuffer& buffer);
};

class GetEntityProfileResponse : public Wrappers::PFProfilesGetEntityProfileResponseWrapper<Allocator>, public OutputModel<PFProfilesGetEntityProfileResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetEntityProfileResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesGetEntityProfileResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesGetEntityProfileResponse& model);
    static HRESULT Copy(const PFProfilesGetEntityProfileResponse& input, PFProfilesGetEntityProfileResponse& output, ModelBuffer& buffer);
};

class GetEntityProfilesRequest : public Wrappers::PFProfilesGetEntityProfilesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetEntityProfilesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesGetEntityProfilesRequest& input);

};

class GetEntityProfilesResponse : public Wrappers::PFProfilesGetEntityProfilesResponseWrapper<Allocator>, public OutputModel<PFProfilesGetEntityProfilesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetEntityProfilesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesGetEntityProfilesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesGetEntityProfilesResponse& model);
    static HRESULT Copy(const PFProfilesGetEntityProfilesResponse& input, PFProfilesGetEntityProfilesResponse& output, ModelBuffer& buffer);
};

class GetTitlePlayersFromMasterPlayerAccountIdsRequest : public Wrappers::PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequest& input);

};

class GetTitlePlayersFromMasterPlayerAccountIdsResponse : public Wrappers::PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper<Allocator>, public OutputModel<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& model);
    static HRESULT Copy(const PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& input, PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse& output, ModelBuffer& buffer);
};

class SetGlobalPolicyRequest : public Wrappers::PFProfilesSetGlobalPolicyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesSetGlobalPolicyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesSetGlobalPolicyRequest& input);

};

class SetProfileLanguageRequest : public Wrappers::PFProfilesSetProfileLanguageRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesSetProfileLanguageRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesSetProfileLanguageRequest& input);

};

class SetProfileLanguageResponse : public Wrappers::PFProfilesSetProfileLanguageResponseWrapper<Allocator>, public OutputModel<PFProfilesSetProfileLanguageResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesSetProfileLanguageResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesSetProfileLanguageResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesSetProfileLanguageResponse& model);
    static HRESULT Copy(const PFProfilesSetProfileLanguageResponse& input, PFProfilesSetProfileLanguageResponse& output, ModelBuffer& buffer);
};

class SetEntityProfilePolicyRequest : public Wrappers::PFProfilesSetEntityProfilePolicyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesSetEntityProfilePolicyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFProfilesSetEntityProfilePolicyRequest& input);

};

class SetEntityProfilePolicyResponse : public Wrappers::PFProfilesSetEntityProfilePolicyResponseWrapper<Allocator>, public OutputModel<PFProfilesSetEntityProfilePolicyResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFProfilesSetEntityProfilePolicyResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFProfilesSetEntityProfilePolicyResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFProfilesSetEntityProfilePolicyResponse& model);
    static HRESULT Copy(const PFProfilesSetEntityProfilePolicyResponse& input, PFProfilesSetEntityProfilePolicyResponse& output, ModelBuffer& buffer);
};

} // namespace Profiles
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
