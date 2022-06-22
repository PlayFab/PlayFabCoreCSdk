`**********************************************************************`
`* This is a template file for the tracewpp preprocessor.             *`
`* If you need to use a custom version of this file in your project,  *`
`* please clone it from this one and point WPP to it by specifying    *`
`* -gen:{yourfile}*.tmh on the RUN_WPP line in your sources file.     *`
`*                                                                    *`
`*    Copyright (c) Microsoft Corporation. All rights reserved.       *`
`**********************************************************************`
// Checksum="`Compiler.Checksum`" Generated file. Do not edit.
// File created by `Compiler.Name` compiler version `Compiler.Version`
// from template `TemplateFile`

// ***************************************************************************
// PREVIEW: Behavior of the -man option, the `TemplateFile` template, and the
// associated configuration options may change in future versions of tracewpp.
// ***************************************************************************

#pragma once

// Define the macros (if any) specified on the tracewpp command line.
// -- Begin macro definitions.
`FORALL def IN MacroDefinitions`
#define `def.Name` `def.Alias`
`ENDFOR`
// -- End macro definitions.

// The "`Manifest.HeaderFileName`" file should be generated by running the
// MC.exe tool: mc.exe -um `Manifest.Arguments`
#include "`Manifest.HeaderFileName`"
`IF FOUND WPP_INIT_TRACING`

#ifndef WPP_INIT_TRACING
#define WPP_INIT_TRACING(...) WPP_INIT()
#endif
`ENDIF FOUND WPP_INIT_TRACING`

// WPP_LOG_ALWAYS:
// Called for each event: WPP_LOG_ALWAYS(EX, MSG, arg1, arg2, arg3...) Other()
// If defined, the definition needs to include a trailing comma or semicolon.
// In addition, you will need to define a WPP_EX_[args](args...) macro to
// extract any needed information from the other arguments (e.g. LEVEL).
#ifndef WPP_LOG_ALWAYS
#define WPP_LOG_ALWAYS(...)
#endif

// WPP_DEBUG:
// Called for each enabled event: WPP_DEBUG((MSG, arg1, arg2, arg3...)), Other()
// Potential definition: printf MsgArgs
// Definition should not include any trailing comma or semicolon.
#ifdef WPP_DEBUG
#define WPP_INVOKE_WPP_DEBUG(MsgArgs) WPP_DEBUG(MsgArgs)
#else // WPP_DEBUG
#define WPP_INVOKE_WPP_DEBUG(MsgArgs) (void)0
#endif // WPP_DEBUG

#ifndef WPP_FORCEINLINE
#define WPP_FORCEINLINE __forceinline
#endif

#define WPP_THIS_FILE `SourceFile.CanonicalName`

#define WPP_FLATTEN(...) __VA_ARGS__
#define WPP_INVOKE_MCMACRO(f, args) f args
#define WPP_EVAL(x) x
#define WPP_(Id) WPP_EVAL(WPP_)##WPP_EVAL(Id)##WPP_EVAL(_)##WPP_EVAL(WPP_THIS_FILE)##WPP_EVAL(__LINE__)

// Calls EventRegister_[ProviderName] for each provider in the generated manifest.
#define WPP_INIT() \
    { \
`FORALL ControlGuid IN ControlGuids`
`  FORALL TraceGuid IN ControlGuid.TraceGuids`
    EventRegister_`ControlGuid.Symbol``IF TraceGuid No`_`TraceGuid.No``ENDIF`(); \
`  ENDFOR TraceGuid`
`ENDFOR ControlGuid`
    }

// Calls EventUnregister_[ProviderName] for each provider in the generated manifest.
#define WPP_CLEANUP() \
    { \
`FORALL ControlGuid IN ControlGuids`
`  FORALL TraceGuid IN ControlGuid.TraceGuids`
    EventUnregister_`ControlGuid.Symbol``IF TraceGuid No`_`TraceGuid.No``ENDIF`(); \
`  ENDFOR TraceGuid`
`ENDFOR ControlGuid`
    }

// Adapters

#ifndef WPP_ADAPTER_PUSTR
#ifdef WPP_CHECK_FOR_NULL_STRING
# define WPP_ADAPTER_PUSTR(x) \
        (x) ? (x)->Length/2 : 4, \
        (x) ? (x)->Buffer   : L"NULL"
#else // WPP_CHECK_FOR_NULL_STRING
# define WPP_ADAPTER_PUSTR(x) (x)->Length/2, (x)->Buffer
#endif // WPP_CHECK_FOR_NULL_STRING
#endif // WPP_ADAPTER_PUSTR

#ifndef WPP_ADAPTER_PCSTR
#ifdef WPP_CHECK_FOR_NULL_STRING
# define WPP_ADAPTER_PCSTR(x) \
        (x) ? (x)->Length : 4, \
        (x) ? (x)->Buffer : "NULL"
#else // WPP_CHECK_FOR_NULL_STRING
# define WPP_ADAPTER_PCSTR(x) (x)->Length, (x)->Buffer
#endif // WPP_CHECK_FOR_NULL_STRING
#endif // WPP_ADAPTER_PCSTR

#ifndef WPP_ADAPTER_PSID
# define WPP_ADAPTER_PSID(pSid) (const SID*)pSid
#endif // WPP_ADAPTER_PSID

#ifndef WPP_ADAPTER_PVOID
# define WPP_ADAPTER_PVOID(intptr) (const void*)intptr
#endif // WPP_ADAPTER_PVOID

#ifndef WPP_ADAPTER_PFILETIME
# define WPP_ADAPTER_PFILETIME(i64) (const FILETIME*)&i64
#endif // WPP_ADAPTER_PFILETIME

#ifdef __cplusplus

#ifndef WPP_ADAPTER_CPPSTR
#define WPP_ADAPTER_CPPSTR(x) static_cast<USHORT>(x.size()), x.c_str()
#endif // WPP_ADAPTER_CPPSTR

#ifndef WPP_ADAPTER_CPPVEC
#define WPP_ADAPTER_CPPVEC(x) static_cast<USHORT>(x.size()), x.data()
#endif // WPP_ADAPTER_CPPVEC

#endif // __cplusplus

// Functions

`FORALL f IN Funcs WHERE !DoubleP && !MsgArgs`
#undef `f.Name`
#define `f.Name` WPP_(CALL)
`ENDFOR`
`FORALL f IN Funcs WHERE DoubleP && !MsgArgs`
#undef `f.Name`
#define `f.Name`(ARGS) WPP_(CALL) ARGS
`ENDFOR`
`FORALL f IN Funcs WHERE MsgArgs`
#undef `f.Name`
#define `f.Name`(`f.FixedArgs` MSGARGS) WPP_(CALL)(`f.FixedArgs` MSGARGS)
`ENDFOR`
`FORALL r IN Reorder`
#undef  WPP_REORDER_`r.Name`
#define WPP_REORDER_`r.Name`(`r.Arguments`) `r.PermutationNoLeadingComma`
`ENDFOR`

// Messages
`FORALL i IN Messages WHERE !MsgArgs`

// `i.Name`
#ifndef WPP`i.GooId`_PRE
#  define WPP`i.GooId`_PRE(`i.GooArgs`)
#endif
#ifndef WPP`i.GooId`_POST
#  define WPP`i.GooId`_POST(`i.GooArgs`)
#endif
WPP_FORCEINLINE ULONG WPP_MFUNC_`i.Name`(`i.FuncArgDecls`)
{ return WPP_INVOKE_MCMACRO(`Manifest.Prefix``i.Name`_AssumeEnabled, (`i.FuncArgExprs`)); }
#define WPP_CALL_`i.Name`(`i.FixedArgs``i.MacroArgs`) \
    WPP_LOG_ALWAYS(WPP_EX`i.GooId`(`i.GooVals`), `i.DbgMacroArgs`) \
    WPP`i.GooId`_PRE(`i.GooVals`) \
    (( \
        MCGEN_EVENT_ENABLED(`i.Name`) \
        ?   WPP_INVOKE_WPP_DEBUG((`i.DbgMacroArgs`)), \
            WPP_MFUNC_`i.Name`(`i.MacroExprsNoLeadingComma`) \
        :   0 \
    )) \
    WPP`i.GooId`_POST(`i.GooVals`)
`ENDFOR i IN Messages WHERE !MsgArgs`
`FORALL i IN Messages WHERE MsgArgs`

// `i.Name`
#ifndef WPP`i.GooId`_PRE
#  define WPP`i.GooId`_PRE(`i.GooArgs`)
#endif
#ifndef WPP`i.GooId`_POST
#  define WPP`i.GooId`_POST(`i.GooArgs`)
#endif
WPP_FORCEINLINE ULONG WPP_MFUNC_`i.Name`(`i.FuncArgDecls`)
{ return WPP_INVOKE_MCMACRO(`Manifest.Prefix``i.Name`_AssumeEnabled, (`i.FuncArgExprs`)); }
#define WPP_CALL_`i.Name`(`i.FixedArgs` MSGARGS) \
    WPP_LOG_ALWAYS(WPP_EX`i.GooId`(`i.GooVals`), WPP_FLATTEN MSGARGS) \
    WPP`i.GooId`_PRE(`i.GooVals`) \
    (( \
        MCGEN_EVENT_ENABLED(`i.Name`) \
        ?   WPP_INVOKE_WPP_DEBUG(MSGARGS), \
            WPP_MFUNC_`i.Name` WPP_EVAL((WPP_REORDER_`i.ReorderSig` MSGARGS)) \
        :   0 \
    )) \
    WPP`i.GooId`_POST(`i.GooVals`)
`ENDFOR i IN Messages WHERE MsgArgs`