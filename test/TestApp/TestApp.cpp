﻿// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#include <cstdarg>
#include <functional>
#include <thread>

#include "TestApp.h"
#include "TestRunner.h"
#include "TestReport.h"
#include "TestUtils.h"

#include <httpClient/httpClient.h>
#include "ApiTests.h" 
#include "EntityTests.h"

#include "AutoGenTests/AutoGenEventsTests.h" 
#include "AutoGenTests/AutoGenAccountManagementTests.h" 
#include "AutoGenTests/AutoGenPlayerDataManagementTests.h" 
#include "AutoGenTests/AutoGenFriendsTests.h" 
#include "AutoGenTests/AutoGenSharedGroupsTests.h" 
#include "AutoGenTests/AutoGenDataTests.h" 
#include "AutoGenTests/AutoGenGroupsTests.h" 
#include "AutoGenTests/AutoGenProfilesTests.h" 

using namespace PlayFab;

namespace PlayFabUnit
{
PFTestTraceLevel TestApp::traceLevel = PFTestTraceLevel::Important;

#if !defined(DISABLE_PLAYFABCLIENT_API)
    // Time out if waiting for the final cloudscript submission longer than this
    constexpr int CLOUDSCRIPT_TIMEOUT_MS = 30000;
#endif // !defined(DISABLE_PLAYFABCLIENT_API)


    void TestApp::LogInit()
    {
        // Delete existing log file if it exists
        std::remove(s_logfileName);
    }

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestApp::Log(const char* format, ...)
    {
        static char message[1024*64];

        va_list args;
        va_start(args, format);
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        vsnprintf_s(message, sizeof(message), format, args);
#elif defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_SWITCH)
        vsnprintf(message, sizeof(message), format, args);
#else
        _vsnprintf_s(message, sizeof(message), format, args);
#endif // defined(PLAYFAB_PLATFORM_PLAYSTATION)
        va_end(args);

        // Output the message in a platform-dependent way.
        LogPut(message);
    }
#endif

    int TestApp::Main()
    {
        TestApp::LogInit();

        HCSettingsSetTraceLevel(HCTraceLevel::Verbose);
        HCTraceSetTraceToDebugger(true);

        // Load the TestTitleData
        TestTitleData testTitleData;
        bool loadSuccessful = LoadTitleData(testTitleData);

        // If the title data fails to load, and you want to use custom hard-coded data, you can
        // comment out the return statement and fill out the TestTitleData fields manually.
        if (!loadSuccessful)
        {
            // TODO: POPULATE THIS SECTION WITH REAL INFORMATION (or set up a testTitleData file, and set your PF_TEST_TITLE_DATA_JSON to the path for that file)
            testTitleData.titleId = ""; // The titleId for your title, found in the "Settings" section of PlayFab Game Manager
            testTitleData.userEmail = ""; // This is the email for a valid user (test tries to log into it with an invalid password, and verifies error result)
            testTitleData.developerSecretKey = "";
            testTitleData.connectionString = "";
        }

        // Initialize the test runner/test data.
        TestRunner testRunner;

        EntityTests entityTests;
        entityTests.SetTitleInfo(testTitleData);
        testRunner.Add(entityTests);

        ApiTests apiTests;
        apiTests.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests);


        AutoGenEventsTests apiTests4;
        apiTests4.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests4);

        AutoGenAccountManagementTests apiTests7;
        apiTests7.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests7);

        AutoGenPlayerDataManagementTests apiTests14;
        apiTests14.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests14);

        AutoGenFriendsTests apiTests19;
        apiTests19.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests19);

        AutoGenSharedGroupsTests apiTests20;
        apiTests20.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests20);

        AutoGenDataTests apiTests25;
        apiTests25.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests25);

        AutoGenGroupsTests apiTests28;
        apiTests28.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests28);

        AutoGenProfilesTests apiTests31;
        apiTests31.SetTitleInfo(testTitleData);
        testRunner.Add(apiTests31);


        // Run the tests (blocks until all tests have finished).
        testRunner.Run(); 

        // Publish the test summary to STDOUT.
        Log("%s\n", testRunner.suiteTestSummary.c_str());

        // Return 0 (success) if all tests passed. Otherwise, return 1 (error).
        return testRunner.AllTestsPassed()
#if !defined(DISABLE_PLAYFABCLIENT_API)
            && !cloudResponse.empty() ? 0 : 1
#endif // !defined(DISABLE_PLAYFABCLIENT_API)
            ;
    }

    bool TestApp::LoadTitleData(TestTitleData& titleData)
    {
        // Load JSON string in a platform-dependent way.
        std::shared_ptr<char*> titleJsonPtr;
        size_t size;
        const bool loadedSuccessfully = LoadTitleDataJson(titleJsonPtr, size);

        if (!loadedSuccessfully)
        {
            return false;
        }

        // Parse JSON string into output TestTitleData.
        JsonDocument titleDataJson;
        titleDataJson.Parse(*titleJsonPtr);

        if (!titleDataJson.HasParseError())
        {
            titleData.titleId = titleDataJson["titleId"].GetString();
            if (titleDataJson.HasMember("userEmail"))
            {
                titleData.userEmail = titleDataJson["userEmail"].GetString();
            }
            if (titleDataJson.HasMember("developerSecretKey"))
            {
                titleData.developerSecretKey = titleDataJson["developerSecretKey"].GetString();
            }
            if (titleDataJson.HasMember("connectionString"))
            {
                titleData.connectionString = titleDataJson["connectionString"].GetString();
            }
        }

        return !titleDataJson.HasParseError();
    }
}
