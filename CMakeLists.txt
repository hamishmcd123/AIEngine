cmake_minimum_required(VERSION 3.14)

project(AIEngine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(Dependencies.cmake)


add_subdirectory(Core)
add_subdirectory(App)
