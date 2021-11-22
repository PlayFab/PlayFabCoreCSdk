#pragma once

#include <playfab/cpp/PFDataDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Data
{

// Data Classes
class AbortFileUploadsRequest : public Wrappers::PFDataAbortFileUploadsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataAbortFileUploadsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataAbortFileUploadsRequest& input);

};

class AbortFileUploadsResponse : public Wrappers::PFDataAbortFileUploadsResponseWrapper<Allocator>, public OutputModel<PFDataAbortFileUploadsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataAbortFileUploadsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataAbortFileUploadsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataAbortFileUploadsResponse& model);
    static HRESULT Copy(const PFDataAbortFileUploadsResponse& input, PFDataAbortFileUploadsResponse& output, ModelBuffer& buffer);
};

class DeleteFilesRequest : public Wrappers::PFDataDeleteFilesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataDeleteFilesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataDeleteFilesRequest& input);

};

class DeleteFilesResponse : public Wrappers::PFDataDeleteFilesResponseWrapper<Allocator>, public OutputModel<PFDataDeleteFilesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataDeleteFilesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataDeleteFilesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataDeleteFilesResponse& model);
    static HRESULT Copy(const PFDataDeleteFilesResponse& input, PFDataDeleteFilesResponse& output, ModelBuffer& buffer);
};

class FinalizeFileUploadsRequest : public Wrappers::PFDataFinalizeFileUploadsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataFinalizeFileUploadsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataFinalizeFileUploadsRequest& input);

};

class GetFileMetadata : public Wrappers::PFDataGetFileMetadataWrapper<Allocator>, public OutputModel<PFDataGetFileMetadata>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataGetFileMetadataWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataGetFileMetadata const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataGetFileMetadata& model);
    static HRESULT Copy(const PFDataGetFileMetadata& input, PFDataGetFileMetadata& output, ModelBuffer& buffer);
};

class FinalizeFileUploadsResponse : public Wrappers::PFDataFinalizeFileUploadsResponseWrapper<Allocator>, public OutputModel<PFDataFinalizeFileUploadsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataFinalizeFileUploadsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataFinalizeFileUploadsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataFinalizeFileUploadsResponse& model);
    static HRESULT Copy(const PFDataFinalizeFileUploadsResponse& input, PFDataFinalizeFileUploadsResponse& output, ModelBuffer& buffer);
};

class GetFilesRequest : public Wrappers::PFDataGetFilesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataGetFilesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataGetFilesRequest& input);

};

class GetFilesResponse : public Wrappers::PFDataGetFilesResponseWrapper<Allocator>, public OutputModel<PFDataGetFilesResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataGetFilesResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataGetFilesResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataGetFilesResponse& model);
    static HRESULT Copy(const PFDataGetFilesResponse& input, PFDataGetFilesResponse& output, ModelBuffer& buffer);
};

class GetObjectsRequest : public Wrappers::PFDataGetObjectsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataGetObjectsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataGetObjectsRequest& input);

};

class ObjectResult : public Wrappers::PFDataObjectResultWrapper<Allocator>, public OutputModel<PFDataObjectResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataObjectResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataObjectResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataObjectResult& model);
    static HRESULT Copy(const PFDataObjectResult& input, PFDataObjectResult& output, ModelBuffer& buffer);
};

class GetObjectsResponse : public Wrappers::PFDataGetObjectsResponseWrapper<Allocator>, public OutputModel<PFDataGetObjectsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataGetObjectsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataGetObjectsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataGetObjectsResponse& model);
    static HRESULT Copy(const PFDataGetObjectsResponse& input, PFDataGetObjectsResponse& output, ModelBuffer& buffer);
};

class InitiateFileUploadsRequest : public Wrappers::PFDataInitiateFileUploadsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataInitiateFileUploadsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataInitiateFileUploadsRequest& input);

};

class InitiateFileUploadMetadata : public Wrappers::PFDataInitiateFileUploadMetadataWrapper<Allocator>, public OutputModel<PFDataInitiateFileUploadMetadata>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataInitiateFileUploadMetadataWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataInitiateFileUploadMetadata const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataInitiateFileUploadMetadata& model);
    static HRESULT Copy(const PFDataInitiateFileUploadMetadata& input, PFDataInitiateFileUploadMetadata& output, ModelBuffer& buffer);
};

class InitiateFileUploadsResponse : public Wrappers::PFDataInitiateFileUploadsResponseWrapper<Allocator>, public OutputModel<PFDataInitiateFileUploadsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataInitiateFileUploadsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataInitiateFileUploadsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataInitiateFileUploadsResponse& model);
    static HRESULT Copy(const PFDataInitiateFileUploadsResponse& input, PFDataInitiateFileUploadsResponse& output, ModelBuffer& buffer);
};

class SetObject : public Wrappers::PFDataSetObjectWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataSetObjectWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataSetObject& input);

};

class SetObjectsRequest : public Wrappers::PFDataSetObjectsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFDataSetObjectsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFDataSetObjectsRequest& input);

};

class SetObjectInfo : public Wrappers::PFDataSetObjectInfoWrapper<Allocator>, public OutputModel<PFDataSetObjectInfo>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataSetObjectInfoWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataSetObjectInfo const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataSetObjectInfo& model);
    static HRESULT Copy(const PFDataSetObjectInfo& input, PFDataSetObjectInfo& output, ModelBuffer& buffer);
};

class SetObjectsResponse : public Wrappers::PFDataSetObjectsResponseWrapper<Allocator>, public OutputModel<PFDataSetObjectsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFDataSetObjectsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFDataSetObjectsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFDataSetObjectsResponse& model);
    static HRESULT Copy(const PFDataSetObjectsResponse& input, PFDataSetObjectsResponse& output, ModelBuffer& buffer);
};

} // namespace Data
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
