#pragma once 
#include "glm/glm.hpp"

namespace Renderer {

class Camera{


    private:
    glm::vec3 m_CameraPos;
    glm::vec3 m_CameraUp;
    glm::vec3 m_CameraFront;

};


}
