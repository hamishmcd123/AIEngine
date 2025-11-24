#include "TestLayer.hpp"
#include "Application.hpp"
#include "Renderer/BufferElement.hpp"
#include "Renderer/Camera.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/VertexBuffer.hpp"
#include "imgui.h"
#include <memory>

namespace App {

void TestLayer::OnUpdate(float ts) {}

void TestLayer::OnRender() {
  Renderer::Renderer::Submit(Renderer::RenderCommand{m_Shader, m_VAO, 36});
}

void TestLayer::ImGuiRender() {}

void TestLayer::OnEvent(Core::Event &e) {}

TestLayer::TestLayer() {

  float vertices[] = {
      // Front face (Z =  0.5)
      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      -0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,

      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,
      -0.5f,
      0.5f,
      0.5f,

      // Back face (Z = -0.5)
      -0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      -0.5f,

      -0.5f,
      -0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      0.5f,
      0.5f,
      -0.5f,

      // Left face (X = -0.5)
      -0.5f,
      -0.5f,
      -0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      0.5f,
      0.5f,

      -0.5f,
      -0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      -0.5f,
      0.5f,
      -0.5f,

      // Right face (X = 0.5)
      0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,
      -0.5f,
      0.5f,

      0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      -0.5f,
      0.5f,
      0.5f,
      0.5f,

      // Top face (Y = 0.5)
      -0.5f,
      0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,

      -0.5f,
      0.5f,
      -0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,
      0.5f,
      -0.5f,

      // Bottom face (Y = -0.5)
      -0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      -0.5f,
      0.5f,

      -0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      -0.5f,
      0.5f,
      -0.5f,
      0.5f,
  };

  // Change this eventually. This is creating a needless copy of Camera.
  glm::ivec2 FrameBufferSize = Core::Application::Get()->GetWindowSize();
  m_Camera = Renderer::Camera(FrameBufferSize.x, FrameBufferSize.y, 45.0);

  Renderer::Renderer::SetCurrentCamera(&m_Camera);

  m_Shader = std::make_shared<Renderer::Shader>("Resources/vert.glsl",
                                                "Resources/frag.glsl");
  m_VBO = std::make_shared<Renderer::VertexBuffer>(vertices, sizeof(vertices));
  m_VAO = std::make_shared<Renderer::VertexArray>();

  Renderer::BufferLayout BufferLayout = {
      {"Vertices", 3, Renderer::ShaderDataType::Float, false}};

  m_VAO->AddLayout(m_VBO, BufferLayout);
}

TestLayer::~TestLayer() {}

} // namespace App
