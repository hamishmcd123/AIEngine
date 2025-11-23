#pragma once
#include <fstream>
#include "glm/glm.hpp"
#include "glad/gl.h"
#include <string>

namespace Renderer {
    class Shader {
    public:
        Shader();
        Shader(const std::string& VertexPath, const std::string& FragPath);
        void DeleteShader();
        void Bind() const;
        void Unbind() const;

        void SetMat4(const char* UniformName, const glm::mat4x4& mat) const;
        void SetBool (const char* UniformName, const bool boolean) const;
        void SetInt(const char* UniformName, const int integer) const;
        void SetFloat(const char* UniformName, const float floating) const;
        void SetVec3(const char* UniformName, const glm::vec3& vec) const;
        void SetVec4(const char* UniformName, const glm::vec4& vec) const;

    private:
        GLuint m_ShaderID;
        std::string m_Storedfpath;
    };
}

