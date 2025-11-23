#include "Application.hpp"
#include "Event.hpp"
#include "Events/WindowEvents.hpp"
#include "GLFW/glfw3.h"
#include <GL/gl.h>
#include <memory>
#include "ImguiLayer.hpp"
#include "Window.hpp"
#include "Logger.hpp"

namespace Core{
    
    Application* Application::s_Instance = nullptr;

    Application::Application(const ApplicationSpec& AppSpec) {
        Logger::init();
        m_Window = std::make_shared<Window>(AppSpec.m_WindowSpec);
        m_Window->Create();
        m_Window->SetEventCallback([this](Event& e) -> void {this->OnEvent(e);});
        s_Instance = this;
        m_ImguiLayer = std::make_unique<ImguiLayer>();
    }

    float Application::GetTime() {
        return (float)glfwGetTime();
    }

    void Application::Run() {
        float LastTime = GetTime();

        // Temp -- Set clear colour for GlClear before
        glClearColor(1 ,1 ,1 ,0);

        bRunning = true;
        while(bRunning) {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT );
            // Get deltaTime
            float CurrentTime = GetTime();
            float deltaTime = CurrentTime - LastTime;
            LastTime = CurrentTime;

            for (const auto& Layer : LayerStack) {
                Layer->OnUpdate(deltaTime);
            }

            // For layers using ImGui...
            // NOTE TO SELF 22/11/25 -- We split the for loop into two separate for loops to guarantee that
            // game logic happens before rendering the ImGui shit
            
            m_ImguiLayer->Begin();
            for (const auto& Layer : LayerStack) {
                Layer->ImGuiRender();
            }
            m_ImguiLayer->End();

            m_Window->Update();
        }
    }

    Window* Application::GetWindow() {
        return m_Window.get();
    }

    Application* Application::Get() {
        return s_Instance;
    }

    void Application::OnEvent(Event& e) {

        // Application will handle specific events.
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) -> bool{
                bRunning = false;
                return true;
        });

        dispatcher.Dispatch<WindowResizeEvent>([](WindowResizeEvent& e) -> bool {
            glViewport(0, 0, e.GetWindowWidth(), e.GetWindowHeight());
            return true;
        });


        // Send the event from the bottom to the top. This ensures that layers like the editor layer get it first...
        for (auto it = LayerStack.rbegin(); it != LayerStack.rend(); it++) {
            it->get()->OnEvent(e);
        }
    }
}

