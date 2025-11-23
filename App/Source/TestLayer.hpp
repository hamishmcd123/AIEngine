#pragma once 
#include <memory>
#include <type_traits>
#include <vector>
#include <cassert>
#include "Layer.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/VertexBuffer.hpp"
#include <memory>

namespace App {

class TestLayer final : public Core::Layer {
    public:
    TestLayer();
    ~TestLayer();
    void OnUpdate(float ts) override;
    void OnRender() override;
    void ImGuiRender() override;
    void OnEvent(Core::Event& e) override;

    private:
    std::shared_ptr<Renderer::VertexBuffer> m_VBO;
    std::shared_ptr<Renderer::VertexArray> m_VAO;
    std::shared_ptr<Renderer::Shader> m_Shader;

};

}
