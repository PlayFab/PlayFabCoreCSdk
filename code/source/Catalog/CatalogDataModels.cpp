#include "stdafx.h"
#include "CatalogDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Catalog
{

JsonValue CatalogAlternateId::ToJson() const
{
    return CatalogAlternateId::ToJson(this->Model());
}

JsonValue CatalogAlternateId::ToJson(const PFCatalogCatalogAlternateId& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    JsonUtils::ObjectAddMember(output, "Value", input.value);
    return output;
}

void CatalogAlternateId::FromJson(const JsonValue& input)
{
    String type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));

    String value{};
    JsonUtils::ObjectGetMember(input, "Value", value);
    this->SetValue(std::move(value));
}

size_t CatalogAlternateId::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogCatalogAlternateId const*> CatalogAlternateId::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogAlternateId>(&this->Model());
}

size_t CatalogAlternateId::RequiredBufferSize(const PFCatalogCatalogAlternateId& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.type)
    {
        requiredSize += (std::strlen(model.type) + 1);
    }
    if (model.value)
    {
        requiredSize += (std::strlen(model.value) + 1);
    }
    return requiredSize;
}

HRESULT CatalogAlternateId::Copy(const PFCatalogCatalogAlternateId& input, PFCatalogCatalogAlternateId& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.value); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.value = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Content::ToJson() const
{
    return Content::ToJson(this->Model());
}

JsonValue Content::ToJson(const PFCatalogContent& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "MaxClientVersion", input.maxClientVersion);
    JsonUtils::ObjectAddMember(output, "MinClientVersion", input.minClientVersion);
    JsonUtils::ObjectAddMember(output, "Url", input.url);
    return output;
}

void Content::FromJson(const JsonValue& input)
{
    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String maxClientVersion{};
    JsonUtils::ObjectGetMember(input, "MaxClientVersion", maxClientVersion);
    this->SetMaxClientVersion(std::move(maxClientVersion));

    String minClientVersion{};
    JsonUtils::ObjectGetMember(input, "MinClientVersion", minClientVersion);
    this->SetMinClientVersion(std::move(minClientVersion));

    String url{};
    JsonUtils::ObjectGetMember(input, "Url", url);
    this->SetUrl(std::move(url));
}

size_t Content::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogContent const*> Content::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Content>(&this->Model());
}

size_t Content::RequiredBufferSize(const PFCatalogContent& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.maxClientVersion)
    {
        requiredSize += (std::strlen(model.maxClientVersion) + 1);
    }
    if (model.minClientVersion)
    {
        requiredSize += (std::strlen(model.minClientVersion) + 1);
    }
    if (model.url)
    {
        requiredSize += (std::strlen(model.url) + 1);
    }
    return requiredSize;
}

HRESULT Content::Copy(const PFCatalogContent& input, PFCatalogContent& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.maxClientVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.maxClientVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.minClientVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.minClientVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.url); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.url = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Image::ToJson() const
{
    return Image::ToJson(this->Model());
}

JsonValue Image::ToJson(const PFCatalogImage& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    JsonUtils::ObjectAddMember(output, "Url", input.url);
    return output;
}

void Image::FromJson(const JsonValue& input)
{
    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));

    String url{};
    JsonUtils::ObjectGetMember(input, "Url", url);
    this->SetUrl(std::move(url));
}

size_t Image::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogImage const*> Image::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Image>(&this->Model());
}

size_t Image::RequiredBufferSize(const PFCatalogImage& model)
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
    if (model.url)
    {
        requiredSize += (std::strlen(model.url) + 1);
    }
    return requiredSize;
}

HRESULT Image::Copy(const PFCatalogImage& input, PFCatalogImage& output, ModelBuffer& buffer)
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
    {
        auto propCopyResult = buffer.CopyTo(input.url); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.url = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue KeywordSet::ToJson() const
{
    return KeywordSet::ToJson(this->Model());
}

JsonValue KeywordSet::ToJson(const PFCatalogKeywordSet& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "Values", input.values, input.valuesCount);
    return output;
}

void KeywordSet::FromJson(const JsonValue& input)
{
    CStringVector values{};
    JsonUtils::ObjectGetMember(input, "Values", values);
    this->SetValues(std::move(values));
}

size_t KeywordSet::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogKeywordSet const*> KeywordSet::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<KeywordSet>(&this->Model());
}

size_t KeywordSet::RequiredBufferSize(const PFCatalogKeywordSet& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.valuesCount);
    for (size_t i = 0; i < model.valuesCount; ++i)
    {
        requiredSize += (std::strlen(model.values[i]) + 1);
    }
    return requiredSize;
}

HRESULT KeywordSet::Copy(const PFCatalogKeywordSet& input, PFCatalogKeywordSet& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.values, input.valuesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.values = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ModerationState::ToJson() const
{
    return ModerationState::ToJson(this->Model());
}

JsonValue ModerationState::ToJson(const PFCatalogModerationState& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberTime(output, "LastModifiedDate", input.lastModifiedDate);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    JsonUtils::ObjectAddMember(output, "Status", input.status);
    return output;
}

void ModerationState::FromJson(const JsonValue& input)
{
    StdExtra::optional<time_t> lastModifiedDate{};
    JsonUtils::ObjectGetMemberTime(input, "LastModifiedDate", lastModifiedDate);
    this->SetLastModifiedDate(std::move(lastModifiedDate));

    String reason{};
    JsonUtils::ObjectGetMember(input, "Reason", reason);
    this->SetReason(std::move(reason));

    StdExtra::optional<PFCatalogModerationStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));
}

size_t ModerationState::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogModerationState const*> ModerationState::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ModerationState>(&this->Model());
}

size_t ModerationState::RequiredBufferSize(const PFCatalogModerationState& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.lastModifiedDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.reason)
    {
        requiredSize += (std::strlen(model.reason) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFCatalogModerationStatus) + sizeof(PFCatalogModerationStatus));
    }
    return requiredSize;
}

HRESULT ModerationState::Copy(const PFCatalogModerationState& input, PFCatalogModerationState& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.lastModifiedDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastModifiedDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reason); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reason = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Rating::ToJson() const
{
    return Rating::ToJson(this->Model());
}

JsonValue Rating::ToJson(const PFCatalogRating& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Average", input.average);
    JsonUtils::ObjectAddMember(output, "Count1Star", input.count1Star);
    JsonUtils::ObjectAddMember(output, "Count2Star", input.count2Star);
    JsonUtils::ObjectAddMember(output, "Count3Star", input.count3Star);
    JsonUtils::ObjectAddMember(output, "Count4Star", input.count4Star);
    JsonUtils::ObjectAddMember(output, "Count5Star", input.count5Star);
    JsonUtils::ObjectAddMember(output, "TotalCount", input.totalCount);
    return output;
}

void Rating::FromJson(const JsonValue& input)
{
    StdExtra::optional<float> average{};
    JsonUtils::ObjectGetMember(input, "Average", average);
    this->SetAverage(std::move(average));

    StdExtra::optional<int32_t> count1Star{};
    JsonUtils::ObjectGetMember(input, "Count1Star", count1Star);
    this->SetCount1Star(std::move(count1Star));

    StdExtra::optional<int32_t> count2Star{};
    JsonUtils::ObjectGetMember(input, "Count2Star", count2Star);
    this->SetCount2Star(std::move(count2Star));

    StdExtra::optional<int32_t> count3Star{};
    JsonUtils::ObjectGetMember(input, "Count3Star", count3Star);
    this->SetCount3Star(std::move(count3Star));

    StdExtra::optional<int32_t> count4Star{};
    JsonUtils::ObjectGetMember(input, "Count4Star", count4Star);
    this->SetCount4Star(std::move(count4Star));

    StdExtra::optional<int32_t> count5Star{};
    JsonUtils::ObjectGetMember(input, "Count5Star", count5Star);
    this->SetCount5Star(std::move(count5Star));

    StdExtra::optional<int32_t> totalCount{};
    JsonUtils::ObjectGetMember(input, "TotalCount", totalCount);
    this->SetTotalCount(std::move(totalCount));
}

size_t Rating::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogRating const*> Rating::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Rating>(&this->Model());
}

size_t Rating::RequiredBufferSize(const PFCatalogRating& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.average)
    {
        requiredSize += (alignof(float) + sizeof(float));
    }
    if (model.count1Star)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.count2Star)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.count3Star)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.count4Star)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.count5Star)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.totalCount)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT Rating::Copy(const PFCatalogRating& input, PFCatalogRating& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.average); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.average = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.count1Star); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.count1Star = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.count2Star); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.count2Star = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.count3Star); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.count3Star = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.count4Star); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.count4Star = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.count5Star); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.count5Star = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.totalCount); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.totalCount = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CatalogItem::ToJson() const
{
    return CatalogItem::ToJson(this->Model());
}

JsonValue CatalogItem::ToJson(const PFCatalogCatalogItem& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<CatalogAlternateId>(output, "AlternateIds", input.alternateIds, input.alternateIdsCount);
    JsonUtils::ObjectAddMemberArray<Content>(output, "Contents", input.contents, input.contentsCount);
    JsonUtils::ObjectAddMember(output, "ContentType", input.contentType);
    JsonUtils::ObjectAddMemberTime(output, "CreationDate", input.creationDate);
    JsonUtils::ObjectAddMember<EntityKey>(output, "CreatorEntity", input.creatorEntity);
    JsonUtils::ObjectAddMemberDictionary(output, "Description", input.description, input.descriptionCount);
    JsonUtils::ObjectAddMember(output, "DisplayProperties", input.displayProperties);
    JsonUtils::ObjectAddMember(output, "DisplayVersion", input.displayVersion);
    JsonUtils::ObjectAddMemberTime(output, "EndDate", input.endDate);
    JsonUtils::ObjectAddMember(output, "ETag", input.eTag);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMemberArray<Image>(output, "Images", input.images, input.imagesCount);
    JsonUtils::ObjectAddMember(output, "IsHidden", input.isHidden);
    JsonUtils::ObjectAddMemberDictionary<KeywordSet>(output, "Keywords", input.keywords, input.keywordsCount);
    JsonUtils::ObjectAddMemberTime(output, "LastModifiedDate", input.lastModifiedDate);
    JsonUtils::ObjectAddMember<ModerationState>(output, "Moderation", input.moderation);
    JsonUtils::ObjectAddMember<Rating>(output, "Rating", input.rating);
    JsonUtils::ObjectAddMemberTime(output, "StartDate", input.startDate);
    JsonUtils::ObjectAddMemberArray(output, "Tags", input.tags, input.tagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Title", input.title, input.titleCount);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

void CatalogItem::FromJson(const JsonValue& input)
{
    ModelVector<CatalogAlternateId> alternateIds{};
    JsonUtils::ObjectGetMember<CatalogAlternateId>(input, "AlternateIds", alternateIds);
    this->SetAlternateIds(std::move(alternateIds));

    ModelVector<Content> contents{};
    JsonUtils::ObjectGetMember<Content>(input, "Contents", contents);
    this->SetContents(std::move(contents));

    String contentType{};
    JsonUtils::ObjectGetMember(input, "ContentType", contentType);
    this->SetContentType(std::move(contentType));

    StdExtra::optional<time_t> creationDate{};
    JsonUtils::ObjectGetMemberTime(input, "CreationDate", creationDate);
    this->SetCreationDate(std::move(creationDate));

    StdExtra::optional<EntityKey> creatorEntity{};
    JsonUtils::ObjectGetMember(input, "CreatorEntity", creatorEntity);
    if (creatorEntity)
    {
        this->SetCreatorEntity(std::move(*creatorEntity));
    }

    StringDictionaryEntryVector description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    JsonObject displayProperties{};
    JsonUtils::ObjectGetMember(input, "DisplayProperties", displayProperties);
    this->SetDisplayProperties(std::move(displayProperties));

    String displayVersion{};
    JsonUtils::ObjectGetMember(input, "DisplayVersion", displayVersion);
    this->SetDisplayVersion(std::move(displayVersion));

    StdExtra::optional<time_t> endDate{};
    JsonUtils::ObjectGetMemberTime(input, "EndDate", endDate);
    this->SetEndDate(std::move(endDate));

    String eTag{};
    JsonUtils::ObjectGetMember(input, "ETag", eTag);
    this->SetETag(std::move(eTag));

    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    ModelVector<Image> images{};
    JsonUtils::ObjectGetMember<Image>(input, "Images", images);
    this->SetImages(std::move(images));

    StdExtra::optional<bool> isHidden{};
    JsonUtils::ObjectGetMember(input, "IsHidden", isHidden);
    this->SetIsHidden(std::move(isHidden));

    ModelDictionaryEntryVector<KeywordSet> keywords{};
    JsonUtils::ObjectGetMember<KeywordSet>(input, "Keywords", keywords);
    this->SetKeywords(std::move(keywords));

    StdExtra::optional<time_t> lastModifiedDate{};
    JsonUtils::ObjectGetMemberTime(input, "LastModifiedDate", lastModifiedDate);
    this->SetLastModifiedDate(std::move(lastModifiedDate));

    StdExtra::optional<ModerationState> moderation{};
    JsonUtils::ObjectGetMember(input, "Moderation", moderation);
    if (moderation)
    {
        this->SetModeration(std::move(*moderation));
    }

    StdExtra::optional<Rating> rating{};
    JsonUtils::ObjectGetMember(input, "Rating", rating);
    if (rating)
    {
        this->SetRating(std::move(*rating));
    }

    StdExtra::optional<time_t> startDate{};
    JsonUtils::ObjectGetMemberTime(input, "StartDate", startDate);
    this->SetStartDate(std::move(startDate));

    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));

    StringDictionaryEntryVector title{};
    JsonUtils::ObjectGetMember(input, "Title", title);
    this->SetTitle(std::move(title));

    String type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));
}

size_t CatalogItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogCatalogItem const*> CatalogItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogItem>(&this->Model());
}

size_t CatalogItem::RequiredBufferSize(const PFCatalogCatalogItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCatalogCatalogAlternateId*) + sizeof(PFCatalogCatalogAlternateId*) * model.alternateIdsCount);
    for (size_t i = 0; i < model.alternateIdsCount; ++i)
    {
        requiredSize += CatalogAlternateId::RequiredBufferSize(*model.alternateIds[i]);
    }
    requiredSize += (alignof(PFCatalogContent*) + sizeof(PFCatalogContent*) * model.contentsCount);
    for (size_t i = 0; i < model.contentsCount; ++i)
    {
        requiredSize += Content::RequiredBufferSize(*model.contents[i]);
    }
    if (model.contentType)
    {
        requiredSize += (std::strlen(model.contentType) + 1);
    }
    if (model.creationDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.creatorEntity)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.creatorEntity);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.descriptionCount);
    for (size_t i = 0; i < model.descriptionCount; ++i)
    {
        requiredSize += (std::strlen(model.description[i].key) + 1);
        requiredSize += (std::strlen(model.description[i].value) + 1);
    }
    if (model.displayProperties.stringValue)
    {
    requiredSize += (std::strlen(model.displayProperties.stringValue) + 1);
    }
    if (model.displayVersion)
    {
        requiredSize += (std::strlen(model.displayVersion) + 1);
    }
    if (model.endDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.eTag)
    {
        requiredSize += (std::strlen(model.eTag) + 1);
    }
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    requiredSize += (alignof(PFCatalogImage*) + sizeof(PFCatalogImage*) * model.imagesCount);
    for (size_t i = 0; i < model.imagesCount; ++i)
    {
        requiredSize += Image::RequiredBufferSize(*model.images[i]);
    }
    if (model.isHidden)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    requiredSize += (alignof(PFCatalogKeywordSetDictionaryEntry) + sizeof(PFCatalogKeywordSetDictionaryEntry) * model.keywordsCount);
    for (size_t i = 0; i < model.keywordsCount; ++i)
    {
        requiredSize += (std::strlen(model.keywords[i].key) + 1);
        requiredSize += KeywordSet::RequiredBufferSize(*model.keywords[i].value);
    }
    if (model.lastModifiedDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.moderation)
    {
        requiredSize += ModerationState::RequiredBufferSize(*model.moderation);
    }
    if (model.rating)
    {
        requiredSize += Rating::RequiredBufferSize(*model.rating);
    }
    if (model.startDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.titleCount);
    for (size_t i = 0; i < model.titleCount; ++i)
    {
        requiredSize += (std::strlen(model.title[i].key) + 1);
        requiredSize += (std::strlen(model.title[i].value) + 1);
    }
    if (model.type)
    {
        requiredSize += (std::strlen(model.type) + 1);
    }
    return requiredSize;
}

HRESULT CatalogItem::Copy(const PFCatalogCatalogItem& input, PFCatalogCatalogItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CatalogAlternateId>(input.alternateIds, input.alternateIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.alternateIds = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Content>(input.contents, input.contentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.contents = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.contentType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.contentType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.creationDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creationDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<EntityKey>(input.creatorEntity); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creatorEntity = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.description, input.descriptionCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayProperties.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayProperties.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.endDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.endDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.eTag); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.eTag = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Image>(input.images, input.imagesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.images = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.isHidden); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.isHidden = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<KeywordSet>(input.keywords, input.keywordsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.keywords = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastModifiedDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastModifiedDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ModerationState>(input.moderation); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.moderation = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<Rating>(input.rating); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rating = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.startDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.startDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.title, input.titleCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.title = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateDraftItemRequest::ToJson() const
{
    return CreateDraftItemRequest::ToJson(this->Model());
}

JsonValue CreateDraftItemRequest::ToJson(const PFCatalogCreateDraftItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<CatalogItem>(output, "Item", input.item);
    JsonUtils::ObjectAddMember(output, "Publish", input.publish);
    return output;
}

void CreateDraftItemResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<CatalogItem> item{};
    JsonUtils::ObjectGetMember(input, "Item", item);
    if (item)
    {
        this->SetItem(std::move(*item));
    }
}

size_t CreateDraftItemResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogCreateDraftItemResponse const*> CreateDraftItemResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateDraftItemResponse>(&this->Model());
}

size_t CreateDraftItemResponse::RequiredBufferSize(const PFCatalogCreateDraftItemResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.item)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.item);
    }
    return requiredSize;
}

HRESULT CreateDraftItemResponse::Copy(const PFCatalogCreateDraftItemResponse& input, PFCatalogCreateDraftItemResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CatalogItem>(input.item); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.item = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UploadInfo::ToJson() const
{
    return UploadInfo::ToJson(this->Model());
}

JsonValue UploadInfo::ToJson(const PFCatalogUploadInfo& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "FileName", input.fileName);
    return output;
}

JsonValue CreateUploadUrlsRequest::ToJson() const
{
    return CreateUploadUrlsRequest::ToJson(this->Model());
}

JsonValue CreateUploadUrlsRequest::ToJson(const PFCatalogCreateUploadUrlsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<UploadInfo>(output, "Files", input.files, input.filesCount);
    return output;
}

void UploadUrlMetadata::FromJson(const JsonValue& input)
{
    String fileName{};
    JsonUtils::ObjectGetMember(input, "FileName", fileName);
    this->SetFileName(std::move(fileName));

    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String url{};
    JsonUtils::ObjectGetMember(input, "Url", url);
    this->SetUrl(std::move(url));
}

size_t UploadUrlMetadata::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogUploadUrlMetadata const*> UploadUrlMetadata::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UploadUrlMetadata>(&this->Model());
}

size_t UploadUrlMetadata::RequiredBufferSize(const PFCatalogUploadUrlMetadata& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.fileName)
    {
        requiredSize += (std::strlen(model.fileName) + 1);
    }
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.url)
    {
        requiredSize += (std::strlen(model.url) + 1);
    }
    return requiredSize;
}

HRESULT UploadUrlMetadata::Copy(const PFCatalogUploadUrlMetadata& input, PFCatalogUploadUrlMetadata& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.fileName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fileName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.url); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.url = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void CreateUploadUrlsResponse::FromJson(const JsonValue& input)
{
    ModelVector<UploadUrlMetadata> uploadUrls{};
    JsonUtils::ObjectGetMember<UploadUrlMetadata>(input, "UploadUrls", uploadUrls);
    this->SetUploadUrls(std::move(uploadUrls));
}

size_t CreateUploadUrlsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogCreateUploadUrlsResponse const*> CreateUploadUrlsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateUploadUrlsResponse>(&this->Model());
}

size_t CreateUploadUrlsResponse::RequiredBufferSize(const PFCatalogCreateUploadUrlsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCatalogUploadUrlMetadata*) + sizeof(PFCatalogUploadUrlMetadata*) * model.uploadUrlsCount);
    for (size_t i = 0; i < model.uploadUrlsCount; ++i)
    {
        requiredSize += UploadUrlMetadata::RequiredBufferSize(*model.uploadUrls[i]);
    }
    return requiredSize;
}

HRESULT CreateUploadUrlsResponse::Copy(const PFCatalogCreateUploadUrlsResponse& input, PFCatalogCreateUploadUrlsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<UploadUrlMetadata>(input.uploadUrls, input.uploadUrlsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.uploadUrls = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteEntityItemReviewsRequest::ToJson() const
{
    return DeleteEntityItemReviewsRequest::ToJson(this->Model());
}

JsonValue DeleteEntityItemReviewsRequest::ToJson(const PFCatalogDeleteEntityItemReviewsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

JsonValue DeleteItemRequest::ToJson() const
{
    return DeleteItemRequest::ToJson(this->Model());
}

JsonValue DeleteItemRequest::ToJson(const PFCatalogDeleteItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

JsonValue GetCatalogConfigRequest::ToJson() const
{
    return GetCatalogConfigRequest::ToJson(this->Model());
}

JsonValue GetCatalogConfigRequest::ToJson(const PFCatalogGetCatalogConfigRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue DisplayPropertyIndexInfo::ToJson() const
{
    return DisplayPropertyIndexInfo::ToJson(this->Model());
}

JsonValue DisplayPropertyIndexInfo::ToJson(const PFCatalogDisplayPropertyIndexInfo& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

void DisplayPropertyIndexInfo::FromJson(const JsonValue& input)
{
    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    StdExtra::optional<PFCatalogDisplayPropertyType> type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));
}

size_t DisplayPropertyIndexInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogDisplayPropertyIndexInfo const*> DisplayPropertyIndexInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DisplayPropertyIndexInfo>(&this->Model());
}

size_t DisplayPropertyIndexInfo::RequiredBufferSize(const PFCatalogDisplayPropertyIndexInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.type)
    {
        requiredSize += (alignof(PFCatalogDisplayPropertyType) + sizeof(PFCatalogDisplayPropertyType));
    }
    return requiredSize;
}

HRESULT DisplayPropertyIndexInfo::Copy(const PFCatalogDisplayPropertyIndexInfo& input, PFCatalogDisplayPropertyIndexInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UserGeneratedContentSpecificConfig::ToJson() const
{
    return UserGeneratedContentSpecificConfig::ToJson(this->Model());
}

JsonValue UserGeneratedContentSpecificConfig::ToJson(const PFCatalogUserGeneratedContentSpecificConfig& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "ContentTypes", input.contentTypes, input.contentTypesCount);
    JsonUtils::ObjectAddMemberArray(output, "Tags", input.tags, input.tagsCount);
    return output;
}

void UserGeneratedContentSpecificConfig::FromJson(const JsonValue& input)
{
    CStringVector contentTypes{};
    JsonUtils::ObjectGetMember(input, "ContentTypes", contentTypes);
    this->SetContentTypes(std::move(contentTypes));

    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));
}

size_t UserGeneratedContentSpecificConfig::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogUserGeneratedContentSpecificConfig const*> UserGeneratedContentSpecificConfig::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UserGeneratedContentSpecificConfig>(&this->Model());
}

size_t UserGeneratedContentSpecificConfig::RequiredBufferSize(const PFCatalogUserGeneratedContentSpecificConfig& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.contentTypesCount);
    for (size_t i = 0; i < model.contentTypesCount; ++i)
    {
        requiredSize += (std::strlen(model.contentTypes[i]) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    return requiredSize;
}

HRESULT UserGeneratedContentSpecificConfig::Copy(const PFCatalogUserGeneratedContentSpecificConfig& input, PFCatalogUserGeneratedContentSpecificConfig& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.contentTypes, input.contentTypesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.contentTypes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CatalogConfig::ToJson() const
{
    return CatalogConfig::ToJson(this->Model());
}

JsonValue CatalogConfig::ToJson(const PFCatalogCatalogConfig& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<EntityKey>(output, "AdminEntities", input.adminEntities, input.adminEntitiesCount);
    JsonUtils::ObjectAddMemberArray<DisplayPropertyIndexInfo>(output, "DisplayPropertyIndexInfos", input.displayPropertyIndexInfos, input.displayPropertyIndexInfosCount);
    JsonUtils::ObjectAddMember(output, "IsCatalogEnabled", input.isCatalogEnabled);
    JsonUtils::ObjectAddMemberArray<EntityKey>(output, "ReviewerEntities", input.reviewerEntities, input.reviewerEntitiesCount);
    JsonUtils::ObjectAddMember<UserGeneratedContentSpecificConfig>(output, "UserGeneratedContent", input.userGeneratedContent);
    return output;
}

void CatalogConfig::FromJson(const JsonValue& input)
{
    ModelVector<EntityKey> adminEntities{};
    JsonUtils::ObjectGetMember<EntityKey>(input, "AdminEntities", adminEntities);
    this->SetAdminEntities(std::move(adminEntities));

    ModelVector<DisplayPropertyIndexInfo> displayPropertyIndexInfos{};
    JsonUtils::ObjectGetMember<DisplayPropertyIndexInfo>(input, "DisplayPropertyIndexInfos", displayPropertyIndexInfos);
    this->SetDisplayPropertyIndexInfos(std::move(displayPropertyIndexInfos));

    JsonUtils::ObjectGetMember(input, "IsCatalogEnabled", this->m_model.isCatalogEnabled);

    ModelVector<EntityKey> reviewerEntities{};
    JsonUtils::ObjectGetMember<EntityKey>(input, "ReviewerEntities", reviewerEntities);
    this->SetReviewerEntities(std::move(reviewerEntities));

    StdExtra::optional<UserGeneratedContentSpecificConfig> userGeneratedContent{};
    JsonUtils::ObjectGetMember(input, "UserGeneratedContent", userGeneratedContent);
    if (userGeneratedContent)
    {
        this->SetUserGeneratedContent(std::move(*userGeneratedContent));
    }
}

size_t CatalogConfig::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogCatalogConfig const*> CatalogConfig::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogConfig>(&this->Model());
}

size_t CatalogConfig::RequiredBufferSize(const PFCatalogCatalogConfig& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFEntityKey*) + sizeof(PFEntityKey*) * model.adminEntitiesCount);
    for (size_t i = 0; i < model.adminEntitiesCount; ++i)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.adminEntities[i]);
    }
    requiredSize += (alignof(PFCatalogDisplayPropertyIndexInfo*) + sizeof(PFCatalogDisplayPropertyIndexInfo*) * model.displayPropertyIndexInfosCount);
    for (size_t i = 0; i < model.displayPropertyIndexInfosCount; ++i)
    {
        requiredSize += DisplayPropertyIndexInfo::RequiredBufferSize(*model.displayPropertyIndexInfos[i]);
    }
    requiredSize += (alignof(PFEntityKey*) + sizeof(PFEntityKey*) * model.reviewerEntitiesCount);
    for (size_t i = 0; i < model.reviewerEntitiesCount; ++i)
    {
        requiredSize += EntityKey::RequiredBufferSize(*model.reviewerEntities[i]);
    }
    if (model.userGeneratedContent)
    {
        requiredSize += UserGeneratedContentSpecificConfig::RequiredBufferSize(*model.userGeneratedContent);
    }
    return requiredSize;
}

HRESULT CatalogConfig::Copy(const PFCatalogCatalogConfig& input, PFCatalogCatalogConfig& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<EntityKey>(input.adminEntities, input.adminEntitiesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.adminEntities = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<DisplayPropertyIndexInfo>(input.displayPropertyIndexInfos, input.displayPropertyIndexInfosCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayPropertyIndexInfos = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<EntityKey>(input.reviewerEntities, input.reviewerEntitiesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reviewerEntities = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<UserGeneratedContentSpecificConfig>(input.userGeneratedContent); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.userGeneratedContent = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetCatalogConfigResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<CatalogConfig> config{};
    JsonUtils::ObjectGetMember(input, "Config", config);
    if (config)
    {
        this->SetConfig(std::move(*config));
    }
}

size_t GetCatalogConfigResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetCatalogConfigResponse const*> GetCatalogConfigResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetCatalogConfigResponse>(&this->Model());
}

size_t GetCatalogConfigResponse::RequiredBufferSize(const PFCatalogGetCatalogConfigResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.config)
    {
        requiredSize += CatalogConfig::RequiredBufferSize(*model.config);
    }
    return requiredSize;
}

HRESULT GetCatalogConfigResponse::Copy(const PFCatalogGetCatalogConfigResponse& input, PFCatalogGetCatalogConfigResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CatalogConfig>(input.config); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.config = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetDraftItemRequest::ToJson() const
{
    return GetDraftItemRequest::ToJson(this->Model());
}

JsonValue GetDraftItemRequest::ToJson(const PFCatalogGetDraftItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

void GetDraftItemResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<CatalogItem> item{};
    JsonUtils::ObjectGetMember(input, "Item", item);
    if (item)
    {
        this->SetItem(std::move(*item));
    }
}

size_t GetDraftItemResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetDraftItemResponse const*> GetDraftItemResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetDraftItemResponse>(&this->Model());
}

size_t GetDraftItemResponse::RequiredBufferSize(const PFCatalogGetDraftItemResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.item)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.item);
    }
    return requiredSize;
}

HRESULT GetDraftItemResponse::Copy(const PFCatalogGetDraftItemResponse& input, PFCatalogGetDraftItemResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CatalogItem>(input.item); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.item = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetDraftItemsRequest::ToJson() const
{
    return GetDraftItemsRequest::ToJson(this->Model());
}

JsonValue GetDraftItemsRequest::ToJson(const PFCatalogGetDraftItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<CatalogAlternateId>(output, "AlternateIds", input.alternateIds, input.alternateIdsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMemberArray(output, "Ids", input.ids, input.idsCount);
    return output;
}

void GetDraftItemsResponse::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    ModelVector<CatalogItem> items{};
    JsonUtils::ObjectGetMember<CatalogItem>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t GetDraftItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetDraftItemsResponse const*> GetDraftItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetDraftItemsResponse>(&this->Model());
}

size_t GetDraftItemsResponse::RequiredBufferSize(const PFCatalogGetDraftItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    requiredSize += (alignof(PFCatalogCatalogItem*) + sizeof(PFCatalogCatalogItem*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT GetDraftItemsResponse::Copy(const PFCatalogGetDraftItemsResponse& input, PFCatalogGetDraftItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<CatalogItem>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetEntityDraftItemsRequest::ToJson() const
{
    return GetEntityDraftItemsRequest::ToJson(this->Model());
}

JsonValue GetEntityDraftItemsRequest::ToJson(const PFCatalogGetEntityDraftItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMember(output, "Count", input.count);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void GetEntityDraftItemsResponse::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    ModelVector<CatalogItem> items{};
    JsonUtils::ObjectGetMember<CatalogItem>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t GetEntityDraftItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetEntityDraftItemsResponse const*> GetEntityDraftItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetEntityDraftItemsResponse>(&this->Model());
}

size_t GetEntityDraftItemsResponse::RequiredBufferSize(const PFCatalogGetEntityDraftItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    requiredSize += (alignof(PFCatalogCatalogItem*) + sizeof(PFCatalogCatalogItem*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT GetEntityDraftItemsResponse::Copy(const PFCatalogGetEntityDraftItemsResponse& input, PFCatalogGetEntityDraftItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<CatalogItem>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetEntityItemReviewRequest::ToJson() const
{
    return GetEntityItemReviewRequest::ToJson(this->Model());
}

JsonValue GetEntityItemReviewRequest::ToJson(const PFCatalogGetEntityItemReviewRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

JsonValue Review::ToJson() const
{
    return Review::ToJson(this->Model());
}

JsonValue Review::ToJson(const PFCatalogReview& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "HelpfulNegative", input.helpfulNegative);
    JsonUtils::ObjectAddMember(output, "HelpfulnessVotes", input.helpfulnessVotes);
    JsonUtils::ObjectAddMember(output, "HelpfulPositive", input.helpfulPositive);
    JsonUtils::ObjectAddMember(output, "IsInstalled", input.isInstalled);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "ItemVersion", input.itemVersion);
    JsonUtils::ObjectAddMember(output, "Locale", input.locale);
    JsonUtils::ObjectAddMember(output, "Rating", input.rating);
    JsonUtils::ObjectAddMember(output, "ReviewerId", input.reviewerId);
    JsonUtils::ObjectAddMember(output, "ReviewId", input.reviewId);
    JsonUtils::ObjectAddMember(output, "ReviewText", input.reviewText);
    JsonUtils::ObjectAddMemberTime(output, "Submitted", input.submitted);
    JsonUtils::ObjectAddMember(output, "Title", input.title);
    return output;
}

void Review::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "HelpfulNegative", this->m_model.helpfulNegative);

    JsonUtils::ObjectGetMember(input, "HelpfulnessVotes", this->m_model.helpfulnessVotes);

    JsonUtils::ObjectGetMember(input, "HelpfulPositive", this->m_model.helpfulPositive);

    JsonUtils::ObjectGetMember(input, "IsInstalled", this->m_model.isInstalled);

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));

    String itemVersion{};
    JsonUtils::ObjectGetMember(input, "ItemVersion", itemVersion);
    this->SetItemVersion(std::move(itemVersion));

    String locale{};
    JsonUtils::ObjectGetMember(input, "Locale", locale);
    this->SetLocale(std::move(locale));

    JsonUtils::ObjectGetMember(input, "Rating", this->m_model.rating);

    String reviewerId{};
    JsonUtils::ObjectGetMember(input, "ReviewerId", reviewerId);
    this->SetReviewerId(std::move(reviewerId));

    String reviewId{};
    JsonUtils::ObjectGetMember(input, "ReviewId", reviewId);
    this->SetReviewId(std::move(reviewId));

    String reviewText{};
    JsonUtils::ObjectGetMember(input, "ReviewText", reviewText);
    this->SetReviewText(std::move(reviewText));

    JsonUtils::ObjectGetMemberTime(input, "Submitted", this->m_model.submitted);

    String title{};
    JsonUtils::ObjectGetMember(input, "Title", title);
    this->SetTitle(std::move(title));
}

size_t Review::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogReview const*> Review::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Review>(&this->Model());
}

size_t Review::RequiredBufferSize(const PFCatalogReview& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    if (model.itemVersion)
    {
        requiredSize += (std::strlen(model.itemVersion) + 1);
    }
    if (model.locale)
    {
        requiredSize += (std::strlen(model.locale) + 1);
    }
    if (model.reviewerId)
    {
        requiredSize += (std::strlen(model.reviewerId) + 1);
    }
    if (model.reviewId)
    {
        requiredSize += (std::strlen(model.reviewId) + 1);
    }
    if (model.reviewText)
    {
        requiredSize += (std::strlen(model.reviewText) + 1);
    }
    if (model.title)
    {
        requiredSize += (std::strlen(model.title) + 1);
    }
    return requiredSize;
}

HRESULT Review::Copy(const PFCatalogReview& input, PFCatalogReview& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.itemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.locale); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.locale = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reviewerId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reviewerId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reviewId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reviewId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reviewText); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reviewText = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.title); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.title = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetEntityItemReviewResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<Review> review{};
    JsonUtils::ObjectGetMember(input, "Review", review);
    if (review)
    {
        this->SetReview(std::move(*review));
    }
}

size_t GetEntityItemReviewResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetEntityItemReviewResponse const*> GetEntityItemReviewResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetEntityItemReviewResponse>(&this->Model());
}

size_t GetEntityItemReviewResponse::RequiredBufferSize(const PFCatalogGetEntityItemReviewResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.review)
    {
        requiredSize += Review::RequiredBufferSize(*model.review);
    }
    return requiredSize;
}

HRESULT GetEntityItemReviewResponse::Copy(const PFCatalogGetEntityItemReviewResponse& input, PFCatalogGetEntityItemReviewResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<Review>(input.review); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.review = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetItemRequest::ToJson() const
{
    return GetItemRequest::ToJson(this->Model());
}

JsonValue GetItemRequest::ToJson(const PFCatalogGetItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

void GetItemResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<CatalogItem> item{};
    JsonUtils::ObjectGetMember(input, "Item", item);
    if (item)
    {
        this->SetItem(std::move(*item));
    }
}

size_t GetItemResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetItemResponse const*> GetItemResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetItemResponse>(&this->Model());
}

size_t GetItemResponse::RequiredBufferSize(const PFCatalogGetItemResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.item)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.item);
    }
    return requiredSize;
}

HRESULT GetItemResponse::Copy(const PFCatalogGetItemResponse& input, PFCatalogGetItemResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CatalogItem>(input.item); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.item = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetItemModerationStateRequest::ToJson() const
{
    return GetItemModerationStateRequest::ToJson(this->Model());
}

JsonValue GetItemModerationStateRequest::ToJson(const PFCatalogGetItemModerationStateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

void GetItemModerationStateResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<ModerationState> state{};
    JsonUtils::ObjectGetMember(input, "State", state);
    if (state)
    {
        this->SetState(std::move(*state));
    }
}

size_t GetItemModerationStateResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetItemModerationStateResponse const*> GetItemModerationStateResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetItemModerationStateResponse>(&this->Model());
}

size_t GetItemModerationStateResponse::RequiredBufferSize(const PFCatalogGetItemModerationStateResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.state)
    {
        requiredSize += ModerationState::RequiredBufferSize(*model.state);
    }
    return requiredSize;
}

HRESULT GetItemModerationStateResponse::Copy(const PFCatalogGetItemModerationStateResponse& input, PFCatalogGetItemModerationStateResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<ModerationState>(input.state); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.state = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetItemPublishStatusRequest::ToJson() const
{
    return GetItemPublishStatusRequest::ToJson(this->Model());
}

JsonValue GetItemPublishStatusRequest::ToJson(const PFCatalogGetItemPublishStatusRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

void ScanResult::FromJson(const JsonValue& input)
{
    String url{};
    JsonUtils::ObjectGetMember(input, "Url", url);
    this->SetUrl(std::move(url));
}

size_t ScanResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogScanResult const*> ScanResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ScanResult>(&this->Model());
}

size_t ScanResult::RequiredBufferSize(const PFCatalogScanResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.url)
    {
        requiredSize += (std::strlen(model.url) + 1);
    }
    return requiredSize;
}

HRESULT ScanResult::Copy(const PFCatalogScanResult& input, PFCatalogScanResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.url); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.url = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetItemPublishStatusResponse::FromJson(const JsonValue& input)
{
    ModelVector<ScanResult> failedScanResults{};
    JsonUtils::ObjectGetMember<ScanResult>(input, "FailedScanResults", failedScanResults);
    this->SetFailedScanResults(std::move(failedScanResults));

    StdExtra::optional<PFCatalogPublishResult> result{};
    JsonUtils::ObjectGetMember(input, "Result", result);
    this->SetResult(std::move(result));

    String statusMessage{};
    JsonUtils::ObjectGetMember(input, "StatusMessage", statusMessage);
    this->SetStatusMessage(std::move(statusMessage));
}

size_t GetItemPublishStatusResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetItemPublishStatusResponse const*> GetItemPublishStatusResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetItemPublishStatusResponse>(&this->Model());
}

size_t GetItemPublishStatusResponse::RequiredBufferSize(const PFCatalogGetItemPublishStatusResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFCatalogScanResult*) + sizeof(PFCatalogScanResult*) * model.failedScanResultsCount);
    for (size_t i = 0; i < model.failedScanResultsCount; ++i)
    {
        requiredSize += ScanResult::RequiredBufferSize(*model.failedScanResults[i]);
    }
    if (model.result)
    {
        requiredSize += (alignof(PFCatalogPublishResult) + sizeof(PFCatalogPublishResult));
    }
    if (model.statusMessage)
    {
        requiredSize += (std::strlen(model.statusMessage) + 1);
    }
    return requiredSize;
}

HRESULT GetItemPublishStatusResponse::Copy(const PFCatalogGetItemPublishStatusResponse& input, PFCatalogGetItemPublishStatusResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ScanResult>(input.failedScanResults, input.failedScanResultsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failedScanResults = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.result); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.result = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.statusMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statusMessage = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetItemReviewsRequest::ToJson() const
{
    return GetItemReviewsRequest::ToJson(this->Model());
}

JsonValue GetItemReviewsRequest::ToJson(const PFCatalogGetItemReviewsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMember(output, "Count", input.count);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "OrderBy", input.orderBy);
    return output;
}

void GetItemReviewsResponse::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    ModelVector<Review> reviews{};
    JsonUtils::ObjectGetMember<Review>(input, "Reviews", reviews);
    this->SetReviews(std::move(reviews));
}

size_t GetItemReviewsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetItemReviewsResponse const*> GetItemReviewsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetItemReviewsResponse>(&this->Model());
}

size_t GetItemReviewsResponse::RequiredBufferSize(const PFCatalogGetItemReviewsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    requiredSize += (alignof(PFCatalogReview*) + sizeof(PFCatalogReview*) * model.reviewsCount);
    for (size_t i = 0; i < model.reviewsCount; ++i)
    {
        requiredSize += Review::RequiredBufferSize(*model.reviews[i]);
    }
    return requiredSize;
}

HRESULT GetItemReviewsResponse::Copy(const PFCatalogGetItemReviewsResponse& input, PFCatalogGetItemReviewsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Review>(input.reviews, input.reviewsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reviews = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetItemReviewSummaryRequest::ToJson() const
{
    return GetItemReviewSummaryRequest::ToJson(this->Model());
}

JsonValue GetItemReviewSummaryRequest::ToJson(const PFCatalogGetItemReviewSummaryRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

void GetItemReviewSummaryResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<Review> leastFavorableReview{};
    JsonUtils::ObjectGetMember(input, "LeastFavorableReview", leastFavorableReview);
    if (leastFavorableReview)
    {
        this->SetLeastFavorableReview(std::move(*leastFavorableReview));
    }

    StdExtra::optional<Review> mostFavorableReview{};
    JsonUtils::ObjectGetMember(input, "MostFavorableReview", mostFavorableReview);
    if (mostFavorableReview)
    {
        this->SetMostFavorableReview(std::move(*mostFavorableReview));
    }

    StdExtra::optional<Rating> rating{};
    JsonUtils::ObjectGetMember(input, "Rating", rating);
    if (rating)
    {
        this->SetRating(std::move(*rating));
    }

    JsonUtils::ObjectGetMember(input, "ReviewsCount", this->m_model.reviewsCount);
}

size_t GetItemReviewSummaryResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogGetItemReviewSummaryResponse const*> GetItemReviewSummaryResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetItemReviewSummaryResponse>(&this->Model());
}

size_t GetItemReviewSummaryResponse::RequiredBufferSize(const PFCatalogGetItemReviewSummaryResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.leastFavorableReview)
    {
        requiredSize += Review::RequiredBufferSize(*model.leastFavorableReview);
    }
    if (model.mostFavorableReview)
    {
        requiredSize += Review::RequiredBufferSize(*model.mostFavorableReview);
    }
    if (model.rating)
    {
        requiredSize += Rating::RequiredBufferSize(*model.rating);
    }
    return requiredSize;
}

HRESULT GetItemReviewSummaryResponse::Copy(const PFCatalogGetItemReviewSummaryResponse& input, PFCatalogGetItemReviewSummaryResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<Review>(input.leastFavorableReview); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leastFavorableReview = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<Review>(input.mostFavorableReview); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.mostFavorableReview = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<Rating>(input.rating); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rating = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PublishDraftItemRequest::ToJson() const
{
    return PublishDraftItemRequest::ToJson(this->Model());
}

JsonValue PublishDraftItemRequest::ToJson(const PFCatalogPublishDraftItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "ETag", input.eTag);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    return output;
}

JsonValue ReportItemRequest::ToJson() const
{
    return ReportItemRequest::ToJson(this->Model());
}

JsonValue ReportItemRequest::ToJson(const PFCatalogReportItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMember(output, "ConcernCategory", input.concernCategory);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

JsonValue ReportItemReviewRequest::ToJson() const
{
    return ReportItemReviewRequest::ToJson(this->Model());
}

JsonValue ReportItemReviewRequest::ToJson(const PFCatalogReportItemReviewRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMember(output, "ConcernCategory", input.concernCategory);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    JsonUtils::ObjectAddMember(output, "ReviewId", input.reviewId);
    return output;
}

JsonValue ReviewItemRequest::ToJson() const
{
    return ReviewItemRequest::ToJson(this->Model());
}

JsonValue ReviewItemRequest::ToJson(const PFCatalogReviewItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember<Review>(output, "Review", input.review);
    return output;
}

JsonValue SearchItemsRequest::ToJson() const
{
    return SearchItemsRequest::ToJson(this->Model());
}

JsonValue SearchItemsRequest::ToJson(const PFCatalogSearchItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMember(output, "Count", input.count);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Filter", input.filter);
    JsonUtils::ObjectAddMember(output, "OrderBy", input.orderBy);
    JsonUtils::ObjectAddMember(output, "Search", input.search);
    JsonUtils::ObjectAddMember(output, "Select", input.select);
    return output;
}

void SearchItemsResponse::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    ModelVector<CatalogItem> items{};
    JsonUtils::ObjectGetMember<CatalogItem>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t SearchItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogSearchItemsResponse const*> SearchItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SearchItemsResponse>(&this->Model());
}

size_t SearchItemsResponse::RequiredBufferSize(const PFCatalogSearchItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    requiredSize += (alignof(PFCatalogCatalogItem*) + sizeof(PFCatalogCatalogItem*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT SearchItemsResponse::Copy(const PFCatalogSearchItemsResponse& input, PFCatalogSearchItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<CatalogItem>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SetItemModerationStateRequest::ToJson() const
{
    return SetItemModerationStateRequest::ToJson(this->Model());
}

JsonValue SetItemModerationStateRequest::ToJson(const PFCatalogSetItemModerationStateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    JsonUtils::ObjectAddMember(output, "Status", input.status);
    return output;
}

JsonValue SubmitItemReviewVoteRequest::ToJson() const
{
    return SubmitItemReviewVoteRequest::ToJson(this->Model());
}

JsonValue SubmitItemReviewVoteRequest::ToJson(const PFCatalogSubmitItemReviewVoteRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "ReviewId", input.reviewId);
    JsonUtils::ObjectAddMember(output, "Vote", input.vote);
    return output;
}

JsonValue ReviewTakedown::ToJson() const
{
    return ReviewTakedown::ToJson(this->Model());
}

JsonValue ReviewTakedown::ToJson(const PFCatalogReviewTakedown& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogAlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "ReviewId", input.reviewId);
    return output;
}

JsonValue TakedownItemReviewsRequest::ToJson() const
{
    return TakedownItemReviewsRequest::ToJson(this->Model());
}

JsonValue TakedownItemReviewsRequest::ToJson(const PFCatalogTakedownItemReviewsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<ReviewTakedown>(output, "Reviews", input.reviews, input.reviewsCount);
    return output;
}

JsonValue UpdateCatalogConfigRequest::ToJson() const
{
    return UpdateCatalogConfigRequest::ToJson(this->Model());
}

JsonValue UpdateCatalogConfigRequest::ToJson(const PFCatalogUpdateCatalogConfigRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogConfig>(output, "Config", input.config);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UpdateDraftItemRequest::ToJson() const
{
    return UpdateDraftItemRequest::ToJson(this->Model());
}

JsonValue UpdateDraftItemRequest::ToJson(const PFCatalogUpdateDraftItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<CatalogItem>(output, "Item", input.item);
    JsonUtils::ObjectAddMember(output, "Publish", input.publish);
    return output;
}

void UpdateDraftItemResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<CatalogItem> item{};
    JsonUtils::ObjectGetMember(input, "Item", item);
    if (item)
    {
        this->SetItem(std::move(*item));
    }
}

size_t UpdateDraftItemResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFCatalogUpdateDraftItemResponse const*> UpdateDraftItemResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateDraftItemResponse>(&this->Model());
}

size_t UpdateDraftItemResponse::RequiredBufferSize(const PFCatalogUpdateDraftItemResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.item)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.item);
    }
    return requiredSize;
}

HRESULT UpdateDraftItemResponse::Copy(const PFCatalogUpdateDraftItemResponse& input, PFCatalogUpdateDraftItemResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CatalogItem>(input.item); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.item = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Catalog
} // namespace PlayFab
