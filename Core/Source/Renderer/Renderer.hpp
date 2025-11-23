#pragma once
#include "Camera.hpp"
#include "RenderCommand.hpp"
#include <queue>
namespace Renderer{
    class Renderer {

    public:
    static void Init();
    // Remember to put camera back in BeginScene()
    static void BeginScene();
    static void Submit(const RenderCommand& command);
    static void EndScene();

    private:
    static std::queue<RenderCommand> m_CommandQueue;
 //   static Camera& m_CurrentCamera;
    };
}
