cmake_minimum_required(VERSION 3.27)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project main.cpp Clock.cpp Clock.h WaitingOnWaiter.h WaitingOnWaiter.cpp WaitingOnFood.h
WaitingOnFood.cpp Busy.h Busy.cpp Bill.h Bill.cpp TableComponent.h TableComponent.cpp  TableComposite.h
TableComposite.cpp TableState.h TableState.cpp ../Occupied.h ../Occupied.cpp Free.h Free.cpp Eating.h
Eating.cpp SubBill.h SubBill.cpp BillComponent.h BillComponent.cpp BillComposite.h BillComposite.cpp)
add_subdirectory(GTest)
