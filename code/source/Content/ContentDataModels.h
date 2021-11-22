#pragma once

#include <playfab/cpp/PFContentDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Content
{

// Content Classes
class DeleteContentRequest : public Wrappers::PFContentDeleteContentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFContentDeleteContentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFContentDeleteContentRequest& input);

};

class GetContentListRequest : public Wrappers::PFContentGetContentListRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFContentGetContentListRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFContentGetContentListRequest& input);

};

class ContentInfo : public Wrappers::PFContentContentInfoWrapper<Allocator>, public OutputModel<PFContentContentInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFContentContentInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFContentContentInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFContentContentInfo& model);
    static HRESULT Copy(const PFContentContentInfo& input, PFContentContentInfo& output, ModelBuffer& buffer);
};

class GetContentListResult : public Wrappers::PFContentGetContentListResultWrapper<Allocator>, public OutputModel<PFContentGetContentListResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFContentGetContentListResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFContentGetContentListResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFContentGetContentListResult& model);
    static HRESULT Copy(const PFContentGetContentListResult& input, PFContentGetContentListResult& output, ModelBuffer& buffer);
};

class GetContentUploadUrlRequest : public Wrappers::PFContentGetContentUploadUrlRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFContentGetContentUploadUrlRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFContentGetContentUploadUrlRequest& input);

};

class GetContentUploadUrlResult : public Wrappers::PFContentGetContentUploadUrlResultWrapper<Allocator>, public OutputModel<PFContentGetContentUploadUrlResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFContentGetContentUploadUrlResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFContentGetContentUploadUrlResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFContentGetContentUploadUrlResult& model);
    static HRESULT Copy(const PFContentGetContentUploadUrlResult& input, PFContentGetContentUploadUrlResult& output, ModelBuffer& buffer);
};

class GetContentDownloadUrlRequest : public Wrappers::PFContentGetContentDownloadUrlRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFContentGetContentDownloadUrlRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFContentGetContentDownloadUrlRequest& input);

};

class GetContentDownloadUrlResult : public Wrappers::PFContentGetContentDownloadUrlResultWrapper<Allocator>, public OutputModel<PFContentGetContentDownloadUrlResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFContentGetContentDownloadUrlResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFContentGetContentDownloadUrlResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFContentGetContentDownloadUrlResult& model);
    static HRESULT Copy(const PFContentGetContentDownloadUrlResult& input, PFContentGetContentDownloadUrlResult& output, ModelBuffer& buffer);
};

} // namespace Content
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
