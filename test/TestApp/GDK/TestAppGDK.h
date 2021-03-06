// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
#pragma once

#include "DeviceResources.h"
#include "ATGTK/TextConsole.h"
#include "StepTimer.h"
#include "SampleGUI.h"

class Sample;

// A basic sample implementation that creates a D3D12 device and
// provides a render loop.
class Sample final : public DX::IDeviceNotify
{
public:

    Sample() noexcept(false);
    ~Sample();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic render loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowMoved();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize(int& width, int& height) const;

    std::unique_ptr<DX::TextConsoleImage> m_log;

private:
    bool m_testsStarted{ false };
    float m_startTimer{ 1.0f };
    std::atomic<bool> m_testsCompleted{ false };

    void RunTests();

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void SetupUI();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>        m_deviceResources;

    // Rendering loop timer.
    uint64_t                                    m_frame;
    DX::StepTimer                               m_timer;

    // Input devices.
    std::unique_ptr<DirectX::GamePad>           m_gamePad;
    std::unique_ptr<DirectX::Keyboard>          m_keyboard;
    std::unique_ptr<DirectX::Mouse>             m_mouse;

    DirectX::GamePad::ButtonStateTracker        m_gamePadButtons;
    DirectX::Keyboard::KeyboardStateTracker     m_keyboardButtons;

    // DirectXTK objects.
    std::unique_ptr<DirectX::GraphicsMemory>    m_graphicsMemory;
    std::unique_ptr<DirectX::DescriptorPile>    m_resourceDescriptors;

    // UI Objects
    std::shared_ptr<ATG::UIManager>             m_ui;

    XTaskQueueHandle                            m_asyncQueue;

    enum Descriptors
    {
        Font,
        ConsoleFont,
        Background,
        ConsoleBackground,
        Reserve,
        Count = 32,
    };
};