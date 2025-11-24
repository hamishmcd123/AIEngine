#pragma once

#include <cstdint>
#include <string>
#include "Event.hpp"

class GLFWwindow;

namespace Core{

struct WindowSpec{
    uint16_t Width;
    uint16_t Height;
    std::string Name;
    bool bVsyncEnabled = true;
};

class Window{
    public:
    Window(const WindowSpec& WindowSpec);

    void Create();
    void Update();
    void Destroy();

    bool ShouldWindowClose();

    void ClearWindow();

    void SetEventCallback(std::function<void(Event&)> func);

    GLFWwindow* GetHandle() const {return m_WindowHandle;}
    
    private:
    GLFWwindow* m_WindowHandle = nullptr;
    WindowSpec m_WindowSpec;
    std::function<void(Event&)> ApplicationCallback;
};


}

