#pragma once 

#include <initializer_list>
#include <vector>
#include <string>
#include "glad/gl.h"
#include <cstdint>

namespace Renderer {

    enum class ShaderDataType {
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
    };

	static size_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:    return 4;
			case ShaderDataType::Float2:   return 4 * 2;
			case ShaderDataType::Float3:   return 4 * 3;
			case ShaderDataType::Float4:   return 4 * 4;
			case ShaderDataType::Mat3:     return 4 * 3 * 3;
			case ShaderDataType::Mat4:     return 4 * 4 * 4;
			case ShaderDataType::Int:      return 4;
			case ShaderDataType::Int2:     return 4 * 2;
			case ShaderDataType::Int3:     return 4 * 3;
			case ShaderDataType::Int4:     return 4 * 4;
			case ShaderDataType::Bool:     return 1;
            case ShaderDataType::None: return 0;
		}
        return 0;
	}
    
    static GLenum ShaderDataTypeToGLEnum(ShaderDataType type) {
        switch (type)
		{
			case ShaderDataType::Float:
			case ShaderDataType::Float2:
			case ShaderDataType::Float3:
			case ShaderDataType::Float4:
			case ShaderDataType::Mat3:
			case ShaderDataType::Mat4:
                return GL_FLOAT;

			case ShaderDataType::Int:
			case ShaderDataType::Int2:
			case ShaderDataType::Int3:
			case ShaderDataType::Int4:
                return GL_INT;

			case ShaderDataType::Bool:
                return GL_BOOL;

            case ShaderDataType::None: return 0;
		}
        return 0;
    }


    // Maybe add ShaderDataType to Count
    
    class BufferElement {
    public: 
    BufferElement(const std::string AttribName, size_t Count, ShaderDataType Type, bool IsNormalised) :
    m_AttribName(AttribName), m_Count(Count), m_DataType(Type), bIsNormalised(IsNormalised)
    {
        m_Size = ShaderDataTypeSize(m_DataType);
    }

    size_t GetSize() const {return m_Size;}
    size_t GetCount() const {return m_Count;}
    size_t m_Offset;
    ShaderDataType GetDataType() const {return m_DataType;}
    bool IsNormalised() const {return bIsNormalised;}
    private:
    std::string m_AttribName;
    ShaderDataType m_DataType;
    bool bIsNormalised = false;
    size_t m_Count;
    size_t m_Size;
   };

    class BufferLayout {
    public:
    BufferLayout(std::initializer_list<BufferElement> elements) : m_Elements(elements) {

        size_t RunningOffset = 0;

        for (BufferElement& element : m_Elements) {
            element.m_Offset = RunningOffset;
            m_Stride += element.GetSize() * element.GetCount();
            RunningOffset += element.GetSize() * element.GetCount();
        }
    }

    size_t GetStride() {return m_Stride;}

    const std::vector<BufferElement>& GetElements() {return m_Elements;};

    private:
    std::vector<BufferElement> m_Elements;
    size_t m_Stride = 0;
    };
}
