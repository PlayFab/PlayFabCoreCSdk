#pragma once

#include <playfab/cpp/PFLocalizationDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Localization
{

// Localization Classes
class GetLanguageListRequest : public Wrappers::PFLocalizationGetLanguageListRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFLocalizationGetLanguageListRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFLocalizationGetLanguageListRequest& input);

};

class GetLanguageListResponse : public Wrappers::PFLocalizationGetLanguageListResponseWrapper<Allocator>, public OutputModel<PFLocalizationGetLanguageListResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFLocalizationGetLanguageListResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFLocalizationGetLanguageListResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFLocalizationGetLanguageListResponse& model);
    static HRESULT Copy(const PFLocalizationGetLanguageListResponse& input, PFLocalizationGetLanguageListResponse& output, ModelBuffer& buffer);
};

} // namespace Localization
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
