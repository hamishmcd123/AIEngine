set(SOURCES
    Source/main.cpp
    Source/EditorLayer.cpp
    Source/EditorLayer.hpp
    Source/Panels/MenuBar.cpp
    Source/Panels/MenuBar.hpp
    Source/Panels/TestWindow.cpp
    Source/Panels/TestWindow.hpp
)

add_executable(App)

target_sources(App PRIVATE ${SOURCES})

# For working in VS
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES "${SOURCES}")

target_link_libraries(App PUBLIC Core)

target_include_directories(App PRIVATE Source)

# Set working directory for VS debugger
#set_target_properties(App PROPERTIES
#    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/App"
#)
