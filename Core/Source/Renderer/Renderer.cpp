#include "Renderer.hpp"
#include "Application.hpp"
#include "Renderer/RenderCommand.hpp"
#include "glad/gl.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/trigonometric.hpp"
#include "imgui.h"
#include <queue>

namespace Renderer {
std::queue<RenderCommand> Renderer::m_CommandQueue;
Camera *Renderer::m_CurrentCamera = nullptr;

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
    
    // Change this
    glm::mat4 Model(1.0f);
    float time = Core::Application::Get()->GetTime();
    Model = glm::rotate(Model, time * glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    currentCommand.CommandShader->SetMat4("model", Model);
    currentCommand.CommandShader->SetMat4("view", Renderer::m_CurrentCamera->GetViewMatrix());
    currentCommand.CommandShader->SetMat4("proj", Renderer::m_CurrentCamera->GetPerspectiveMatrix());

    glDrawArrays(GL_TRIANGLES, 0, currentCommand.VertexCount);

    m_CommandQueue.pop();
  }
}

void Renderer::SetCurrentCamera(Camera *Camera){
    m_CurrentCamera = Camera;
}



  void Renderer::UpdateCurrentCameraPerspectiveMatrix(const int Width, const int Height) {
    m_CurrentCamera->UpdatePerspectiveMatrix(Width, Height);
  }
} // namespace Renderer
