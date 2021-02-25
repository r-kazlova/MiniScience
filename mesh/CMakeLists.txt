cmake_minimum_required(VERSION 3.17)
project(mesh)

set(CMAKE_CXX_STANDARD 14)

add_executable(mesh main.cpp)

target_link_libraries(mesh gmsh)