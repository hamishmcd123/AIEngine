#pragma once
#include "Camera.hpp"
#include "RenderCommand.hpp"
#include <queue>
namespace Renderer {
class Renderer {

public:
  static void Init();
  static void BeginScene();
  static void Submit(const RenderCommand &command);
  static void EndScene();
  static void SetCurrentCamera(Camera* Camera);
  static void UpdateCurrentCameraPerspectiveMatrix(const int Width, const int Height);

private:
  static std::queue<RenderCommand> m_CommandQueue;
  static Camera* m_CurrentCamera;
};
} // namespace Renderer
