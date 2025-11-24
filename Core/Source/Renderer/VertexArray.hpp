#pragma once 
#include "glad/gl.h"
#include "VertexBuffer.hpp"
#include "BufferElement.hpp"
#include <memory>

namespace Renderer {
class VertexArray{
    public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void AddLayout(std::shared_ptr<VertexBuffer> VBO, BufferLayout& Layout);

    size_t GetVertexCount() const {return m_VertexCount;}


    private:
    GLuint m_ArrayID;
    size_t m_VertexCount;
    GLuint m_Index = 0;
};
}
