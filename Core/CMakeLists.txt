set (SOURCES 
    Source/Application.cpp
    Source/Application.hpp
    Source/Layer.hpp
    Source/Window.cpp
    Source/Window.hpp
    Source/ImguiLayer.cpp
    Source/ImguiLayer.hpp
    Source/Events/MouseEvents.hpp
    Source/Events/KeyEvents.hpp
    Source/Events/WindowEvents.hpp
    Source/Event.hpp
    Source/Logger.cpp
    Source/Logger.hpp
    Source/Renderer/Camera.hpp
    Source/Renderer/Renderer.hpp
    Source/Renderer/RenderCommand.hpp
    Source/Renderer/Shader.hpp
    Source/Renderer/Shader.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

target_include_directories(Core PUBLIC Source)

# If find_package(glfw) worked
if(TARGET glfw::glfw)
    target_link_libraries(Core PRIVATE glfw::glfw)
#otherwise
else()
    target_link_libraries(Core PRIVATE glfw)
endif()

target_link_libraries(Core PRIVATE OpenGL::GL)

if (TARGET glm::glm)
    target_link_libraries(Core PUBLIC glm::glm)
else()
    target_link_libraries(Core PUBLIC glm)
endif()

target_link_libraries(Core PRIVATE glad_gl_core_33)

target_link_libraries(Core PUBLIC imgui)
# For working in VS
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES "${SOURCES}")

