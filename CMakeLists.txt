cmake_minimum_required(VERSION 3.27)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project TableState.h TableState.cpp Free.h Free.cpp)
add_subdirectory(GTest)


