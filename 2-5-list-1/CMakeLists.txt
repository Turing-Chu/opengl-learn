cmake_minimum_required(VERSION 3.19)
project(untitled)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 20)
add_executable(untitled main.cpp)

target_link_libraries(untitled "-framework OpenGL")
target_link_libraries(untitled "-framework GLUT")
