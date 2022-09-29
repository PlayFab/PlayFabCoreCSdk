#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAuthenticationTests.h"
#include "XAsyncHelper.h"

uint32_t g_AuthenticationTestIndex = 1;

namespace PlayFabUnit
{

void AutoGenAuthenticationTests::LogCreateOpenIdConnectionRequest(PFAuthenticationCreateOpenIdConnectionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationCreateOpenIdConnectionRequest struct:
    // request->clientId: const char*
    if (request->clientId) { ss << "  clientId " << request->clientId; Log(ss); } else { ss << "  clientId = nullptr"; Log(ss); } // Class: const char* 
    if (request->clientSecret) { ss << "  clientSecret " << request->clientSecret; Log(ss); } else { ss << "  clientSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->connectionId) { ss << "  connectionId " << request->connectionId; Log(ss); } else { ss << "  connectionId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  ignoreNonce " << request->ignoreNonce; Log(ss); // Class: bool 
    if (request->issuerDiscoveryUrl) { ss << "  issuerDiscoveryUrl " << request->issuerDiscoveryUrl; Log(ss); } else { ss << "  issuerDiscoveryUrl = nullptr"; Log(ss); } // Class: const char* 
    ss << "  issuerInformation " << request->issuerInformation; Log(ss); // Class: PFAuthenticationOpenIdIssuerInformation 

}

void AutoGenAuthenticationTests::LogCreatePlayerSharedSecretRequest(PFAuthenticationCreatePlayerSharedSecretRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationCreatePlayerSharedSecretRequest struct:
    // request->friendlyName: const char*
    if (request->friendlyName) { ss << "  friendlyName " << request->friendlyName; Log(ss); } else { ss << "  friendlyName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogCreatePlayerSharedSecretResult(PFAuthenticationCreatePlayerSharedSecretResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationCreatePlayerSharedSecretResult    
    if (result->secretKey) { ss << "  secretKey " << result->secretKey; Log(ss); } else { ss << "  secretKey = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAuthenticationTests::LogDeleteOpenIdConnectionRequest(PFAuthenticationDeleteOpenIdConnectionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationDeleteOpenIdConnectionRequest struct:
    // request->connectionId: const char*
    if (request->connectionId) { ss << "  connectionId " << request->connectionId; Log(ss); } else { ss << "  connectionId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogDeletePlayerSharedSecretRequest(PFAuthenticationDeletePlayerSharedSecretRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationDeletePlayerSharedSecretRequest struct:
    // request->secretKey: const char*
    if (request->secretKey) { ss << "  secretKey " << request->secretKey; Log(ss); } else { ss << "  secretKey = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogGetPlayerSharedSecretsResult(PFAuthenticationGetPlayerSharedSecretsResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationGetPlayerSharedSecretsResult        
    ss << "  sharedSecretsCount " << result->sharedSecretsCount; Log(ss);

    // PFAuthenticationSharedSecret
    for (uint32_t i=0; i<result->sharedSecretsCount; i++)
    {
            ss << "  result->sharedSecrets[" << i << "]:" << result->sharedSecrets[i]; Log(ss); // PFAuthenticationSharedSecret
    } 
    return S_OK;
}

void AutoGenAuthenticationTests::LogGetPolicyRequest(PFAuthenticationGetPolicyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationGetPolicyRequest struct:
    // request->policyName: const char*
    if (request->policyName) { ss << "  policyName " << request->policyName; Log(ss); } else { ss << "  policyName = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogGetPolicyResponse(PFAuthenticationGetPolicyResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationGetPolicyResponse    
    if (result->policyName) { ss << "  policyName " << result->policyName; Log(ss); } else { ss << "  policyName = nullptr"; Log(ss); } // Class: const char*     
    ss << "  policyVersion " << result->policyVersion; Log(ss); // Class: int32_t         
    ss << "  statementsCount " << result->statementsCount; Log(ss);

    // PFAuthenticationPermissionStatement
    for (uint32_t i=0; i<result->statementsCount; i++)
    {
            ss << "  result->statements[" << i << "]:" << result->statements[i]; Log(ss); // PFAuthenticationPermissionStatement
    } 
    return S_OK;
}

HRESULT AutoGenAuthenticationTests::LogListOpenIdConnectionResponse(PFAuthenticationListOpenIdConnectionResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationListOpenIdConnectionResponse        
    ss << "  connectionsCount " << result->connectionsCount; Log(ss);

    // PFAuthenticationOpenIdConnection
    for (uint32_t i=0; i<result->connectionsCount; i++)
    {
            ss << "  result->connections[" << i << "]:" << result->connections[i]; Log(ss); // PFAuthenticationOpenIdConnection
    } 
    return S_OK;
}

void AutoGenAuthenticationTests::LogAdminSetPlayerSecretRequest(PFAuthenticationAdminSetPlayerSecretRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationSetPlayerSecretRequest struct:
    // request->playerSecret: const char*
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogUpdateOpenIdConnectionRequest(PFAuthenticationUpdateOpenIdConnectionRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationUpdateOpenIdConnectionRequest struct:
    // request->clientId: const char*
    if (request->clientId) { ss << "  clientId " << request->clientId; Log(ss); } else { ss << "  clientId = nullptr"; Log(ss); } // Class: const char* 
    if (request->clientSecret) { ss << "  clientSecret " << request->clientSecret; Log(ss); } else { ss << "  clientSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->connectionId) { ss << "  connectionId " << request->connectionId; Log(ss); } else { ss << "  connectionId = nullptr"; Log(ss); } // Class: const char* 
    if (request->issuerDiscoveryUrl) { ss << "  issuerDiscoveryUrl " << request->issuerDiscoveryUrl; Log(ss); } else { ss << "  issuerDiscoveryUrl = nullptr"; Log(ss); } // Class: const char* 
    ss << "  issuerInformation " << request->issuerInformation; Log(ss); // Class: PFAuthenticationOpenIdIssuerInformation 

}

void AutoGenAuthenticationTests::LogUpdatePlayerSharedSecretRequest(PFAuthenticationUpdatePlayerSharedSecretRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationUpdatePlayerSharedSecretRequest struct:
    // request->disabled: bool
    ss << "  disabled " << request->disabled; Log(ss); // Class: bool 
    if (request->friendlyName) { ss << "  friendlyName " << request->friendlyName; Log(ss); } else { ss << "  friendlyName = nullptr"; Log(ss); } // Class: const char* 
    if (request->secretKey) { ss << "  secretKey " << request->secretKey; Log(ss); } else { ss << "  secretKey = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogUpdatePolicyRequest(PFAuthenticationUpdatePolicyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationUpdatePolicyRequest struct:
    // request->overwritePolicy: bool
    ss << "  overwritePolicy " << request->overwritePolicy; Log(ss); // Class: bool 
    if (request->policyName) { ss << "  policyName " << request->policyName; Log(ss); } else { ss << "  policyName = nullptr"; Log(ss); } // Class: const char* 
    ss << "  policyVersion " << request->policyVersion; Log(ss); // Class: int32_t     
    ss << "  statementsCount " << request->statementsCount; Log(ss);

    // PFAuthenticationPermissionStatement
    for (uint32_t i=0; i<request->statementsCount; i++)
    {
            ss << "  request->statements[" << i << "]:" << request->statements[i]; Log(ss); // PFAuthenticationPermissionStatement
    } 

}

HRESULT AutoGenAuthenticationTests::LogUpdatePolicyResponse(PFAuthenticationUpdatePolicyResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationUpdatePolicyResponse    
    if (result->policyName) { ss << "  policyName " << result->policyName; Log(ss); } else { ss << "  policyName = nullptr"; Log(ss); } // Class: const char*         
    ss << "  statementsCount " << result->statementsCount; Log(ss);

    // PFAuthenticationPermissionStatement
    for (uint32_t i=0; i<result->statementsCount; i++)
    {
            ss << "  result->statements[" << i << "]:" << result->statements[i]; Log(ss); // PFAuthenticationPermissionStatement
    } 
    return S_OK;
}

void AutoGenAuthenticationTests::LogGetPhotonAuthenticationTokenRequest(PFAuthenticationGetPhotonAuthenticationTokenRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationGetPhotonAuthenticationTokenRequest struct:
    // request->photonApplicationId: const char*
    if (request->photonApplicationId) { ss << "  photonApplicationId " << request->photonApplicationId; Log(ss); } else { ss << "  photonApplicationId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogGetPhotonAuthenticationTokenResult(PFAuthenticationGetPhotonAuthenticationTokenResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationGetPhotonAuthenticationTokenResult    
    if (result->photonCustomAuthenticationToken) { ss << "  photonCustomAuthenticationToken " << result->photonCustomAuthenticationToken; Log(ss); } else { ss << "  photonCustomAuthenticationToken = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAuthenticationTests::LogGetTitlePublicKeyRequest(PFAuthenticationGetTitlePublicKeyRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationGetTitlePublicKeyRequest struct:
    // request->titleId: const char*
    if (request->titleId) { ss << "  titleId " << request->titleId; Log(ss); } else { ss << "  titleId = nullptr"; Log(ss); } // Class: const char* 
    if (request->titleSharedSecret) { ss << "  titleSharedSecret " << request->titleSharedSecret; Log(ss); } else { ss << "  titleSharedSecret = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogGetTitlePublicKeyResult(PFAuthenticationGetTitlePublicKeyResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationGetTitlePublicKeyResult    
    if (result->RSAPublicKey) { ss << "  RSAPublicKey " << result->RSAPublicKey; Log(ss); } else { ss << "  RSAPublicKey = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAuthenticationTests::LogLoginWithAndroidDeviceIDRequest(PFAuthenticationLoginWithAndroidDeviceIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithAndroidDeviceIDRequest struct:
    // request->androidDevice: const char*
    if (request->androidDevice) { ss << "  androidDevice " << request->androidDevice; Log(ss); } else { ss << "  androidDevice = nullptr"; Log(ss); } // Class: const char* 
    if (request->androidDeviceId) { ss << "  androidDeviceId " << request->androidDeviceId; Log(ss); } else { ss << "  androidDeviceId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->OS) { ss << "  OS " << request->OS; Log(ss); } else { ss << "  OS = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogLoginResult(PFAuthenticationLoginResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationLoginResult    
    ss << "  entityToken " << result->entityToken; Log(ss); // Class: PFAuthenticationEntityTokenResponse     
    ss << "  infoResultPayload " << result->infoResultPayload; Log(ss); // Class: PFGetPlayerCombinedInfoResultPayload     
    ss << "  lastLoginTime " << result->lastLoginTime; Log(ss); // Class: time_t     
    ss << "  newlyCreated " << result->newlyCreated; Log(ss); // Class: bool     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    if (result->sessionTicket) { ss << "  sessionTicket " << result->sessionTicket; Log(ss); } else { ss << "  sessionTicket = nullptr"; Log(ss); } // Class: const char*     
    ss << "  settingsForUser " << result->settingsForUser; Log(ss); // Class: PFAuthenticationUserSettings     
    ss << "  treatmentAssignment " << result->treatmentAssignment; Log(ss); // Class: PFTreatmentAssignment 
    return S_OK;
}

void AutoGenAuthenticationTests::LogLoginWithAppleRequest(PFAuthenticationLoginWithAppleRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithAppleRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->identityToken) { ss << "  identityToken " << request->identityToken; Log(ss); } else { ss << "  identityToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithCustomIDRequest(PFAuthenticationLoginWithCustomIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithCustomIDRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool 
    if (request->customId) { ss << "  customId " << request->customId; Log(ss); } else { ss << "  customId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithEmailAddressRequest(PFAuthenticationLoginWithEmailAddressRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithEmailAddressRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->password) { ss << "  password " << request->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithFacebookRequest(PFAuthenticationLoginWithFacebookRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithFacebookRequest struct:
    // request->accessToken: const char*
    if (request->accessToken) { ss << "  accessToken " << request->accessToken; Log(ss); } else { ss << "  accessToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithFacebookInstantGamesIdRequest(PFAuthenticationLoginWithFacebookInstantGamesIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithFacebookInstantGamesIdRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->facebookInstantGamesSignature) { ss << "  facebookInstantGamesSignature " << request->facebookInstantGamesSignature; Log(ss); } else { ss << "  facebookInstantGamesSignature = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithGameCenterRequest(PFAuthenticationLoginWithGameCenterRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithGameCenterRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerId) { ss << "  playerId " << request->playerId; Log(ss); } else { ss << "  playerId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->publicKeyUrl) { ss << "  publicKeyUrl " << request->publicKeyUrl; Log(ss); } else { ss << "  publicKeyUrl = nullptr"; Log(ss); } // Class: const char* 
    if (request->salt) { ss << "  salt " << request->salt; Log(ss); } else { ss << "  salt = nullptr"; Log(ss); } // Class: const char* 
    if (request->signature) { ss << "  signature " << request->signature; Log(ss); } else { ss << "  signature = nullptr"; Log(ss); } // Class: const char* 
    if (request->timestamp) { ss << "  timestamp " << request->timestamp; Log(ss); } else { ss << "  timestamp = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithGoogleAccountRequest(PFAuthenticationLoginWithGoogleAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithGoogleAccountRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->serverAuthCode) { ss << "  serverAuthCode " << request->serverAuthCode; Log(ss); } else { ss << "  serverAuthCode = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithGooglePlayGamesServicesRequest(PFAuthenticationLoginWithGooglePlayGamesServicesRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithGooglePlayGamesServicesRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->serverAuthCode) { ss << "  serverAuthCode " << request->serverAuthCode; Log(ss); } else { ss << "  serverAuthCode = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithIOSDeviceIDRequest(PFAuthenticationLoginWithIOSDeviceIDRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithIOSDeviceIDRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->deviceId) { ss << "  deviceId " << request->deviceId; Log(ss); } else { ss << "  deviceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->deviceModel) { ss << "  deviceModel " << request->deviceModel; Log(ss); } else { ss << "  deviceModel = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->OS) { ss << "  OS " << request->OS; Log(ss); } else { ss << "  OS = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithKongregateRequest(PFAuthenticationLoginWithKongregateRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithKongregateRequest struct:
    // request->authTicket: const char*
    if (request->authTicket) { ss << "  authTicket " << request->authTicket; Log(ss); } else { ss << "  authTicket = nullptr"; Log(ss); } // Class: const char* 
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->kongregateId) { ss << "  kongregateId " << request->kongregateId; Log(ss); } else { ss << "  kongregateId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithNintendoServiceAccountRequest(PFAuthenticationLoginWithNintendoServiceAccountRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithNintendoServiceAccountRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->identityToken) { ss << "  identityToken " << request->identityToken; Log(ss); } else { ss << "  identityToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithNintendoSwitchDeviceIdRequest(PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithNintendoSwitchDeviceIdRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->nintendoSwitchDeviceId) { ss << "  nintendoSwitchDeviceId " << request->nintendoSwitchDeviceId; Log(ss); } else { ss << "  nintendoSwitchDeviceId = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithOpenIdConnectRequest(PFAuthenticationLoginWithOpenIdConnectRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithOpenIdConnectRequest struct:
    // request->connectionId: const char*
    if (request->connectionId) { ss << "  connectionId " << request->connectionId; Log(ss); } else { ss << "  connectionId = nullptr"; Log(ss); } // Class: const char* 
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->idToken) { ss << "  idToken " << request->idToken; Log(ss); } else { ss << "  idToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithPlayFabRequest(PFAuthenticationLoginWithPlayFabRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithPlayFabRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->password) { ss << "  password " << request->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char* 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithPSNRequest(PFAuthenticationLoginWithPSNRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithPSNRequest struct:
    // request->authCode: const char*
    if (request->authCode) { ss << "  authCode " << request->authCode; Log(ss); } else { ss << "  authCode = nullptr"; Log(ss); } // Class: const char* 
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    ss << "  issuerId " << request->issuerId; Log(ss); // Class: int32_t 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->redirectUri) { ss << "  redirectUri " << request->redirectUri; Log(ss); } else { ss << "  redirectUri = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithSteamRequest(PFAuthenticationLoginWithSteamRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithSteamRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->steamTicket) { ss << "  steamTicket " << request->steamTicket; Log(ss); } else { ss << "  steamTicket = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithTwitchRequest(PFAuthenticationLoginWithTwitchRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithTwitchRequest struct:
    // request->accessToken: const char*
    if (request->accessToken) { ss << "  accessToken " << request->accessToken; Log(ss); } else { ss << "  accessToken = nullptr"; Log(ss); } // Class: const char* 
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogClientLoginWithXboxRequest(PFAuthenticationClientLoginWithXboxRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithXboxRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogRegisterPlayFabUserRequest(PFAuthenticationRegisterPlayFabUserRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationRegisterPlayFabUserRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->displayName) { ss << "  displayName " << request->displayName; Log(ss); } else { ss << "  displayName = nullptr"; Log(ss); } // Class: const char* 
    if (request->email) { ss << "  email " << request->email; Log(ss); } else { ss << "  email = nullptr"; Log(ss); } // Class: const char* 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->password) { ss << "  password " << request->password; Log(ss); } else { ss << "  password = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    ss << "  requireBothUsernameAndEmail " << request->requireBothUsernameAndEmail; Log(ss); // Class: bool 
    if (request->username) { ss << "  username " << request->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogRegisterPlayFabUserResult(PFAuthenticationRegisterPlayFabUserResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationRegisterPlayFabUserResult    
    ss << "  entityToken " << result->entityToken; Log(ss); // Class: PFAuthenticationEntityTokenResponse     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    if (result->sessionTicket) { ss << "  sessionTicket " << result->sessionTicket; Log(ss); } else { ss << "  sessionTicket = nullptr"; Log(ss); } // Class: const char*     
    ss << "  settingsForUser " << result->settingsForUser; Log(ss); // Class: PFAuthenticationUserSettings     
    if (result->username) { ss << "  username " << result->username; Log(ss); } else { ss << "  username = nullptr"; Log(ss); } // Class: const char* 
    return S_OK;
}

void AutoGenAuthenticationTests::LogClientSetPlayerSecretRequest(PFAuthenticationClientSetPlayerSecretRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationSetPlayerSecretRequest struct:
    // request->encryptedRequest: const char*
    if (request->encryptedRequest) { ss << "  encryptedRequest " << request->encryptedRequest; Log(ss); } else { ss << "  encryptedRequest = nullptr"; Log(ss); } // Class: const char* 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogAuthenticateSessionTicketRequest(PFAuthenticationAuthenticateSessionTicketRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationAuthenticateSessionTicketRequest struct:
    // request->sessionTicket: const char*
    if (request->sessionTicket) { ss << "  sessionTicket " << request->sessionTicket; Log(ss); } else { ss << "  sessionTicket = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogAuthenticateSessionTicketResult(PFAuthenticationAuthenticateSessionTicketResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationAuthenticateSessionTicketResult    
    ss << "  isSessionTicketExpired " << result->isSessionTicketExpired; Log(ss); // Class: bool     
    ss << "  userInfo " << result->userInfo; Log(ss); // Class: PFUserAccountInfo 
    return S_OK;
}

void AutoGenAuthenticationTests::LogLoginWithServerCustomIdRequest(PFAuthenticationLoginWithServerCustomIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithServerCustomIdRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->serverCustomId) { ss << "  serverCustomId " << request->serverCustomId; Log(ss); } else { ss << "  serverCustomId = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogServerLoginResult(PFAuthenticationServerLoginResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationServerLoginResult    
    ss << "  entityToken " << result->entityToken; Log(ss); // Class: PFAuthenticationEntityTokenResponse     
    ss << "  infoResultPayload " << result->infoResultPayload; Log(ss); // Class: PFGetPlayerCombinedInfoResultPayload     
    ss << "  lastLoginTime " << result->lastLoginTime; Log(ss); // Class: time_t     
    ss << "  newlyCreated " << result->newlyCreated; Log(ss); // Class: bool     
    if (result->playFabId) { ss << "  playFabId " << result->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char*     
    if (result->sessionTicket) { ss << "  sessionTicket " << result->sessionTicket; Log(ss); } else { ss << "  sessionTicket = nullptr"; Log(ss); } // Class: const char*     
    ss << "  settingsForUser " << result->settingsForUser; Log(ss); // Class: PFAuthenticationUserSettings     
    ss << "  treatmentAssignment " << result->treatmentAssignment; Log(ss); // Class: PFAuthenticationTreatmentAssignment 
    return S_OK;
}

void AutoGenAuthenticationTests::LogLoginWithSteamIdRequest(PFAuthenticationLoginWithSteamIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithSteamIdRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->steamId) { ss << "  steamId " << request->steamId; Log(ss); } else { ss << "  steamId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogServerLoginWithXboxRequest(PFAuthenticationServerLoginWithXboxRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithXboxRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->xboxToken) { ss << "  xboxToken " << request->xboxToken; Log(ss); } else { ss << "  xboxToken = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogLoginWithXboxIdRequest(PFAuthenticationLoginWithXboxIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationLoginWithXboxIdRequest struct:
    // request->createAccount: bool
    ss << "  createAccount " << request->createAccount; Log(ss); // Class: bool     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  infoRequestParameters " << request->infoRequestParameters; Log(ss); // Class: PFGetPlayerCombinedInfoRequestParams 
    if (request->sandbox) { ss << "  sandbox " << request->sandbox; Log(ss); } else { ss << "  sandbox = nullptr"; Log(ss); } // Class: const char* 
    if (request->xboxId) { ss << "  xboxId " << request->xboxId; Log(ss); } else { ss << "  xboxId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogServerSetPlayerSecretRequest(PFAuthenticationServerSetPlayerSecretRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationSetPlayerSecretRequest struct:
    // request->playerSecret: const char*
    if (request->playerSecret) { ss << "  playerSecret " << request->playerSecret; Log(ss); } else { ss << "  playerSecret = nullptr"; Log(ss); } // Class: const char* 
    if (request->playFabId) { ss << "  playFabId " << request->playFabId; Log(ss); } else { ss << "  playFabId = nullptr"; Log(ss); } // Class: const char* 

}

void AutoGenAuthenticationTests::LogAuthenticateCustomIdRequest(PFAuthenticationAuthenticateCustomIdRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationAuthenticateCustomIdRequest struct:
    // request->customId: const char*
    if (request->customId) { ss << "  customId " << request->customId; Log(ss); } else { ss << "  customId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 

}

HRESULT AutoGenAuthenticationTests::LogAuthenticateCustomIdResult(PFAuthenticationAuthenticateCustomIdResult const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationAuthenticateCustomIdResult    
    ss << "  entityToken " << result->entityToken; Log(ss); // Class: PFAuthenticationEntityTokenResponse     
    ss << "  newlyCreated " << result->newlyCreated; Log(ss); // Class: bool 
    return S_OK;
}

void AutoGenAuthenticationTests::LogDeleteRequest(PFAuthenticationDeleteRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationDeleteRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

void AutoGenAuthenticationTests::LogGetEntityTokenRequest(PFAuthenticationGetEntityTokenRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationGetEntityTokenRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    ss << "  entity " << request->entity; Log(ss); // Class: PFEntityKey 

}

HRESULT AutoGenAuthenticationTests::LogGetEntityTokenResponse(PFAuthenticationGetEntityTokenResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationGetEntityTokenResponse    
    ss << "  entity " << result->entity; Log(ss); // Class: PFEntityKey     
    if (result->entityToken) { ss << "  entityToken " << result->entityToken; Log(ss); } else { ss << "  entityToken = nullptr"; Log(ss); } // Class: const char*     
    ss << "  tokenExpiration " << result->tokenExpiration; Log(ss); // Class: time_t 
    return S_OK;
}

void AutoGenAuthenticationTests::LogValidateEntityTokenRequest(PFAuthenticationValidateEntityTokenRequest const* request, const char* testName)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return;
    }

    std::stringstream ss;
    ss << "----------"; Log(ss);
    ss << "Test #" << g_AuthenticationTestIndex++ << ": " << testName << ".  Last Known Status: "; Log(ss);
    ss << "Request:"; Log(ss);


    // PlayFabAuthenticationValidateEntityTokenRequest struct:
    // request->customTags: struct PFStringDictionaryEntry const*
    // request->customTagsCount: uint32_t    
    ss << "  customTagsCount " << request->customTagsCount; Log(ss);

    // PFStringDictionaryEntry
    for (uint32_t i=0; i<request->customTagsCount; i++)
    {
            ss << "  request->customTags[" << i << "]:" << request->customTags[i].key << "=" << request->customTags[i].value; Log(ss);
            
    } 
    if (request->entityToken) { ss << "  entityToken " << request->entityToken; Log(ss); } else { ss << "  entityToken = nullptr"; Log(ss); } // Class: const char* 

}

HRESULT AutoGenAuthenticationTests::LogValidateEntityTokenResponse(PFAuthenticationValidateEntityTokenResponse const* result)
{
    if (!TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        return S_OK;
    }

    std::stringstream ss;
    ss << "Response:"; Log(ss);

    // Found PlayFabAuthenticationValidateEntityTokenResponse    
    ss << "  entity " << result->entity; Log(ss); // Class: PFEntityKey     
    ss << "  identifiedDeviceType " << result->identifiedDeviceType; Log(ss); // Class: PFAuthenticationIdentifiedDeviceType     
    ss << "  identityProvider " << result->identityProvider; Log(ss); // Class: PFLoginIdentityProvider     
    if (result->identityProviderIssuedId) { ss << "  identityProviderIssuedId " << result->identityProviderIssuedId; Log(ss); } else { ss << "  identityProviderIssuedId = nullptr"; Log(ss); } // Class: const char*     
    ss << "  lineage " << result->lineage; Log(ss); // Class: PFEntityLineage 
    return S_OK;
}

 

}
