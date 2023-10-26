cmake_minimum_required(VERSION 3.26.4)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project main.cpp
        Order.h
        Burger.cpp
        Burger.h
        Kitchen.cpp
        Kitchen.h)
add_subdirectory(GTest)
