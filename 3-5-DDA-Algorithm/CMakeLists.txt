cmake_minimum_required(VERSION 3.19)
project(3-5-DDA-Algorithm)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 20)
add_executable(3-5-DDA-Algorithm main.cpp)

target_link_libraries(3-5-DDA-Algorithm "-framework OpenGL")
target_link_libraries(3-5-DDA-Algorithm "-framework GLUT")
