cmake_minimum_required(VERSION 3.26.4)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project main.cpp
        Order.h
        Burger.cpp
        Burger.h
        Kitchen.cpp
        Kitchen.h
        HeadChef.cpp
        HeadChef.h
        Chef.cpp
        Chef.h
        Clock.cpp
        Clock.h
        BakerChef.cpp
        BakerChef.h)
add_subdirectory(GTest)
