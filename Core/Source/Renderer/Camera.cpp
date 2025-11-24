#include "Camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

namespace Renderer {

    Camera::Camera(const int Width, const int Height, const float FOV) {
        m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
        m_PerspectiveMatrix = glm::perspective(m_FOV, (float)Width / (float)Height, 0.1f, 100.0f);
    }

    Camera::Camera(const int Width, const int Height, const float FOV, const glm::vec3 Pos, const glm::vec3 CameraFront , const glm::vec3 Up) : 
    m_CameraPos(Pos), m_CameraFront(CameraFront), m_CameraUp(Up), m_FOV(FOV)
    {
        m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
        m_PerspectiveMatrix = glm::perspective(m_FOV, (float)Width / (float)Height, 0.1f, 100.0f);
    }


    void Camera::UpdatePerspectiveMatrix(const int NewWidth, const int NewHeight) {
        m_PerspectiveMatrix = glm::perspective(m_FOV, (float)NewWidth / (float)NewHeight, 0.1f, 100.0f);
    }

    Camera::Camera() {}

    glm::mat4x4 Camera::GetViewMatrix() const {return m_ViewMatrix;}

    glm::mat4x4 Camera::GetPerspectiveMatrix() const {return m_PerspectiveMatrix;}

} // namespace Renderer
    
