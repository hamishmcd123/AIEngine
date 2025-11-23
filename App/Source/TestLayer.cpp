#include "TestLayer.hpp"
#include "Renderer/BufferElement.hpp"
#include "Renderer/RenderCommand.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/VertexBuffer.hpp"
#include "imgui.h"
#include <memory>

namespace App {

void TestLayer::OnUpdate(float ts) {}

void TestLayer::OnRender() {
  Renderer::Renderer::Submit(Renderer::RenderCommand{m_Shader, m_VAO, 3});
}

void TestLayer::ImGuiRender() {}

void TestLayer::OnEvent(Core::Event &e) {}

TestLayer::TestLayer() {

  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

  m_Shader = std::make_shared<Renderer::Shader>("Resources/vert.glsl",
                                              "Resources/frag.glsl");
  m_VBO = std::make_shared<Renderer::VertexBuffer>(vertices, sizeof(vertices));
  m_VAO = std::make_shared<Renderer::VertexArray>();

  Renderer::BufferLayout BufferLayout = {
      {"", 3, Renderer::ShaderDataType::Float, false}};

  m_VAO->AddLayout(m_VBO, BufferLayout);
}

TestLayer::~TestLayer() {}

} // namespace App
