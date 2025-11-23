#pragma once
#include "glad/gl.h"
#include <stddef.h>
namespace Renderer {

    class VertexBuffer {

    VertexBuffer(const void* data, const size_t size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

    private:
        GLuint m_BufferID;
    };

}
