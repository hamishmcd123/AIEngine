include(FetchContent)

# Fetch GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Try to find GLFW first
find_package(glfw3 3.4 QUIET)
if (NOT glfw3_FOUND)
    FetchContent_Declare(
        glfw
        URL https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zip
        # Remember to do this!
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
    )
FetchContent_MakeAvailable(glfw)
endif()

# Find OpenGL
find_package(OpenGL REQUIRED)

#glm 
find_package(glm QUIET)
if (NOT glm_FOUND)
    FetchContent_Declare(
        glm
        URL https://github.com/g-truc/glm/releases/download/1.0.2/glm-1.0.2.zip 
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
    )
FetchContent_MakeAvailable(glm)
endif()

#glad
# https://github.com/Dav1dde/glad/discussions/426
# requires jinja and requests
FetchContent_Declare(
    glad
    URL https://github.com/Dav1dde/glad/archive/refs/tags/v2.0.8.zip
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(glad)
glad_add_library(glad_gl_core_33 STATIC REPRODUCIBLE LOADER API gl:core=3.3)

# Imgui
find_package(imgui QUIET)
if (NOT imgui_FOUND)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG docking          # fetch docking branch
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
)

FetchContent_MakeAvailable(imgui)

# Build an ImGui static library target
file(GLOB IMGUI_SOURCES
    "${imgui_SOURCE_DIR}/*.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
    "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
)

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
)

target_link_libraries(imgui PUBLIC glfw)

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    target_link_libraries(imgui PUBLIC ${X11_LIBRARIES})
endif()

target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
endif()
