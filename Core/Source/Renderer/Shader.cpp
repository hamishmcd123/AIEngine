#include "Shader.hpp"
#include <GL/gl.h>
#include <GL/glext.h>
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <string>
#include "../Logger.hpp"
#include "glad/gl.h"
#include <cassert>

namespace Renderer {
    Shader::Shader(const std::string& VertexPath, const std::string& FragPath){

	std::ifstream fstream;

    std::string VertexSource;
    std::string FragmentSource;

    // Load the vertex shader first.
	fstream.open(VertexPath, std::ios::binary);
	if (fstream) {
		fstream.seekg(0, fstream.end);
		int length = fstream.tellg();
		fstream.seekg(0, fstream.beg);
		char* buffer = new char[length + 1];
		fstream.read(buffer, length);
		buffer[length] = '\0';
        VertexSource = std::string(buffer);
		delete[] buffer;
	}
	else {
        LOG(LogLevel::FATAL, "Failed to read vertex shader!");
        assert(false);
	}
    GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    // Change the ifstream to point to the fragment shader
	fstream.close();
    fstream.open(FragPath, std::ios::binary);
    if (fstream) {
		fstream.seekg(0, fstream.end);
		int length = fstream.tellg();
		fstream.seekg(0, fstream.beg);
		char* buffer = new char[length + 1];
		fstream.read(buffer, length);
		buffer[length] = '\0';
        FragmentSource = std::string(buffer);
		delete[] buffer;
	}
    else {
        LOG(LogLevel::FATAL, "Failed to read fragment shader!");
        assert(false);
	}

    GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    

    //Convert the std::strings to const char*
    
    const char* VertexSourceCStr = VertexSource.c_str();
    const char* FragmentSourceCStr = FragmentSource.c_str();

    glShaderSource(VertexShader, 1, &VertexSourceCStr, NULL);
    glShaderSource(FragmentShader, 1, &FragmentSourceCStr, NULL);
    m_ShaderID = glCreateProgram();

    
    glAttachShader(m_ShaderID, VertexShader);
    glAttachShader(m_ShaderID, FragmentShader);


    glLinkProgram(m_ShaderID);

    GLint success;
    glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &success);

    if (!success) {
        GLint logLength;
        glGetProgramiv(m_ShaderID , GL_INFO_LOG_LENGTH, &logLength);
        char infoLog[512];

        if (logLength > 0) {
        glGetProgramInfoLog(m_ShaderID, 512, nullptr, infoLog);
        LOG(LogLevel::FATAL, "Failed to link shader program!");
        assert(false);
        }
    }
}

Shader::Shader() {


}
void Shader::DeleteShader()
{
	glDeleteProgram(m_ShaderID);
    LOG_QUIET(LogLevel::INFO, std::string("Deleted shader program with ID ") + std::to_string(m_ShaderID));
}

void Shader::Bind() const {
    glUseProgram(m_ShaderID);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

void Shader::SetMat4(const char* uniformName, const glm::mat4& mat) const {
    glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, uniformName), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetBool(const char* uniformName, bool boolean) const {
    glUniform1i(glGetUniformLocation(m_ShaderID, uniformName), boolean);
}

void Shader::SetInt(const char* uniformName, int integer) const {
    glUniform1i(glGetUniformLocation(m_ShaderID, uniformName), integer);
}

void Shader::SetFloat(const char* uniformName, float floating) const {
    glUniform1f(glGetUniformLocation(m_ShaderID, uniformName), floating);
}

void Shader::SetVec3(const char* uniformName, const glm::vec3& vec) const {
    glUniform3fv(glGetUniformLocation(m_ShaderID, uniformName), 1, glm::value_ptr(vec));
}

void Shader::SetVec4(const char* uniformName, const glm::vec4& vec) const {
    glUniform4fv(glGetUniformLocation(m_ShaderID, uniformName), 1, glm::value_ptr(vec));
}


}

