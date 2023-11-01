cmake_minimum_required(VERSION 3.27)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project main.cpp SubBill.h SubBill.cpp BillComposite.h BillComposite.cpp Clock.cpp Clock.h TableState.h Free.h Free.cpp)
add_subdirectory(GTest)
