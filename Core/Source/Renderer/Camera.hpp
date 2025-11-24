#pragma once 
#include "glm/glm.hpp"

namespace Renderer {

class Camera{
    public:
    Camera();
    Camera(const int Width, const int Height, const float FOV);
    Camera(const int Width, const int Height, const float FOV, const glm::vec3 Pos, const glm::vec3 CameraFront, const glm::vec3 Up);

    glm::mat4 GetViewMatrix() const;
    void UpdatePerspectiveMatrix(const int NewWidth, const int NewHeight);
    glm::mat4 GetPerspectiveMatrix() const;

    private:
    glm::vec3 m_CameraPos = glm::vec3(0.0f, 0.0f, -3.0f);
    glm::vec3 m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 m_CameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::mat4 m_ViewMatrix;
    glm::mat4 m_PerspectiveMatrix;
    float m_FOV = 45.0f;
};


}
