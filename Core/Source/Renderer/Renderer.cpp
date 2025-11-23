#include "Renderer.hpp"
#include "Renderer/RenderCommand.hpp"
#include "glad/gl.h"
#include "imgui.h"
#include <iostream>
#include <queue>

namespace Renderer {
std::queue<RenderCommand> Renderer::m_CommandQueue;

void Renderer::Init() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Renderer::BeginScene() {
  //        m_CurrentCamera = Camera;

  // Empty the queue with guaranteed memory release.
  std::queue<RenderCommand> empty;
  m_CommandQueue.swap(empty);
}

void Renderer::Submit(const RenderCommand &command) {
  m_CommandQueue.push(command);
}

void Renderer::EndScene() {

  while (!m_CommandQueue.empty()) {
    RenderCommand &currentCommand = m_CommandQueue.front();
    currentCommand.CommandShader->Bind();
    currentCommand.VAO->Bind();
    glDrawArrays(GL_TRIANGLES, 0, currentCommand.VertexCount);

    m_CommandQueue.pop();
  }
}

} // namespace Renderer
