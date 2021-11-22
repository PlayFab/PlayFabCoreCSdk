#include "stdafx.h"
#include "ContentDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Content
{

JsonValue DeleteContentRequest::ToJson() const
{
    return DeleteContentRequest::ToJson(this->Model());
}

JsonValue DeleteContentRequest::ToJson(const PFContentDeleteContentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    return output;
}

JsonValue GetContentListRequest::ToJson() const
{
    return GetContentListRequest::ToJson(this->Model());
}

JsonValue GetContentListRequest::ToJson(const PFContentGetContentListRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Prefix", input.prefix);
    return output;
}

void ContentInfo::FromJson(const JsonValue& input)
{
    String key{};
    JsonUtils::ObjectGetMember(input, "Key", key);
    this->SetKey(std::move(key));

    JsonUtils::ObjectGetMemberTime(input, "LastModified", this->m_model.lastModified);

    JsonUtils::ObjectGetMember(input, "Size", this->m_model.size);
}

size_t ContentInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFContentContentInfo const*> ContentInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ContentInfo>(&this->Model());
}

size_t ContentInfo::RequiredBufferSize(const PFContentContentInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.key)
    {
        requiredSize += (std::strlen(model.key) + 1);
    }
    return requiredSize;
}

HRESULT ContentInfo::Copy(const PFContentContentInfo& input, PFContentContentInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.key); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.key = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetContentListResult::FromJson(const JsonValue& input)
{
    ModelVector<ContentInfo> contents{};
    JsonUtils::ObjectGetMember<ContentInfo>(input, "Contents", contents);
    this->SetContents(std::move(contents));

    JsonUtils::ObjectGetMember(input, "ItemCount", this->m_model.itemCount);

    JsonUtils::ObjectGetMember(input, "TotalSize", this->m_model.totalSize);
}

size_t GetContentListResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFContentGetContentListResult const*> GetContentListResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetContentListResult>(&this->Model());
}

size_t GetContentListResult::RequiredBufferSize(const PFContentGetContentListResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFContentContentInfo*) + sizeof(PFContentContentInfo*) * model.contentsCount);
    for (size_t i = 0; i < model.contentsCount; ++i)
    {
        requiredSize += ContentInfo::RequiredBufferSize(*model.contents[i]);
    }
    return requiredSize;
}

HRESULT GetContentListResult::Copy(const PFContentGetContentListResult& input, PFContentGetContentListResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ContentInfo>(input.contents, input.contentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.contents = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetContentUploadUrlRequest::ToJson() const
{
    return GetContentUploadUrlRequest::ToJson(this->Model());
}

JsonValue GetContentUploadUrlRequest::ToJson(const PFContentGetContentUploadUrlRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ContentType", input.contentType);
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    return output;
}

void GetContentUploadUrlResult::FromJson(const JsonValue& input)
{
    String URL{};
    JsonUtils::ObjectGetMember(input, "URL", URL);
    this->SetURL(std::move(URL));
}

size_t GetContentUploadUrlResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFContentGetContentUploadUrlResult const*> GetContentUploadUrlResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetContentUploadUrlResult>(&this->Model());
}

size_t GetContentUploadUrlResult::RequiredBufferSize(const PFContentGetContentUploadUrlResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.URL)
    {
        requiredSize += (std::strlen(model.URL) + 1);
    }
    return requiredSize;
}

HRESULT GetContentUploadUrlResult::Copy(const PFContentGetContentUploadUrlResult& input, PFContentGetContentUploadUrlResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.URL); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.URL = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetContentDownloadUrlRequest::ToJson() const
{
    return GetContentDownloadUrlRequest::ToJson(this->Model());
}

JsonValue GetContentDownloadUrlRequest::ToJson(const PFContentGetContentDownloadUrlRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "HttpMethod", input.httpMethod);
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    JsonUtils::ObjectAddMember(output, "ThruCDN", input.thruCDN);
    return output;
}

void GetContentDownloadUrlResult::FromJson(const JsonValue& input)
{
    String URL{};
    JsonUtils::ObjectGetMember(input, "URL", URL);
    this->SetURL(std::move(URL));
}

size_t GetContentDownloadUrlResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFContentGetContentDownloadUrlResult const*> GetContentDownloadUrlResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetContentDownloadUrlResult>(&this->Model());
}

size_t GetContentDownloadUrlResult::RequiredBufferSize(const PFContentGetContentDownloadUrlResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.URL)
    {
        requiredSize += (std::strlen(model.URL) + 1);
    }
    return requiredSize;
}

HRESULT GetContentDownloadUrlResult::Copy(const PFContentGetContentDownloadUrlResult& input, PFContentGetContentDownloadUrlResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.URL); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.URL = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Content
} // namespace PlayFab
