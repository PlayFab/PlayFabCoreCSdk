// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// OperationTypes enum.
/// </summary>
enum class PFOperationTypes : uint32_t
{
    Created,
    Updated,
    Deleted,
    None
};

/// <summary>
/// ProtocolType enum.
/// </summary>
enum class PFProtocolType : uint32_t
{
    TCP,
    UDP
};

/// <summary>
/// String representation of a Json Object
/// </summary>
typedef struct PFJsonObject
{
    _Maybenull_ _Null_terminated_ const char* stringValue;
} PFJsonObject;

#ifndef PF_ENTITY_KEY_DEFINED
#define PF_ENTITY_KEY_DEFINED
/// <summary>
/// PFEntityKey data model. Combined entity type and ID structure which uniquely identifies a single
/// entity.
/// </summary>
typedef struct PFEntityKey
{
    /// <summary>
    /// Unique ID of the entity.
    /// </summary>
    _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) Entity type. See https://docs.microsoft.com/gaming/playfab/features/data/entities/available-built-in-entity-types.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* type;

} PFEntityKey;
#endif // PF_ENTITY_KEY_DEFINED

/// <summary>
/// PFPort data model.
/// </summary>
typedef struct PFPort
{
    /// <summary>
    /// The name for the port.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// The number for the port.
    /// </summary>
    int32_t num;

    /// <summary>
    /// The protocol for the port.
    /// </summary>
    PFProtocolType protocol;

} PFPort;

/// <summary>
/// Dictionary entry for an associative array with string values.
/// </summary>
typedef struct PFStringDictionaryEntry
{
    _Null_terminated_ const char* key;
    _Null_terminated_ const char* value;
} PFStringDictionaryEntry;

/// <summary>
/// Dictionary entry for an associative array with int32_t values.
/// </summary>
typedef struct PFInt32DictionaryEntry
{
    _Null_terminated_ const char* key;
    int32_t value;
} PFInt32DictionaryEntry;

/// <summary>
/// Dictionary entry for an associative array with uint32_t values.
/// </summary>
typedef struct PFUint32DictionaryEntry
{
    _Null_terminated_ const char* key;
    uint32_t value;
} PFUint32DictionaryEntry;

/// <summary>
/// Dictionary entry for an associative array with time_t values.
/// </summary>
typedef struct PFDateTimeDictionaryEntry
{
    _Null_terminated_ const char* key;
    time_t value;
} PFDateTimeDictionaryEntry;

/// <summary>
/// Dictionary entry for an associative array with PFEntityKey values.
/// </summary>
typedef struct PFEntityKeyDictionaryEntry
{
    _Null_terminated_ const char* key;
    PFEntityKey const* value;
} PFEntityKeyDictionaryEntry;

#pragma pop_macro("IN")

}
