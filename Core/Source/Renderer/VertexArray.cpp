#include "VertexArray.hpp"

#include <iostream>

#include "Renderer/BufferElement.hpp"
#include "Renderer/VertexBuffer.hpp"
#include "glad/gl.h"
#include <memory>
#include <ostream>
#include <strings.h>


namespace Renderer {
    
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_ArrayID);
    }
    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_ArrayID);
    }

    void VertexArray::Bind() const {
        glBindVertexArray(m_ArrayID);
    }

    void VertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void VertexArray::AddLayout(std::shared_ptr<VertexBuffer> VBO, BufferLayout& Layout) {

        Bind();
        VBO->Bind();

        const std::vector<BufferElement>& Elements = Layout.GetElements();
        for (const auto& BufferElement : Elements) {
            glVertexAttribPointer(m_Index,
                    BufferElement.GetCount(), 
                    ShaderDataTypeToGLEnum(BufferElement.GetDataType()),
                    BufferElement.IsNormalised() ? GL_TRUE : GL_FALSE,
                    Layout.GetStride(), 
                    (void*)BufferElement.m_Offset
                    );
            glEnableVertexAttribArray(m_Index);
            m_Index++;
        }

        VBO->Unbind();
        Unbind();
    }

}
