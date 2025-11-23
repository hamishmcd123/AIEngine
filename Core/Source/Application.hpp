#pragma once
#include "Event.hpp"
#include "Window.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <type_traits>
#include "Layer.hpp"
#include "ImguiLayer.hpp"

namespace Core{
    struct ApplicationSpec {
        WindowSpec m_WindowSpec;
        std::string m_AppName;
    };

class Application{
    public:
    Application(const ApplicationSpec& AppSpec);

    void Run();

    template<typename TLayer, typename ...Args>
    std::enable_if_t<std::is_base_of_v<Layer, TLayer>, void>
    PushNewLayer(Args&& ...args) {
        LayerStack.push_back(std::make_unique<TLayer>(std::forward<Args>(args)...));
    }

    void OnEvent(Event& e);

    float GetTime();

    static Application* Get();

    Window* GetWindow();

    private:
    std::shared_ptr<Window> m_Window = nullptr;
    std::unique_ptr<ImguiLayer> m_ImguiLayer;
    ApplicationSpec m_ApplicationSpec;
    std::vector<std::unique_ptr<Layer>> LayerStack;
    bool bRunning = false;
    static Application* s_Instance;
};

}

