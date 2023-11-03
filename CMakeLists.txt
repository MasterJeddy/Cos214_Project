cmake_minimum_required(VERSION 3.27)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cos214_Project main.cpp Clock.cpp Clock.h WaitingOnWaiter.h WaitingOnWaiter.cpp WaitingOnFood.h
WaitingOnFood.cpp Busy.h Busy.cpp Bill.h Bill.cpp TableComponent.h TableComponent.cpp  TableComposite.h
TableComposite.cpp TableState.h TableState.cpp ../Occupied.h ../Occupied.cpp Free.h Free.cpp Eating.h
Eating.cpp SubBill.h SubBill.cpp BillComponent.h BillComponent.cpp BillComposite.h BillComposite.cpp
IOInterface.cpp IOInterface.h UserCommand.cpp UserCommand.h UserCommand.h Commands.cpp Commands.h Update.cpp
Update.h Save.cpp Save.h Load.cpp Load.h CommandLog.cpp CommandLog.h SavedLog.cpp SavedLog.h Logs.cpp Logs.h
CommandLogIterator.cpp CommandLogIterator.h)
add_subdirectory(GTest)
