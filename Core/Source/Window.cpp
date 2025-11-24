#include "Window.hpp"
#include "Logger.hpp"
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include <cassert>
#include <iostream>
#include "Events/MouseEvents.hpp"
#include "Events/WindowEvents.hpp"
#include "Events/KeyEvents.hpp"

namespace Core{
    Window::Window(const WindowSpec& WindowSpec) : m_WindowSpec(WindowSpec) {}

    void Window::Create() {
    // Set the window hints for GLFW.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialise GLFW
    glfwInit();
     
    // Create window and set it to be the current GLFW context.
    m_WindowHandle = glfwCreateWindow(m_WindowSpec.Width, m_WindowSpec.Height, m_WindowSpec.Name.c_str(), NULL, NULL);
    glfwMakeContextCurrent(m_WindowHandle);
    
    if (!m_WindowHandle) {
        std::cerr << "Failed to make GLFW window!" << std::endl;
        assert(false);
    }

    gladLoadGL(glfwGetProcAddress);

    // Enable vsync
    m_WindowSpec.bVsyncEnabled ? glfwSwapInterval(1) : glfwSwapInterval(0);

    glfwSetWindowUserPointer(m_WindowHandle, this);

    // We can set the callbacks here, because glfwPollEvents() will only be called once the application is actually running.
    // Note to self -- Non-capturing lambdas are required since they don't have any state, and can decay into function pointers.
    
    glfwSetCursorPosCallback(m_WindowHandle, [](GLFWwindow* window, double xpos, double ypos){
            MouseMovedEvent e(xpos, ypos);
            Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
            win->ApplicationCallback(e);
    });

    glfwSetFramebufferSizeCallback(m_WindowHandle, [](GLFWwindow* window, int width, int height){
        WindowResizeEvent e(width, height);
        Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
        win->ApplicationCallback(e);
        });

    glfwSetKeyCallback(m_WindowHandle, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        KeyPressedEvent e(key);
        Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
        win->ApplicationCallback(e);
        });
    }


    void Window::Update() {
        glfwSwapBuffers(m_WindowHandle);
    }

    bool Window::ShouldWindowClose() {
        return glfwWindowShouldClose(m_WindowHandle);
    }

    void Window::SetEventCallback(std::function<void(Event&)> func) {
       ApplicationCallback = func; 
    }


}
