#pragma once
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "glad/gl.h"

#include <memory>

namespace Renderer {

struct RenderCommand {
  std::shared_ptr<Shader> CommandShader;
  std::shared_ptr<VertexArray> VAO;
  int VertexCount; // TODO - Replace this with mesh
};
}
