#pragma once
#include "Camera.hpp"
#include "RenderCommand.hpp"
#include <queue>
namespace Renderer{
    class Renderer {

    public:
    static void Init();
    static void BeginScene(Camera& Camera);
    static void EndScene();

    private:
    std::queue<RenderCommand> m_CommandQueue;

    };
}
